CXX = g++-4.9									# compiler
CXXFLAGS = -g -Wall -Werror -std=c++11 -MMD				# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}			# makefile name

OBJECTS1 = main.o textdisplay.o game.o cell.o gameobject.o item.o character.o knight.o samurai.o wizard.o orc.o merchant.o dragon.o goblin.o bug.o 			# object files forming executable
EXEC1 = cc3k									# executable name

OBJECTS = ${OBJECTS1}
EXECS = ${EXEC1}
DEPENDS = ${OBJECTS:.o=.d}							# substitute ".o" with ".d"

.PHONY : all clean

all : ${EXECS}

${EXEC1} : ${OBJECTS1}								# link step
	${CXX} $^ -o $@

${OBJECTS} : ${MAKEFILE_NAME}							# OPTIONAL : changes to this file => recompile

-include ${DEPENDS}								# include *.d files containing program dependences

clean :										# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}
