SOURCE_DIR=/Users/admin/Code/xnu/xnu-2422.115.4
export IDENT=-DMACH -DMACH_KERNEL -DMACH_LOAD -DCONFIG_ZLEAKS -DCONFIG_SLEEP -DCONFIG_KEXT_BASEMENT -DCONFIG_THREAD_MAX="2560" -DCONFIG_TASK_MAX="1024" -DCONFIG_ZONE_MAP_MIN="12582912" -DCONFIG_ZLEAK_ALLOCATION_MAP_NUM="16384" -DCONFIG_ZLEAK_TRACE_MAP_NUM="8192" -DCONFIG_DYNAMIC_CODE_SIGNING -DCONFIG_SCHED_TRADITIONAL -DCONFIG_SCHED_PROTO -DCONFIG_SCHED_GRRR -DCONFIG_SCHED_FIXEDPRIORITY -DCONFIG_SCHED_GRRR_CORE -DCONFIG_GZALLOC -DCONFIG_MEMORYSTATUS -DVM_PRESSURE_EVENTS -DCONFIG_TELEMETRY -DPC_SUPPORT -DUXPR -DEVENT -DMACH_BSD -DIOKIT -DMACH_PE -DKPERF -DKPC -DPAE -DX86_64 -DDISPATCH_COUNTS -DPAL_I386 -DCONFIG_MACF -DCONFIG_AUDIT -DCONFIG_CODE_DECRYPTION -DCONFIG_MCA -DCONFIG_VMX -DCONFIG_MTRR
OSFMK_MACHINE=x86_64
CCONFIGFLAGS=-O3
RELOC=00100000
SYMADDR=00780000
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
CFLAGS+= -include meta_features.h -DMACH_KERNEL_PRIVATE

# Objects that don't want -Wcast-align warning (8474835)
OBJS_NO_CAST_ALIGN =			\
		model_dep.o		\
		chud_thread.o		\
		chud_thread_arm.o   \
		video_console.o		\
		kdp.o			\
		kdp_udp.o		\
		kdp_machdep.o		\
		host.o			\
		processor.o		\
		sched_prim.o		\
		task.o			\
		thread.o		\
		threadinfo.o		\
		gssd_mach.o		\
		UNDRequest.o		\
		panic_dialog.o		\
		bsd_i386.o		\
		commpage.o		\
		cpu_threads.o		\
		cpuid.o			\
		locks_i386.o		\
		machine_task.o		\
		mp_desc.o		\
		pcb.o			\
		pcb_native.o		\
		kdp_x86_common.o	\
		memory_object.o		\
		vm_apple_protect.o	\
		vm_map.o		\
		startup64.o		\
		affinity.o		\
		sched_grrr.o		\
		sched_fixedpriority.o	\
		stack.o			\
		task_policy.o		\
		wait_queue.o		\
		bsd_kern.o		\
		pmc.o			\
		default_freezer.o	\
		status.o		\
		machine_routines.o	\
		loose_ends.o		\
		sleh.o


$(foreach file,$(OBJS_NO_CAST_ALIGN),$(eval $(call add_perfile_cflags,$(file),-Wno-cast-align)))

#
# Do not provide CTF symbolic these files
#
chud_glue.o_SKIP_CTFCONVERT = 1

#
# XXX: INCFLAGS to include libsa prototypes
#
INCFLAGS_MAKEFILE= -I$(SOURCE)libsa

#
# Directories for mig generated files
#
COMP_SUBDIRS = \
	default_pager \
	device \
	mach \
	UserNotification \
	gssd \
	kextd \
	lockd

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

OBJS=vm_compressor_backing_store.o default_pager.o dp_backing_store.o \
	dp_memory_object.o default_pager_alerts_user.o \
	default_pager_object_server.o gssd_mach.o lockd_mach.o \
	kextd_mach.o UNDRequest.o UNDReplyServer.o \
	KUNCUserNotifications.o kdp.o kdp_udp.o kdp_serial.o ipc_entry.o \
	ipc_hash.o ipc_init.o ipc_kmsg.o ipc_mqueue.o ipc_notify.o \
	ipc_object.o ipc_port.o ipc_pset.o ipc_right.o ipc_space.o \
	ipc_table.o ipc_labelh.o mach_debug.o mach_kernelrpc.o \
	mach_msg.o mach_port.o affinity.o ast.o audit_sessionport.o \
	btlog.o clock.o clock_oldops.o counters.o debug.o exception.o \
	extmod_statistics.o host.o host_notify.o ipc_clock.o ipc_host.o \
	ipc_kobject.o ipc_mig.o ipc_misc.o ipc_sync.o ipc_tt.o kalloc.o \
	ledger.o locks.o machine.o mk_sp.o mk_timer.o page_decrypt.o \
	printf.o priority.o processor.o processor_data.o queue.o \
	sched_average.o sched_prim.o sched_proto.o sched_grrr.o \
	sched_fixedpriority.o security.o stack.o startup.o sync_lock.o \
	sync_sema.o syscall_emulation.o syscall_subr.o syscall_sw.o \
	task.o task_policy.o task_swap.o thread.o thread_act.o \
	thread_call.o thread_policy.o timer.o timer_call.o wait_queue.o \
	zalloc.o gzalloc.o bsd_kern.o hibernate.o pmc.o clock_server.o \
	clock_priv_server.o clock_reply_user.o exc_user.o exc_server.o \
	host_priv_server.o host_security_server.o lock_set_server.o \
	mach_exc_user.o mach_exc_server.o mach_host_server.o \
	mach_notify_user.o mach_port_server.o mach_vm_server.o \
	memory_object_server.o memory_object_control_server.o \
	memory_object_default_server.o memory_object_name_server.o \
	upl_server.o audit_triggers_user.o task_access_user.o \
	telemetry_notification_user.o processor_server.o \
	processor_set_server.o task_server.o thread_act_server.o \
	vm32_map_server.o security_server.o bsd_vm.o vm_compressor.o \
	vm_compressor_pager.o device_vm.o memory_object.o vm_debug.o \
	vm_external.o vm_fault.o vm_init.o vm_kern.o vm_map.o \
	vm_map_store.o vm_map_store_ll.o vm_map_store_rb.o vm_object.o \
	vm_pageout.o vm_purgeable.o vm_resident.o vm_shared_region.o \
	vm_swapfile_pager.o vm_user.o vm32_user.o iokit_rpc.o \
	device_server.o device_init.o kext_alloc.o kmod.o subrs.o \
	chud_cpu.o chud_glue.o chud_memory.o chud_osfmk_callback.o \
	chud_thread.o kperf.o action.o callstack.o pet.o threadinfo.o \
	timetrigger.o kperf_kpc.o kpc_thread.o kpc_common.o \
	serial_general.o telemetry.o vm_apple_protect.o pmap.o \
	pmap_x86_common.o pmap_common.o pmap_pcid.o pal_routines.o \
	pal_routines_asm.o bsd_i386.o bsd_i386_native.o machdep_call.o \
	boot_pt.o mp_desc.o gdt.o start.o bcopy.o bzero.o \
	WKdmDecompress_new.o WKdmCompress_new.o WKdmData_new.o cpu.o \
	cpuid.o cpu_threads.o cpu_topology.o i386_timer.o fpu.o \
	i386_lock.o i386_init.o i386_vm_init.o io_map.o ktss.o ldt.o \
	loose_ends.o copyio.o locks_i386.o locore.o lowmem_vectors.o \
	cswitch.o machine_routines.o machine_routines_asm.o \
	machine_check.o machine_task.o pcb.o pcb_native.o phys.o \
	rtclock.o rtclock_native.o trap.o trap_native.o user_ldt.o \
	Diagnostics.o pmCPU.o tsc.o commpage.o commpage_asm.o \
	fifo_queues.o conf.o model_dep.o lapic.o lapic_native.o mp.o \
	mp_native.o acpi.o mtrr.o serial_console.o video_console.o \
	video_scroll.o kdp_machdep.o kdp_vm.o kdp_x86_common.o \
	hibernate_i386.o hibernate_restore.o chud_osfmk_callback_i386.o \
	chud_cpu_i386.o chud_thread_i386.o ucode.o vmx_cpu.o vmx_shims.o \
	kperf_mp.o kpc_x86.o startup64.o idt64.o 

