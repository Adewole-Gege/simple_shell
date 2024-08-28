# Simple Shell

## Overview
The Simple Shell project is a basic command-line interpreter that replicates the functionality of a Unix shell. It reads user input, interprets commands, and executes them using system calls.

## Features
- Execute built-in commands
- Handle basic command-line arguments
- Support for simple shell commands like `ls`, `pwd`, `cd`, etc.
- Memory management with no leaks
- Error handling for command not found

## Requirements
- Ubuntu 20.04 LTS
- GCC compiler with options `-Wall -Werror -Wextra -pedantic -std=gnu89`

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/Adewole-Gege/simple_shell.git
Simple Shell
Overview
This project is a simple UNIX command line interpreter, developed as part of the Holberton School curriculum. The goal of this shell is to emulate the basic functionalities of a UNIX shell, allowing users to interact with the system by executing commands.

Features
Basic Command Execution: Executes basic commands typed by the user.
Prompt Display: Continuously displays a prompt for the user to input commands.
Error Handling: Displays an error message if a command cannot be found.
End of File Handling: Handles the "end of file" condition (Ctrl+D) gracefully.
Requirements
Operating System: Ubuntu 20.04 LTS
Compiler: GCC with the options -Wall -Werror -Wextra -pedantic -std=gnu89
Code Style: Must adhere to the Betty coding style.
Usage
To compile and run the shell:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
./simple_shell
