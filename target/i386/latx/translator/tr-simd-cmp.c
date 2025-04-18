#include "common.h"
#include "reg-alloc.h"
#include "latx-options.h"
#include "translate.h"
#include "env.h"

bool translate_pcmpeqb(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vseq_b(dest, dest, src);
    } else { //mmx
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vseq_b(dest_lo, dest_lo, src_lo);
    }
    return true;
}

bool translate_pcmpeqw(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vseq_h(dest, dest, src);
    } else { //mmx
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vseq_h(dest_lo, dest_lo, src_lo);
    }
    return true;
}

bool translate_pcmpeqd(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vseq_w(dest, dest, src);
    } else { //mmx
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vseq_w(dest_lo, dest_lo, src_lo);
    }
    return true;
}

bool translate_pcmpgtb(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vslt_b(dest, src, dest);
        return true;
    } else {
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vslt_b(dest_lo, src_lo, dest_lo);
    }
    return true;
}

bool translate_pcmpgtw(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vslt_h(dest, src, dest);
        return true;
    }
    /* transfer_to_mmx_mode */
    transfer_to_mmx_mode();

    IR2_OPND dest_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
    IR2_OPND src_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
    la_vslt_h(dest_lo, src_lo, dest_lo);
    return true;
}

bool translate_pcmpgtd(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vslt_w(dest, src, dest);
        return true;
    }
    /* transfer_to_mmx_mode */
    transfer_to_mmx_mode();

    IR2_OPND dest_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
    IR2_OPND src_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
    la_vslt_w(dest_lo, src_lo, dest_lo);
    return true;
}

bool translate_pcmpgtq(IR1_INST *pir1)
{
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vslt_d(dest, src, dest);
    return true;
}

bool translate_cmpeqpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_EQ);
    return true;
}

bool translate_cmpltpd(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_LT);
    return true;
}

bool translate_cmplepd(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_LE);
    return true;
}

bool translate_cmpunordpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_UNORD);
    return true;
}

bool translate_cmpneqpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_NEQ);
    return true;
}

bool translate_cmpnltpd(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !< B & UOR == B <= A & UOR */
    la_vfcmp_cond_d(dest, src, dest, X86_FCMP_COND_NLT);
    return true;
}

bool translate_cmpnlepd(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !<= B & UOR == B < A & UOR */
    la_vfcmp_cond_d(dest, src, dest, X86_FCMP_COND_NLE);
    return true;
}

bool translate_cmpordpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_ORD);
    return true;
}

bool translate_cmpeqps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_EQ);
    return true;
}

bool translate_cmpltps(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_LT);
    return true;
}

bool translate_cmpleps(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_LE);
    return true;
}

bool translate_cmpunordps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_UNORD);
    return true;
}

bool translate_cmpneqps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_NEQ);
    return true;
}

bool translate_cmpnltps(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !< B & UOR == B <= A & UOR */
    la_vfcmp_cond_s(dest, src, dest, X86_FCMP_COND_NLT);
    return true;
}

bool translate_cmpnleps(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !<= B & UOR == B < A & UOR */
    la_vfcmp_cond_s(dest, src, dest, X86_FCMP_COND_NLE);
    return true;
}

bool translate_cmpordps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_ORD);
    return true;
}
bool translate_cmpps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqps(pir1);
    case 1:
        return translate_cmpltps(pir1);
    case 2:
        return translate_cmpleps(pir1);
    case 3:
        return translate_cmpunordps(pir1);
    case 4:
        return translate_cmpneqps(pir1);
    case 5:
        return translate_cmpnltps(pir1);
    case 6:
        return translate_cmpnleps(pir1);
    case 7:
        return translate_cmpordps(pir1);
    default:
        lsassert(0);
    }
    return true;
}


bool translate_cmpeqsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_EQ);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpltsd(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LT);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmplesd(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LE);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpunordsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_UNORD);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpneqsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_NEQ);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

/**
 * NOTE:
 * LA has no condition of nlt, it is replaced by sule,
 * and the order of dest and src operand needs to be swapped.
 */
bool translate_cmpnltsd(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLT);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

/**
 * NOTE:
 * LA has no condition of nle, it is replaced by sult,
 * and the order of dest and src operand needs to be swapped.
 */
bool translate_cmpnlesd(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLE);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpordsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_ORD);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpeqss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_EQ);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpltss(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LT);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpless(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LE);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);
    return true;
}

