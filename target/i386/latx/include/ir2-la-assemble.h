#ifndef __LISA_ASSEMBLE_H_
#define __LISA_ASSEMBLE_H_

#include "la-ir2.h"
typedef enum {
    OPD_INVALID = 0,
    FCC_CA,
    FCC_CD,
    FCC_CJ,
    IMM_CODE,
    IMM_CONDF,
    IMM_CONDH,
    IMM_CONDL,
    OPD_CSR,
    FPR_FA,
    OPD_FCSRH,
    OPD_FCSRL,
    FPR_FD,
    FPR_FJ,
    FPR_FK,
    IMM_HINTL,
    IMM_HINTS,
    IMM_I13,
    IMM_IDXS,
    IMM_IDXM,
    IMM_IDXL,
    IMM_IDXLL,
    IMM_LEVEL,
    IMM_LSBD,
    IMM_LSBW,
    IMM_MODE,
    IMM_MSBD,
    IMM_MSBW,
    IMM_OFFS,
    IMM_OFFL,
    IMM_OFFLL,
    OPD_OPCACHE,
    IMM_OPX86,
    IMM_PTR,
    GPR_RD,
    GPR_RJ,
    GPR_RK,
    IMM_SA2,
    IMM_SA3,
    SCR_SD,
    IMM_SEQ,
    IMM_SI10,
    IMM_SI11,
    IMM_SI12,
    IMM_SI14,
    IMM_SI16,
    IMM_SI20,
    IMM_SI5,
    IMM_SI8,
    IMM_SI9,
    SCR_SJ,
    IMM_UI1,
    IMM_UI12,
    IMM_UI2,
    IMM_UI3,
    IMM_UI4,
    IMM_UI5H,
    IMM_UI5L,
    IMM_UI6,
    IMM_UI7,
    IMM_UI8,
    FPR_VA,
    FPR_VD,
    FPR_VJ,
    FPR_VK,
    FPR_XA,
    FPR_XD,
    FPR_XJ,
    FPR_XK,
} GM_OPERAND_TYPE;

typedef struct pair {
    int start;
    int end;
} pair;

typedef struct {
    GM_OPERAND_TYPE type;
    pair bit_range_0;
    pair bit_range_1; /* some branch offset is splited into 2 parts */
} GM_OPERAND_PLACE_RELATION;

typedef struct {
    IR2_OPCODE type;
    uint32_t opcode;
    GM_OPERAND_TYPE opnd[4];
} GM_LA_OPCODE_FORMAT;

typedef struct {
    GM_OPERAND_TYPE place;
    IR2_OPND_TYPE type;
} GM_LA_OPERAND_PLACE_TYPE;

GM_OPERAND_PLACE_RELATION bit_field_table[] = {
    {OPD_INVALID, {-1, -1}, {-1, -1} },
    {FCC_CA, {15, 17}, {-1, -1} },
    {FCC_CD, {0, 2}, {-1, -1} },
    {FCC_CJ, {5, 7}, {-1, -1} },
    {IMM_CODE, {0, 14}, {-1, -1} },
    {IMM_CONDF, {15, 19}, {-1, -1} },
    {IMM_CONDH, {10, 13}, {-1, -1} },
    {IMM_CONDL, {0, 3}, {-1, -1} },
    {OPD_CSR, {10, 23}, {-1, -1} },
    {FPR_FA, {15, 19}, {-1, -1} },
    {OPD_FCSRH, {5, 9}, {-1, -1} },
    {OPD_FCSRL, {0, 4}, {-1, -1} },
    {FPR_FD, {0, 4}, {-1, -1} },
    {FPR_FJ, {5, 9}, {-1, -1} },
    {FPR_FK, {10, 14}, {-1, -1} },
    {IMM_HINTL, {0, 14}, {-1, -1} },
    {IMM_HINTS, {0, 4}, {-1, -1} },
    {IMM_I13, {5, 17}, {-1, -1} },
    {IMM_IDXS, {18, 18}, {-1, -1} },
    {IMM_IDXM, {18, 19}, {-1, -1} },
    {IMM_IDXL, {18, 20}, {-1, -1} },
    {IMM_IDXLL, {18, 21}, {-1, -1} },
    {IMM_LEVEL, {10, 17}, {-1, -1} },
    {IMM_LSBD, {10, 15}, {-1, -1} },
    {IMM_LSBW, {10, 14}, {-1, -1} },
    {IMM_MODE, {5, 9}, {-1, -1} },
    {IMM_MSBD, {16, 21}, {-1, -1} },
    {IMM_MSBW, {16, 20}, {-1, -1} },
    {IMM_OFFS, {10, 25}, {-1, -1} },
    {IMM_OFFL, {10, 25}, {0, 4} },
    {IMM_OFFLL, {10, 25}, {0, 9} },
    {OPD_OPCACHE, {0, 4}, {-1, -1} },
    {IMM_OPX86, {5, 9}, {-1, -1} },
    {IMM_PTR, {5, 7}, {-1, -1} },
    {GPR_RD, {0, 4}, {-1, -1} },
    {GPR_RJ, {5, 9}, {-1, -1} },
    {GPR_RK, {10, 14}, {-1, -1} },
    {IMM_SA2, {15, 16}, {-1, -1} },
    {IMM_SA3, {15, 17}, {-1, -1} },
    {SCR_SD, {0, 1}, {-1, -1} },
    {IMM_SEQ, {10, 17}, {-1, -1} },
    {IMM_SI10, {10, 19}, {-1, -1} },
    {IMM_SI11, {10, 20}, {-1, -1} },
    {IMM_SI12, {10, 21}, {-1, -1} },
    {IMM_SI14, {10, 23}, {-1, -1} },
    {IMM_SI16, {10, 25}, {-1, -1} },
    {IMM_SI20, {5, 24}, {-1, -1} },
    {IMM_SI5, {10, 14}, {-1, -1} },
    {IMM_SI8, {10, 17}, {-1, -1} },
    {IMM_SI9, {10, 18}, {-1, -1} },
    {SCR_SJ, {5, 6}, {-1, -1} },
    {IMM_UI1, {10, 10}, {-1, -1} },
    {IMM_UI12, {10, 21}, {-1, -1} },
    {IMM_UI2, {10, 11}, {-1, -1} },
    {IMM_UI3, {10, 12}, {-1, -1} },
    {IMM_UI4, {10, 13}, {-1, -1} },
    {IMM_UI5H, {15, 19}, {-1, -1} },
    {IMM_UI5L, {10, 14}, {-1, -1} },
    {IMM_UI6, {10, 15}, {-1, -1} },
    {IMM_UI7, {10, 16}, {-1, -1} },
    {IMM_UI8, {10, 17}, {-1, -1} },
    {FPR_VA, {15, 19}, {-1, -1} },
    {FPR_VD, {0, 4}, {-1, -1} },
    {FPR_VJ, {5, 9}, {-1, -1} },
    {FPR_VK, {10, 14}, {-1, -1} },
    {FPR_XA, {15, 19}, {-1, -1} },
    {FPR_XD, {0, 4}, {-1, -1} },
    {FPR_XJ, {5, 9}, {-1, -1} },
    {FPR_XK, {10, 14}, {-1, -1} },
};
/* there are some errors in vector instruction */
GM_LA_OPCODE_FORMAT lisa_format_table[] = {
#include "format-table.h"
};

#endif

