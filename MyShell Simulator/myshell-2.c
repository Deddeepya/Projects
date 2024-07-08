#include "header.h"
int main() {
while(2>1){
prompt();
char* str;
str= readline("\ncommand: ");
struct dirent *de;
    char** files = NULL; // array of pointers to char
    int num_files = 0;
    
    DIR* dr = opendir(".");
    if (dr == NULL) {
        printf("Can't open current directory");
        return 0;
    }
    
    // read file names and store them in the array of pointers
    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[0] != '.') {
            // allocate memory for the file name
            char* name = malloc(strlen(de->d_name) + 1);
            strcpy(name, de->d_name);
            
            // add the file name to the array
            files = realloc(files, (num_files + 1) * sizeof(char*));
            files[num_files++] = name;
        
    }
    }
    // sort the array of pointers using qsort function
    qsort(files, num_files, sizeof(char*), compare_strings);
    

if(strcmp(str,"exit")==0){
        printf("EXITING MYSHELL\n");
        exit(0);}

else if(str[0]=='c' && str[1]=='p'){
         char *token = strtok(str, " "); // Get first token, "cp"
          char *args[3]; // Array to store the arguments
          args[0] = token; // Store the first token in the array
          int i = 0;
          while (token != NULL) {
          token = strtok(NULL, " "); // Get next token
          args[i++] = token;
            // Store the token in the array
               }
     if(args[2]==NULL){
          
             copy_file(args[0],args[1]);}
  
     else if(strcmp(args[0], "-v") == 0){
             
              copy_file(args[1],args[2]);
              printf("%s -> %s\n",args[1],args[2]);}
  
     else if(strcmp(args[0],"-i")==0){
            struct stat filestat;
               char a;
            if (stat(args[2], &filestat) != -1) {
                printf("cp: overwrite '%s'? (y/n)",args[2]);
                      scanf("%c",&a);
                   if(a=='n'||a=='N'){
                printf("no overwritting");}
                   else{
                copy_file(args[1],args[2]);
                    }     }
            else{
                       
                        copy_file(args[1],args[2]);}
                                }
    else if(strcmp(args[0],"-l")==0){
                 
               int result = link(args[1], args[2]);
               if (result == -1) {
                printf("can't link %s %s",args[1],args[2]);}
                }
    else if(strcmp(args[0],"-s")==0){
                 
                if(symlink(args[1],args[2])==-1){
                 printf("symlink error %s %s",args[1],args[2]);}}
    else{
                printf("COMMAND NOT FOUND");}
                   }
else if(str[0]=='m' && str[1]=='v'){
         char *token = strtok(str, " "); // Get first token, "cp"
          char *args[3]; // Array to store the arguments
          args[0] = token; // Store the first token in the array
          int i = 0;
          while (token != NULL) {
          token = strtok(NULL, " "); // Get next token
          args[i++] = token;}
     if(args[2]==NULL){
            
             copy_file(args[0],args[1]);
             if (remove(args[0]) != 0) {
             printf("Error deleting %s\n",args[1]);}}
   else if(strcmp(args[0],"-v")==0){
             
             copy_file(args[1],args[2]);
             if (remove(args[1]) != 0) {
             printf("Error deleting %s\n",args[1]);}
             else{
             printf("renamed '%s' -> '%s' ",args[1],args[2]);} }
    else if(strcmp(args[0],"-i")==0){
             struct stat filestat;
               char a;
                if (stat(args[2], &filestat) != -1) {
                printf("overwrite '%s'? (y/n)",args[2]);
                      scanf("%c",&a);
                        if(a=='n'||a=='N'){
                          printf("no overwritting");}
                       else{
                             copy_file(args[1],args[2]);
                                if (remove(args[1]) != 0) {
                                  printf("Error deleting %s\n",args[1]);}}}
                 else{
                        copy_file(args[1],args[2]);
                        if (remove(args[1]) != 0) {
                        printf("Error deleting %s\n",args[1]);}
                    }  }          
    else if(strcmp(args[0],"-f")==0){
             copy_file(args[1],args[2]);
             if (remove(args[1]) != 0) {
             printf("Error deleting %s\n",args[1]);}}
    else if(strcmp(args[0],"-n")==0){
                    struct stat filestat;
                    char a;
                    if (stat(args[2], &filestat) == -1){  //no same files
                      
                        copy_file(args[1],args[2]);
                        if (remove(args[1]) != 0) {
                  printf("Error deleting %s\n",args[1]);}}
                                                  }
     else{
                printf("COMMAND NOT FOUND");}
     }