CFILES=\
	$(SOURCE_DIR)/osfmk/vm/vm_compressor_backing_store.c \
	$(SOURCE_DIR)/osfmk/default_pager/default_pager.c \
	$(SOURCE_DIR)/osfmk/default_pager/dp_backing_store.c \
	$(SOURCE_DIR)/osfmk/default_pager/dp_memory_object.c \
	./default_pager/default_pager_alerts_user.c \
	./default_pager/default_pager_object_server.c \
	./gssd/gssd_mach.c \
	./lockd/lockd_mach.c \
	./kextd/kextd_mach.c \
	./UserNotification/UNDRequest.c \
	./UserNotification/UNDReplyServer.c \
	$(SOURCE_DIR)/osfmk/UserNotification/KUNCUserNotifications.c \
	$(SOURCE_DIR)/osfmk/kdp/kdp.c \
	$(SOURCE_DIR)/osfmk/kdp/kdp_udp.c \
	$(SOURCE_DIR)/osfmk/kdp/kdp_serial.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_entry.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_hash.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_init.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_kmsg.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_mqueue.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_notify.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_object.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_port.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_pset.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_right.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_space.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_table.c \
	$(SOURCE_DIR)/osfmk/ipc/ipc_labelh.c \
	$(SOURCE_DIR)/osfmk/ipc/mach_debug.c \
	$(SOURCE_DIR)/osfmk/ipc/mach_kernelrpc.c \
	$(SOURCE_DIR)/osfmk/ipc/mach_msg.c \
	$(SOURCE_DIR)/osfmk/ipc/mach_port.c \
	$(SOURCE_DIR)/osfmk/kern/affinity.c \
	$(SOURCE_DIR)/osfmk/kern/ast.c \
	$(SOURCE_DIR)/osfmk/kern/audit_sessionport.c \
	$(SOURCE_DIR)/osfmk/kern/btlog.c \
	$(SOURCE_DIR)/osfmk/kern/clock.c \
	$(SOURCE_DIR)/osfmk/kern/clock_oldops.c \
	$(SOURCE_DIR)/osfmk/kern/counters.c \
	$(SOURCE_DIR)/osfmk/kern/debug.c \
	$(SOURCE_DIR)/osfmk/kern/exception.c \
	$(SOURCE_DIR)/osfmk/kern/extmod_statistics.c \
	$(SOURCE_DIR)/osfmk/kern/host.c \
	$(SOURCE_DIR)/osfmk/kern/host_notify.c \
	$(SOURCE_DIR)/osfmk/kern/ipc_clock.c \
	$(SOURCE_DIR)/osfmk/kern/ipc_host.c \
	$(SOURCE_DIR)/osfmk/kern/ipc_kobject.c \
	$(SOURCE_DIR)/osfmk/kern/ipc_mig.c \
	$(SOURCE_DIR)/osfmk/kern/ipc_misc.c \
	$(SOURCE_DIR)/osfmk/kern/ipc_sync.c \
	$(SOURCE_DIR)/osfmk/kern/ipc_tt.c \
	$(SOURCE_DIR)/osfmk/kern/kalloc.c \
	$(SOURCE_DIR)/osfmk/kern/ledger.c \
	$(SOURCE_DIR)/osfmk/kern/locks.c \
	$(SOURCE_DIR)/osfmk/kern/machine.c \
	$(SOURCE_DIR)/osfmk/kern/mk_sp.c \
	$(SOURCE_DIR)/osfmk/kern/mk_timer.c \
	$(SOURCE_DIR)/osfmk/kern/page_decrypt.c \
	$(SOURCE_DIR)/osfmk/kern/printf.c \
	$(SOURCE_DIR)/osfmk/kern/priority.c \
	$(SOURCE_DIR)/osfmk/kern/processor.c \
	$(SOURCE_DIR)/osfmk/kern/processor_data.c \
	$(SOURCE_DIR)/osfmk/kern/queue.c \
	$(SOURCE_DIR)/osfmk/kern/sched_average.c \
	$(SOURCE_DIR)/osfmk/kern/sched_prim.c \
	$(SOURCE_DIR)/osfmk/kern/sched_proto.c \
	$(SOURCE_DIR)/osfmk/kern/sched_grrr.c \
	$(SOURCE_DIR)/osfmk/kern/sched_fixedpriority.c \
	$(SOURCE_DIR)/osfmk/kern/security.c \
	$(SOURCE_DIR)/osfmk/kern/stack.c \
	$(SOURCE_DIR)/osfmk/kern/startup.c \
	$(SOURCE_DIR)/osfmk/kern/sync_lock.c \
	$(SOURCE_DIR)/osfmk/kern/sync_sema.c \
	$(SOURCE_DIR)/osfmk/kern/syscall_emulation.c \
	$(SOURCE_DIR)/osfmk/kern/syscall_subr.c \
	$(SOURCE_DIR)/osfmk/kern/syscall_sw.c \
	$(SOURCE_DIR)/osfmk/kern/task.c \
	$(SOURCE_DIR)/osfmk/kern/task_policy.c \
	$(SOURCE_DIR)/osfmk/kern/task_swap.c \
	$(SOURCE_DIR)/osfmk/kern/thread.c \
	$(SOURCE_DIR)/osfmk/kern/thread_act.c \
	$(SOURCE_DIR)/osfmk/kern/thread_call.c \
	$(SOURCE_DIR)/osfmk/kern/thread_policy.c \
	$(SOURCE_DIR)/osfmk/kern/timer.c \
	$(SOURCE_DIR)/osfmk/kern/timer_call.c \
	$(SOURCE_DIR)/osfmk/kern/wait_queue.c \
	$(SOURCE_DIR)/osfmk/kern/zalloc.c \
	$(SOURCE_DIR)/osfmk/kern/gzalloc.c \
	$(SOURCE_DIR)/osfmk/kern/bsd_kern.c \
	$(SOURCE_DIR)/osfmk/kern/hibernate.c \
	$(SOURCE_DIR)/osfmk/pmc/pmc.c \
	./mach/clock_server.c \
	./mach/clock_priv_server.c \
	./mach/clock_reply_user.c \
	./mach/exc_user.c \
	./mach/exc_server.c \
	./mach/host_priv_server.c \
	./mach/host_security_server.c \
	./mach/lock_set_server.c \
	./mach/mach_exc_user.c \
	./mach/mach_exc_server.c \
	./mach/mach_host_server.c \
	./mach/mach_notify_user.c \
	./mach/mach_port_server.c \
	./mach/mach_vm_server.c \
	./mach/memory_object_server.c \
	./mach/memory_object_control_server.c \
	./mach/memory_object_default_server.c \
	./mach/memory_object_name_server.c \
	./mach/upl_server.c \
	./mach/audit_triggers_user.c \
	./mach/task_access_user.c \
	./mach/telemetry_notification_user.c \
	./mach/processor_server.c \
	./mach/processor_set_server.c \
	./mach/task_server.c \
	./mach/thread_act_server.c \
	./mach/vm32_map_server.c \
	./mach/security_server.c \
	$(SOURCE_DIR)/osfmk/vm/bsd_vm.c \
	$(SOURCE_DIR)/osfmk/vm/vm_compressor.c \
	$(SOURCE_DIR)/osfmk/vm/vm_compressor_pager.c \
	$(SOURCE_DIR)/osfmk/vm/device_vm.c \
	$(SOURCE_DIR)/osfmk/vm/memory_object.c \
	$(SOURCE_DIR)/osfmk/vm/vm_debug.c \
	$(SOURCE_DIR)/osfmk/vm/vm_external.c \
	$(SOURCE_DIR)/osfmk/vm/vm_fault.c \
	$(SOURCE_DIR)/osfmk/vm/vm_init.c \
	$(SOURCE_DIR)/osfmk/vm/vm_kern.c \
	$(SOURCE_DIR)/osfmk/vm/vm_map.c \
	$(SOURCE_DIR)/osfmk/vm/vm_map_store.c \
	$(SOURCE_DIR)/osfmk/vm/vm_map_store_ll.c \
	$(SOURCE_DIR)/osfmk/vm/vm_map_store_rb.c \
	$(SOURCE_DIR)/osfmk/vm/vm_object.c \
	$(SOURCE_DIR)/osfmk/vm/vm_pageout.c \
	$(SOURCE_DIR)/osfmk/vm/vm_purgeable.c \
	$(SOURCE_DIR)/osfmk/vm/vm_resident.c \
	$(SOURCE_DIR)/osfmk/vm/vm_shared_region.c \
	$(SOURCE_DIR)/osfmk/vm/vm_swapfile_pager.c \
	$(SOURCE_DIR)/osfmk/vm/vm_user.c \
	$(SOURCE_DIR)/osfmk/vm/vm32_user.c \
	$(SOURCE_DIR)/osfmk/device/iokit_rpc.c \
	./device/device_server.c \
	$(SOURCE_DIR)/osfmk/device/device_init.c \
	$(SOURCE_DIR)/osfmk/kern/kext_alloc.c \
	$(SOURCE_DIR)/osfmk/kern/kmod.c \
	$(SOURCE_DIR)/osfmk/device/subrs.c \
	$(SOURCE_DIR)/osfmk/chud/chud_cpu.c \
	$(SOURCE_DIR)/osfmk/chud/chud_glue.c \
	$(SOURCE_DIR)/osfmk/chud/chud_memory.c \
	$(SOURCE_DIR)/osfmk/chud/chud_osfmk_callback.c \
	$(SOURCE_DIR)/osfmk/chud/chud_thread.c \
	$(SOURCE_DIR)/osfmk/kperf/kperf.c \
	$(SOURCE_DIR)/osfmk/kperf/action.c \
	$(SOURCE_DIR)/osfmk/kperf/callstack.c \
	$(SOURCE_DIR)/osfmk/kperf/pet.c \
	$(SOURCE_DIR)/osfmk/kperf/threadinfo.c \
	$(SOURCE_DIR)/osfmk/kperf/timetrigger.c \
	$(SOURCE_DIR)/osfmk/kperf/kperf_kpc.c \
	$(SOURCE_DIR)/osfmk/kern/kpc_thread.c \
	$(SOURCE_DIR)/osfmk/kern/kpc_common.c \
	$(SOURCE_DIR)/osfmk/console/serial_general.c \
	$(SOURCE_DIR)/osfmk/kern/telemetry.c \
	$(SOURCE_DIR)/osfmk/vm/vm_apple_protect.c \
	$(SOURCE_DIR)/osfmk/x86_64/pmap.c \
	$(SOURCE_DIR)/osfmk/i386/pmap_x86_common.c \
	$(SOURCE_DIR)/osfmk/i386/pmap_common.c \
	$(SOURCE_DIR)/osfmk/x86_64/pmap_pcid.c \
	$(SOURCE_DIR)/osfmk/i386/pal_routines.c \
	$(SOURCE_DIR)/osfmk/i386/bsd_i386.c \
	$(SOURCE_DIR)/osfmk/i386/bsd_i386_native.c \
	$(SOURCE_DIR)/osfmk/i386/machdep_call.c \
	$(SOURCE_DIR)/osfmk/x86_64/boot_pt.c \
	$(SOURCE_DIR)/osfmk/i386/mp_desc.c \
	$(SOURCE_DIR)/osfmk/i386/gdt.c \
	$(SOURCE_DIR)/osfmk/i386/cpu.c \
	$(SOURCE_DIR)/osfmk/i386/cpuid.c \
	$(SOURCE_DIR)/osfmk/i386/cpu_threads.c \
	$(SOURCE_DIR)/osfmk/i386/cpu_topology.c \
	$(SOURCE_DIR)/osfmk/i386/i386_timer.c \
	$(SOURCE_DIR)/osfmk/i386/fpu.c \
	$(SOURCE_DIR)/osfmk/i386/i386_init.c \
	$(SOURCE_DIR)/osfmk/i386/i386_vm_init.c \
	$(SOURCE_DIR)/osfmk/i386/io_map.c \
	$(SOURCE_DIR)/osfmk/i386/ktss.c \
	$(SOURCE_DIR)/osfmk/i386/ldt.c \
	$(SOURCE_DIR)/osfmk/x86_64/loose_ends.c \
	$(SOURCE_DIR)/osfmk/x86_64/copyio.c \
	$(SOURCE_DIR)/osfmk/i386/locks_i386.c \
	$(SOURCE_DIR)/osfmk/x86_64/lowmem_vectors.c \
	$(SOURCE_DIR)/osfmk/i386/machine_routines.c \
	$(SOURCE_DIR)/osfmk/i386/machine_check.c \
	$(SOURCE_DIR)/osfmk/i386/machine_task.c \
	$(SOURCE_DIR)/osfmk/i386/pcb.c \
	$(SOURCE_DIR)/osfmk/i386/pcb_native.c \
	$(SOURCE_DIR)/osfmk/i386/phys.c \
	$(SOURCE_DIR)/osfmk/i386/rtclock.c \
	$(SOURCE_DIR)/osfmk/i386/rtclock_native.c \
	$(SOURCE_DIR)/osfmk/i386/trap.c \
	$(SOURCE_DIR)/osfmk/i386/trap_native.c \
	$(SOURCE_DIR)/osfmk/i386/user_ldt.c \
	$(SOURCE_DIR)/osfmk/i386/Diagnostics.c \
	$(SOURCE_DIR)/osfmk/i386/pmCPU.c \
	$(SOURCE_DIR)/osfmk/i386/tsc.c \
	$(SOURCE_DIR)/osfmk/i386/commpage/commpage.c \
	$(SOURCE_DIR)/osfmk/i386/AT386/conf.c \
	$(SOURCE_DIR)/osfmk/i386/AT386/model_dep.c \
	$(SOURCE_DIR)/osfmk/i386/lapic.c \
	$(SOURCE_DIR)/osfmk/i386/lapic_native.c \
	$(SOURCE_DIR)/osfmk/i386/mp.c \
	$(SOURCE_DIR)/osfmk/i386/mp_native.c \
	$(SOURCE_DIR)/osfmk/i386/acpi.c \
	$(SOURCE_DIR)/osfmk/i386/mtrr.c \
	$(SOURCE_DIR)/osfmk/console/i386/serial_console.c \
	$(SOURCE_DIR)/osfmk/console/video_console.c \
	$(SOURCE_DIR)/osfmk/console/i386/video_scroll.c \
	$(SOURCE_DIR)/osfmk/kdp/ml/x86_64/kdp_machdep.c \
	$(SOURCE_DIR)/osfmk/kdp/ml/x86_64/kdp_vm.c \
	$(SOURCE_DIR)/osfmk/kdp/ml/i386/kdp_x86_common.c \
	$(SOURCE_DIR)/osfmk/i386/hibernate_i386.c \
	$(SOURCE_DIR)/osfmk/i386/hibernate_restore.c \
	$(SOURCE_DIR)/osfmk/chud/i386/chud_osfmk_callback_i386.c \
	$(SOURCE_DIR)/osfmk/chud/i386/chud_cpu_i386.c \
	$(SOURCE_DIR)/osfmk/chud/i386/chud_thread_i386.c \
	$(SOURCE_DIR)/osfmk/i386/ucode.c \
	$(SOURCE_DIR)/osfmk/i386/vmx/vmx_cpu.c \
	$(SOURCE_DIR)/osfmk/i386/vmx/vmx_shims.c \
	$(SOURCE_DIR)/osfmk/kperf/x86_64/kperf_mp.c \
	$(SOURCE_DIR)/osfmk/x86_64/kpc_x86.c \
	$(SOURCE_DIR)/osfmk/i386/startup64.c 
