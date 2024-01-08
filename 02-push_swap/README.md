<p align="center">
  <img src="https://github.com/lbordonal/lbordonal/blob/main/.titles/push_swap.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/score-84%20%2F%20100-success?style=flat-square" />
	<img src="https://img.shields.io/github/languages/code-size/lbordonal/02-push_swap?style=flat-square" />
	<img src="https://img.shields.io/github/languages/count/lbordonal/02-push_swap?style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/lbordonal/02-push_swap?style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/lbordonal/02-push_swap?style=flat-square" />
</p>

<p align="center">
This repository contains code developed at 42 Porto for push_swap Project, from 03/01/2023 to 13/04/2023.
</p>

<img src="https://github.com/lbordonal/lbordonal/blob/main/.42_badges/push_swape.png" align="right" />
<h2>
	 :notebook: Subject
</h2>
<a href="https://github.com/lbordonal/02-push_swap/blob/main/Subject/en.subject.pdf">Click here</a> for the subject of this project.
<br /><br />

<h2 align="left">
	:computer: Usage
</h2>
1- Clone this repository: </br>
<code>git clone https://github.com/lbordonal/02-push_swap.git</code> </br></br>

2- Navigate to push_swap folder: </br>
<code>cd 02-push_swap/push_swap/</code><br /><br />

3- Run with make: </br>
<code>make</code><br /><br />

4- Run push_swap with: </br>
<code>./push_swap number_1 number_2 ... </code> or <code>ARG="number_1 number_2 ..."; ./push_swap $ARG</code><br /><br />

5- If you want to use the tester, run with: </br>
<code>ARG="number_1 number_2 ..."; ./push_swap $ARG | ./checker_linux $ARG</code><br /><br />

6- If you want to see how many moves it takes to sort, run with: </br>
<code>ARG="number_1 number_2 ..."; ./push_swap $ARG | wc -l</code><br /><br />


<h2 align="left">
	:medal_sports: Mandatory Part
</h2>

<h3 align="left">
push_swap Rules:
</h3>
The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

Moves:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

<h3 align="left">
Evaluation:
</h3>

* **Sorting 3 values:** no more than 3 moves.
* **Sorting 5 values:** no more than 12 moves.
* **Sorting 100 values:** grade from 1 to 5 points depending on the number of moves:

  * 5 points for less than 700
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500

* **Sorting 500 values:** grade from 1 to 5 points depending on the number of moves:

  * 5 points for less than 5500
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

<h3 align="left">
Sort Algorithms:
</h3>

* **Sorting 3 values:** <code>ft_sort_three</code> → brute force, no more than 6 possible combinations to sort 3 numbers.
* **Sorting 5 values:** <code>ft_sort_five</code> → search for the minimum and the maximum values in stack A, push it to stack B → sort stack A with <code>ft_sort_three</code> → push to stack A the elements in stack B, inserting them in the correct position in stack A.
* **Sorting less than 60 values:** <code>ft_crazy_sort</code> → find the lowest element in stack A and push it to stack B → do it again until stack A has only one element → pushback to stack A all the elements from stack B.
* **Sorting more than 60 values:** <code>ft_sort</code> → Radix sort.


<br />
<br />
<hr/>
<p align="center">
This work is published under the terms of <a href="https://github.com/gcamerli/42unlicense">42 Unlicense</a>.
</p>

