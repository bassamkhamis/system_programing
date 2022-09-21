# Assignment 2 #Femto shell

## Create static and dynamic lib
  1. __commands for static__
     __gcc -c fib.c fact.c rand.c__
     __ar -rs libstatic.a fact.o fib.o rand.o__
     __gcc -o myout1 main.o -I. -lstatic -L.__
     __Result__
     ![](https://github.com/bassamkhamis/system_programing/blob/main/assignment_2/task2_out1.png)
  
  2. __commands for dynamic__
     __gcc -shared -fpic -o libdynamic.so fib.c fact.c rand.c__
     __gcc -o myout2 main.c ./libdynamic.so__ 
     __Result__
     ![](https://github.com/bassamkhamis/system_programing/blob/main/assignment_2/task2_out2.png)

