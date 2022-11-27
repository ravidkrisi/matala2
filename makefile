main.o: main.c my_mat.h
	gcc -c main.c

my_mat.o: my_mat.c my_mat.h
	gcc -Wall -fPIC -c my_mat.c

libclassmat.a: my_mat.o my_mat.h
	ar rcs libclassmat.a my_mat.o

libclassmat.so: my_mat.o my_mat.h
	gcc -shared my_mat.o -o libclassmat.so

mains: main.o libclassmat.a
	gcc main.o libclassmat.a -lm -o mains

maind: main.o libclassmat.so
	gcc main.o ./libclassmat.so -lm -o maind

clean: 
	rm *.txt *.o *.a *.so mains maind