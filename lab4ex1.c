#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid_filho;
    
    pid_filho = fork();
    
    if (pid_filho < 0) {
        printf("Erro ao criar processo filho!\n");
        return 1;
    } else if (pid_filho == 0) {
        printf("Eu sou o processo filho, meu PID é %d.\n", getpid());
    } else {
        printf("Eu sou o processo pai, meu PID é %d e criei um filho com PID %d.\n", getpid(), pid_filho);
    }
    
    return 0;
}
