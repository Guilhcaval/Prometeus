#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char usuarioRegistrado [50];
char senhaRegistrada [50];


void salvarUsuario (char usua [50] , char senha [50]){
    strcpy(usuarioRegistrado, usua);
    strcpy(senhaRegistrada, senha);

}

void Registro (){
    char Nomeusua [50];
    char Usuasenha [50];

    printf("Digite seu nome de usuário:\n");
    scanf("%s", Nomeusua);
    printf("Digite sua senha:\n");
    scanf("%s", Usuasenha);

    printf("Registro de usuário '%s' salvo com sucesso\n", Nomeusua);
    printf("Registro de senha '%s' salvo com sucesso\n", Usuasenha);

    salvarUsuario (Nomeusua, Usuasenha);


    
    
}

void Conecte (){

    char usuaDigi[50];
    char senhaDigi[50];

    printf("----------LOGIN----------\n");

    printf("Usuário:\n");
    scanf("%s",usuaDigi);
    printf("Senha\n");
    scanf("%s",senhaDigi);

    while (strcmp(usuaDigi, usuarioRegistrado) !=0 || strcmp(senhaDigi, senhaRegistrada) !=0){
        printf("Usuário ou senha estão incorretos\n");

        printf("Usuário:\n");
        scanf("%s",usuaDigi);
        printf("Senha\n");
        scanf("%s",senhaDigi);
    }

    printf("Acesso Permitido");

}

int main (){
    setlocale(LC_ALL,"portuguese");

    int opcoes; 

    printf("-----------------HOME-----------------\n");
    printf("1-Registre-se\n");
    printf("2-Conecte-se\n");
    printf("3-Sair\n");
    scanf("%d", &opcoes);

    switch(opcoes){
        case 1:
         Registro();
        case 2:
        Conecte();
        case 3:
        break;
        printf("Saindo do Programa");
        break;
        default:
        printf("Opção Inválida");
    }
    


}