bool translate_cmpunordss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_UNORD);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpneqss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_NEQ);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpnltss(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    /* A !< B & UOR == B <= A & UOR */
    la_vfcmp_cond_s(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLT);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpnless(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    /* A !<= B & UOR == B < A & UOR */
    la_vfcmp_cond_s(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLE);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpordss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_ORD);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    return true;
}

bool translate_cmpss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqss(pir1);
    case 1:
        return translate_cmpltss(pir1);
    case 2:
        return translate_cmpless(pir1);
    case 3:
        return translate_cmpunordss(pir1);
    case 4:
        return translate_cmpneqss(pir1);
    case 5:
        return translate_cmpnltss(pir1);
    case 6:
        return translate_cmpnless(pir1);
    case 7:
        return translate_cmpordss(pir1);
    default:
        lsassert(0);
    }
    return true;
}


bool translate_cmppd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqpd(pir1);
    case 1:
        return translate_cmpltpd(pir1);
    case 2:
        return translate_cmplepd(pir1);
    case 3:
        return translate_cmpunordpd(pir1);
    case 4:
        return translate_cmpneqpd(pir1);
    case 5:
        return translate_cmpnltpd(pir1);
    case 6:
        return translate_cmpnlepd(pir1);
    case 7:
        return translate_cmpordpd(pir1);
    default:
        lsassert(0);
    }
    return true;
}

#ifdef CONFIG_LATX_XCOMISX_OPT
#define ZPCF_USEDEF_BIT (ZF_USEDEF_BIT | PF_USEDEF_BIT | CF_USEDEF_BIT)
#define OASF_USEDEF_BIT (OF_USEDEF_BIT | AF_USEDEF_BIT | SF_USEDEF_BIT)
#define OASF_BIT        (OF_BIT | AF_BIT | SF_BIT)

void generate_xcomisx(IR2_OPND src0, IR2_OPND src1, bool is_double,
                      bool qnan_exp, uint8_t eflags)
{
    lsassert(!(eflags & ~(ZPCF_USEDEF_BIT | OASF_USEDEF_BIT)));
    bool calc_zpc = !!(ZPCF_USEDEF_BIT & eflags);
    bool calc_oas = !!(OASF_USEDEF_BIT & eflags);
    /* 1. all need not calculate */
    if (!calc_zpc & !calc_oas)
        return;
    /*
     * 2. Only OF/AF/SF need calculate
     *    hint: ZF/PF/CF will clear OF/AF/SF
     */
    if (!calc_zpc && calc_oas) {
        /* clear OF/AF/SF manually */
        la_x86mtflag(zero_ir2_opnd, OASF_USEDEF_BIT);
        return;
    }

    bool calc_zf = !!(ZF_USEDEF_BIT & eflags);
    bool calc_pf = !!(PF_USEDEF_BIT & eflags);
    bool calc_cf = !!(CF_USEDEF_BIT & eflags);

    /**
     * 3. ZF/PF/CF need calculate
     * (bit 6)ZF = 1 if EQ || UOR
     * (bit 2)PF = 1 if UOR (= ZF & CF)
     * (bit 0)CF = 1 if LT || UOR
     */

    IR2_OPND flag_zf = ra_alloc_itemp();
    IR2_OPND flag_pf = ra_alloc_itemp();
    IR2_OPND flags   = ra_alloc_itemp();

    lsassert(calc_zpc);
    /* 3.0. set flag = 0 */
    if (calc_oas)
        la_mov64(flags, zero_ir2_opnd);

    /* 3.1. check CF, are they less & unordered? */
    if (calc_cf) {
        if (is_double)
            la_fcmp_cond_d(fcc1_ir2_opnd, src0, src1, FCMP_COND_CULT + qnan_exp);
        else
            la_fcmp_cond_s(fcc1_ir2_opnd, src0, src1, FCMP_COND_CULT + qnan_exp);
        la_movcf2gr(flags, fcc1_ir2_opnd);
    }

    /* 3.2. check ZF, are they equal & unordered? */
    if (calc_zf) {
        if (is_double)
            la_fcmp_cond_d(fcc0_ir2_opnd, src0, src1, FCMP_COND_CUEQ + qnan_exp);
        else
            la_fcmp_cond_s(fcc0_ir2_opnd, src0, src1, FCMP_COND_CUEQ + qnan_exp);
        la_movcf2gr(flag_zf, fcc0_ir2_opnd);
        la_bstrins_w(flags, flag_zf, ZF_BIT_INDEX, ZF_BIT_INDEX);
    }

    /* 3.3. check PF, are they unordered? (= ZF & CF) */
    if (calc_pf) {
        if (calc_zf && calc_cf) {
            la_and(flag_pf, flags, flag_zf);
        } else {
            if (is_double)
                la_fcmp_cond_d(fcc2_ir2_opnd, src0, src1,
                               FCMP_COND_CUN + qnan_exp);
            else
                la_fcmp_cond_s(fcc2_ir2_opnd, src0, src1,
                               FCMP_COND_CUN + qnan_exp);
            la_movcf2gr(flag_pf, fcc2_ir2_opnd);
        }
        la_bstrins_w(flags, flag_pf, PF_BIT_INDEX, PF_BIT_INDEX);
    }

    /* 3.4. mov flag to EFLAGS */
    lsassert(calc_zpc);
    la_x86mtflag(flags, eflags);

    ra_free_temp(flag_pf);
    ra_free_temp(flag_zf);
    ra_free_temp(flags);
}

