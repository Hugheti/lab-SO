#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int arquivo;
    char buffer[128];
    int lidos;
    
    arquivo = open("lab2_ex1.txt", O_RDONLY);
    if (arquivo == -1) {
        printf("Erro: Não foi possível abrir o arquivo\n");
        return 1;
    }
    
    lidos = read(arquivo, buffer, 127);
    if (lidos == -1) {
        printf("Erro: Falha ao ler o arquivo\n");
        close(arquivo);
        return 1;
    }
    
    buffer[lidos] = '\0';
    printf("Conteúdo do arquivo:\n%s\n", buffer);
    
    close(arquivo);
    return 0;
}
