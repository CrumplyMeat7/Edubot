#include <iostream>
#include "libs/EdubotLib.hpp"
#include <chrono>
#include <thread>

void viraDireita(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);
void viraEsquerda(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);
void viraAtras(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);


int main(){
	//Variavel para evitar q o bot faça varias rotações seguidas e para fazer a contagem de rotações pledge
	bool fezCurva = false;
	int numeroCurvas = 0;
   
    EdubotLib *bot = new EdubotLib();

    //Variavel que define a distancia usada nos sonares em ambos mapas
    //const float DIST_SONARES = 0.07; // PACMAN
    const float DIST_SONARES = 0.2; // MAZE
    //const float TAM_CELULA = 0.4f;
    
    
    if(bot->connect()){ 
	    
	    //rotaciona para redefinir o angulo 0
	    //bot->rotate(180);//APENAS PARA PACMAN
	    bot->sleepMilliseconds(1300);
	    while(bot->isConnected()){
	    		bot->sleepMilliseconds(200);


	    		//Configurações de pausa e velocidade para PACMAN
	    		/*if(bot->getSonar(3) > DIST_SONARES){
	    		bot->move(0.5);
	    		}
	    		bot->sleepMilliseconds(920);*/ //PACMAN(MUITO INCONSISTENTE POR ALGUM MOTIVO)
	    		
	    		
	    		//Configurações de pausa e velocidade para MAZE
	    		if(bot->getSonar(3) > DIST_SONARES){
	    		bot->move(1);
	    		}
	    		bot->sleepMilliseconds(700);
	    		
	    		bot->stop();
	    		
    			
    			
    			//Variaveis frente,esquerda e direita
    			float frente = bot->getSonar(3);
    			float direita = bot->getSonar(6);
    			float esquerda = bot->getSonar(0);

    			//Printa variaveis na tela
    			std::cout << "Frente:"<< frente <<std::endl;
    			std::cout << "Esquerda:"<< esquerda << std::endl;
    			std::cout << "Direita:"<< direita << std::endl;
    			bool frenteLivre = frente > DIST_SONARES;
    			bool direitaLivre = direita > DIST_SONARES;
    			bool esquerdaLivre = esquerda > DIST_SONARES;
    			bot->sleepMilliseconds(200);
			
			
			
			//ROTACAO(0)
	    		
	    		//Frente bloqueada, segue direita.
	    		if(numeroCurvas == 0 && !frenteLivre && direitaLivre && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);

	    		//Frente e direita bloqueada, segue esquerda
	    		else if(numeroCurvas == 0 && !frenteLivre && !direitaLivre && esquerdaLivre && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);

	    		//Frente,direita e esquerda bloqueada, vira atras
	    		else if(numeroCurvas == 0 && !frenteLivre && !direitaLivre && !esquerdaLivre && !fezCurva)
	    			viraAtras(bot, &fezCurva, &numeroCurvas);

	    		//ROTACAO(90)

	    		//Segue esquerda se estiver livre
	    		if(numeroCurvas == 1 && esquerdaLivre && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);

	    		//Frente e esquerda bloqueada, segue direita
	    		else if(numeroCurvas == 1 && !frenteLivre && !esquerdaLivre && direitaLivre && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);

	    		//Frente,direita e esquerda bloqueada, vira atras
	    		else if(numeroCurvas == 1 && !frenteLivre && !direitaLivre && !esquerdaLivre && !fezCurva)
	    			viraAtras(bot, &fezCurva, &numeroCurvas);

	    		//ROTACAO(-90)
	    		
	    		//Segue direita se estiver livre
	    		if(numeroCurvas == -1 && direitaLivre && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);

	    		//Frente e direita bloqueada, segue esquerda
	    		else if(numeroCurvas == -1 && !frenteLivre && !direitaLivre && esquerdaLivre && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		
	    		//Frente,direita e esquerda bloqueada, vira atras
	    		else if(numeroCurvas == -1 && !frenteLivre && !direitaLivre && !esquerdaLivre && !fezCurva)
	    			viraAtras(bot, &fezCurva, &numeroCurvas);
	    		
	    		//ROTACAO(180)
	    		if((numeroCurvas == -2 || numeroCurvas == 2) && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);
	    		else if((numeroCurvas == -2 || numeroCurvas == 2) && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		
	    		
	    		
	    		std::cout << "Sentido Rotação:"<< numeroCurvas << std::endl;
	    		fezCurva = false;
	    }
    		 bot->disconnect();
    }
    	
    else{
        std::cout << "Could not connect on robot!" << std::endl;
    }
    return 0;
}
//----------------------FUNCOES DE ROTACOES-------------------------------
void viraDireita(EdubotLib* bot,bool* fezCurva,int* numeroCurvas){

	bot->rotate(90);
	bot->sleepMilliseconds(1500);
	*fezCurva = true;
	if(*numeroCurvas == 2)
		(*numeroCurvas)-=3;
	else
		(*numeroCurvas)++;
}

void viraEsquerda(EdubotLib* bot,bool* fezCurva, int* numeroCurvas){

	bot->rotate(-90);
	bot->sleepMilliseconds(1500);
	*fezCurva = true;
	if(*numeroCurvas == -2)
		(*numeroCurvas)+=3;
	else
		(*numeroCurvas)--;
}

void viraAtras(EdubotLib* bot,bool* fezCurva,int* numeroCurvas){
	
	bot->rotate(180);
	bot->sleepMilliseconds(1800);
	*fezCurva = true;
	(*numeroCurvas)=-2;
	
}