# CMPE 283 Assignment - 4

## Zi Shun Yang(007562568):
* Setup to create a nested VM for the program to execute
* Built the linux kernel 
* Debugged and performed the required changes to fix the errors which occurred while compiling the code
* Capture outputs from the test runs (ept vs no-ept)
* Retrieved data for the nested and shadow paging exits

## Rohan Patel(010745904):
* Helped build the kernel and debugged errors while building the linux kernel 
* Analyse the changes between the two test runs 
* Error handling while performing the compilation
* Tester code for running tests
* Analysing the nested paging and shadow paging data


## Questions to be answered:
### 2. Include a sample of your print of exit count output from dmesg from “with ept” and “without ept”.
- dmesg output (ept=0 NOT set)
```
[ 7970.134443] CPUID(0x4FFFFFFF), exits=695480
[ 7970.134729] CPUID(0x4FFFFFFE), total time in vmm: 10055375136 cycles
[ 7970.134732]  --- (0x4FFFFFFE), registers: ebx=2, ecx=1465440544
[ 7985.796846] CPUID(0x4FFFFFFD), exit number 0 exits=6741
[ 7985.796917] CPUID(0x4FFFFFFC), exit number 0 time in vmm: 1090671354 cycles
[ 7985.796918]  --- (0x4FFFFFFC), registers: ebx=0, ecx=1090671354
[ 7985.797612] CPUID(0x4FFFFFFD), exit number 1 exits=7415
[ 7985.797691] CPUID(0x4FFFFFFC), exit number 1 time in vmm: 874303 cycles
[ 7985.797692]  --- (0x4FFFFFFC), registers: ebx=0, ecx=874303
[ 7985.798451] CPUID(0x4FFFFFFD), exit number 2 exits=0
[ 7985.798533] CPUID(0x4FFFFFFC), exit number 2 time in vmm: 0 cycles
[ 7985.798535]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.799403] CPUID(0x4FFFFFFD), exit number 3 exits=0
[ 7985.799956] CPUID(0x4FFFFFFC), exit number 3 time in vmm: 0 cycles
[ 7985.799959]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 7985.807831] CPUID(0x4FFFFFFD), exit number 7 exits=935
[ 7985.808223] CPUID(0x4FFFFFFC), exit number 7 time in vmm: 2220437 cycles
[ 7985.808226]  --- (0x4FFFFFFC), registers: ebx=0, ecx=2220437
[ 7985.809433] CPUID(0x4FFFFFFD), exit number 8 exits=0
[ 7985.809810] CPUID(0x4FFFFFFC), exit number 8 time in vmm: 0 cycles
[ 7985.809813]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.810921] CPUID(0x4FFFFFFD), exit number 9 exits=0
[ 7985.811372] CPUID(0x4FFFFFFC), exit number 9 time in vmm: 0 cycles
[ 7985.811374]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.812590] CPUID(0x4FFFFFFD), exit number 10 exits=90010
[ 7985.813033] CPUID(0x4FFFFFFC), exit number 10 time in vmm: 674923687 cycles
[ 7985.813035]  --- (0x4FFFFFFC), registers: ebx=0, ecx=674923687

[ 7985.815401] CPUID(0x4FFFFFFD), exit number 12 exits=2264
[ 7985.815837] CPUID(0x4FFFFFFC), exit number 12 time in vmm: 28096225 cycles
[ 7985.815839]  --- (0x4FFFFFFC), registers: ebx=0, ecx=28096225
[ 7985.817085] CPUID(0x4FFFFFFD), exit number 13 exits=0
[ 7985.817511] CPUID(0x4FFFFFFC), exit number 13 time in vmm: 0 cycles
[ 7985.817513]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.818596] CPUID(0x4FFFFFFD), exit number 14 exits=0
[ 7985.819034] CPUID(0x4FFFFFFC), exit number 14 time in vmm: 0 cycles
[ 7985.819036]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.820189] CPUID(0x4FFFFFFD), exit number 15 exits=0
[ 7985.820769] CPUID(0x4FFFFFFC), exit number 15 time in vmm: 0 cycles
[ 7985.820772]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.821851] CPUID(0x4FFFFFFD), exit number 16 exits=0
[ 7985.822191] CPUID(0x4FFFFFFC), exit number 16 time in vmm: 0 cycles
[ 7985.822194]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 7985.824488] CPUID(0x4FFFFFFD), exit number 18 exits=0
[ 7985.824768] CPUID(0x4FFFFFFC), exit number 18 time in vmm: 0 cycles
[ 7985.824770]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.825879] CPUID(0x4FFFFFFD), exit number 19 exits=0
[ 7985.826181] CPUID(0x4FFFFFFC), exit number 19 time in vmm: 0 cycles
[ 7985.826184]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.827257] CPUID(0x4FFFFFFD), exit number 20 exits=0
[ 7985.827550] CPUID(0x4FFFFFFC), exit number 20 time in vmm: 0 cycles
[ 7985.827552]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.828556] CPUID(0x4FFFFFFD), exit number 21 exits=0
[ 7985.828835] CPUID(0x4FFFFFFC), exit number 21 time in vmm: 0 cycles
[ 7985.828837]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.829736] CPUID(0x4FFFFFFD), exit number 22 exits=0
[ 7985.830027] CPUID(0x4FFFFFFC), exit number 22 time in vmm: 0 cycles
[ 7985.830030]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.831024] CPUID(0x4FFFFFFD), exit number 23 exits=0
[ 7985.831415] CPUID(0x4FFFFFFC), exit number 23 time in vmm: 0 cycles
[ 7985.831417]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.832527] CPUID(0x4FFFFFFD), exit number 24 exits=0
[ 7985.832892] CPUID(0x4FFFFFFC), exit number 24 time in vmm: 0 cycles
[ 7985.832894]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.833963] CPUID(0x4FFFFFFD), exit number 25 exits=0
[ 7985.834347] CPUID(0x4FFFFFFC), exit number 25 time in vmm: 0 cycles
[ 7985.834349]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.835473] CPUID(0x4FFFFFFD), exit number 26 exits=0
[ 7985.835905] CPUID(0x4FFFFFFC), exit number 26 time in vmm: 0 cycles
[ 7985.835907]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.837087] CPUID(0x4FFFFFFD), exit number 27 exits=0
[ 7985.837535] CPUID(0x4FFFFFFC), exit number 27 time in vmm: 0 cycles
[ 7985.837538]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.838685] CPUID(0x4FFFFFFD), exit number 28 exits=14737
[ 7985.839140] CPUID(0x4FFFFFFC), exit number 28 time in vmm: 239997316 cycles
[ 7985.839142]  --- (0x4FFFFFFC), registers: ebx=0, ecx=239997316
[ 7985.840391] CPUID(0x4FFFFFFD), exit number 29 exits=1
[ 7985.840809] CPUID(0x4FFFFFFC), exit number 29 time in vmm: 37659 cycles
[ 7985.840812]  --- (0x4FFFFFFC), registers: ebx=0, ecx=37659
[ 7985.842170] CPUID(0x4FFFFFFD), exit number 30 exits=195973
[ 7985.842587] CPUID(0x4FFFFFFC), exit number 30 time in vmm: 1338733614 cycles
[ 7985.842590]  --- (0x4FFFFFFC), registers: ebx=0, ecx=1338733614
[ 7985.843764] CPUID(0x4FFFFFFD), exit number 31 exits=283
[ 7985.844177] CPUID(0x4FFFFFFC), exit number 31 time in vmm: 2649122 cycles
[ 7985.844180]  --- (0x4FFFFFFC), registers: ebx=0, ecx=2649122
[ 7985.845387] CPUID(0x4FFFFFFD), exit number 32 exits=5762
[ 7985.845777] CPUID(0x4FFFFFFC), exit number 32 time in vmm: 98106879 cycles
[ 7985.845779]  --- (0x4FFFFFFC), registers: ebx=0, ecx=98106879
[ 7985.846897] CPUID(0x4FFFFFFD), exit number 33 exits=0
[ 7985.847314] CPUID(0x4FFFFFFC), exit number 33 time in vmm: 0 cycles
[ 7985.847316]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.848494] CPUID(0x4FFFFFFD), exit number 34 exits=0
[ 7985.848853] CPUID(0x4FFFFFFC), exit number 34 time in vmm: 0 cycles
[ 7985.848855]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 7985.851106] CPUID(0x4FFFFFFD), exit number 36 exits=0
[ 7985.851487] CPUID(0x4FFFFFFC), exit number 36 time in vmm: 0 cycles
[ 7985.851489]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.852799] CPUID(0x4FFFFFFD), exit number 37 exits=0
[ 7985.853163] CPUID(0x4FFFFFFC), exit number 37 time in vmm: 0 cycles
[ 7985.853165]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 7985.855380] CPUID(0x4FFFFFFD), exit number 39 exits=0
[ 7985.855745] CPUID(0x4FFFFFFC), exit number 39 time in vmm: 0 cycles
[ 7985.855747]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.856916] CPUID(0x4FFFFFFD), exit number 40 exits=30
[ 7985.857285] CPUID(0x4FFFFFFC), exit number 40 time in vmm: 264934 cycles
[ 7985.857288]  --- (0x4FFFFFFC), registers: ebx=0, ecx=264934
[ 7985.858440] CPUID(0x4FFFFFFD), exit number 41 exits=0
[ 7985.858729] CPUID(0x4FFFFFFC), exit number 41 time in vmm: 0 cycles
[ 7985.858732]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 7985.860679] CPUID(0x4FFFFFFD), exit number 43 exits=0
[ 7985.860948] CPUID(0x4FFFFFFC), exit number 43 time in vmm: 0 cycles
[ 7985.860951]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.861884] CPUID(0x4FFFFFFD), exit number 44 exits=0
[ 7985.862160] CPUID(0x4FFFFFFC), exit number 44 time in vmm: 0 cycles
[ 7985.862162]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.863203] CPUID(0x4FFFFFFD), exit number 45 exits=0
[ 7985.863577] CPUID(0x4FFFFFFC), exit number 45 time in vmm: 0 cycles
[ 7985.863579]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.864647] CPUID(0x4FFFFFFD), exit number 46 exits=0
[ 7985.865019] CPUID(0x4FFFFFFC), exit number 46 time in vmm: 0 cycles
[ 7985.865021]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.866112] CPUID(0x4FFFFFFD), exit number 47 exits=0
[ 7985.866536] CPUID(0x4FFFFFFC), exit number 47 time in vmm: 0 cycles
[ 7985.866538]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.867684] CPUID(0x4FFFFFFD), exit number 48 exits=365434
[ 7985.868073] CPUID(0x4FFFFFFC), exit number 48 time in vmm: 6334771873 cycles
[ 7985.868076]  --- (0x4FFFFFFC), registers: ebx=1, ecx=2039804577
[ 7985.872772] CPUID(0x4FFFFFFD), exit number 49 exits=6986
[ 7985.873230] CPUID(0x4FFFFFFC), exit number 49 time in vmm: 263183380 cycles
[ 7985.873233]  --- (0x4FFFFFFC), registers: ebx=0, ecx=263183380
[ 7985.874468] CPUID(0x4FFFFFFD), exit number 50 exits=0
[ 7985.874895] CPUID(0x4FFFFFFC), exit number 50 time in vmm: 0 cycles
[ 7985.874897]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.876034] CPUID(0x4FFFFFFD), exit number 51 exits=0
[ 7985.876579] CPUID(0x4FFFFFFC), exit number 51 time in vmm: 0 cycles
[ 7985.876582]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.878941] CPUID(0x4FFFFFFD), exit number 52 exits=0
[ 7985.879388] CPUID(0x4FFFFFFC), exit number 52 time in vmm: 0 cycles
[ 7985.879391]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.884699] CPUID(0x4FFFFFFD), exit number 53 exits=0
[ 7985.885078] CPUID(0x4FFFFFFC), exit number 53 time in vmm: 0 cycles
[ 7985.885081]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.886124] CPUID(0x4FFFFFFD), exit number 54 exits=6
[ 7985.886402] CPUID(0x4FFFFFFC), exit number 54 time in vmm: 48034 cycles
[ 7985.886404]  --- (0x4FFFFFFC), registers: ebx=0, ecx=48034
[ 7985.887301] CPUID(0x4FFFFFFD), exit number 55 exits=2
[ 7985.887586] CPUID(0x4FFFFFFC), exit number 55 time in vmm: 55579 cycles
[ 7985.887589]  --- (0x4FFFFFFC), registers: ebx=0, ecx=55579
[ 7985.888563] CPUID(0x4FFFFFFD), exit number 56 exits=0
[ 7985.888844] CPUID(0x4FFFFFFC), exit number 56 time in vmm: 0 cycles
[ 7985.888846]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.889847] CPUID(0x4FFFFFFD), exit number 57 exits=0
[ 7985.890703] CPUID(0x4FFFFFFC), exit number 57 time in vmm: 0 cycles
[ 7985.890706]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.892029] CPUID(0x4FFFFFFD), exit number 58 exits=0
[ 7985.892550] CPUID(0x4FFFFFFC), exit number 58 time in vmm: 0 cycles
[ 7985.892552]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.894244] CPUID(0x4FFFFFFD), exit number 59 exits=0
[ 7985.894678] CPUID(0x4FFFFFFC), exit number 59 time in vmm: 0 cycles
[ 7985.894681]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.895943] CPUID(0x4FFFFFFD), exit number 60 exits=0
[ 7985.896408] CPUID(0x4FFFFFFC), exit number 60 time in vmm: 0 cycles
[ 7985.896411]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.897743] CPUID(0x4FFFFFFD), exit number 61 exits=0
[ 7985.898099] CPUID(0x4FFFFFFC), exit number 61 time in vmm: 0 cycles
[ 7985.898102]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.899253] CPUID(0x4FFFFFFD), exit number 62 exits=0
[ 7985.899660] CPUID(0x4FFFFFFC), exit number 62 time in vmm: 0 cycles
[ 7985.899664]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.900979] CPUID(0x4FFFFFFD), exit number 63 exits=0
[ 7985.901399] CPUID(0x4FFFFFFC), exit number 63 time in vmm: 0 cycles
[ 7985.901402]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.902561] CPUID(0x4FFFFFFD), exit number 64 exits=0
[ 7985.903072] CPUID(0x4FFFFFFC), exit number 64 time in vmm: 0 cycles
[ 7985.903075]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 7985.906684] CPUID(0x4FFFFFFD), exit number 67 exits=0
[ 7985.907080] CPUID(0x4FFFFFFC), exit number 67 time in vmm: 0 cycles
[ 7985.907082]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 7985.908165] CPUID(0x4FFFFFFD), exit number 68 exits=0
[ 7985.908659] CPUID(0x4FFFFFFC), exit number 68 time in vmm: 0 cycles
[ 7985.908661]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

```
- dmesg output "with ept=0"
```
[ 8306.884800] CPUID(0x4FFFFFFF), exits=2292304
[ 8306.887935] CPUID(0x4FFFFFFE), total time in vmm: 34224632147 cycles
[ 8306.887938]  --- (0x4FFFFFFE), registers: ebx=7, ecx=4159861075
[ 8310.383197] CPUID(0x4FFFFFFD), exit number 0 exits=252436
[ 8310.386599] CPUID(0x4FFFFFFC), exit number 0 time in vmm: 7435052927 cycles
[ 8310.386602]  --- (0x4FFFFFFC), registers: ebx=1, ecx=3140085631
[ 8310.409279] CPUID(0x4FFFFFFD), exit number 1 exits=6159
[ 8310.412886] CPUID(0x4FFFFFFC), exit number 1 time in vmm: 528640 cycles
[ 8310.412889]  --- (0x4FFFFFFC), registers: ebx=0, ecx=528640
[ 8310.434941] CPUID(0x4FFFFFFD), exit number 2 exits=0
[ 8310.438375] CPUID(0x4FFFFFFC), exit number 2 time in vmm: 0 cycles
[ 8310.438378]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.458866] CPUID(0x4FFFFFFD), exit number 3 exits=0
[ 8310.461898] CPUID(0x4FFFFFFC), exit number 3 time in vmm: 0 cycles
[ 8310.461900]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 8310.547037] CPUID(0x4FFFFFFD), exit number 7 exits=6503
[ 8310.550117] CPUID(0x4FFFFFFC), exit number 7 time in vmm: 13471824 cycles
[ 8310.550120]  --- (0x4FFFFFFC), registers: ebx=0, ecx=13471824
[ 8310.571397] CPUID(0x4FFFFFFD), exit number 8 exits=0
[ 8310.574377] CPUID(0x4FFFFFFC), exit number 8 time in vmm: 0 cycles
[ 8310.574380]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.596167] CPUID(0x4FFFFFFD), exit number 9 exits=0
[ 8310.599271] CPUID(0x4FFFFFFC), exit number 9 time in vmm: 0 cycles
[ 8310.599274]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.621299] CPUID(0x4FFFFFFD), exit number 10 exits=97495
[ 8310.624476] CPUID(0x4FFFFFFC), exit number 10 time in vmm: 693333804 cycles
[ 8310.624479]  --- (0x4FFFFFFC), registers: ebx=0, ecx=693333804

[ 8310.668226] CPUID(0x4FFFFFFD), exit number 12 exits=444
[ 8310.670929] CPUID(0x4FFFFFFC), exit number 12 time in vmm: 4821198 cycles
[ 8310.670932]  --- (0x4FFFFFFC), registers: ebx=0, ecx=4821198
[ 8310.692036] CPUID(0x4FFFFFFD), exit number 13 exits=0
[ 8310.695058] CPUID(0x4FFFFFFC), exit number 13 time in vmm: 0 cycles
[ 8310.695061]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.717018] CPUID(0x4FFFFFFD), exit number 14 exits=98810
[ 8310.719605] CPUID(0x4FFFFFFC), exit number 14 time in vmm: 1425792462 cycles
[ 8310.719608]  --- (0x4FFFFFFC), registers: ebx=0, ecx=1425792462
[ 8310.741545] CPUID(0x4FFFFFFD), exit number 15 exits=0
[ 8310.744788] CPUID(0x4FFFFFFC), exit number 15 time in vmm: 0 cycles
[ 8310.744791]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.766972] CPUID(0x4FFFFFFD), exit number 16 exits=0
[ 8310.769906] CPUID(0x4FFFFFFC), exit number 16 time in vmm: 0 cycles
[ 8310.769909]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 8310.812342] CPUID(0x4FFFFFFD), exit number 18 exits=0
[ 8310.815053] CPUID(0x4FFFFFFC), exit number 18 time in vmm: 0 cycles
[ 8310.815056]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.836803] CPUID(0x4FFFFFFD), exit number 19 exits=0
[ 8310.839493] CPUID(0x4FFFFFFC), exit number 19 time in vmm: 0 cycles
[ 8310.839495]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.860269] CPUID(0x4FFFFFFD), exit number 20 exits=0
[ 8310.863290] CPUID(0x4FFFFFFC), exit number 20 time in vmm: 0 cycles
[ 8310.863294]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.884798] CPUID(0x4FFFFFFD), exit number 21 exits=0
[ 8310.887522] CPUID(0x4FFFFFFC), exit number 21 time in vmm: 0 cycles
[ 8310.887525]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.910258] CPUID(0x4FFFFFFD), exit number 22 exits=0
[ 8310.913352] CPUID(0x4FFFFFFC), exit number 22 time in vmm: 0 cycles
[ 8310.913355]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.935601] CPUID(0x4FFFFFFD), exit number 23 exits=0
[ 8310.938266] CPUID(0x4FFFFFFC), exit number 23 time in vmm: 0 cycles
[ 8310.938269]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.958786] CPUID(0x4FFFFFFD), exit number 24 exits=0
[ 8310.961835] CPUID(0x4FFFFFFC), exit number 24 time in vmm: 0 cycles
[ 8310.961838]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8310.983146] CPUID(0x4FFFFFFD), exit number 25 exits=0
[ 8310.985807] CPUID(0x4FFFFFFC), exit number 25 time in vmm: 0 cycles
[ 8310.985810]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.006430] CPUID(0x4FFFFFFD), exit number 26 exits=0
[ 8311.009553] CPUID(0x4FFFFFFC), exit number 26 time in vmm: 0 cycles
[ 8311.009556]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.030409] CPUID(0x4FFFFFFD), exit number 27 exits=0
[ 8311.033047] CPUID(0x4FFFFFFC), exit number 27 time in vmm: 0 cycles
[ 8311.033050]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.054247] CPUID(0x4FFFFFFD), exit number 28 exits=1640347
[ 8311.057237] CPUID(0x4FFFFFFC), exit number 28 time in vmm: 20605391769 cycles
[ 8311.057240]  --- (0x4FFFFFFC), registers: ebx=4, ecx=3425522585
[ 8311.078318] CPUID(0x4FFFFFFD), exit number 29 exits=1
[ 8311.081328] CPUID(0x4FFFFFFC), exit number 29 time in vmm: 37435 cycles
[ 8311.081331]  --- (0x4FFFFFFC), registers: ebx=0, ecx=37435
[ 8311.102080] CPUID(0x4FFFFFFD), exit number 30 exits=175583
[ 8311.104850] CPUID(0x4FFFFFFC), exit number 30 time in vmm: 1121373658 cycles
[ 8311.104853]  --- (0x4FFFFFFC), registers: ebx=0, ecx=1121373658
[ 8311.125451] CPUID(0x4FFFFFFD), exit number 31 exits=239
[ 8311.128579] CPUID(0x4FFFFFFC), exit number 31 time in vmm: 2029015 cycles
[ 8311.128582]  --- (0x4FFFFFFC), registers: ebx=0, ecx=2029015
[ 8311.150179] CPUID(0x4FFFFFFD), exit number 32 exits=11490
[ 8311.153252] CPUID(0x4FFFFFFC), exit number 32 time in vmm: 118379194 cycles
[ 8311.153255]  --- (0x4FFFFFFC), registers: ebx=0, ecx=118379194
[ 8311.183317] CPUID(0x4FFFFFFD), exit number 33 exits=12314
[ 8311.186075] CPUID(0x4FFFFFFC), exit number 33 time in vmm: 2499533663 cycles
[ 8311.186078]  --- (0x4FFFFFFC), registers: ebx=0, ecx=2499533663
[ 8311.207184] CPUID(0x4FFFFFFD), exit number 34 exits=0
[ 8311.210406] CPUID(0x4FFFFFFC), exit number 34 time in vmm: 0 cycles
[ 8311.210409]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 8311.256023] CPUID(0x4FFFFFFD), exit number 36 exits=0
[ 8311.259177] CPUID(0x4FFFFFFC), exit number 36 time in vmm: 0 cycles
[ 8311.259180]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.280389] CPUID(0x4FFFFFFD), exit number 37 exits=0
[ 8311.283262] CPUID(0x4FFFFFFC), exit number 37 time in vmm: 0 cycles
[ 8311.283265]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 8311.326262] CPUID(0x4FFFFFFD), exit number 39 exits=0
[ 8311.328956] CPUID(0x4FFFFFFC), exit number 39 time in vmm: 0 cycles
[ 8311.328958]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.350541] CPUID(0x4FFFFFFD), exit number 40 exits=24
[ 8311.353558] CPUID(0x4FFFFFFC), exit number 40 time in vmm: 200511 cycles
[ 8311.353572]  --- (0x4FFFFFFC), registers: ebx=0, ecx=200511
[ 8311.374987] CPUID(0x4FFFFFFD), exit number 41 exits=0
[ 8311.378108] CPUID(0x4FFFFFFC), exit number 41 time in vmm: 0 cycles
[ 8311.378111]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 8311.421062] CPUID(0x4FFFFFFD), exit number 43 exits=0
[ 8311.424120] CPUID(0x4FFFFFFC), exit number 43 time in vmm: 0 cycles
[ 8311.424123]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.446106] CPUID(0x4FFFFFFD), exit number 44 exits=0
[ 8311.449364] CPUID(0x4FFFFFFC), exit number 44 time in vmm: 0 cycles
[ 8311.449367]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.470670] CPUID(0x4FFFFFFD), exit number 45 exits=0
[ 8311.473719] CPUID(0x4FFFFFFC), exit number 45 time in vmm: 0 cycles
[ 8311.473722]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.495741] CPUID(0x4FFFFFFD), exit number 46 exits=0
[ 8311.498834] CPUID(0x4FFFFFFC), exit number 46 time in vmm: 0 cycles
[ 8311.498837]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.520902] CPUID(0x4FFFFFFD), exit number 47 exits=0
[ 8311.524098] CPUID(0x4FFFFFFC), exit number 47 time in vmm: 0 cycles
[ 8311.524101]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.546264] CPUID(0x4FFFFFFD), exit number 48 exits=0
[ 8311.549328] CPUID(0x4FFFFFFC), exit number 48 time in vmm: 0 cycles
[ 8311.549331]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.570805] CPUID(0x4FFFFFFD), exit number 49 exits=0
[ 8311.573866] CPUID(0x4FFFFFFC), exit number 49 time in vmm: 0 cycles
[ 8311.573869]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.595121] CPUID(0x4FFFFFFD), exit number 50 exits=0
[ 8311.598246] CPUID(0x4FFFFFFC), exit number 50 time in vmm: 0 cycles
[ 8311.598249]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.620379] CPUID(0x4FFFFFFD), exit number 51 exits=0
[ 8311.623029] CPUID(0x4FFFFFFC), exit number 51 time in vmm: 0 cycles
[ 8311.623031]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.643371] CPUID(0x4FFFFFFD), exit number 52 exits=0
[ 8311.646126] CPUID(0x4FFFFFFC), exit number 52 time in vmm: 0 cycles
[ 8311.646129]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.666451] CPUID(0x4FFFFFFD), exit number 53 exits=0
[ 8311.669314] CPUID(0x4FFFFFFC), exit number 53 time in vmm: 0 cycles
[ 8311.669317]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.690138] CPUID(0x4FFFFFFD), exit number 54 exits=6
[ 8311.693043] CPUID(0x4FFFFFFC), exit number 54 time in vmm: 47368 cycles
[ 8311.693046]  --- (0x4FFFFFFC), registers: ebx=0, ecx=47368
[ 8311.714037] CPUID(0x4FFFFFFD), exit number 55 exits=2
[ 8311.716819] CPUID(0x4FFFFFFC), exit number 55 time in vmm: 25768 cycles
[ 8311.716822]  --- (0x4FFFFFFC), registers: ebx=0, ecx=25768
[ 8311.738223] CPUID(0x4FFFFFFD), exit number 56 exits=0
[ 8311.741317] CPUID(0x4FFFFFFC), exit number 56 time in vmm: 0 cycles
[ 8311.741320]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.763186] CPUID(0x4FFFFFFD), exit number 57 exits=0
[ 8311.766402] CPUID(0x4FFFFFFC), exit number 57 time in vmm: 0 cycles
[ 8311.766405]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.787615] CPUID(0x4FFFFFFD), exit number 58 exits=26815
[ 8311.790843] CPUID(0x4FFFFFFC), exit number 58 time in vmm: 820376476 cycles
[ 8311.790846]  --- (0x4FFFFFFC), registers: ebx=0, ecx=820376476
[ 8311.812406] CPUID(0x4FFFFFFD), exit number 59 exits=0
[ 8311.815157] CPUID(0x4FFFFFFC), exit number 59 time in vmm: 0 cycles
[ 8311.815160]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.837276] CPUID(0x4FFFFFFD), exit number 60 exits=0
[ 8311.840166] CPUID(0x4FFFFFFC), exit number 60 time in vmm: 0 cycles
[ 8311.840169]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.862454] CPUID(0x4FFFFFFD), exit number 61 exits=0
[ 8311.865523] CPUID(0x4FFFFFFC), exit number 61 time in vmm: 0 cycles
[ 8311.865526]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.887043] CPUID(0x4FFFFFFD), exit number 62 exits=0
[ 8311.889976] CPUID(0x4FFFFFFC), exit number 62 time in vmm: 0 cycles
[ 8311.889979]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.912407] CPUID(0x4FFFFFFD), exit number 63 exits=0
[ 8311.915426] CPUID(0x4FFFFFFC), exit number 63 time in vmm: 0 cycles
[ 8311.915430]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8311.937154] CPUID(0x4FFFFFFD), exit number 64 exits=0
[ 8311.940206] CPUID(0x4FFFFFFC), exit number 64 time in vmm: 0 cycles
[ 8311.940209]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

[ 8312.008008] CPUID(0x4FFFFFFD), exit number 67 exits=0
[ 8312.011106] CPUID(0x4FFFFFFC), exit number 67 time in vmm: 0 cycles
[ 8312.011109]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0
[ 8312.033446] CPUID(0x4FFFFFFD), exit number 68 exits=0
[ 8312.036579] CPUID(0x4FFFFFFC), exit number 68 time in vmm: 0 cycles
[ 8312.036582]  --- (0x4FFFFFFC), registers: ebx=0, ecx=0

```
- Please refer to [283_assign4/](283_assign4/) folder for detail of outputs

