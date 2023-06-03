TARGET = hello

SRCDIR     := src
INCLUDEDIR := include
BUILDDIR   := obj
BINDIR     := bin

SRCEXT := c
OBJEXT := o

SOURCES := $(shell find ${SRCDIR} -type f -name *.${SRCEXT})
OBJECTS := $(patsubst ${SRCDIR}/%,${BUILDDIR}/%,${SOURCES:.${SRCEXT}=.${OBJEXT}})

CC      := clang
CFLAGS  := -Wall -Wextra -std=c2x -pedantic
LDFLAGS :=

.PHONY : all
all: ${TARGET}

.PHONY : debug
debug: CFLAGS += -g3 -glldb
debug: clean ${TARGET}

##
# Compilation.
#
# Make each object file by looking for the corresponding source file.
# '$@' is the name of this target
# '$<' is the first file this target depends upon (here we only depend upon one anyways).
# So:
#   ${CC} ${CFLAGS} -c $< -o $@
# Expands to:
#   ${CC} ${CFLAGS} -c foo.c -o foo.o
#
${BUILDDIR}/%.${OBJEXT}: ${SRCDIR}/%.${SRCEXT}
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -I${INCLUDEDIR} -c $< -o $@

##
# Linking.
#
# Make the target binary by linking all of the object files.
#
${TARGET} : ${OBJECTS}
		@mkdir -p ${BINDIR}
		${CC} ${LDFLAGS} -o ${BINDIR}/$@ ${OBJECTS}

.PHONY: clean
clean:
		@rm -rf ${BUILDDIR}

.PHONY: purge
purge: clean
		@rm -rf ${BINDIR}
