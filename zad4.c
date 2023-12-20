#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
/* Napisati naredbu cat koja štampa sadržaj fajla koji je proslijeđen kao argument. Ukoliko je
proslijeđen i flag -l tada se štampaju samo neparne linije fajla. */
char* readLine(int r1){
    char c;
    char* l=malloc(sizeof(char)*100);
    int m=read(r1,&c,1);
    int p=0;

    while(m>0 && c!='\n'){
       l[p]=c;
        p++;
        m=read(r1,&c,1);
    }    
    
    if(p==0){
        return NULL;
    }else{
        l[p]='\0';
        return l;
    }

}


int main(int argc, char* argv[]){

if(argc !=2 && argc !=3){
    printf("Nedovoljan broj argumeata");
    return 1;
}

int r1=open(argv[1],O_RDONLY);
if(r1<0){
    printf("greska pri otvaranju fajla");
    return 2;
}

    if(argc==3){
        if(strcmp(argv[2],"-n")==0){
            char* line=readLine(r1);
            int i=1;
            while(line !=NULL){
                if(i%2!=0){
                    printf("%s \n",line);            
                }
            i++;
            line=readLine(r1);
        }
        return 3;
    }}
            char* line=readLine(r1);
            while(line !=NULL){
                printf("%s \n",line);            
                line=readLine(r1);
}
return 0;

}