### 3. What did you learn from the count of exits? Was the count what you expected? If not, why not?
- The ept flag for ept vs no-ept caused exits in different ways. Total exit count was higher when ept=0 is set meaning that forcing KVM to use shadow paging could cuase many exits, which it makes sense that the KVM reflect the shadow page tables that are kept by the hypervisor, and it needs to exit. In the end, we learned that shadow paging in relation to nested paging had noticeably more exits due to the reason being that for nested paging VM exits occur whenever EPT violation happens. As per our anticipation, when nested paging executes page walk the page tables rapidly updated compared to shadow paging in turn needing exorbitant hypervisor arbitration with page table changes.


### 4. What changed between the two runs (ept vs no-ept)?
- For ept, there is no mandate for an exit as two-layer page tables are employed to retrieve the physical address of the host and also with the page table being associated to the guest VM whereas, for no-ept, the guess doesn't own the page table and so it doesn't link to the guest virtual machine.

- Some exits didn't trigger when ept=0, but triggered when no ept set, such as:
    * exit # 48 - EPT violation
    * exit # 49 - EPT misconfiguration
- Some exits triggered when ept=0, but did not trigger when no ept set:
    * exit # 14 - INVLPG
    * exit # 33 - VM-entry failure due to invalid guest state
    * exit # 58 - INVPCID
- The counts for certain exit reasons when ept=0 were LARGER than without ept set:
    * exit # 0 - Exception or non-maskable interrupt (NMI)
    * exit # 7 - Interrupt window
    * exit # 10 - CPUID
    * exit # 28 - Control-register accesses
- The counts for certain exit reasons when ept=0 were SMALLER than without ept set:
    * exit # 1 - External interrupt
    * exit # 12 - HLT
    * exit # 30 - I/O instruction
    * exit # 31 - RDMSR
    * exit # 40 - PAUSE

