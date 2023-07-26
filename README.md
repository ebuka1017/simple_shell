# Simple Shell (Version 1.0+)

![Shell Logo](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [How to use](#how-to-use)
- [Built-in Commands](#built-in-commands)
- [Code Organization](#code-organization)
- [Requirements](#requirements)
- [Contact](#contact)
- [License](#license)



## Introduction

This is a comprehensive and efficient implementation of a simple shell program. The shell, named "Simple Shell," provides a user-friendly command-line interface to interact with the operating system. It supports basic command execution, environment variables, aliases, and other essential shell functionalities.

## Features

- **Command Execution:** Simple Shell allows users to execute various commands with arguments, just like a standard shell(e.g., `ls`, `cat`, `mkdir`, etc.) .

- **Environment Variables:** Users can manage environment variables and access their values within the shell.

- **Aliases:** Simple Shell supports user-defined aliases for frequently used commands or command combinations.

- **Input Redirection:** The shell allows users to redirect standard input from files, enabling them to read commands from external sources.

- **Output Redirection:** Users can redirect standard output to files, enabling them to save command output to external files.

- **Piping:** Simple Shell supports command chaining with pipes, allowing users to send the output of one command as input to another command.

- **Interactive and Batch Modes:** The shell operates in interactive mode, providing an intuitive command prompt. Additionally, it can also execute commands from batch files in non-interactive mode.

- **Error Handling:** Proper error handling is implemented throughout the code to ensure graceful handling of unexpected scenarios.

- **Efficient Data Structures:** Simple Shell uses linked lists and dynamic memory allocation for efficient handling of data structures.

- Handle arguments for the built-in `exit` command to exit the shell with a specific status.

## Installation

To use the Simple Shell, follow these steps:

1. Clone the repository to your local machine:
   
```
git clone <repository-url>
```

2. Compile the source code using a C compiler (e.g., `gcc`):
   
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

3. Run the shell:
   
```    
./hsh
```


## How to Use

Once the Simple Shell is running, you can enter commands as you would in a regular shell. The shell will display the prompt, and you can start entering commands:

```bash
$ ls
file1.txt file2.txt
```

To execute the built-in `exit` command with a specific status, use the following format:

```
$ exit status
```

Replace `status` with an integer that will be used to exit the shell. If no argument is provided, the shell will exit with status 0.

To execute commands from a batch file, provide the file as an argument to the shell:

```bash
./simple_shell batch_commands.txt
```

To Initialize a new environment variable or set a new one.
```bash
$ setenv VARIABLE VALUE
```

To remove an environment variable:
```bash
$ unsetenv VARIABLE
```
## Built-in Commands

The Simple Shell includes the following built-in commands:

1. `cd [directory]`: Change the current working directory to `directory`. If no argument is provided, change to the home directory.
2. `env`: Display the current environment variables.
3. `exit [status]`: Exit the shell with the specified `status`. If no argument is provided, exit with status 0.
4. `setenv & unsetenv`: initialize or modify a(n) environment variable && remove an environment variable
## Code Organization

The Simple Shell codebase is organized into multiple source files, each serving a specific purpose:

1. `main.c`: Contains the main function to initiate the shell.

2. `shell.c`: Implements the core functionalities of the shell, such as command execution and processing.

3. `input.c` and `input_func.c`: Handle user input and read commands from standard input or batch files.

4. `execute.c`: Executes commands and handles built-in commands.

5. `file_info.c`, `file_io_func.c`, and `mem_func.c`: Manage file and memory-related functionalities.

6. `func_hsh.c`, `my_chain.c`, `my_path.c`, and `prompt.c`: Implement various utility functions required by the shell.

7. `env_func1.c` and `env_func2.c`: Provide functionality for managing environment variables.

8. `alias_func.c`: Implement alias-related functions.

9. `err_func.c` and `err_func2.c`: Handle error reporting and error handling.

10. `str_func1.c`, `str_func2.c`, and `str_func3.c`: Contain string manipulation functions used throughout the shell.

11. `linked_list1.c` and `linked_list2.c`: Implement linked list data structure and related functions.

12. `emulator_func.c` and `utils.c`: Contain additional utility functions used by the shell.

13. `utils2.c`: Houses more utility functions used in the shell.

## Requirements

The Simple Shell program has been developed and tested on various Unix-like systems, including Linux and macOS. It requires a standard C compiler (GCC) and a POSIX-compliant operating system.


## Contact

For any questions or suggestions, feel free to reach out to us at [isaacokwuzi@gmail.com](mailto:isaacokwuzi@gmail.com).

---

**Authors:** [ebuka1017](https://github.com/ebuka1017), [Omarr-kh](https://github.com/Omarr-kh)<br>
**Organization:** [alx_africa](https://www.alxafrica.com/)<br>
**Date:** July, 2023

## License

The Simple Shell is open-source software released under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and distribute the code as permitted by the license.

