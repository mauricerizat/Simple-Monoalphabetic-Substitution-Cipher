#MONOALPHABETIC SUBSTITUTION CIPHER

monoCipher.out: main.o header.h encrypt.o decrypt.o keygen.o
	g++ -o monoCipher.out main.o header.h encrypt.o decrypt.o keygen.o

main.o: main.cpp header.h encrypt.o decrypt.o keygen.o
	g++ -c main.cpp

encrypt.o: encrypt.cpp header.h 
	g++ -c encrypt.cpp

decrypt.o: decrypt.cpp header.h 
	g++ -c decrypt.cpp

keygen.o: keygen.cpp header.h 
	g++ -c keygen.cpp

clean:
	rm *.o monoCipher.out
