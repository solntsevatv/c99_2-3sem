CC := gcc

CFLAGS := -Wall -pedantic -std=c99 -Werror
UNIT_CFLAGS := -lcheck -std=c99

OBJS := out/my_func.o
UNIT_OBJS := out/my_func.o out/check_my_func.o


app.exe : $(OBJS) out/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(UNIT_OBJS) out/check_main.o
	$(CC) $^ -lcheck -o $@

out/%.o : unit_tests/%.c
	$(CC) $(UNIT_CFLAGS) -c $<
	mkdir -p out
	mv *.o out

out/%.o : src/%.c
	$(CC) $(CFLAGS) -c $<
	mkdir -p out
	mv *.o out

%.d : src/%.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

.PHONY : clean, unit, run_tests

unit: unit_tests.exe
	./unit_tests.exe

run_tests: unit_tests.exe
	./unit_tests.exe

clean :
	$(RM) out/*.o *.exe *.d
