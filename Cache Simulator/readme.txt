************************************************************LAB-6****************************************
Compile my 1.c file as gcc 1.c -lm

Example:

input file:

cache.config
32768
16
8
LRU
WT

cache.access
R: 0xb333c680
R: 0x6c9aae2b
R: 0xa909d2ba
R: 0x93e84d38
R: 0xa05dbaee
R: 0xdedaf689
R: 0x3ac83837
R: 0x99ec8ddf
R: 0x9bc0999f
R: 0xc7e28426
R: 0x61bb6b16
W: 0x75be51a4
R: 0xd6fe42a4

output:

deddeepya@deddeepya:~$ gcc 1.c -lm
deddeepya@deddeepya:~$ ./a.out
Address: 0xb333c680, Set: 0x68, Miss, Tag: 0xb333c
Address: 0x6c9aae2b, Set: 0xe2, Miss, Tag: 0x6c9aa
Address: 0xa909d2ba, Set: 0x2b, Miss, Tag: 0xa909d
Address: 0x93e84d38, Set: 0xd3, Miss, Tag: 0x93e84
Address: 0xa05dbaee, Set: 0xae, Miss, Tag: 0xa05db
Address: 0xdedaf689, Set: 0x68, Miss, Tag: 0xdedaf
Address: 0x3ac83837, Set: 0x83, Miss, Tag: 0x3ac83
Address: 0x99ec8ddf, Set: 0xdd, Miss, Tag: 0x99ec8
Address: 0x9bc0999f, Set: 0x99, Miss, Tag: 0x9bc09
Address: 0xc7e28426, Set: 0x42, Miss, Tag: 0xc7e28
Address: 0x61bb6b16, Set: 0xb1, Miss, Tag: 0x61bb6
Address: 0x75be51a4, Set: 0x1a, Miss, Tag: 0x75be5
Address: 0xd6fe42a4, Set: 0x2a, Miss, Tag: 0xd6fe4

