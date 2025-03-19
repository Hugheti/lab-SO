#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_filho;
    
    pid_filho = fork();
    
    if (pid_filho < 0) {
        perror("Erro ao criar processo filho");
        return 1;
    } else if (pid_filho == 0) {
        printf("Processo filho iniciado. PID: %d\n", getpid());
        
        execlp("ls", "ls", NULL);
        
        perror("Falha ao executar o comando");
        return 1;
    } else {
        printf("Processo pai em execução. PID: %d, Filho PID: %d\n", getpid(), pid_filho);
        
        wait(NULL);
        printf("Comando executado com sucesso.\n");
    }
    
    return 0;
}
