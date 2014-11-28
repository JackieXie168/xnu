SOURCE_DIR=/Users/admin/Code/xnu/xnu-2422.115.4
export IDENT=-DIOKIT -DIOKITSTATS -DVM_PRESSURE_EVENTS -DCONFIG_SLEEP -DCONFIG_MAX_THREADS="64" -DCONFIG_MEMORYSTATUS -DCONFIG_MACF
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
CFLAGS+= -include meta_features.h -DDRIVER_PRIVATE		\
	-DIOKIT_KERNEL_PRIVATE -DIOMATCHDEBUG=1 -DIOALLOCDEBUG=1
#-DIOKITDEBUG=-1

CWARNFLAGS   = $(CWARNFLAGS_STD) -Wno-unused-parameter
CXXWARNFLAGS = $(CXXWARNFLAGS_STD) -Wno-unused-parameter -Wno-cast-qual -Wno-shadow

# Objects that don't want -Wcast-align warning (8474835)
IOHibernateRestoreKernel.o_CWARNFLAGS_ADD = -Wno-cast-align
CXXOBJS_NO_CAST_ALIGN =				\
		IODMACommand.cpo		\
		IODataQueue.cpo			\
		IOHibernateIO.cpo		\
		IOMemoryDescriptor.cpo		\
		IONVRAM.cpo			\
		IOPMrootDomain.cpo		\
		IOSharedDataQueue.cpo		\
		IOUserClient.cpo

$(foreach file,$(CXXOBJS_NO_CAST_ALIGN),$(eval $(call add_perfile_cxxflags,$(file),-Wno-cast-align)))

CFLAGS_RELEASE += -DIOASSERT=0
CFLAGS_DEVELOPMENT += -DIOASSERT=1
CFLAGS_DEBUG += -DIOASSERT=1

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

OBJS=IOHibernateIO.cpo IOHibernateRestoreKernel.o IOLib.cpo IOLocks.cpo \
	IOConditionLock.cpo IOStartIOKit.cpo IODeviceTreeSupport.cpo \
	IORegistryEntry.cpo IOService.cpo IOServicePM.cpo \
	IOPMinformee.cpo IOPMinformeeList.cpo IOPMPowerStateQueue.cpo \
	IOCatalogue.cpo IOPMPowerSource.cpo IOPMPowerSourceList.cpo \
	IOPolledInterface.cpo IOWorkLoop.cpo IOEventSource.cpo \
	IOInterruptEventSource.cpo IOCommandGate.cpo IOCommand.cpo \
	IOCommandPool.cpo IOCommandQueue.cpo IODMAEventSource.cpo \
	IOFilterInterruptEventSource.cpo IOTimerEventSource.cpo \
	IOBufferMemoryDescriptor.cpo IODMACommand.cpo IODeviceMemory.cpo \
	IOInterleavedMemoryDescriptor.cpo IOMapper.cpo \
	IOMemoryCursor.cpo IOMemoryDescriptor.cpo \
	IOMultiMemoryDescriptor.cpo IORangeAllocator.cpo \
	IOSubMemoryDescriptor.cpo IOPlatformExpert.cpo IOCPU.cpo \
	IONVRAM.cpo IODMAController.cpo IOInterruptController.cpo \
	IOUserClient.cpo IOKitDebug.cpo IODataQueue.cpo \
	IOSharedDataQueue.cpo IOStatistics.cpo IOStringFuncs.o \
	KernelConfigTables.cpo IOKitBSDInit.cpo DINetBootHook.cpo \
	RootDomainUserClient.cpo IOPowerConnection.cpo \
	IOWatchDogTimer.cpo IOSyncer.cpo IOSharedLock.o IOAsmSupport.o \
	IOPMrootDomain.cpo IOKeyStoreHelper.cpo 

CFILES=\
	$(SOURCE_DIR)/iokit/Kernel/IOHibernateRestoreKernel.c \
	$(SOURCE_DIR)/iokit/Kernel/IOStringFuncs.c 
COBJS=IOHibernateRestoreKernel.o IOStringFuncs.o 

SFILES=\
	$(SOURCE_DIR)/iokit/Kernel/x86_64/IOSharedLock.s \
	$(SOURCE_DIR)/iokit/Kernel/x86_64/IOAsmSupport.s 
SOBJS=IOSharedLock.o IOAsmSupport.o 

######################################################################
#BEGIN  Machine dependent Makefile fragment for x86_64
######################################################################

# Files that must go in the __HIB segment:
UNCONFIGURED_HIB_FILES=	\
			IOHibernateRestoreKernel.o

