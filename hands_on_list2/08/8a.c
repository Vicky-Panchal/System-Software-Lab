#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    int *ptr = NULL;
    *ptr = 42;

    return 0;
}

