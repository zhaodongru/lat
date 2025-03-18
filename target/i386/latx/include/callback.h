#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#include <stdint.h>

uint64_t RunFunctionWithState(uintptr_t fnc, int nargs, ...);
#define RunFunction RunFunctionWithState
#define RunFunctionFmt(fnc,fmt, ...) RunFunctionWithState(fnc, strlen(fmt), ## __VA_ARGS__)

#endif //__CALLBACK_H__
