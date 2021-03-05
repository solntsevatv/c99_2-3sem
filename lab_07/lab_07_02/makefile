CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic


OBJS := out/input_output.o out/processing.o
UNIT_OBJS := out/check_input_output.o out/check_processing.o out/input_output.o out/processing.o


app.exe : $(OBJS) out/main.o
	$(CC) $^ -o $@

unit_tests.exe : $(UNIT_OBJS) out/check_main.o
	$(CC) $^ -lcheck -o $@

out/%.o : unit_tests/%.c
	$(CC) $(CFLAGS) -c $<
	mkdir -p out
	mv *.o out

out/%.o : src/%.c
	$(CC) $(CFLAGS) -c $<
	mkdir -p out
	mv *.o out

%.d : src/%.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

.PHONY : clean, func, unit

func:
	
unit: unit_tests.exe
	./unit_tests.exe

clean :
	$(RM) *.o *.exe *.d
