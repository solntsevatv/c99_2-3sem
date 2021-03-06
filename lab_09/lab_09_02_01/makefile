CC := gcc

CFLAGS := -Wall -Werror -pedantic

POS_TESTS := $(wildcard func_tests/pos_0*_in.txt)
POS_TESTS := $(POS_TESTS:_in.txt=)
NEG_TESTS := $(wildcard func_tests/neg_0*_in.txt)
NEG_TESTS := $(NEG_TESTS:_in.txt=)
OBJS := out/input.o  out/output.o out/processing.o
UNIT_OBJS := out/input.o out/output.o out/processing.o out/check_input.o


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

func: app.exe positive $(POS_TESTS) negative $(NEG_TESTS)
	rm out.txt
	
func_tests/pos_0%:
	-$(shell cat ./$@_args.txt)
	@-FC out.txt $@_out.txt
	@echo

func_tests/neg_0%:
	-$(shell cat ./$@_args.txt)
	@-FC out.txt $@_out.txt
	@echo

unit: unit_tests.exe
	./unit_tests.exe

positive:
	@echo Positive tests:
	@echo

negative:
	@echo Negative tests:
	@echo

clean :
	$(RM) out/*.o *.exe *.d
