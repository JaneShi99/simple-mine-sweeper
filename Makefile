CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror -g -MMD
EXEC=mineSweeper
OBJECTS=cell.o game.o main.o
DEPENDS=${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
