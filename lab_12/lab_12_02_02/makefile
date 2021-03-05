CC := gcc

CFLAGS := -Wall -std=c99 -Werror
UNIT_CFLAGS := -lcheck -std=c99

DYN_LIB := src/arr_lib.c
C_UNIT := unit_tests/check_arr_lib.c  unit_tests/check_main.c

libarr.so:  arr_lib.o
	$(CC) -o libarr.so -shared arr_lib.o

arr_lib.o:
	$(CC) $(CFLAGS) -fpic -c $(DYN_LIB)

unit_tests.exe : libarr.so
	$(CC) $(CFLAGS) $(C_UNIT) -L. -larr -lcheck -o $@

out/%.o : unit_tests/%.c
	$(CC) $(UNIT_CFLAGS) -c $<
	mkdir -p out
	mv *.o out

out/%.o : 
	$(CC) $(CFLAGS) -c $(C_FILES)
	mkdir -p out
	mv *.o out

%.d : src/%.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

.PHONY : clean, unit, run_tests

unit: unit_tests.exe
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
	./unit_tests.exe

run_tests: unit_tests.exe
	./unit_tests.exe

clean :
	$(RM) out/*.o *.exe *.d *.a *.so *.o
