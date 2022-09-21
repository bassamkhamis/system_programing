# build all files useing Make utility


static: fib.o fact.o rand.o
	ar -rs libstatic.a fib.o fact.o rand.o
	

*.o: *.c
	gcc -o $@ -c $<
	

run_static: libstatic.a	main.o
	gcc -o myout1 main.o -I. -lstatic -L.
	./myout1

dynamic:
	gcc -shared -fpic -o libdymamic.so fib.c fact.c rand.c
	
run_dynamic: libdymamic.so
	gcc -o myout2 main.c ./libdymamic.so
	./myout2
	
clean:
	@rm *.o *.a *.so
	@echo "removing...."	