#undef ZPCF_USEDEF_BIT
#undef OASF_USEDEF_BIT
#undef OASF_BIT

bool translate_xcomisx(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 2);
    IR2_OPND src0 = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    generate_eflag_calculation(src0, src0, src1, pir1, false);
    return true;
}

#endif
static inline void xcomisx(IR1_INST *pir1, bool is_double, bool qnan_exp)
{
    /**
     * (bit 6)ZF = 1 if EQ || UOR
     * (bit 2)PF = 1 if UOR (= ZF & CF)
     * (bit 0)CF = 1 if LT || UOR
     */
    lsassert(ir1_opnd_num(pir1) == 2);
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* 0. set flag = 0 */
    IR2_OPND flag_zf = ra_alloc_itemp();
    IR2_OPND flag_pf = ra_alloc_itemp();
    IR2_OPND flag = ra_alloc_itemp();
    la_mov64(flag, zero_ir2_opnd);

    /* 1. check ZF, are they equal & unordered? */
    if (is_double) {
        la_fcmp_cond_d(fcc0_ir2_opnd, dest, src, FCMP_COND_CUEQ + qnan_exp);
    } else {
        la_fcmp_cond_s(fcc0_ir2_opnd, dest, src, FCMP_COND_CUEQ + qnan_exp);
    }
    la_movcf2gr(flag_zf, fcc0_ir2_opnd);

    /* 2. check CF, are they less & unordered? */
    if (is_double) {
        la_fcmp_cond_d(fcc2_ir2_opnd, dest, src, FCMP_COND_CULT + qnan_exp);
    } else {
        la_fcmp_cond_s(fcc2_ir2_opnd, dest, src, FCMP_COND_CULT + qnan_exp);
    }
    la_movcf2gr(flag, fcc2_ir2_opnd);

    /* 3. check PF, are they unordered? (= ZF & CF) */
    la_and(flag_pf, flag, flag_zf);

    la_bstrins_w(flag, flag_zf, ZF_BIT_INDEX, ZF_BIT_INDEX);
    la_bstrins_w(flag, flag_pf, PF_BIT_INDEX, PF_BIT_INDEX);

    /* 4. mov flag to EFLAGS */
    la_x86mtflag(flag, 0x3f);

    ra_free_temp(flag_pf);
    ra_free_temp(flag_zf);
    ra_free_temp(flag);

}

bool translate_comisd(IR1_INST *pir1)
{
    xcomisx(pir1, true, true);
    return true;
}

bool translate_comiss(IR1_INST *pir1)
{
    xcomisx(pir1, false, true);
    return true;
}

bool translate_ucomisd(IR1_INST *pir1)
{
    xcomisx(pir1, true, false);
    return true;
}

bool translate_ucomiss(IR1_INST *pir1)
{
    xcomisx(pir1, false, false);
    return true;
}

bool translate_cmpsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqsd(pir1);
    case 1:
        return translate_cmpltsd(pir1);
    case 2:
        return translate_cmplesd(pir1);
    case 3:
        return translate_cmpunordsd(pir1);
    case 4:
        return translate_cmpneqsd(pir1);
    case 5:
        return translate_cmpnltsd(pir1);
    case 6:
        return translate_cmpnlesd(pir1);
    case 7:
        return translate_cmpordsd(pir1);
    default:
        lsassert(0);
    }
    return true;
}
#ifdef CONFIG_LATX_AVX_OPT

