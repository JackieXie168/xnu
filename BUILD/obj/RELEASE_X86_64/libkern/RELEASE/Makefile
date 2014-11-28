SOURCE_DIR=/Users/admin/Code/xnu/xnu-2422.115.4
export IDENT=-DLIBKERN -DVM_PRESSURE_EVENTS -DIOKITSTATS -DCONFIG_KXLD -DCONFIG_KEC_FIPS -DCONFIG_MACF
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
CFLAGS+= -include meta_features.h -DLIBKERN_KERNEL_PRIVATE -DOSALLOCDEBUG=1

# Objects that don't want -Wcast-align warning (8474835)
OSKextLib.cpo_CXXWARNFLAGS_ADD = -Wno-cast-align
OSKext.cpo_CXXWARNFLAGS_ADD = -Wno-cast-align
OSMetaClass.cpo_CXXWARNFLAGS_ADD = -Wno-cast-align
OSUnserialize.cpo_CXXWARNFLAGS_ADD = -Wno-cast-align
corecrypto_md5.o_CWARNFLAGS_ADD = -Wno-cast-align
corecrypto_sha1.o_CWARNFLAGS_ADD = -Wno-cast-align

# zlib is 3rd party source
compress.o_CWARNFLAGS_ADD = -Wno-cast-qual 
deflate.o_CWARNFLAGS_ADD = -Wno-cast-qual 
infback.o_CWARNFLAGS_ADD = -Wno-cast-qual 
inffast.o_CWARNFLAGS_ADD = -Wno-cast-qual 
inflate.o_CWARNFLAGS_ADD = -Wno-cast-qual 
trees.o_CWARNFLAGS_ADD = -Wno-cast-qual 
uncompr.o_CWARNFLAGS_ADD = -Wno-cast-qual 

# warnings in bison-generated code
OSUnserializeXML.cpo_CXXWARNFLAGS_ADD = -Wno-uninitialized

# Runtime support functions don't interact well with LTO (9294679)
stack_protector.o_CFLAGS_ADD += $(CFLAGS_NOLTO_FLAG)

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

OBJS=OSAtomicOperations.o OSDebug.cpo OSMetaClass.cpo OSObject.cpo \
	OSArray.cpo OSBoolean.cpo OSCollection.cpo \
	OSCollectionIterator.cpo OSData.cpo OSDictionary.cpo \
	OSIterator.cpo OSKext.cpo OSNumber.cpo OSOrderedSet.cpo \
	OSRuntime.cpo OSRuntimeSupport.o OSSerialize.cpo OSSet.cpo \
	OSString.cpo OSSymbol.cpo OSUnserialize.cpo OSUnserializeXML.cpo \
	OSKextLib.cpo mkext.o OSKextVersion.o inet_aton.o inet_ntoa.o \
	inet_ntop.o inet_pton.o scanf.o uuid.o kernel_mach_header.o \
	adler32.o compress.o crc32.o deflate.o infback.o inffast.o \
	inflate.o inftrees.o trees.o uncompr.o zutil.o register_crypto.o \
	corecrypto_sha2.o corecrypto_sha1.o corecrypto_md5.o \
	corecrypto_des.o corecrypto_aes.o corecrypto_aesxts.o \
	stack_protector.o kxld.o kxld_array.o kxld_copyright.o \
	kxld_demangle.o kxld_dict.o kxld_kext.o kxld_reloc.o \
	kxld_object.o kxld_sect.o kxld_seg.o kxld_srcversion.o \
	kxld_sym.o kxld_symtab.o kxld_util.o kxld_uuid.o \
	kxld_versionmin.o kxld_vtable.o kxld_stubs.o OSAtomic.o 

