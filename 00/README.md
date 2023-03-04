# Experiment 00

**March 3rd, 2023 after dinner and TV**

In this experiment I drew a single line and two segments on a black window.  
Note that the two connected segments were drawn by `XDrawSegments` instead of `XDrawLines`.


## Compiling on OS X

On OS X 10.11.6, I managed to compile with `clang` using the headers from Tk framework 8.5 under the `CommandLineTools` tree and the `X11.6` library from `/usr/X11/lib/`, but on execution it prompted me to install XQuartz runtime.  
Yes, I just picked up whatever header/lib looked nice after a `find`.

After installation, a new `/opt/X11/` folder was created and `/usr/X11` is now a symlink to it. Running the previously compiled program correctly started XQuartz, but resulted in a segfault.  
Current compilation command is
```
clang -o ./runme.out -I/opt/X11/include -L/opt/X11/lib -lX11 00/cyan_line_and_segments.c
```

A nice xHTML/PDF/PS/txt manual and reference comes together with the XQuartz runtime installation, but I confess not reading it, `Ctrl+F`-ing the function references that sounded interesting for my goals.


### Acknowledgements

Many thanks to https://github.com/AlexViaColl/x11-open-window for popping up while I was searching how to draw simple graphics with X11 on OS X.


### More fun

Check https://www.geeks3d.com/20120102/programming-tutorial-simple-x11-x-window-code-sample-for-linux-and-mac-os-x/ for printing an info window for your system (I haven't tried it).
