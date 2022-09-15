# Assignment 2 #Femto shell

## Create static and dynamic lib
## 1- commands for static
  ### gcc -c fib.c fact.c rand.c
  ### ar -rs libstatic.a fact.o fib.o rand.o
  ### gcc -o myout1 main.o -I. -lstatic -L.
## 2- commands for dynamic
  ### gcc -shared -fpic -o libdynamic.so fib.c fact.c rand.c
  ### gcc -o myout2 main.c ./libdynamic.so 
    

