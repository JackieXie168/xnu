SOURCE_DIR=/Users/admin/Code/xnu/xnu-2422.115.4
export IDENT=-DPEXPERT -DMACH_PE -DMACH_KERNEL
#
# Mach Operating System
# Copyright (c) 1986 Carnegie-Mellon University
# All rights reserved.  The CMU software License Agreement specifies
# the terms and conditions for use and redistribution.
#

export MakeInc_cmd=${SRCROOT}/makedefs/MakeInc.cmd
export MakeInc_def=${SRCROOT}/makedefs/MakeInc.def
export MakeInc_rule=${SRCROOT}/makedefs/MakeInc.rule
export MakeInc_dir=${SRCROOT}/makedefs/MakeInc.dir

include $(MakeInc_cmd)
include $(MakeInc_def)

#
# CFLAGS
#
CFLAGS+= -include meta_features.h -DPEXPERT_KERNEL_PRIVATE

# Objects that don't want -Wcast-align warning (8474835)
pe_identify_machine.o_CWARNFLAGS_ADD = -Wno-cast-align

#
# Directories for mig generated files
#
COMP_SUBDIRS = 

#
#  Make sure we don't remove this by accident if interrupted at the wrong
#  time.
#
.PRECIOUS: Makefile

#
#  Theses macros are filled in by the config program depending on the
#  current configuration.  The MACHDEP macro is replaced by the
#  contents of the machine dependent makefile template and the others
#  are replaced by the corresponding symbol definitions for the
#  configuration.
#

OBJS=device_tree.o bootargs.o pe_gen.o pe_init.o pe_bootargs.o \
	pe_identify_machine.o pe_kprintf.o pe_interrupt.o pe_serial.o 

CFILES=\
	$(SOURCE_DIR)/pexpert/gen/device_tree.c \
	$(SOURCE_DIR)/pexpert/gen/bootargs.c \
	$(SOURCE_DIR)/pexpert/gen/pe_gen.c \
	$(SOURCE_DIR)/pexpert/i386/pe_init.c \
	$(SOURCE_DIR)/pexpert/i386/pe_bootargs.c \
	$(SOURCE_DIR)/pexpert/i386/pe_identify_machine.c \
	$(SOURCE_DIR)/pexpert/i386/pe_kprintf.c \
	$(SOURCE_DIR)/pexpert/i386/pe_interrupt.c \
	$(SOURCE_DIR)/pexpert/i386/pe_serial.c 
COBJS=device_tree.o bootargs.o pe_gen.o pe_init.o pe_bootargs.o \
	pe_identify_machine.o pe_kprintf.o pe_interrupt.o pe_serial.o 

SFILES=SOBJS=

######################################################################
#BEGIN  Machine dependent Makefile fragment for x86_64
######################################################################

######################################################################
#END    Machine dependent Makefile fragment for x86_64
######################################################################


#
#  OBJSDEPS is the set of files (defined in the machine dependent
#  template if necessary) which all objects depend on (such as an
#  in-line assembler expansion filter)
#
${OBJS}: ${OBJSDEPS}

LDOBJS = $(OBJS)

$(COMPONENT).filelist: $(LDOBJS)
	@echo LDFILELIST $(COMPONENT)
	$(_v)( for obj in ${LDOBJS}; do	\
		 echo $(TARGET)/$(CURRENT_KERNEL_CONFIG)/$${obj}; \
	done; ) > $(COMPONENT).filelist

do_all: $(COMPONENT).filelist

do_build_all:: do_all

-include device_tree.d
device_tree.o: $(SOURCE_DIR)/pexpert/gen/device_tree.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/gen/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/gen/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bootargs.d
bootargs.o: $(SOURCE_DIR)/pexpert/gen/bootargs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/gen/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/gen/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pe_gen.d
pe_gen.o: $(SOURCE_DIR)/pexpert/gen/pe_gen.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/gen/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/gen/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pe_init.d
pe_init.o: $(SOURCE_DIR)/pexpert/i386/pe_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pe_bootargs.d
pe_bootargs.o: $(SOURCE_DIR)/pexpert/i386/pe_bootargs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pe_identify_machine.d
pe_identify_machine.o: $(SOURCE_DIR)/pexpert/i386/pe_identify_machine.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pe_kprintf.d
pe_kprintf.o: $(SOURCE_DIR)/pexpert/i386/pe_kprintf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pe_interrupt.d
pe_interrupt.o: $(SOURCE_DIR)/pexpert/i386/pe_interrupt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pe_serial.d
pe_serial.o: $(SOURCE_DIR)/pexpert/i386/pe_serial.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/pexpert/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}

include $(MakeInc_rule)
include $(MakeInc_dir)
