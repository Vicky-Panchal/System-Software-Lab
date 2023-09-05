#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    clock_t start, end;
    pid_t pid;

    start = clock();

    pid = getpid(); 

    end = clock(); 

    double elapsed_time_ms = (double)(end - start) * 1000000.0/CLOCKS_PER_SEC;

    printf("Process ID: %d\n", pid);
    printf("Time taken (microseconds): %.2lf\n", elapsed_time_ms);

    return 0;
}

