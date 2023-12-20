#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
/* Napisati C program koji simulira naredbu ls. Programu se zadaje 0 ili 1 argument koji
predstavlja folder. Ukoliko argument nije proslijeđen izlistava se aktivni direktorijum.*/
int main(int argc, char* argv[]){

    if(argc !=1 && argc !=2){
        printf("Pogresan broj argumenata");
        return 10;
    }

    char* s=malloc(sizeof(char)*100);

    if(argc==2){
        strcpy(s,argv[1]);
    }else{
        strcpy(s,".");
    }


    DIR* d=opendir(s);

    if(d == NULL){
        printf("Direktorijum nije otvoren");
        return 1;
    }

    struct dirent* dir=readdir(d);

    while(dir != NULL){

        printf("%s \n",dir->d_name);
        dir=readdir(d);
    }
    closedir(d);
    return 0;

}
