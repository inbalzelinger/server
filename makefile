a.out: compileAll
	g++ -pthread *.o -o ../../exe/server.out
	rm -f *.o

compileAll: *.cpp *.h
	g++ -pthread -c *.cpp
