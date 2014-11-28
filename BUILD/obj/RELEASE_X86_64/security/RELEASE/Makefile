SOURCE_DIR=/Users/admin/Code/xnu/xnu-2422.115.4
export IDENT=-DSECURITY -DCONFIG_LCTX -DCONFIG_DTRACE -DVM_PRESSURE_EVENTS -DCONFIG_MEMORYSTATUS -DCONFIG_TRIGGERS -DCONFIG_EXT_RESOLVER -DCONFIG_AUDIT
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
# XXX: CFLAGS
#
CFLAGS+= -include meta_features.h -DBSD_KERNEL_PRIVATE

# Objects that don't want -Wcast-align warning (8474835)
OBJS_NO_CAST_ALIGN =		\
		mac_alloc.o	\
		mac_base.o

$(foreach file,$(OBJS_NO_CAST_ALIGN),$(eval $(call add_perfile_cflags,$(file),-Wno-cast-align)))

#
# INCFLAGS to include security prototypes
#
INCFLAGS_MAKEFILE= -I$(SOURCE)/..

#
# Directories for mig generated files
#
COMP_SUBDIRS = 

#
#  Make sure we don't remove this by accident if interrupted at the wrong
#  time.
#
.PRECIOUS: Makefile

VERSION_FILES= \
	$(SOURCE_DIR)/$(COMPONENT)/conf/version.major  \
	$(SOURCE_DIR)/$(COMPONENT)/conf/version.minor   \
	$(SOURCE_DIR)/$(COMPONENT)/conf/version.variant

COPYRIGHT_FILES = \
	$(SOURCE_DIR)/$(COMPONENT)/conf/copyright.nai

#
#  Theses macros are filled in by the config program depending on the
#  current configuration.  The MACHDEP macro is replaced by the
#  contents of the machine dependent makefile template and the others
#  are replaced by the corresponding symbol definitions for the
#  configuration.
#

OBJS=mac_alloc.o mac_audit.o mac_base.o mac_data.o mac_label.o \
	mac_process.o mac_vfs.o mac_vfs_subr.o mac_system.o \
	mac_sysv_sem.o mac_sysv_shm.o mac_sysv_msg.o mac_posix_sem.o \
	mac_posix_shm.o mac_socket.o mac_pipe.o mac_iokit.o mac_file.o \
	mac_priv.o mac_pty.o mac_kext.o 

CFILES=\
	$(SOURCE_DIR)/security/mac_alloc.c \
	$(SOURCE_DIR)/security/mac_audit.c \
	$(SOURCE_DIR)/security/mac_base.c \
	$(SOURCE_DIR)/security/mac_data.c \
	$(SOURCE_DIR)/security/mac_label.c \
	$(SOURCE_DIR)/security/mac_process.c \
	$(SOURCE_DIR)/security/mac_vfs.c \
	$(SOURCE_DIR)/security/mac_vfs_subr.c \
	$(SOURCE_DIR)/security/mac_system.c \
	$(SOURCE_DIR)/security/mac_sysv_sem.c \
	$(SOURCE_DIR)/security/mac_sysv_shm.c \
	$(SOURCE_DIR)/security/mac_sysv_msg.c \
	$(SOURCE_DIR)/security/mac_posix_sem.c \
	$(SOURCE_DIR)/security/mac_posix_shm.c \
	$(SOURCE_DIR)/security/mac_socket.c \
	$(SOURCE_DIR)/security/mac_pipe.c \
	$(SOURCE_DIR)/security/mac_iokit.c \
	$(SOURCE_DIR)/security/mac_file.c \
	$(SOURCE_DIR)/security/mac_priv.c \
	$(SOURCE_DIR)/security/mac_pty.c \
	$(SOURCE_DIR)/security/mac_kext.c 
COBJS=mac_alloc.o mac_audit.o mac_base.o mac_data.o mac_label.o \
	mac_process.o mac_vfs.o mac_vfs_subr.o mac_system.o \
	mac_sysv_sem.o mac_sysv_shm.o mac_sysv_msg.o mac_posix_sem.o \
	mac_posix_shm.o mac_socket.o mac_pipe.o mac_iokit.o mac_file.o \
	mac_priv.o mac_pty.o mac_kext.o 

SFILES=SOBJS=

######################################################################
#BEGIN	Machine dependent Makefile fragment for x86_64
######################################################################

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

$(COMPONENT).filelist: $(LDOBJS) vers.o
	@echo LDFILELIST $(COMPONENT)
	$(_v)( for obj in ${LDOBJS} vers.o; do	\
		 echo $(TARGET)/$(CURRENT_KERNEL_CONFIG)/$${obj}; \
	done; ) > $(COMPONENT).filelist

do_all: $(COMPONENT).filelist

do_build_all:: do_all

vers.o: vers.c
	@echo CC $@
	$(_v)${KCC} $(CFLAGS) -o ${@} -c ${INCFLAGS} $<

vers.c:
	$(_v)$(SRCROOT)/SETUP/newvers \
		`$(CAT) ${VERSION_FILES}` ${COPYRIGHT_FILES}

-include mac_alloc.d
mac_alloc.o: $(SOURCE_DIR)/security/mac_alloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_audit.d
mac_audit.o: $(SOURCE_DIR)/security/mac_audit.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_base.d
mac_base.o: $(SOURCE_DIR)/security/mac_base.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_data.d
mac_data.o: $(SOURCE_DIR)/security/mac_data.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_label.d
mac_label.o: $(SOURCE_DIR)/security/mac_label.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_process.d
mac_process.o: $(SOURCE_DIR)/security/mac_process.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_vfs.d
mac_vfs.o: $(SOURCE_DIR)/security/mac_vfs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_vfs_subr.d
mac_vfs_subr.o: $(SOURCE_DIR)/security/mac_vfs_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_system.d
mac_system.o: $(SOURCE_DIR)/security/mac_system.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_sysv_sem.d
mac_sysv_sem.o: $(SOURCE_DIR)/security/mac_sysv_sem.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_sysv_shm.d
mac_sysv_shm.o: $(SOURCE_DIR)/security/mac_sysv_shm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_sysv_msg.d
mac_sysv_msg.o: $(SOURCE_DIR)/security/mac_sysv_msg.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_posix_sem.d
mac_posix_sem.o: $(SOURCE_DIR)/security/mac_posix_sem.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_posix_shm.d
mac_posix_shm.o: $(SOURCE_DIR)/security/mac_posix_shm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_socket.d
mac_socket.o: $(SOURCE_DIR)/security/mac_socket.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_pipe.d
mac_pipe.o: $(SOURCE_DIR)/security/mac_pipe.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_iokit.d
mac_iokit.o: $(SOURCE_DIR)/security/mac_iokit.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_file.d
mac_file.o: $(SOURCE_DIR)/security/mac_file.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_priv.d
mac_priv.o: $(SOURCE_DIR)/security/mac_priv.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_pty.d
mac_pty.o: $(SOURCE_DIR)/security/mac_pty.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mac_kext.d
mac_kext.o: $(SOURCE_DIR)/security/mac_kext.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/security/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/security/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}

include $(MakeInc_rule)
include $(MakeInc_dir)
