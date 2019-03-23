all : a.out
.PHONY : clean

a.out : test_main.o skipList.o 
		g++ test_main.cpp skipList.cc

clean : 
	rm *.o *.out