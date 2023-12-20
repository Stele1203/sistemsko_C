#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
/*Napisati C program koji imitira naredbu grep. Naredbi se proslijeđuje fajl, i string od jedne
riječi. Naredba štampa one linije koje sadrže datu riječ Moguće je proslijediti i flagove -c i -v
(proizvoljnim redom) koji naznačavaju da je potrebno prebrojati linije koje sadrže datu riječ,
odnosno posmatraju suprotni slučaj. Moguće je i samo jedan od ovih flagova proslijediti.
Obraditi moguće greške. */
char* readLine(int r1){
    
    char c;
    int p=0;
    char* line=malloc(sizeof(char)*100);
    int s1=read(r1,&c,1);
    while(s1>0 && c!='\n'){
        line[p]=c;
        p++;
        s1=read(r1,&c,1);
    }

    if(p==0){
        return NULL;
    }else{
        line[p]='\0';
        return line;
    }
}

bool sadrzi(char* a, char* b){
        
    if (strstr(a, b) != NULL) {
        return true;
    } else {
        return false;
    }
}

int main(int argc,char* argv[]){

    if(argc !=3 && argc !=4 && argc != 5){
        printf("Pogresan broj argumenata");
        return 1;
    }

    int r1= open(argv[1],O_RDONLY);
    if(r1<0){
        printf("Greska u fajlu ");
        return 2;
    }
    int sum=0;
    int poj=0;
    char* line= readLine(r1);
    while(line != NULL){
        if(strstr(line,argv[2]) !=NULL){
            printf("%s \n",line);
            poj++;
        }
        sum++;
        line=readLine(r1);
    }
   
    if(argc==4){
        if(strcmp(argv[3],"-c")==0){
            printf("Broj linija koje sadrze rijec je %d",poj);
        }else if(strcmp(argv[3],"-v")==0){
            printf("Broj linija koje na sadrze rijec je %d",sum-poj);        
        }
    }else if(argc==5){
           
        if(strcmp(argv[3],"-c")==0 || strcmp(argv[4],"-c")==0){
            printf("Broj linija koje sadrze rijec je %d \n",poj);
        }

        if(strcmp(argv[3],"-v")==0 || strcmp(argv[4],"-v")==0){
            printf("Broj linija koje ne sadrze rijec je %d \n",sum-poj);
        }
    }   
}
