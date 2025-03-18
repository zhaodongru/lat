#ifndef _IR1_OPTIMIZATION_H_
#define _IR1_OPTIMIZATION_H_

void ir1_optimization(TranslationBlock *tb);
void over_tb_rfd(TranslationBlock **tb_list, int tb_num);

#endif
