# Assignment 2 #Femto shell

## Create static and dynamic lib
  ## commands for static
    1. gcc -c fib.c fact.c rand.c
    2. ar -rs libstatic.a fact.o fib.o rand.o
    3. gcc -o myout1 main.o -I. -lstatic -L.
    4. Result



![](https://github.com/bassamkhamis/system_programing/blob/main/assignment_2/task2_out1.png)
     
  
  ## commands for dynamic
    1. gcc -shared -fpic -o libdynamic.so fib.c fact.c rand.c
    2. gcc -o myout2 main.c ./libdynamic.so
    3. Result
    
    
     
     
![](https://github.com/bassamkhamis/system_programing/blob/main/assignment_2/task2_out2.png)

