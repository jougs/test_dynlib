# test_dynlib

This is a simple test program to understand the effects of
`LD_PRELEAD`ing a library versus `dlopen`ing it and how to use a
symbol lookup to call a function from the `dlopen`ed library.

You can configure the program sources with `cmake .`, compile it with
`make`, and run it with either `LD_PRELOAD=libtwo.so ./main` or just
*plain* as `./main`.
