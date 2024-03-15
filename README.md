<h1 align="center" id="title">push_swap</h1>

<p align="center"><img src="https://socialify.git.ci/nkarapet42/push_swap/image?font=KoHo&logo=https%3A%2F%2Fgithub.com%2Fnkarapet42%2Fpush_swap%2Fassets%2F157054887%2F650e7778-1a23-4cdb-b793-2697f7a83cbc&name=1&owner=1&pattern=Brick%20Wall&theme=Light" alt="push_swap" /></p>

### Grade 125/100

### Description:
  Push_Swap is a project that involves sorting a set of integers using two stacks and a limited set of operations. This project challenges programmers to devise efficient algorithms for sorting without using any built-in sorting functions.

### Operations :
sa (swap a): Swap the first 2 elements at the top of stack a.</br>
Do nothing if there is only one or no elements.</br>
sb (swap b): Swap the first 2 elements at the top of stack b.</br>
Do nothing if there is only one or no elements.</br>
ss : sa and sb at the same time.</br>
pa (push a): Take the first element at the top of b and put it at the top of a.</br>
Do nothing if b is empty.</br>
pb (push b): Take the first element at the top of a and put it at the top of b.</br>
Do nothing if a is empty.</br>
ra (rotate a): Shift up all elements of stack a by 1.</br>
The first element becomes the last one.</br>
rb (rotate b): Shift up all elements of stack b by 1.</br>
The first element becomes the last one.</br>
rr : ra and rb at the same time.</br>
rra (reverse rotate a): Shift down all elements of stack a by 1.</br>
The last element becomes the first one.</br>
rrb (reverse rotate b): Shift down all elements of stack b by 1.</br>
The last element becomes the first one.</br>
rrr : rra and rrb at the same time.</br>

#### Makefile Available Targets:  
`make` or `make all` - Makes _push_swap_    
`make bonus` - Makes _checker_    
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes _push_swap_ , _checker_ and all the resulting object files  
`make re` - Deletes everything and rebuilds

### Basic Usage

Compile the files with `make` and run the program:
```bash
./push_swap 4 1 3 2
```
Output should be:
```
ra
pb
sa
pa
```
Compile the files with `make bonus` and run the program:
##### 1----------------------------------------------------------------------------------------------------------------------------
```bash
./push_swap 4 1 3 2 | ./checker 4 1 3 2
```
Output should be:
```
OK
```
##### 2----------------------------------------------------------------------------------------------------------------------------
```bash
./push_swap 4 1 3 2 | ./checker 4 1 3 2 5 8
```
Output should be:
```
KO
```
##### 3----------------------------------------------------------------------------------------------------------------------------
```bash
./checker a h
./push_swap a h
```
Output should be same:
```
Error
```
