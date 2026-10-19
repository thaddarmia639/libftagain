*This project has been created as part of the 42 curriculum by <thsi>.*

# Description

## Goal

The goal of this project is to understand how commonly used C standard library
functions work internally by reimplementing them from scratch. This project
provides **Libft**, a custom C library containing reimplementations of `libc`
functions (prefixed with `ft_`) along with additional utility functions for
string manipulation, memory handling, and singly linked lists. The resulting
library, `libft.a`, is reused throughout the rest of the 42 curriculum.

## Brief Overview

The implementation is organized into three parts:

* **Part 1 — Libc reimplementations**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`,
  `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`,
  `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`,
  `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`,
  `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`
* **Part 2 — Additional functions**: `ft_substr`, `ft_strjoin`, `ft_strtrim`,
  `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`,
  `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
* **Part 3 — Linked lists**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`,
  `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`,
  `ft_lstmap`

## Algorithm and Data Structure

Most functions in Part 1 and Part 2 operate on raw character or byte buffers,
traversed with a pointer or index rather than any complex structure. A few
functions rely on specific techniques worth noting:

* **`ft_split`** uses a two-pass approach: the string is first scanned once
  to count how many words it contains (so the output array can be sized
  correctly), then scanned again to extract each word into its own allocated
  string. If any allocation fails partway through, everything allocated so
  far is freed before returning `NULL`, to avoid memory leaks.
* **`ft_itoa`** and **`ft_putnbr_fd`** both handle the fact that digits are
  naturally extracted from least significant to most significant (via `% 10`
  and `/ 10`), while they need to be produced in the opposite order.
  `ft_itoa` writes into a buffer from the back forward; `ft_putnbr_fd` uses
  recursion, printing higher place-value digits only after the recursive
  call for the remaining digits has returned.
* **`ft_calloc`** checks for multiplication overflow before allocating, and
  zeroes the allocated memory using `ft_bzero`.

Part 3 introduces the `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Each node stores a generic `void *content` and a pointer to the next node.
List functions (`ft_lstclear`, `ft_lstmap`, etc.) rely on functions passed in
by the caller (`del`, `f`) to operate on `content` without needing to know
its actual type.

# Instructions

## Compilation

The project includes a `Makefile` for building the library.

To compile the project:

```bash
make
```

This produces the static library:

```text
libft.a
```

To remove object files:

```bash
make clean
```

To remove object files and the compiled library:

```bash
make fclean
```

To recompile everything from scratch:

```bash
make re
```

## Usage

Copy the `libft` folder into your project, then include the header in your
source files:

```c
#include "libft.h"
```

Compile your program together with the library:

```bash
cc main.c libft.a -o your_program
```

Or, in your project's own `Makefile`:

```makefile
LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

your_program: $(LIBFT) other_objects.o
	$(CC) other_objects.o -L$(LIBFT_DIR) -lft -o your_program
```

# Resources

## References

```bash
https://man7.org/linux/man-pages/dir_section_3.html

https://github.com/42School/norminette

https://man.openbsd.org/string.3

https://valgrind.org/docs/manual/manual.html
```

Kernighan & Ritchie, *The C Programming Language* (2nd ed.) — classic
reference for pointers, memory, and string handling in C.

## AI Usage

An AI assistant (Claude) was used to draft this README file and for conceptual understanding of certain functions. Source codes, Makefile and functions were written independently without AI usage.
 

# Testing

Functions can be tested by comparing their output and return values against
the standard `libc` equivalents where applicable.

For example:

```c
printf("%d\n", ft_atoi("42"));
printf("%d\n", atoi("42"));

char *s = ft_strdup("hello");
printf("%s\n", s);
free(s);

char *n = ft_itoa(INT_MIN);
printf("%s\n", n);
free(n);
```

Testing should include normal values as well as edge cases such as:

* Empty strings (`""`)
* `NULL` inputs, where relevant
* `INT_MIN` / `INT_MAX`
* Zero-length or zero-size allocations (`ft_calloc(0, 0)`)
* Overlapping memory regions (`ft_memmove`)
* Strings made entirely of delimiter characters (`ft_split`, `ft_strtrim`)
* Multiple nodes, single-node, and empty lists (Part 3 functions)

Memory correctness (no leaks, no invalid access) was additionally checked
with Valgrind.
