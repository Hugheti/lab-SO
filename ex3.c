#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define TAM_BUFFER 128

int main() {
    int arquivo_origem, arquivo_destino;
    char buffer[TAM_BUFFER];
    ssize_t lidos, escritos;
    
    arquivo_origem = open("lab2_ex3_origem.txt", O_RDONLY);
    if (arquivo_origem < 0) {
        printf("Falha ao abrir arquivo de origem\n");
        return 1;
    }
    
    arquivo_destino = open("lab2_ex3_destino.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (arquivo_destino < 0) {
        printf("Falha ao criar arquivo de destino\n");
        close(arquivo_origem);
        return 1;
    }
    
    while ((lidos = read(arquivo_origem, buffer, TAM_BUFFER)) > 0) {
        char *ptr = buffer;
        int restantes = lidos;
        
        while (restantes > 0) {
            escritos = write(arquivo_destino, ptr, restantes);
            if (escritos < 0) {
                printf("Erro na escrita do arquivo\n");
                close(arquivo_origem);
                close(arquivo_destino);
                return 1;
            }
            restantes -= escritos;
            ptr += escritos;
        }
    }
    
    if (lidos < 0) {
        printf("Erro na leitura do arquivo\n");
    }
    
    if (close(arquivo_origem) < 0 || close(arquivo_destino) < 0) {
        printf("Erro ao fechar arquivos\n");
        return 1;
    }
    
    return 0;
}
