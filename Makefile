CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror -g -MMD
EXEC=mineSweeper
OBJECTS=main.o cell.o game.o 
DEPNDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
