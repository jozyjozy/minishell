# Minishell

Minishell is a simple Unix-like shell implemented as part of the curriculum at **École 42**. It aims to replicate basic functionalities of a shell such as handling user input, executing commands, managing processes, and handling built-in commands like `echo`, `cd`, `pwd`, and more.

## Introduction

Minishell is a project that provides hands-on experience in building a Unix shell. It was developed as part of the **42 School** curriculum to learn how to interact with the operating system through system calls and to manage user input and processes.

The shell allows users to interact with the system by executing commands, redirecting input/output, and supporting basic shell features such as piping.

## Features

- **Command Execution**: Execute standard system commands.
- **Built-in Commands**: Support for `echo`, `cd`, `pwd`, and `exit`.
- **Input Parsing**: Handles user input and parses it into commands.
- **Process Management**: Executes processes and manages their life cycle.
- **Piping**: Supports piping between commands.
- **Redirection**: Handle input and output redirection using `>` and `<`.
- **Signals**: Proper handling of signals like `Ctrl-C` and `Ctrl-D`.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/jozyjozy/minishell.git
   cd minishell
   make
