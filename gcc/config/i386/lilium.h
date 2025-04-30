
#define LILIUM_LINK_SPEC \
    "%{" SPEC_64 ":-m " GNU_USER_LINK_EMULATION64 "} \
                   %{" SPEC_32 ":-m " GNU_USER_LINK_EMULATION32 "} \
                   %{" SPEC_X32 ":-m " GNU_USER_LINK_EMULATIONX32 "} \
  %{shared:-shared} \
  %{!shared: \
    %{!static: \
      %{!static-pie: \
	%{rdynamic:-export-dynamic} \
	%{" SPEC_32 ":-dynamic-linker " LILIUM_DYNAMIC_LINKER "} \
    %{static:-static} %{static-pie:-static -pie --no-dynamic-linker -z text}}"

#undef LINK_SPEC
#define LINK_SPEC LILIUM_LINK_SPEC