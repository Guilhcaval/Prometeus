#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// ------------------ LOGIN ------------------

void Limpartela() {
    system("cls || clear");
}

void salvarUsuario(char destinoUsua[50], char destinoSenha[50], const char origemUsua[50], const char origemSenha[50]) {
    strcpy(destinoUsua, origemUsua);
    strcpy(destinoSenha, origemSenha);
}

void Registro(char usua[50], char senha[50]) {
    char Nomeusua[50];
    char Usuasenha[50];

    Limpartela();
    printf("Digite seu nome de usuário:\n");
    scanf("%s", Nomeusua);
    printf("Digite sua senha:\n");
    scanf("%s", Usuasenha);

    salvarUsuario(usua, senha, Nomeusua, Usuasenha);
}

void Conecte(const char usua[50], const char senha[50]) {
    Limpartela();

    char usuaDigi[50];
    char senhaDigi[50];

    printf("----------LOGIN----------\n");

    printf("Usuário:\n");
    scanf("%s", usuaDigi);
    printf("Senha:\n");
    scanf("%s", senhaDigi);

    while (strcmp(usuaDigi, usua) != 0 || strcmp(senhaDigi, senha) != 0) {
        printf("Usuário ou senha incorretos. Tente novamente.\n\n");
        printf("Usuário:\n");
        scanf("%s", usuaDigi);
        printf("Senha:\n");
        scanf("%s", senhaDigi);
    }

    printf("Acesso Permitido!\n");

    Limpartela();
}

int Login(char usua[50], char senha[50]) {
    setlocale(LC_ALL, "Portuguese");
    int opcoes;

    while (1) {
        Limpartela();
        printf("-----------------HOME-----------------\n");
        printf("1 - Registre-se\n");
        printf("2 - Conecte-se\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcoes);

        switch (opcoes) {
            case 1:
                Registro(usua, senha);
                break;
            case 2:
                Conecte(usua, senha);
                return 1;
            case 3:
                printf("Saindo do Programa\n");
                return 0;
            default:
                printf("Opção Inválida\n");
                break;
        }
    }
    return 0;
}

// ------------------ SISTEMA DE ALUGUEL ------------------

char modelos[100][50];
int anos[100];
float precos[100];
int disponiveis[100];
int totalCarros = 0;

char historicoModelos[100][50];
int historicoDias[100];
float historicoPagamentos[100];
int totalAlugueis = 0;

void cadastrarCarro() {
    if (totalCarros >= 100) {
        printf("Limite de carros atingido.\n");
        return;
    }

    printf("Modelo: ");
    scanf(" %[^\n]", modelos[totalCarros]);

    printf("Ano: ");
    scanf("%d", &anos[totalCarros]);

    printf("Preço por dia (R$): ");
    scanf("%f", &precos[totalCarros]);

    disponiveis[totalCarros] = 1;
    totalCarros++;

    printf("Carro cadastrado com sucesso!\n\n");

    Limpartela();
}

void listarCarrosDisponiveis() {
    printf("\nCarros disponíveis:\n");
    int encontrados = 0;
    for (int i = 0; i < totalCarros; i++) {
        if (disponiveis[i]) {
            printf("%d - %s (%d) - R$%.2f/dia\n", i, modelos[i], anos[i], precos[i]);
            encontrados = 1;
        }
    }
    if (!encontrados) {
        printf("Nenhum carro disponível no momento.\n");
    }
    printf("\n");
}

void alugarCarro() {
    int id, dias;

    listarCarrosDisponiveis();
    printf("Informe o ID do carro que deseja alugar: ");
    scanf("%d", &id);

    if (id < 0 || id >= totalCarros || !disponiveis[id]) {
        printf("Carro inválido ou indisponível.\n");
        return;
    }

    printf("Por quantos dias deseja alugar? ");
    scanf("%d", &dias);

    disponiveis[id] = 0;

    float totalPago = dias * precos[id];

    printf("Você alugou o carro %s por %d dias.\n", modelos[id], dias);
    printf("Total a pagar: R$%.2f\n\n", totalPago);

    strcpy(historicoModelos[totalAlugueis], modelos[id]);
    historicoDias[totalAlugueis] = dias;
    historicoPagamentos[totalAlugueis] = totalPago;
    totalAlugueis++;
}

void devolverCarro() {
    char modelo[50];
    printf("\n=== DEVOLVER CARRO ===\n");
    printf("Informe o modelo do carro: ");
    scanf(" %[^\n]", modelo);

    for (int i = 0; i < totalCarros; i++) {
        if (!disponiveis[i] && strcmp(modelos[i], modelo) == 0) {
            disponiveis[i] = 1;
            printf("Carro devolvido com sucesso!\n\n");
            return;
        }
    }

    printf("Carro não encontrado ou já está disponível.\n\n");
}

void exibirHistorico() {
    printf("\n=== HISTÓRICO DE ALUGUEIS ===\n");
    if (totalAlugueis == 0) {
        printf("Nenhum aluguel registrado.\n\n");
        return;
    }

    for (int i = 0; i < totalAlugueis; i++) {
        printf("%s | Dias: %d | Total pago: R$ %.2f\n",
               historicoModelos[i],
               historicoDias[i],
               historicoPagamentos[i]);
    }
    printf("\n");
}

// ------------------ MAIN ------------------

int main() {
    setlocale(LC_ALL, "Portuguese");

    char usuarioRegistrado[50];
    char senhaRegistrada[50];

    if (!Login(usuarioRegistrado, senhaRegistrada)) {
        return 0;
    }

    int opcao;
    do {
        
        printf("==== MENU ====\n");
        printf("1. Cadastrar carro\n");
        printf("2. Listar carros disponíveis\n");
        printf("3. Alugar carros disponíveis\n");
        printf("4. Devolver carros\n");
        printf("5. Exibir o histórico de Aluguéis\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCarro();
                break;
            case 2:
                listarCarrosDisponiveis();
                break;
            case 3:
                alugarCarro();
                break;
            case 4:
                devolverCarro();
                break;
            case 5:
                exibirHistorico();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
