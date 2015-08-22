/* vim: tabstop=4 shiftwidth=4 noexpandtab
 * This file was adapted from kernel/cpu/irq.c in the ToAruOS source.
 * This file is part of ToaruOS and is released under the terms
 * of the NCSA / University of Illinois License - see below
 * Copyright (C) 2011-2014 Kevin Lange
 * Copyright (C) 2015 Dale Weiler
 *
 Copyright (c) 2011-2015 Kevin Lange.  All rights reserved.

                          Dedicated to the memory of
                               Dennis Ritchie
                                  1941-2011

Developed by: ToAruOS Kernel Development Team
              http://toaruos.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal with the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimers.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimers in the
     documentation and/or other materials provided with the distribution.
  3. Neither the names of the ToAruOS Kernel Development Team, Kevin Lange,
     nor the names of its contributors may be used to endorse
     or promote products derived from this Software without specific prior
     written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
WITH THE SOFTWARE.
 *
 */

#define PIC1           0x20
#define PIC1_COMMAND   PIC1
#define PIC1_OFFSET    0xD0
#define PIC1_DATA      (PIC1+1)

#define PIC2           0xA0
#define PIC2_COMMAND   PIC2
#define PIC2_OFFSET    0xD8
#define PIC2_DATA      (PIC2+1)

#define PIC_EOI        0x20

#define ICW1_ICW4      0x01
#define ICW1_INIT      0x10

#define PIC_WAIT() \
	do { \
		/* May be fragile */ \
		asm volatile("jmp 1f\n\t" \
		             "1:\n\t" \
		             "    jmp 2f\n\t" \
		             "2:"); \
	} while (0)

static inline void outb_inline(unsigned short _port, unsigned char _data) {
	asm volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void _lapic_irq_remap(void) __attribute__((noinline));
void _lapic_irq_remap(void) {
	/* Cascade initialization */
	outb_inline(PIC1_COMMAND, ICW1_INIT|ICW1_ICW4); PIC_WAIT();
	outb_inline(PIC2_COMMAND, ICW1_INIT|ICW1_ICW4); PIC_WAIT();

	/* Remap */
	outb_inline(PIC1_DATA, PIC1_OFFSET); PIC_WAIT();
	outb_inline(PIC2_DATA, PIC2_OFFSET); PIC_WAIT();

	/* Cascade identity with slave PIC at IRQ2 */
	outb_inline(PIC1_DATA, 0x04); PIC_WAIT();
	outb_inline(PIC2_DATA, 0x02); PIC_WAIT();

	/* Request 8086 mode on each PIC */
	outb_inline(PIC1_DATA, 0x01); PIC_WAIT();
	outb_inline(PIC2_DATA, 0x01); PIC_WAIT();

	extern void kprintf(const char *, ...);
	kprintf("IRQ remap complete\n");
}
