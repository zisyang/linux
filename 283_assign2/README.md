##### CMPE 283 Assignment - 2

# Zi Shun Yang(007562568):
* Setup to create a nested VM for the program to execute
* Built the linux kernel 
* Made code modifications on cpuid.c file
* Debugged and performed the required changes to fix the errors which occurred while compiling the code
* Created Documentation

# Rohan Patel(010745904):
* Helped build the kernel and debugged errors while building the linux kernel 
* Made code modifications on vmx.c file
* Figured out how to perform tests for kernel
* Updated Documentation
* Error handling while performing the compilation

## Steps executed to complete the assignment:
  * In cpuid.c file, 
    1. add two global variables: 
       * total_exits_all_types: to calculate the total number of exits (all types);
       * total_time_spent_proc_exits: to count the total values are measured in processor cycles across all VCPUs;
     1. modify the function kvm_emulate_cpuid(...) to report back the information when below CPUID leaf nodes code in EAX are met:
       * read the number of total exits for all types while EAX is 0x4FFFFFFF;
       * read the number of total time spent processing all exits while EAX is 0x4FFFFFFE;
  * In vmx.c file, 
    1. declare two global variables from external: 
       * total_exits_all_types: counter to count how many time the exit handler got called; 
       * total_time_spent_proc_exits: calculate the total processing time of __vmx_handle_exit;
    2. modify the function __vmx_handle_exit(...) to increase the exit counter total_exits_all_types;
    3. modify the funciton vmx_handle_exit(...) to accumulate the processing time of each exit to variable total_time_spent_proc_exits;
  * please refer to [Steps to follow].
  
3. for this assignment, CPUID 0x4FFFFFFF & 0x4FFFFFFE, have been chosen. Question 3 & 4 will be skipped for this time.
4. skip as #3.

###### Steps to follow:

1. Clone the repository:
```
$ git clone https://github.com/zisyang/linux.git
```
2. Build the kernel from the first assignment 1, verify the kernel version is below: 
```
Linux ubuntu 5.15.0-rc7 #1 SMP Sat Oct 30 17:31:38 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
```
3. Modify the code for CPUID leaf node in below files or download and use the files from this repository:
```
linux/arch/x86/kvm/cpuid.c
```
```
linux/arch/x86/kvm/vmx/vmx.c
```
4. Rebuild the module
```
make modules
sudo make INSTALL_MOD_STRIP=1 modules_install 
```
5. Verify if the old kvm modules loaded, if so, then remove it.
```
lsmod | grep kvm 
sudo rmmod kvm_intel kvm ## unload the old module
```
6. Insert the new built module
```
sudo modprobe kvm_intel
lsmod | grep kvm ## check if new one loaded
```
7. Install KVM packages by following the guide (URL: https://phoenixnap.com/kb/ubuntu-install-kvm)
```
# Check Virtualization Support on Ubuntu 20.04
sudo apt install cpu-checker
sudo kvm-ok 

# Install KVM packages
sudo apt update 
sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils

# Authorize users
sudo adduser [username] libvirt
sudo adduser [username] kvm

# Verify the Installation
virsh list --all
sudo systemctl status libvirtd # check if it's running good, then press Q to quit the status screen
sudo systemctl enable --now libvirtd

# Prepare creating nested VM
sudo apt install virt-manager
```
8. Create a nested VM
```
# method 1: with GUI
sudo virt-manager
```
```
# method 2: without GUI
sudo virt-install \
--name=Ubtest1 \
--description='Ubuntu 18.04' \
--ram=1536 \
--vcpus=1 \
--disk pool=default,size=20,bus=virtio,format=qcow2 \
--os-type linux \
--os-variant ubuntu18.04 \
--network network:default \
--graphics none \
--console pty,target_type=serial \
--location 'http://gb.archive.ubuntu.com/ubuntu/dists/bionic/main/installer-amd64/' \
--extra-args 'console=ttyS0,115200n8 serial'  \
--force 
# during install, remember to install OpenSSH package when prompt
# after successfully install, press [Ctrl+Shift+] or open up a new ternmial to restart the nested VM
```

9. Restart the nested VM, and get the IP to access it
```
# a. restart
virsh destroy Ubtest1
virsh start Ubtest1

# b. get MAC address
virsh domiflist Ubtest1 

# c. get IP address
arp -an | grep <MAC> ## <MAC> is the result from b.

# d. ssh into it
ssh <user>@<IP> ## <user> is user created during installation, <IP> is the result from c.
```

10. Install CPUID package inside the nested VM
```
sudo apt install cpuid
```

11. run the test using cpuid package
```
# test with leaf node 0 check if cpuid installed good
cpuid -l 0x0 

# test for how many total exits
cpuid -l 0x4fffffff 

# test for how many total time spent for processing exits
cpuid -l 0x4ffffffe 
```


## Output for dmesg from host VM:
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

## Output from nested VM:
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
