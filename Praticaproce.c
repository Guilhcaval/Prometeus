#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void salvarUsuario (char usua [50] , char senha [50]){


}

void Registro (){
    char Nomeusua [50];
    char Usuasenha [50];

    printf("Digite seu nome de usuário:\n");
    scanf("%s", Nomeusua);
    printf("Digite sua senha:\n");
    scanf("%s", Usuasenha);

    printf("Registro de usuário '%s' salvo com sucesso\n", Nomeusua);
    printf("Registro de senha '%s' salvo com sucesso", Usuasenha);

    salvarUsuario (Nomeusua, Usuasenha);
    
    
}

/*void Conecte (){







}*/

int main (){
    setlocale(LC_ALL,"portuguese");

    int opcoes; 

    printf("-----------------HOME-----------------\n");
    printf("1-Registre-se\n");
    printf("2-Conecte-se\n");
    scanf("%d", &opcoes);

    if(opcoes == 1){
        Registro();
    }


}