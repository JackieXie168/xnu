SOURCE_DIR=/Users/admin/Code/xnu/xnu-2422.115.4
export IDENT=-DNEXT -DTIMEZONE="0" -DPST="0" -DCONFIG_LCTX -DMACH -DCONFIG_ZLEAKS -DNO_DIRECT_RPC -DIPFIREWALL_FORWARD -DIPFIREWALL_DEFAULT_TO_ACCEPT -DTRAFFIC_MGT -DMULTICAST -DTCP_DROP_SYNFIN -DICMP_BANDLIM -DIFNET_INPUT_SANITY_CHK -DPSYNCH -DFLOW_DIVERT -DOLD_SEMWAIT_SIGNAL -DCONFIG_MBUF_JUMBO -DCONFIG_WORKQUEUE -DCONFIG_HFS_STD -DCONFIG_HFS_TRIM -DCONFIG_HFS_DIRLINK -DQUOTA -DNAMEDSTREAMS -DCONFIG_APPLEDOUBLE -DCONFIG_VOLFS -DCONFIG_IMGSRC_ACCESS -DCONFIG_TRIGGERS -DCONFIG_EXT_RESOLVER -DCONFIG_SEARCHFS -DIPSEC -DIPSEC_ESP -DIPV6FIREWALL_DEFAULT_TO_ACCEPT -Dcrypto -DCONFIG_KN_HASHSIZE="64" -DCONFIG_VNODES="263168" -DCONFIG_VNODE_FREE_MIN="300" -DCONFIG_NC_HASH="4096" -DCONFIG_VFS_NAMES="4096" -DCONFIG_MAX_CLUSTERS="8" -DKAUTH_CRED_PRIMES_COUNT="7" -DKAUTH_CRED_PRIMES="{97, 241, 397, 743, 1499, 3989, 7499}" -DCONFIG_MIN_NBUF="256" -DCONFIG_MIN_NIOBUF="128" -DCONFIG_NMBCLUSTERS="((1024 * 512) / MCLBYTES)" -DCONFIG_TCBHASHSIZE="4096" -DCONFIG_ICMP_BANDLIM="250" -DCONFIG_AIO_MAX="90" -DCONFIG_AIO_PROCESS_MAX="16" -DCONFIG_AIO_THREAD_COUNT="4" -DCONFIG_THREAD_MAX="2560" -DCONFIG_MAXVIFS="32" -DCONFIG_MFCTBLSIZ="256" -DCONFIG_MSG_BSIZE="16384" -DCONFIG_FINE_LOCK_GROUPS -DCONFIG_DYNAMIC_CODE_SIGNING -DCONFIG_MEMORYSTATUS -DVM_PRESSURE_EVENTS -DCONFIG_TELEMETRY -DCONFIG_PROC_UUID_POLICY -DCONFIG_APP_PROFILE="0" -DKPERF -DKPC -DCONFIG_CODE_DECRYPTION
LIBDRIVER=libDriver_kern.o
LIBOBJC=libkobjc.o
CCONFIGFLAGS=-g -O3 -fno-omit-frame-pointer
RELOC=00100000
SYMADDR=00780000
#
# Copyright (c) 2000-2011 Apple Inc. All rights reserved.
#
# @APPLE_LICENSE_HEADER_START@
# 
# The contents of this file constitute Original Code as defined in and
# are subject to the Apple Public Source License Version 1.1 (the
# "License").  You may not use this file except in compliance with the
# License.  Please obtain a copy of the License at
# http://www.apple.com/publicsource and read it before using this file.
# 
# This Original Code and all software distributed under the License are
# distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
# EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
# INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
# License for the specific language governing rights and limitations
# under the License.
# 
# @APPLE_LICENSE_HEADER_END@
#

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
CFLAGS+= -include meta_features.h -DDRIVER_PRIVATE \
	-D_KERNEL_BUILD -DKERNEL_BUILD -DMACH_KERNEL -DBSD_BUILD \
	-DBSD_KERNEL_PRIVATE -DLP64_DEBUG=0

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

OBJS=nfs4_subs.o nfs4_vnops.o krpc_subr.o nfs_bio.o nfs_boot.o nfs_gss.o \
	nfs_gss_crypto.o nfs_lock.o nfs_node.o nfs_serv.o nfs_socket.o \
	nfs_srvcache.o nfs_subs.o nfs_syscalls.o nfs_vfsops.o \
	nfs_vnops.o nfs_upcall.o netboot.o dtrace.o lockstat.o \
	dtrace_ptss.o dtrace_subr.o dtrace_glue.o dtrace_alloc.o blist.o \
	fbt.o sdt.o sdt_subr.o systrace.o profile_prvd.o fasttrap.o \
	randomdev.o fips_sha1.o smf.o comp.o prng.o sha1mod.o \
	yarrowUtils.o memdev.o munge.o unix_startup.o vn.o shadow.o \
	crc32.o random.o scanc.o skpc.o strsep.o bcd.o memchr.o \
	vfs_attrlist.o vfs_bio.o vfs_cache.o vfs_cluster.o vfs_conf.o \
	vfs_fslog.o vfs_init.o vfs_lookup.o vfs_quota.o vfs_subr.o \
	vfs_syscalls.o vfs_support.o vfs_utfconv.o vfs_vnops.o \
	vfs_xattr.o vnode_if.o kpi_vfs.o vfs_journal.o vfs_fsevents.o \
	dead_vnops.o devfs_fdesc_support.o fifo_vnops.o spec_vnops.o \
	devfs_tree.o devfs_vnops.o devfs_vfsops.o decmpfs.o net_stubs.o \
	bpf.o bpf_filter.o if_bridge.o if.o init.o dlil.o \
	ether_if_module.o ether_inet_pr_module.o ether_inet6_pr_module.o \
	if_loop.o if_mib.o if_vlan.o multicast_list.o if_bond.o \
	devtimer.o ndrv.o radix.o raw_cb.o raw_usrreq.o route.o rtsock.o \
	netsrc.o ntstat.o if_gif.o if_stf.o kpi_interface.o \
	kpi_protocol.o kpi_interfacefilter.o net_str_id.o if_utun.o \
	if_utun_crypto.o if_utun_crypto_dtls.o if_utun_crypto_ipsec.o \
	if_ipsec.o if_pflog.o pf.o pf_if.o pf_ioctl.o pf_norm.o \
	pf_osfp.o pf_ruleset.o pf_table.o iptap.o pktap.o if_llreach.o \
	flowhash.o flowadv.o classq.o classq_sfb.o classq_subr.o \
	classq_util.o pktsched.o pktsched_qfq.o pktsched_tcq.o igmp.o \
	in.o in_dhcp.o dhcp_options.o in_arp.o in_mcast.o in_pcb.o \
	in_pcblist.o in_proto.o in_rmx.o in_tclass.o ip_divert.o \
	ip_dummynet.o ip_fw2.o ip_fw2_compat.o ip_icmp.o ip_id.o \
	ip_input.o ip_output.o raw_ip.o tcp_input.o tcp_output.o \
	tcp_sack.o tcp_subr.o tcp_timer.o tcp_usrreq.o tcp_newreno.o \
	tcp_lro.o tcp_ledbat.o udp_usrreq.o in_gif.o ip_ecn.o ip_encap.o \
	kpi_ipfilter.o flow_divert.o ah_core.o ah_input.o ah_output.o \
	esp_core.o esp_input.o esp_output.o esp_rijndael.o ipsec.o \
	dest6.o frag6.o icmp6.o in6.o in6_cga.o in6_cksum.o in6_gif.o \
	ip6_fw.o ip6_forward.o in6_ifattach.o ip6_input.o ip6_output.o \
	in6_src.o ipcomp_core.o ipcomp_input.o ipcomp_output.o \
	in6_mcast.o in6_pcb.o in6_proto.o in6_rmx.o mld6.o nd6.o \
	nd6_nbr.o nd6_prproxy.o nd6_rtr.o nd6_send.o raw_ip6.o route6.o \
	scope6.o udp6_output.o udp6_usrreq.o ip6_id.o key.o key_debug.o \
	keysock.o keydb.o bf_enc.o bf_skey.o cast128.o rc4.o \
	hfs_attrlist.o hfs_btreeio.o hfs_catalog.o hfs_chash.o \
	hfs_cnode.o hfs_encodinghint.o hfs_encodings.o hfs_endian.o \
	hfs_hotfiles.o hfs_link.o hfs_lookup.o hfs_notification.o \
	hfs_quota.o hfs_readwrite.o hfs_search.o hfs_vfsops.o \
	hfs_vfsutils.o hfs_vnops.o hfs_xattr.o MacOSStubs.o \
	hfs_cprotect.o rangelist.o BTree.o BTreeAllocate.o \
	BTreeMiscOps.o BTreeNodeOps.o BTreeNodeReserve.o BTreeScanner.o \
	BTreeTreeOps.o CatalogUtilities.o FileIDsServices.o \
	BTreeWrapper.o FileExtentMapping.o VolumeAllocation.o \
	UnicodeWrappers.o audit.o audit_arg.o audit_bsd.o audit_bsm.o \
	audit_bsm_errno.o audit_bsm_fcntl.o audit_bsm_domain.o \
	audit_bsm_klib.o audit_bsm_socket_type.o audit_bsm_token.o \
	audit_kevents.o audit_mac.o audit_pipe.o audit_session.o \
	audit_syscalls.o audit_worker.o bsd_init.o init_sysent.o \
	kdebug.o kern_acct.o kern_aio.o kern_authorization.o \
	kern_clock.o kern_core.o kern_credential.o kern_cs.o \
	kern_symfile.o kern_descrip.o kern_guarded.o kern_event.o \
	kern_control.o kern_exec.o kern_exit.o kern_lockf.o kern_fork.o \
	kern_asl.o kern_malloc.o kern_mman.o kern_physio.o kern_priv.o \
	kern_proc.o kern_prot.o kern_resource.o kern_shutdown.o \
	kern_sig.o kern_subr.o kern_synch.o kern_sysctl.o \
	kern_newsysctl.o kern_memorystatus.o kern_mib.o kpi_mbuf.o \
	kern_time.o kern_xxx.o mach_process.o mcache.o spl.o subr_log.o \
	subr_prf.o subr_prof.o subr_sbuf.o subr_xxx.o sys_generic.o \
	sys_pipe.o sys_socket.o sys_domain.o syscalls.o tty.o \
	tty_compat.o tty_conf.o tty_pty.o tty_ptmx.o tty_subr.o \
	tty_tty.o ubc_subr.o uipc_domain.o uipc_mbuf.o uipc_mbuf2.o \
	uipc_proto.o uipc_socket.o uipc_socket2.o uipc_syscalls.o \
	uipc_usrreq.o sysv_ipc.o sysv_shm.o sysv_sem.o sysv_msg.o \
	mach_fat.o mach_loader.o posix_sem.o posix_shm.o qsort.o \
	kpi_socket.o kpi_socketfilter.o pthread_shims.o proc_info.o \
	process_policy.o kern_overrides.o vm_pressure.o socket_info.o \
	vnode_pager.o vm_unix.o dp_backing_file.o \
	vm_compressor_backing_file.o ux_exception.o param.o ioconf.o \
	chud_bsd_callback.o chud_process.o imageboot.o kperfbsd.o \
	kern_kpc.o proc_uuid_policy.o conf.o cons.o mem.o km.o \
	kern_machdep.o memmove.o stubs.o systemcalls.o sysctl.o \
	unix_signal.o dtrace_isa.o dtrace_subr_x86.o fbt_x86.o sdt_x86.o \
	fasttrap_isa.o instr_size.o dis_tables.o policy_check.o \
	bsd_stubs.o cpu_in_cksum.o in_cksum.o 

