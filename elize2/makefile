# @file makefile
# @brief Makefile

OUTFILE	= bin/elize

INCLUDE ?=
SFILES	?=

CFLAGS ?= 

INCLUDE	+= 
SFILES	+= elize.c

#------------------------------------------------------------
# Default
all: build

# Build
build:
	gcc $(CFLAGS) $(SFILES) $(INCLUDE) -o $(OUTFILE)
#
