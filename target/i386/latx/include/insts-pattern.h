/**
 * @file insts-pattern.h
 * @author huqi <spcreply@outlook.com>
 *         liuchaoyi <lcy285183897@gmail.com>
 * @brief insts-ptn optimization header file
 */
#ifndef _INSTS_PATTERN_H_
#define _INSTS_PATTERN_H_
#include "common.h"
#include "translate.h"
#include "ir1.h"
#include "ir2.h"

#define PTN_BUF_SIZE 2

void insts_pattern_combine(IR1_INST *pir, IR1_INST *scan_buf[PTN_BUF_SIZE]);

#ifdef CONFIG_LATX_INSTS_PATTERN

#define DEF_INSTS_PTN(_prex) \
        IR1_INST *_prex##_scaned[PTN_BUF_SIZE] \
        __attribute__((unused)) = {NULL};
#define OPT_INSTS_PTN(_prex, _inst) \
        do { \
            if (option_insts_pattern) { \
                insts_pattern_combine(_inst, _prex##_scaned); \
            } \
        } while (0)

#else /* !CONFIG_LATX_INSTS_PATTERN */

#define DEF_INSTS_PTN(_prex)        ((void)0)
#define OPT_INSTS_PTN(_prex, _inst) ((void)0)

#endif

TRANS_FUNC_DEF(cmp_jcc);
TRANS_FUNC_DEF(cmp_sbb);
TRANS_FUNC_DEF(sub_jcc);
TRANS_FUNC_DEF(test_jcc);
#ifdef CONFIG_LATX_XCOMISX_OPT
TRANS_FUNC_DEF(comisd_jcc);
TRANS_FUNC_DEF(comiss_jcc);
TRANS_FUNC_DEF(ucomisd_jcc);
TRANS_FUNC_DEF(ucomiss_jcc);
#endif
bool translate_bt_jcc(IR1_INST *ir1);
bool translate_cqo_idiv(IR1_INST *ir1);
bool translate_xor_div(IR1_INST *ir1);
bool translate_cdq_idiv(IR1_INST *ir1);

#endif
