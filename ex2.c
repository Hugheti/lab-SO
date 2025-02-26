#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    char buf[128];
    ssize_t bytes;
    int linhas = 0;
    char *ponteiro;
    
    fd = open("lab2_ex2.txt", O_RDONLY);
    if (fd == -1) {
        printf("Falha na abertura do arquivo\n");
        return 1;
    }
    
    while ((bytes = read(fd, buf, 127)) > 0) {
        buf[bytes] = '\0';
        ponteiro = buf;
        
        for (int i = 0; i < bytes; i++) {
            if (buf[i] == '\n') {
                linhas++;
            }
        }
    }
    
    if (bytes == -1) {
        printf("Erro durante a leitura do arquivo\n");
        close(fd);
        return 1;
    }
    
    // Se o arquivo não terminar com nova linha, ainda conta como uma linha
    if (bytes > 0 && buf[bytes-1] != '\n') {
        linhas++;
    }
    
    printf("Número total de linhas: %d\n", linhas);
    
    close(fd);
    return 0;
}
