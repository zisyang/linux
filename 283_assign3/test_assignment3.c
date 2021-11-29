/*
*   Assignment -3 test program
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

static inline void
__cpuid(unsigned int *eax, unsigned int *ebx, unsigned int *ecx,
        unsigned int *edx)
{
    asm volatile("cpuid"
                 : "=a"(*eax),
                   "=b"(*ebx),
                   "=c"(*ecx),
                   "=d"(*edx)
                 : "0"(*eax), "1"(*ebx), "2"(*ecx), "3"(*edx));
}

int main(int argc, char **argv)
{
    unsigned int eax, ebx, ecx, edx, input_exit;
    unsigned long long exits_per_exit, cycles_per_exit;

    if (argc<2) {
        printf("Usage: %s [number]\n", *argv);    
    }
    else {
        input_exit = atoi(*(argv+1));

        eax = 0x4ffffffd;
        ecx = input_exit;

        __cpuid(&eax, &ebx, &ecx, &edx);

        if (eax == 0x0 && ebx == 0x0 && ecx == 0x0 && edx == 0xffffffff)
        {
            printf("CPUID(0x4FFFFFFD|0x4FFFFFFC), value %u not defined by the SDM\n", input_exit);
        }
        else if(eax == 0x0 && ebx == 0x0 && ecx == 0x0 && edx == 0x0) {
            printf("CPUID(0x4FFFFFFD|0x4FFFFFFC), exit type %u not enabled in KVM\n", input_exit);
        }
        else {
            exits_per_exit = eax;

            printf("CPUID(0x4FFFFFFD|0x4FFFFFFC), exit number %u exits=%llu\n", input_exit, exits_per_exit);

            eax = 0x4ffffffc;
            ecx = input_exit;

            __cpuid(&eax, &ebx, &ecx, &edx);

            cycles_per_exit = (unsigned long long) ebx << 32 | ecx;

            printf("CPUID(0x4FFFFFFC), exit number %u time in vmm: %llu cycles\n", input_exit, cycles_per_exit);
        }
    }
}
