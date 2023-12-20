#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/*Napisati C program koji imitira naredbu cp. Prihvata dva fajla kao argumente. Sadržaj prvog
fajla se kopira u drugi. Obraditi moguće greške. */

int main(int argc, char* argv[]){
    
    if(argc != 3){
        printf("Greska");
        return 1;
    }

    int f1=open(argv[1],O_RDONLY);
    int f2=open(argv[2],O_WRONLY|O_CREAT);
    

    if(f1<0 || f2<0){
        printf("Nemoguce otovoriti");
        return 2;

    }

    char* c;
    int m1=read(f1,&c,1);

    while(m1>0){
        write(f2,&c,1);
        read(f1,&c,1);
    }
    return 0;

}
