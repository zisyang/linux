# CMPE 283 Assignment - 3

## Zi Shun Yang(007562568):
* Setup to create a nested VM for the program to execute
* Built the linux kernel 
* Made code modifications on vmx.c file
* Debugged and performed the required changes to fix the errors which occurred while compiling the code

## Rohan Patel(010745904):
* Helped build the kernel and debugged errors while building the linux kernel 
* Made code modifications on cpuid.c file
* Error handling while performing the compilation
* Tester code for running tests

### Steps executed to complete the assignment:
  * In cpuid.c file, 
    1. add two global arrays: 
       * exits_per_reason[70]: to calculate the total number of exits for the exit number provided (on input) in %ecx;
       * total_time_spent_per_reason[70]: to count the total time spent processing the exit number (on input) in %ecx;
     1. modify the function kvm_emulate_cpuid(...) to report back the information when below CPUID leaf nodes code in EAX are met:
       * read the number of total exits for the exit number provided on input while EAX is 0x4FFFFFFD;
       * read the number of total time spent processing the exit number provided on input while EAX is 0x4FFFFFFC;
  * In vmx.c file, 
    1. declare two global arrays from external: 
       * exits_per_reason[]: counter to count how many times exit reason is handled for each exit reason; 
       * total_time_spent_per_reason[]: calculate the processing time of __vmx_handle_exit for each exit reason;
    2. modify the function __vmx_handle_exit(...) to increase the exit counter exits_per_reason[#exit_reason] for each exit reason;
    3. modify the funciton vmx_handle_exit(...) to accumulate the processing time of each exit reason to total_time_spent_per_reason[#exit_reason];
  * please refer to [Steps to follow].

### Question 3 ~ Comment on the frequency of exits – does the number of exits increase at a stable rate? Or are there more exits performed during certain VM operations? Approximately how many exits does a full VM boot entail?
- Most of the exits increase at a non stable rate, but from what obvserved, there's one exit increase at a stable rate. Full VM boot entail about 1532384 exits.

### Question 4 ~ Of the exit types defined in the SDM, which are the most frequent? Least?
- Most Frequent:
    * exit number 48 : EPT violation
    * exit number 30 : I/O instruction
    * exit number 10 : CPUID
- Least Frequent:
    * exit number 2 : Triple fault
    * exit number 3 : INIT signal
    * exit number 8 : NMI window
    * exit number 9 : Task switch
    * exit number 13 : INVD
    * exit number 14 : INVLPG
    * exit number 15 : RDPMC
    * exit number 16 : RDTSC
    * exit number 18 : VMCALL
    * exit number 19 : VMCLEAR
    * exit number 20 : VMLAUNCH
    * exit number 21 : VMPTRLD
    * exit number 22 : VMPTRST
    * exit number 23 : VMREAD
    * exit number 24 : VMRESUME
    * exit number 25 : VMWRITE
    * exit number 26 : VMXOFF
    * exit number 27 : VMXON
    * exit number 33 : VM-entry failure due to invalid guest state
    * exit number 34 : VM-entry failure due to MSR loading
    * exit number 36 : MWAIT
    * exit number 37 : Monitor trap flag
    * exit number 39 : MONITOR
    * exit number 41 : VM-entry failure due to machine-check event
    * exit number 43 : TPR below threshold
    * exit number 44 : APIC access
    * exit number 45 : Virtualized EOI
    * exit number 46 : Access to GDTR or IDTR
    * exit number 47 : Access to LDTR or TR
    * exit number 50 : INVEPT
    * exit number 51 : RDTSCP
    * exit number 52 : VMX-preemption timer expired
    * exit number 53 : INVVPID
    * exit number 56 : APIC write
    * exit number 57 : RDRAND
    * exit number 58 : INVPCID
    * exit number 59 : VMFUNC
    * exit number 60 : ENCLS
    * exit number 61 : RDSEED
    * exit number 62 : Page-modification log full
    * exit number 63 : XSAVES
    * exit number 64 : XRSTORS
    * exit number 67 : UMWAIT
    * exit number 68 : TPAUSE


## Steps to follow:

1. Clone the repository:
```
$ git clone https://github.com/zisyang/linux.git
```
2. Build the linux kernel 
3. Verify the kernel version is below: 
```
Linux ubuntu 5.15.0-rc7 #1 SMP Sat Oct 30 17:31:38 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
```
4. Modify the code for CPUID leaf node in cpuid.c & vmx.c, download the files from this repository path and paste them to the cooresponding locations as shown below:
```
linux/arch/x86/kvm/cpuid.c
```
```
linux/arch/x86/kvm/vmx/vmx.c
```
5. Rebuild the module
```
make modules
sudo make INSTALL_MOD_STRIP=1 modules_install 
```
6. Verify if the old kvm modules loaded, if so, then remove it.
```
lsmod | grep kvm 
sudo rmmod kvm_intel kvm ## unload the old module
```
7. Insert the new built module
```
sudo modprobe kvm_intel
lsmod | grep kvm ## check if new one loaded
```
8. Install KVM packages by following the guide (URL: https://phoenixnap.com/kb/ubuntu-install-kvm)
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
9. Create a nested VM
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

10. Restart the nested VM, and get the IP to access it
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

11. Install CPUID package inside the nested VM
```
sudo apt install cpuid
```

12. for user test program, download the test_assignment3.c run the test as below:
```
# build the code
gcc test_assignment3.c
mv a.out test_assignment3

# test w/o parameter
./test_assignment3 

# test for certain type of exit reason
./test_assignment3 0
./test_assignment3 1
./test_assignment3 2
```


## Output from nested VM:
```
zy@ub:~$ ./test_assignment3 
CPUID(0x4FFFFFFF), exits=2286878
CPUID(0x4FFFFFFE), total time in vmm: 30553290010 cycles
zy@ub:~$ ./test_assignment3 0
CPUID(0x4FFFFFFD), exit number 0 exits=6741
CPUID(0x4FFFFFFC), exit number 0 time in vmm: 1026320488 cycles
zy@ub:~$ ./test_assignment3 1
CPUID(0x4FFFFFFD), exit number 1 exits=8750
CPUID(0x4FFFFFFC), exit number 1 time in vmm: 1163587 cycles
zy@ub:~$ ./test_assignment3 2
CPUID(0x4FFFFFFD), exit number 2 exits=0
CPUID(0x4FFFFFFC), exit number 2 time in vmm: 0 cycles
```
