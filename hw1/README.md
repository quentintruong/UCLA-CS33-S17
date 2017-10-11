Homework 1

[33 syllabus]

Do homework problems 2.64, 2.72, 2.73, and 2.82 from Bryant & O'Hallaron 3rd edition, with the following additions:

In problem 2.82, also analyze the following expressions:
F.
x >> 1 == (ux >> 1) + (ux & (-1 << 31))
G.
x % 128 == (x & 127)
Redo problem 2.73, this time using a call to the __builtin_add_overflow function available in GCC 5 and later; the third argument of the call should consist of the unary address-of operator '&' applied to a local variable. In other respects your function should continue to follow the bit-level integer coding rules.
Submit your homework answers as a gzipped tarball containing your answers to each problem, in the files hw1/2.64.c, hw1/2.72.txt, hw1/2.73.c, hw1/2.82.txt, and hw1/2.73-redo.c respectively. The .txt files should be plain ASCII text files with lines terminated by LF. The .c files should compile cleanly with shell commands like this:

gcc -m32 -fwrapv -O2 -Wall -Wextra -S hw1/2.73.c
As we will grade your submission with the latest version of GCC installed in /usr/local/cs/bin/ on the newer SEASnet GNU/Linux servers (lnxsrv06, lnxsrv07, and lnxsrv09), using the flags shown above, it would be wise to check your work on that platform. The shell command 'gcc --version' should output 'gcc (GCC) 6.3.0' or later.

To create your tarball, use the shell command:

tar -czf hw1.tar.gz hw1/2.64.c hw1/2.72.txt hw1/2.73.c hw1/2.82.txt hw1/2.73-redo.c