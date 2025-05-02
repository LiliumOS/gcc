
#if TARGET_64BIT_DEFAULT
#define LILIUM_TARGET_EMUL "elf_x86_64"
#else
#define LILIUM_TARGET_EMUL "elf_i386"
#endif

#define LILIUM_LINK_SPEC \
  "%{64|32:-m " LILIUM_TARGET_EMUL "} \
  %{shared:-shared} \
  %{!shared: \
    %{!static: \
      %{!static-pie: \
	%{rdynamic:-export-dynamic} \
	%{ -dynamic-linker " LILIUM_DYNAMIC_LINKER "} \
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