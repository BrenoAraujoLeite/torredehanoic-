#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include "rlutil.h"
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
    rlutil::saveDefaultColor();                 //Salvando Cor do Console
    setlocale(LC_ALL,"Portuguese");             //Utilizando Para Escrever Caracteres Especiais
    rlutil::setConsoleTitle("Torre de Hanoi");  //Alterando Nome do Terminal

    //Declaracao de Variaveis Para Execução do Jogo
    bool execucao=true;      //Variavel que roda o jogo
    char comando;            //Variavel para a captura dos comandos

    //Execucao do Jogo

    while(execucao){   //Laço de Execução do Programa

    //Menu
    system("cls");
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-------------------Torre de Hanoi--------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------Menu--------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"---------------Iniciar (Pressione X)-----------------"<<endl;
    cout<<"---------------Intrucoes (Pressione H)---------------"<<endl;
    cout<<"---------------Sair (Pressione S)--------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"------------------By: Breno e Italo------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cin>>comando;   //Entrada do comando
    //Fim do Menu

    //Se o Comando for Jogar
    if(comando=='x' || comando=='X'){
        system("cls");                //Apaga o Terminal
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"--------------------Modo de Jogo---------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-------------Singleplayer(Pressione s)---------------"<<endl;
        cout<<"-------------Multiplayer (Pressione m)---------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cin>>comando;                 //Entrada do Multi ou single player

        //Se for singleplayer
        if(comando=='s' || comando=='S'){
        system("cls");             //Limpa Terminal
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"--------------Escolha o nivel de jogo:---------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------Facil (Pressione f)-----------------"<<endl;
        cout<<"-----------------Medio (Pressione m)-----------------"<<endl;
        cout<<"----------------Dificil (Pressione d)----------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cin>>comando;              //Entrada da Dificuldade

        //Selecionando Nivel
        int nivel;    //Declara a variavel nivel
        //Detecta o nivel e atribui a quantidade
        if(comando=='f' || comando=='F'){nivel=3;}
        if(comando=='m' || comando=='D'){nivel=5;}
        if(comando=='d' || comando=='M'){nivel=7;}

        //Interacao Jogador - Nome
        char nome[111];   //Cria a String do Nome
        system("cls");    //Limpa o terminal
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cin.ignore();     //Ignora os Buffers acumulados
        cout<<"----------------Insira o seu nome------------------- "<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Nome: ";
        cin.getline(nome,111);   //Captura o nome do jogador na string


        //Codigo do Jogo e Laço de inicializacao
        bool play=true;   //Variavel de Execução do Jogo
        //Laço em que roda o jogo
        while(play){
        //Declaracao de Variaveis
        clock_t tempo;                    //Variavel Tempo
        int peca, movimento;              //Variaveis de Peça e do Movimento para a Jogada
        bool again=false, vitoria=false;  //Variaveis relacionadas a jogar novamente e vitoria
        char comando;                     //Captura os Comandos (Jogar novamente...)
        int contador=0;                   //Contador de Jogadas
        int score;                        //Armazenamento da Pontuação
        int jogo[nivel][3];               //Declaração da Matriz que Armazena o Jogo
            for(int i=0; i<nivel; i++){   //Contruindo a Matriz inicial
                jogo[i][0]=i+1;
                jogo[i][1]=0;
                jogo[i][2]=0;
            }
        //^^Contrucao da Matriz do Jogo ^^

        //Laço Da Jogatina
        while(!again){        //Verifica se o jogo pode ser executado (Primeira jogatina ou jogar novamente)
            tempo=clock();    //Captura o clock para a medição do tempo

            //Compilando a Matriz do Jogo
            system("cls");  //Limpando Terminal
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"Jogadas: "<<contador<<endl;  // Contador de Jogadas
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"        |                 |                 |"<<endl;
                for(int i=0; i<nivel; i++){    //Imprimindo a Matriz Percorrendo Cada Linha e Coluna
                    for(int j=0; j<3; j++){    //Imprimindo a Matriz Percorrendo Cada Linha e Coluna
                        if(jogo[i][j]==0){
                            rlutil::setColor(7); //Define a cor para o console
                            cout<<"        |        "<<" ";     //Se o valor for 0
                        }else{
                        if(jogo[i][j]==1){rlutil::setColor(12); cout<<"      *(1)*      "<<" ";}  //Se for 1
                        if(jogo[i][j]==2){rlutil::setColor(9); cout<<"     **(2)**     "<<" ";}  //Se for 2
                        if(jogo[i][j]==3){rlutil::setColor(14); cout<<"    ***(3)***    "<<" ";}  //Se for 3
                        if(jogo[i][j]==4){rlutil::setColor(10); cout<<"   ****(4)****   "<<" ";}  //Se for 4
                        if(jogo[i][j]==5){rlutil::setColor(3); cout<<"  *****(5)*****  "<<" ";}  //Se for 5
                        if(jogo[i][j]==6){rlutil::setColor(8); cout<<" ******(6)****** "<<" ";}  //Se for 6
                        if(jogo[i][j]==7){rlutil::setColor(13); cout<<"*******(7)*******"<<" ";}  //Se for 7
                        }
                    }
                    cout<<endl;
                }
            rlutil::resetColor(); //Volta a cor do console
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"        1                 2                 3"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<endl;
            //Fim da Tela Com a Matriz e as Colunas

            //Capturando a Jodada
            cout<<"Sr(a).: "<<nome<<endl;   //Interação Jogador
            cout<<"Digite a peca <1 à "<<nivel<<">: ";
            cin>>peca;                      //Entrada da Peça
            cout<<"Digite a jogada <1 à 3>: ";
            cin>>movimento;                 //Entrada da Coluna do Movimento

            //Computando a Jogada se For Valida
            if((peca>=1 && peca<=nivel)&&(movimento>=1 && movimento<=3)){ //Verifica se e uma peça e coluna valida
            for(int i=0; i<nivel; i++){     //Percorre cada linha e coluna ate localizar a peça
                for(int j=0; j<3; j++){     //Percorre cada linha e coluna ate localizar a peça
                    if(jogo[i][j]==peca){   //Verifica se a posição da matriz é a peça
                        if(i==0 || jogo[i-1][j]==0){   //Verifica se a peça pertence a primeira linha ou é a primeira peça da sua coluna
                            //Com essas condições a peça pode ser movida
                            //Agora indentifica se a coluna e valida para a jogada
                            int cont=(nivel-1);   //Define o indice da ultima linha da matriz para percorrela de forma decrescente
                            while(cont>=0){       //Inicia a verificação
                                if((cont==(nivel-1) && jogo[cont][movimento-1]==0) || (jogo[cont][movimento-1]==0 && jogo[cont+1][movimento-1]>peca)){
                                    //Na primeira parte verifica se a coluna esta vazia e portanto a jogada e valida
                                    //Caso contrario localiza o primeiro zero da coluna e verifica se a primeira peça do monte (posição+1) e maior que a peça a ser movida
                                    //Satisfazendo umas das condições a jogada e valida e segue a seguir:
                                    jogo[i][j]=0;                 //Zerando onde a peça se encontrava inicialmente
                                    jogo[cont][movimento-1]=peca; //Aloca a peça na posição do movimento
                                    cont=-1;                      //Define o contador um numero para sair do laço

                                }else{
                                    //Caso nao satisfaça a primeira condição de a coluna ser nula ira decrementando ate achar um zero na coluna
                                    cont--; //Decremento
                                }

                            }
                        }
                    }
                }
            }             //Saida do laço da Jogada
            contador++;   //Incremento de Jogadas no contador
            }

            //Apos Sair da Jogada Detectando o Caso de Vitoria
            if(jogo[0][1]==1 || jogo[0][2]==1){  //Condição: A segunda ou a terceira coluna da primeira linha da matriz ser o 1
                vitoria=true;   //Assim Define Vitoria
                again=true;     //Encerra a Execução dessa Jogatina
                tempo=clock()-tempo;  //Calcula o tempo de Jogatina
                //Calculo da Pontuacao
                score=(((pow(2,nivel)-1)/contador)*7000)+(((pow(2,nivel)-1)/(tempo/100))*3000);
                //Relaciona as jogadas e o tempo a uma pontuação estabelecida
            }
        }

                //Saida do Laco da Jogatina (Again)
                if(vitoria){ //Imprimindo a Vitoria
                system("cls"); //Limpando Terminal
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"------------------------Vitoria----------------------"<<endl;
                cout<<"Sr(a).: "<<nome<<endl;  //Jogador
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Jogadas: "<<contador<<endl; //Jogadas
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Pontuacao: "<<score<<endl;  //Pontuação
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Tempo: "<<tempo/100<<" segundos."<<endl; //Tempo de jogatina
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                //Jogar Novamente ou Sair do Laco de Execucao
                cout<<"Continuar (S/N)"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cin>>comando; //Entrada de Jogar novamente
                    if(comando=='n' || comando=='N'){ //Caso nao queria
                        play=false;  //Altera a variavel e sai do laço do jogo
                    }
                }
        //Fim do Laco do Jogo
        }
    }
    }   //Fim do Laço Singleplayer

    if(comando=='m' || comando=='M'){ //Caso o Usuario Escolha Multiplayer

        //Escolha da Dificuldade
        system("cls"); //Limpa terminal
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"--------------Escolha o nivel de jogo:---------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------Facil (Pressione f)-----------------"<<endl;
        cout<<"-----------------Medio (Pressione m)-----------------"<<endl;
        cout<<"----------------Dificil (Pressione d)----------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cin>>comando; //Entrada da Dificuldade

        //Selecionando Nivel
        int nivel;  //Declara o nivel
        if(comando=='f' || comando=='F'){nivel=3;} //Atribui as linhas a matriz com relação ao nivel
        if(comando=='m' || comando=='D'){nivel=5;} //Atribui as linhas a matriz com relação ao nivel
        if(comando=='d' || comando=='M'){nivel=7;} //Atribui as linhas a matriz com relação ao nivel

        //Nome - Interacao Jogador
        system("cls"); //Limpa Terminal
        char player1[111]; //String do Nome Jogador 1
        cin.ignore();  //Ignora comandos anteriores no buffer
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"---------------Insira os seus nomes----------------- "<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Nome do jogador 1: ";
        cin.getline(player1,111); //Captura do nick do jogador 1
        char player2[111]; //String do Nome Jogador 2
        cout<<"Nome do jogador 2: ";
        cin.getline(player2,111); //Captura do nick do jogador 2

        //Codigo do Jogo e Laço de inicializacao
        bool play=true;  //Variavel da Execição do Jogo
        while(play){     //Laço do Jogo
        //Declaracao de Variaveis
        clock_t tempo1, tempo2;  //Variaveis para armazenar o tempo
        int peca, movimento;     //Peças e Movimentos
        bool again=false, vitoria=false;  //Detecta jogar novamente e vitoria
        char comando;  //Entrada de comando
        int contador=0; //Contador de Jogadas
        int score1, score2; //Score player 1 e 2
        int jogo[nivel][3]; //Define a matriz do jogo
            for(int i=0; i<nivel; i++){  //Compila a Matriz inicial do jogo linha por linha
                jogo[i][0]=i+1; //elemento da coluna 1
                jogo[i][1]=0;   //elemento da coluna 2
                jogo[i][2]=0;   //elemento da coluna 3
            }
        //^^Contrucao da Matriz do Jogo ^^

        //Laço Da Jogatina Player 1
        while(!again){ //Condição de execução
            tempo1=clock(); //Captura do clock inicial
            //Compilando a Matriz
            system("cls");
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"Jogadas: "<<contador<<endl;  //Contador de Jogadas
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"        |                 |                 |"<<endl;
                for(int i=0; i<nivel; i++){ //Imprimindo a matriz
                    for(int j=0; j<3; j++){
                        if(jogo[i][j]==0){
                            rlutil::setColor(7);
                            cout<<"        |        "<<" ";
                        }else{
                        if(jogo[i][j]==1){rlutil::setColor(12); cout<<"      *(1)*      "<<" ";}
                        if(jogo[i][j]==2){rlutil::setColor(9); cout<<"     **(2)**     "<<" ";}
                        if(jogo[i][j]==3){rlutil::setColor(14); cout<<"    ***(3)***    "<<" ";}
                        if(jogo[i][j]==4){rlutil::setColor(10); cout<<"   ****(4)****   "<<" ";}
                        if(jogo[i][j]==5){rlutil::setColor(3); cout<<"  *****(5)*****  "<<" ";}
                        if(jogo[i][j]==6){rlutil::setColor(8); cout<<" ******(6)****** "<<" ";}
                        if(jogo[i][j]==7){rlutil::setColor(13); cout<<"*******(7)*******"<<" ";}
                        }
                    }
                    cout<<endl;
                }
            rlutil::resetColor();
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"        1                 2                 3"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<endl;

            //Capturando a Jodada
            cout<<"Sr(a).: "<<player1<<endl;   //Interação Jogador
            cout<<"Digite a peca <1 à "<<nivel<<">: ";
            cin>>peca;                      //Entrada da Peça
            cout<<"Digite a jogada <1 à 3>: ";
            cin>>movimento;

            //Computando a Jogada
            if((peca>=1 && peca<=nivel)&&(movimento>=1 && movimento<=3)){ //Verifica se e uma peça e coluna valida
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
            //Incremento de Jogadas no Contador
            contador++;
            }
            //Detectando Vitoria
            if(jogo[0][1]==1 || jogo[0][2]==1){
                vitoria=true;
                again=true;
                tempo1=clock()-tempo1;
                //Calculo da Pontuacao
                score1=(((pow(2,nivel)-1)/contador)*7000)+(((pow(2,nivel)-1)/(tempo1/100))*3000);
            }
        }

        //Zerando para player 2
        again=false; //Voltando a variavel para a inicial
        vitoria=false; //Voltando a variavel para a inicial
        contador=0; //Voltando ao inicial
            for(int i=0; i<nivel; i++){ //Voltando a matriz inicial
                jogo[i][0]=i+1;
                jogo[i][1]=0;
                jogo[i][2]=0;
            }

        //Laco player2
        while(!again){ //Laço do jogo player 2
            tempo2=clock(); //Definindo clock player 2
            //Compilando a Matriz
            system("cls");
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"Jogadas: "<<contador<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"        |                 |                 |"<<endl;
                for(int i=0; i<nivel; i++){
                    for(int j=0; j<3; j++){
                        if(jogo[i][j]==0){
                            rlutil::setColor(7);
                            cout<<"        |        "<<" ";
                        }else{
                        if(jogo[i][j]==1){rlutil::setColor(12); cout<<"      *(1)*      "<<" ";}
                        if(jogo[i][j]==2){rlutil::setColor(9); cout<<"     **(2)**     "<<" ";}
                        if(jogo[i][j]==3){rlutil::setColor(14); cout<<"    ***(3)***    "<<" ";}
                        if(jogo[i][j]==4){rlutil::setColor(10); cout<<"   ****(4)****   "<<" ";}
                        if(jogo[i][j]==5){rlutil::setColor(3); cout<<"  *****(5)*****  "<<" ";}
                        if(jogo[i][j]==6){rlutil::setColor(8); cout<<" ******(6)****** "<<" ";}
                        if(jogo[i][j]==7){rlutil::setColor(13); cout<<"*******(7)*******"<<" ";}
                        }
                    }
                    cout<<endl;
                }
            rlutil::resetColor();
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"        1                 2                 3"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<endl;

            //Capturando a Jodada
            cout<<"Sr(a).: "<<player2<<endl;   //Interação Jogador
            cout<<"Digite a peca <1 à "<<nivel<<">: ";
            cin>>peca;                      //Entrada da Peça
            cout<<"Digite a jogada <1 à 3>: ";
            cin>>movimento;

            //Computando a Jogada
            if((peca>=1 && peca<=nivel)&&(movimento>=1 && movimento<=3)){ //Verifica se e uma peça e coluna valida
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
            }
            //Detectando Vitoria
            if(jogo[0][1]==1 || jogo[0][2]==1){
                vitoria=true;
                again=true;
                tempo2=clock()-tempo2;
                //Calculo da Pontuacao
                score2=(((pow(2,nivel)-1)/contador)*7000)+(((pow(2,nivel)-1)/(tempo2/100))*3000);
            }
        }

                //Vitoria Detectada - Jogar Novamente
                system("cls"); //Limpa Terminal
                if(score1==score2){ //Pontuação Igual
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"----------------------Empate!------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Pontuacao: "<<score1<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Tempo: "<<tempo1/100<<" segundos."<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                //Jogar Novamente ou Sair do Laco de Execucao
                cout<<"Continuar (S/N)"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cin>>comando;
                    if(comando=='n' || comando=='N'){
                        play=false;
                    }
                }else{
                if(score1>score2){ //Vitoria Player 1
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------Vitoria do Jogador 1----------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Parabéns Sr(a).: "<<player1<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Pontuacao: "<<score1<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Tempo: "<<tempo1/100<<" segundos."<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Jogador Perdedor: "<<player2<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Pontuacao: "<<score2<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Tempo: "<<tempo2/100<<" segundos."<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                //Jogar Novamente ou Sair do Laco de Execucao
                cout<<"Continuar (S/N)"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cin>>comando;
                    if(comando=='n' || comando=='N'){
                        play=false;
                    }
                }else{ //Vitoria Player 2
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------Vitoria do Jogador 2----------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Parabéns Sr(a).: "<<player2<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Pontuacao: "<<score2<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Tempo: "<<tempo2/100<<" segundos."<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Jogador Perdedor: "<<player1<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Pontuacao: "<<score1<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Tempo: "<<tempo1/100<<" segundos."<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                //Jogar Novamente ou Sair do Laco de Execucao
                cout<<"Continuar (S/N)"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cin>>comando;
                    if(comando=='n' || comando=='N'){
                        play=false;
                    }
                }
                }

        //Fim do Laco do Jogo
        }

    } //Fim do Laço Multiplayer

    //Instruções
    if(comando=='h' || comando=='H'){
            system("cls");
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"---------------------Intruções-----------------------"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"O objetivo deste jogo consiste em deslocar todos os"<<endl;
            cout<<"discos da haste inicial onde se encontram, para outra"<<endl;
            cout<<"-----------------------Regras------------------------"<<endl;
            cout<<"1. Deslocar um disco de cada vez (Primeiro da Haste);"<<endl;
            cout<<"2. Cada disco não poderá ser colocado em outro menor."<<endl;
            cout<<"3. Cada disco está representado pelo seu número."<<endl;
            cout<<"4. Para o movimento escolha a peça e a coluna."<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            rlutil::anykey("Pressione uma tecla para continuar...\n"); //Esperando qualquer tecla

    }
    //Sair
    if(comando=='s' || comando=='S'){
        system("cls");
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"--------------------Jogo Finalizado------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"--------Obrigado por Utilizar nossa Ferramenta-------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"---------------------Desenvolvido por:---------------"<<endl;
        cout<<"--------------------------Breno----------------------"<<endl;
        cout<<"----------------------------e------------------------"<<endl;
        cout<<"--------------------------Italo----------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"--------------------------2016-----------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        execucao=false; //Saindo do laço principa do jogo
    }
    }
    //Fim do Jogo
system("pause");
return 0;
}
