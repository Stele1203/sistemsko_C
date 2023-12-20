#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
/*Napisati C program koji kao argumente ima dva direktorijuma. Program kopira sve fajlove
iz prvog direktorijuma, u drugi. Obraditi moguće greške.*/
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Treba da sadrzi makar dva argumenta");
        return 1;
    }

    DIR* d1 = opendir(argv[1]);
    DIR* d2 = opendir(argv[2]);

    if (d1 == NULL || d2 == NULL) {
        printf("Neki folder se ne moze otvoriti ");
        return 2;
    }

    struct dirent* a = readdir(d1);

    while (a != NULL) {
        if (a->d_type == DT_REG) {
            char* path1 = malloc(sizeof(char) * 100);
            char* path2 = malloc(sizeof(char) * 100);

            strcpy(path1, argv[1]);
            strcat(path1, "/");
            strcat(path1, a->d_name);

            strcpy(path2, argv[2]);
            strcat(path2, "/");
            strcat(path2, a->d_name);

            int f1 = open(path1, O_RDONLY);
            if (f1 < 0) {
                printf("Greska pri otvaranju fajala");
                free(path1);
                free(path2);
                return 3;
            }

            int f2 = open(path2, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (f2 < 0) {
                printf("Greska pri otvaranju fajala");
                free(path1);
                free(path2);
                close(f1);
                return 3;
            }

            char c;
            int read_file = read(f1, &c, 1);

            while (read_file > 0) {
                int write_file = write(f2, &c, 1);
                read_file = read(f1, &c, 1);
            }

            free(path1);
            free(path2);
            close(f1);
            close(f2);
        }

        a = readdir(d1);
    }

    closedir(d1);
    closedir(d2);

    return 0;
}

