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
* `make` works by creating or updating 'targets' which are really just the files that it finds in the context directory
* Targets are skipped if `make` sees that they do not need to be updated (e.g. the source code has not changed) -- this avoids needless recompilation
* Allows for the creation of "phony" targets which act like commands -- allowing for the creation of a CLI-like utilty for the project

### Cons:
* While bash-like, the syntax is complicated (e.g. if you mess up tabs-vs-spaces you'll get runtime errors) and some "tips and tricks" with Makefile syntax become "odd quirks that you'll very quickly forget" leading to a complicated build system