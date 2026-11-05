*This project has been created as part of the 42 curriculum by moalnajj*

# printf
## Description
This project is about reimplementing pritnf (but it handles less conversions),and its goal is to use this function in upcoming projects and that what makes it so important because it saves a lot of effort when you want to print something.

## Instructions
In order to use this function you should follow these steps:

1.after cloning the repository,you run "make" command this while create a libft.a library and a libftprintf.a library.

2.you should include "ft_printf.h" library.

3.you should compile your main.c (or anyfile you used ft_printf in it) with libftprintf.a .

## Resources
I relied in understanding variadic functions on youtube videos such as :

- [codeVault](https://youtu.be/oDC208zvsdg?si=Dkp1wcdrARGqWiMG)

- [Oceano](https://youtu.be/7Sph8JlRo0g?si=B8k3DAezeRHT87v1)

I understood how can I compile another Makefile from my Makefile from stack overflow.
AI had a small contribution in my project,it was just in trying to think of edge cases i can try on my ft_printf function.

## Additional section

I used va_list struct so i can move through the variable number of arguments sent to the function.I begin with declaring a variable of type va_list and I should initilize it so it would point to the

first argument and I do so by calling the built in function (va_start),now the code moves through the sent string and type every char it faces until it face a '%' in this case it checks the next char 

and makes the va_list pointer move bytes depending on the char after '%',for example if it was 's' it will move as much bytes as the sizeof char pointer then it will call the suitable fuction to handle it.
