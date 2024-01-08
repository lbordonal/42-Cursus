<p align="center">
  <img src="https://github.com/lbordonal/lbordonal/blob/main/.titles/ft_printf.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/score-100%20%2F%20100-success?style=flat-square" />
	<img src="https://img.shields.io/github/languages/code-size/lbordonal/01-ft_printf?style=flat-square" />
	<img src="https://img.shields.io/github/languages/count/lbordonal/01-ft_printf?style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/lbordonal/01-ft_printf?style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/lbordonal/01-ft_printf?style=flat-square" />
</p>

<p align="center">
This repository contains code developed at 42 Porto for ft_printf Project, from 16/11/22 to 30/11/22.

<img src="https://github.com/lbordonal/lbordonal/blob/main/.42_badges/ft_printfe.png" align="right" />
<h2>
	 :notebook: Subject
</h2>
<a href="https://github.com/lbordonal/01-ft_printf/blob/main/Subject/en.subject.pdf">Click here</a> for the subject of this project.
<br /><br />

<h2 align="left">
	:zap: Function Prototype
</h2>
<p align="left">
  <img src="https://github.com/lbordonal/lbordonal/blob/main/.images/ft_printf_function.png">
</p>



<h2 align="left">
	:medal_sports: Mandatory Part
</h2>

**File conversions:** ```cspdiuxX%```

**`ft_printf.c`**
* `ft_printf` - main function.

**`ft_printf_utils.c`**
* `check_argument` - verify argument (char, string, pointer, decimal, integer, unsigned decimal, hexadecimal and %).

**`ft_args_csp.c`**
* `ft_putchar_count` - char ``` %c ```.
* `ft_putstr_count` - string  ``` %s ```.
* `ft_putptr_count` - pointer ``` %p ```.
* `ft_ptrlen` - return pointer length.
* `ft_putptr` - print pointer in hexadecimal.

**`ft_args_diu.c`**
* `ft_putnbr_count` - decimal ``` %d ``` and integer ``` %i ```.
* `ft_put_unsignedint_count` - unsigned decimal ``` %u ```.
* `ft_numlen` - return unsigned int length.
* `ft_uitoa` - ``` ft_itoa ``` function for unsigned int.

**`ft_args_xXpercent.c`**
* `ft_puthex_count` - hexadecimal lowercase ``` %x ``` and hexadecimal uppercase ``` %X ```.
* `ft_hexlen` - return hexadecimal length.
* `ft_puthex` - print hexadecimal.
* `ft_putpercent` - percent ``` %% ```.

**`libft_functions.c`**
* `ft_putchar_fd` - outputs the character to the given file descriptor.
* `ft_itoa` - allocates and returns a string representing the integer received as an argument.
* `absolute_value` - aux function to ``` ft_itoa ```.
* `ft_digit_count` - aux function to ``` ft_itoa ```.
<br /><br />

<h2 align="left">
	:memo: Tester
</h2>

- [printfTester][1]

[1]: https://github.com/Tripouille/printfTester

<br />
<br />
<hr/>
<p align="center">
This work is published under the terms of <a href="https://github.com/gcamerli/42unlicense">42 Unlicense</a>.
</p>
