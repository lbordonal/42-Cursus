<p align="center">
  <img src="https://github.com/lbordonal/lbordonal/blob/main/.titles/get_next_line.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/score-125%20%2F%20100%20%E2%98%85-9cf?style=flat-square" />
	<img src="https://img.shields.io/github/languages/code-size/lbordonal/01-get_next_line?style=flat-square" />
	<img src="https://img.shields.io/github/languages/count/lbordonal/01-get_next_line?style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/lbordonal/01-get_next_line?style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/lbordonal/01-get_next_line?style=flat-square" />
</p>

<p align="center">
This repository contains code developed at 42 Porto for get_next_line Project, from 11/11/2022 to 21/11/2022.
</p>


<img src="https://github.com/lbordonal/lbordonal/blob/main/.42_badges/get_next_linem.png" align="right" />
<h2>
	 :notebook: Subject
</h2>
<a href="https://github.com/lbordonal/01-get_next_line/blob/main/Subject/en.subject.pdf">Click here</a> for the subject of this project.
<br /><br />


<h2 align="left">
	:zap: Function Prototype
</h2>

<p align="left">
  <img src="https://github.com/lbordonal/lbordonal/blob/main/.images/get_next_line_function.png">
</p>

<h2 align="left">
	:computer: Usage
</h2>
1- Clone this repository: </br>
<code>git clone https://github.com/lbordonal/01-get_next_line.git</code> </br></br>

2- Navigate to get_next_line folder: </br>
<code>cd 01-get_next_line/get_next_line/</code><br /><br />

3- Compile with: </br>
<code>cc -Wall -Werror -Wextra ../Tests/main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=size</code><br /><br />

If you do not set ```BUFFER_SIZE```, it will run with ```BUFFER_SIZE=42``` pre-defined at **`get_next_line.h`**.

4- Run with: </br>
<code>./a.out</code>

<br />

<h2 align="left">
	:medal_sports: Mandatory Part
</h2>

**`get_next_line.c`**

* `get_next_line`	- main function.
* `read_and_save`	- takes the opened file descriptor and saves on a "buffer" variable what readed from it.
* `get_line`		- extract the first line of the file.
* `ft_save`		- stores the updated file with whatever is left from the original file, except the line extracted.

**`get_next_line_utils.c`**

* `ft_strlen`		- find length of string.
* `ft_strchr`		- find first occurence of a character in string.
* `ft_strjoin`		- concatenate two strings into a new string using malloc to alocate memory.
* `ft_calloc`		- allocates memory for an array with '/0'.

**`get_next_line.h`**
<br /><br />

<h2 align="left">
	:trophy: Bonus Part
</h2>

**`get_next_line_bonus.c`**

* `get_next_line`	- main function with bonus part.
* `read_and_save`	- takes the opened file descriptor and saves on a "buffer" variable what readed from it.
* `get_line`		- extract the first line of the file.
* `ft_save`		- stores the updated file with whatever is left from the original file, except the line extracted.

**`get_next_line_utils_bonus.c`**

* `ft_strlen`		- find length of string.
* `ft_strchr`		- find first occurence of a character in string.
* `ft_strjoin`		- concatenate two strings into a new string using malloc to alocate memory.
* `ft_calloc`		- allocates memory for an array with '/0'.

**`get_next_line_bonus.h`**
</br><br />

<h2 align="left">
	:memo: Tester
</h2>

- [gnlTester][1]

[1]: https://github.com/Tripouille/gnlTester


<br />
<br />
<hr/>
<p align="center">
This work is published under the terms of <a href="https://github.com/gcamerli/42unlicense">42 Unlicense</a>.
</p>
