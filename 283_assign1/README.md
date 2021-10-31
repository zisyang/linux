# CMPE 283 Assignment 1
## Questions to be answered
1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. (You may skip this question if you are doing the lab by yourself).
- Ans: all works done by myself.
2. Describe in detail the steps you used to complete the assignment. Consider your reader to be someone skilled in software development but otherwise unfamiliar with the assignment. Good answers to this question will be recipes that someone can follow to reproduce your development steps.
Note: I may decide to follow these instructions for random assignments, so you should make sure they are accurate.
- Ans: Steps shown as below

# How to run
1. First create a VM using VMWare Fusion (Mac User)
    - for my case, I put 2 cores for processors and 4096MB for Memory
2. Install Ubuntu Live Server 20.04 LTS into the VM
3. After the installation, turn off the VM and go to the VM Settings menu
    - turn on or check "Enable hypervisor applications in this Virtual Machine" or something simliar
4. After done settings, turn back on the VM, and run below commands after login:
    ```
    cat /proc/cpuinfo 
    ```
    or
    ```
    cat /proc/cpuinfo | grep vmx
    ```
    Check if the VMX flag has enabled.
5. Assume the required system components have been installed, otherwise, please run below, some of them are optional depending on the system.
    ```
    sudo apt update
    sudo apt install gcc make
    sudo apt install linux-source
    sudo apt install build-essential
    sudo apt install flex bison
    sudo apt install openssl libssl-dev libelf-dev
    sudo apt install git snap
    sudo snap install gh
    sudo reboot
    ```
6. Assume Github CLI or git have been installed and configured to your github account, please run below to clone the code:
    ```
    git clone git@github.com:zisyang/linux.git
    ```
    or download the zip file from https://github.com/zisyang/linux
7. After clone or download the code, 
    ```
    cd linux
    cp -v /boot/config-$(uname -r) .config
    make oldconfig  ## hit enter for many many times
    make prepare
    scripts/config --set-str SYSTEM_TRUSTED_KEYS ""
    make -j $(nproc) modules
    ```
8. Make modules would spend very very long, but after complete, then
    ```
    make -j $(nproc)
    ```
    this would also take very very long time. 
9. After make complete successfully, a message shown "Kernel: arch/x86/boot/bzImage is ready", then
    ```
    sudo make INSTALL_MOD_STRIP=1 modules_install
    ```
    This can reduce the kernel build size that ignore the debug information.
    Then,
    ```
    sudo make install
    ```
    and finallly,
    ```
    sudo reboot
    ```
10. After the VM reboot, log back in and check the new kernel applied. Version is 5.15.0-rc7
11. cd into the assignment code folder,
    ```
    cd linux/283_assign1
    ls
    ```
    Verify that it contains the following files:
    ```
    cmpe283-1.c
    Makefile
    README.md
    ```
    Now, to compile the code, please run:
    ```
    make
    ```
    There shouldn't be any error. Then,
    ```
    sudo insmod cmpe283-1.ko
    ```
    It should also complete without error. Then,
    ```
    dmesg
    sudo rmmod cmpe283_1
    ```

