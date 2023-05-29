const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const hello = b.addExecutable(.{
        .name = "hello",
        .target = target,
        .optimize = optimize,
    });

    hello.addIncludePath("src/include");
    hello.addCSourceFiles(&.{
        "src/geometry/point.c",
        "src/main.c"
    }, &.{
        "-Wall",
        "-Wextra",
        "-std=c2x",
        "-pedantic"
    });

    b.installArtifact(hello);
}
