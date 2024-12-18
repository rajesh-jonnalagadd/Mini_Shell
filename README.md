# Mini_Shell

#Description:-

            The MiniShell project is a simplified implementation of a Unix-like shell for Linux. It allows users to interact with the system by executing commands, handling built-in functions, and supporting redirections, pipes, and signals.

This project is designed to deepen understanding of process management, system calls, and the fundamentals of a Unix shell.

#Features

Command Execution

Executes simple Unix commands (e.g., ls, pwd, echo, clear).

#Built-in Commands

Supports common built-in commands:

cd    : Change directory.

pwd   : Print current working directory.

exit  : Exit the shell.

clear : Clear the terminal.

#Pipes

Implements piping to connect commands (e.g., ls | grep file).

#Environment Variables

Handles environment variables using $ (e.g., $SHELL).

#Signal Handling

Manages signals like:

Ctrl+C (SIGINT): Interrupt the current process.

Ctrl+Z (SIGTSTP): Suspend the current process.

#Error Handling

Displays appropriate error messages for invalid inputs or operations.

#Requirements

Operating System: Linux

Language: C

Compiler: GCC (GNU Compiler Collection)

Compilation

To compile the project, use the following command:

$ make

Running the Shell

Start the shell by executing the compiled binary:

$ ./mini_shell

#License

This project is licensed under the MIT License. You are free to use, modify, and distribute this software as per the terms of the license.

