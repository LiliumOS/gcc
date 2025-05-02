/* Definitions for systems using the Lilium kernel and variants.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#undef TARGET_LIBC_HAS_FUNCTION
#define TARGET_LIBC_HAS_FUNCTION no_c99_libc_has_function

#if (!(LILIUM_NO_LIBUSI))
#define LILIUM_STARTFILE_SPEC "%{!shared:--whole-archive -lusi-init --no-whole-archive}"

#define LILIUM_ENDFILE_SPEC "" // There are no endfiles - all initialization is handled by libusi-init.a

#define LILIUM_TARGET_LIB_SPEC "-lc -lusi"

#else
#define LILIUM_STARTFILE_SPEC ""
#define LILIUM_ENDFILE_SPEC ""
#define LILIUM_TARGET_LIB_SPEC ""
#endif
#undef STARTFILE_SPEC
#define STARTFILE_SPEC LILIUM_STARTFILE_SPEC
#undef ENDFILE_SPEC
#define ENDFILE_SPEC LILIUM_ENDFILE_SPEC
#undef LIB_SPEC
#define LIB_SPEC LILIUM_TARGET_LIB_SPEC

#ifndef LILIUM_DYNAMIC_LINKER
#if (!(LILIUM_USE_KERNEL_LDSO))
#define LILIUM_DYNAMIC_LINKER "/lib/ld-lilium-" LILIUM_LDSO_ARCH ".so.1"
#else
#define LILIUM_DYNAMIC_LINKER "/lilium-loader-" LILIUM_LDSO_ARCH ".so"
#endif
#endif

#undef CPP_SPEC
#define CPP_SPEC "-D_LILIUM=1"
