#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "wrapper.h"
#include "bridge.h"
#include "library_private.h"

const char* xkbcommonx11Name = "libxkbcommon-x11.so.0";
#define LIBNAME xkbcommonx11

#include "wrappedlib_init.h"