bool translate_vcomisd(IR1_INST * pir1) {
    xcomisx(pir1, true, true);
    return true;
}

bool translate_vcomiss(IR1_INST * pir1) {
    xcomisx(pir1, false, true);
    return true;
}

bool translate_vucomisd(IR1_INST * pir1) {
    xcomisx(pir1, true, false);
    return true;
}

bool translate_vucomiss(IR1_INST * pir1) {
    xcomisx(pir1, false, false);
    return true;
}

bool translate_vpcmpeqx(IR1_INST * pir1) {
    IR1_OPND * opnd0 = ir1_get_opnd(pir1, 0);
    IR1_OPND * opnd1 = ir1_get_opnd(pir1, 1);
    IR1_OPND * opnd2 = ir1_get_opnd(pir1, 2);
    lsassert((ir1_opnd_is_xmm(opnd0) && ir1_opnd_is_xmm(opnd1)) ||
        (ir1_opnd_is_ymm(opnd0) && ir1_opnd_is_ymm(opnd1)));
    IR2_OPND dest = load_freg256_from_ir1(opnd0);
    IR2_OPND src1 = load_freg256_from_ir1(opnd1);
    IR2_OPND src2 = load_freg256_from_ir1(opnd2);
    IR1_OPCODE op = ir1_opcode(pir1);
    IR2_INST * ( * tr_inst)(IR2_OPND, IR2_OPND, IR2_OPND);
    switch (op) {
        case dt_X86_INS_VPCMPEQB:
            tr_inst = la_vseq_b;
            break;
        case dt_X86_INS_VPCMPEQW:
            tr_inst = la_vseq_h;
            break;
        case dt_X86_INS_VPCMPEQD:
            tr_inst = la_vseq_w;
            break;
        case dt_X86_INS_VPCMPEQQ:
            tr_inst = la_vseq_d;
            break;
        default:
            tr_inst = NULL;
            lsassert(0);
            break;
    }
    tr_inst(dest, src1, src2);
    if (ir1_opnd_is_xmm(opnd0))
        set_high128_xreg_to_zero(dest);
    return true;
}

bool translate_vpcmpgtx(IR1_INST * pir1) {
    IR1_OPND * opnd0 = ir1_get_opnd(pir1, 0);
    IR1_OPND * opnd1 = ir1_get_opnd(pir1, 1);
    IR1_OPND * opnd2 = ir1_get_opnd(pir1, 2);
    lsassert((ir1_opnd_is_xmm(opnd0) && ir1_opnd_is_xmm(opnd1)) ||
        (ir1_opnd_is_ymm(opnd0) && ir1_opnd_is_ymm(opnd1)));
    IR2_OPND dest = load_freg256_from_ir1(opnd0);
    IR2_OPND src1 = load_freg256_from_ir1(opnd1);
    IR2_OPND src2 = load_freg256_from_ir1(opnd2);
    IR1_OPCODE op = ir1_opcode(pir1);
    IR2_INST * ( * tr_inst)(IR2_OPND, IR2_OPND, IR2_OPND);
    switch (op) {
        case dt_X86_INS_VPCMPGTB:
            tr_inst = la_vslt_b;
            break;
        case dt_X86_INS_VPCMPGTW:
            tr_inst = la_vslt_h;
            break;
        case dt_X86_INS_VPCMPGTD:
            tr_inst = la_vslt_w;
            break;
        case dt_X86_INS_VPCMPGTQ:
            tr_inst = la_vslt_d;
            break;
        default:
            tr_inst = NULL;
            lsassert(0);
            break;
    }
    tr_inst(dest, src2, src1);
    if (ir1_opnd_is_xmm(opnd0))
        set_high128_xreg_to_zero(dest);
    return true;
}