COBJS=vm_compressor_backing_store.o default_pager.o dp_backing_store.o \
	dp_memory_object.o default_pager_alerts_user.o \
	default_pager_object_server.o gssd_mach.o lockd_mach.o \
	kextd_mach.o UNDRequest.o UNDReplyServer.o \
	KUNCUserNotifications.o kdp.o kdp_udp.o kdp_serial.o ipc_entry.o \
	ipc_hash.o ipc_init.o ipc_kmsg.o ipc_mqueue.o ipc_notify.o \
	ipc_object.o ipc_port.o ipc_pset.o ipc_right.o ipc_space.o \
	ipc_table.o ipc_labelh.o mach_debug.o mach_kernelrpc.o \
	mach_msg.o mach_port.o affinity.o ast.o audit_sessionport.o \
	btlog.o clock.o clock_oldops.o counters.o debug.o exception.o \
	extmod_statistics.o host.o host_notify.o ipc_clock.o ipc_host.o \
	ipc_kobject.o ipc_mig.o ipc_misc.o ipc_sync.o ipc_tt.o kalloc.o \
	ledger.o locks.o machine.o mk_sp.o mk_timer.o page_decrypt.o \
	printf.o priority.o processor.o processor_data.o queue.o \
	sched_average.o sched_prim.o sched_proto.o sched_grrr.o \
	sched_fixedpriority.o security.o stack.o startup.o sync_lock.o \
	sync_sema.o syscall_emulation.o syscall_subr.o syscall_sw.o \
	task.o task_policy.o task_swap.o thread.o thread_act.o \
	thread_call.o thread_policy.o timer.o timer_call.o wait_queue.o \
	zalloc.o gzalloc.o bsd_kern.o hibernate.o pmc.o clock_server.o \
	clock_priv_server.o clock_reply_user.o exc_user.o exc_server.o \
	host_priv_server.o host_security_server.o lock_set_server.o \
	mach_exc_user.o mach_exc_server.o mach_host_server.o \
	mach_notify_user.o mach_port_server.o mach_vm_server.o \
	memory_object_server.o memory_object_control_server.o \
	memory_object_default_server.o memory_object_name_server.o \
	upl_server.o audit_triggers_user.o task_access_user.o \
	telemetry_notification_user.o processor_server.o \
	processor_set_server.o task_server.o thread_act_server.o \
	vm32_map_server.o security_server.o bsd_vm.o vm_compressor.o \
	vm_compressor_pager.o device_vm.o memory_object.o vm_debug.o \
	vm_external.o vm_fault.o vm_init.o vm_kern.o vm_map.o \
	vm_map_store.o vm_map_store_ll.o vm_map_store_rb.o vm_object.o \
	vm_pageout.o vm_purgeable.o vm_resident.o vm_shared_region.o \
	vm_swapfile_pager.o vm_user.o vm32_user.o iokit_rpc.o \
	device_server.o device_init.o kext_alloc.o kmod.o subrs.o \
	chud_cpu.o chud_glue.o chud_memory.o chud_osfmk_callback.o \
	chud_thread.o kperf.o action.o callstack.o pet.o threadinfo.o \
	timetrigger.o kperf_kpc.o kpc_thread.o kpc_common.o \
	serial_general.o telemetry.o vm_apple_protect.o pmap.o \
	pmap_x86_common.o pmap_common.o pmap_pcid.o pal_routines.o \
	bsd_i386.o bsd_i386_native.o machdep_call.o boot_pt.o mp_desc.o \
	gdt.o cpu.o cpuid.o cpu_threads.o cpu_topology.o i386_timer.o \
	fpu.o i386_init.o i386_vm_init.o io_map.o ktss.o ldt.o \
	loose_ends.o copyio.o locks_i386.o lowmem_vectors.o \
	machine_routines.o machine_check.o machine_task.o pcb.o \
	pcb_native.o phys.o rtclock.o rtclock_native.o trap.o \
	trap_native.o user_ldt.o Diagnostics.o pmCPU.o tsc.o commpage.o \
	conf.o model_dep.o lapic.o lapic_native.o mp.o mp_native.o \
	acpi.o mtrr.o serial_console.o video_console.o video_scroll.o \
	kdp_machdep.o kdp_vm.o kdp_x86_common.o hibernate_i386.o \
	hibernate_restore.o chud_osfmk_callback_i386.o chud_cpu_i386.o \
	chud_thread_i386.o ucode.o vmx_cpu.o vmx_shims.o kperf_mp.o \
	kpc_x86.o startup64.o 

