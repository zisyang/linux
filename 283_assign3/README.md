# CMPE 283 Assignment - 3

## Zi Shun Yang(007562568):

## Rohan Patel(010745904):


### Steps executed to complete the assignment:
  * In cpuid.c file, 
    1. add two global arrays: 
       * exits_per_reason[]: to calculate the total number of exits for each exit reason;
       * total_time_spent_per_reason[]: to count the total values are measured in processor cycles across all VCPUs for each exit reason;
    2. modify the function kvm_emulate_cpuid(...) to report back the information when below CPUID leaf nodes code in EAX are met:
       * read the number of exits for specific reason provided by ECX, when EAX is 0x4FFFFFFD;
       * read the number of total time spent processing for certain exits provided by ECX when EAX is 0x4FFFFFFC;
       * assign specific flag values to all registers for certain types of exit that are not defined by the SDM or not enabled in KVM;
  * In vmx.c file, 
    1. declare two global arrays from external: 
       * exits_per_reason[]: counter to count how many time the exit handler got called for each exit reason; 
       * total_time_spent_per_reason[]: calculate the total processing time of __vmx_handle_exit for each type of exit reason;
    2. modify the function __vmx_handle_exit(...) to increase the exit counter array exits_per_reason[] for each type of reason;
    3. modify the funciton vmx_handle_exit(...) to calcuate the processing time of each exit to array total_time_spent_per_reason[] for each exit reason;
  * please refer to [Steps to follow].
  
3. 
4. 

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

# show usage
./test_assignment3 
Usage: ./test_assignment3 [number]

# test for certain type of exit reason
./test_assignment3 0
CPUID(0x4FFFFFFD|0x4FFFFFFC), exit number 0 exits=6741
CPUID(0x4FFFFFFC), exit number 0 time in vmm: 1026320488 cycles
```


## Output for dmesg from host VM:
```
zy@ub:~$ ./test_assignment3 0
CPUID(0x4FFFFFFD|0x4FFFFFFC), exit number 0 exits=6741
CPUID(0x4FFFFFFC), exit number 0 time in vmm: 1026320488 cycles
zy@ub:~$ ./test_assignment3 1
CPUID(0x4FFFFFFD|0x4FFFFFFC), exit number 1 exits=8750
CPUID(0x4FFFFFFC), exit number 1 time in vmm: 1163587 cycles
zy@ub:~$ ./test_assignment3 2
CPUID(0x4FFFFFFD|0x4FFFFFFC), exit number 2 exits=0
CPUID(0x4FFFFFFC), exit number 2 time in vmm: 0 cycles
```