CFILES=\
	$(SOURCE_DIR)/bsd/nfs/nfs4_subs.c \
	$(SOURCE_DIR)/bsd/nfs/nfs4_vnops.c \
	$(SOURCE_DIR)/bsd/nfs/krpc_subr.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_bio.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_boot.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_gss.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_gss_crypto.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_lock.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_node.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_serv.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_socket.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_srvcache.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_subs.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_syscalls.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_vfsops.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_vnops.c \
	$(SOURCE_DIR)/bsd/nfs/nfs_upcall.c \
	$(SOURCE_DIR)/bsd/kern/netboot.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/dtrace.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/lockstat.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/dtrace_ptss.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/dtrace_subr.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/dtrace_glue.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/dtrace_alloc.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/blist.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/fbt.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/sdt.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/sdt_subr.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/systrace.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/profile_prvd.c \
	$(SOURCE_DIR)/bsd/dev/dtrace/fasttrap.c \
	$(SOURCE_DIR)/bsd/dev/random/randomdev.c \
	$(SOURCE_DIR)/bsd/dev/random/fips_sha1.c \
	$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/port/smf.c \
	$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/comp.c \
	$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/prng.c \
	$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/sha1mod.c \
	$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/yarrowUtils.c \
	$(SOURCE_DIR)/bsd/dev/memdev.c \
	$(SOURCE_DIR)/bsd/dev/munge.c \
	$(SOURCE_DIR)/bsd/dev/unix_startup.c \
	$(SOURCE_DIR)/bsd/dev/vn/vn.c \
	$(SOURCE_DIR)/bsd/dev/vn/shadow.c \
	$(SOURCE_DIR)/bsd/libkern/crc32.c \
	$(SOURCE_DIR)/bsd/libkern/random.c \
	$(SOURCE_DIR)/bsd/libkern/scanc.c \
	$(SOURCE_DIR)/bsd/libkern/skpc.c \
	$(SOURCE_DIR)/bsd/libkern/strsep.c \
	$(SOURCE_DIR)/bsd/libkern/bcd.c \
	$(SOURCE_DIR)/bsd/libkern/memchr.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_attrlist.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_bio.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_cache.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_cluster.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_conf.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_fslog.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_init.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_lookup.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_quota.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_subr.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_syscalls.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_support.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_utfconv.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_vnops.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_xattr.c \
	$(SOURCE_DIR)/bsd/vfs/vnode_if.c \
	$(SOURCE_DIR)/bsd/vfs/kpi_vfs.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_journal.c \
	$(SOURCE_DIR)/bsd/vfs/vfs_fsevents.c \
	$(SOURCE_DIR)/bsd/miscfs/deadfs/dead_vnops.c \
	$(SOURCE_DIR)/bsd/miscfs/devfs/devfs_fdesc_support.c \
	$(SOURCE_DIR)/bsd/miscfs/fifofs/fifo_vnops.c \
	$(SOURCE_DIR)/bsd/miscfs/specfs/spec_vnops.c \
	$(SOURCE_DIR)/bsd/miscfs/devfs/devfs_tree.c \
	$(SOURCE_DIR)/bsd/miscfs/devfs/devfs_vnops.c \
	$(SOURCE_DIR)/bsd/miscfs/devfs/devfs_vfsops.c \
	$(SOURCE_DIR)/bsd/kern/decmpfs.c \
	$(SOURCE_DIR)/bsd/net/net_stubs.c \
	$(SOURCE_DIR)/bsd/net/bpf.c \
	$(SOURCE_DIR)/bsd/net/bpf_filter.c \
	$(SOURCE_DIR)/bsd/net/if_bridge.c \
	$(SOURCE_DIR)/bsd/net/if.c \
	$(SOURCE_DIR)/bsd/net/init.c \
	$(SOURCE_DIR)/bsd/net/dlil.c \
	$(SOURCE_DIR)/bsd/net/ether_if_module.c \
	$(SOURCE_DIR)/bsd/net/ether_inet_pr_module.c \
	$(SOURCE_DIR)/bsd/net/ether_inet6_pr_module.c \
	$(SOURCE_DIR)/bsd/net/if_loop.c \
	$(SOURCE_DIR)/bsd/net/if_mib.c \
	$(SOURCE_DIR)/bsd/net/if_vlan.c \
	$(SOURCE_DIR)/bsd/net/multicast_list.c \
	$(SOURCE_DIR)/bsd/net/if_bond.c \
	$(SOURCE_DIR)/bsd/net/devtimer.c \
	$(SOURCE_DIR)/bsd/net/ndrv.c \
	$(SOURCE_DIR)/bsd/net/radix.c \
	$(SOURCE_DIR)/bsd/net/raw_cb.c \
	$(SOURCE_DIR)/bsd/net/raw_usrreq.c \
	$(SOURCE_DIR)/bsd/net/route.c \
	$(SOURCE_DIR)/bsd/net/rtsock.c \
	$(SOURCE_DIR)/bsd/net/netsrc.c \
	$(SOURCE_DIR)/bsd/net/ntstat.c \
	$(SOURCE_DIR)/bsd/net/if_gif.c \
	$(SOURCE_DIR)/bsd/net/if_stf.c \
	$(SOURCE_DIR)/bsd/net/kpi_interface.c \
	$(SOURCE_DIR)/bsd/net/kpi_protocol.c \
	$(SOURCE_DIR)/bsd/net/kpi_interfacefilter.c \
	$(SOURCE_DIR)/bsd/net/net_str_id.c \
	$(SOURCE_DIR)/bsd/net/if_utun.c \
	$(SOURCE_DIR)/bsd/net/if_utun_crypto.c \
	$(SOURCE_DIR)/bsd/net/if_utun_crypto_dtls.c \
	$(SOURCE_DIR)/bsd/net/if_utun_crypto_ipsec.c \
	$(SOURCE_DIR)/bsd/net/if_ipsec.c \
	$(SOURCE_DIR)/bsd/net/if_pflog.c \
	$(SOURCE_DIR)/bsd/net/pf.c \
	$(SOURCE_DIR)/bsd/net/pf_if.c \
	$(SOURCE_DIR)/bsd/net/pf_ioctl.c \
	$(SOURCE_DIR)/bsd/net/pf_norm.c \
	$(SOURCE_DIR)/bsd/net/pf_osfp.c \
	$(SOURCE_DIR)/bsd/net/pf_ruleset.c \
	$(SOURCE_DIR)/bsd/net/pf_table.c \
	$(SOURCE_DIR)/bsd/net/iptap.c \
	$(SOURCE_DIR)/bsd/net/pktap.c \
	$(SOURCE_DIR)/bsd/net/if_llreach.c \
	$(SOURCE_DIR)/bsd/net/flowhash.c \
	$(SOURCE_DIR)/bsd/net/flowadv.c \
	$(SOURCE_DIR)/bsd/net/classq/classq.c \
	$(SOURCE_DIR)/bsd/net/classq/classq_sfb.c \
	$(SOURCE_DIR)/bsd/net/classq/classq_subr.c \
	$(SOURCE_DIR)/bsd/net/classq/classq_util.c \
	$(SOURCE_DIR)/bsd/net/pktsched/pktsched.c \
	$(SOURCE_DIR)/bsd/net/pktsched/pktsched_qfq.c \
	$(SOURCE_DIR)/bsd/net/pktsched/pktsched_tcq.c \
	$(SOURCE_DIR)/bsd/netinet/igmp.c \
	$(SOURCE_DIR)/bsd/netinet/in.c \
	$(SOURCE_DIR)/bsd/netinet/in_dhcp.c \
	$(SOURCE_DIR)/bsd/netinet/dhcp_options.c \
	$(SOURCE_DIR)/bsd/netinet/in_arp.c \
	$(SOURCE_DIR)/bsd/netinet/in_mcast.c \
	$(SOURCE_DIR)/bsd/netinet/in_pcb.c \
	$(SOURCE_DIR)/bsd/netinet/in_pcblist.c \
	$(SOURCE_DIR)/bsd/netinet/in_proto.c \
	$(SOURCE_DIR)/bsd/netinet/in_rmx.c \
	$(SOURCE_DIR)/bsd/netinet/in_tclass.c \
	$(SOURCE_DIR)/bsd/netinet/ip_divert.c \
	$(SOURCE_DIR)/bsd/netinet/ip_dummynet.c \
	$(SOURCE_DIR)/bsd/netinet/ip_fw2.c \
	$(SOURCE_DIR)/bsd/netinet/ip_fw2_compat.c \
	$(SOURCE_DIR)/bsd/netinet/ip_icmp.c \
	$(SOURCE_DIR)/bsd/netinet/ip_id.c \
	$(SOURCE_DIR)/bsd/netinet/ip_input.c \
	$(SOURCE_DIR)/bsd/netinet/ip_output.c \
	$(SOURCE_DIR)/bsd/netinet/raw_ip.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_input.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_output.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_sack.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_subr.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_timer.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_usrreq.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_newreno.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_lro.c \
	$(SOURCE_DIR)/bsd/netinet/tcp_ledbat.c \
	$(SOURCE_DIR)/bsd/netinet/udp_usrreq.c \
	$(SOURCE_DIR)/bsd/netinet/in_gif.c \
	$(SOURCE_DIR)/bsd/netinet/ip_ecn.c \
	$(SOURCE_DIR)/bsd/netinet/ip_encap.c \
	$(SOURCE_DIR)/bsd/netinet/kpi_ipfilter.c \
	$(SOURCE_DIR)/bsd/netinet/flow_divert.c \
	$(SOURCE_DIR)/bsd/netinet6/ah_core.c \
	$(SOURCE_DIR)/bsd/netinet6/ah_input.c \
	$(SOURCE_DIR)/bsd/netinet6/ah_output.c \
	$(SOURCE_DIR)/bsd/netinet6/esp_core.c \
	$(SOURCE_DIR)/bsd/netinet6/esp_input.c \
	$(SOURCE_DIR)/bsd/netinet6/esp_output.c \
	$(SOURCE_DIR)/bsd/netinet6/esp_rijndael.c \
	$(SOURCE_DIR)/bsd/netinet6/ipsec.c \
	$(SOURCE_DIR)/bsd/netinet6/dest6.c \
	$(SOURCE_DIR)/bsd/netinet6/frag6.c \
	$(SOURCE_DIR)/bsd/netinet6/icmp6.c \
	$(SOURCE_DIR)/bsd/netinet6/in6.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_cga.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_cksum.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_gif.c \
	$(SOURCE_DIR)/bsd/netinet6/ip6_fw.c \
	$(SOURCE_DIR)/bsd/netinet6/ip6_forward.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_ifattach.c \
	$(SOURCE_DIR)/bsd/netinet6/ip6_input.c \
	$(SOURCE_DIR)/bsd/netinet6/ip6_output.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_src.c \
	$(SOURCE_DIR)/bsd/netinet6/ipcomp_core.c \
	$(SOURCE_DIR)/bsd/netinet6/ipcomp_input.c \
	$(SOURCE_DIR)/bsd/netinet6/ipcomp_output.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_mcast.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_pcb.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_proto.c \
	$(SOURCE_DIR)/bsd/netinet6/in6_rmx.c \
	$(SOURCE_DIR)/bsd/netinet6/mld6.c \
	$(SOURCE_DIR)/bsd/netinet6/nd6.c \
	$(SOURCE_DIR)/bsd/netinet6/nd6_nbr.c \
	$(SOURCE_DIR)/bsd/netinet6/nd6_prproxy.c \
	$(SOURCE_DIR)/bsd/netinet6/nd6_rtr.c \
	$(SOURCE_DIR)/bsd/netinet6/nd6_send.c \
	$(SOURCE_DIR)/bsd/netinet6/raw_ip6.c \
	$(SOURCE_DIR)/bsd/netinet6/route6.c \
	$(SOURCE_DIR)/bsd/netinet6/scope6.c \
	$(SOURCE_DIR)/bsd/netinet6/udp6_output.c \
	$(SOURCE_DIR)/bsd/netinet6/udp6_usrreq.c \
	$(SOURCE_DIR)/bsd/netinet6/ip6_id.c \
	$(SOURCE_DIR)/bsd/netkey/key.c \
	$(SOURCE_DIR)/bsd/netkey/key_debug.c \
	$(SOURCE_DIR)/bsd/netkey/keysock.c \
	$(SOURCE_DIR)/bsd/netkey/keydb.c \
	$(SOURCE_DIR)/bsd/crypto/blowfish/bf_enc.c \
	$(SOURCE_DIR)/bsd/crypto/blowfish/bf_skey.c \
	$(SOURCE_DIR)/bsd/crypto/cast128/cast128.c \
	$(SOURCE_DIR)/bsd/crypto/rc4/rc4.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_attrlist.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_btreeio.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_catalog.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_chash.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_cnode.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_encodinghint.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_encodings.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_endian.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_hotfiles.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_link.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_lookup.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_notification.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_quota.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_readwrite.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_search.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_vfsops.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_vfsutils.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_vnops.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_xattr.c \
	$(SOURCE_DIR)/bsd/hfs/MacOSStubs.c \
	$(SOURCE_DIR)/bsd/hfs/hfs_cprotect.c \
	$(SOURCE_DIR)/bsd/hfs/rangelist.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTree.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeAllocate.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeMiscOps.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeNodeOps.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeNodeReserve.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeScanner.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeTreeOps.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/CatalogUtilities.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/FileIDsServices.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/BTreeWrapper.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/FileExtentMapping.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/VolumeAllocation.c \
	$(SOURCE_DIR)/bsd/hfs/hfscommon/Unicode/UnicodeWrappers.c \
	$(SOURCE_DIR)/bsd/security/audit/audit.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_arg.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsd.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsm.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsm_errno.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsm_fcntl.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsm_domain.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsm_klib.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsm_socket_type.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_bsm_token.c \
	./audit_kevents.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_mac.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_pipe.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_session.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_syscalls.c \
	$(SOURCE_DIR)/bsd/security/audit/audit_worker.c \
	$(SOURCE_DIR)/bsd/kern/bsd_init.c \
	./init_sysent.c \
	$(SOURCE_DIR)/bsd/kern/kdebug.c \
	$(SOURCE_DIR)/bsd/kern/kern_acct.c \
	$(SOURCE_DIR)/bsd/kern/kern_aio.c \
	$(SOURCE_DIR)/bsd/kern/kern_authorization.c \
	$(SOURCE_DIR)/bsd/kern/kern_clock.c \
	$(SOURCE_DIR)/bsd/kern/kern_core.c \
	$(SOURCE_DIR)/bsd/kern/kern_credential.c \
	$(SOURCE_DIR)/bsd/kern/kern_cs.c \
	$(SOURCE_DIR)/bsd/kern/kern_symfile.c \
	$(SOURCE_DIR)/bsd/kern/kern_descrip.c \
	$(SOURCE_DIR)/bsd/kern/kern_guarded.c \
	$(SOURCE_DIR)/bsd/kern/kern_event.c \
	$(SOURCE_DIR)/bsd/kern/kern_control.c \
	$(SOURCE_DIR)/bsd/kern/kern_exec.c \
	$(SOURCE_DIR)/bsd/kern/kern_exit.c \
	$(SOURCE_DIR)/bsd/kern/kern_lockf.c \
	$(SOURCE_DIR)/bsd/kern/kern_fork.c \
	$(SOURCE_DIR)/bsd/kern/kern_asl.c \
	$(SOURCE_DIR)/bsd/kern/kern_malloc.c \
	$(SOURCE_DIR)/bsd/kern/kern_mman.c \
	$(SOURCE_DIR)/bsd/kern/kern_physio.c \
	$(SOURCE_DIR)/bsd/kern/kern_priv.c \
	$(SOURCE_DIR)/bsd/kern/kern_proc.c \
	$(SOURCE_DIR)/bsd/kern/kern_prot.c \
	$(SOURCE_DIR)/bsd/kern/kern_resource.c \
	$(SOURCE_DIR)/bsd/kern/kern_shutdown.c \
	$(SOURCE_DIR)/bsd/kern/kern_sig.c \
	$(SOURCE_DIR)/bsd/kern/kern_subr.c \
	$(SOURCE_DIR)/bsd/kern/kern_synch.c \
	$(SOURCE_DIR)/bsd/kern/kern_sysctl.c \
	$(SOURCE_DIR)/bsd/kern/kern_newsysctl.c \
	$(SOURCE_DIR)/bsd/kern/kern_memorystatus.c \
	$(SOURCE_DIR)/bsd/kern/kern_mib.c \
	$(SOURCE_DIR)/bsd/kern/kpi_mbuf.c \
	$(SOURCE_DIR)/bsd/kern/kern_time.c \
	$(SOURCE_DIR)/bsd/kern/kern_xxx.c \
	$(SOURCE_DIR)/bsd/kern/mach_process.c \
	$(SOURCE_DIR)/bsd/kern/mcache.c \
	$(SOURCE_DIR)/bsd/kern/spl.c \
	$(SOURCE_DIR)/bsd/kern/subr_log.c \
	$(SOURCE_DIR)/bsd/kern/subr_prf.c \
	$(SOURCE_DIR)/bsd/kern/subr_prof.c \
	$(SOURCE_DIR)/bsd/kern/subr_sbuf.c \
	$(SOURCE_DIR)/bsd/kern/subr_xxx.c \
	$(SOURCE_DIR)/bsd/kern/sys_generic.c \
	$(SOURCE_DIR)/bsd/kern/sys_pipe.c \
	$(SOURCE_DIR)/bsd/kern/sys_socket.c \
	$(SOURCE_DIR)/bsd/kern/sys_domain.c \
	./syscalls.c \
	$(SOURCE_DIR)/bsd/kern/tty.c \
	$(SOURCE_DIR)/bsd/kern/tty_compat.c \
	$(SOURCE_DIR)/bsd/kern/tty_conf.c \
	$(SOURCE_DIR)/bsd/kern/tty_pty.c \
	$(SOURCE_DIR)/bsd/kern/tty_ptmx.c \
	$(SOURCE_DIR)/bsd/kern/tty_subr.c \
	$(SOURCE_DIR)/bsd/kern/tty_tty.c \
	$(SOURCE_DIR)/bsd/kern/ubc_subr.c \
	$(SOURCE_DIR)/bsd/kern/uipc_domain.c \
	$(SOURCE_DIR)/bsd/kern/uipc_mbuf.c \
	$(SOURCE_DIR)/bsd/kern/uipc_mbuf2.c \
	$(SOURCE_DIR)/bsd/kern/uipc_proto.c \
	$(SOURCE_DIR)/bsd/kern/uipc_socket.c \
	$(SOURCE_DIR)/bsd/kern/uipc_socket2.c \
	$(SOURCE_DIR)/bsd/kern/uipc_syscalls.c \
	$(SOURCE_DIR)/bsd/kern/uipc_usrreq.c \
	$(SOURCE_DIR)/bsd/kern/sysv_ipc.c \
	$(SOURCE_DIR)/bsd/kern/sysv_shm.c \
	$(SOURCE_DIR)/bsd/kern/sysv_sem.c \
	$(SOURCE_DIR)/bsd/kern/sysv_msg.c \
	$(SOURCE_DIR)/bsd/kern/mach_fat.c \
	$(SOURCE_DIR)/bsd/kern/mach_loader.c \
	$(SOURCE_DIR)/bsd/kern/posix_sem.c \
	$(SOURCE_DIR)/bsd/kern/posix_shm.c \
	$(SOURCE_DIR)/bsd/kern/qsort.c \
	$(SOURCE_DIR)/bsd/kern/kpi_socket.c \
	$(SOURCE_DIR)/bsd/kern/kpi_socketfilter.c \
	$(SOURCE_DIR)/bsd/kern/pthread_shims.c \
	$(SOURCE_DIR)/bsd/kern/proc_info.c \
	$(SOURCE_DIR)/bsd/kern/process_policy.c \
	$(SOURCE_DIR)/bsd/kern/kern_overrides.c \
	$(SOURCE_DIR)/bsd/kern/vm_pressure.c \
	$(SOURCE_DIR)/bsd/kern/socket_info.c \
	$(SOURCE_DIR)/bsd/vm/vnode_pager.c \
	$(SOURCE_DIR)/bsd/vm/vm_unix.c \
	$(SOURCE_DIR)/bsd/vm/dp_backing_file.c \
	$(SOURCE_DIR)/bsd/vm/vm_compressor_backing_file.c \
	$(SOURCE_DIR)/bsd/uxkern/ux_exception.c \
	$(SOURCE_DIR)/bsd/conf/param.c \
	./ioconf.c \
	$(SOURCE_DIR)/bsd/dev/chud/chud_bsd_callback.c \
	$(SOURCE_DIR)/bsd/dev/chud/chud_process.c \
	$(SOURCE_DIR)/bsd/kern/imageboot.c \
	$(SOURCE_DIR)/osfmk/kperf/kperfbsd.c \
	$(SOURCE_DIR)/bsd/kern/kern_kpc.c \
	$(SOURCE_DIR)/bsd/kern/proc_uuid_policy.c \
	$(SOURCE_DIR)/bsd/dev/i386/conf.c \
	$(SOURCE_DIR)/bsd/dev/i386/cons.c \
	$(SOURCE_DIR)/bsd/dev/i386/mem.c \
	$(SOURCE_DIR)/bsd/dev/i386/km.c \
	$(SOURCE_DIR)/bsd/dev/i386/kern_machdep.c \
	$(SOURCE_DIR)/bsd/dev/i386/memmove.c \
	$(SOURCE_DIR)/bsd/dev/i386/stubs.c \
	$(SOURCE_DIR)/bsd/dev/i386/systemcalls.c \
	$(SOURCE_DIR)/bsd/dev/i386/sysctl.c \
	$(SOURCE_DIR)/bsd/dev/i386/unix_signal.c \
	$(SOURCE_DIR)/bsd/dev/i386/dtrace_isa.c \
	$(SOURCE_DIR)/bsd/dev/i386/dtrace_subr_x86.c \
	$(SOURCE_DIR)/bsd/dev/i386/fbt_x86.c \
	$(SOURCE_DIR)/bsd/dev/i386/sdt_x86.c \
	$(SOURCE_DIR)/bsd/dev/i386/fasttrap_isa.c \
	$(SOURCE_DIR)/bsd/dev/i386/instr_size.c \
	$(SOURCE_DIR)/bsd/dev/i386/dis_tables.c \
	$(SOURCE_DIR)/bsd/kern/policy_check.c \
	$(SOURCE_DIR)/bsd/kern/bsd_stubs.c \
	$(SOURCE_DIR)/bsd/netinet/cpu_in_cksum.c \
	$(SOURCE_DIR)/bsd/netinet/in_cksum.c 
