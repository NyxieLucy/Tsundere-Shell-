# Tsundere Shell

A tiny, intentionally silly command runner written in C. It behaves like a shell with a rude attitude, prints teasing messages, and executes commands in a very minimal way.

This project is more of a playful experiment than a serious shell replacement. It is simple, lightweight, and meant to be a fun toy project.

## Features

- Runs commands using the system shell
- Prints a sarcastic prompt after each command
- Accepts command strings from arguments or user input
- Built in C with no extra dependencies
- Meant as a small, humorous coding project

## How it works

The program loops through command-line arguments, calls `system()` for each one, prints a taunting line, and then asks for another command. It is intentionally basic and not designed for secure or production use.

The current implementation is a minimal proof of concept. It is not a safe or fully featured shell and should not be treated as one.

## Build

From the repository root:

```bash
gcc src/main.c -o tsundere-shell
```

## Run

```bash
./tsundere-shell "ls -la"
```

You can also pass multiple commands:

```bash
./tsundere-shell "pwd" "whoami" "uname -a"
```

## Example output

```text
$ ./tsundere-shell "ls -la"
 there, i executed your dumb command, hmpf!
(⸝⸝¬`‸´¬⸝⸝)~ 
```

## Notes

This project is intentionally rough around the edges. The current code uses `scanf()` and `system()`, which are not ideal for real shell behavior or security. The repository notes suggest replacing those with safer alternatives such as `getline()` and `fork()` + `execvp()` + `waitpid()`.

## Project status

This is a small toy shell for learning, experimentation, and humor. It is not meant to be a real shell implementation.

## License

No license has been specified in the repository yet.
