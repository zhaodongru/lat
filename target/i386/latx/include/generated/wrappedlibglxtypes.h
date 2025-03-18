#ifndef __wrappedlibglxTYPES_H_
#define __wrappedlibglxTYPES_H_

#ifndef LIBNAME
#error You should only #include this file inside a wrapped*.c file
#endif
#ifndef ADDED_FUNCTIONS
#define ADDED_FUNCTIONS()
#endif

typedef void* (*pFp_t)(void*);
typedef void (*vFpp_t)(void*, void*);
typedef void*         (*pFppp_t)(void*, void*, void*);
typedef int32_t (*iFpppp_t)(void*, void*, void*, void*);
typedef void* (*pFppipi_t)(void*, void*, int32_t, void*, int32_t);

#define SUPER() ADDED_FUNCTIONS() \
	GO(glXGetProcAddress, pFp_t) \
	GO(glXGetProcAddressARB, pFp_t) \
	GO(glXDestroyContext,vFpp_t) \
	GO(glXDestroyPbuffer,vFpp_t) \
        GO(glXCreatePbuffer,pFppp_t) \
        GO(glXMakeContextCurrent,iFpppp_t) \
        GO(glXCreateNewContext,pFppipi_t)

#endif // __wrappedlibglxTYPES_H_