CFILES=\
	$(SOURCE_DIR)/libkern/gen/OSAtomicOperations.c \
	$(SOURCE_DIR)/libkern/c++/OSRuntimeSupport.c \
	$(SOURCE_DIR)/libkern/mkext.c \
	$(SOURCE_DIR)/libkern/OSKextVersion.c \
	$(SOURCE_DIR)/libkern/net/inet_aton.c \
	$(SOURCE_DIR)/libkern/net/inet_ntoa.c \
	$(SOURCE_DIR)/libkern/net/inet_ntop.c \
	$(SOURCE_DIR)/libkern/net/inet_pton.c \
	$(SOURCE_DIR)/libkern/stdio/scanf.c \
	$(SOURCE_DIR)/libkern/uuid/uuid.c \
	$(SOURCE_DIR)/libkern/kernel_mach_header.c \
	$(SOURCE_DIR)/libkern/zlib/adler32.c \
	$(SOURCE_DIR)/libkern/zlib/compress.c \
	$(SOURCE_DIR)/libkern/zlib/crc32.c \
	$(SOURCE_DIR)/libkern/zlib/deflate.c \
	$(SOURCE_DIR)/libkern/zlib/infback.c \
	$(SOURCE_DIR)/libkern/zlib/inffast.c \
	$(SOURCE_DIR)/libkern/zlib/inflate.c \
	$(SOURCE_DIR)/libkern/zlib/inftrees.c \
	$(SOURCE_DIR)/libkern/zlib/trees.c \
	$(SOURCE_DIR)/libkern/zlib/uncompr.c \
	$(SOURCE_DIR)/libkern/zlib/zutil.c \
	$(SOURCE_DIR)/libkern/crypto/register_crypto.c \
	$(SOURCE_DIR)/libkern/crypto/corecrypto_sha2.c \
	$(SOURCE_DIR)/libkern/crypto/corecrypto_sha1.c \
	$(SOURCE_DIR)/libkern/crypto/corecrypto_md5.c \
	$(SOURCE_DIR)/libkern/crypto/corecrypto_des.c \
	$(SOURCE_DIR)/libkern/crypto/corecrypto_aes.c \
	$(SOURCE_DIR)/libkern/crypto/corecrypto_aesxts.c \
	$(SOURCE_DIR)/libkern/stack_protector.c \
	$(SOURCE_DIR)/libkern/kxld/kxld.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_array.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_copyright.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_demangle.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_dict.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_kext.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_reloc.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_object.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_sect.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_seg.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_srcversion.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_sym.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_symtab.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_util.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_uuid.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_versionmin.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_vtable.c \
	$(SOURCE_DIR)/libkern/kxld/kxld_stubs.c 
COBJS=OSAtomicOperations.o OSRuntimeSupport.o mkext.o OSKextVersion.o \
	inet_aton.o inet_ntoa.o inet_ntop.o inet_pton.o scanf.o uuid.o \
	kernel_mach_header.o adler32.o compress.o crc32.o deflate.o \
	infback.o inffast.o inflate.o inftrees.o trees.o uncompr.o \
	zutil.o register_crypto.o corecrypto_sha2.o corecrypto_sha1.o \
	corecrypto_md5.o corecrypto_des.o corecrypto_aes.o \
	corecrypto_aesxts.o stack_protector.o kxld.o kxld_array.o \
	kxld_copyright.o kxld_demangle.o kxld_dict.o kxld_kext.o \
	kxld_reloc.o kxld_object.o kxld_sect.o kxld_seg.o \
	kxld_srcversion.o kxld_sym.o kxld_symtab.o kxld_util.o \
	kxld_uuid.o kxld_versionmin.o kxld_vtable.o kxld_stubs.o 

SFILES=\
	$(SOURCE_DIR)/libkern/x86_64/OSAtomic.s 
SOBJS=OSAtomic.o 

######################################################################
#BEGIN	Machine dependent Makefile fragment for x86_64
######################################################################

######################################################################
#END	Machine dependent Makefile fragment for x86_64
######################################################################

#
# Machine-independent per-file flags
#

# zlib is 3rd party source
compress.o_CWARNFLAGS_ADD = -Wno-cast-qual 
deflate.o_CWARNFLAGS_ADD = -Wno-cast-qual 
infback.o_CWARNFLAGS_ADD = -Wno-cast-qual 
inffast.o_CWARNFLAGS_ADD = -Wno-cast-qual 
inflate.o_CWARNFLAGS_ADD = -Wno-cast-qual 
trees.o_CWARNFLAGS_ADD = -Wno-cast-qual 
uncompr.o_CWARNFLAGS_ADD = -Wno-cast-qual 

# warnings in bison-generated code
OSUnserializeXML.cpo_CXXWARNFLAGS_ADD = -Wno-uninitialized

#
#  OBJSDEPS is the set of files (defined in the machine dependent
#  template if necessary) which all objects depend on (such as an
#  in-line assembler expansion filter)
#
${OBJS}: ${OBJSDEPS}

LDOBJS = $(OBJS)

