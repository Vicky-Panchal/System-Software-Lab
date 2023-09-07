#include<stdio.h>
#include<unistd.h>

int main() {
    char buffer[1024];

    size_t bytesRead;
    while ((bytesRead = read(0, buffer, sizeof(buffer))) > 1) {
        
        write(1, buffer, bytesRead);
    }

    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;

}