COBJS=nfs4_subs.o nfs4_vnops.o krpc_subr.o nfs_bio.o nfs_boot.o \
	nfs_gss.o nfs_gss_crypto.o nfs_lock.o nfs_node.o nfs_serv.o \
	nfs_socket.o nfs_srvcache.o nfs_subs.o nfs_syscalls.o \
	nfs_vfsops.o nfs_vnops.o nfs_upcall.o netboot.o dtrace.o \
	lockstat.o dtrace_ptss.o dtrace_subr.o dtrace_glue.o \
	dtrace_alloc.o blist.o fbt.o sdt.o sdt_subr.o systrace.o \
	profile_prvd.o fasttrap.o randomdev.o fips_sha1.o smf.o comp.o \
	prng.o sha1mod.o yarrowUtils.o memdev.o munge.o unix_startup.o \
	vn.o shadow.o crc32.o random.o scanc.o skpc.o strsep.o bcd.o \
	memchr.o vfs_attrlist.o vfs_bio.o vfs_cache.o vfs_cluster.o \
	vfs_conf.o vfs_fslog.o vfs_init.o vfs_lookup.o vfs_quota.o \
	vfs_subr.o vfs_syscalls.o vfs_support.o vfs_utfconv.o \
	vfs_vnops.o vfs_xattr.o vnode_if.o kpi_vfs.o vfs_journal.o \
	vfs_fsevents.o dead_vnops.o devfs_fdesc_support.o fifo_vnops.o \
	spec_vnops.o devfs_tree.o devfs_vnops.o devfs_vfsops.o decmpfs.o \
	net_stubs.o bpf.o bpf_filter.o if_bridge.o if.o init.o dlil.o \
	ether_if_module.o ether_inet_pr_module.o ether_inet6_pr_module.o \
	if_loop.o if_mib.o if_vlan.o multicast_list.o if_bond.o \
	devtimer.o ndrv.o radix.o raw_cb.o raw_usrreq.o route.o rtsock.o \
	netsrc.o ntstat.o if_gif.o if_stf.o kpi_interface.o \
	kpi_protocol.o kpi_interfacefilter.o net_str_id.o if_utun.o \
	if_utun_crypto.o if_utun_crypto_dtls.o if_utun_crypto_ipsec.o \
	if_ipsec.o if_pflog.o pf.o pf_if.o pf_ioctl.o pf_norm.o \
	pf_osfp.o pf_ruleset.o pf_table.o iptap.o pktap.o if_llreach.o \
	flowhash.o flowadv.o classq.o classq_sfb.o classq_subr.o \
	classq_util.o pktsched.o pktsched_qfq.o pktsched_tcq.o igmp.o \
	in.o in_dhcp.o dhcp_options.o in_arp.o in_mcast.o in_pcb.o \
	in_pcblist.o in_proto.o in_rmx.o in_tclass.o ip_divert.o \
	ip_dummynet.o ip_fw2.o ip_fw2_compat.o ip_icmp.o ip_id.o \
	ip_input.o ip_output.o raw_ip.o tcp_input.o tcp_output.o \
	tcp_sack.o tcp_subr.o tcp_timer.o tcp_usrreq.o tcp_newreno.o \
	tcp_lro.o tcp_ledbat.o udp_usrreq.o in_gif.o ip_ecn.o ip_encap.o \
	kpi_ipfilter.o flow_divert.o ah_core.o ah_input.o ah_output.o \
	esp_core.o esp_input.o esp_output.o esp_rijndael.o ipsec.o \
	dest6.o frag6.o icmp6.o in6.o in6_cga.o in6_cksum.o in6_gif.o \
	ip6_fw.o ip6_forward.o in6_ifattach.o ip6_input.o ip6_output.o \
	in6_src.o ipcomp_core.o ipcomp_input.o ipcomp_output.o \
	in6_mcast.o in6_pcb.o in6_proto.o in6_rmx.o mld6.o nd6.o \
	nd6_nbr.o nd6_prproxy.o nd6_rtr.o nd6_send.o raw_ip6.o route6.o \
	scope6.o udp6_output.o udp6_usrreq.o ip6_id.o key.o key_debug.o \
	keysock.o keydb.o bf_enc.o bf_skey.o cast128.o rc4.o \
	hfs_attrlist.o hfs_btreeio.o hfs_catalog.o hfs_chash.o \
	hfs_cnode.o hfs_encodinghint.o hfs_encodings.o hfs_endian.o \
	hfs_hotfiles.o hfs_link.o hfs_lookup.o hfs_notification.o \
	hfs_quota.o hfs_readwrite.o hfs_search.o hfs_vfsops.o \
	hfs_vfsutils.o hfs_vnops.o hfs_xattr.o MacOSStubs.o \
	hfs_cprotect.o rangelist.o BTree.o BTreeAllocate.o \
	BTreeMiscOps.o BTreeNodeOps.o BTreeNodeReserve.o BTreeScanner.o \
	BTreeTreeOps.o CatalogUtilities.o FileIDsServices.o \
	BTreeWrapper.o FileExtentMapping.o VolumeAllocation.o \
	UnicodeWrappers.o audit.o audit_arg.o audit_bsd.o audit_bsm.o \
	audit_bsm_errno.o audit_bsm_fcntl.o audit_bsm_domain.o \
	audit_bsm_klib.o audit_bsm_socket_type.o audit_bsm_token.o \
	audit_kevents.o audit_mac.o audit_pipe.o audit_session.o \
	audit_syscalls.o audit_worker.o bsd_init.o init_sysent.o \
	kdebug.o kern_acct.o kern_aio.o kern_authorization.o \
	kern_clock.o kern_core.o kern_credential.o kern_cs.o \
	kern_symfile.o kern_descrip.o kern_guarded.o kern_event.o \
	kern_control.o kern_exec.o kern_exit.o kern_lockf.o kern_fork.o \
	kern_asl.o kern_malloc.o kern_mman.o kern_physio.o kern_priv.o \
	kern_proc.o kern_prot.o kern_resource.o kern_shutdown.o \
	kern_sig.o kern_subr.o kern_synch.o kern_sysctl.o \
	kern_newsysctl.o kern_memorystatus.o kern_mib.o kpi_mbuf.o \
	kern_time.o kern_xxx.o mach_process.o mcache.o spl.o subr_log.o \
	subr_prf.o subr_prof.o subr_sbuf.o subr_xxx.o sys_generic.o \
	sys_pipe.o sys_socket.o sys_domain.o syscalls.o tty.o \
	tty_compat.o tty_conf.o tty_pty.o tty_ptmx.o tty_subr.o \
	tty_tty.o ubc_subr.o uipc_domain.o uipc_mbuf.o uipc_mbuf2.o \
	uipc_proto.o uipc_socket.o uipc_socket2.o uipc_syscalls.o \
	uipc_usrreq.o sysv_ipc.o sysv_shm.o sysv_sem.o sysv_msg.o \
	mach_fat.o mach_loader.o posix_sem.o posix_shm.o qsort.o \
	kpi_socket.o kpi_socketfilter.o pthread_shims.o proc_info.o \
	process_policy.o kern_overrides.o vm_pressure.o socket_info.o \
	vnode_pager.o vm_unix.o dp_backing_file.o \
	vm_compressor_backing_file.o ux_exception.o param.o ioconf.o \
	chud_bsd_callback.o chud_process.o imageboot.o kperfbsd.o \
	kern_kpc.o proc_uuid_policy.o conf.o cons.o mem.o km.o \
	kern_machdep.o memmove.o stubs.o systemcalls.o sysctl.o \
	unix_signal.o dtrace_isa.o dtrace_subr_x86.o fbt_x86.o sdt_x86.o \
	fasttrap_isa.o instr_size.o dis_tables.o policy_check.o \
	bsd_stubs.o cpu_in_cksum.o in_cksum.o 

