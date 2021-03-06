/*
 * This program is used to generate definitions needed by
 * assembly language modules.
 */
#define MK_DEFS
#include <stdio.h> 

#include <linux/config.h>
#include <linux/signal.h>
#include <linux/sched.h>
#include <linux/head.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/ptrace.h>
#include <linux/mman.h>
#include <linux/mm.h>
#include <asm/pgtable.h>

extern int errno;

main(int argc, char *argv[])
{
	FILE *out;
	struct task_struct task;
	struct thread_struct tss;
	struct pt_regs regs;
	if (!(out = fopen(argv[1], "w")))
	{
		fprintf(stderr, "Can't create output file: %s\n", strerror(errno));
		exit(1);
	}
	fprintf(out, "/*\n");
	fprintf(out, " * WARNING! This file is automatically generated - DO NOT EDIT!\n");
	fprintf(out, " */\n");
	put_line(out, "STATE", (int)&task.state-(int)&task);
	put_line(out, "COUNTER", (int)&task.counter-(int)&task);
	put_line(out, "BLOCKED", (int)&task.blocked-(int)&task);
	put_line(out, "SIGNAL", (int)&task.signal-(int)&task);
	put_line(out, "KERNEL_STACK_PAGE", (int)&task.kernel_stack_page-(int)&task);
	put_line(out, "TSS", (int)&task.tss-(int)&task);
	put_line(out, "KSP", (int)&tss.ksp-(int)&tss);
	put_line(out, "LAST_PC", (int)&tss.last_pc-(int)&tss);
	put_line(out, "USER_STACK", (int)&tss.user_stack-(int)&tss);
	put_line(out, "PT_REGS", (int)&tss.regs-(int)&tss);
	put_line(out, "PF_TRACESYS", PF_TRACESYS);
	put_line(out, "TASK_FLAGS", (int)&task.flags-(int)&task);
	put_line(out, "MMU_SEG0", (int)&tss.segs[0]-(int)&tss);
	put_line(out, "MMU_SEG1", (int)&tss.segs[1]-(int)&tss);
	put_line(out, "MMU_SEG2", (int)&tss.segs[2]-(int)&tss);
	put_line(out, "MMU_SEG3", (int)&tss.segs[3]-(int)&tss);
	put_line(out, "MMU_SEG4", (int)&tss.segs[4]-(int)&tss);
	put_line(out, "MMU_SEG5", (int)&tss.segs[5]-(int)&tss);
	put_line(out, "MMU_SEG6", (int)&tss.segs[6]-(int)&tss);
	put_line(out, "MMU_SEG7", (int)&tss.segs[7]-(int)&tss);
	put_line(out, "MMU_SEG8", (int)&tss.segs[8]-(int)&tss);
	put_line(out, "MMU_SEG9", (int)&tss.segs[9]-(int)&tss);
	put_line(out, "MMU_SEG10", (int)&tss.segs[10]-(int)&tss);
	put_line(out, "MMU_SEG11", (int)&tss.segs[11]-(int)&tss);
	put_line(out, "MMU_SEG12", (int)&tss.segs[12]-(int)&tss);
	put_line(out, "MMU_SEG13", (int)&tss.segs[13]-(int)&tss);
	put_line(out, "MMU_SEG14", (int)&tss.segs[14]-(int)&tss);
	put_line(out, "MMU_SEG15", (int)&tss.segs[15]-(int)&tss);
	put_line(out, "TSS_FPR0", (int)&tss.fpr[0]-(int)&tss);
	put_line(out, "TSS_FPR1", (int)&tss.fpr[1]-(int)&tss);
	put_line(out, "TSS_FPR2", (int)&tss.fpr[2]-(int)&tss);
	put_line(out, "TSS_FPR3", (int)&tss.fpr[3]-(int)&tss);
	put_line(out, "TSS_FPR4", (int)&tss.fpr[4]-(int)&tss);
	put_line(out, "TSS_FPR5", (int)&tss.fpr[5]-(int)&tss);
	put_line(out, "TSS_FPR6", (int)&tss.fpr[6]-(int)&tss);
	put_line(out, "TSS_FPR7", (int)&tss.fpr[7]-(int)&tss);
	put_line(out, "TSS_FPR8", (int)&tss.fpr[8]-(int)&tss);
	put_line(out, "TSS_FPR9", (int)&tss.fpr[9]-(int)&tss);
	put_line(out, "TSS_FPR10", (int)&tss.fpr[10]-(int)&tss);
	put_line(out, "TSS_FPR11", (int)&tss.fpr[11]-(int)&tss);
	put_line(out, "TSS_FPR12", (int)&tss.fpr[12]-(int)&tss);
	put_line(out, "TSS_FPR13", (int)&tss.fpr[13]-(int)&tss);
	put_line(out, "TSS_FPR14", (int)&tss.fpr[14]-(int)&tss);
	put_line(out, "TSS_FPR15", (int)&tss.fpr[15]-(int)&tss);
	put_line(out, "TSS_FPR16", (int)&tss.fpr[16]-(int)&tss);
	put_line(out, "TSS_FPR17", (int)&tss.fpr[17]-(int)&tss);
	put_line(out, "TSS_FPR18", (int)&tss.fpr[18]-(int)&tss);
	put_line(out, "TSS_FPR19", (int)&tss.fpr[19]-(int)&tss);
	put_line(out, "TSS_FPR20", (int)&tss.fpr[20]-(int)&tss);
	put_line(out, "TSS_FPR21", (int)&tss.fpr[21]-(int)&tss);
	put_line(out, "TSS_FPR22", (int)&tss.fpr[22]-(int)&tss);
	put_line(out, "TSS_FPR23", (int)&tss.fpr[23]-(int)&tss);
	put_line(out, "TSS_FPR24", (int)&tss.fpr[24]-(int)&tss);
	put_line(out, "TSS_FPR25", (int)&tss.fpr[25]-(int)&tss);
	put_line(out, "TSS_FPR26", (int)&tss.fpr[26]-(int)&tss);
	put_line(out, "TSS_FPR27", (int)&tss.fpr[27]-(int)&tss);
	put_line(out, "TSS_FPR28", (int)&tss.fpr[28]-(int)&tss);
	put_line(out, "TSS_FPR29", (int)&tss.fpr[29]-(int)&tss);
	put_line(out, "TSS_FPR30", (int)&tss.fpr[30]-(int)&tss);
	put_line(out, "TSS_FPR31", (int)&tss.fpr[31]-(int)&tss);
	/* Interrupt register frame */
	put_line(out, "INT_FRAME_SIZE", sizeof(regs));
	put_line(out, "GPR0", (int)&regs.gpr[0]-(int)&regs);
	put_line(out, "GPR1", (int)&regs.gpr[1]-(int)&regs);
	put_line(out, "GPR2", (int)&regs.gpr[2]-(int)&regs);
	put_line(out, "GPR3", (int)&regs.gpr[3]-(int)&regs);
	put_line(out, "GPR4", (int)&regs.gpr[4]-(int)&regs);
	put_line(out, "GPR5", (int)&regs.gpr[5]-(int)&regs);
	put_line(out, "GPR6", (int)&regs.gpr[6]-(int)&regs);
	put_line(out, "GPR7", (int)&regs.gpr[7]-(int)&regs);
	put_line(out, "GPR8", (int)&regs.gpr[8]-(int)&regs);
	put_line(out, "GPR9", (int)&regs.gpr[9]-(int)&regs);
	put_line(out, "GPR10", (int)&regs.gpr[10]-(int)&regs);
	put_line(out, "GPR11", (int)&regs.gpr[11]-(int)&regs);
	put_line(out, "GPR12", (int)&regs.gpr[12]-(int)&regs);
	put_line(out, "GPR13", (int)&regs.gpr[13]-(int)&regs);
	put_line(out, "GPR14", (int)&regs.gpr[14]-(int)&regs);
	put_line(out, "GPR15", (int)&regs.gpr[15]-(int)&regs);
	put_line(out, "GPR16", (int)&regs.gpr[16]-(int)&regs);
	put_line(out, "GPR17", (int)&regs.gpr[17]-(int)&regs);
	put_line(out, "GPR18", (int)&regs.gpr[18]-(int)&regs);
	put_line(out, "GPR19", (int)&regs.gpr[19]-(int)&regs);
	put_line(out, "GPR20", (int)&regs.gpr[20]-(int)&regs);
	put_line(out, "GPR21", (int)&regs.gpr[21]-(int)&regs);
	put_line(out, "GPR22", (int)&regs.gpr[22]-(int)&regs);
	put_line(out, "GPR23", (int)&regs.gpr[23]-(int)&regs);
	put_line(out, "GPR24", (int)&regs.gpr[24]-(int)&regs);
	put_line(out, "GPR25", (int)&regs.gpr[25]-(int)&regs);
	put_line(out, "GPR26", (int)&regs.gpr[26]-(int)&regs);
	put_line(out, "GPR27", (int)&regs.gpr[27]-(int)&regs);
	put_line(out, "GPR28", (int)&regs.gpr[28]-(int)&regs);
	put_line(out, "GPR29", (int)&regs.gpr[29]-(int)&regs);
	put_line(out, "GPR30", (int)&regs.gpr[30]-(int)&regs);
	put_line(out, "GPR31", (int)&regs.gpr[31]-(int)&regs);
	put_line(out, "FPR0", (int)&regs.fpr[0]-(int)&regs);
	put_line(out, "FPR1", (int)&regs.fpr[1]-(int)&regs);
	put_line(out, "FPR2", (int)&regs.fpr[2]-(int)&regs);
	put_line(out, "FPR3", (int)&regs.fpr[3]-(int)&regs);
	put_line(out, "FPCSR", (int)&regs.fpcsr-(int)&regs);
	/* Note: these symbols include "_" because they overlap with special register names */
	put_line(out, "_NIP", (int)&regs.nip-(int)&regs);
	put_line(out, "_MSR", (int)&regs.msr-(int)&regs);
	put_line(out, "_CTR", (int)&regs.ctr-(int)&regs);
	put_line(out, "_LINK", (int)&regs.link-(int)&regs);
	put_line(out, "_CCR", (int)&regs.ccr-(int)&regs);
	put_line(out, "_XER", (int)&regs.xer-(int)&regs);
	put_line(out, "_DAR", (int)&regs.dar-(int)&regs);
	put_line(out, "_DSISR", (int)&regs.dsisr-(int)&regs);
	put_line(out, "_HASH1", (int)&regs.hash1-(int)&regs);
	put_line(out, "_HASH2", (int)&regs.hash2-(int)&regs);
	put_line(out, "_IMISS", (int)&regs.imiss-(int)&regs);
	put_line(out, "_DMISS", (int)&regs.dmiss-(int)&regs);
	put_line(out, "_ICMP", (int)&regs.icmp-(int)&regs);
	put_line(out, "_DCMP", (int)&regs.dcmp-(int)&regs);
	put_line(out, "ORIG_GPR3", (int)&regs.orig_gpr3-(int)&regs);
	put_line(out, "RESULT", (int)&regs.result-(int)&regs);
	put_line(out, "TRAP", (int)&regs.trap-(int)&regs);
	put_line(out, "MARKER", (int)&regs.marker-(int)&regs);
	exit(0);
}

put_line(FILE *out, char *name, int offset)
{
	fprintf(out, "#define %s %d\n", name, offset);
}
