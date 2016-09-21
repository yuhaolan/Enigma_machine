drive : drive drive.o rotor.o permutation.o
	g++ -g -o drive.o rotor.o permutation.o
drvier.o : drive.cc rotor.hh permutation.hh
	g++ -Wall -c drive.cc 
rotor.o : rotor.cc rotor.hh
	g++ -Wall -c rotor.cc
permutation.o : percent:qmutation.cc permutation.hh
	g++ -Wall -c permutation.cc
clean :
	rm  *.o