SFILES=SOBJS=

LIBDRIVER=libDriver_kern.o
LIBOBJC=libkobjc.o
CCONFIGFLAGS=-g -O3 -fno-omit-frame-pointer
RELOC=00100000
SYMADDR=00780000
######################################################################
#BEGIN  Machine dependent Makefile fragment for x86_64
######################################################################
 
# Files to build with certain warnings turned off
dis_tables.o_CFLAGS_ADD += -Wno-cast-qual
fbt_x86.o_CFLAGS_ADD += -Wno-cast-qual

# Inline assembly doesn't interact well with LTO
fbt_x86.o_CFLAGS_ADD += $(CFLAGS_NOLTO_FLAG)
# Taking the address of labels doesn't work with LTO (9524055)
dtrace.o_CFLAGS_ADD += $(CFLAGS_NOLTO_FLAG)

######################################################################
#END    Machine dependent Makefile fragment for x86_64
######################################################################


#
# Machine-independent per-file flags
#

dp_backing_file.o_CFLAGS_ADD	+= -Wshorten-64-to-32
ubc_subr.o_CFLAGS_ADD			+= -Wshorten-64-to-32
vnode_pager.o_CFLAGS_ADD		+= -Wshorten-64-to-32
vm_unix.o_CFLAGS_ADD			+= -Wshorten-64-to-32
pthread_synch.o_CFLAGS_ADD		+= -Wno-unused-parameter -Wno-missing-prototypes
pthread_support.o_CFLAGS_ADD		+= -Wno-unused-parameter -Wno-missing-prototypes

# Objects that don't want -Wsign-compare
OBJS_NO_SIGN_COMPARE =		\
		radix.o	\
		route.o	\
		rtsock.o	\
		dhcp_options.o	\
		igmp.o	\
		in_cksum.o	\
		ip_divert.o	\
		ip_dummynet.o	\
		ip_flow.o	\
		ip_fw2.o	\
		ip_fw2_compat.o	\
		ip_icmp.o	\
		ip_input.o	\
		ip_mroute.o	\
		ip_output.o	\
		raw_ip.o	\
		tcp_input.o	\
		tcp_output.o	\
		tcp_subr.o	\
		tcp_usrreq.o	\
		tcp_timer.o	\
		udp_usrreq.o	\
		ah_input.o	\
		ah_core.o	\
		ah_output.o	\
		esp_core.o	\
		esp_input.o	\
		esp_output.o	\
		esp_rijndael.o	\
		ipsec.o	\
		dest6.o	\
		frag6.o	\
		icmp6.o	\
		in6.o	\
		in6_src.o	\
		in6_cksum.o	\
		ip6_fw.o	\
		ip6_forward.o	\
		in6_ifattach.o	\
		ip6_input.o	\
		ip6_mroute.o	\
		ip6_output.o	\
		ipcomp_input.o	\
		ipcomp_output.o	\
		in6_proto.o	\
		mld6.o	\
		nd6.o	\
		nd6_nbr.o	\
		nd6_prproxy.o	\
		nd6_rtr.o	\
		raw_ip6.o	\
		route6.o	\
		scope6.o	\
		udp6_usrreq.o	\
		key.o	\
		keysock.o	\
		keydb.o	\
		des_setkey.o	\
		uipc_mbuf.o	\
		uipc_mbuf2.o	\
		uipc_socket.o	\
		uipc_socket2.o

$(foreach file,$(OBJS_NO_SIGN_COMPARE),$(eval $(call add_perfile_cflags,$(file),-Wno-sign-compare)))

