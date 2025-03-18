#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "wrapper.h"
#include "bridge.h"
#include "library_private.h"

const char* libxdmcpName = "libXdmcp.so.6";
#define LIBNAME libxdmcp


#include "wrappedlib_init.h"
