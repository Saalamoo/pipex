# pipex

## About

The goal of this project is to reproduce the behavior of shell pipelines (`|`) using C and UNIX system calls. It mimics how a shell passes the output of one command as input to another, handling redirections and multiple processes.

For example, this shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

Becomes:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

## What It Does:
  - Reads from the infile
  
  - Executes cmd1, feeding it the contents of infile
  
  - Pipes the output of cmd1 into cmd2
  
  - Writes the final output to outfile

## Skills Learned:
  - System calls: fork(), pipe(), dup2(), execve()
  
  - File descriptor management
  
  - Process creation and synchronization
  
  - Handling command paths and arguments


## Compilation & Usage

Compile
  
```bash
make
```
This will generate the pipex executable.

Run

```bash
./pipex infile "command1" "command2" outfile
```

Example:

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```
This reads input.txt, searches for lines containing "hello", and writes the number of matching lines to output.txt.

## Bonus Features

Compile
  
```bash
make bonus
```
### Multiple Commands

The bonus version allows an arbitrary number of commands:

```bash
./pipex_bonus infile "cmd1" "cmd2" "cmd3" "cmd4" outfile
```

Example:

```bash
./pipex_bonus input.txt "tr a-z A-Z" "sort" "uniq -c" output.txt
```

### here_doc Support

The program can simulate the shell’s here_doc feature for inline input:

```bash
./pipex_bonus here_doc LIMITER "cmd1" "cmd2" outfile
```

Example:

```bash
./pipex_bonus here_doc END "cat" "wc -l" output.txt
```

Type some text, and finish by entering END on a new line. The final line count will be written to output.txt.

