#include "header.h"   
int copy_file(const char* src_path, const char* dst_path) {
    FILE* src_file = fopen(src_path, "rb");
    if (src_file == NULL) {
        fprintf(stderr, "Error opening source file '%s': %s\n", src_path, strerror(errno));
        return 1;
    }

    char dst_file_path[1024];
    int dst_is_dir = 0;
    FILE* dst_file = NULL;

    // Check if the destination path is a directory
    if (dst_path[strlen(dst_path) - 1] == '/') {
        char* src_path_copy = strdup(src_path);
        snprintf(dst_file_path, sizeof(dst_file_path), "%s%s", dst_path, basename(src_path_copy));
        free(src_path_copy);
        dst_is_dir = 1;
    } else {
        strncpy(dst_file_path, dst_path, sizeof(dst_file_path));
    }

    dst_file = fopen(dst_file_path, "wb");
    if (dst_file == NULL) {
        fprintf(stderr, "Error opening destination file '%s': %s\n", dst_file_path, strerror(errno));
        return 1;
    }

    char buf[4096];
    size_t read_bytes = 0;
    while ((read_bytes = fread(buf, 1, sizeof(buf), src_file)) > 0) {
        fwrite(buf, 1, read_bytes, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}

void prompt(){
char c[maxcl];
getcwd(c,sizeof(c));
printf("%s:%s$ ", getlogin(), c);}
int compare_strings(const void* a, const void* b) {
    char* lower_a = strdup(*(const char**)a);
    char* lower_b = strdup(*(const char**)b);
    for (int i = 0; i < strlen(lower_a); i++) {
        lower_a[i] = tolower(lower_a[i]);
    }
    for (int i = 0; i < strlen(lower_b); i++) {
        lower_b[i] = tolower(lower_b[i]);
    }
    int cmp = strcmp(lower_a, lower_b);
    free(lower_a);
    free(lower_b);
    return cmp;
}