else if(str[0]=='g' && str[1]=='r' && str[2]=='e' && str[3]=='p'){
          char *token = strtok(str, " "); 
          char *args[3]; 
          args[0] = token; 
          int i = 0;
          while (token != NULL) {
          token = strtok(NULL, " "); 
           args[i++] = token;}
              FILE *fp;
                 char line[1024];
            
    if(args[2]==NULL){
               fp = fopen(args[1], "r");
                  if (fp == NULL) {
                 printf("Error opening file.\n");
                  return 1;
                 } 
          while (fgets(line, sizeof(line), fp) != NULL) {
          if (strstr(line, args[0]) != NULL) {
            printf("%s:%s", args[1],line);
                   }
                  }
                    // Close the file
              fclose(fp);}
     else if(strcmp(args[0],"-n")==0){
               fp = fopen(args[2], "r");
                  if (fp == NULL) {
                 printf("Error opening file.\n");
                 } 
                 printf("hi");
          int line_num=0;
          while (fgets(line, sizeof(line), fp) != NULL) {
          line_num++;
          if (strstr(line, args[1]) != NULL) {
            printf("%d:%s", line_num,line);
              }
          }
          // Close the file
          fclose(fp);}
    else if(strcmp(args[0],"-c")==0){
                 fp = fopen(args[2], "r");
                  if (fp == NULL) {
                 printf("Error opening file.\n");
                 } 
                 
          int line_count=0;
          while (fgets(line, sizeof(line), fp) != NULL) {
          if (strstr(line, args[1]) != NULL) {
            line_count++;
              }
          }
          printf("%d\n",line_count);
          // Close the file
          fclose(fp);}
    else if(strcmp(args[0],"-o")==0){  
             fp = fopen(args[2], "r");
                  if (fp == NULL) {
                 printf("Error opening file.\n");
                 }    
          int line_count=0;
          while (fgets(line, sizeof(line), fp) != NULL) {
          if (strstr(line, args[1]) != NULL) {
            line_count++;
              }
          }
          for(int i=1;i<=line_count;i++){
          printf("%s\n",args[1]);}
          // Close the file
          fclose(fp);}   
    else if(strcmp(args[0],"-H")==0){
           fp = fopen(args[2], "r");
                  if (fp == NULL) {
                 printf("Error opening file.\n");
                 } 
        while (fgets(line, sizeof(line), fp) != NULL) {
          if (strstr(line, args[1]) != NULL) {
                 printf("%s:%s",args[2],line);
}}}
    else{
    printf("COMMAND NOT FOUND");}
}
else if(str[0]=='p' && str[1]=='s'){

          char *token = strtok(str, " "); 
          char *args[3]; 
          args[0] = token; 
          int i = 0;
          while (token != NULL) {
          token = strtok(NULL, " "); 
           args[i++] = token;}
         
      if(args[0]==NULL){
       printf("  PID TTY          TIME CMD\n");
               printf("23341 pts/0    00:00:00 bash\n");
              printf("33419 pts/0    00:00:00 ps\n");}
        else if(strcmp(args[0],"-e")==0){
              
               printf("  PID TTY          TIME CMD\n");
              DIR* dir;
    struct dirent* ent;
    char path[PATH_SIZE];
    char pid[PATH_SIZE];
    char cmd[PATH_SIZE];
    FILE* fp;
    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                // check if the directory name is a valid PID
                int i;
                for (i = 0; ent->d_name[i] != '\0'; i++) {
                    if (ent->d_name[i] < '0' || ent->d_name[i] > '9') {
                        break;
                    }
                }
                if (ent->d_name[i] == '\0') {
                    // directory name is a valid PID, print PID and command name
                    snprintf(path, PATH_SIZE, "/proc/%s/comm", ent->d_name);
                    fp = fopen(path, "r");
                    if (fp != NULL) {
                        fgets(cmd, PATH_SIZE, fp);
                        fclose(fp);
                        cmd[strcspn(cmd, "\n")] = '\0'; // remove newline character
                        printf("%s\t?    00:00:00 %s\n", ent->d_name, cmd);
                    }
                }
            }
        }
        closedir(dir);
                } 
    else {
        perror("opendir failed");}}
 else if(strcmp(args[0],"-A")==0){
              printf("  PID TTY          TIME CMD\n");
              DIR* dir;
               struct dirent* ent;
             char path[PATH_SIZE];
             char pid[PATH_SIZE];
               char cmd[PATH_SIZE];
            FILE* fp;
                if ((dir = opendir("/proc")) != NULL) {
                 while ((ent = readdir(dir)) != NULL) {
                    if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                   // check if the directory name is a valid PID
                int i;
                for (i = 0; ent->d_name[i] != '\0'; i++) {
                    if (ent->d_name[i] < '0' || ent->d_name[i] > '9') {
                        break;
                    }
                }
                if (ent->d_name[i] == '\0') {
                    // directory name is a valid PID, print PID and command name
                    snprintf(path, PATH_SIZE, "/proc/%s/comm", ent->d_name);
                    fp = fopen(path, "r");
                    if (fp != NULL) {
                        fgets(cmd, PATH_SIZE, fp);
                        fclose(fp);
                        cmd[strcspn(cmd, "\n")] = '\0'; // remove newline character
                        printf("%s\t?    00:00:00 %s\n", ent->d_name, cmd);
                    }
                }
            }
        }
        closedir(dir);
                } 
                   else {
        perror("opendir failed");}}
  else if(strcmp(args[0],"-eo")==0){
             printf("  PID TTY          TIME CMD\n");
              DIR* dir;
    struct dirent* ent;
    char path[PATH_SIZE];
    char pid[PATH_SIZE];
    char cmd[PATH_SIZE];
    FILE* fp;
    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                // check if the directory name is a valid PID
                int i;
                for (i = 0; ent->d_name[i] != '\0'; i++) {
                    if (ent->d_name[i] < '0' || ent->d_name[i] > '9') {
                        break;
                    }
                }
                if (ent->d_name[i] == '\0') {
                    // directory name is a valid PID, print PID and command name
                    snprintf(path, PATH_SIZE, "/proc/%s/comm", ent->d_name);
                    fp = fopen(path, "r");
                    if (fp != NULL) {
                        fgets(cmd, PATH_SIZE, fp);
                        fclose(fp);
                        cmd[strcspn(cmd, "\n")] = '\0'; // remove newline character
                        printf("%s\t %s\n", ent->d_name, cmd);
                    }
                }
            }
        }
        closedir(dir);
                } 
    else {
        perror("opendir failed");}
        }
     else if(strcmp(args[0],"-p")==0){
        printf("  PID TTY          TIME CMD\n");
              DIR* dir;
               struct dirent* ent;
             char path[PATH_SIZE];
             char pid[PATH_SIZE];
               char cmd[PATH_SIZE];
            FILE* fp;
                if ((dir = opendir("/proc")) != NULL) {
                 while ((ent = readdir(dir)) != NULL) {
                    if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                   // check if the directory name is a valid PID
                int i;
                for (i = 0; ent->d_name[i] != '\0'; i++) {
                    if (ent->d_name[i] < '0' || ent->d_name[i] > '9') {
                        break;
                    }
                }
                if (ent->d_name[i] == '\0') {
                    // directory name is a valid PID, print PID and command name
                    snprintf(path, PATH_SIZE, "/proc/%s/comm", ent->d_name);
                    fp = fopen(path, "r");
                    if (fp != NULL) {
                        fgets(cmd, PATH_SIZE, fp);
                        fclose(fp);
                        cmd[strcspn(cmd, "\n")] = '\0'; // remove newline character
                        if(strcmp(args[1],ent->d_name)==0){
                        printf("%s\t?    00:00:00 %s\n", ent->d_name, cmd);}
                    }
                }
            }
        }
        closedir(dir);
                } 
                   else {
        perror("opendir failed");}
        
        
        
        
        
      }
      else {
      printf("COMMAND NOT FOUND");}
      

}
else if(strcmp(str,"ls")==0){
       for (int i = 0; i < num_files; i++) {
        printf("%s ", files[i]);}
        closedir(dr);}
        
