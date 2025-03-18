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

const char* libxcbxtestName = "libxcb-xtest.so.0";
#define LIBNAME libxcbxtest

#include "wrappedlib_init.h"
