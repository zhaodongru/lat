/* this is used at translate table */
#ifdef TRANSLATE_TABLE
    TRANS_FUNC_GEN(CMP_JCC , cmp_jcc),
    TRANS_FUNC_GEN(SUB_JCC , sub_jcc),
    TRANS_FUNC_GEN(BT_JCC , bt_jcc),
    TRANS_FUNC_GEN(CQO_IDIV , cqo_idiv),
    TRANS_FUNC_GEN(CMP_SBB , cmp_sbb),
    TRANS_FUNC_GEN(TEST_JCC, test_jcc),
#ifdef CONFIG_LATX_XCOMISX_OPT
    TRANS_FUNC_GEN(COMISD_JCC, comisd_jcc),
    TRANS_FUNC_GEN(COMISS_JCC, comiss_jcc),
    TRANS_FUNC_GEN(UCOMISD_JCC, ucomisd_jcc),
    TRANS_FUNC_GEN(UCOMISS_JCC, ucomiss_jcc),
#endif
    TRANS_FUNC_GEN(XOR_DIV , xor_div),
    TRANS_FUNC_GEN(CDQ_IDIV , cdq_idiv),
#endif

/* addtional instructions insert into x86 decoder */
#ifdef ADDITION_INSTS
    dt_X86_INS_CMP_JCC,
    dt_X86_INS_SUB_JCC,
    dt_X86_INS_BT_JCC,
    dt_X86_INS_CQO_IDIV,
    dt_X86_INS_CMP_SBB,
    dt_X86_INS_TEST_JCC,
    dt_X86_INS_COMISD_JCC,
    dt_X86_INS_COMISS_JCC,
    dt_X86_INS_UCOMISD_JCC,
    dt_X86_INS_UCOMISS_JCC,
    dt_X86_INS_XOR_DIV,
    dt_X86_INS_CDQ_IDIV,
#endif

/* pattern tail table */
#ifdef PATTERN_TAIL
    case WRAP(JNS):
    case WRAP(JNO):
    case WRAP(JO):
    case WRAP(JS):
    case WRAP(JB):
    case WRAP(JAE):
    case WRAP(JE):
    case WRAP(JNE):
    case WRAP(JBE):
    case WRAP(JA):
    case WRAP(JL):
    case WRAP(JGE):
    case WRAP(JLE):
    case WRAP(JG):
    case WRAP(SBB):
    case WRAP(IDIV):
    case WRAP(DIV):
#endif

/* pattern header table */
#ifdef PATTERN_HEADER
    case WRAP(CMP):
    case WRAP(SUB):
    case WRAP(TEST):
    case WRAP(CQO):
    case WRAP(BT):
#ifdef CONFIG_LATX_XCOMISX_OPT
    case WRAP(COMISD):
    case WRAP(COMISS):
    case WRAP(UCOMISD):
    case WRAP(UCOMISS):
#endif
    case WRAP(XOR):
    case WRAP(CDQ):
#endif
