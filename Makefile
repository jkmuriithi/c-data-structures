MAKE = make
BINDIR = bin

all: tests

clean:
	rm -f **/*.o **/*.gch **/*.exe src/**/*.gch

exec:
	$(MAKE) && ./$(BINDIR)/*.exe

tests:
	$(MAKE) -C test

