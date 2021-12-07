
output: main.o room.o LAB.o LECTURE.o
	g++ main.o room.o LAB.o LECTURE.o -o output

main.o: main.cpp
	g++ -c main.cpp

room.o: room.cpp
	g++ -c room.cpp

LAB.o: LAB.cpp
	g++ -c LAB.cpp

LECTURE.o: LECTURE.cpp
	g++ -c LECTURE.cpp

clean:
	rm *o sample
