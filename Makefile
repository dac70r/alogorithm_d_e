all: distance_energy main
	gcc main.o distance_energy.o

distance_energy: distance_energy
	gcc -c distance_energy.c

main: main
	gcc -c main.c

clean: main
	rm main.o