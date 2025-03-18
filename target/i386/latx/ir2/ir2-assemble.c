#include "ir2.h"
#include "translate.h"
#include "ir2-la-assemble.h"

void set_operand_into_instruction(GM_OPERAND_TYPE operand_type,
                                  IR2_OPND *p_opnd, uint32 *result);

/*
 * FIXME: This is a intial port code, there is no any verification!!!
 */
uint32 ir2_assemble(const IR2_INST *ir2)
{
    if (ir2_opcode(ir2) == LISA_CODE) {
        lsassert(ir2_opnd_is_pseudo(&ir2->_opnd[0]));
        return ir2->_opnd[0]._val;
    }
    lsassert(ir2_opcode(ir2) > LISA_PSEUDO_END);
    GM_LA_OPCODE_FORMAT format = lisa_format_table[ir2_opcode(ir2) - LISA_INVALID];
    lsassert(format.type == ir2_opcode(ir2));
    lsassert(format.opcode != 0);

    uint32_t ins = format.opcode;
    lsassertm(ins, "Cannot use a pseudo opcode!");
    for (int i = 0; i < 4; i++) {
        GM_OPERAND_TYPE opnd_type = format.opnd[i];
        if (opnd_type == OPD_INVALID)
            break;

        GM_OPERAND_PLACE_RELATION bit_field = bit_field_table[opnd_type];
        lsassert(opnd_type == bit_field.type);

        int start = bit_field.bit_range_0.start;
        int end = bit_field.bit_range_0.end;
        int bit_len = end - start + 1;
        // FIXME: this is a unoin here.
        int val = ir2->_opnd[i]._val;
        int mask = (1 << bit_len) - 1;

        lsassert(!(ir2_opnd_is_pseudo(&ir2->_opnd[i]) ||
                   ir2_opnd_is_data(&ir2->_opnd[i])));

        ins |= (val & mask) << start;

        if (bit_field.bit_range_1.start >= 0) {
            val = val >> bit_len;
            start = bit_field.bit_range_1.start;
            end = bit_field.bit_range_1.end;
            bit_len = end - start + 1;
            mask = (1 << bit_len) - 1;
            ins |= (val & mask) << start;
        }
    }

    return ins;
}
