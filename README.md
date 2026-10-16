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

## 04 · A process and its children

The notes in `04/4.c` walk through where each part of a program lives once it runs:

```
 high addresses
┌──────────────┐
│    stack     │   local variables
│      ↓       │
│              │
│      ↑       │
│     heap     │   whatever malloc hands out
├──────────────┤
│   globals    │   int b = 2;
├──────────────┤
│     text     │   the compiled code
└──────────────┘
 low addresses
```

The code that runs forks five times to build this tree, and every process prints its own ID and its parent's:

```
Father
├── A
│   └── C
└── B
    ├── D
    └── E
```

```
$ ./a.out
I'm Father, Me: 42569, Parent: 42568
I'm child A Me: 42570, Parent: 42569
I'm child B Me: 42571, Parent: 42569
I'm child C Me: 42572, Parent: 42570
I'm child D Me: 42573, Parent: 42571
I'm child E Me: 42574, Parent: 42571
```

The order changes from run to run. The father never waits for its children, so one that prints after the father has exited reports `Parent: 1`. Redirect the output to a file and the father's line appears several times: `stdout` is buffered there, and `fork()` copies the unflushed buffer into each child.

## quera · Judged problems

| File | Problem | Example |
| --- | --- | --- |
| [`1.factorial.c`](quera/1.factorial.c) | *n*!, recursively | `5` → `120` |
| [`2.fisaghores.c`](quera/2.fisaghores.c) | Can three lengths form a right triangle? | `3 4 5` → `YES` |
| [`3.fibo.c`](quera/3.fibo.c) | For 1 to *n*, print `+` for a Fibonacci number and `-` otherwise | `8` → `+++-+--+` |
| [`4.diamond.c`](quera/4.diamond.c) | A diamond of stars | below |
| [`5.tri.c`](quera/5.tri.c) | Pascal's triangle | below |
| [`6.complex.c`](quera/6.complex.c) | (*a* + *x*)<sup>*n*</sup> summed term by term with binomial coefficients | `1 2 3` → `27` |
| [`fork1.c`](quera/fork1.c), [`fork2.c`](quera/fork2.c) | The process tree from `04/` | |

<table>
<tr>
<td valign="top">

```
$ echo 3 | ./4.diamond
   *
  ***
 *****
*******
 *****
  ***
   *
```

</td>
<td valign="top">

```
$ echo 5 | ./5.tri
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

</td>
</tr>
</table>

`fork2.c` differs from `fork1.c` in having each parent print its children's IDs too. [`hs/`](quera/hs) has other takes on some of the problems: the factorial (`6.c`), the right-triangle check (`py.c`), an earlier version of the binomial sum (`old6.c`) and the process tree (`frok.f.c`).

## Building

Any C compiler on Linux or macOS will do. `fork()` is POSIX, so on Windows use WSL.

```bash
gcc quera/5.tri.c -o tri
echo 5 | ./tri
```

The programs that call `pow` also need the math library, so add `-lm` for those. The third session is split across two files, which compile together:

```bash
gcc 03/03.c 03/03_math.c -o add
```