SFILES=\
	$(SOURCE_DIR)/osfmk/x86_64/pal_routines_asm.s \
	$(SOURCE_DIR)/osfmk/x86_64/start.s \
	$(SOURCE_DIR)/osfmk/x86_64/bcopy.s \
	$(SOURCE_DIR)/osfmk/x86_64/bzero.s \
	$(SOURCE_DIR)/osfmk/x86_64/WKdmDecompress_new.s \
	$(SOURCE_DIR)/osfmk/x86_64/WKdmCompress_new.s \
	$(SOURCE_DIR)/osfmk/x86_64/WKdmData_new.s \
	$(SOURCE_DIR)/osfmk/i386/i386_lock.s \
	$(SOURCE_DIR)/osfmk/x86_64/locore.s \
	$(SOURCE_DIR)/osfmk/x86_64/cswitch.s \
	$(SOURCE_DIR)/osfmk/x86_64/machine_routines_asm.s \
	$(SOURCE_DIR)/osfmk/i386/commpage/commpage_asm.s \
	$(SOURCE_DIR)/osfmk/i386/commpage/fifo_queues.s \
	$(SOURCE_DIR)/osfmk/x86_64/idt64.s 
SOBJS=pal_routines_asm.o start.o bcopy.o bzero.o WKdmDecompress_new.o \
	WKdmCompress_new.o WKdmData_new.o i386_lock.o locore.o cswitch.o \
	machine_routines_asm.o commpage_asm.o fifo_queues.o idt64.o 

OSFMK_MACHINE=x86_64
CCONFIGFLAGS=-O3
RELOC=00100000
SYMADDR=00780000
######################################################################
#BEGIN	Machine dependent Makefile fragment for x86_64
######################################################################

CWARNFLAGS = $(CWARNFLAGS_STD) -Wshorten-64-to-32

# Files that must go in the __HIB segment:
UNCONFIGURED_HIB_FILES=					\
           WKdmDecompress_new.o         \
           WKdmData_new.o               \
           hibernate_restore.o          \
           hibernate_bootstrap.o	\
           bcopy.o			\
           bzero.o

HIB_FILES=$(filter $(UNCONFIGURED_HIB_FILES),$(OBJS))