bool translate_vcmpeqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_EQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_EQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpltpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_LT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_LT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmplepd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_LE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_LE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpunordpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_UNORD);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_UNORD);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NEQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NEQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnltpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        /* A !< B & UOR == B <= A & UOR */
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_NLT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_NLT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnlepd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_NLE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_NLE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpordpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_ORD);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_ORD);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpeq_uqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_EQ_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_EQ_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpngepd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NGE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NGE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpngtpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NGT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NGT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpfalsepd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_FALSE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_FALSE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneq_oqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NEQ_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NEQ_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpgepd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_GE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_GE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpgtpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_GT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_GT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmptruepd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_xvfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_TRUE);
        la_xvori_b(dest, temp, 0xff);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_TRUE);
        la_xvori_b(temp, temp, 0xff);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpeq_ospd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_EQ_OS);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_EQ_OS);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmplt_oqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_LT_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_LT_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmple_oqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_LE_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_LE_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpunord_spd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_UNORD_S);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_UNORD_S);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneq_uspd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NEQ_US);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NEQ_US);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnlt_uqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_NLT_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_NLT_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnle_uqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_NLE_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_NLE_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpord_spd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_ORD_S);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_ORD_S);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpeq_uspd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_EQ_US);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_EQ_US);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnge_uqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NGE_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NGE_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpngt_uqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NGT_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NGT_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpfalse_ospd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_FALSE_OS);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_FALSE_OS);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneq_ospd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src1, src2, X86_FCMP_COND_NEQ_OS);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_NEQ_OS);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpge_oqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_GE_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_GE_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpgt_oqpd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_d(dest, src2, src1, X86_FCMP_COND_GT_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src2, src1, X86_FCMP_COND_GT_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmptrue_uspd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_xvfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_TRUE_US);
        la_xvori_b(dest, temp, 0xff);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_d(temp, src1, src2, X86_FCMP_COND_TRUE_US);
        la_xvori_b(temp, temp, 0xff);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmppd(IR1_INST * pir1) {
    lsassert(ir1_opnd_num(pir1) == 4 &&
        ir1_opnd_is_imm(ir1_get_opnd(pir1, 3)));
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    uint8 predicate = ir1_opnd_uimm(ir1_get_opnd(pir1, 3)) & 0x1f;
    switch (predicate) {
        case 0:
            return translate_vcmpeqpd(pir1);
        case 1:
            return translate_vcmpltpd(pir1);
        case 2:
            return translate_vcmplepd(pir1);
        case 3:
            return translate_vcmpunordpd(pir1);
        case 4:
            return translate_vcmpneqpd(pir1);
        case 5:
            return translate_vcmpnltpd(pir1);
        case 6:
            return translate_vcmpnlepd(pir1);
        case 7:
            return translate_vcmpordpd(pir1);
        case 8:
            return translate_vcmpeq_uqpd(pir1);
        case 9:
            return translate_vcmpngepd(pir1);
        case 10:
            return translate_vcmpngtpd(pir1);
        case 11:
            return translate_vcmpfalsepd(pir1);
        case 12:
            return translate_vcmpneq_oqpd(pir1);
        case 13:
            return translate_vcmpgepd(pir1);
        case 14:
            return translate_vcmpgtpd(pir1);
        case 15:
            return translate_vcmptruepd(pir1);
        case 16:
            return translate_vcmpeq_ospd(pir1);
        case 17:
            return translate_vcmplt_oqpd(pir1);
        case 18:
            return translate_vcmple_oqpd(pir1);
        case 19:
            return translate_vcmpunord_spd(pir1);
        case 20:
            return translate_vcmpneq_uspd(pir1);
        case 21:
            return translate_vcmpnlt_uqpd(pir1);
        case 22:
            return translate_vcmpnle_uqpd(pir1);
        case 23:
            return translate_vcmpord_spd(pir1);
        case 24:
            return translate_vcmpeq_uspd(pir1);
        case 25:
            return translate_vcmpnge_uqpd(pir1);
        case 26:
            return translate_vcmpngt_uqpd(pir1);
        case 27:
            return translate_vcmpfalse_ospd(pir1);
        case 28:
            return translate_vcmpneq_ospd(pir1);
        case 29:
            return translate_vcmpge_oqpd(pir1);
        case 30:
            return translate_vcmpgt_oqpd(pir1);
        case 31:
            return translate_vcmptrue_uspd(pir1);
        default:
            lsassert(0);
    }
    return true;
}

