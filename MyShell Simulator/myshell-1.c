#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>
#define maxcl 1000
#define maxhl 100
void prompt();
void history(char *p);
int main(){

while(2>1){
prompt();
char *str;
str=readline("\ncommand: ");

if(strcmp(str,"exit")==0){
printf("EXITING MYSHELL");
exit(0);}
else if(strcmp(str,"help")==0){
system("bash -c help");}
else{
system(str);}

add_history(str);
history(str);
free(str);
}
return 0;}

void prompt(){
char c[maxcl];
getcwd(c,sizeof(c));
printf("%s:%s$ ", getlogin(), c);}

void history(char *p){
int num=0;
char *commands[maxhl];
if(num<maxhl){
   commands[num++]=strdup(p);
}
else{
free(commands[0]);
 for (int i=1;i<num;i++) {
 commands[i-1]=commands[i];}
 commands[num-1]=strdup(p);}

 for(int i=0;i<num;i++){
 free(commands[i]);}}
