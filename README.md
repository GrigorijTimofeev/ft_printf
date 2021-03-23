# ft_printf
Writing the cut functionality of a well-known printf from C

My function mimic the following printf conversions:
- c
- s
- p
- d
- i
- u
- x
- X
- %

And the following flags:
- -(minus)
- 0
- .
- *(asterisk)

# Compiling

Type 
```
make
```
in terminal and then add the library(libftprintf.a) to your project

# Usage example

```
ft_printf("My age is %-.d", 20);
```
