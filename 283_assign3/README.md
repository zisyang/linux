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
    1. add two global variables: 
       * exits_per_reason[70]: to calculate the total number of exits for the exit number provided (on input) in %ecx;
       * total_time_spent_per_reason[70]: to count the total time spent processing the exit number (on input) in %ecx;
     1. modify the function kvm_emulate_cpuid(...) to report back the information when below CPUID leaf nodes code in EAX are met:
       * read the number of total exits for the exit number provided on input while EAX is 0x4FFFFFFD;
       * read the number of total time spent processing the exit number provided on input while EAX is 0x4FFFFFFC;
  * In vmx.c file, 
    1. declare two global variables from external: 
       * exits_per_reason: counter to count how many times exit reason is handled; 
       * total_time_spent_per_reason: calculate the total processing time of __vmx_handle_exit;
    2. modify the function __vmx_handle_exit(...) to increase the exit counter exits_per_reason[exit_reason.basic]++;
    3. modify the funciton vmx_handle_exit(...) to accumulate the processing time of each exit reason to variable total_time_spent_per_reason[exit_reason_basic];
  * please refer to [Steps to follow].

### Question 3 ~ Comment on the frequency of exits – does the number of exits increase at a stable rate? Or are there more exits performed during certain VM operations? Approximately how many exits does a full VM boot entail?
- 

### Question 4 ~ Of the exit types defined in the SDM, which are the most frequent? Least?
- 
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
4. Modify the code for CPUID leaf node in below files or download and use the files from this repository:
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

12. run the test using cpuid package
```
# test with leaf node 0 check if cpuid installed good
cpuid -l 0x0 

# test for how many times exit reason 0 is handled
cpuid -l 0x4FFFFFFD -s 0
# test for how much total time spent for processing exit reason 0
cpuid -l 0x4FFFFFFC -s 0
```
## Output for dmesg from host VM:

```

```

## Output from nested VM:

```

```
