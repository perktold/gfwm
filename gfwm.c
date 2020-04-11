#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>


void die(char str[]){
	fprintf(stderr, str);
	exit(1);
}

int main(void){
	XEvent event;
	Display* display;

	XButtonEvent start; //nani what dis

	if(!(display = XOpenDisplay(NULL))) die("cant open display, get fucked\n");
	
	Window root = DefaultRootWindow(display);
	//XGrabKey(display, XK_F1, Mod1Mask, root, True, GrabModeAsync, GrabModeAsync);
	XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("F1")), Mod1Mask, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
	//XGrabButton(display, 1, Mod1Mask, DefaultRootWindow(display), True, ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
	//XGrabButton(display, 3, Mod1Mask, DefaultRootWindow(display), True, ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

	start.subwindow = None; //nani wat dis
	while(1){
		XNextEvent(display, &event);
		if(event.serial == XK_F1){
			exit(0);
		}else{
			system("st");
		}
	}
}
