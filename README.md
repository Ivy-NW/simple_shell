# Project Name

Simple Shell Project

## Description

This project is a simple shell implementation, also known as a command-line interpreter. It provides a basic command-line interface where users can interact with the operating system by executing various commands and programs.

## Features

- Command execution: The shell allows users to execute commands and run programs by typing them into the command prompt.
- Input/output redirection: Users can redirect input and output streams, enabling them to read input from files or write output to files.
- Pipeline support: Users can create command pipelines by connecting multiple commands together, allowing the output of one command to serve as input to another.
- Built-in commands: The shell provides a set of built-in commands that can be executed directly, such as `cd` for changing directories or `exit` for terminating the shell.
- Error handling: The shell handles errors gracefully, providing appropriate error messages and returning exit codes.

## Technologies Used

- C programming language: The shell is implemented using the C programming language, taking advantage of its low-level system access and standard libraries.
- Operating system interfaces: The shell utilizes operating system interfaces, such as system calls, to interact with the underlying operating system and execute commands.

## Installation

1. Clone the repository.
2. Compile the shell source code using a C compiler. For example: `gcc shell.c -o shell`.
3. Run the compiled executable: `./shell`.
4. The shell prompt will be displayed, allowing you to enter commands and interact with the shell.
5. Enter `help` or `man` command within the shell to get information about available commands and their usage.

### Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

#### Interactive Mode

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

#### Non-Interactive Mode

In non-interactive mode, echo your desired command and pipe it into the program like this:

```sh
echo "ls" | ./shell
```

In non-interactive mode, the program will exit after finishing your desired command(s).

#### Included Built-Ins

Our shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.                                                                    |
| setenv [var][value] | Set an environment variable and value. If the variable exists, the value will be updated. |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the directory.                                                                     |
| help [built-in]     | Read documentation for a built-in.                                                        |

### Credits

All code has been written by [Ivy Njoroge](https://github.com/irisvlack) and [Marcus Ngugi](https://github.com/Marcusngugi25)

