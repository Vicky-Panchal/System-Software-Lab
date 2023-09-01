#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* hardlink_path = "./hard_link_system_call";

    int result = link(source_path, hardlink_path);
    if (result == -1) {
        perror("link");
        return 1;
    }

    return 0;
}

