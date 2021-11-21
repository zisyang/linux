# CMPE 283 Assignment 2
## Questions to be answered
1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. (You may skip this question if you are doing the lab by yourself).
- Ans: all works done by myself. 
2. Describe in detail the steps you used to complete the assignment. Consider your reader to be someone skilled in software development but otherwise unfamiliar with the assignment. Good answers to this question will be recipes that someone can follow to reproduce your development steps.
- Ans: Steps shown in [How to run].
3. for this assignment, I chose CPUID 0x4FFFFFFF & 0x4FFFFFFE, Question 3 & 4 will be skipped for this time.
4. skip as above.

# How to run
1. 
2.



## output for dmesg
```
[41041.775204] virbr0: port 2(vnet0) entered learning state
[41043.838718] virbr0: port 2(vnet0) entered forwarding state
[41043.838726] virbr0: topology change detected, propagating
[41605.341202] CPUID(0x4FFFFFFF), exits=2578298
[41609.238802] CPUID(0x4FFFFFFF), exits=2578459
[41612.056876] CPUID(0x4FFFFFFF), exits=2578563
[41613.794207] CPUID(0x4FFFFFFE), total time in vmm: 101380739188 cycles
[41613.794212]  --- (0x4FFFFFFE), registers: ebx=23, ecx=-1698475916
[41615.049413] CPUID(0x4FFFFFFE), total time in vmm: 101381798623 cycles
[41615.049418]  --- (0x4FFFFFFE), registers: ebx=23, ecx=-1697416481
[41615.886688] CPUID(0x4FFFFFFE), total time in vmm: 101382681874 cycles
[41615.886693]  --- (0x4FFFFFFE), registers: ebx=23, ecx=-1696533230
[41617.266328] CPUID(0x4FFFFFFE), total time in vmm: 101383608441 cycles
[41617.266333]  --- (0x4FFFFFFE), registers: ebx=23, ecx=-1695606663
[41621.934800] CPUID(0x4FFFFFFF), exits=2579008
[41623.396212] CPUID(0x4FFFFFFE), total time in vmm: 101387010285 cycles
[41623.396218]  --- (0x4FFFFFFE), registers: ebx=23, ecx=-1692204819
zy@ubuntu:~/data/git/linux$ 
```

## output from nested VM
```
zy@ub:~$ cpuid -l 0x0
CPU 0:
   vendor_id = "GenuineIntel"
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x0027577a ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x0027581b ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x00275883 ebx=0x00000000 ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000017 ecx=0x9ac35074 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000017 ecx=0x9ad37adf edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000017 ecx=0x9ae0f512 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000017 ecx=0x9aef1879 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04fffffff
CPU 0:
   0x4fffffff 0x00: eax=0x00275a40 ebx=0xffff9d9d ecx=0x00000000 edx=0xffffba6c
zy@ub:~$ cpuid -l 0x04ffffffe
CPU 0:
   0x4ffffffe 0x00: eax=0x4ffffffe ebx=0x00000017 ecx=0x9b2300ed edx=0xffffba6c
zy@ub:~$ 
```
12. That's all. Thanks!