# Unconfigured __HIB files must be Mach-O for "setsegname"
WKdmDecompress_new.o_CFLAGS_ADD += -fno-stack-protector $(CFLAGS_NOLTO_FLAG)
WKdmData_new.o_CFLAGS_ADD += -fno-stack-protector $(CFLAGS_NOLTO_FLAG)
hibernate_restore.o_CFLAGS_ADD += -fno-stack-protector $(CFLAGS_NOLTO_FLAG)
hibernate_bootstrap.o_CFLAGS_ADD += -fno-stack-protector $(CFLAGS_NOLTO_FLAG)
bcopy.o_CFLAGS_ADD += -fno-stack-protector $(CFLAGS_NOLTO_FLAG)
bzero.o_CFLAGS_ADD += -fno-stack-protector $(CFLAGS_NOLTO_FLAG)

# To appear at the beginning of the __HIB segment, emit
# as Mach-O so that the linker can enforce symbol order
boot_pt.o_CFLAGS_ADD += $(CFLAGS_NOLTO_FLAG)

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

$(COMPONENT).filelist: $(LDOBJS) assym.s
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

# genassym.o actually is an assembly file,
# we name it genassym.o to help with the automatic
# dependency generation

GENASSYM_LOCATION = $(CURRENT_ARCH_CONFIG_LC)

ifeq ($(CURRENT_ARCH_CONFIG_LC),x86_64)
GENASSYM_LOCATION = i386
endif

genassym.o: $(SOURCE_DIR)/$(COMPONENT)/$(GENASSYM_LOCATION)/genassym.c
	@echo GENASSYM $<
	$(_v)${KCC} $(subst -flto,,${CFLAGS}) -MD -S -o ${@} ${INCFLAGS} $<

assym.s: genassym.o
	$(_v)sed -e '/#DEFINITION#/!d' -e 's/^.*#DEFINITION#//' -e 's/\$$//' -e 'p' -e 's/#//2' -e 's/[^A-Za-z0-9_]*\([A-Za-z0-9_]*\)/ \1_NUM/2' genassym.o > $@

${SOBJS}: assym.s

-include vm_compressor_backing_store.d
vm_compressor_backing_store.o: $(SOURCE_DIR)/osfmk/vm/vm_compressor_backing_store.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include default_pager.d
default_pager.o: $(SOURCE_DIR)/osfmk/default_pager/default_pager.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/default_pager/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/default_pager/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dp_backing_store.d
dp_backing_store.o: $(SOURCE_DIR)/osfmk/default_pager/dp_backing_store.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/default_pager/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/default_pager/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dp_memory_object.d
dp_memory_object.o: $(SOURCE_DIR)/osfmk/default_pager/dp_memory_object.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/default_pager/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/default_pager/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include default_pager_alerts_user.d
default_pager_alerts_user.o: default_pager/default_pager_alerts_user.c
	${C_RULE_0}
	${C_RULE_1A}default_pager/${C_RULE_1B}
	${C_CTFRULE_1A}default_pager/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include default_pager_object_server.d
default_pager_object_server.o: default_pager/default_pager_object_server.c
	${C_RULE_0}
	${C_RULE_1A}default_pager/${C_RULE_1B}
	${C_CTFRULE_1A}default_pager/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include gssd_mach.d
gssd_mach.o: gssd/gssd_mach.c
	${C_RULE_0}
	${C_RULE_1A}gssd/${C_RULE_1B}
	${C_CTFRULE_1A}gssd/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include lockd_mach.d
lockd_mach.o: lockd/lockd_mach.c
	${C_RULE_0}
	${C_RULE_1A}lockd/${C_RULE_1B}
	${C_CTFRULE_1A}lockd/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kextd_mach.d
kextd_mach.o: kextd/kextd_mach.c
	${C_RULE_0}
	${C_RULE_1A}kextd/${C_RULE_1B}
	${C_CTFRULE_1A}kextd/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include UNDRequest.d
UNDRequest.o: UserNotification/UNDRequest.c
	${C_RULE_0}
	${C_RULE_1A}UserNotification/${C_RULE_1B}
	${C_CTFRULE_1A}UserNotification/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include UNDReplyServer.d
UNDReplyServer.o: UserNotification/UNDReplyServer.c
	${C_RULE_0}
	${C_RULE_1A}UserNotification/${C_RULE_1B}
	${C_CTFRULE_1A}UserNotification/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include KUNCUserNotifications.d
