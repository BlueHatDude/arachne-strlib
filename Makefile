lib: src/arachne_funcs.c src/arachne_strlib.h
	$(CC) -c src/arachne_funcs.c
	ar -rc libarachne.a arachne_funcs.o

tests: clean lib
	$(CC) -o tests.out src/tests.c arachne_funcs.o

clean:
	$(RM) *.o *.a *.out
