#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL,"portuguese");

    char senha [50];
    char usuario [50];
    
    printf("----------------Login----------------\n");

    printf("Usuário:\n");
    scanf("%s", usuario);
    printf("Senha:\n");
    scanf("%s", senha);

    while(strcmp(usuario,"admin") != 0 || strcmp(senha,"1234") != 0){
        printf("Usuário ou senha estão incorretos\n");

        printf("Usuário:\n");
        scanf("%s", usuario);
        printf("Senha:\n");
        scanf("%s", senha);


}

    printf("Acesso Permitido");


}