# Objects that don't want -Wcast-align warning (8474835)
OBJS_NO_CAST_ALIGN =			\
		BTree.o			\
		BTreeAllocate.o		\
		BTreeMiscOps.o		\
		BTreeNodeOps.o		\
		BTreeScanner.o		\
		BTreeTreeOps.o		\
		CatalogUtilities.o	\
		audit_bsm_token.o	\
		audit_pipe.o		\
		audit_session.o		\
		bsd_i386.o		\
		decmpfs.o		\
		dtrace.o		\
		fasttrap.o		\
		fasttrap_isa.o		\
		fbt_arm.o		\
		fbt_x86.o		\
		fips_sha1.o		\
		hfs_attrlist.o		\
		hfs_btreeio.o		\
		hfs_catalog.o		\
		hfs_cnode.o		\
		hfs_endian.o		\
		hfs_hotfiles.o		\
		hfs_link.o		\
		hfs_quota.o		\
		hfs_readwrite.o		\
		hfs_search.o		\
		hfs_vfsops.o		\
		hfs_vnops.o		\
		hfs_xattr.o		\
		if_bond.o		\
		ip6_fw.o		\
		ip_dummynet.o		\
		ip_fw2.o		\
		kern_credential.o	\
		kern_descrip.o		\
		kern_event.o		\
		kern_exec.o		\
		kern_lockf.o		\
		kern_subr.o		\
		km.o			\
		lockstat.o		\
		mach_loader.o		\
		memdev.o		\
		nfs4_subs.o		\
		nfs4_vnops.o		\
		nfs_boot.o		\
		nfs_gss.o		\
		nfs_serv.o		\
		nfs_socket.o		\
		nfs_srvcache.o		\
		nfs_subs.o		\
		nfs_syscalls.o		\
		nfs_vfsops.o		\
		nfs_vnops.o		\
		proc_info.o		\
		pthread_synch.o		\
		qsort.o			\
		randomdev.o		\
		sdt.o			\
                sha1mod.o               \
		shadow.o		\
		spec_vnops.o		\
		subr_log.o		\
		subr_prof.o		\
		sys_generic.o		\
		sys_pipe.o		\
		systemcalls.o		\
		systrace.o		\
		tcp_lro.o		\
		tty.o			\
		tty_compat.o		\
		tty_ptmx.o		\
		tty_pty.o		\
		ubc_subr.o		\
		uipc_usrreq.o		\
		vfs_attrlist.o		\
		vfs_fsevents.o		\
		vfs_journal.o		\
		vfs_lookup.o		\
		vfs_subr.o		\
		vfs_syscalls.o		\
		vfs_utfconv.o		\
		vfs_vnops.o		\
		vfs_xattr.o		\
		vn.o			\
		munge.o			\
		aes.o			\
		aeskey.o		\
		sdt_arm.o

$(foreach file,$(OBJS_NO_CAST_ALIGN),$(eval $(call add_perfile_cflags,$(file),-Wno-cast-align)))

#
# This rule insures that the subr_prof.c does NOT get compiled with
# profiling. It implements mcount() and profiling it leads to recursion.
#

subr_prof.o_CFLAGS_RM = -pg

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

MAKESYSCALLS = $(SRCROOT)/bsd/kern/makesyscalls.sh

init_sysent.c: $(SRCROOT)/bsd/kern/syscalls.master $(MAKESYSCALLS)
	@echo "Generating $@ from $<";
	$(_v)$(MAKESYSCALLS) $< table > /dev/null

syscalls.c: $(SRCROOT)/bsd/kern/syscalls.master $(MAKESYSCALLS)
	@echo "Generating $@ from $<";
	$(_v)$(MAKESYSCALLS) $< names > /dev/null

audit_kevents.c: $(SRCROOT)/bsd/kern/syscalls.master $(MAKESYSCALLS)
	@echo "Generating $@ from $<";
	$(_v)$(MAKESYSCALLS) $< audit > /dev/null

do_all: $(COMPONENT).filelist

do_build_all:: do_all

