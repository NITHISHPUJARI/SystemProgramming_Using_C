TESTDIR=tests
LIBDIR=libs
DISTDIR=dist
SRCDIR=src
EXAMPLEDIR=examples
COMPFLAGS=-Wall -Wpedantic -Winline -Wextra -Wno-unknown-pragmas -Wno-long-long
# Lib Name :
LIBNAME=$(LIBDIR)/libC-utils.a
# Shared Lib Link 
LIBLINKCCFLAGS = -L. $(LIBNAME)


all: libraries examples

test_all: libraries test

libraries: string bitarray fileutils linkedlist doublylinkedlist graph queue stack permutations 

string:
	$(CC) $(STD) -c $(SRCDIR)/stringlib.c -o $(LIBDIR)/string-lib.o $(CCFLAGS) $(COMPFLAGS)

bitarray:
	$(CC) $(STD) -c $(SRCDIR)/bitarray.c -o $(LIBDIR)/bitarray-lib.o $(CCFLAGS) $(COMPFLAGS)

fileutils:
	$(CC) $(STD) -c $(SRCDIR)/fileutils.c -o $(LIBDIR)/fileutils-lib.o $(CCFLAGS) $(COMPFLAGS)

linkedlist:
	$(CC) $(STD) -c $(SRCDIR)/llist.c -o $(LIBDIR)/llist-lib.o $(CCFLAGS) $(COMPFLAGS)

doublylinkedlist:
	$(CC) $(STD) -c $(SRCDIR)/dllist.c -o $(LIBDIR)/dllist-lib.o $(CCFLAGS) $(COMPFLAGS)

stack:
	$(CC) $(STD) -c $(SRCDIR)/stack.c -o $(LIBDIR)/stack-lib.o $(CCFLAGS) $(COMPFLAGS)

queue:
	$(CC) $(STD) -c $(SRCDIR)/queue.c -o $(LIBDIR)/queue-lib.o $(CCFLAGS) $(COMPFLAGS)

graph:
	$(CC) $(STD) -c $(SRCDIR)/graph.c -o $(LIBDIR)/graph-lib.o $(CCFLAGS) $(COMPFLAGS)

permutations:
	$(CC) $(STD) -c $(SRCDIR)/permutations.c -o $(LIBDIR)/permutations-lib.o $(CCFLAGS) $(COMPFLAGS)

debug: CCFLAGS += -g
debug: all

openmp: CCFLAGS += -fopenmp
openmp: all

test: CCFLAGS += -coverage
test: libraries
	$(CC) $(STD) $(LIBDIR)/string-lib.o $(TESTDIR)/stringlib_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/strlib
	$(CC) $(STD) $(TESTDIR)/timing_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/timing
	$(CC) $(STD) $(TESTDIR)/minunit_test.c $(CCFLAGS) $(COMPFLAGS) -lm -o ./$(DISTDIR)/minunit
	$(CC) $(STD) $(LIBDIR)/bitarray-lib.o $(TESTDIR)/bitarray_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/bitarray
	$(CC) $(STD) $(LIBDIR)/fileutils-lib.o $(TESTDIR)/fileutils_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/fileutils
	$(CC) $(STD) $(LIBDIR)/llist-lib.o $(TESTDIR)/linked_list_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/linkedlist
	$(CC) $(STD) $(LIBDIR)/dllist-lib.o $(TESTDIR)/doubly_linked_list_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/doublelinkedlist
	$(CC) $(STD) $(LIBDIR)/queue-lib.o $(TESTDIR)/queue_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/queue
	$(CC) $(STD) $(LIBDIR)/stack-lib.o $(TESTDIR)/stack_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/stack
	$(CC) $(STD) $(LIBDIR)/graph-lib.o $(TESTDIR)/graph_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/graph
	$(CC) $(STD) $(LIBDIR)/permutations-lib.o $(TESTDIR)/permutations_test.c $(CCFLAGS) $(COMPFLAGS) -o ./$(DISTDIR)/permutations

examples: libraries
# Create a Shared Library 
	ar -cr $(LIBNAME) $(LIBDIR)/*.o
	$(CC) $(STD) $(EXAMPLEDIR)/bitarray_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS)  -o ./$(DISTDIR)/ex_bitarray 
	$(CC) $(STD) $(EXAMPLEDIR)/fileutils_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_fileutils
	$(CC) $(STD) $(EXAMPLEDIR)/stringlib_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_stringlib
	$(CC) $(STD) $(EXAMPLEDIR)/linkedlist_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_linkedlist
	$(CC) $(STD) $(EXAMPLEDIR)/doublylinkedlist_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_doublylinkedlist
	$(CC) $(STD) $(EXAMPLEDIR)/queue_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_queue
	$(CC) $(STD) $(EXAMPLEDIR)/stack_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_stack
	$(CC) $(STD) $(EXAMPLEDIR)/graph_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_graph
	$(CC) $(STD) $(EXAMPLEDIR)/permutations_example.c $(CCFLAGS) $(COMPFLAGS) $(LIBLINKCCFLAGS) -o ./$(DISTDIR)/ex_permutations

runtests:
	@ if [ -f "./$(DISTDIR)/fileutils" ]; then ./$(DISTDIR)/fileutils; fi
	@ if [ -f "./$(DISTDIR)/bitarray" ]; then ./$(DISTDIR)/bitarray; fi
	@ if [ -f "./$(DISTDIR)/strlib" ]; then ./$(DISTDIR)/strlib; fi
	@ if [ -f "./$(DISTDIR)/timing" ]; then ./$(DISTDIR)/timing; fi
	@ if [ -f "./$(DISTDIR)/linkedlist" ]; then ./$(DISTDIR)/linkedlist; fi
	@ if [ -f "./$(DISTDIR)/doublelinkedlist" ]; then ./$(DISTDIR)/doublelinkedlist; fi
	@ if [ -f "./$(DISTDIR)/queue" ]; then ./$(DISTDIR)/queue; fi
	@ if [ -f "./$(DISTDIR)/stack" ]; then ./$(DISTDIR)/stack; fi
	@ if [ -f "./$(DISTDIR)/graph" ]; then ./$(DISTDIR)/graph; fi
	@ if [ -f "./$(DISTDIR)/permutations" ]; then ./$(DISTDIR)/permutations; fi

clean:
	if [ -d "./$(DISTDIR)/" ]; then rm ./$(DISTDIR)/*; fi
	if [ -d "./$(LIBDIR)/" ]; then rm ./$(LIBDIR)/*; fi
	rm -f ./*.gcno
	rm -f ./*.gcda
	rm -f ./*.gcov
