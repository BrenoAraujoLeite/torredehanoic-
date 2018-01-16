#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
setlocale(LC_ALL,"Portuguese");
    //Declaracao de Variaveis
    bool execucao=true;
    char comando;

    //Execucao do Jogo
    while(execucao){
    //Menu
    system("cls");
    cout<<"*******************************"<<endl;
    cout<<"Iniciar (Pressione X)"<<endl;
    cout<<"Intrucoes (Pressione H)"<<endl;
    cout<<"Sair (Pressione S)"<<endl;
    cout<<"*******************************"<<endl;
    cout<<"Digite o comando: ";
    cin>>comando;

    //Sair
    if(comando=='s' || comando=='S'){
        system("cls");
        cout<<"Jogo Finalizado";
        execucao=false;
    }
    }
return 0;
}
