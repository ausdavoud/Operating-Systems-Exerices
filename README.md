# Operating Systems Exercises

C exercises from an operating systems course, autumn 2024. The first sessions cover the C the course leans on: pointers, input, and splitting a program across files. The fourth gets to the operating system itself, with how a process sits in memory and how `fork()` grows a tree of processes. Alongside them is a set of judged problems from [Quera](https://quera.org).

## What's in each folder

| Folder | What it covers |
| --- | --- |
| [`01/`](01) | Operators (`&` versus `&&`), `switch`, `for` and `goto`, and why a function can't change a variable passed to it by value |
| [`02/`](02) | Pointers, pointers to pointers, and the difference between a `char` array and a string literal |
| [`03/`](03) | Reading input with `scanf` and `getline`, bitwise operators, and a program split into a header, a source file and a Makefile |
| [`04/`](04) | How a process is laid out in memory, `malloc` and `free`, and a tree of processes made with `fork()` |
| [`quera/`](quera) | Six judged problems and two `fork()` assignments |
| [`quera/hs/`](quera/hs) | Other versions of a few of the same problems |

In `01/`, `03/` and `04/` most snippets are kept as comments, one per idea, with a single part left to run.

## Building

Any C compiler on Linux or macOS will do. `fork()` is POSIX, so on Windows use WSL.

```bash
gcc quera/5.tri.c -o tri
echo 5 | ./tri
```

The programs that call `pow` also need the math library, so add `-lm` for those. The third session is split across two files and builds with `make`:

```bash
cd 03 && make
```
