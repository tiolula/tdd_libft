# libft [![build](https://github.com/tiolula/tdd_libft/actions/workflows/build.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/build.yml) [![norminette](https://github.com/tiolula/tdd_libft/actions/workflows/norminette.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/norminette.yml)  [![test](https://github.com/tiolula/tdd_libft/actions/workflows/test.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/test.yml)  [![valgrind](https://github.com/tiolula/tdd_libft/actions/workflows/memoryleak.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/memoryleak.yml)


A library I hope someday will be useful to myself.

## 42 Style

[42](https://en.wikipedia.org/wiki/42_(school)) learning style is not for everyone. In addition to programming in C (that is not something very easy and also not very common), since the beginning you are not allowed to use common libraries like, for example, stdio.h.

It's like swimming in a cold lake with your hands tied. But since you are learning to program, you can untie them by yourself. 

Libft is my own library, wich I hope will be useful until my last project of 42 curriculum.

### Libft Content

23 functions that implements the original ones and do not use any external function: 

• isalpha
• isdigit
• isalnum
• isascii
• isprint
• strlen
• memset
• bzero
• memcpy
• memmove
• strlcpy
• strlcat
• toupper
• tolower
• strchr
• strrchr
• strncmp
• memchr [TODO]
• memcmp [TODO]
• strnstr
• atoi
• calloc
• strdup

2 functions that implements the original ones and use malloc():

• calloc [TODO]
• strdup [TODO]

11 functions that are either not in the libc, or that are part of it but in a different form:

• ft_substr
• ft_strjoin
• ft_strtrim [TODO]
• ft_split [TODO]
• ft_itoa
• ft_strmapi [TODO]
• ft_striteri [TODO]
• ft_putchar_fd
• ft_putstr_fd
• ft_putendl_fd
• ft_putnbr_fd

## TDD

Once I already know something about programming, I also decided to tie my legs and develop my Libft fully using [TDD - Test Driven Development](http://www.extremeprogramming.org/rules/testfirst.html). 

In this repo you can see the consequences of that.

If you don't know anything about [TDD](http://www.extremeprogramming.org/rules/testfirst.html), I recommend you read about [Extreme Programming](http://www.extremeprogramming.org/index.html).