#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "wrapper.h"
#include "bridge.h"
#include "library_private.h"

const char* libvadrmName = "libva-drm.so.2";
#define LIBNAME libvadrm

#include "wrappedlib_init.h"

