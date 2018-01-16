#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
setlocale(LC_ALL,"Portuguese");
    //Declaracao de Variaveis
    bool execucao=true;
    char comando, auxiliar;
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

    //Instrucoes
    if(comando=='h' || comando=='H'){
            system("cls");
            cout<<"-------------------"<<endl;
            cout<<"O objetivo deste jogo consiste em deslocar todos os discos da haste onde se encontram para uma haste diferente."<<endl;
            cout<<"1. Deslocar um disco de cada vez, o qual deverá ser o do topo de uma das três hastes;"<<endl;
            cout<<"2. Cada disco nunca poderá ser colocado sobre outro de valor menor."<<endl;
            cout<<"Aperte qualquer tecla para voltar para o menu: ";
            cin>>auxiliar;

    }
    //sair
    if(comando=='s' || comando=='S'){
        system("cls");
        cout<<"Jogo Finalizado";
        execucao=false;
    }
    }
return 0;
}
