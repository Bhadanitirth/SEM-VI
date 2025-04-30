print : 
	@ echo "hello"
all : Print Create
create : 
	touch file.c 
	@ echo "File created"

file.o : file.c
	cc file.c -c

run : file.out
	./file.out
all : compile run
compile : 
	cc file.c file2.c -o file
run : 
	./file
