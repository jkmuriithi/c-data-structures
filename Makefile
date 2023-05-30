MAKE = make
BINDIR = bin

all: testfiles

clean:
	rm -f **/*.o **/*.gch **/*.exe src/**/*.gch

exec:
	$(MAKE) && ./$(BINDIR)/*.exe

testfiles:
	$(MAKE) -C test

