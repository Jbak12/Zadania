run_zad2: zad2 podprogram
	./zad2 ./podprogram
zad2: zad2.o podprogram
	cc zad2.o -o zad2 
zad2.o: zad2.c 
	cc -c zad2.c -o zad2.o
podprogram: podprogram.o 
	cc podprogram.o -o podprogram
podprogram.o: podprogram.c
	cc -c podprogram.c -o podprogram.o
