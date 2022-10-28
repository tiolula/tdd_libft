# Libft [![build](https://github.com/tiolula/tdd_libft/actions/workflows/build.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/build.yml) [![norminette](https://github.com/tiolula/tdd_libft/actions/workflows/norminette.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/norminette.yml)  [![test](https://github.com/tiolula/tdd_libft/actions/workflows/test.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/test.yml)  [![valgrind](https://github.com/tiolula/tdd_libft/actions/workflows/memoryleak.yml/badge.svg)](https://github.com/tiolula/tdd_libft/actions/workflows/memoryleak.yml)


> A library I hope someday will be useful to myself.

## 🎓 42

[42](https://en.wikipedia.org/wiki/42_(school)) learning style is not for everyone. In addition to programming in C (that is not something very easy and also not very common), since the beginning you are not allowed to use common libraries like, for example, stdio.h.

It's like swimming 🏊🏾 in a cold lake with your hands tied. But since you are learning to program, you can untie them by yourself. 

So [libft](https://github.com/tiolula/tdd_libft/blob/master/src/libft.h) is my own library, wich I hope will be useful until my last project of 42 curriculum.

### 📚 Libft Content

* 23 functions that implements the original ones and do not use any external function: 

	* [isalpha](https://github.com/tiolula/tdd_libft/blob/master/src/ft_isalpha.c)
	* [isdigit](https://github.com/tiolula/tdd_libft/blob/master/src/ft_isdigit.c)
	* [isalnum](https://github.com/tiolula/tdd_libft/blob/master/src/ft_isalnum.c)
	* [isascii](https://github.com/tiolula/tdd_libft/blob/master/src/ft_isascii.c)
	* [isprint](https://github.com/tiolula/tdd_libft/blob/master/src/ft_isprint.c)
	* [strlen](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strlen.c)
	* [memset](https://github.com/tiolula/tdd_libft/blob/master/src/ft_memset.c)
	* [bzero](https://github.com/tiolula/tdd_libft/blob/master/src/ft_bzero.c)
	* [memcpy](https://github.com/tiolula/tdd_libft/blob/master/src/ft_memcpy.c)
	* [memmove](https://github.com/tiolula/tdd_libft/blob/master/src/ft_memmove.c)
	* [strlcpy](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strlcpy.c)
	* [strlcat](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strlcat.c)
	* [toupper](https://github.com/tiolula/tdd_libft/blob/master/src/ft_toupper.c)
	* [tolower](https://github.com/tiolula/tdd_libft/blob/master/src/ft_tolower.c)
	* [strchr](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strchr.c)
	* [strrchr](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strrchr.c)
	* [strncmp](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strncmp.c)
	* [memchr](https://github.com/tiolula/tdd_libft/blob/master/src/ft_memchr.c)
	* [memcmp](https://github.com/tiolula/tdd_libft/blob/master/src/ft_memchr.c)
	* [strnstr](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strnstr.c)
	* [atoi](https://github.com/tiolula/tdd_libft/blob/master/src/ft_atoi.c)
	* [calloc](https://github.com/tiolula/tdd_libft/blob/master/src/ft_calloc.c)
	* [strdup](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strdup.c)

* 2 functions that implements the original ones and use malloc():

	* [calloc](https://github.com/tiolula/tdd_libft/blob/master/src/ft_calloc.c)
	* [strdup](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strdup.c)

* 11 functions that are either not in the libc, or that are part of it but in a different form:

	* [ft_substr](https://github.com/tiolula/tdd_libft/blob/master/src/ft_substr.c)
	* [ft_strjoin](https://github.com/tiolula/tdd_libft/blob/master/src/ft_strjoin.c)
	* ft_strtrim [TODO]
	* ft_split [TODO] 🔥
	* [ft_itoa](https://github.com/tiolula/tdd_libft/blob/master/src/ft_itoa.c)
	* ft_strmapi [TODO]
	* [ft_striteri](https://github.com/tiolula/tdd_libft/blob/master/src/ft_striteri.c)
	* [ft_putchar_fd](https://github.com/tiolula/tdd_libft/blob/master/src/ft_putchar_fd.c)
	* [ft_putstr_fd](https://github.com/tiolula/tdd_libft/blob/master/src/ft_putstr_fd.c)
	* [ft_putendl_fd](https://github.com/tiolula/tdd_libft/blob/master/src/ft_putendl_fd.c)
	* [ft_putnbr_fd](https://github.com/tiolula/tdd_libft/blob/master/src/ft_putnbr_fd.c)

------------------------

## 🥋 42 as a dojo

> A [dōjō](https://en.wikipedia.org/wiki/Dojo) (道場, Japanese pronunciation: [doꜜː(d)ʑoː][note 1]) is a hall or place for immersive learning or meditation. This is traditionally in the field of martial arts, but has been seen increasingly in other fields, such as meditation and software development. The term literally means "place of the Way" in Japanese.

Once I already know something about programming, I decided to use my libft as a training space for techniques I like, for example:

👇🏽

### 🔴🟢🟢 TDD

One of the practices I decided to try on my libft fully is [TDD - Test Driven Development](http://www.extremeprogramming.org/rules/testfirst.html). 🤦🏽‍♂️

In this repo you can see the consequences of that.

If you don't know anything about [TDD](http://www.extremeprogramming.org/rules/testfirst.html), I recommend you read about [Extreme Programming](http://www.extremeprogramming.org/index.html).

👍🏽

### ✅ Continuous Integration

Also following [Extreme Programming](http://www.extremeprogramming.org/index.html) practices, I [configured github actions](http://www.extremeprogramming.org/rules/dedicated.html) to build the project, run my [tests](http://www.extremeprogramming.org/rules/unittests.html), run valgrind to check memory leaks and finally run norminette, wich validates the oficial 42 [standards](http://www.extremeprogramming.org/rules/standards.html). Maybe we can call it [Continuous Integration](http://www.extremeprogramming.org/rules/integrateoften.html). Can we?

🤔

### 👬🏽 Pair Programming

I never liked to code alone. I know I can do it, but why using just one mind if I can use several? My libft was almost 100% [pair programmed](http://www.extremeprogramming.org/rules/pair.html), with several people.

Most part of the paired code was made in [this repo](https://github.com/tiolula/dojozin_libft). We can say that all the code on it is [collective](http://www.extremeprogramming.org/rules/collective.html).

🙌🏽
