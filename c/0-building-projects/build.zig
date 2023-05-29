const std = @import("std");

pub fn build(b: *std.build.Builder) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Create the compilation 'Step' ('hello' here is of type *Step.Compile)
    const hello = b.addExecutable(.{
        .name = "hello",
        .target = target,
        .optimize = optimize,
    });

    // Dynamically discover all ".c" files in the directory tree under "src"
    var sources = std.ArrayList([]const u8).init(b.allocator);
    var srcDir = try std.fs.cwd().openIterableDir("src", .{});
    var srcDirWalker = try srcDir.walk(b.allocator);
    defer srcDirWalker.deinit();

    while (try srcDirWalker.next()) |entry| {
        const entryExt = std.fs.path.extension(entry.basename);
        if (!std.mem.eql(u8, entryExt, ".c")) {
            continue;
        }
        try sources.append(b.pathJoin(&.{ "src", entry.path }));
    }

    hello.addIncludePath("src/include");
    hello.addCSourceFiles(sources.items, &.{ "-Wall", "-Wextra", "-Werror=return-type", "-std=c2x", "-pedantic" });

    // Specify which compile step the 'build install' command should perform. This could be the end of the build function.
    b.installArtifact(hello);

    // Create a custom build step called 'run' which depends upon 'build install'.
    const cmd_run = b.addRunArtifact(hello);
    cmd_run.step.dependOn(b.getInstallStep());

    const step_run = b.step("run", "Run the binary");
    step_run.dependOn(&cmd_run.step);
}
