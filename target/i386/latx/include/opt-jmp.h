/**
 * @file opt-jmp.h
 * @author Hanlu Li <heuleehanlu@gmail.com>
 * @brief JRRA optimization header file
 */
#ifndef _OPT_JMP_H_
#define _OPT_JMP_H_
#include "common.h"
#include "exec/cpu-defs.h"

void jrra_pre_translate(void** list, int num, CPUState *cpu,
                        target_ulong cs_base, uint32_t flags, uint32_t cflags);
#endif
