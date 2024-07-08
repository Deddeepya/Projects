#include <stdio.h>
#include <math.h>

int convert_to_decimal(int start_index,int end_index,int array[],int b){  
    if(b == 1){// as immediate can be negative so checking whether array[start_index] is 1 or 0
      if(array[start_index] == 1){     
        array[start_index]= -1;
      }} 
    int a=0;
    int n=start_index - end_index;
   for(int i=0;i<=n;i++){
    int k=1;
for(int q=1;q<=i;q++){  // this loop is to find 2 power i
   k=2*k;
}
a = a + (k*(array[end_index + i]));  
   }
    if(array[start_index] == -1){     
        array[start_index]= 1;
      }
  return a;
}
int Binary(unsigned int instruction,int num_of_instrc,int index,int e1,int e2) { 
    if(e1 != -1 && e1 != -2){
            printf("label-%d: ",e1);
    }
    int array[32];
    int arr[num_of_instrc];
    for (int i = 31; i >= 0; i--) {
        int bit = (instruction >> i) & 1;
      array[i]=bit;
    }
    int opcode = convert_to_decimal(6,0,array,0);// as it is not immediate so b=0
    if(opcode == 51){              // R-TYPE
    if(e1 == -2){
    arr[index]=1;
    return arr[index];}
      int rs2,rs1,rd,funct3,funct7;
      rd=convert_to_decimal(11,7,array,0);
      rs1=convert_to_decimal(19,15,array,0);
      rs2=convert_to_decimal(24,20,array,0);
      funct3=convert_to_decimal(14,12,array,0);
      funct7=convert_to_decimal(31,25,array,0);
      if(funct3 == 0){
        if(funct7 == 0){
            printf("add x%d,x%d,x%d",rd,rs1,rs2);}
        else{
            printf("sub x%d,x%d,x%d",rd,rs1,rs2);}
      }
      else if(funct3 == 1){
         printf("sll x%d,x%d,x%d",rd,rs1,rs2);
      }
      else if(funct3 == 4){
         printf("xor x%d,x%d,x%d",rd,rs1,rs2);
      }
      else if(funct3 == 5){
         if(funct7 == 0){
            printf("srl x%d,x%d,x%d",rd,rs1,rs2);}
        else{
            printf("sra x%d,x%d,x%d",rd,rs1,rs2);}
      }
      else if(funct3 == 6){
         printf("or x%d,x%d,x%d",rd,rs1,rs2);
      }
      else if(funct3 == 7){
         printf("and x%d,x%d,x%d",rd,rs1,rs2);
      }   
    }
    else if(opcode == 19 || opcode == 3 || opcode == 103){ // I-TYPE
    if(e1 == -2){
    arr[index]=1;
    return arr[index];}
     int rd=convert_to_decimal(11,7,array,0);
    int rs1=convert_to_decimal(19,15,array,0);
    int funct3=convert_to_decimal(14,12,array,0);
         int imm=convert_to_decimal(31,20,array,1);
     int imm11_6=convert_to_decimal(31,26,array,0);
      int im=convert_to_decimal(25,20,array,0);
     if(opcode == 19){
         if(funct3 == 0){
             printf("addi x%d,x%d,%d",rd,rs1,imm);
         }
         else if(funct3 == 1){
            printf("slli x%d,x%d,%d",rd,rs1,im);
         }
         else if(funct3 == 4){
            printf("xori x%d,x%d,%d",rd,rs1,imm);
         }
         else if(funct3 == 5){
            if(imm11_6 == 0){
                printf("srli x%d,x%d,%d",rd,rs1,im);
            }
            else{
                printf("srai x%d,x%d,%d",rd,rs1,im);
            }
         }
         else if(funct3 == 6){
             printf("ori x%d,x%d,%d",rd,rs1,imm);
         }
         else if(funct3 == 7){
             printf("andi x%d,x%d,%d",rd,rs1,imm);
         }
     }
     else if(opcode == 3){
        if(funct3 == 0){
            printf("lb x%d,%d(x%d)",rd,imm,rs1);
        }
        else if(funct3 == 1){
            printf("lh x%d,%d(x%d)",rd,imm,rs1);
        }
       else if(funct3 == 2){
            printf("lw x%d,%d(x%d)",rd,imm,rs1);
        }
        else if(funct3 == 3){
            printf("ld x%d,%d(x%d)",rd,imm,rs1);
        }
        else if(funct3 == 4){
             int imm1=convert_to_decimal(31,20,array,0);
            printf("lbu x%d,%d(x%d)",rd,imm1,rs1);
        }
        else if(funct3 == 5){
             int imm1=convert_to_decimal(31,20,array,0);
            printf("lhu x%d,%d(x%d)",rd,imm1,rs1);
        }
         else if(funct3 == 6){
         int imm1=convert_to_decimal(31,20,array,0);
         printf("lwu x%d,%d(x%d)",rd,imm1,rs1);
         }
     }
     else if(opcode == 103){
        printf("jalr x%d,%d(x%d)",rd,imm,rs1);
     }
    }
    else if(opcode == 35){  // S-TYPE
    if(e1 == -2){
    arr[index]=1;
    return arr[index];}
        int rs2=convert_to_decimal(24,20,array,0);
    int rs1=convert_to_decimal(19,15,array,0);
    int funct3=convert_to_decimal(14,12,array,0);
         int imm31_25=convert_to_decimal(31,25,array,1);
         int imm11_7=convert_to_decimal(11,7,array,0);
        int imm=(imm31_25)*32 + imm11_7 ;
         if(funct3 == 0){
            printf("sb x%d,%d(x%d)",rs2,imm,rs1);
        }
        else if(funct3 == 1){
            printf("sh x%d,%d(x%d)",rs2,imm,rs1);
        }
       else if(funct3 == 2){
            printf("sw x%d,%d(x%d)",rs2,imm,rs1);
        }
        else if(funct3 == 3){
            printf("sd x%d,%d(x%d)",rs2,imm,rs1);
    }}
    else if(opcode == 99){      // B-TYPE
    
       int rs2=convert_to_decimal(24,20,array,0);
    int rs1=convert_to_decimal(19,15,array,0);
    int funct3=convert_to_decimal(14,12,array,0);
         int imm30_25=convert_to_decimal(30,25,array,0);
         int imm11_8=convert_to_decimal(11,8,array,0);
         if(array[31] == 1){
            array[31]= -1;
         }
        int p=(2048*array[31])+(1024*array[7]) + (16*imm30_25) + imm11_8;
        int imm=2*p;
        if(e1 == -2){
    arr[index]=imm;
    return arr[index];}
         if(array[31] == -1){
            array[31]= 1;
         }
         if(funct3 == 0){
            printf("beq x%d,x%d,label-%d",rs1,rs2,e2);
         }
         else if(funct3 == 1){
            printf("bne x%d,x%d,label-%d",rs1,rs2,e2);
         }
        else if(funct3 == 4){
            printf("blt x%d,x%d,label-%d",rs1,rs2,e2);
         }
        else if(funct3 == 5){
            printf("bge x%d,x%d,label-%d",rs1,rs2,e2);
         }
         else if(funct3 == 6){
            printf("bltu x%d,x%d,label-%d",rs1,rs2,e2);
         }
        else if(funct3 == 7){
            printf("bgeu x%d,x%d,label-%d",rs1,rs2,e2);
         }
    }
    else if(opcode == 111){   //J-TYPE
                int rd=convert_to_decimal(11,7,array,0);
        int imm19_12=convert_to_decimal(19,12,array,0);
int imm10_1=convert_to_decimal(30,21,array,0);
if(array[31] == 1){
    array[31] = -1;
}
int imm=pow(2,20)*array[31]+pow(2,12)*imm19_12 +pow(2,11)*array[11]+2*imm10_1;
if(e1 == -2){
    arr[index]=imm;
    return arr[index];}
printf("jal x%d,label-%d",rd,e2);
if(array[31] == -1){
    array[31] = 1;
}
    }
    else if(opcode == 55){// U-TYPE
        int rd=convert_to_decimal(11,7,array,0);
        int imm=convert_to_decimal(31,12,array,0);
        if(e1 == -2){
    arr[index]=1;
    return arr[index];}
        printf("lui x%d,0x%X",rd,imm);
    }
    printf("\n");
}

