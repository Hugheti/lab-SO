#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_filho_b, pid_filho_c;
    
    printf("Eu sou o processo A (PID: %d) e meu pai é %d\n", getpid(), getppid());
    
    pid_filho_b = fork();
    if (pid_filho_b < 0) {
        perror("Falha na criação do processo B");
        return 1;
    } else if (pid_filho_b == 0) {
        sleep(1);
        printf("Eu sou o processo B (PID: %d) e meu pai é %d\n", getpid(), getppid());
        
        pid_filho_c = fork();
        if (pid_filho_c < 0) {
            perror("Falha na criação do processo C");
            return 1;
        } else if (pid_filho_c == 0) {
            sleep(1);
            printf("Eu sou o processo C (PID: %d) e meu pai é %d\n", getpid(), getppid());
            printf("Processo C concluindo execução.\n");
            exit(0);
        }
        
        wait(NULL);
        printf("Processo B concluindo execução.\n");
        exit(0);
    }
    
    wait(NULL);
    printf("Processo A concluindo execução.\n");
    printf("Árvore de processos finalizada com sucesso!\n");
    return 0;
}
