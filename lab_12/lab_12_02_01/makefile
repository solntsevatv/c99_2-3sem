CC := gcc

CFLAGS := -Wall -std=c99 

POS_TESTS := $(wildcard func_tests/pos_0*_in.txt)
POS_TESTS := $(POS_TESTS:_in.txt=)
NEG_TESTS := $(wildcard func_tests/neg_0*_in.txt)
NEG_TESTS := $(NEG_TESTS:_in.txt=)

STATIC_LIB := src/filtr_lib.c
DYN_LIB := src/input_lib.c src/output_lib.c
C_FILES := src/processing.c src/main.c
C_UNIT := src/processing.c unit_tests/check_processing.c \
unit_tests/check_input_lib.c unit_tests/check_main.c

app.exe: build_static_lib build_dyn_lib
	$(CC) $(CFLAGS) $(C_FILES) -L. -lfiltr -linput -ldl -o $@
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

build_static_lib: 
	$(CC) $(CFLAGS) -c $(STATIC_LIB)
	ar rc libfiltr.a filtr_lib.o
	ranlib libfiltr.a

build_dyn_lib:
	$(CC) $(CFLAGS) -fPIC -c $(DYN_LIB)
	$(CC) -o libinput.so -shared input_lib.o
	$(CC) -o liboutput.so -shared output_lib.o


unit_tests.exe : build_static_lib build_dyn_lib
	$(CC) $(CFLAGS) $(C_UNIT) -L. -lfiltr -linput -lcheck -o $@

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

clean :
	$(RM) out/*.o *.exe *.d *.a *.so *.o
