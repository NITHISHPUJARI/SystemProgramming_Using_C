cmd_/home/user/Downloads/Module3_SystemProgramming_Using_C/Module3_SystemProgramming_Using_C/Others/Module_6/Linux_drivers/modules.order := {   echo /home/user/Downloads/Module3_SystemProgramming_Using_C/Module3_SystemProgramming_Using_C/Others/Module_6/Linux_drivers/hello_module.ko;   echo /home/user/Downloads/Module3_SystemProgramming_Using_C/Module3_SystemProgramming_Using_C/Others/Module_6/Linux_drivers/hello_nass.ko; :; } | awk '!x[$$0]++' - > /home/user/Downloads/Module3_SystemProgramming_Using_C/Module3_SystemProgramming_Using_C/Others/Module_6/Linux_drivers/modules.order