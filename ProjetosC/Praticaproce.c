#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void Limpartela (){
    system("cls");


}



void salvarUsuario (char destinoUsua[50], char destinoSenha[50], const char origemUsua[50], const char origemSenha[50]){
    strcpy(destinoUsua, origemUsua);
    strcpy(destinoSenha, origemSenha);

}

void Registro (char usua[50], char senha [50]){
    char Nomeusua [50];
    char Usuasenha [50];

    printf("Digite seu nome de usuário:\n");
    scanf("%s", Nomeusua);
    printf("Digite sua senha:\n");
    scanf("%s", Usuasenha);

    printf("Registro de usuário '%s' salvo com sucesso\n", Nomeusua);
    printf("Registro de senha '%s' salvo com sucesso\n", Usuasenha);

    salvarUsuario (usua,senha, Nomeusua, Usuasenha);  

}

void Conecte (const char usua[50], const char senha[50]){
    Limpartela();

    char usuaDigi[50];
    char senhaDigi[50];

    printf("----------LOGIN----------\n");

    printf("Usuário:\n");
    scanf("%s",usuaDigi);
    printf("Senha\n");
    scanf("%s",senhaDigi);

    while (strcmp(usuaDigi, usua) !=0 || strcmp(senhaDigi, senha) !=0){
        printf("Usuário ou senha estão incorretos\n");

        Limpartela();

        printf("Usuário:\n");
        scanf("%s",usuaDigi);
        printf("Senha\n");
        scanf("%s",senhaDigi);
    }

    printf("Acesso Permitido\n");

}

int Login (char usua[50], char senha[50]){
    setlocale(LC_ALL,"portuguese");
    
    Limpartela();

    int opcoes;
    int cont = 1; 

    while (cont){
    Limpartela();

    printf("-----------------HOME-----------------\n");
    printf("1-Registre-se\n");
    printf("2-Conecte-se\n");
    printf("3-Sair\n");
    scanf("%d", &opcoes);

    switch(opcoes){
        case 1:
        Registro(usua,senha);
        break;
        case 2:
        Conecte(usua,senha);
        return 1;
        case 3:
        printf("Saindo do Programa\n");
        return 0;;
        break;
        default:
        printf("Opção Inválida\n");
    }
}
return 0;

}


int main(){
    setlocale(LC_ALL,"portuguese");
    Limpartela();

    char usuarioRegistrado [50];
    char senhaRegistrada [50];
    
    Login(usuarioRegistrado,senhaRegistrada); 

    printf("---------MENU---------");



    }
