default: all

hellodll_v1.o: hellodll_v1.c
	gcc -c hellodll_v1.c -o tests/hellodll.o

hellodll_v1.dll: hellodll_v1.o
	cd tests && gcc -o hellodll.dll -s -shared hellodll.o -Wl,--subsystem,windows

hellodll_v2.o: hellodll_v2.c
	gcc -c hellodll_v2.c -o tests/lib/hellodll.o

hellodll_v2.dll: hellodll_v2.o
	cd tests/lib && gcc -o hellodll.dll -s -shared hellodll.o -Wl,--subsystem,windows

hello.o: hello.c
	gcc -c -o tests/hello.o hello.c

hello.exe: hello.o hellodll_v1.dll hellodll_v2.dll
	cd tests && gcc -o hello.exe -s hello.o -L. -lhellodll

all: hello.exe

clean:
	find . -name "*.o" -exec rm -f {} \;
	find . -name "*~" -exec rm -f {} \;
	find . -name "*.exe" -exec rm -f {} \;
	find . -name "*.dll" -exec rm -f {} \;