bool translate_vcmpeqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_EQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_EQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpltps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_LT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_LT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpleps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_LE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_LE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpunordps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_UNORD);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_UNORD);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NEQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NEQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnltps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        /* A !< B & UOR == B <= A & UOR */
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_NLT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_NLT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnleps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_NLE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_NLE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpordps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_ORD);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_ORD);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpeq_uqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_EQ_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_EQ_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpngeps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NGE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NGE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpngtps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NGT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NGT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpfalseps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_FALSE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_FALSE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneq_oqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NEQ_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NEQ_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpgeps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_GE);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_GE);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpgtps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_GT);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_GT);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmptrueps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_xvfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_TRUE);
        la_xvori_b(dest, temp, 0xff);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_TRUE);
        la_xvori_b(temp, temp, 0xff);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpeq_osps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_EQ_OS);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_EQ_OS);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmplt_oqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_LT_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_LT_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmple_oqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_LE_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_LE_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpunord_sps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_UNORD_S);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_UNORD_S);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneq_usps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NEQ_US);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NEQ_US);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnlt_uqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_NLT_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_NLT_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnle_uqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_NLE_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_NLE_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpord_sps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_ORD_S);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_ORD_S);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpeq_usps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_EQ_US);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_EQ_US);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpnge_uqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NGE_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NGE_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpngt_uqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NGT_UQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NGT_UQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpfalse_osps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_FALSE_OS);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_FALSE_OS);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpneq_osps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src1, src2, X86_FCMP_COND_NEQ_OS);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_NEQ_OS);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpge_oqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_GE_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_GE_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpgt_oqps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        la_xvfcmp_cond_s(dest, src2, src1, X86_FCMP_COND_GT_OQ);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src2, src1, X86_FCMP_COND_GT_OQ);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmptrue_usps(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    if (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg256_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg256_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg256_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_xvfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_TRUE_US);
        la_xvori_b(dest, temp, 0xff);
    } else {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
        IR2_OPND temp = ra_alloc_ftemp();
        la_vfcmp_cond_s(temp, src1, src2, X86_FCMP_COND_TRUE_US);
        la_xvori_b(temp, temp, 0xff);
        set_high128_xreg_to_zero(temp);
        la_xvori_b(dest, temp, 0);
    }
    return true;
}

bool translate_vcmpps(IR1_INST * pir1) {
    lsassert(ir1_opnd_num(pir1) == 4 &&
        ir1_opnd_is_imm(ir1_get_opnd(pir1, 3)));
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))) ||
        (ir1_opnd_is_ymm(ir1_get_opnd(pir1, 0)) &&
            ir1_opnd_is_ymm(ir1_get_opnd(pir1, 1))));
    uint8 predicate = ir1_opnd_uimm(ir1_get_opnd(pir1, 3)) & 0x1f;
    switch (predicate) {
        case 0:
            return translate_vcmpeqps(pir1);
        case 1:
            return translate_vcmpltps(pir1);
        case 2:
            return translate_vcmpleps(pir1);
        case 3:
            return translate_vcmpunordps(pir1);
        case 4:
            return translate_vcmpneqps(pir1);
        case 5:
            return translate_vcmpnltps(pir1);
        case 6:
            return translate_vcmpnleps(pir1);
        case 7:
            return translate_vcmpordps(pir1);
        case 8:
            return translate_vcmpeq_uqps(pir1);
        case 9:
            return translate_vcmpngeps(pir1);
        case 10:
            return translate_vcmpngtps(pir1);
        case 11:
            return translate_vcmpfalseps(pir1);
        case 12:
            return translate_vcmpneq_oqps(pir1);
        case 13:
            return translate_vcmpgeps(pir1);
        case 14:
            return translate_vcmpgtps(pir1);
        case 15:
            return translate_vcmptrueps(pir1);
        case 16:
            return translate_vcmpeq_osps(pir1);
        case 17:
            return translate_vcmplt_oqps(pir1);
        case 18:
            return translate_vcmple_oqps(pir1);
        case 19:
            return translate_vcmpunord_sps(pir1);
        case 20:
            return translate_vcmpneq_usps(pir1);
        case 21:
            return translate_vcmpnlt_uqps(pir1);
        case 22:
            return translate_vcmpnle_uqps(pir1);
        case 23:
            return translate_vcmpord_sps(pir1);
        case 24:
            return translate_vcmpeq_usps(pir1);
        case 25:
            return translate_vcmpnge_uqps(pir1);
        case 26:
            return translate_vcmpngt_uqps(pir1);
        case 27:
            return translate_vcmpfalse_osps(pir1);
        case 28:
            return translate_vcmpneq_osps(pir1);
        case 29:
            return translate_vcmpge_oqps(pir1);
        case 30:
            return translate_vcmpgt_oqps(pir1);
        case 31:
            return translate_vcmptrue_usps(pir1);
        default:
            lsassert(0);
    }
    return true;
}

