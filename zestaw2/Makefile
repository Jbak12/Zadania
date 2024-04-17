run_zad2: zad2.x podprogram.x
	./zad2.x ./podprogram.x
zad2.x: zad2.o podprogram.x
	cc zad2.o -o zad2.x 
zad2.o: zad2.c 
	cc -c zad2.c -o zad2.o
podprogram.x: podprogram.o 
	cc podprogram.o -o podprogram.x
podprogram.o: podprogram.c
	cc -c podprogram.c -o podprogram.o
