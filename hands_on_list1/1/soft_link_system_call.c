/*#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* symlink_path = "./soft_link_system_call2";

    int result = symlink(source_path, symlink_path);
    if (result == -1) {
        perror("symlink");
        return 1;
    }

    return 0;
}*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
int v = symlink("example.txt","destSL2");
if(v<0)
	{perror("Failed"); return 1; }
int f = link("example.txt","destHL2");
if(f<0)
	{perror("Failed"); return 1;}
int e = mknod("destFIFO2",S_IFIFO,0);
if(e<0) perror("Failed");
return 0;
}




