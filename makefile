all:
	g++ -std=c++11 -o main main.cpp
test:
	g++ -std=c++11 -I ~/googletest/googletest/include -L ~/googletest/build/lib UnitTest.cpp -o test -lgtest -lpthread
	./test
coverage:
	g++ -std=c++11 -fprofile-arcs -ftest-coverage -fPIC main.cpp -o coverage
	./coverage
	./coverage sample1_input_image.txt
	~/.local/bin/gcovr -r .
clean:
	rm -f *.o main test
