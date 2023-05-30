MAKE = make

all: testfiles

clean:
	rm -f **/*.o **/*.gch **/*.exe src/**/*.gch

testfiles:
	$(MAKE) -C test