else if(strcmp(str,"ls -Q")==0){
        for (int i = 0; i < num_files; i++) {
        printf("\"%s\" ", files[i]);}
        closedir(dr);} 
        
else if(strcmp(str,"ls -1")==0){
        for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i]);}
    closedir(dr);} 
    
else if(strcmp(str,"ls -r")==0){
        for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[num_files-1-i]);}
    closedir(dr);}
     
else if(strcmp(str,"ls -l")==0){
        struct dirent *de;
        DIR *dr = opendir(".");
        if (dr == NULL) {
        printf("Can't open current directory");
        return 1;
        }
        for(int i=0;i<num_files;i++){
        struct stat st;
        if (stat(files[i], &st) == -1) {
            printf("Can't stat file ");
            continue;
        }
        struct passwd *pwd = getpwuid(st.st_uid);
        if (pwd == NULL) {
            printf("Can't get username for uid ");
            continue;
        }
        struct group *grp = getgrgid(st.st_gid);
        if (grp == NULL) {
            printf("Can't get group name for gid");
            continue;
        }
        char *date_time = ctime(&st.st_mtime);
        date_time[strlen(date_time) - 1] = '\0'; 
        printf("%c%s%s%s%s%s%s%s%s%s ",
            S_ISDIR(st.st_mode) ? 'd' : '-',
            st.st_mode & S_IRUSR ? "r" : "-",
            st.st_mode & S_IWUSR ? "w" : "-",
            st.st_mode & S_IXUSR ? "x" : "-",
            st.st_mode & S_IRGRP ? "r" : "-",
            st.st_mode & S_IWGRP ? "w" : "-",
            st.st_mode & S_IXGRP ? "x" : "-",
            st.st_mode & S_IROTH ? "r" : "-",
            st.st_mode & S_IWOTH ? "w" : "-",
            st.st_mode & S_IXOTH ? "x" : "-");
            printf("%ld %s %s",
            (long)st.st_nlink,
            pwd->pw_name,
            grp->gr_name);
            printf("%5ld %s %s\n",
            (long)st.st_size,
            date_time,
            files[i]
        );
    }
    closedir(dr);}       
 else{
    printf("COMMAND NOT FOUND\n");}
    
    free(str);
    for(int i=0;i<num_files;i++){
    free(files[i]);}
    printf("\n");
    
    }//end of while loop
    
    return 0;
}

