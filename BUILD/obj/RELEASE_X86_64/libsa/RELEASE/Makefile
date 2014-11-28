SOURCE_DIR=/Users/admin/Code/xnu/xnu-2422.115.4
export IDENT=-DLIBSA -DVM_PRESSURE_EVENTS -DCONFIG_KXLD -DCONFIG_KEXT_BASEMENT
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
CFLAGS+= -include meta_features.h -DLIBSA_KERNEL_PRIVATE

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

OBJS=bootstrap.cpo 

CFILES=COBJS=

SFILES=SOBJS=

######################################################################
#BEGIN	Machine dependent Makefile fragment for x86_64
######################################################################


# Bootstrap __KLD files must be Mach-O for "setsegname"
$(foreach file,$(OBJS),$(eval $(file)_CFLAGS_ADD += $(CFLAGS_NOLTO_FLAG)))

######################################################################
#END	Machine dependent Makefile fragment for x86_64
######################################################################

#
#  OBJSDEPS is the set of files (defined in the machine dependent
#  template if necessary) which all objects depend on (such as an
#  in-line assembler expansion filter)
#
${OBJS}: ${OBJSDEPS}

LDOBJS = $(OBJS)

$(COMPONENT).filelist: $(LDOBJS)
	$(_v)for kld_file in ${LDOBJS}; do      \
		$(SEG_HACK) -n __KLD -o $${kld_file}__ $${kld_file} ; \
		mv $${kld_file}__ $${kld_file} ; \
	done
	@echo LDFILELIST $(COMPONENT)
	$(_v)( for obj in ${LDOBJS}; do	\
		 echo $(TARGET)/$(CURRENT_KERNEL_CONFIG)/$${obj}; \
	done; ) > $(COMPONENT).filelist


do_all: $(COMPONENT).filelist

do_build_all:: do_all

-include bootstrap.cpd
bootstrap.cpo: $(SOURCE_DIR)/libsa/bootstrap.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libsa/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libsa/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}

include $(MakeInc_rule)
include $(MakeInc_dir)
