Your:Your.o HugeInt.o
	g++ -o Your Your.o HugeInt.o
Your.o:Your.cpp HugeInt.h
	g++ -c Your.cpp
HugeInt.o:HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp
