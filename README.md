
# ft_printf

## Overview

**ft_printf** is a custom implementation of the standard C `printf` function, developed as part of the 42 curriculum. The goal of this project is to recreate the functionality of `printf` from scratch, handling various format specifiers, flags, and conversions, while gaining a deeper understanding of variadic functions and string formatting in C.

## Table of Contents

- [Getting Started](#getting-started)
- [Supported Conversions](#supported-conversions)
- [Usage](#usage)
- [Makefile](#makefile)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

To compile and use `ft_printf`, you need:
- A Unix-like operating system (Linux, macOS, etc.)
- `gcc` or another C compiler
- `make`

### Installation

Clone the repository to your local machine:

```bash
git clone git@github.com:Mohamadaliibrahim/ft_printf.git
```
Enter the file:
```bash
cd ft_printf/ft_printf
```

### Building the Library

To compile the library, simply run:

```bash
make
```

This will generate the `libftprintf.a` static library file, which you can link against in your projects.

## Supported Conversions

The `ft_printf` function supports the following format specifiers:

- **Characters and Strings:**
  - `%c` - Single character
  - `%s` - String of characters

- **Integer Types:**
  - `%d` or `%i` - Signed integer
  - `%u` - Unsigned integer

- **Hexadecimal:**
  - `%x` - Unsigned hexadecimal (lowercase)
  - `%X` - Unsigned hexadecimal (uppercase)

- **Pointers:**
  - `%p` - Pointer address

- **Percentage:**
  - `%%` - Literal `%` character

### Flags

The following flags are supported:

- `-` : Left-justify the output within the given field width.
- `0` : Zero-pad the output to the specified width.
- `.` : Precision specifier for strings and numbers.
- `#` : Alternative form for `%x` and `%X` (adds `0x` or `0X`).
- ` ` : A blank space before a positive number or an empty string.
- `+` : Forces a sign (`+` or `-`) to be used on a number.

## Usage

To use `ft_printf` in your project, include the library header:

```c
#include "inc/ft_printf.h"
```

Use it just like you would use `printf`:

```c
ft_printf("Hello, %s!\n", "world");
ft_printf("The number is %d.\n", 42);
```

Compile your project by linking the `libftprintf.a` file:

```bash
gcc -Wall -Wextra -Werror -o my_program my_program.c -L. -lftprintf
```

## Makefile

The `Makefile` includes the following rules:

- `make` or `make all`: Compiles the library.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the compiled library.
- `make re`: Cleans and recompiles the library.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please fork the repository and create a new branch for your feature or bug fix. Submit a pull request once your changes are ready.

1. Fork the project.
2. Create your feature branch: `git checkout -b feature/my-feature`
3. Commit your changes: `git commit -m 'Add some feature'`
4. Push to the branch: `git push origin feature/my-feature`
5. Open a pull request.

### Author

This project was developed by **mohamibr** as part of the 42 school curriculum.
