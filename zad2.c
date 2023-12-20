#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


/* Napisati C program koji imitira naredbu wc. Naredba vraća veličinu fajlova, odnosno, broji
koliko karaktera dati fajl sadrži. Moguće je ovoj naredbi proslijediti i flagove -n, koji naznačava
da je potrebno dodati broj redova kao rezultat. Obraditi moguće greške.*/


int main(int argc, char* argv[]){

    if(argc !=2 && argc !=3){
        printf("Netacan broj argumenata");
        return 1;
    }


    int r1=open(argv[1],O_RDONLY);

    if(r1<0){
        printf("Greska pri otvaranju fajla");
        return 2;
    }

    int broj_redova=0;
    int kar=0;
    int c;
    int k1=read(r1,&c,1);

    while(k1>0){
        
        if(c !=' ' && c != '\n' && c !='\0'){
            kar++;
        }
        if(c=='\n'){
            broj_redova++;
        }
        k1=read(r1,&c,1);

    }

    if(argc==3){
        if(strcmp(argv[2],"-n")==0){
            printf("BRoj redova je %d \n",broj_redova);
        }

    }
    printf("Broj karaktera je %d \n",kar);

    return 0;
}
