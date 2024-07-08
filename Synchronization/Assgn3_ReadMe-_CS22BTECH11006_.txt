**********************Programming Assignment2: Thread Affinity**************************

Inputfile format:(inp.txt)
(first line consists of N,K,C,BT vales which are separated by single space,next N lines contains matrix .Each line represents each rows (elements are separated by spaces))

N K RowInc 
ROW1
ROW2
.
.
.
ROWN
example of inputfile:
4 4 2
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

OUTPUT:
It creates 4 output files named as out_atomic_incrememt.txt , out_BoundedCAS.txt,out_CAS.txt,out_TAS.txt

each outfile formate is:
first n rows consists of square of given matrix ,next line contains time in seconds

row1
row2
.
.
.
rown
Time : ....

My zip file consists of 4 files
(1.) Assgn2_TAS_Src-<CS22BTECH11006>.cpp    : c++ code of the given problem
(2.) Assgn2_CAS_Src-<CS22BTECH11006>.cpp    : c++ code of the given problem
(3.) Assgn2_BoundedCAS_Src-<CS22BTECH11006>.cpp    : c++ code of the given problem
(4.) Assgn2_atomic_incrememt_Src-<CS22BTECH11006>.cpp    : c++ code of the given problem
(5.) Assgn2_ReadMe-<CS22BTECH11006>.txt : readme file of Assignment
(6.) Assgn2_Report-<CS22BTECH11006>.pdf : Report of given Assignment
(7.) inputfile.txt                      : sample input file
 
Execution of c++ file :  
 Compile the code -
        $ g++ Assgn2_Src-<CS22BTECH11006>.cpp
        $ ./a.out 