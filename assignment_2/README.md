# Assignment 2 #Femto shell

## Create static and dynamic lib
  ## __commands for static__
    1. __gcc -c fib.c fact.c rand.c__
    2. __ar -rs libstatic.a fact.o fib.o rand.o__
    3. __gcc -o myout1 main.o -I. -lstatic -L.__
    4. __Result__



![](https://github.com/bassamkhamis/system_programing/blob/main/assignment_2/task2_out1.png)
     
  
  ## __commands for dynamic__
    1. __gcc -shared -fpic -o libdynamic.so fib.c fact.c rand.c__
    2. __gcc -o myout2 main.c ./libdynamic.so__ 
    3. __Result__
    
    
     
     
![](https://github.com/bassamkhamis/system_programing/blob/main/assignment_2/task2_out2.png)