int main() {
    FILE* file = fopen("input.txt", "r"); // Open the file in read mode
    if (!file) {
        perror("Error opening the file");
        return 1;
    }
    unsigned int instructions[50]; // Assuming a maximum of 20 instructions
    int numInstructions = 0;
    // Read instructions from the file
    while (numInstructions < 50 && fscanf(file, "%x", &instructions[numInstructions]) == 1) {
        numInstructions++;
    }
    fclose(file);
    int arr[numInstructions];
    int n=numInstructions;
    int line[n];
    int num_labels=0;
    for (int i = 0; i < numInstructions; i++) {
        // Convert the hex instruction to binary here
        unsigned int binaryInstruction = instructions[i];   
        // Print the binary representation of the instruction
     arr[i]= Binary(binaryInstruction,numInstructions,i,-2,-2);  
     if(arr[i] != 1){
         line[i]=i+(arr[i]/4);
         num_labels++; }
      else{
         line[i]=-1; } //there is no label
    }
    int e[n];
for(int i=0;i<n;i++){
   e[i]=-1;
    unsigned int binaryInstruction = instructions[i];
    for(int q=0;q<n;q++){
      if(line[q] == i){
         e[i] = i;
         break;
         }
    }
int c= Binary(binaryInstruction,numInstructions,i,e[i],line[i]);
}
    return 0;
}
