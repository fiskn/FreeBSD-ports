--- lib/Display.cc.orig	2005-01-03 10:42:38.000000000 +0100
+++ lib/Display.cc	2013-08-31 15:42:48.395906537 +0200
@@ -25,6 +25,7 @@
 #include "Display.hh"
 
 #include <algorithm>
+#include <cstdlib>
 
 #include <X11/Xutil.h>
 
@@ -32,7 +33,6 @@
 #include <fcntl.h>
 #include <stdio.h>
 
-
 namespace bt {
 
   void createBitmapLoader(const Display &display);
@@ -68,7 +68,7 @@
   if (!(xdisplay = XOpenDisplay(dpy_name))) {
     fprintf(stderr, "bt::Display: failed to open display '%s'\n",
             dpy_name ? dpy_name : "");
-    ::exit(2);
+    std::exit(2);
   }
 
 #ifdef DEBUG
@@ -77,7 +77,7 @@
 
   if (fcntl(XConnectionNumber(xdisplay), F_SETFD, 1) == -1) {
     fprintf(stderr, "bt::Display: failed to mark connection close-on-exec\n");
-    ::exit(2);
+    std::exit(2);
   }
 
   if (!multi_head || ScreenCount(xdisplay) == 1) {
