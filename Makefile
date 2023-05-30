MAKE = make

all: testfiles

clean:
	rm -f **/*.o src/**/*.gch bin/*.exe

testfiles:
	$(MAKE) -C test