KUNCUserNotifications.o: $(SOURCE_DIR)/osfmk/UserNotification/KUNCUserNotifications.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/UserNotification/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/UserNotification/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kdp.d
kdp.o: $(SOURCE_DIR)/osfmk/kdp/kdp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kdp/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kdp/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kdp_udp.d
kdp_udp.o: $(SOURCE_DIR)/osfmk/kdp/kdp_udp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kdp/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kdp/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kdp_serial.d
kdp_serial.o: $(SOURCE_DIR)/osfmk/kdp/kdp_serial.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kdp/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kdp/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_entry.d
ipc_entry.o: $(SOURCE_DIR)/osfmk/ipc/ipc_entry.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_hash.d
ipc_hash.o: $(SOURCE_DIR)/osfmk/ipc/ipc_hash.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_init.d
ipc_init.o: $(SOURCE_DIR)/osfmk/ipc/ipc_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_kmsg.d
ipc_kmsg.o: $(SOURCE_DIR)/osfmk/ipc/ipc_kmsg.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_mqueue.d
ipc_mqueue.o: $(SOURCE_DIR)/osfmk/ipc/ipc_mqueue.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_notify.d
ipc_notify.o: $(SOURCE_DIR)/osfmk/ipc/ipc_notify.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_object.d
ipc_object.o: $(SOURCE_DIR)/osfmk/ipc/ipc_object.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_port.d
ipc_port.o: $(SOURCE_DIR)/osfmk/ipc/ipc_port.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_pset.d
ipc_pset.o: $(SOURCE_DIR)/osfmk/ipc/ipc_pset.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_right.d
ipc_right.o: $(SOURCE_DIR)/osfmk/ipc/ipc_right.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_space.d
ipc_space.o: $(SOURCE_DIR)/osfmk/ipc/ipc_space.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_table.d
ipc_table.o: $(SOURCE_DIR)/osfmk/ipc/ipc_table.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_labelh.d
ipc_labelh.o: $(SOURCE_DIR)/osfmk/ipc/ipc_labelh.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_debug.d
mach_debug.o: $(SOURCE_DIR)/osfmk/ipc/mach_debug.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_kernelrpc.d
mach_kernelrpc.o: $(SOURCE_DIR)/osfmk/ipc/mach_kernelrpc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_msg.d
mach_msg.o: $(SOURCE_DIR)/osfmk/ipc/mach_msg.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_port.d
mach_port.o: $(SOURCE_DIR)/osfmk/ipc/mach_port.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/ipc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include affinity.d
affinity.o: $(SOURCE_DIR)/osfmk/kern/affinity.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ast.d
ast.o: $(SOURCE_DIR)/osfmk/kern/ast.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_sessionport.d
audit_sessionport.o: $(SOURCE_DIR)/osfmk/kern/audit_sessionport.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include btlog.d
btlog.o: $(SOURCE_DIR)/osfmk/kern/btlog.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include clock.d
clock.o: $(SOURCE_DIR)/osfmk/kern/clock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include clock_oldops.d
clock_oldops.o: $(SOURCE_DIR)/osfmk/kern/clock_oldops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include counters.d
counters.o: $(SOURCE_DIR)/osfmk/kern/counters.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include debug.d
debug.o: $(SOURCE_DIR)/osfmk/kern/debug.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include exception.d
exception.o: $(SOURCE_DIR)/osfmk/kern/exception.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include extmod_statistics.d
extmod_statistics.o: $(SOURCE_DIR)/osfmk/kern/extmod_statistics.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include host.d
host.o: $(SOURCE_DIR)/osfmk/kern/host.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include host_notify.d
host_notify.o: $(SOURCE_DIR)/osfmk/kern/host_notify.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_clock.d
ipc_clock.o: $(SOURCE_DIR)/osfmk/kern/ipc_clock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_host.d
ipc_host.o: $(SOURCE_DIR)/osfmk/kern/ipc_host.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_kobject.d
ipc_kobject.o: $(SOURCE_DIR)/osfmk/kern/ipc_kobject.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_mig.d
ipc_mig.o: $(SOURCE_DIR)/osfmk/kern/ipc_mig.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_misc.d
ipc_misc.o: $(SOURCE_DIR)/osfmk/kern/ipc_misc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_sync.d
ipc_sync.o: $(SOURCE_DIR)/osfmk/kern/ipc_sync.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipc_tt.d
ipc_tt.o: $(SOURCE_DIR)/osfmk/kern/ipc_tt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kalloc.d
kalloc.o: $(SOURCE_DIR)/osfmk/kern/kalloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ledger.d
ledger.o: $(SOURCE_DIR)/osfmk/kern/ledger.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include locks.d
locks.o: $(SOURCE_DIR)/osfmk/kern/locks.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include machine.d
machine.o: $(SOURCE_DIR)/osfmk/kern/machine.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mk_sp.d
mk_sp.o: $(SOURCE_DIR)/osfmk/kern/mk_sp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mk_timer.d
mk_timer.o: $(SOURCE_DIR)/osfmk/kern/mk_timer.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include page_decrypt.d
page_decrypt.o: $(SOURCE_DIR)/osfmk/kern/page_decrypt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include printf.d
printf.o: $(SOURCE_DIR)/osfmk/kern/printf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include priority.d
priority.o: $(SOURCE_DIR)/osfmk/kern/priority.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include processor.d
processor.o: $(SOURCE_DIR)/osfmk/kern/processor.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include processor_data.d
processor_data.o: $(SOURCE_DIR)/osfmk/kern/processor_data.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include queue.d
queue.o: $(SOURCE_DIR)/osfmk/kern/queue.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sched_average.d
sched_average.o: $(SOURCE_DIR)/osfmk/kern/sched_average.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sched_prim.d
sched_prim.o: $(SOURCE_DIR)/osfmk/kern/sched_prim.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sched_proto.d
sched_proto.o: $(SOURCE_DIR)/osfmk/kern/sched_proto.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sched_grrr.d
sched_grrr.o: $(SOURCE_DIR)/osfmk/kern/sched_grrr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sched_fixedpriority.d
sched_fixedpriority.o: $(SOURCE_DIR)/osfmk/kern/sched_fixedpriority.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include security.d
security.o: $(SOURCE_DIR)/osfmk/kern/security.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include stack.d
stack.o: $(SOURCE_DIR)/osfmk/kern/stack.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include startup.d
startup.o: $(SOURCE_DIR)/osfmk/kern/startup.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sync_lock.d
sync_lock.o: $(SOURCE_DIR)/osfmk/kern/sync_lock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sync_sema.d
sync_sema.o: $(SOURCE_DIR)/osfmk/kern/sync_sema.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include syscall_emulation.d
syscall_emulation.o: $(SOURCE_DIR)/osfmk/kern/syscall_emulation.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include syscall_subr.d
syscall_subr.o: $(SOURCE_DIR)/osfmk/kern/syscall_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include syscall_sw.d
syscall_sw.o: $(SOURCE_DIR)/osfmk/kern/syscall_sw.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include task.d
task.o: $(SOURCE_DIR)/osfmk/kern/task.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include task_policy.d
task_policy.o: $(SOURCE_DIR)/osfmk/kern/task_policy.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include task_swap.d
task_swap.o: $(SOURCE_DIR)/osfmk/kern/task_swap.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include thread.d
thread.o: $(SOURCE_DIR)/osfmk/kern/thread.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include thread_act.d
thread_act.o: $(SOURCE_DIR)/osfmk/kern/thread_act.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include thread_call.d
thread_call.o: $(SOURCE_DIR)/osfmk/kern/thread_call.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include thread_policy.d
thread_policy.o: $(SOURCE_DIR)/osfmk/kern/thread_policy.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include timer.d
timer.o: $(SOURCE_DIR)/osfmk/kern/timer.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include timer_call.d
timer_call.o: $(SOURCE_DIR)/osfmk/kern/timer_call.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include wait_queue.d
wait_queue.o: $(SOURCE_DIR)/osfmk/kern/wait_queue.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include zalloc.d
zalloc.o: $(SOURCE_DIR)/osfmk/kern/zalloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include gzalloc.d
gzalloc.o: $(SOURCE_DIR)/osfmk/kern/gzalloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bsd_kern.d
bsd_kern.o: $(SOURCE_DIR)/osfmk/kern/bsd_kern.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hibernate.d
hibernate.o: $(SOURCE_DIR)/osfmk/kern/hibernate.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pmc.d
pmc.o: $(SOURCE_DIR)/osfmk/pmc/pmc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/pmc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/pmc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include clock_server.d
clock_server.o: mach/clock_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include clock_priv_server.d
clock_priv_server.o: mach/clock_priv_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include clock_reply_user.d
clock_reply_user.o: mach/clock_reply_user.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include exc_user.d
exc_user.o: mach/exc_user.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include exc_server.d
exc_server.o: mach/exc_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include host_priv_server.d
host_priv_server.o: mach/host_priv_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include host_security_server.d
host_security_server.o: mach/host_security_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include lock_set_server.d
lock_set_server.o: mach/lock_set_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_exc_user.d
mach_exc_user.o: mach/mach_exc_user.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_exc_server.d
mach_exc_server.o: mach/mach_exc_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_host_server.d
mach_host_server.o: mach/mach_host_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_notify_user.d
mach_notify_user.o: mach/mach_notify_user.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_port_server.d
mach_port_server.o: mach/mach_port_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_vm_server.d
mach_vm_server.o: mach/mach_vm_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memory_object_server.d
memory_object_server.o: mach/memory_object_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memory_object_control_server.d
memory_object_control_server.o: mach/memory_object_control_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memory_object_default_server.d
memory_object_default_server.o: mach/memory_object_default_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memory_object_name_server.d
memory_object_name_server.o: mach/memory_object_name_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include upl_server.d
upl_server.o: mach/upl_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_triggers_user.d
audit_triggers_user.o: mach/audit_triggers_user.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include task_access_user.d
task_access_user.o: mach/task_access_user.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include telemetry_notification_user.d
telemetry_notification_user.o: mach/telemetry_notification_user.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include processor_server.d
processor_server.o: mach/processor_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include processor_set_server.d
processor_set_server.o: mach/processor_set_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include task_server.d
task_server.o: mach/task_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include thread_act_server.d
thread_act_server.o: mach/thread_act_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm32_map_server.d
vm32_map_server.o: mach/vm32_map_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include security_server.d
security_server.o: mach/security_server.c
	${C_RULE_0}
	${C_RULE_1A}mach/${C_RULE_1B}
	${C_CTFRULE_1A}mach/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bsd_vm.d
