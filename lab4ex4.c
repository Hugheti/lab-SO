#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int N;
    
    if (argc > 1) {
        N = atoi(argv[1]);
        if (N <= 0) {
            fprintf(stderr, "Erro: O número de processos deve ser positivo.\n");
            return 1;
        }
    } else {
        printf("Informe o número de processos filhos: ");
        if (scanf("%d", &N) != 1 || N <= 0) {
            fprintf(stderr, "Entrada inválida. O número deve ser um inteiro positivo.\n");
            return 1;
        }
    }

    printf("Criando %d processos filhos...\n", N);
    
    for (int i = 1; i <= N; i++) {
        pid_t pid = fork();
        
        if (pid < 0) {
            perror("Falha ao criar processo filho");
            return 1;
        }
        else if (pid == 0) {
            printf("Eu sou o filho número %d, meu PID é %d\n", i, getpid());
            exit(0);
        }
    }
    
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    printf("Todos os processos filhos foram finalizados.\n");
    return 0;
}
