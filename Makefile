CXXFLAGS= -g -fsanitize=leak,address,undefined
LDFLAGS= -l Catch2Main -l Catch2
all: main.x

cream.o random69.o main.o: cream.cpp random69.cpp main.cpp input.txt
	g++ ${CXXFLAGS} -c cream.cpp -o cream.o
	g++ ${CXXFLAGS} -c random69.cpp -o random69.o
	g++ ${CXXFLAGS} -c main.cpp -o main.o

main.x: cream.o random69.o main.o
	g++	${CXXFLAGS} $^ -o main.x
	./main.x

cream_test.o: cream_test.cpp
	g++ -c $^ -o $@
	g++ -c cream.cpp -o cream.o
	g++ -c random69.cpp -o random69.o

cream_test.x: cream_test.o cream.o random69.o
	g++ $^ -o $@ ${LDFLAGS}
	rm -f *.o

test: cream_test.x
	./cream_test.x


# plot.py: datos0.txt datos1.txt

# plot: plot.py
# 	python3 plot.py


clean:
	rm -f *.o *.x EntropyVsTime*.txt SizeVsTime.txt moleculesVsTime.txt *.pdf *.png datos0.txt
