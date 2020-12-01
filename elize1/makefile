# @file makefile
# @brief build Makefile

OUTFILE	= bin/elize1

INCLUDE ?=
SFILES	?=

CFLAGS ?= 

INCLUDE	+= 
SFILES	+= elize1.c

#------------------------------------------------------------
# Default
all: clean build

# Build
build:
	gcc $(CFLAGS) $(SFILES) $(INCLUDE) -o $(OUTFILE)

# Clean up
clean:
	rm -f $(OUTFILE)
#
