make: run
	./run
run: functions.o main.o
	gcc -o run functions.o main.o
function.o: functions.c header.h
	gcc -c functions.c
main.o: main.c header.h
	gcc -c main.c
