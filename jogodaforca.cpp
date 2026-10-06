#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#include <time.h>
#define TAM 3
using namespace std;
void limpatela (){

system ("CLS");

}
string retornapalavraaleatoria (){


string palavras[3]= {"abacaxi", "manga", "morango"};


int indicealeatorio=rand()%3;

return palavras[indicealeatorio];
}

string retornapalavramascara(string palavra, int tamanhodapalavra){


        int cont=0;

    string palavracommascara;

    while (cont<tamanhodapalavra){

        palavracommascara+="_";
        cont ++;



}


return palavracommascara;




}
void exibestatus(string palavracommascara, int tamanhodapalavra, int tentativasrestantes, string letrajaarriscada, string mensagem){
  cout<<mensagem<<"\n";
cout <<"A palavra  eh: "<<palavracommascara <<" (Tamanho: "<<tamanhodapalavra <<")";
cout <<"\n\n Tentativas restantes: "<<tentativasrestantes;



int cont;
cout<<"\n\n Letras ja arriscadas: ";

for(cont=0;cont<letrajaarriscada.size(); cont++){

 cout<<letrajaarriscada[cont]<<", ";

       }




}

int jogar (int numerodejogadores){
    //palavra a ser adivinhada
    string palavra;


//comfere numero de jogadores

if (numerodejogadores==1){

 palavra =retornapalavraaleatoria();

}else{


    cout<<"\ndigite uma palavra sem seu amigo saber:  ";
    cin>>palavra;





        }






int tamanhodapalavra=palavra.size();

//palavra mascarada
string palavracommascara=retornapalavramascara (palavra, tamanhodapalavra);

int tentativas=0, maximodetentativas=15;
int cont=0;;
char letra;
int opcao;
string letrajaarriscada;
string mensagem;
string palavraarriscada;
bool jadigitouletra=false, acertouletra=false;


while (palavra!=palavracommascara&&(maximodetentativas-tentativas)>0){

limpatela();



exibestatus(palavracommascara, tamanhodapalavra,maximodetentativas-tentativas, letrajaarriscada, mensagem);


    cout<<
    "\nDigite uma letra ou digite 1 para arriscar a palavra: ";
    cin>>letra;
    //se didigtar 1 deixa o usuario arriscar a apalavra inteira
    if(letra=='1'){

        cin>>palavraarriscada;
        if (palavraarriscada==palavra){

           palavracommascara=palavraarriscada;}
           else{ tentativas=maximodetentativas;


        }

    }


    //percorre as letras ja arriscadas
    for(cont=0;cont<tentativas;cont++){

        if (letrajaarriscada[cont]==letra){

            mensagem="\nEssa letra ja foi arriscada!!!\n";


            jadigitouletra=true;

        }


    }
//se for letra nova
if (jadigitouletra==false){

    letrajaarriscada+=tolower(letra);
    //percorre a palavra real se a letra existir

    for (cont=0;cont<tamanhodapalavra;cont++){


        if (palavra[cont]==tolower(letra)){


            palavracommascara[cont]=palavra[cont];


             acertouletra=true;
        }


    }
    if (acertouletra==false){


    mensagem="   voce errou uma letra!\n";


}else{
mensagem="   voce acertou  uma letra!\n";




   }

tentativas++;

}
jadigitouletra=false;
acertouletra=false;

      }


if (palavra==palavracommascara){
        limpatela();
        cout<<"Parabens voce venceu!!!!!!!";
        cout<<"\n Deseja reiniciar?";
        cout<<"\n1-SIM";
        cout<<"\n2-NAO";
        cin>>opcao;
       return opcao;



}else{
  limpatela();
    cout<<"voce perdeuuuuuuuu";
     cout<<"\n Deseja reiniciar?";
    cout<<"\n1-SIM";
    cout<<"\n2-NAO";
    cin>>opcao;
       return opcao;

        }


}
void menuincial (){
  int opcao=0;

    while (opcao<1||opcao>3){
        limpatela();
        cout<<"Bem vindo ao jogo";
        cout<<"\n1- Jogar singleplayer";
        cout<<"\n2- Jogar em Dupla";
        cout<<"\n3- sobre";
        cout<<"\n4- Sair";
        cout<<"\nEscolha uma opcao e tecle ENTER: ";

cin>>opcao;

switch (opcao){

case 1:
    //inicia o jogo
     if (jogar(1) ==1){
       menuincial();


     }
    break;

case 2:

     if (jogar(2) ==1){
       menuincial();


     }







    break;

case 3:
      cout <<" Informacoes do jogo";

    break;

case 4:
     cout<<" \nAte mais :) \n\n";
    break;




       }


    }



}


int main (){

 srand((unsigned)time (NULL));

menuincial ();






return 0;
}
