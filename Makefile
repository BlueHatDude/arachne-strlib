lib: src/arachne_funcs.c src/arachne_strlib.h
	$(CC) -c src/arachne_funcs.c
	ar -rc libarachne.a src/arachne_funcs.c

tests: src/tests.c arachne_funcs.o src/arachne_strlib.h
	$(CC) -o tests.out src/tests.c arachne_funcs.o

clean:
	$(RM) *.o *.a *.out
