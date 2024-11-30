#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para celular
typedef struct {
    char modelo[50];
    char marca[50];
    double preco;
} Celular;

// Função para cadastrar celular
void cadastrarCelular() {
    Celular celular;

    FILE *file = fopen("C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\Celulares.txt", "a"); // Modo append para adicionar ao final do arquivo

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Coleta dados do celular
    printf("\nDigite o modelo do celular: ");
    fgets(celular.modelo, 50, stdin);
    celular.modelo[strcspn(celular.modelo, "\n")] = 0; // Remove o '\n' do fgets

    printf("Digite a marca do celular: ");
    fgets(celular.marca, 50, stdin);
    celular.marca[strcspn(celular.marca, "\n")] = 0;

    printf("Digite o preço do celular: R$ ");
    scanf("%lf", &celular.preco);
    getchar(); // Limpa o buffer do scanf

    // Grava no arquivo
    fprintf(file, "%s\n%s\n%.2f\n", celular.modelo, celular.marca, celular.preco);

    fclose(file);  // Fecha o arquivo
printf("\nMenu de Opcoes:\n");
    printf("Celular cadastrado com sucesso!\n");
}

// Função para consultar celular
void consultarCelular() {
    char modelo[50];
    Celular celular;
    int achou = 0;

    FILE *file = fopen("C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\Celulares.txt", "r"); // Modo leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\nDigite o modelo do celular que deseja consultar: ");
    fgets(modelo, 50, stdin);
    modelo[strcspn(modelo, "\n")] = 0; // Remove o '\n' do fgets

    // Lê os dados do arquivo
    while (fscanf(file, "%49[^\n]\n%49[^\n]\n%lf\n", celular.modelo, celular.marca, &celular.preco) != EOF) {
        if (strcmp(celular.modelo, modelo) == 0) {
            printf("\nModelo: %s\nMarca: %s\nPreco: R$ %.2f\n", celular.modelo, celular.marca, celular.preco);
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("\nCelular nao encontrado.\n");
    }

    fclose(file);
}

// Função para gerar relatório de todos os celulares
void gerarRelatorio() {
    Celular celular;

    FILE *file = fopen("C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\Celulares.txt", "r"); // Modo leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\nRelatorio de Celulares Cadastrados:\n");
    while (fscanf(file, "%49[^\n]\n%49[^\n]\n%lf\n", celular.modelo, celular.marca, &celular.preco) != EOF) {
        printf("Modelo: %s\nMarca: %s\nPreco: R$ %.2f\n\n", celular.modelo, celular.marca, celular.preco);
    }

    fclose(file);
}

// Função para excluir celular
void excluirCelular() {
    char modelo[50];
    Celular celular;
    int achou = 0;

    FILE *file = fopen("C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\Celulares.txt", "r");  // Modo leitura
    FILE *tempFile = fopen("C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\TempCelulares.txt", "w"); // Modo escrita

    if (file == NULL || tempFile == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    printf("\nDigite o modelo do celular que deseja excluir: ");
    fgets(modelo, 50, stdin);
    modelo[strcspn(modelo, "\n")] = 0;

    // Lê os dados do arquivo e escreve no arquivo temporário, exceto o celular a ser excluído
    while (fscanf(file, "%49[^\n]\n%49[^\n]\n%lf\n", celular.modelo, celular.marca, &celular.preco) != EOF) {
        if (strcmp(celular.modelo, modelo) == 0) {
            achou = 1;
            printf("Celular %s excluido com sucesso!\n", celular.modelo);
        } else {
            fprintf(tempFile, "%s\n%s\n%.2f\n", celular.modelo, celular.marca, celular.preco);
        }
    }

    if (!achou) {
        printf("Celular nao encontrado.\n");
    }

    fclose(file);
    fclose(tempFile);

    // Deleta o arquivo original e renomeia o arquivo temporário
    remove("C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\Celulares.txt");
    rename("C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\TempCelulares.txt", "C:\\Faculdade Com Arquivos\\Aplicativo Cadastrar Celular\\Celulares.txt");
}

// Função principal para o menu
int main() {
    int opcao;

    do {
    	printf("\nInfoTech\n");
    	printf("\n==========\n");
        printf("\nMenu de Opcoes:\n");
        printf("1. Cadastrar Celular\n");
        printf("2. Consultar Celular\n");
        printf("3. Gerar Relatorio\n");
        printf("4. Excluir Celular\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do scanf

        switch (opcao) {
            case 1:
                cadastrarCelular();
                break;
            case 2:
                consultarCelular();
                break;
            case 3:
                gerarRelatorio();
                break;
            case 4:
                excluirCelular();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
