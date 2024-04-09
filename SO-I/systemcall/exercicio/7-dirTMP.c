#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define STDERR_FILENO 2
#define STDOUT_FILENO 1

void write_str(int fd, const char *str) {
    while (*str) {
        write(fd, str++, 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write_str(STDERR_FILENO, "Uso: ");
        write_str(STDERR_FILENO, argv[0]);
        write_str(STDERR_FILENO, " <nome_do_diretorio>\n");
        return 1;
    }

    char *nome_do_diretorio = argv[1];
    char *caminho_do_diretorio = "/tmp/";

    char caminho_completo[strlen(caminho_do_diretorio) + strlen(nome_do_diretorio) + 1];
    sprintf(caminho_completo, "%s%s", caminho_do_diretorio, nome_do_diretorio);

    int status = mkdir(caminho_completo, 0700);
    if (status == -1) {
        char error_message[100];
        sprintf(error_message, "Erro ao criar o diretório\n");
        write_str(STDERR_FILENO, error_message);
        return 1;
    }

    char success_message[100];
    sprintf(success_message, "Diretório '%s' criado com sucesso em '/tmp/'.\n", nome_do_diretorio);
    write_str(STDOUT_FILENO, success_message);