-include nfs4_subs.d
nfs4_subs.o: $(SOURCE_DIR)/bsd/nfs/nfs4_subs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs4_vnops.d
nfs4_vnops.o: $(SOURCE_DIR)/bsd/nfs/nfs4_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include krpc_subr.d
krpc_subr.o: $(SOURCE_DIR)/bsd/nfs/krpc_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_bio.d
nfs_bio.o: $(SOURCE_DIR)/bsd/nfs/nfs_bio.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_boot.d
nfs_boot.o: $(SOURCE_DIR)/bsd/nfs/nfs_boot.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_gss.d
nfs_gss.o: $(SOURCE_DIR)/bsd/nfs/nfs_gss.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_gss_crypto.d
nfs_gss_crypto.o: $(SOURCE_DIR)/bsd/nfs/nfs_gss_crypto.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_lock.d
nfs_lock.o: $(SOURCE_DIR)/bsd/nfs/nfs_lock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_node.d
nfs_node.o: $(SOURCE_DIR)/bsd/nfs/nfs_node.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_serv.d
nfs_serv.o: $(SOURCE_DIR)/bsd/nfs/nfs_serv.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_socket.d
nfs_socket.o: $(SOURCE_DIR)/bsd/nfs/nfs_socket.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_srvcache.d
nfs_srvcache.o: $(SOURCE_DIR)/bsd/nfs/nfs_srvcache.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_subs.d
nfs_subs.o: $(SOURCE_DIR)/bsd/nfs/nfs_subs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_syscalls.d
nfs_syscalls.o: $(SOURCE_DIR)/bsd/nfs/nfs_syscalls.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_vfsops.d
nfs_vfsops.o: $(SOURCE_DIR)/bsd/nfs/nfs_vfsops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_vnops.d
nfs_vnops.o: $(SOURCE_DIR)/bsd/nfs/nfs_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nfs_upcall.d
nfs_upcall.o: $(SOURCE_DIR)/bsd/nfs/nfs_upcall.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/nfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include netboot.d
netboot.o: $(SOURCE_DIR)/bsd/kern/netboot.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dtrace.d
dtrace.o: $(SOURCE_DIR)/bsd/dev/dtrace/dtrace.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include lockstat.d
lockstat.o: $(SOURCE_DIR)/bsd/dev/dtrace/lockstat.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dtrace_ptss.d
dtrace_ptss.o: $(SOURCE_DIR)/bsd/dev/dtrace/dtrace_ptss.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dtrace_subr.d
dtrace_subr.o: $(SOURCE_DIR)/bsd/dev/dtrace/dtrace_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dtrace_glue.d
dtrace_glue.o: $(SOURCE_DIR)/bsd/dev/dtrace/dtrace_glue.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dtrace_alloc.d
dtrace_alloc.o: $(SOURCE_DIR)/bsd/dev/dtrace/dtrace_alloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include blist.d
blist.o: $(SOURCE_DIR)/bsd/dev/dtrace/blist.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include fbt.d
fbt.o: $(SOURCE_DIR)/bsd/dev/dtrace/fbt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sdt.d
sdt.o: $(SOURCE_DIR)/bsd/dev/dtrace/sdt.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sdt_subr.d
sdt_subr.o: $(SOURCE_DIR)/bsd/dev/dtrace/sdt_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include systrace.d
systrace.o: $(SOURCE_DIR)/bsd/dev/dtrace/systrace.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include profile_prvd.d
profile_prvd.o: $(SOURCE_DIR)/bsd/dev/dtrace/profile_prvd.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include fasttrap.d
fasttrap.o: $(SOURCE_DIR)/bsd/dev/dtrace/fasttrap.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/dtrace/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include randomdev.d
randomdev.o: $(SOURCE_DIR)/bsd/dev/random/randomdev.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/random/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/random/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include fips_sha1.d
fips_sha1.o: $(SOURCE_DIR)/bsd/dev/random/fips_sha1.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/random/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/random/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include smf.d
smf.o: $(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/port/smf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/port/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/port/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include comp.d
comp.o: $(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/comp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include prng.d
prng.o: $(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/prng.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sha1mod.d
sha1mod.o: $(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/sha1mod.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include yarrowUtils.d
yarrowUtils.o: $(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/yarrowUtils.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/random/YarrowCoreLib/src/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memdev.d
memdev.o: $(SOURCE_DIR)/bsd/dev/memdev.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include munge.d
munge.o: $(SOURCE_DIR)/bsd/dev/munge.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include unix_startup.d
unix_startup.o: $(SOURCE_DIR)/bsd/dev/unix_startup.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vn.d
vn.o: $(SOURCE_DIR)/bsd/dev/vn/vn.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/vn/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/vn/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include shadow.d
shadow.o: $(SOURCE_DIR)/bsd/dev/vn/shadow.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/vn/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/vn/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include crc32.d
crc32.o: $(SOURCE_DIR)/bsd/libkern/crc32.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include random.d
random.o: $(SOURCE_DIR)/bsd/libkern/random.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include scanc.d
scanc.o: $(SOURCE_DIR)/bsd/libkern/scanc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include skpc.d
skpc.o: $(SOURCE_DIR)/bsd/libkern/skpc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include strsep.d
strsep.o: $(SOURCE_DIR)/bsd/libkern/strsep.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bcd.d
bcd.o: $(SOURCE_DIR)/bsd/libkern/bcd.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memchr.d
memchr.o: $(SOURCE_DIR)/bsd/libkern/memchr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/libkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_attrlist.d
vfs_attrlist.o: $(SOURCE_DIR)/bsd/vfs/vfs_attrlist.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_bio.d
vfs_bio.o: $(SOURCE_DIR)/bsd/vfs/vfs_bio.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_cache.d
vfs_cache.o: $(SOURCE_DIR)/bsd/vfs/vfs_cache.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_cluster.d
vfs_cluster.o: $(SOURCE_DIR)/bsd/vfs/vfs_cluster.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_conf.d
vfs_conf.o: $(SOURCE_DIR)/bsd/vfs/vfs_conf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_fslog.d
vfs_fslog.o: $(SOURCE_DIR)/bsd/vfs/vfs_fslog.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_init.d
vfs_init.o: $(SOURCE_DIR)/bsd/vfs/vfs_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_lookup.d
vfs_lookup.o: $(SOURCE_DIR)/bsd/vfs/vfs_lookup.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_quota.d
vfs_quota.o: $(SOURCE_DIR)/bsd/vfs/vfs_quota.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_subr.d
vfs_subr.o: $(SOURCE_DIR)/bsd/vfs/vfs_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_syscalls.d
vfs_syscalls.o: $(SOURCE_DIR)/bsd/vfs/vfs_syscalls.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_support.d
vfs_support.o: $(SOURCE_DIR)/bsd/vfs/vfs_support.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_utfconv.d
vfs_utfconv.o: $(SOURCE_DIR)/bsd/vfs/vfs_utfconv.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_vnops.d
vfs_vnops.o: $(SOURCE_DIR)/bsd/vfs/vfs_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_xattr.d
vfs_xattr.o: $(SOURCE_DIR)/bsd/vfs/vfs_xattr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vnode_if.d
vnode_if.o: $(SOURCE_DIR)/bsd/vfs/vnode_if.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_vfs.d
kpi_vfs.o: $(SOURCE_DIR)/bsd/vfs/kpi_vfs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_journal.d
vfs_journal.o: $(SOURCE_DIR)/bsd/vfs/vfs_journal.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vfs_fsevents.d
vfs_fsevents.o: $(SOURCE_DIR)/bsd/vfs/vfs_fsevents.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dead_vnops.d
dead_vnops.o: $(SOURCE_DIR)/bsd/miscfs/deadfs/dead_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/miscfs/deadfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/miscfs/deadfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include devfs_fdesc_support.d
devfs_fdesc_support.o: $(SOURCE_DIR)/bsd/miscfs/devfs/devfs_fdesc_support.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include fifo_vnops.d
fifo_vnops.o: $(SOURCE_DIR)/bsd/miscfs/fifofs/fifo_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/miscfs/fifofs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/miscfs/fifofs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include spec_vnops.d
spec_vnops.o: $(SOURCE_DIR)/bsd/miscfs/specfs/spec_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/miscfs/specfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/miscfs/specfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include devfs_tree.d
devfs_tree.o: $(SOURCE_DIR)/bsd/miscfs/devfs/devfs_tree.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include devfs_vnops.d
devfs_vnops.o: $(SOURCE_DIR)/bsd/miscfs/devfs/devfs_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include devfs_vfsops.d
devfs_vfsops.o: $(SOURCE_DIR)/bsd/miscfs/devfs/devfs_vfsops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/miscfs/devfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include decmpfs.d
decmpfs.o: $(SOURCE_DIR)/bsd/kern/decmpfs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include net_stubs.d
net_stubs.o: $(SOURCE_DIR)/bsd/net/net_stubs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bpf.d
bpf.o: $(SOURCE_DIR)/bsd/net/bpf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bpf_filter.d
bpf_filter.o: $(SOURCE_DIR)/bsd/net/bpf_filter.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_bridge.d
if_bridge.o: $(SOURCE_DIR)/bsd/net/if_bridge.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if.d
if.o: $(SOURCE_DIR)/bsd/net/if.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include init.d
init.o: $(SOURCE_DIR)/bsd/net/init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dlil.d
dlil.o: $(SOURCE_DIR)/bsd/net/dlil.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ether_if_module.d
ether_if_module.o: $(SOURCE_DIR)/bsd/net/ether_if_module.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ether_inet_pr_module.d
ether_inet_pr_module.o: $(SOURCE_DIR)/bsd/net/ether_inet_pr_module.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ether_inet6_pr_module.d
ether_inet6_pr_module.o: $(SOURCE_DIR)/bsd/net/ether_inet6_pr_module.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_loop.d
if_loop.o: $(SOURCE_DIR)/bsd/net/if_loop.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_mib.d
if_mib.o: $(SOURCE_DIR)/bsd/net/if_mib.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_vlan.d
if_vlan.o: $(SOURCE_DIR)/bsd/net/if_vlan.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include multicast_list.d
multicast_list.o: $(SOURCE_DIR)/bsd/net/multicast_list.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_bond.d
if_bond.o: $(SOURCE_DIR)/bsd/net/if_bond.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include devtimer.d
devtimer.o: $(SOURCE_DIR)/bsd/net/devtimer.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ndrv.d
ndrv.o: $(SOURCE_DIR)/bsd/net/ndrv.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include radix.d
radix.o: $(SOURCE_DIR)/bsd/net/radix.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include raw_cb.d
raw_cb.o: $(SOURCE_DIR)/bsd/net/raw_cb.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include raw_usrreq.d
raw_usrreq.o: $(SOURCE_DIR)/bsd/net/raw_usrreq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include route.d
route.o: $(SOURCE_DIR)/bsd/net/route.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include rtsock.d
rtsock.o: $(SOURCE_DIR)/bsd/net/rtsock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include netsrc.d
netsrc.o: $(SOURCE_DIR)/bsd/net/netsrc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ntstat.d
ntstat.o: $(SOURCE_DIR)/bsd/net/ntstat.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_gif.d
if_gif.o: $(SOURCE_DIR)/bsd/net/if_gif.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_stf.d
if_stf.o: $(SOURCE_DIR)/bsd/net/if_stf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_interface.d
kpi_interface.o: $(SOURCE_DIR)/bsd/net/kpi_interface.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_protocol.d
kpi_protocol.o: $(SOURCE_DIR)/bsd/net/kpi_protocol.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_interfacefilter.d
kpi_interfacefilter.o: $(SOURCE_DIR)/bsd/net/kpi_interfacefilter.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include net_str_id.d
net_str_id.o: $(SOURCE_DIR)/bsd/net/net_str_id.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_utun.d
if_utun.o: $(SOURCE_DIR)/bsd/net/if_utun.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_utun_crypto.d
if_utun_crypto.o: $(SOURCE_DIR)/bsd/net/if_utun_crypto.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_utun_crypto_dtls.d
if_utun_crypto_dtls.o: $(SOURCE_DIR)/bsd/net/if_utun_crypto_dtls.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_utun_crypto_ipsec.d
if_utun_crypto_ipsec.o: $(SOURCE_DIR)/bsd/net/if_utun_crypto_ipsec.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_ipsec.d
if_ipsec.o: $(SOURCE_DIR)/bsd/net/if_ipsec.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_pflog.d
if_pflog.o: $(SOURCE_DIR)/bsd/net/if_pflog.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pf.d
pf.o: $(SOURCE_DIR)/bsd/net/pf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pf_if.d
pf_if.o: $(SOURCE_DIR)/bsd/net/pf_if.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pf_ioctl.d
pf_ioctl.o: $(SOURCE_DIR)/bsd/net/pf_ioctl.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pf_norm.d
pf_norm.o: $(SOURCE_DIR)/bsd/net/pf_norm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pf_osfp.d
pf_osfp.o: $(SOURCE_DIR)/bsd/net/pf_osfp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pf_ruleset.d
pf_ruleset.o: $(SOURCE_DIR)/bsd/net/pf_ruleset.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pf_table.d
pf_table.o: $(SOURCE_DIR)/bsd/net/pf_table.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include iptap.d
iptap.o: $(SOURCE_DIR)/bsd/net/iptap.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pktap.d
pktap.o: $(SOURCE_DIR)/bsd/net/pktap.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include if_llreach.d
if_llreach.o: $(SOURCE_DIR)/bsd/net/if_llreach.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include flowhash.d
flowhash.o: $(SOURCE_DIR)/bsd/net/flowhash.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include flowadv.d
flowadv.o: $(SOURCE_DIR)/bsd/net/flowadv.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include classq.d
classq.o: $(SOURCE_DIR)/bsd/net/classq/classq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include classq_sfb.d
classq_sfb.o: $(SOURCE_DIR)/bsd/net/classq/classq_sfb.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include classq_subr.d
classq_subr.o: $(SOURCE_DIR)/bsd/net/classq/classq_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include classq_util.d
classq_util.o: $(SOURCE_DIR)/bsd/net/classq/classq_util.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/classq/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pktsched.d
pktsched.o: $(SOURCE_DIR)/bsd/net/pktsched/pktsched.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/pktsched/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/pktsched/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pktsched_qfq.d
pktsched_qfq.o: $(SOURCE_DIR)/bsd/net/pktsched/pktsched_qfq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/pktsched/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/pktsched/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pktsched_tcq.d
pktsched_tcq.o: $(SOURCE_DIR)/bsd/net/pktsched/pktsched_tcq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/net/pktsched/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/net/pktsched/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include igmp.d
igmp.o: $(SOURCE_DIR)/bsd/netinet/igmp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in.d
in.o: $(SOURCE_DIR)/bsd/netinet/in.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_dhcp.d
in_dhcp.o: $(SOURCE_DIR)/bsd/netinet/in_dhcp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dhcp_options.d
dhcp_options.o: $(SOURCE_DIR)/bsd/netinet/dhcp_options.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_arp.d
in_arp.o: $(SOURCE_DIR)/bsd/netinet/in_arp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_mcast.d
in_mcast.o: $(SOURCE_DIR)/bsd/netinet/in_mcast.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_pcb.d
in_pcb.o: $(SOURCE_DIR)/bsd/netinet/in_pcb.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_pcblist.d
in_pcblist.o: $(SOURCE_DIR)/bsd/netinet/in_pcblist.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_proto.d
in_proto.o: $(SOURCE_DIR)/bsd/netinet/in_proto.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_rmx.d
in_rmx.o: $(SOURCE_DIR)/bsd/netinet/in_rmx.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_tclass.d
in_tclass.o: $(SOURCE_DIR)/bsd/netinet/in_tclass.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_divert.d
ip_divert.o: $(SOURCE_DIR)/bsd/netinet/ip_divert.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_dummynet.d
ip_dummynet.o: $(SOURCE_DIR)/bsd/netinet/ip_dummynet.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_fw2.d
ip_fw2.o: $(SOURCE_DIR)/bsd/netinet/ip_fw2.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_fw2_compat.d
ip_fw2_compat.o: $(SOURCE_DIR)/bsd/netinet/ip_fw2_compat.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_icmp.d
ip_icmp.o: $(SOURCE_DIR)/bsd/netinet/ip_icmp.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_id.d
ip_id.o: $(SOURCE_DIR)/bsd/netinet/ip_id.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_input.d
ip_input.o: $(SOURCE_DIR)/bsd/netinet/ip_input.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_output.d
ip_output.o: $(SOURCE_DIR)/bsd/netinet/ip_output.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include raw_ip.d
raw_ip.o: $(SOURCE_DIR)/bsd/netinet/raw_ip.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_input.d
tcp_input.o: $(SOURCE_DIR)/bsd/netinet/tcp_input.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_output.d
tcp_output.o: $(SOURCE_DIR)/bsd/netinet/tcp_output.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_sack.d
tcp_sack.o: $(SOURCE_DIR)/bsd/netinet/tcp_sack.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_subr.d
tcp_subr.o: $(SOURCE_DIR)/bsd/netinet/tcp_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_timer.d
tcp_timer.o: $(SOURCE_DIR)/bsd/netinet/tcp_timer.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_usrreq.d
tcp_usrreq.o: $(SOURCE_DIR)/bsd/netinet/tcp_usrreq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_newreno.d
tcp_newreno.o: $(SOURCE_DIR)/bsd/netinet/tcp_newreno.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_lro.d
tcp_lro.o: $(SOURCE_DIR)/bsd/netinet/tcp_lro.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tcp_ledbat.d
tcp_ledbat.o: $(SOURCE_DIR)/bsd/netinet/tcp_ledbat.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include udp_usrreq.d
udp_usrreq.o: $(SOURCE_DIR)/bsd/netinet/udp_usrreq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_gif.d
in_gif.o: $(SOURCE_DIR)/bsd/netinet/in_gif.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_ecn.d
ip_ecn.o: $(SOURCE_DIR)/bsd/netinet/ip_ecn.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip_encap.d
ip_encap.o: $(SOURCE_DIR)/bsd/netinet/ip_encap.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_ipfilter.d
kpi_ipfilter.o: $(SOURCE_DIR)/bsd/netinet/kpi_ipfilter.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include flow_divert.d
flow_divert.o: $(SOURCE_DIR)/bsd/netinet/flow_divert.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ah_core.d
ah_core.o: $(SOURCE_DIR)/bsd/netinet6/ah_core.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ah_input.d
ah_input.o: $(SOURCE_DIR)/bsd/netinet6/ah_input.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ah_output.d
ah_output.o: $(SOURCE_DIR)/bsd/netinet6/ah_output.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include esp_core.d
esp_core.o: $(SOURCE_DIR)/bsd/netinet6/esp_core.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include esp_input.d
esp_input.o: $(SOURCE_DIR)/bsd/netinet6/esp_input.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include esp_output.d
esp_output.o: $(SOURCE_DIR)/bsd/netinet6/esp_output.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include esp_rijndael.d
esp_rijndael.o: $(SOURCE_DIR)/bsd/netinet6/esp_rijndael.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipsec.d
ipsec.o: $(SOURCE_DIR)/bsd/netinet6/ipsec.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dest6.d
dest6.o: $(SOURCE_DIR)/bsd/netinet6/dest6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include frag6.d
frag6.o: $(SOURCE_DIR)/bsd/netinet6/frag6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include icmp6.d
icmp6.o: $(SOURCE_DIR)/bsd/netinet6/icmp6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6.d
in6.o: $(SOURCE_DIR)/bsd/netinet6/in6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_cga.d
in6_cga.o: $(SOURCE_DIR)/bsd/netinet6/in6_cga.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_cksum.d
in6_cksum.o: $(SOURCE_DIR)/bsd/netinet6/in6_cksum.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_gif.d
in6_gif.o: $(SOURCE_DIR)/bsd/netinet6/in6_gif.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip6_fw.d
ip6_fw.o: $(SOURCE_DIR)/bsd/netinet6/ip6_fw.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip6_forward.d
ip6_forward.o: $(SOURCE_DIR)/bsd/netinet6/ip6_forward.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_ifattach.d
in6_ifattach.o: $(SOURCE_DIR)/bsd/netinet6/in6_ifattach.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip6_input.d
ip6_input.o: $(SOURCE_DIR)/bsd/netinet6/ip6_input.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip6_output.d
ip6_output.o: $(SOURCE_DIR)/bsd/netinet6/ip6_output.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_src.d
in6_src.o: $(SOURCE_DIR)/bsd/netinet6/in6_src.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipcomp_core.d
ipcomp_core.o: $(SOURCE_DIR)/bsd/netinet6/ipcomp_core.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipcomp_input.d
ipcomp_input.o: $(SOURCE_DIR)/bsd/netinet6/ipcomp_input.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ipcomp_output.d
ipcomp_output.o: $(SOURCE_DIR)/bsd/netinet6/ipcomp_output.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_mcast.d
in6_mcast.o: $(SOURCE_DIR)/bsd/netinet6/in6_mcast.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_pcb.d
in6_pcb.o: $(SOURCE_DIR)/bsd/netinet6/in6_pcb.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_proto.d
in6_proto.o: $(SOURCE_DIR)/bsd/netinet6/in6_proto.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in6_rmx.d
in6_rmx.o: $(SOURCE_DIR)/bsd/netinet6/in6_rmx.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mld6.d
mld6.o: $(SOURCE_DIR)/bsd/netinet6/mld6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nd6.d
nd6.o: $(SOURCE_DIR)/bsd/netinet6/nd6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nd6_nbr.d
nd6_nbr.o: $(SOURCE_DIR)/bsd/netinet6/nd6_nbr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nd6_prproxy.d
nd6_prproxy.o: $(SOURCE_DIR)/bsd/netinet6/nd6_prproxy.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nd6_rtr.d
nd6_rtr.o: $(SOURCE_DIR)/bsd/netinet6/nd6_rtr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include nd6_send.d
nd6_send.o: $(SOURCE_DIR)/bsd/netinet6/nd6_send.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include raw_ip6.d
raw_ip6.o: $(SOURCE_DIR)/bsd/netinet6/raw_ip6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include route6.d
route6.o: $(SOURCE_DIR)/bsd/netinet6/route6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include scope6.d
scope6.o: $(SOURCE_DIR)/bsd/netinet6/scope6.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include udp6_output.d
udp6_output.o: $(SOURCE_DIR)/bsd/netinet6/udp6_output.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include udp6_usrreq.d
udp6_usrreq.o: $(SOURCE_DIR)/bsd/netinet6/udp6_usrreq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ip6_id.d
ip6_id.o: $(SOURCE_DIR)/bsd/netinet6/ip6_id.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet6/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include key.d
key.o: $(SOURCE_DIR)/bsd/netkey/key.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include key_debug.d
key_debug.o: $(SOURCE_DIR)/bsd/netkey/key_debug.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include keysock.d
keysock.o: $(SOURCE_DIR)/bsd/netkey/keysock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include keydb.d
keydb.o: $(SOURCE_DIR)/bsd/netkey/keydb.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netkey/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bf_enc.d
bf_enc.o: $(SOURCE_DIR)/bsd/crypto/blowfish/bf_enc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/crypto/blowfish/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/crypto/blowfish/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bf_skey.d
bf_skey.o: $(SOURCE_DIR)/bsd/crypto/blowfish/bf_skey.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/crypto/blowfish/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/crypto/blowfish/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include cast128.d
cast128.o: $(SOURCE_DIR)/bsd/crypto/cast128/cast128.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/crypto/cast128/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/crypto/cast128/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include rc4.d
rc4.o: $(SOURCE_DIR)/bsd/crypto/rc4/rc4.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/crypto/rc4/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/crypto/rc4/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_attrlist.d
hfs_attrlist.o: $(SOURCE_DIR)/bsd/hfs/hfs_attrlist.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_btreeio.d
hfs_btreeio.o: $(SOURCE_DIR)/bsd/hfs/hfs_btreeio.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_catalog.d
hfs_catalog.o: $(SOURCE_DIR)/bsd/hfs/hfs_catalog.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_chash.d
hfs_chash.o: $(SOURCE_DIR)/bsd/hfs/hfs_chash.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_cnode.d
hfs_cnode.o: $(SOURCE_DIR)/bsd/hfs/hfs_cnode.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_encodinghint.d
hfs_encodinghint.o: $(SOURCE_DIR)/bsd/hfs/hfs_encodinghint.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_encodings.d
hfs_encodings.o: $(SOURCE_DIR)/bsd/hfs/hfs_encodings.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_endian.d
hfs_endian.o: $(SOURCE_DIR)/bsd/hfs/hfs_endian.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_hotfiles.d
hfs_hotfiles.o: $(SOURCE_DIR)/bsd/hfs/hfs_hotfiles.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_link.d
hfs_link.o: $(SOURCE_DIR)/bsd/hfs/hfs_link.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_lookup.d
hfs_lookup.o: $(SOURCE_DIR)/bsd/hfs/hfs_lookup.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_notification.d
hfs_notification.o: $(SOURCE_DIR)/bsd/hfs/hfs_notification.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_quota.d
hfs_quota.o: $(SOURCE_DIR)/bsd/hfs/hfs_quota.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_readwrite.d
hfs_readwrite.o: $(SOURCE_DIR)/bsd/hfs/hfs_readwrite.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_search.d
hfs_search.o: $(SOURCE_DIR)/bsd/hfs/hfs_search.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_vfsops.d
hfs_vfsops.o: $(SOURCE_DIR)/bsd/hfs/hfs_vfsops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_vfsutils.d
hfs_vfsutils.o: $(SOURCE_DIR)/bsd/hfs/hfs_vfsutils.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_vnops.d
hfs_vnops.o: $(SOURCE_DIR)/bsd/hfs/hfs_vnops.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_xattr.d
hfs_xattr.o: $(SOURCE_DIR)/bsd/hfs/hfs_xattr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include MacOSStubs.d
MacOSStubs.o: $(SOURCE_DIR)/bsd/hfs/MacOSStubs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include hfs_cprotect.d
hfs_cprotect.o: $(SOURCE_DIR)/bsd/hfs/hfs_cprotect.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include rangelist.d
rangelist.o: $(SOURCE_DIR)/bsd/hfs/rangelist.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTree.d
BTree.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTree.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTreeAllocate.d
BTreeAllocate.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeAllocate.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTreeMiscOps.d
BTreeMiscOps.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeMiscOps.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTreeNodeOps.d
BTreeNodeOps.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeNodeOps.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTreeNodeReserve.d
BTreeNodeReserve.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeNodeReserve.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTreeScanner.d
BTreeScanner.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeScanner.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTreeTreeOps.d
BTreeTreeOps.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/BTreeTreeOps.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/BTree/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include CatalogUtilities.d
CatalogUtilities.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/CatalogUtilities.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include FileIDsServices.d
FileIDsServices.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/FileIDsServices.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Catalog/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include BTreeWrapper.d
BTreeWrapper.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/BTreeWrapper.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include FileExtentMapping.d
FileExtentMapping.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/FileExtentMapping.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include VolumeAllocation.d
VolumeAllocation.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/VolumeAllocation.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Misc/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include UnicodeWrappers.d
UnicodeWrappers.o: $(SOURCE_DIR)/bsd/hfs/hfscommon/Unicode/UnicodeWrappers.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Unicode/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/hfs/hfscommon/Unicode/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit.d
audit.o: $(SOURCE_DIR)/bsd/security/audit/audit.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_arg.d
audit_arg.o: $(SOURCE_DIR)/bsd/security/audit/audit_arg.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsd.d
audit_bsd.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsd.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsm.d
audit_bsm.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsm_errno.d
audit_bsm_errno.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsm_errno.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsm_fcntl.d
audit_bsm_fcntl.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsm_fcntl.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsm_domain.d
audit_bsm_domain.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsm_domain.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsm_klib.d
audit_bsm_klib.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsm_klib.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsm_socket_type.d
audit_bsm_socket_type.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsm_socket_type.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_bsm_token.d
audit_bsm_token.o: $(SOURCE_DIR)/bsd/security/audit/audit_bsm_token.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_kevents.d
audit_kevents.o: audit_kevents.c
	${C_RULE_0}
	${C_RULE_1A}${C_RULE_1B}
	${C_CTFRULE_1A}${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_mac.d
audit_mac.o: $(SOURCE_DIR)/bsd/security/audit/audit_mac.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_pipe.d
audit_pipe.o: $(SOURCE_DIR)/bsd/security/audit/audit_pipe.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_session.d
audit_session.o: $(SOURCE_DIR)/bsd/security/audit/audit_session.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_syscalls.d
audit_syscalls.o: $(SOURCE_DIR)/bsd/security/audit/audit_syscalls.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include audit_worker.d
audit_worker.o: $(SOURCE_DIR)/bsd/security/audit/audit_worker.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/security/audit/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bsd_init.d
bsd_init.o: $(SOURCE_DIR)/bsd/kern/bsd_init.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include init_sysent.d
init_sysent.o: init_sysent.c
	${C_RULE_0}
	${C_RULE_1A}${C_RULE_1B}
	${C_CTFRULE_1A}${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kdebug.d
kdebug.o: $(SOURCE_DIR)/bsd/kern/kdebug.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_acct.d
kern_acct.o: $(SOURCE_DIR)/bsd/kern/kern_acct.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_aio.d
kern_aio.o: $(SOURCE_DIR)/bsd/kern/kern_aio.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_authorization.d
kern_authorization.o: $(SOURCE_DIR)/bsd/kern/kern_authorization.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_clock.d
kern_clock.o: $(SOURCE_DIR)/bsd/kern/kern_clock.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_core.d
kern_core.o: $(SOURCE_DIR)/bsd/kern/kern_core.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_credential.d
kern_credential.o: $(SOURCE_DIR)/bsd/kern/kern_credential.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_cs.d
kern_cs.o: $(SOURCE_DIR)/bsd/kern/kern_cs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_symfile.d
kern_symfile.o: $(SOURCE_DIR)/bsd/kern/kern_symfile.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_descrip.d
kern_descrip.o: $(SOURCE_DIR)/bsd/kern/kern_descrip.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_guarded.d
kern_guarded.o: $(SOURCE_DIR)/bsd/kern/kern_guarded.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_event.d
kern_event.o: $(SOURCE_DIR)/bsd/kern/kern_event.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_control.d
kern_control.o: $(SOURCE_DIR)/bsd/kern/kern_control.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_exec.d
kern_exec.o: $(SOURCE_DIR)/bsd/kern/kern_exec.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_exit.d
kern_exit.o: $(SOURCE_DIR)/bsd/kern/kern_exit.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_lockf.d
kern_lockf.o: $(SOURCE_DIR)/bsd/kern/kern_lockf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_fork.d
kern_fork.o: $(SOURCE_DIR)/bsd/kern/kern_fork.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_asl.d
kern_asl.o: $(SOURCE_DIR)/bsd/kern/kern_asl.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_malloc.d
kern_malloc.o: $(SOURCE_DIR)/bsd/kern/kern_malloc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_mman.d
kern_mman.o: $(SOURCE_DIR)/bsd/kern/kern_mman.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_physio.d
kern_physio.o: $(SOURCE_DIR)/bsd/kern/kern_physio.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_priv.d
kern_priv.o: $(SOURCE_DIR)/bsd/kern/kern_priv.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_proc.d
kern_proc.o: $(SOURCE_DIR)/bsd/kern/kern_proc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_prot.d
kern_prot.o: $(SOURCE_DIR)/bsd/kern/kern_prot.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_resource.d
kern_resource.o: $(SOURCE_DIR)/bsd/kern/kern_resource.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_shutdown.d
kern_shutdown.o: $(SOURCE_DIR)/bsd/kern/kern_shutdown.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_sig.d
kern_sig.o: $(SOURCE_DIR)/bsd/kern/kern_sig.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_subr.d
kern_subr.o: $(SOURCE_DIR)/bsd/kern/kern_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_synch.d
kern_synch.o: $(SOURCE_DIR)/bsd/kern/kern_synch.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_sysctl.d
kern_sysctl.o: $(SOURCE_DIR)/bsd/kern/kern_sysctl.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_newsysctl.d
kern_newsysctl.o: $(SOURCE_DIR)/bsd/kern/kern_newsysctl.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_memorystatus.d
kern_memorystatus.o: $(SOURCE_DIR)/bsd/kern/kern_memorystatus.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_mib.d
kern_mib.o: $(SOURCE_DIR)/bsd/kern/kern_mib.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_mbuf.d
kpi_mbuf.o: $(SOURCE_DIR)/bsd/kern/kpi_mbuf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_time.d
kern_time.o: $(SOURCE_DIR)/bsd/kern/kern_time.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_xxx.d
kern_xxx.o: $(SOURCE_DIR)/bsd/kern/kern_xxx.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_process.d
mach_process.o: $(SOURCE_DIR)/bsd/kern/mach_process.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mcache.d
mcache.o: $(SOURCE_DIR)/bsd/kern/mcache.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include spl.d
spl.o: $(SOURCE_DIR)/bsd/kern/spl.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include subr_log.d
subr_log.o: $(SOURCE_DIR)/bsd/kern/subr_log.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include subr_prf.d
subr_prf.o: $(SOURCE_DIR)/bsd/kern/subr_prf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include subr_prof.d
subr_prof.o: $(SOURCE_DIR)/bsd/kern/subr_prof.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include subr_sbuf.d
subr_sbuf.o: $(SOURCE_DIR)/bsd/kern/subr_sbuf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include subr_xxx.d
subr_xxx.o: $(SOURCE_DIR)/bsd/kern/subr_xxx.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sys_generic.d
sys_generic.o: $(SOURCE_DIR)/bsd/kern/sys_generic.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sys_pipe.d
sys_pipe.o: $(SOURCE_DIR)/bsd/kern/sys_pipe.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sys_socket.d
sys_socket.o: $(SOURCE_DIR)/bsd/kern/sys_socket.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sys_domain.d
sys_domain.o: $(SOURCE_DIR)/bsd/kern/sys_domain.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include syscalls.d
syscalls.o: syscalls.c
	${C_RULE_0}
	${C_RULE_1A}${C_RULE_1B}
	${C_CTFRULE_1A}${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tty.d
tty.o: $(SOURCE_DIR)/bsd/kern/tty.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tty_compat.d
tty_compat.o: $(SOURCE_DIR)/bsd/kern/tty_compat.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tty_conf.d
tty_conf.o: $(SOURCE_DIR)/bsd/kern/tty_conf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tty_pty.d
tty_pty.o: $(SOURCE_DIR)/bsd/kern/tty_pty.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tty_ptmx.d
tty_ptmx.o: $(SOURCE_DIR)/bsd/kern/tty_ptmx.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tty_subr.d
tty_subr.o: $(SOURCE_DIR)/bsd/kern/tty_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include tty_tty.d
tty_tty.o: $(SOURCE_DIR)/bsd/kern/tty_tty.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ubc_subr.d
ubc_subr.o: $(SOURCE_DIR)/bsd/kern/ubc_subr.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_domain.d
uipc_domain.o: $(SOURCE_DIR)/bsd/kern/uipc_domain.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_mbuf.d
uipc_mbuf.o: $(SOURCE_DIR)/bsd/kern/uipc_mbuf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_mbuf2.d
uipc_mbuf2.o: $(SOURCE_DIR)/bsd/kern/uipc_mbuf2.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_proto.d
uipc_proto.o: $(SOURCE_DIR)/bsd/kern/uipc_proto.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_socket.d
uipc_socket.o: $(SOURCE_DIR)/bsd/kern/uipc_socket.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_socket2.d
uipc_socket2.o: $(SOURCE_DIR)/bsd/kern/uipc_socket2.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_syscalls.d
uipc_syscalls.o: $(SOURCE_DIR)/bsd/kern/uipc_syscalls.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include uipc_usrreq.d
uipc_usrreq.o: $(SOURCE_DIR)/bsd/kern/uipc_usrreq.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sysv_ipc.d
sysv_ipc.o: $(SOURCE_DIR)/bsd/kern/sysv_ipc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sysv_shm.d
sysv_shm.o: $(SOURCE_DIR)/bsd/kern/sysv_shm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sysv_sem.d
sysv_sem.o: $(SOURCE_DIR)/bsd/kern/sysv_sem.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sysv_msg.d
sysv_msg.o: $(SOURCE_DIR)/bsd/kern/sysv_msg.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_fat.d
mach_fat.o: $(SOURCE_DIR)/bsd/kern/mach_fat.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mach_loader.d
mach_loader.o: $(SOURCE_DIR)/bsd/kern/mach_loader.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include posix_sem.d
posix_sem.o: $(SOURCE_DIR)/bsd/kern/posix_sem.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include posix_shm.d
posix_shm.o: $(SOURCE_DIR)/bsd/kern/posix_shm.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include qsort.d
qsort.o: $(SOURCE_DIR)/bsd/kern/qsort.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_socket.d
kpi_socket.o: $(SOURCE_DIR)/bsd/kern/kpi_socket.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kpi_socketfilter.d
kpi_socketfilter.o: $(SOURCE_DIR)/bsd/kern/kpi_socketfilter.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include pthread_shims.d
pthread_shims.o: $(SOURCE_DIR)/bsd/kern/pthread_shims.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include proc_info.d
proc_info.o: $(SOURCE_DIR)/bsd/kern/proc_info.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include process_policy.d
process_policy.o: $(SOURCE_DIR)/bsd/kern/process_policy.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_overrides.d
kern_overrides.o: $(SOURCE_DIR)/bsd/kern/kern_overrides.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_pressure.d
vm_pressure.o: $(SOURCE_DIR)/bsd/kern/vm_pressure.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include socket_info.d
socket_info.o: $(SOURCE_DIR)/bsd/kern/socket_info.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vnode_pager.d
vnode_pager.o: $(SOURCE_DIR)/bsd/vm/vnode_pager.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_unix.d
vm_unix.o: $(SOURCE_DIR)/bsd/vm/vm_unix.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dp_backing_file.d
dp_backing_file.o: $(SOURCE_DIR)/bsd/vm/dp_backing_file.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include vm_compressor_backing_file.d
vm_compressor_backing_file.o: $(SOURCE_DIR)/bsd/vm/vm_compressor_backing_file.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/vm/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/vm/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ux_exception.d
ux_exception.o: $(SOURCE_DIR)/bsd/uxkern/ux_exception.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/uxkern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/uxkern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include param.d
param.o: $(SOURCE_DIR)/bsd/conf/param.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/conf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/conf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include ioconf.d
ioconf.o: ioconf.c
	${C_RULE_0}
	${C_RULE_1A}${C_RULE_1B}
	${C_CTFRULE_1A}${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_bsd_callback.d
chud_bsd_callback.o: $(SOURCE_DIR)/bsd/dev/chud/chud_bsd_callback.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/chud/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/chud/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include chud_process.d
chud_process.o: $(SOURCE_DIR)/bsd/dev/chud/chud_process.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/chud/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/chud/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include imageboot.d
imageboot.o: $(SOURCE_DIR)/bsd/kern/imageboot.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kperfbsd.d
kperfbsd.o: $(SOURCE_DIR)/osfmk/kperf/kperfbsd.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/osfmk/kperf/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_kpc.d
kern_kpc.o: $(SOURCE_DIR)/bsd/kern/kern_kpc.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include proc_uuid_policy.d
proc_uuid_policy.o: $(SOURCE_DIR)/bsd/kern/proc_uuid_policy.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include conf.d
conf.o: $(SOURCE_DIR)/bsd/dev/i386/conf.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include cons.d
cons.o: $(SOURCE_DIR)/bsd/dev/i386/cons.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include mem.d
mem.o: $(SOURCE_DIR)/bsd/dev/i386/mem.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include km.d
km.o: $(SOURCE_DIR)/bsd/dev/i386/km.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include kern_machdep.d
kern_machdep.o: $(SOURCE_DIR)/bsd/dev/i386/kern_machdep.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include memmove.d
memmove.o: $(SOURCE_DIR)/bsd/dev/i386/memmove.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include stubs.d
stubs.o: $(SOURCE_DIR)/bsd/dev/i386/stubs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include systemcalls.d
systemcalls.o: $(SOURCE_DIR)/bsd/dev/i386/systemcalls.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sysctl.d
sysctl.o: $(SOURCE_DIR)/bsd/dev/i386/sysctl.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include unix_signal.d
unix_signal.o: $(SOURCE_DIR)/bsd/dev/i386/unix_signal.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dtrace_isa.d
dtrace_isa.o: $(SOURCE_DIR)/bsd/dev/i386/dtrace_isa.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dtrace_subr_x86.d
dtrace_subr_x86.o: $(SOURCE_DIR)/bsd/dev/i386/dtrace_subr_x86.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include fbt_x86.d
fbt_x86.o: $(SOURCE_DIR)/bsd/dev/i386/fbt_x86.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include sdt_x86.d
sdt_x86.o: $(SOURCE_DIR)/bsd/dev/i386/sdt_x86.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include fasttrap_isa.d
fasttrap_isa.o: $(SOURCE_DIR)/bsd/dev/i386/fasttrap_isa.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include instr_size.d
instr_size.o: $(SOURCE_DIR)/bsd/dev/i386/instr_size.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include dis_tables.d
dis_tables.o: $(SOURCE_DIR)/bsd/dev/i386/dis_tables.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/dev/i386/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include policy_check.d
policy_check.o: $(SOURCE_DIR)/bsd/kern/policy_check.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include bsd_stubs.d
bsd_stubs.o: $(SOURCE_DIR)/bsd/kern/bsd_stubs.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/kern/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/kern/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include cpu_in_cksum.d
cpu_in_cksum.o: $(SOURCE_DIR)/bsd/netinet/cpu_in_cksum.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}
-include in_cksum.d
in_cksum.o: $(SOURCE_DIR)/bsd/netinet/in_cksum.c
	${C_RULE_0}
	${C_RULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_RULE_1B}
	${C_CTFRULE_1A}$(SOURCE_DIR)/bsd/netinet/${C_CTFRULE_1B}
	${C_RULE_2}
	${C_CTFRULE_2}

include $(MakeInc_rule)
include $(MakeInc_dir)
