#include <iostream>
#include <stdlib.h>
#include <cmath>
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

    //Jogar
    if(comando=='x' || comando=='X'){
        system("cls");
        cout<<"***************************"<<endl;
        cout<<"Escolha o nivel de jogo"<<endl;
        cout<<"Facil (Pressione f)"<<endl;
        cout<<"Medio (Pressione m)"<<endl;
        cout<<"Dificil (Pressione d)"<<endl;
        cout<<"***************************"<<endl;
        cin>>comando;

        //Selecionando Nivel
        int nivel;
        if(comando=='f' || comando=='F'){nivel=3;}
        if(comando=='m' || comando=='D'){nivel=5;}
        if(comando=='d' || comando=='M'){nivel=7;}

        //Codigo do Jogo e La�o de inicializacao
        bool play=true;
        while(play){
        //Declaracao de Variaveis
        int peca, movimento;
        bool again=false, vitoria=false;
        char comando;
        int contador=0;
        int jogo[nivel][3];
            for(int i=0; i<nivel; i++){
                jogo[i][0]=i+1;
                jogo[i][1]=0;
                jogo[i][2]=0;
            }
        //^^Contrucao da Matriz do Jogo ^^

        //La�o Da Jogatina
        while(!again){

            //Compilando a Matriz
            system("cls");
            cout<<"Jogadas: "<<contador<<endl;
            cout<<"-----------"<<endl;
            for(int i=0; i<nivel; i++){
                for(int j=0; j<3; j++){
                    cout<<jogo[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"-----------"<<endl;
            cout<<"1 2 3"<<endl;
            cout<<endl;

            //Capturando a Jodada
            cout<<"Digite a peca: ";
            cin>>peca;
            cout<<"Digite a jogada: ";
            cin>>movimento;

            //Computando a Jogada
            for(int i=0; i<nivel; i++){
                for(int j=0; j<3; j++){
                    if(jogo[i][j]==peca){
                        if(i==0 || jogo[i-1][j]==0){

                            int cont=(nivel-1);
                            while(cont>=0){
                                if((cont==(nivel-1) && jogo[cont][movimento-1]==0) || (jogo[cont][movimento-1]==0 && jogo[cont+1][movimento-1]>peca)){
                                    jogo[i][j]=0;
                                    jogo[cont][movimento-1]=peca;
                                    cont=-1;

                                }else{
                                    cont--;
                                }

                            }
                        }
                    }
                }
            }
            //Incremento de Jogadas
            contador++;

            //Detectando Vitoria
            if(jogo[0][1]==1 || jogo[0][2]==1){
                vitoria=true;
                again=true;
            }
        }

                //Saida do Laco da Jogatina
                if(vitoria){
                system("cls");
                cout<<"Vitoria, jogadas: "<<contador<<endl;
                //Jogar Novamente ou Sair do Laco de Execucao
                cout<<"Continuar (S/N)"<<endl;
                cin>>comando;
                    if(comando=='n' || comando=='N'){
                        play=false;
                    }
                }
        //Fim do Laco do Jogo
        }
    }

    //Instru��es
    if(comando=='h' || comando=='H'){
            system("cls");
            cout<<"-------------------"<<endl;
            cout<<"O objetivo deste jogo consiste em deslocar todos os discos da haste onde se encontram para uma haste diferente."<<endl;
            cout<<"1. Deslocar um disco de cada vez, o qual dever� ser o do topo de uma das tr�s hastes;"<<endl;
            cout<<"2. Cada disco nunca poder� ser colocado sobre outro de valor menor."<<endl;
            cout<<"3. Cada disco esta representado pelo valor do seu tamanho."<<endl;
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
