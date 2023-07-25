# Simple Shell - README

![Shell Logo](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

## Introduction

This is a comprehensive and efficient implementation of a simple shell program. The shell, named "Simple Shell," provides a user-friendly command-line interface to interact with the operating system. It supports basic command execution, environment variables, aliases, and other essential shell functionalities.

## Features

- **Command Execution:** Simple Shell allows users to execute various commands with arguments, just like a standard shell.

- **Environment Variables:** Users can manage environment variables and access their values within the shell.

- **Aliases:** Simple Shell supports user-defined aliases for frequently used commands or command combinations.

- **Input Redirection:** The shell allows users to redirect standard input from files, enabling them to read commands from external sources.

- **Output Redirection:** Users can redirect standard output to files, enabling them to save command output to external files.

- **Piping:** Simple Shell supports command chaining with pipes, allowing users to send the output of one command as input to another command.

- **Interactive and Batch Modes:** The shell operates in interactive mode, providing an intuitive command prompt. Additionally, it can also execute commands from batch files in non-interactive mode.

- **Error Handling:** Proper error handling is implemented throughout the code to ensure graceful handling of unexpected scenarios.

- **Efficient Data Structures:** Simple Shell uses linked lists and dynamic memory allocation for efficient handling of data structures.

## How to Use

1. **Compilation:** To compile the Simple Shell program, use a C compiler with the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

2. **Launching the Shell:** Execute the compiled binary to start the Simple Shell:

```bash
./simple_shell
```

3. **Interactive Mode:** In interactive mode, the shell will present a command prompt where you can enter commands. Type `exit` to quit the shell.

```bash
$ ls
file1.txt file2.txt
$ pwd
/home/user/Documents
$ exit
```

4. **Batch Mode:** To execute commands from a batch file, provide the file as an argument to the shell:

```bash
./simple_shell batch_commands.txt
```

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

## License

Nil

## Acknowledgments

The Simple Shell project has been developed with inspiration from various open-source shell projects and POSIX shell standards.

## Contact

For any questions or suggestions, feel free to reach out to us at [isaacokwuzi@gmail.com](mailto:isaacokwuzi@gmail.com).

---

**Authors:** ebuka1017, Omarr-kh<br>
**Organization:** alx_africa<br>
**Date:** July, 2023
