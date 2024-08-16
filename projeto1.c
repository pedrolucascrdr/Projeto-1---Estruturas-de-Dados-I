#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct{
    char nl[20], email[80], senha[8];
} User;

void cadastrar(){
    system("cls");
    FILE *file = fopen("cadastro.txt", "w");
    User user;
    printf("Digite seu email: \n");
    scanf("%s", user.email);
    printf("Digite seu nome de usuario: \n");
    scanf("%s", user.nl);
    printf("Digite sua senha: \n");
    scanf("%s", user.senha);
    fprintf(file, "%s, %s, %s", user.email, user.nl, user.senha);
    fclose(file);
}

void listar(){
    system("cls");
    FILE *file = fopen("cadastro.txt", "r");
    User r;
    while(fread(&r, sizeof(User), 1, file)){
        printf("%s", r.nl);
    }
    fclose(file);
}

int tamanho(){
    FILE *file = fopen("cadastro.txt", "r");
    User r;
    int tam = 0;
    while(fread(&r, sizeof(User), 1, file)){
        tam ++;
    }
    fclose(file);
    return tam;
}

void excluir(){
    system("cls");
    int tam = tamanho();
    FILE *file = fopen("cadastro.txt", "r");
    User v[tam];
    fread(v, sizeof(User), tam, file);
    fclose(file);
    User temp[tam];
    printf("Informe o nome do usuario que sera excluido: \n");
    char nl[20];
    scanf("%s", nl);
    int i, j = 0;
    for(i = 0; i < tam; i++){
        if(v[i].nl != nl){
            temp[j] = v[i];
            j++;
        }
    }
    file = fopen("cadastro.txt", "w");
    fwrite(temp, sizeof(User), j, file);
    fclose(file);
}

void editar(){
    system("cls");
    int tam = tamanho();
    FILE *file = fopen("cadastro.txt", "r");
    User v[tam];
    fread(v, sizeof(User), tam, file);
    fclose(file);
    printf("Digite o nome do usuario que sera editado: \n");
    char nl[20];
    scanf("%s", nl);
    int i;
    for(i = 0; i < tam; i++){
        if(v[i].nl == nl){
            printf("Digite o novo nome para o usuario: \n");
            scanf("%[^\n]", v[i].nl);
        }
    }
    file = fopen("cadastro.txt", "w");
    fwrite(v, sizeof(User), tam, file);
    fclose(file);
}

void menu1(){
    int op;
    int x = 0;
    while(x == 0){
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Editar um usuario\n");
    printf("4 - Excluir um usuario\n");
    printf("5 - Sair\n");
    scanf("%d", &op);
    switch(op){
    case 1:
        cadastrar();
    break;
    case 2:
        listar();
    break;
    case 3:
        editar();
    break;
    case 4:
        excluir();
    break;
    case 5:
        return;
    break;
    default:
        printf("Escolha uma opcao valida.\n");
        menu1();
    break;
    }
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    printf("Boas vindas!\n");
    printf("Escolha uma opção para continuar.\n");
    menu1();
    return(0);
}