#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "library_private.h"
#include "callback.h"
#include "librarian.h"
#include "box64context.h"

const char* libxcbrandrName = "libxcb-randr.so.0";
#define LIBNAME libxcbrandr

#include "wrappedlib_init.h"
