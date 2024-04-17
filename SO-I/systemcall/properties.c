// Guilherme Silveira Machado (196890)

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    char *arquivo = argv[1];

    struct stat fileStat;
    if (stat(arquivo, &fileStat) < 0) {
        perror("Erro ao obter informações do arquivo");
        return 1;
    }

    struct passwd *pw = getpwuid(fileStat.st_uid);

    printf("ID do Dono: %s\n", pw->pw_name);
    printf("Tamanho Total (em bytes): %lld\n", (long long) fileStat.st_size);
    printf("Data de Criação: %s", ctime(&fileStat.st_ctime));
    printf("Data de Modificação: %s", ctime(&fileStat.st_mtime));
    printf("Último Acesso: %s", ctime(&fileStat.st_atime));

    return 0;
}