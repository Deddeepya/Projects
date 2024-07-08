*************************** ASSIGNMENT - 1 *****************************
To compile :

deddeepya@deddeepya:~/Desktop$ gcc 1.c
deddeepya@deddeepya:~/Desktop$ ./a.out

Discription:

# Tetrahedral Number Finder
This program finds tetrahedral numbers using a multi-processed solution and writes the results to an
output file.

Input File :
The input file (input.txt) should contain two integers, N and K, separated by a space.

Example input.txt
59 3

Output Files :
The program generates k Outfiles (like OutputFile1.txt, OutputFile2.txt, ... ,OutputFilek.txt) 
Each file containing weather number is tetrahedral or not.
And it also generate 1 OutMain file(like OutMain.txt) which contains only tetrahedral numbers <= N

Example :
For above example of input file which has N=59 and K=3
here it generate 3 outfiles and 1 outMain file

OutputFile1.txt:

1: a tetrahedral number
2: Not a tetrahedral number
3: Not a tetrahedral number
4: a tetrahedral number
5: Not a tetrahedral number
6: Not a tetrahedral number
7: Not a tetrahedral number
8: Not a tetrahedral number
9: Not a tetrahedral number
10: a tetrahedral number
11: Not a tetrahedral number
12: Not a tetrahedral number
13: Not a tetrahedral number
14: Not a tetrahedral number
15: Not a tetrahedral number
16: Not a tetrahedral number
17: Not a tetrahedral number
18: Not a tetrahedral number
19: Not a tetrahedral number

OutputFile2.txt:

20: a tetrahedral number
21: Not a tetrahedral number
22: Not a tetrahedral number
23: Not a tetrahedral number
24: Not a tetrahedral number
25: Not a tetrahedral number
26: Not a tetrahedral number
27: Not a tetrahedral number
28: Not a tetrahedral number
29: Not a tetrahedral number
30: Not a tetrahedral number
31: Not a tetrahedral number
32: Not a tetrahedral number
33: Not a tetrahedral number
34: Not a tetrahedral number
35: a tetrahedral number
36: Not a tetrahedral number
37: Not a tetrahedral number
38: Not a tetrahedral number

OutputFile3.txt:

39: Not a tetrahedral number
40: Not a tetrahedral number
41: Not a tetrahedral number
42: Not a tetrahedral number
43: Not a tetrahedral number
44: Not a tetrahedral number
45: Not a tetrahedral number
46: Not a tetrahedral number
47: Not a tetrahedral number
48: Not a tetrahedral number
49: Not a tetrahedral number
50: Not a tetrahedral number
51: Not a tetrahedral number
52: Not a tetrahedral number
53: Not a tetrahedral number
54: Not a tetrahedral number
55: Not a tetrahedral number
56: a tetrahedral number
57: Not a tetrahedral number
58: Not a tetrahedral number
59: Not a tetrahedral number

OutMain.txt:

P1: 1 4 10
P2: 20 35
P3: 56