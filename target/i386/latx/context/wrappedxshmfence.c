#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "wrapper.h"
#include "bridge.h"
#include "library_private.h"

const char* xshmfenceName = "libxshmfence.so.1";
#define LIBNAME xshmfence


#include "wrappedlib_init.h"
