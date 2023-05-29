# Building C Projects

## Make

### Usage:

**Release**

```
> make
> ./bin/hello
```

**Debug**

*Emits debug events to allow for GDB/LLDB debugging*

```
> make debug
> ./bin/hello
```

**Clean**

*Removes .o files, leaves binary releases untouched*

```
> make clean
```

**Purge**

*Removes .o and binary release files*

```
> make purge
```

### Pros:
* This is basically what `make` was made for
* `make` is almost certainly already installed on your system
* `make` works by creating or updating 'targets' which are really just the files that it finds in the context directory
* Targets are skipped if `make` sees that they do not need to be updated (e.g. the source code has not changed) -- this avoids needless recompilation
* Allows for the creation of "phony" targets which act like commands -- allowing for the creation of a CLI-like utilty for the project

### Cons:
* While bash-like, the syntax is complicated (e.g. if you mess up tabs-vs-spaces you'll get runtime errors) and some "tips and tricks" with Makefile syntax become "odd quirks that you'll very quickly forget" leading to a complicated build system

## Bash Script

### Usage:

**Release**

```
> TARGET=hello ./scripts/build
> ./bin/hello
```

**Debug**

*Emits debug events to allow for GDB/LLDB debugging*

```
> TARGET=hello MODE=debug ./scripts/build
> ./bin/hello
```

**Clean**

*Up to you!*

```
> rm -r obj
```

**Purge**

*Up to you!*

```
> rm -r obj bin
```

### Pros:
* You control your own destiny!
* The logic for C and C++ compilation is *slightly* complex, but once you get over the necessary steps, those steps really never change (and, arguably, knowing what those steps are is better than obfuscating them with `make` magic): 
  1. For each source file:
  1. Compile the file into an object file (`clang foo.c -o foo.o`)
      * To ensure header files are found: `clang -Idir/where/headers/are -c foo.c -foo.o`
      * To add compile flags: `clang -Wall -Wextra -std=c2x -Idir/where/headers/are -c foo.c -foo.o`
  1. Using all of the object files, create a target (binary) (`clang -o foobin foo.o bar.o baz.o)
* Bash things are more easily understood/googleable than `make` things
* Once you get over the use of `clang` or `gcc`, the script is as simple or complex as you'd like


### Cons:
* You control your own destiny!
* Unless you want to start re-implementing `make`, you'll be re-compiling on every build. Note: while this was definitely considered a bad practice in the 1970s, I wonder how big of an issue that is in the modern era...