HIB_FILES=$(filter $(UNCONFIGURED_HIB_FILES),$(OBJS))

# Unconfigured __HIB files must be Mach-O for "setsegname"
IOHibernateRestoreKernel.o_CFLAGS_ADD += -fno-stack-protector $(CFLAGS_NOLTO_FLAG)

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
	$(_v)for hib_file in ${HIB_FILES};		\
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

-include IOHibernateIO.cpd
IOHibernateIO.cpo: $(SOURCE_DIR)/iokit/Kernel/IOHibernateIO.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOHibernateRestoreKernel.d
IOHibernateRestoreKernel.o: $(SOURCE_DIR)/iokit/Kernel/IOHibernateRestoreKernel.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include IOLib.cpd
IOLib.cpo: $(SOURCE_DIR)/iokit/Kernel/IOLib.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOLocks.cpd
IOLocks.cpo: $(SOURCE_DIR)/iokit/Kernel/IOLocks.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOConditionLock.cpd
IOConditionLock.cpo: $(SOURCE_DIR)/iokit/Kernel/IOConditionLock.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOStartIOKit.cpd
IOStartIOKit.cpo: $(SOURCE_DIR)/iokit/Kernel/IOStartIOKit.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IODeviceTreeSupport.cpd
IODeviceTreeSupport.cpo: $(SOURCE_DIR)/iokit/Kernel/IODeviceTreeSupport.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IORegistryEntry.cpd
IORegistryEntry.cpo: $(SOURCE_DIR)/iokit/Kernel/IORegistryEntry.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOService.cpd
IOService.cpo: $(SOURCE_DIR)/iokit/Kernel/IOService.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOServicePM.cpd
IOServicePM.cpo: $(SOURCE_DIR)/iokit/Kernel/IOServicePM.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPMinformee.cpd
IOPMinformee.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPMinformee.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPMinformeeList.cpd
IOPMinformeeList.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPMinformeeList.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPMPowerStateQueue.cpd
IOPMPowerStateQueue.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPMPowerStateQueue.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOCatalogue.cpd
IOCatalogue.cpo: $(SOURCE_DIR)/iokit/Kernel/IOCatalogue.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPMPowerSource.cpd
IOPMPowerSource.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPMPowerSource.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPMPowerSourceList.cpd
IOPMPowerSourceList.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPMPowerSourceList.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPolledInterface.cpd
IOPolledInterface.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPolledInterface.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOWorkLoop.cpd
IOWorkLoop.cpo: $(SOURCE_DIR)/iokit/Kernel/IOWorkLoop.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOEventSource.cpd
IOEventSource.cpo: $(SOURCE_DIR)/iokit/Kernel/IOEventSource.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOInterruptEventSource.cpd
IOInterruptEventSource.cpo: $(SOURCE_DIR)/iokit/Kernel/IOInterruptEventSource.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOCommandGate.cpd
IOCommandGate.cpo: $(SOURCE_DIR)/iokit/Kernel/IOCommandGate.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOCommand.cpd
IOCommand.cpo: $(SOURCE_DIR)/iokit/Kernel/IOCommand.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOCommandPool.cpd
IOCommandPool.cpo: $(SOURCE_DIR)/iokit/Kernel/IOCommandPool.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOCommandQueue.cpd
IOCommandQueue.cpo: $(SOURCE_DIR)/iokit/Kernel/IOCommandQueue.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IODMAEventSource.cpd
IODMAEventSource.cpo: $(SOURCE_DIR)/iokit/Kernel/IODMAEventSource.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOFilterInterruptEventSource.cpd
IOFilterInterruptEventSource.cpo: $(SOURCE_DIR)/iokit/Kernel/IOFilterInterruptEventSource.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOTimerEventSource.cpd
IOTimerEventSource.cpo: $(SOURCE_DIR)/iokit/Kernel/IOTimerEventSource.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOBufferMemoryDescriptor.cpd
IOBufferMemoryDescriptor.cpo: $(SOURCE_DIR)/iokit/Kernel/IOBufferMemoryDescriptor.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IODMACommand.cpd
IODMACommand.cpo: $(SOURCE_DIR)/iokit/Kernel/IODMACommand.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IODeviceMemory.cpd
IODeviceMemory.cpo: $(SOURCE_DIR)/iokit/Kernel/IODeviceMemory.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOInterleavedMemoryDescriptor.cpd
IOInterleavedMemoryDescriptor.cpo: $(SOURCE_DIR)/iokit/Kernel/IOInterleavedMemoryDescriptor.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOMapper.cpd
IOMapper.cpo: $(SOURCE_DIR)/iokit/Kernel/IOMapper.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOMemoryCursor.cpd
IOMemoryCursor.cpo: $(SOURCE_DIR)/iokit/Kernel/IOMemoryCursor.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOMemoryDescriptor.cpd
IOMemoryDescriptor.cpo: $(SOURCE_DIR)/iokit/Kernel/IOMemoryDescriptor.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOMultiMemoryDescriptor.cpd
IOMultiMemoryDescriptor.cpo: $(SOURCE_DIR)/iokit/Kernel/IOMultiMemoryDescriptor.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IORangeAllocator.cpd
IORangeAllocator.cpo: $(SOURCE_DIR)/iokit/Kernel/IORangeAllocator.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOSubMemoryDescriptor.cpd
IOSubMemoryDescriptor.cpo: $(SOURCE_DIR)/iokit/Kernel/IOSubMemoryDescriptor.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPlatformExpert.cpd
IOPlatformExpert.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPlatformExpert.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOCPU.cpd
IOCPU.cpo: $(SOURCE_DIR)/iokit/Kernel/IOCPU.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IONVRAM.cpd
IONVRAM.cpo: $(SOURCE_DIR)/iokit/Kernel/IONVRAM.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IODMAController.cpd
IODMAController.cpo: $(SOURCE_DIR)/iokit/Kernel/IODMAController.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOInterruptController.cpd
IOInterruptController.cpo: $(SOURCE_DIR)/iokit/Kernel/IOInterruptController.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOUserClient.cpd
IOUserClient.cpo: $(SOURCE_DIR)/iokit/Kernel/IOUserClient.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOKitDebug.cpd
IOKitDebug.cpo: $(SOURCE_DIR)/iokit/Kernel/IOKitDebug.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IODataQueue.cpd
IODataQueue.cpo: $(SOURCE_DIR)/iokit/Kernel/IODataQueue.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOSharedDataQueue.cpd
IOSharedDataQueue.cpo: $(SOURCE_DIR)/iokit/Kernel/IOSharedDataQueue.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOStatistics.cpd
IOStatistics.cpo: $(SOURCE_DIR)/iokit/Kernel/IOStatistics.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOStringFuncs.d
IOStringFuncs.o: $(SOURCE_DIR)/iokit/Kernel/IOStringFuncs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include KernelConfigTables.cpd
KernelConfigTables.cpo: $(SOURCE_DIR)/iokit/KernelConfigTables.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOKitBSDInit.cpd
IOKitBSDInit.cpo: $(SOURCE_DIR)/iokit/bsddev/IOKitBSDInit.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/bsddev/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/bsddev/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include DINetBootHook.cpd
DINetBootHook.cpo: $(SOURCE_DIR)/iokit/bsddev/DINetBootHook.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/bsddev/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/bsddev/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include RootDomainUserClient.cpd
RootDomainUserClient.cpo: $(SOURCE_DIR)/iokit/Kernel/RootDomainUserClient.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOPowerConnection.cpd
IOPowerConnection.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPowerConnection.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOWatchDogTimer.cpd
IOWatchDogTimer.cpo: $(SOURCE_DIR)/iokit/Families/IOSystemManagement/IOWatchDogTimer.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Families/IOSystemManagement/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Families/IOSystemManagement/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOSyncer.cpd
IOSyncer.cpo: $(SOURCE_DIR)/iokit/Kernel/IOSyncer.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOSharedLock.d
IOSharedLock.o: $(SOURCE_DIR)/iokit/Kernel/x86_64/IOSharedLock.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include IOAsmSupport.d
IOAsmSupport.o: $(SOURCE_DIR)/iokit/Kernel/x86_64/IOAsmSupport.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include IOPMrootDomain.cpd
IOPMrootDomain.cpo: $(SOURCE_DIR)/iokit/Kernel/IOPMrootDomain.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}
-include IOKeyStoreHelper.cpd
IOKeyStoreHelper.cpo: $(SOURCE_DIR)/iokit/Kernel/i386/IOKeyStoreHelper.cpp
	${P_RULE_0}
	${P_RULE_1A}$(SOURCE_DIR)/iokit/Kernel/i386/${P_RULE_1B}
	${P_CTFRULE_1A}$(SOURCE_DIR)/iokit/Kernel/i386/${P_CTFRULE_1B}
	${P_RULE_2}
	${P_CTFRULE_2}

include $(MakeInc_rule)
include $(MakeInc_dir)