bool translate_vcmpeqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_EQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpltsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_LT);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmplesd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_LE);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpunordsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_UNORD);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpneqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpnltsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_NLT);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpnlesd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_NLE);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpordsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_ORD);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpeq_uqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_EQ_UQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpngesd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NGE);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpngtsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NGT);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpfalsesd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_FALSE);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpneq_oqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ_OQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpgesd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_GE);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpgtsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_GT);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmptruesd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_TRUE);
    la_xvori_b(dest_temp, dest_temp, 0xff);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpeq_ossd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_EQ_OS);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmplt_oqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_LT_OQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmple_oqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_LE_OQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpunord_ssd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_UNORD_S);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpneq_ussd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ_US);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpnlt_uqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_NLT_UQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpnle_uqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_NLE_UQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpord_ssd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_ORD_S);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpeq_ussd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_EQ_US);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpnge_uqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NGE_UQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpngt_uqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NGT_UQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpfalse_ossd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_FALSE_OS);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpneq_ossd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ_OS);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpge_oqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_GE_OQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpgt_oqsd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp2, temp1, X86_FCMP_COND_GT_OQ);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmptrue_ussd(IR1_INST * pir1) {
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
    IR2_OPND temp1 = ra_alloc_ftemp();
    IR2_OPND temp2 = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    la_vreplve_d(temp1, src1, zero_ir2_opnd);
    la_vreplve_d(temp2, src2, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_temp, temp1, temp2, X86_FCMP_COND_TRUE_US);
    la_xvori_b(dest_temp, dest_temp, 0xff);
    la_vshuf4i_d(dest_temp, src1, 0xc);
    set_high128_xreg_to_zero(dest_temp);
    la_xvori_b(dest, dest_temp, 0);

    ra_free_temp(temp1);
    ra_free_temp(temp2);
    ra_free_temp(dest_temp);
    return true;
}

bool translate_vcmpsd(IR1_INST * pir1) {
    lsassert(ir1_opnd_num(pir1) == 4 &&
        ir1_opnd_is_imm(ir1_get_opnd(pir1, 3)));
    lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
        ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
    uint8 predicate = ir1_opnd_uimm(ir1_get_opnd(pir1, 3)) & 0x1f;
    switch (predicate) {
        case 0:
            return translate_vcmpeqsd(pir1);
        case 1:
            return translate_vcmpltsd(pir1);
        case 2:
            return translate_vcmplesd(pir1);
        case 3:
            return translate_vcmpunordsd(pir1);
        case 4:
            return translate_vcmpneqsd(pir1);
        case 5:
            return translate_vcmpnltsd(pir1);
        case 6:
            return translate_vcmpnlesd(pir1);
        case 7:
            return translate_vcmpordsd(pir1);
        case 8:
            return translate_vcmpeq_uqsd(pir1);
        case 9:
            return translate_vcmpngesd(pir1);
        case 10:
            return translate_vcmpngtsd(pir1);
        case 11:
            return translate_vcmpfalsesd(pir1);
        case 12:
            return translate_vcmpneq_oqsd(pir1);
        case 13:
            return translate_vcmpgesd(pir1);
        case 14:
            return translate_vcmpgtsd(pir1);
        case 15:
            return translate_vcmptruesd(pir1);
        case 16:
            return translate_vcmpeq_ossd(pir1);
        case 17:
            return translate_vcmplt_oqsd(pir1);
        case 18:
            return translate_vcmple_oqsd(pir1);
        case 19:
            return translate_vcmpunord_ssd(pir1);
        case 20:
            return translate_vcmpneq_ussd(pir1);
        case 21:
            return translate_vcmpnlt_uqsd(pir1);
        case 22:
            return translate_vcmpnle_uqsd(pir1);
        case 23:
            return translate_vcmpord_ssd(pir1);
        case 24:
            return translate_vcmpeq_ussd(pir1);
        case 25:
            return translate_vcmpnge_uqsd(pir1);
        case 26:
            return translate_vcmpngt_uqsd(pir1);
        case 27:
            return translate_vcmpfalse_ossd(pir1);
        case 28:
            return translate_vcmpneq_ossd(pir1);
        case 29:
            return translate_vcmpge_oqsd(pir1);
        case 30:
            return translate_vcmpgt_oqsd(pir1);
        case 31:
            return translate_vcmptrue_ussd(pir1);
        default:
            lsassert(0);
    }
    return true;
}

