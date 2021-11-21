# CMPE 283 Assignment 2
## Questions to be answered
1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. (You may skip this question if you are doing the lab by yourself).
- Ans: all works done by myself. 
2. Describe in detail the steps you used to complete the assignment. Consider your reader to be someone skilled in software development but otherwise unfamiliar with the assignment. Good answers to this question will be recipes that someone can follow to reproduce your development steps.
- Ans: Steps shown under [How to run] below.
3. for this assignment, I chose CPUID 0x4FFFFFFF & 0x4FFFFFFE, Question 3 & 4 will be skipped for this time.
4. skip as above.

# How to run
1. Clone my linux repository by using below command:
```
$ git clone https://github.com/zisyang/linux.git
```
2. Build the kernel from the first assignment 1, verify the kernel version is below: 
```
Linux ubuntu 5.15.0-rc7 #1 SMP Sat Oct 30 17:31:38 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
```
3. Modify the code for CPUID leaf node in below files:
```
linux/arch/x86/kvm/cpuid.c
```
```
linux/arch/x86/kvm/vmx/vmx.c
```




## output for dmesg
```
[45341.540472] virbr0: port 2(vnet0) entered learning state
[45343.560415] virbr0: port 2(vnet0) entered forwarding state
[45343.560421] virbr0: topology change detected, propagating
[45550.467153] CPUID(0x4FFFFFFF), exits=817346
[45554.124818] CPUID(0x4FFFFFFF), exits=817458
[45555.241615] CPUID(0x4FFFFFFF), exits=817533
[45560.442361] CPUID(0x4FFFFFFE), total time in vmm: 14402591322 cycles
[45560.442367]  --- (0x4FFFFFFE), registers: ebx=3, ecx=1517689434
[45562.846337] CPUID(0x4FFFFFFE), total time in vmm: 14403738732 cycles
[45562.846342]  --- (0x4FFFFFFE), registers: ebx=3, ecx=1518836844
[45563.564438] CPUID(0x4FFFFFFE), total time in vmm: 14404744237 cycles
[45563.564443]  --- (0x4FFFFFFE), registers: ebx=3, ecx=1519842349
[45564.269907] CPUID(0x4FFFFFFE), total time in vmm: 14406351518 cycles
[45564.269912]  --- (0x4FFFFFFE), registers: ebx=3, ecx=1521449630
[45596.883873] CPUID(0x4FFFFFFF), exits=818468
[45598.542785] CPUID(0x4FFFFFFF), exits=818550
[45600.316000] CPUID(0x4FFFFFFE), total time in vmm: 14417620369 cycles
[45600.316005]  --- (0x4FFFFFFE), registers: ebx=3, ecx=1532718481
zy@ubuntu:~/data/git/linux/283_assign2$ 
```

## output from nested VM
```
zy@ub:~$ cpuid -l 0x0
CPU 0:
   vendor_id = "GenuineIntel"
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x000c78c2 ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x000c7932 ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x000c797d ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000003 ecx=0x5a761a5a edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000003 ecx=0x5a879c6c edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000003 ecx=0x5a96f42d edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000003 ecx=0x5aaf7a9e edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x000c7d24 ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x000c7d76 ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000003 ecx=0x5b5b6d91 edx=0xffffba6c
zy@ub:~$ 
```
12. That's all. Thanks!