$(COMPONENT).filelist: $(LDOBJS)
	$(_v)for hib_file in ${HIB_FILES}; \
	do	\
		$(SEG_HACK) -n __HIB -o $${hib_file}__ $${hib_file} ; \
		mv $${hib_file}__ $${hib_file} ; \
	done
	@echo LDFILELIST $(COMPONENT)
	$(_v)( for obj in ${LDOBJS}; do	\
		 echo $(TARGET)/$(CURRENT_KERNEL_CONFIG)/$${obj}; \
	done; ) > $(COMPONENT).filelist

do_all: $(COMPONENT).filelist

do_build_all:: do_all

-include OSAtomicOperations.d
OSAtomicOperations.o: $(SOURCE_DIR)/libkern/gen/OSAtomicOperations.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/gen/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/gen/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include OSDebug.cpd
OSDebug.cpo: $(SOURCE_DIR)/libkern/gen/OSDebug.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/gen/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/gen/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSMetaClass.cpd
OSMetaClass.cpo: $(SOURCE_DIR)/libkern/c++/OSMetaClass.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSObject.cpd
OSObject.cpo: $(SOURCE_DIR)/libkern/c++/OSObject.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSArray.cpd
OSArray.cpo: $(SOURCE_DIR)/libkern/c++/OSArray.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSBoolean.cpd
OSBoolean.cpo: $(SOURCE_DIR)/libkern/c++/OSBoolean.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSCollection.cpd
OSCollection.cpo: $(SOURCE_DIR)/libkern/c++/OSCollection.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSCollectionIterator.cpd
OSCollectionIterator.cpo: $(SOURCE_DIR)/libkern/c++/OSCollectionIterator.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSData.cpd
OSData.cpo: $(SOURCE_DIR)/libkern/c++/OSData.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSDictionary.cpd
OSDictionary.cpo: $(SOURCE_DIR)/libkern/c++/OSDictionary.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSIterator.cpd
OSIterator.cpo: $(SOURCE_DIR)/libkern/c++/OSIterator.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSKext.cpd
OSKext.cpo: $(SOURCE_DIR)/libkern/c++/OSKext.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSNumber.cpd
OSNumber.cpo: $(SOURCE_DIR)/libkern/c++/OSNumber.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSOrderedSet.cpd
OSOrderedSet.cpo: $(SOURCE_DIR)/libkern/c++/OSOrderedSet.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSRuntime.cpd
OSRuntime.cpo: $(SOURCE_DIR)/libkern/c++/OSRuntime.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSRuntimeSupport.d
OSRuntimeSupport.o: $(SOURCE_DIR)/libkern/c++/OSRuntimeSupport.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/c++/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include OSSerialize.cpd
OSSerialize.cpo: $(SOURCE_DIR)/libkern/c++/OSSerialize.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSSet.cpd
OSSet.cpo: $(SOURCE_DIR)/libkern/c++/OSSet.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSString.cpd
OSString.cpo: $(SOURCE_DIR)/libkern/c++/OSString.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSSymbol.cpd
OSSymbol.cpo: $(SOURCE_DIR)/libkern/c++/OSSymbol.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSUnserialize.cpd
OSUnserialize.cpo: $(SOURCE_DIR)/libkern/c++/OSUnserialize.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSUnserializeXML.cpd
OSUnserializeXML.cpo: $(SOURCE_DIR)/libkern/c++/OSUnserializeXML.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/c++/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/c++/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include OSKextLib.cpd
OSKextLib.cpo: $(SOURCE_DIR)/libkern/OSKextLib.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/libkern/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/libkern/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include mkext.d
mkext.o: $(SOURCE_DIR)/libkern/mkext.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include OSKextVersion.d
OSKextVersion.o: $(SOURCE_DIR)/libkern/OSKextVersion.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include inet_aton.d
inet_aton.o: $(SOURCE_DIR)/libkern/net/inet_aton.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include inet_ntoa.d
inet_ntoa.o: $(SOURCE_DIR)/libkern/net/inet_ntoa.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include inet_ntop.d
inet_ntop.o: $(SOURCE_DIR)/libkern/net/inet_ntop.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include inet_pton.d
inet_pton.o: $(SOURCE_DIR)/libkern/net/inet_pton.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include scanf.d
scanf.o: $(SOURCE_DIR)/libkern/stdio/scanf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/stdio/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/stdio/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uuid.d
uuid.o: $(SOURCE_DIR)/libkern/uuid/uuid.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/uuid/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/uuid/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kernel_mach_header.d
kernel_mach_header.o: $(SOURCE_DIR)/libkern/kernel_mach_header.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include adler32.d
adler32.o: $(SOURCE_DIR)/libkern/zlib/adler32.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include compress.d
compress.o: $(SOURCE_DIR)/libkern/zlib/compress.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include crc32.d
crc32.o: $(SOURCE_DIR)/libkern/zlib/crc32.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include deflate.d
deflate.o: $(SOURCE_DIR)/libkern/zlib/deflate.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include infback.d
infback.o: $(SOURCE_DIR)/libkern/zlib/infback.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include inffast.d
inffast.o: $(SOURCE_DIR)/libkern/zlib/inffast.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include inflate.d
inflate.o: $(SOURCE_DIR)/libkern/zlib/inflate.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include inftrees.d
inftrees.o: $(SOURCE_DIR)/libkern/zlib/inftrees.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include trees.d
trees.o: $(SOURCE_DIR)/libkern/zlib/trees.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uncompr.d
uncompr.o: $(SOURCE_DIR)/libkern/zlib/uncompr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include zutil.d
zutil.o: $(SOURCE_DIR)/libkern/zlib/zutil.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/zlib/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include register_crypto.d
register_crypto.o: $(SOURCE_DIR)/libkern/crypto/register_crypto.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include corecrypto_sha2.d
corecrypto_sha2.o: $(SOURCE_DIR)/libkern/crypto/corecrypto_sha2.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include corecrypto_sha1.d
corecrypto_sha1.o: $(SOURCE_DIR)/libkern/crypto/corecrypto_sha1.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include corecrypto_md5.d
corecrypto_md5.o: $(SOURCE_DIR)/libkern/crypto/corecrypto_md5.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include corecrypto_des.d
corecrypto_des.o: $(SOURCE_DIR)/libkern/crypto/corecrypto_des.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include corecrypto_aes.d
corecrypto_aes.o: $(SOURCE_DIR)/libkern/crypto/corecrypto_aes.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include corecrypto_aesxts.d
corecrypto_aesxts.o: $(SOURCE_DIR)/libkern/crypto/corecrypto_aesxts.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/crypto/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include stack_protector.d
stack_protector.o: $(SOURCE_DIR)/libkern/stack_protector.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld.d
kxld.o: $(SOURCE_DIR)/libkern/kxld/kxld.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_array.d
kxld_array.o: $(SOURCE_DIR)/libkern/kxld/kxld_array.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_copyright.d
kxld_copyright.o: $(SOURCE_DIR)/libkern/kxld/kxld_copyright.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_demangle.d
kxld_demangle.o: $(SOURCE_DIR)/libkern/kxld/kxld_demangle.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_dict.d
kxld_dict.o: $(SOURCE_DIR)/libkern/kxld/kxld_dict.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_kext.d
kxld_kext.o: $(SOURCE_DIR)/libkern/kxld/kxld_kext.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_reloc.d
kxld_reloc.o: $(SOURCE_DIR)/libkern/kxld/kxld_reloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_object.d
kxld_object.o: $(SOURCE_DIR)/libkern/kxld/kxld_object.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_sect.d
kxld_sect.o: $(SOURCE_DIR)/libkern/kxld/kxld_sect.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_seg.d
kxld_seg.o: $(SOURCE_DIR)/libkern/kxld/kxld_seg.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_srcversion.d
kxld_srcversion.o: $(SOURCE_DIR)/libkern/kxld/kxld_srcversion.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_sym.d
kxld_sym.o: $(SOURCE_DIR)/libkern/kxld/kxld_sym.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_symtab.d
kxld_symtab.o: $(SOURCE_DIR)/libkern/kxld/kxld_symtab.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_util.d
kxld_util.o: $(SOURCE_DIR)/libkern/kxld/kxld_util.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_uuid.d
kxld_uuid.o: $(SOURCE_DIR)/libkern/kxld/kxld_uuid.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_versionmin.d
kxld_versionmin.o: $(SOURCE_DIR)/libkern/kxld/kxld_versionmin.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_vtable.d
kxld_vtable.o: $(SOURCE_DIR)/libkern/kxld/kxld_vtable.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kxld_stubs.d
kxld_stubs.o: $(SOURCE_DIR)/libkern/kxld/kxld_stubs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/libkern/kxld/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include OSAtomic.d
OSAtomic.o: $(SOURCE_DIR)/libkern/x86_64/OSAtomic.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/libkern/x86_64/${S_RULE_1B}
	${S_RULE_2}

include $(MakeInc_rule)
include $(MakeInc_dir)