bsd_vm.o: $(SOURCE_DIR)/osfmk/vm/bsd_vm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_compressor.d
vm_compressor.o: $(SOURCE_DIR)/osfmk/vm/vm_compressor.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_compressor_pager.d
vm_compressor_pager.o: $(SOURCE_DIR)/osfmk/vm/vm_compressor_pager.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include device_vm.d
device_vm.o: $(SOURCE_DIR)/osfmk/vm/device_vm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memory_object.d
memory_object.o: $(SOURCE_DIR)/osfmk/vm/memory_object.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_debug.d
vm_debug.o: $(SOURCE_DIR)/osfmk/vm/vm_debug.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_external.d
vm_external.o: $(SOURCE_DIR)/osfmk/vm/vm_external.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_fault.d
vm_fault.o: $(SOURCE_DIR)/osfmk/vm/vm_fault.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_init.d
vm_init.o: $(SOURCE_DIR)/osfmk/vm/vm_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_kern.d
vm_kern.o: $(SOURCE_DIR)/osfmk/vm/vm_kern.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_map.d
vm_map.o: $(SOURCE_DIR)/osfmk/vm/vm_map.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_map_store.d
vm_map_store.o: $(SOURCE_DIR)/osfmk/vm/vm_map_store.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_map_store_ll.d
vm_map_store_ll.o: $(SOURCE_DIR)/osfmk/vm/vm_map_store_ll.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_map_store_rb.d
vm_map_store_rb.o: $(SOURCE_DIR)/osfmk/vm/vm_map_store_rb.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_object.d
vm_object.o: $(SOURCE_DIR)/osfmk/vm/vm_object.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_pageout.d
vm_pageout.o: $(SOURCE_DIR)/osfmk/vm/vm_pageout.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_purgeable.d
vm_purgeable.o: $(SOURCE_DIR)/osfmk/vm/vm_purgeable.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_resident.d
vm_resident.o: $(SOURCE_DIR)/osfmk/vm/vm_resident.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_shared_region.d
vm_shared_region.o: $(SOURCE_DIR)/osfmk/vm/vm_shared_region.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_swapfile_pager.d
vm_swapfile_pager.o: $(SOURCE_DIR)/osfmk/vm/vm_swapfile_pager.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_user.d
vm_user.o: $(SOURCE_DIR)/osfmk/vm/vm_user.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm32_user.d
vm32_user.o: $(SOURCE_DIR)/osfmk/vm/vm32_user.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include iokit_rpc.d
iokit_rpc.o: $(SOURCE_DIR)/osfmk/device/iokit_rpc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/device/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/device/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include device_server.d
device_server.o: device/device_server.c
	${C_RULE_0}
	${C_RULE_1A}device/${C_RULE_1B}
	${C_CTFRULE_1A}device/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include device_init.d
device_init.o: $(SOURCE_DIR)/osfmk/device/device_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/device/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/device/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kext_alloc.d
kext_alloc.o: $(SOURCE_DIR)/osfmk/kern/kext_alloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kmod.d
kmod.o: $(SOURCE_DIR)/osfmk/kern/kmod.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include subrs.d
subrs.o: $(SOURCE_DIR)/osfmk/device/subrs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/device/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/device/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_cpu.d
chud_cpu.o: $(SOURCE_DIR)/osfmk/chud/chud_cpu.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_glue.d
chud_glue.o: $(SOURCE_DIR)/osfmk/chud/chud_glue.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_memory.d
chud_memory.o: $(SOURCE_DIR)/osfmk/chud/chud_memory.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_osfmk_callback.d
chud_osfmk_callback.o: $(SOURCE_DIR)/osfmk/chud/chud_osfmk_callback.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_thread.d
chud_thread.o: $(SOURCE_DIR)/osfmk/chud/chud_thread.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kperf.d
kperf.o: $(SOURCE_DIR)/osfmk/kperf/kperf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include action.d
action.o: $(SOURCE_DIR)/osfmk/kperf/action.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include callstack.d
callstack.o: $(SOURCE_DIR)/osfmk/kperf/callstack.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pet.d
pet.o: $(SOURCE_DIR)/osfmk/kperf/pet.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include threadinfo.d
threadinfo.o: $(SOURCE_DIR)/osfmk/kperf/threadinfo.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include timetrigger.d
timetrigger.o: $(SOURCE_DIR)/osfmk/kperf/timetrigger.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kperf_kpc.d
kperf_kpc.o: $(SOURCE_DIR)/osfmk/kperf/kperf_kpc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpc_thread.d
kpc_thread.o: $(SOURCE_DIR)/osfmk/kern/kpc_thread.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpc_common.d
kpc_common.o: $(SOURCE_DIR)/osfmk/kern/kpc_common.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include serial_general.d
serial_general.o: $(SOURCE_DIR)/osfmk/console/serial_general.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/console/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/console/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include telemetry.d
telemetry.o: $(SOURCE_DIR)/osfmk/kern/telemetry.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_apple_protect.d
vm_apple_protect.o: $(SOURCE_DIR)/osfmk/vm/vm_apple_protect.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pmap.d
pmap.o: $(SOURCE_DIR)/osfmk/x86_64/pmap.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pmap_x86_common.d
pmap_x86_common.o: $(SOURCE_DIR)/osfmk/i386/pmap_x86_common.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pmap_common.d
pmap_common.o: $(SOURCE_DIR)/osfmk/i386/pmap_common.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pmap_pcid.d
pmap_pcid.o: $(SOURCE_DIR)/osfmk/x86_64/pmap_pcid.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pal_routines.d
pal_routines.o: $(SOURCE_DIR)/osfmk/i386/pal_routines.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pal_routines_asm.d
pal_routines_asm.o: $(SOURCE_DIR)/osfmk/x86_64/pal_routines_asm.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include bsd_i386.d
bsd_i386.o: $(SOURCE_DIR)/osfmk/i386/bsd_i386.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bsd_i386_native.d
bsd_i386_native.o: $(SOURCE_DIR)/osfmk/i386/bsd_i386_native.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include machdep_call.d
machdep_call.o: $(SOURCE_DIR)/osfmk/i386/machdep_call.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include boot_pt.d
boot_pt.o: $(SOURCE_DIR)/osfmk/x86_64/boot_pt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mp_desc.d
mp_desc.o: $(SOURCE_DIR)/osfmk/i386/mp_desc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include gdt.d
gdt.o: $(SOURCE_DIR)/osfmk/i386/gdt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include start.d
start.o: $(SOURCE_DIR)/osfmk/x86_64/start.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include bcopy.d
bcopy.o: $(SOURCE_DIR)/osfmk/x86_64/bcopy.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include bzero.d
bzero.o: $(SOURCE_DIR)/osfmk/x86_64/bzero.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include WKdmDecompress_new.d
WKdmDecompress_new.o: $(SOURCE_DIR)/osfmk/x86_64/WKdmDecompress_new.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include WKdmCompress_new.d
WKdmCompress_new.o: $(SOURCE_DIR)/osfmk/x86_64/WKdmCompress_new.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include WKdmData_new.d
WKdmData_new.o: $(SOURCE_DIR)/osfmk/x86_64/WKdmData_new.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include cpu.d
cpu.o: $(SOURCE_DIR)/osfmk/i386/cpu.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include cpuid.d
cpuid.o: $(SOURCE_DIR)/osfmk/i386/cpuid.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include cpu_threads.d
cpu_threads.o: $(SOURCE_DIR)/osfmk/i386/cpu_threads.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include cpu_topology.d
cpu_topology.o: $(SOURCE_DIR)/osfmk/i386/cpu_topology.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include i386_timer.d
i386_timer.o: $(SOURCE_DIR)/osfmk/i386/i386_timer.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include fpu.d
fpu.o: $(SOURCE_DIR)/osfmk/i386/fpu.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include i386_lock.d
i386_lock.o: $(SOURCE_DIR)/osfmk/i386/i386_lock.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${S_RULE_1B}
	${S_RULE_2}
