/*
 * Copyright (c) 2006 Apple Computer, Inc. All Rights Reserved.
 * 
 * @APPLE_LICENSE_OSREFERENCE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code 
 * as defined in and that are subject to the Apple Public Source License 
 * Version 2.0 (the 'License'). You may not use this file except in 
 * compliance with the License.  The rights granted to you under the 
 * License may not be used to create, or enable the creation or 
 * redistribution of, unlawful or unlicensed copies of an Apple operating 
 * system, or to circumvent, violate, or enable the circumvention or 
 * violation of, any terms of an Apple operating system software license 
 * agreement.
 *
 * Please obtain a copy of the License at 
 * http://www.opensource.apple.com/apsl/ and read it before using this 
 * file.
 *
 * The Original Code and all software distributed under the License are 
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER 
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, 
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. 
 * Please see the License for the specific language governing rights and 
 * limitations under the License.
 *
 * @APPLE_LICENSE_OSREFERENCE_HEADER_END@
 */
/*
 * CLDeny.c
 *
 * From	Mike Shoemaker 9/6/90
 *   Modified, April 9, 1997 by Tuyen Nguyen for MacOSX.
 */

#include <sys/errno.h>
#include <sys/types.h>
#include <sys/param.h>
#include <machine/spl.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/proc.h>
#include <sys/filedesc.h>
#include <sys/fcntl.h>
#include <sys/mbuf.h>
#include <sys/socket.h>

#include <netat/sysglue.h>
#include <netat/appletalk.h>
#include <netat/ddp.h>
#include <netat/at_pcb.h>
#include <netat/debug.h>
#include <netat/adsp.h>
#include <netat/adsp_internal.h>

/*
 * dspCLDeny
 * 
 * INPUTS:
 * 	--> ccbRefNum		refnum of connection listener
 *	--> remoteCID		connection identifier of remote connection end
 *	--> remoteAddress	internet address of remote connection end
 *
 * OUTPUTS:
 *	none
 *
 * ERRORS:
 *	errRefNum	 	bad connection refnum
 *	errState		not a connection listener
 *	errAborted		request aborted by a Remove call
 */
int adspCLDeny(struct adspcmd *pb, CCBPtr sp)
{
    gbuf_t *mp;
    ADSP_FRAMEPtr adspp;
    ADSP_OPEN_DATAPtr adspop;
	
    if (sp == 0) {
	pb->ioResult = errRefNum;
	return EINVAL;
    }
    mp = gbuf_alloc(AT_WR_OFFSET + DDPL_FRAME_LEN + ADSP_FRAME_LEN + ADSP_OPEN_FRAME_LEN,
		PRI_LO);
    gbuf_rinc(mp,AT_WR_OFFSET);
    gbuf_wset(mp,DDPL_FRAME_LEN);
    adspp = (ADSP_FRAMEPtr)gbuf_wptr(mp);
    gbuf_winc(mp,ADSP_FRAME_LEN);
    bzero((caddr_t) gbuf_rptr(mp),DDPL_FRAME_LEN + ADSP_FRAME_LEN + ADSP_OPEN_FRAME_LEN);
    adspp->descriptor = ADSP_CONTROL_BIT | ADSP_CTL_ODENY;
    adspop = (ADSP_OPEN_DATAPtr)gbuf_wptr(mp);
    gbuf_winc(mp,ADSP_OPEN_FRAME_LEN);
    UAS_ASSIGN(adspop->dstCID, pb->u.openParams.remoteCID);
    UAS_ASSIGN(adspop->version, 0x100);
    adsp_sendddp(sp, mp, 
		 DDPL_FRAME_LEN + ADSP_FRAME_LEN + ADSP_OPEN_FRAME_LEN, 
		 &pb->u.openParams.remoteAddress, DDP_ADSP);
    adspioc_ack(0, pb->ioc, pb->gref);
    return 0;
}
