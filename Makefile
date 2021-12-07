
# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o node.o graph.o

# Generated files
CLEAN_RM = actual-*.png

# Use the cs225 makefile template:
include cs225/make/cs225.mk
