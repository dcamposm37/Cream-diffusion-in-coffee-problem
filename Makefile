CXXFLAGS= -g -fsanitize=leak,address,undefined

all: main.x

%.x: %.o cream.o random69.o
	g++ ${CXXFLAGS} $^ -o $@
	./main.x

# vector_test.x: vector_test.o vector_ops.o
# 	g++  $^ -o $@ -l Catch2Main -l Catch2

# test: vector_test.x
# 	./vector_test.x

clean:
	rm -f *.o *.x
