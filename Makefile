TARGET = bench

all:$(TARGET)

bench:bench.c
	llvm-gcc -Wall -O2 -o $@ $<

clean:
	rm -rf $(TARGET)

