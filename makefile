main: upsample.o
	g++ -o main upsample.o
upsample.o:
	g++ -c upsample.cpp -o upsample.o
test:
	g++ -o tests tests.c
#coverage:
#	g++
clean:
	rm -f *.o main