# ft_printf

<br>
<img align="left" height="250" src="https://github.com/42kmira/ft_printf/blob/master/resources/Untitled.png" />
<br>

In this project we are introduced to va_args in C. We are suppose to partially replicate the functionality
of the stdio function printf. As a bonus I also correctly implemented the printing out of floating point numbers.
This was done through understanding the IEEE [double precision](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) and [extended precision](https://en.wikipedia.org/wiki/Extended_precision) floating point formats.


This implementation is also faster than most other cadets because of the usage of a statically defined
buffer. It is somewhat comparable in speed to the actual printf, except for printing out of floating point numbers,
this is however with my limited testing, partial functionality, and maintaining a certain code style. The buffer allows minimal calls to the write function, a costly system function that interacts with the kernel. Printf writes to stdout which is line buffered, mine is block buffered, whose limit is defined by the macro BUFFER.

Supported specifiers include:
- d or i
- u
- o
- x
- X
- f
- c
- p
- %

With the following datatype modifiers
- hh
- h
- l
- l

The following flags are also supported:
- -
- +
- ' '
- #
- 0

And lastly width and .precision is also supported.

Running make all creates an library .a file that can be compile with other programs to include this program.