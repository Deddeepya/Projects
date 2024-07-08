#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX_LINE1_LENGTH 100
#define MAX_LINE2_LENGTH 100
int convert_to_decimal(int start_index,int end_index,int array[]){  
    int a=0;
    int n=start_index - end_index;
   for(int i=0;i<=n;i++){
    int k=1;
for(int q=1;q<=i;q++){  // this loop is to find 2 power i
   k=2*k;
}
a = a + (k*(array[end_index + i]));  
   }
    
  return a;
}
void hit_miss(unsigned int address,int t,int l,int w,int cache[l][w],int x,int y){  // x represents weather it is read,WT,WB
    int index=log2(l);                                                 // y represents weather it is FIFO,LRU,RANDOM
    int array[32];

    for (int i = 31; i >= 0; i--) {
        int bit = (address >> i) & 1;
      array[i]=bit;
    }
    // for(int i=0;i<32;i++){
    
    // printf("%d ",array[i]);}
    // printf("\n");
    int offset=32 - index -t;
    int end_index=offset;
    int start_index= offset+index-1;
    int row=convert_to_decimal(start_index,end_index,array);
    int tag_value=convert_to_decimal(31,start_index+1,array);
    printf("Set: 0x%x, ",row);
            int a=0;
            int i;
            for(i=0;i < w;i++){
              if(cache[row][i] == -1){
              a=1;
              break;
              }
            }
            int way;
            if(i == (w-1) && a==0){
            way = w-1;
            }
            else if(i == (w-1) && a == 1 ){
            way = w - 2;
            }
           else {
             way = i-1;
            }
            int h = 0;
            int j;
            for(j=0;j<=way;j++){
                if(tag_value == cache[row][j]){
                    h = 1;
                    break;
                }
            }
            int column;
            if(h == 1){
                column=j;
               
                printf("Hit, ");
               
            }
            else{
                printf("Miss, ");
            }
            printf("Tag: 0x%x",tag_value);
           if( x == 0 || x == 1 ){
                if(y == 0){     // FIFO
                    if(h == 0){  
                       if(way == w-1){
                       for(int t=0;t< way;t++){
                        cache[row][t]=cache[row][t+1];
                       }
                       cache[row][way] = tag_value;}
                       else{
                        cache[row][way + 1]=tag_value;
                       } 
                    }
                }
                else if(y == 1){  // LRU
                    if(h == 0){
                        if(way == w - 1){
                            cache[row][way] = tag_value; 
                        }
                        else{
                            cache[row][way+1]=tag_value;
                        }
                    }
                    else if(h == 1){
                           for(int q=j;q<way;q++){
                            cache[row][q]=cache[row][q+1];
                        }
                        cache[row][way]=tag_value;
                    }
                }
                else if(y == 2){ // RANDOM
                   int random=rand() % (way +1);
                   if(h == 0){
                    cache[row][random]=tag_value;
                   }
                }
           }
           else if(x ==2){
              if(y == 1){
               if(h == 1){
                  for(int q=j;q<way;q++){
                       cache[row][q]=cache[row][q+1];
                        }
                  cache[row][way]=tag_value;
                 }}
             else if(y == 2){
             if(h == 1){
                int random=rand() % (way +1);
                   if(h == 0){
                    cache[row][random]=tag_value;
                   }}}
             
           } 
 }
int main() {
    const char* filename = "cache.config";
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    int size_of_cache, block_size, associativity;
    char replacement_policy[MAX_LINE1_LENGTH];
    char writeback_policy[MAX_LINE1_LENGTH];

    // Read each line from the file
    char line1[MAX_LINE1_LENGTH];
    if (fgets(line1, sizeof(line1), file) != NULL) {
        size_of_cache = atoi(line1);
    }
    if (fgets(line1, sizeof(line1), file) != NULL) {
        block_size = atoi(line1);
    }
    if (fgets(line1, sizeof(line1), file) != NULL) {
        associativity = atoi(line1);
    }
    if (fgets(line1, sizeof(line1), file) != NULL) {
        sscanf(line1, "%s", replacement_policy);
    }
    if (fgets(line1, sizeof(line1), file) != NULL) {
        sscanf(line1, "%s", writeback_policy);
    }
    fclose(file);
    int offset=log2(block_size);
    int number_of_blocks=(size_of_cache)/block_size;
    int lines=(number_of_blocks)/associativity;
    int index=log2(lines);
    int tag= 32 - offset - index;
    int array[lines][associativity];
    for(int i=0;i<lines;i++){
        for(int j=0;j<associativity;j++){
            array[i][j]= -1;
        }
    }
    int r;
    if(strcmp(replacement_policy,"FIFO") == 0){
        r=0;  
    }
    else if(strcmp(replacement_policy,"LRU") == 0){
        r=1;
    }
    else if(strcmp(replacement_policy,"RANDOM") == 0){
        r=2;
    }
    int w;
    if(strcmp(writeback_policy,"WB") == 0){
        w = 1;
    }
    else if(strcmp(writeback_policy,"WT") == 0){
        w = 2;
    }
    const char* inputfile = "cache.access";
    FILE* file2 = fopen(inputfile, "r");

    if (file2 == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    // Read each line from the file
    char line[MAX_LINE2_LENGTH];
    while (fgets(line, sizeof(line), file2) != NULL) {
        char operation;
        unsigned int address;
        // Parse the line to extract operation and address
        if (sscanf(line, "%c: 0x%x", &operation, &address) == 2) {
            // Process the operation and address as needed
            if (operation == 'R') {
                printf("Address: 0x%x, ", address);
                hit_miss(address,tag,lines,associativity,array,0,r);
                printf("\n");
        
            } else if (operation == 'W') {
                printf("Address: 0x%x, ", address);
                hit_miss(address,tag,lines,associativity,array,w,r);
                 printf("\n");
                
            } 
        } 
    }
    fclose(file2);
    return 0;
}


