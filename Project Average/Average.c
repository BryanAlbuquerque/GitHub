#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define CHAVE 3
#define MAX_USUARIOS 100

typedef struct {
    char usuario[30];
    char senha[10];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int total_usuarios = 0;


typedef struct {
    char nome[30];
} Universidade;


void media_unip() {
    int n1, n2, n3;
    double media;

    printf("Digite a nota da sua prova, a nota do PIM e sua nota da disciplina: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    media = (n1 + n2 + n3) / 3.0;

    if (media >= 7) {
        printf("Parabéns, você foi aprovado! Sua nota foi: %.2f\n", media);
    } else {
        printf("Sua nota não atingiu a média. Terá que ser agendado o exame!\n");
    }
}

void media_fmu() {
    int n1, n2;
    float media;

    printf("Digite suas notas: ");
    scanf("%d %d", &n1, &n2);

    media = n1 * 0.4 + n2 * 0.6;

    if (media >= 7) {
        printf("Aluno aprovado!\n");
    } else if (media < 4) {
        printf("Aluno reprovado\n");
    } else {
        printf("Aluno deverá realizar a prova novamente!\n");
    }
}

// Criptografia
void criptografar(char *input) {
    while (*input) {
        *input = *input + CHAVE;
        input++;
    }
}

void descriptografar(char *input) {
    while (*input) {
        *input = *input - CHAVE;
        input++;
    }
}

// Função para cadastro
void cadastrar_usuario() {
    if (total_usuarios >= MAX_USUARIOS) {
        printf("Número máximo de usuários atingido.\n");
        return;
    }

    char usuario[30], senha[10];
    printf("Digite um nome de usuário: ");
    scanf("%s", usuario);

    printf("Digite uma senha: ");
    scanf("%s", senha);

    criptografar(senha);

    strcpy(usuarios[total_usuarios].usuario, usuario);
    strcpy(usuarios[total_usuarios].senha, senha);
    total_usuarios++;

    printf("Usuário cadastrado com sucesso!\n");
}

// Função de login
int login() {
    char usuario[30], senha[10];
    printf("Digite o nome de usuário: ");
    scanf("%s", usuario);
    printf("Digite a senha: ");
    scanf("%s", senha);

    criptografar(senha);

    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(usuarios[i].usuario, usuario) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return 1;
        }
    }
    return 0;
}

// Função principal
int main() {
    setlocale(LC_ALL, "portuguese");

    int opcao;

    do {
        printf("\n1. Cadastrar usuário\n");
        printf("2. Login\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_usuario();
                break;
            case 2:
                if (login()) {
                    printf("Login bem-sucedido!\n");

                    // Menu de universidades
                    int universidade_opcao;
                    printf("Escolha uma universidade para calcular sua média:\n");
                    printf("1. UNIP\n");
                    printf("2. FMU\n");
                    printf("3. Anhanguera (Ainda não implementada)\n");
                    printf("4. Estácio (Ainda não implementada)\n");
                    printf("5. Sair\n");
                    scanf("%d", &universidade_opcao);

                    switch (universidade_opcao) {
                        case 1:
                            media_unip();
                            break;
                        case 2:
                            media_fmu();
                            break;
                        case 3:
                            printf("Opção não implementada.\n");
                            break;
                        case 4:
                            printf("Opção não implementada.\n");
                            break;
                        case 5:
                            printf("Saindo...\n");
                            break;
                        default:
                            printf("Opção inválida!\n");
                    }
                } else {
                    printf("Falha no login!\n");
                }
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