## output for dmesg
```
[23725.194237] CMPE 283 Assignment 1 Module Start
[23725.194245] Pinbased Controls MSR: 0x3f00000016
[23725.194248]   External Interrupt Exiting: Can set=Yes, Can clear=Yes
[23725.194249]   NMI Exiting: Can set=Yes, Can clear=Yes
[23725.194250]   Virtual NMIs: Can set=Yes, Can clear=Yes
[23725.194250]   Activate VMX Preemption Timer: Can set=No, Can clear=Yes
[23725.194251]   Process Posted Interrupts: Can set=No, Can clear=Yes
[23725.194252] Procbased Controls MSR: 0xfff9fffe0401e172
[23725.194253]   Interrupt-window exiting: Can set=Yes, Can clear=Yes
[23725.194254]   Use TSC offsetting: Can set=Yes, Can clear=Yes
[23725.194255]   HLT exiting: Can set=Yes, Can clear=Yes
[23725.194255]   INVLPG exiting: Can set=Yes, Can clear=Yes
[23725.194857]   MWAIT exiting: Can set=Yes, Can clear=Yes
[23725.194867]   RDPMC exiting: Can set=Yes, Can clear=Yes
[23725.194868]   RDTSC exiting: Can set=Yes, Can clear=Yes
[23725.194868]   CR3-load exiting: Can set=Yes, Can clear=No
[23725.194869]   CR3-store exiting: Can set=Yes, Can clear=No
[23725.194870]   CR8-load exiting: Can set=Yes, Can clear=Yes
[23725.194870]   CR8-store exiting: Can set=Yes, Can clear=Yes
[23725.194871]   Use TPR shadow: Can set=Yes, Can clear=Yes
[23725.194872]   NMI-window exiting: Can set=Yes, Can clear=Yes
[23725.194872]   MOV-DR exiting: Can set=Yes, Can clear=Yes
[23725.194873]   Unconditional I/O exiting: Can set=Yes, Can clear=Yes
[23725.194873]   Use I/O bitmaps: Can set=Yes, Can clear=Yes
[23725.194874]   Monitor trap flag: Can set=Yes, Can clear=Yes
[23725.194875]   Use MSR bitmaps: Can set=Yes, Can clear=Yes
[23725.194875]   MONITOR exiting: Can set=Yes, Can clear=Yes
[23725.194876]   PAUSE exiting: Can set=Yes, Can clear=Yes
[23725.194876]   Activate secondary controls: Can set=Yes, Can clear=Yes
[23725.194878] Secondary Procbased Controls MSR: 0x408fe00000000
[23725.194880]   Virtualize APIC accesses: Can set=No, Can clear=Yes
[23725.194880]   Enable EPT: Can set=Yes, Can clear=Yes
[23725.194881]   Descriptor-table exiting: Can set=Yes, Can clear=Yes
[23725.194882]   Enable RDTSCP: Can set=Yes, Can clear=Yes
[23725.194882]   Virtualize x2APIC mode: Can set=Yes, Can clear=Yes
[23725.194883]   Enable VPID: Can set=Yes, Can clear=Yes
[23725.195260]   WBINVD exiting: Can set=Yes, Can clear=Yes
[23725.195260]   Unrestricted guest: Can set=Yes, Can clear=Yes
[23725.195261]   APIC-register virtualization: Can set=No, Can clear=Yes
[23725.195262]   Virtual-interrupt delivery: Can set=No, Can clear=Yes
[23725.195262]   PAUSE-loop exiting: Can set=No, Can clear=Yes
[23725.195263]   RDRAND exiting: Can set=Yes, Can clear=Yes
[23725.195264]   Enable INVPCID: Can set=No, Can clear=Yes
[23725.195264]   Enable VM functions: Can set=No, Can clear=Yes
[23725.195265]   VMCS shadowing: Can set=No, Can clear=Yes
[23725.195266]   Enable ENCLS exiting: Can set=No, Can clear=Yes
[23725.195266]   RDSEED exiting: Can set=No, Can clear=Yes
[23725.195267]   Enable PML: Can set=No, Can clear=Yes
[23725.195276]   EPT-violation #VE: Can set=Yes, Can clear=Yes
[23725.195277]   Conceal VMX non-root operation from Intel PT: Can set=No, Can clear=Yes
[23725.195278]   Enable XSAVES/XRSTORS: Can set=No, Can clear=Yes
[23725.195278]   Mode-based execute control for EPT: Can set=No, Can clear=Yes
[23725.195279]   Use TSC scaling: Can set=No, Can clear=Yes
[23725.195281] Exit Controls MSR: 0x3fffff00036dff
[23725.195282]   Save debug controls: Can set=Yes, Can clear=No
[23725.195283]   Host address- space size: Can set=Yes, Can clear=Yes
[23725.195284]   Load IA32_PERF_GLOB AL_CTRL: Can set=Yes, Can clear=Yes
[23725.195284]   Acknowledge interrupt on exit: Can set=Yes, Can clear=Yes
[23725.195389]   Save IA32_PAT: Can set=Yes, Can clear=Yes
[23725.195390]   Load IA32_PAT: Can set=Yes, Can clear=Yes
[23725.195390]   Save IA32_EFER: Can set=Yes, Can clear=Yes
[23725.195391]   Load IA32_EFER: Can set=Yes, Can clear=Yes
[23725.195392]   Save VMX- preemption timer value: Can set=No, Can clear=Yes
[23725.195393]   Clear IA32_BNDCFGS: Can set=No, Can clear=Yes
[23725.195393]   Conceal VM exits from Intel PT: Can set=No, Can clear=Yes
[23725.195395] Entry Controls MSR: 0xf3ff000011ff
[23725.195396]   Load debug controls: Can set=Yes, Can clear=No
[23725.195397]   IA-32e mode guest: Can set=Yes, Can clear=Yes
[23725.195397]   Entry to SMM: Can set=No, Can clear=Yes
[23725.195398]   Deactivate dual-monitor treatment: Can set=No, Can clear=Yes
[23725.195399]   Load IA32_PERF_GLOBA L_CTRL: Can set=Yes, Can clear=Yes
[23725.195399]   Load IA32_PAT: Can set=Yes, Can clear=Yes
[23725.195400]   Load IA32_EFER: Can set=Yes, Can clear=Yes
[23725.195695]   Load IA32_BNDCFGS: Can set=No, Can clear=Yes
[23725.195701]   Conceal VM entries from Intel PT: Can set=No, Can clear=Yes
[23726.212478] CMPE 283 Assignment 1 Module Exits
```

12. That's all. Thanks!