-include i386_init.d
i386_init.o: $(SOURCE_DIR)/osfmk/i386/i386_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include i386_vm_init.d
i386_vm_init.o: $(SOURCE_DIR)/osfmk/i386/i386_vm_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include io_map.d
io_map.o: $(SOURCE_DIR)/osfmk/i386/io_map.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ktss.d
ktss.o: $(SOURCE_DIR)/osfmk/i386/ktss.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ldt.d
ldt.o: $(SOURCE_DIR)/osfmk/i386/ldt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include loose_ends.d
loose_ends.o: $(SOURCE_DIR)/osfmk/x86_64/loose_ends.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include copyio.d
copyio.o: $(SOURCE_DIR)/osfmk/x86_64/copyio.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include locks_i386.d
locks_i386.o: $(SOURCE_DIR)/osfmk/i386/locks_i386.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include locore.d
locore.o: $(SOURCE_DIR)/osfmk/x86_64/locore.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include lowmem_vectors.d
lowmem_vectors.o: $(SOURCE_DIR)/osfmk/x86_64/lowmem_vectors.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include cswitch.d
cswitch.o: $(SOURCE_DIR)/osfmk/x86_64/cswitch.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include machine_routines.d
machine_routines.o: $(SOURCE_DIR)/osfmk/i386/machine_routines.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include machine_routines_asm.d
machine_routines_asm.o: $(SOURCE_DIR)/osfmk/x86_64/machine_routines_asm.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}
-include machine_check.d
machine_check.o: $(SOURCE_DIR)/osfmk/i386/machine_check.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include machine_task.d
machine_task.o: $(SOURCE_DIR)/osfmk/i386/machine_task.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pcb.d
pcb.o: $(SOURCE_DIR)/osfmk/i386/pcb.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pcb_native.d
pcb_native.o: $(SOURCE_DIR)/osfmk/i386/pcb_native.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include phys.d
phys.o: $(SOURCE_DIR)/osfmk/i386/phys.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include rtclock.d
rtclock.o: $(SOURCE_DIR)/osfmk/i386/rtclock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include rtclock_native.d
rtclock_native.o: $(SOURCE_DIR)/osfmk/i386/rtclock_native.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include trap.d
trap.o: $(SOURCE_DIR)/osfmk/i386/trap.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include trap_native.d
trap_native.o: $(SOURCE_DIR)/osfmk/i386/trap_native.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include user_ldt.d
user_ldt.o: $(SOURCE_DIR)/osfmk/i386/user_ldt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include Diagnostics.d
Diagnostics.o: $(SOURCE_DIR)/osfmk/i386/Diagnostics.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pmCPU.d
pmCPU.o: $(SOURCE_DIR)/osfmk/i386/pmCPU.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tsc.d
tsc.o: $(SOURCE_DIR)/osfmk/i386/tsc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include commpage.d
commpage.o: $(SOURCE_DIR)/osfmk/i386/commpage/commpage.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/commpage/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/commpage/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include commpage_asm.d
commpage_asm.o: $(SOURCE_DIR)/osfmk/i386/commpage/commpage_asm.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/i386/commpage/${S_RULE_1B}
	${S_RULE_2}
-include fifo_queues.d
fifo_queues.o: $(SOURCE_DIR)/osfmk/i386/commpage/fifo_queues.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/i386/commpage/${S_RULE_1B}
	${S_RULE_2}
-include conf.d
conf.o: $(SOURCE_DIR)/osfmk/i386/AT386/conf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/AT386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/AT386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include model_dep.d
model_dep.o: $(SOURCE_DIR)/osfmk/i386/AT386/model_dep.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/AT386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/AT386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include lapic.d
lapic.o: $(SOURCE_DIR)/osfmk/i386/lapic.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include lapic_native.d
lapic_native.o: $(SOURCE_DIR)/osfmk/i386/lapic_native.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mp.d
mp.o: $(SOURCE_DIR)/osfmk/i386/mp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mp_native.d
mp_native.o: $(SOURCE_DIR)/osfmk/i386/mp_native.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include acpi.d
acpi.o: $(SOURCE_DIR)/osfmk/i386/acpi.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mtrr.d
mtrr.o: $(SOURCE_DIR)/osfmk/i386/mtrr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include serial_console.d
serial_console.o: $(SOURCE_DIR)/osfmk/console/i386/serial_console.c
	${C_RULE_0_D}
	${C_RULE_1A_D}$(SOURCE_DIR)/osfmk/console/i386/${C_RULE_1B_D}
	${C_CTFRULE_1A_D}$(SOURCE_DIR)/osfmk/console/i386/${C_CTFRULE_1B_D}
	${C_RULE_2_D}
	${C_CTFRULE_2_D}
-include video_console.d
video_console.o: $(SOURCE_DIR)/osfmk/console/video_console.c
	${C_RULE_0_D}
	${C_RULE_1A_D}$(SOURCE_DIR)/osfmk/console/${C_RULE_1B_D}
	${C_CTFRULE_1A_D}$(SOURCE_DIR)/osfmk/console/${C_CTFRULE_1B_D}
	${C_RULE_2_D}
	${C_CTFRULE_2_D}
-include video_scroll.d
video_scroll.o: $(SOURCE_DIR)/osfmk/console/i386/video_scroll.c
	${C_RULE_0_D}
	${C_RULE_1A_D}$(SOURCE_DIR)/osfmk/console/i386/${C_RULE_1B_D}
	${C_CTFRULE_1A_D}$(SOURCE_DIR)/osfmk/console/i386/${C_CTFRULE_1B_D}
	${C_RULE_2_D}
	${C_CTFRULE_2_D}
-include kdp_machdep.d
kdp_machdep.o: $(SOURCE_DIR)/osfmk/kdp/ml/x86_64/kdp_machdep.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kdp/ml/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kdp/ml/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kdp_vm.d
kdp_vm.o: $(SOURCE_DIR)/osfmk/kdp/ml/x86_64/kdp_vm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kdp/ml/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kdp/ml/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kdp_x86_common.d
kdp_x86_common.o: $(SOURCE_DIR)/osfmk/kdp/ml/i386/kdp_x86_common.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kdp/ml/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kdp/ml/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hibernate_i386.d
hibernate_i386.o: $(SOURCE_DIR)/osfmk/i386/hibernate_i386.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hibernate_restore.d
hibernate_restore.o: $(SOURCE_DIR)/osfmk/i386/hibernate_restore.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_osfmk_callback_i386.d
chud_osfmk_callback_i386.o: $(SOURCE_DIR)/osfmk/chud/i386/chud_osfmk_callback_i386.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_cpu_i386.d
chud_cpu_i386.o: $(SOURCE_DIR)/osfmk/chud/i386/chud_cpu_i386.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_thread_i386.d
chud_thread_i386.o: $(SOURCE_DIR)/osfmk/chud/i386/chud_thread_i386.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/chud/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/chud/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ucode.d
ucode.o: $(SOURCE_DIR)/osfmk/i386/ucode.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vmx_cpu.d
vmx_cpu.o: $(SOURCE_DIR)/osfmk/i386/vmx/vmx_cpu.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/vmx/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/vmx/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vmx_shims.d
vmx_shims.o: $(SOURCE_DIR)/osfmk/i386/vmx/vmx_shims.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/vmx/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/vmx/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kperf_mp.d
kperf_mp.o: $(SOURCE_DIR)/osfmk/kperf/x86_64/kperf_mp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpc_x86.d
kpc_x86.o: $(SOURCE_DIR)/osfmk/x86_64/kpc_x86.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include startup64.d
startup64.o: $(SOURCE_DIR)/osfmk/i386/startup64.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include idt64.d
idt64.o: $(SOURCE_DIR)/osfmk/x86_64/idt64.s
	${S_RULE_0}
	${S_RULE_1A}$(SOURCE_DIR)/osfmk/x86_64/${S_RULE_1B}
	${S_RULE_2}

include $(MakeInc_rule)
include $(MakeInc_dir)
