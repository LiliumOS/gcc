
#if TARGET_64BIT_DEFAULT
#define LILIUM_TARGET_EMUL "elf_x86_64"
#else
#define LILIUM_TARGET_EMUL "elf_i386"
#endif

#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS               \
  {"link_emulation", LILIUM_TARGET_EMUL},   \
  {                                         \
    "dynamic_linker", LILIUM_DYNAMIC_LINKER \
  }

#define LILIUM_LINK_SPEC "-m %(link_emulation) %{shared:-shared} \
  %{!shared: \
    %{!static: \
      %{!static-pie: \
	%{rdynamic:-export-dynamic} \
  %{!no-pie:-pie} \
	-dynamic-linker %(dynamic_linker)}} \
    %{static:-static} %{static-pie:-static -pie --no-dynamic-linker -z text}}"

#undef LINK_SPEC
#define LINK_SPEC LILIUM_LINK_SPEC

#undef SHIFT_DOUBLE_OMITS_COUNT
#define SHIFT_DOUBLE_OMITS_COUNT 0

#undef ASM_APP_ON
#define ASM_APP_ON "#APP\n"

#undef ASM_APP_OFF
#define ASM_APP_OFF "#NO_APP\n"

#undef GLOBAL_ASM_OP
#define GLOBAL_ASM_OP "\t.global\t"