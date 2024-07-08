#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_N 10000000

// Function to check if a number is a tetrahedral number
int isTetrahedral(int num) {
    int p = 1;
    int tetrahedral = 0;

    while (tetrahedral < num) {
        tetrahedral = (p * (p + 1) * (p + 2)) / 6;
        if (tetrahedral == num) {
            return 1;  // It's a tetrahedral number
        }
        p++;
    }

    return 0;  // It's not a tetrahedral number
}

// Function to perform the work in each child process
void childProcess(int start, int end, int* array, int* sharedMemory) {
    // Iterate through the assigned range
    for (int i = start; i <= end; ++i) {
        if (isTetrahedral(i)) {
            array[i - start] = 1;  // Mark as a tetrahedral number
        } else {
            array[i - start] = 0;  // Mark as not a tetrahedral number
        }
    }

    // Store the array in shared memory for communication with the main process
    for (int i = start; i <= end; ++i) {
        sharedMemory[i] = array[i - start];
    }
}

int main() {
   // clock_t start_time = clock();
    int N, K;

    // Read N and K from the input file
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    fscanf(inputFile, "%d %d", &N, &K);
    fclose(inputFile);

    if (N <= 0 || K <= 0 || N > MAX_N) {
        fprintf(stderr, "Invalid input values\n");
        exit(EXIT_FAILURE);
    }

    // Create shared memory for communication between processes
    int fd = shm_open("/tetrahedral", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error in shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, (N + 1) * sizeof(int)) == -1) {
        perror("Error in ftruncate");
        exit(EXIT_FAILURE);
    }

    int* sharedMemory = mmap(NULL, (N + 1) * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (sharedMemory == MAP_FAILED) {
        perror("Error in mmap");
        exit(EXIT_FAILURE);
    }

    // Fork K child processes
    for (int i = 0; i < K; ++i) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("Error in fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {  // Child process
            // Calculate the range of numbers to be handled by this process
            int start = i * (N / K) + 1;
            int end = (i + 1) * (N / K);
            if(i == K-1){
                end = N;
            }

            // Allocate space for local result array
            int* array = (int*)malloc((end - start + 1) * sizeof(int));

            // Call the function to perform the work in the child process
            childProcess(start, end, array, sharedMemory);

            // Free allocated memory
            free(array);

            exit(EXIT_SUCCESS);
        }
    }

    // Wait for all child processes to finish
    for (int i = 0; i < K; ++i) {
        wait(NULL);
    }

    // Consolidate results from shared memory and write to output file
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Create log files for each process
    for (int i = 0; i < K; ++i) {
        char logFileName[20];
        snprintf(logFileName, sizeof(logFileName), "OutFile%d.txt", i + 1);

        FILE* logFile = fopen(logFileName, "w");
        if (logFile == NULL) {
            perror("Error opening log file");
            exit(EXIT_FAILURE);
        }

        int start = i * (N / K) + 1;
        int end = (i + 1) * (N / K);
        if(i == K-1){
            end=N;
        }

        for (int j = start; j <= end; ++j) {
            fprintf(logFile, "%d: %s\n", j, (sharedMemory[j] == 1) ? "a tetrahedral number" : "Not a tetrahedral number");
        }

        fclose(logFile);
    }

    // Create the main log file
    FILE* mainLogFile = fopen("OutMain.txt", "w");
    if (mainLogFile == NULL) {
        perror("Error opening main log file");
        exit(EXIT_FAILURE);
    }

    // Consolidate results from shared memory
    int r=0;
    int s;
    for (int i = 1; i <= N; ++i) {
        if( i >= (r*(N/K)) + 1 ){
            r++;
            s=0;
        }
        if (sharedMemory[i] == 1) {
            if(s==0){
                if(r == 1){
                    fprintf(mainLogFile, "P%d: %d", r , i);
                }
                else{
                fprintf(mainLogFile, "\nP%d: %d", r , i);}
                s++;
            }
           else{
            fprintf(mainLogFile, " %d", i);}
        }
        
    }

    fclose(mainLogFile);

    // Detach and remove shared memory
    if (munmap(sharedMemory, (N + 1) * sizeof(int)) == -1) {
        perror("Error in munmap");
        exit(EXIT_FAILURE);
    }

    if (shm_unlink("/tetrahedral") == -1) {
        perror("Error in shm_unlink");
        exit(EXIT_FAILURE);
    }
   //clock_t end_time = clock();
  // double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  // printf("%f",cpu_time_used);
    return 0;
}
