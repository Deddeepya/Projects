#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<libgen.h>
#include<errno.h>
#include<ctype.h>
#define maxcl 1000
#define maxhl 100
#define PATH_SIZE 100000
int copy_file(const char* source, const char* distination);
void prompt();
int compare_strings(const void* a, const void* b);

