CXXFLAGS= -g -fsanitize=leak,address,undefined
all: main.x

%.x: %.o cream.o random69.o
	g++ ${CXXFLAGS} $^ -o $@
	./main.x



cream_test.o cream.o random69.o: cream_test.cpp cream.cpp random69.cpp
	g++ -c cream_test.cpp -o cream_test.o
	g++ -c cream.cpp -o cream.o
	g++ -c random69.cpp -o random69.o


cream_test.x: cream_test.o cream.o random69.o

	g++  $^ -o $@ -l Catch2Main -l Catch2

test: cream_test.x
	./cream_test.x

clean:
	rm -f *.o *.x
