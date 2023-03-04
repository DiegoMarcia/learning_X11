#include <stdbool.h>
#include <X11/Xlib.h>

int main() {

    /* Instad of using XDefaultGC for the default graphics context, I'm making my own */
    XGCValues my_GCVals;
    my_GCVals.foreground = 0x0000FFFF;  /* Cyan-ish */
    my_GCVals.line_width = 1;
    my_GCVals.line_style = LineSolid;

    /* GC attribute value mask */
    unsigned long my_GCMask = GCForeground|GCLineWidth|GCLineStyle;

    /* These two are connected, yet independent */
    XSegment  my_edgeA = { .x1 = 100, .y1 = 100, .x2 = 150, .y2 = 150 };
    XSegment  my_edgeB = { .x1 = 150, .y1 = 150, .x2 = 150, .y2 = 100 };

    XSegment my_edges[2] = { my_edgeA, my_edgeB };
    /* my_edges[0] = my_edgeA;
    my_edges[1] = my_edgeB; */

    /* Next 18 lines are from AlexViaColl/x11-open-window */
    Display *display = XOpenDisplay(NULL);
    
    Window window = XCreateSimpleWindow(
        display,
        XDefaultRootWindow(display),    // parent
        0, 0,                           // x, y
        800, 600,                       // width, height
        0,                              // border width
        0x00000000,                     // border color
        0x00000000                      // background color
    );
    
    XStoreName(display, window, "Amazing X11 Window");
    
    XSelectInput(display, window, KeyPressMask|KeyReleaseMask);
    
    XMapWindow(display, window);
    
    /* As anticipated, I'm not using the default GC */
    GC my_GC = XCreateGC(display, window, my_GCMask, &my_GCVals);

    /* AlexViaColl again */
    bool quit = false;
    while (!quit) {
        while (XPending(display) > 0) {
            XEvent event = {0};
            XNextEvent(display, &event);
            if (event.type == KeyPress) {
                quit = true;
            }
        }
        
        // Do your application work here
        /* YAY! Fun time! */
        XDrawLine(display, window, my_GC, 50, 50, 200, 300);
        XDrawSegments(display, window, my_GC, my_edges, 2);
    }
    
    /* According to the documentation, this should also free the GC etc. */
    XCloseDisplay(display);
}

