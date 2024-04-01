CXXFLAGS= -g -fsanitize=leak,address,undefined -o3
LDFLAGS= -l Catch2Main -l Catch2


all: main.x

cream.o random69.o main.o: cream.cpp random69.cpp main.cpp input.txt
	g++ ${CXXFLAGS} -c cream.cpp -o cream.o
	g++ ${CXXFLAGS} -c random69.cpp -o random69.o
	g++ ${CXXFLAGS} -c main.cpp -o main.o

main.x: cream.o random69.o main.o
	g++	${CXXFLAGS} $^ -o main.x
	./main.x "input.txt"
	 python3 EntropyPlot.py
	 python3 EntropyDifferentSizesPlot.py
	 python3 sizeVsTimePlot.py
	 python3 moleculesVsTimePlot.py
	 python3 computingTimePlot.py

cream_test.o: cream_test.cpp
	g++ -c $^ -o $@
	g++ -c cream.cpp -o cream.o
	g++ -c random69.cpp -o random69.o

cream_test.x: cream_test.o cream.o random69.o
	g++ $^ -o $@ ${LDFLAGS}
	rm -f *.o

test: cream_test.x
	./cream_test.x

memcheck:
	g++ -g -c cream.cpp -o cream.o
	g++ -g -c random69.cpp -o random69.o
	g++ -g -c main.cpp -o main.o
	g++	-g cream.o random69.o main.o -o memcheck.x
	valgrind --tool=memcheck --track-origins=yes --leak-check=full ./memcheck.x "input-profiling.txt"
	rm -f *.o *.x EntropyVsTime*.txt SizeVsTime.txt moleculesVsTime.txt

cachegrind:
	g++ -g -c cream.cpp -o cream.o
	g++ -g -c random69.cpp -o random69.o
	g++ -g -c main.cpp -o main.o
	g++	-g cream.o random69.o main.o -o cachegrind.x
	valgrind --tool=cachegrind ./cachegrind.x "input-profiling.txt"
	cg_annotate --auto=yes cachegrind.out* > cachegrind-report.txt
	rm -f *.o *.x EntropyVsTime*.txt SizeVsTime.txt moleculesVsTime.txt *.out cachegrind.out*


gprof:
	g++ -Wall -pg -g -c cream.cpp -o cream.o
	g++ -Wall -pg -g -c random69.cpp -o random69.o
	g++ -Wall -pg -g -c main.cpp -o main.o
	g++	-Wall -pg -g cream.o random69.o main.o -o test_gprof.x
	./test_gprof.x "input-profiling.txt"
	gprof test_gprof.x gmon.out > gprof-report.txt
	rm -f *.o *.x EntropyVsTime*.txt SizeVsTime.txt moleculesVsTime.txt *.out

clean:
	rm -f *.o *.x  *.pdf *.png *.out  cachegrind.out* datos0.txt EntropyVsTime*.txt SizeVsTime.txt moleculesVsTime.txt gprof-report.txt cachegrind-report.txt
