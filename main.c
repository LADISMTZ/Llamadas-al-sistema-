#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

void verificar(int fd) {

    if (fd < 0){
        if (errno == EAGAIN){

            printf("Archivo bloqueado.\n");
            exit(1);

        }
        if (errno == EACCES){

            printf("Problema de permisos del archivo.\n");
            exit(1);

        }

        if (errno ==  EBADF ){

            printf("Mal descriptor del archivo.\n");
            exit(1);

        }

        if (errno == EINTR){

            printf("Una llamada al sistema fue interrumpida.\n");
            exit(1);

        }
        else{

            printf("Error desconocido.\n");
            exit(1);
        }
    }
}

int main(){
    int fd,  n, m;
    float buff;
    fd = open("datos2.txt", 0);
    verificar(fd);
    m = read(fd, &buff, sizeof(float));
    verificar(m);
    printf("%f\n", buff);
    m = read(fd, &buff, sizeof(float));
    verificar(m);
    printf("%f\n", buff);
    m = read(fd, &buff, sizeof(float));
    verificar(m);
    printf("%f\n", buff);
    m = read(fd, &buff, sizeof(float));
    verificar(m);
    printf("%f\n", buff);
    m = read(fd, &buff, sizeof(float));
    verificar(m);
    printf("%f\n", buff);
    close(fd);

}



/* PASO 2 TAREA
int fd,  n, m;
   float arreglo [3]={1,2,3};
    fd=creat("datos.txt",777);
    n= write(fd, arreglo, sizeof(arreglo));
    verificar(n);

 */



/* PASO 3 TAREA
int fd,  n, m;
float buff;
float arreglo [3]={1,2,3};
fd = open("datos.txt", 0);
verificar(fd);
m = read(fd, &buff, sizeof(float));
verificar(m);
printf("%f\n", buff);
m = read(fd, &buff, sizeof(float));
verificar(m);
printf("%f\n", buff);
m = read(fd, &buff, sizeof(float));
verificar(m);
printf("%f\n", buff);
close(fd);*/


/* PASO 4 TAREA
    int fd,  n, m;
     float n1=10, n2=11, n3=12, n4=13, n5=14;
    fd = open("datos2.txt", 1);
    verificar(fd);
    n= write(fd, &n1, sizeof(float));
    verificar(n);
    printf("%d\n", n);
    n= write(fd, &n2, sizeof(float));
    verificar(n);
    printf("%d\n", n);
    n= write(fd, &n3, sizeof(float));
    verificar(n);
    printf("%d\n", n);
    n= write(fd, &n4, sizeof(float));
    verificar(n);
    printf("%d\n", n);
    n= write(fd, &n5, sizeof(float));
    verificar(n);
    printf("%d\n", n);
    close(fd);
 * */