bool translate_vcmpeqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_EQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpltss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_LT);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpless(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_LE);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpunordss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_UNORD);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpneqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpnltss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_NLT);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpnless(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_NLE);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpordss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_ORD);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpeq_uqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_EQ_UQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpngess(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NGE);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpngtss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NGT);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpfalsess(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_FALSE);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpneq_oqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ_OQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpgess(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_GE);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpgtss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_GT);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmptruess(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_TRUE);
	la_xvori_b(dest_temp, dest_temp, 0xff);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpeq_osss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_EQ_OS);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmplt_oqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_LT_OQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmple_oqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_LE_OQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpunord_sss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_UNORD_S);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpneq_usss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ_US);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpnlt_uqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_NLT_UQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpnle_uqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_NLE_UQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpord_sss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_ORD_S);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpeq_usss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_EQ_US);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpnge_uqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NGE_UQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpngt_uqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NGT_UQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpfalse_osss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_FALSE_OS);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpneq_osss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_NEQ_OS);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpge_oqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_GE_OQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpgt_oqss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp2, temp1, X86_FCMP_COND_GT_OQ);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmptrue_usss(IR1_INST *pir1)
{
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
	IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
	IR2_OPND src2 = load_freg128_from_ir1(ir1_get_opnd(pir1, 2));
	IR2_OPND temp1 = ra_alloc_ftemp();
	IR2_OPND temp2 = ra_alloc_ftemp();
	IR2_OPND dest_temp = ra_alloc_ftemp();
	la_vreplve_w(temp1, src1, zero_ir2_opnd);
	la_vreplve_w(temp2, src2, zero_ir2_opnd);
	la_vfcmp_cond_s(dest_temp, temp1, temp2, X86_FCMP_COND_TRUE_US);
	la_xvori_b(dest_temp, dest_temp, 0xff);
	if(ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 0)) != ir1_opnd_base_reg_num(ir1_get_opnd(pir1, 1))){
		la_xvori_b(dest, src1, 0);
	}
	la_xvinsve0_w(dest, dest_temp, 0);
	set_high128_xreg_to_zero(dest);

	ra_free_temp(temp1);
	ra_free_temp(temp2);
	ra_free_temp(dest_temp);
	return true;
}

bool translate_vcmpss(IR1_INST *pir1)
{
	lsassert(ir1_opnd_num(pir1) == 4 &&
			ir1_opnd_is_imm(ir1_get_opnd(pir1, 3)));
	lsassert((ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)) &&
				ir1_opnd_is_xmm(ir1_get_opnd(pir1, 1))));
	uint8 predicate = ir1_opnd_uimm(ir1_get_opnd(pir1, 3)) & 0x1f;
	switch (predicate) {
		case 0:
			return translate_vcmpeqss(pir1);
		case 1:
			return translate_vcmpltss(pir1);
		case 2:
			return translate_vcmpless(pir1);
		case 3:
			return translate_vcmpunordss(pir1);
		case 4:
			return translate_vcmpneqss(pir1);
		case 5:
			return translate_vcmpnltss(pir1);
		case 6:
			return translate_vcmpnless(pir1);
		case 7:
			return translate_vcmpordss(pir1);
		case 8:
			return translate_vcmpeq_uqss(pir1);
		case 9:
			return translate_vcmpngess(pir1);
		case 10:
			return translate_vcmpngtss(pir1);
		case 11:
			return translate_vcmpfalsess(pir1);
		case 12:
			return translate_vcmpneq_oqss(pir1);
		case 13:
			return translate_vcmpgess(pir1);
		case 14:
			return translate_vcmpgtss(pir1);
		case 15:
			return translate_vcmptruess(pir1);
		case 16:
			return translate_vcmpeq_osss(pir1);
		case 17:
			return translate_vcmplt_oqss(pir1);
		case 18:
			return translate_vcmple_oqss(pir1);
		case 19:
			return translate_vcmpunord_sss(pir1);
		case 20:
			return translate_vcmpneq_usss(pir1);
		case 21:
			return translate_vcmpnlt_uqss(pir1);
		case 22:
			return translate_vcmpnle_uqss(pir1);
		case 23:
			return translate_vcmpord_sss(pir1);
		case 24:
			return translate_vcmpeq_usss(pir1);
		case 25:
			return translate_vcmpnge_uqss(pir1);
		case 26:
			return translate_vcmpngt_uqss(pir1);
		case 27:
			return translate_vcmpfalse_osss(pir1);
		case 28:
			return translate_vcmpneq_osss(pir1);
		case 29:
			return translate_vcmpge_oqss(pir1);
		case 30:
			return translate_vcmpgt_oqss(pir1);
		case 31:
			return translate_vcmptrue_usss(pir1);
		default:
			lsassert(0);
	}
	return true;
}
#endif

