#include <iostream>
#include "libs/EdubotLib.hpp"
#include <chrono>
#include <thread>

void viraDireita(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);
void viraEsquerda(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);
void viraAtras(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);


int main(){
	bool fezCurva = false;
	bool estadoCurva = false;
	int numeroCurvas = 0;
   
    EdubotLib *bot = new EdubotLib();
    const float DIST_SONARES = 0.06; // PACMAN
    //const float DIST_SONARES = 0.2; // MAZE
    
    
    if(bot->connect()){ 
	    while(bot->isConnected()){
	    		bot->sleepMilliseconds(200);
	    		
	    		//Se move com velocidade 1 enquanto nao encontra parede na frente em um raio de 0.5 metros
	    		bot->move(1);
	    		do{
	    			
	    		}while(bot->getSonar(3) > 0.5);
	    		
	    		//Se move com velocidade 0.2 enquanto nao encontra parede na frente em um raio de DIST_SONARES definido
	    		bot->move(0.2);
	    		
	    		do{
	    			
	    		}while(bot->getSonar(3) > DIST_SONARES );
    			
    			
    			//Variaveis frente,esquerda e direita
    			float frente = bot->getSonar(3);
    			float direita = bot->getSonar(6);
    			float esquerda = bot->getSonar(0);

    			//Printa variaveis na tela
    			std::cout << "Frente:"<< frente << std::endl;
    			std::cout << "Esquerda:"<< esquerda << std::endl;
    			std::cout << "Direita:"<< direita << std::endl;
			
			
			
			//ROTACAO(0)
	    		
	    		//Frente bloqueada, segue direita.
	    		if(numeroCurvas == 0 && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);

	    		//Frente e direita bloqueada, segue esquerda
	    		else if(numeroCurvas == 0 && direita < DIST_SONARES && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);

	    		//Frente,direita e esquerda bloqueada, vira atras
	    		else if(numeroCurvas == 0 && direita < DIST_SONARES && frente < DIST_SONARES && esquerda < DIST_SONARES && !fezCurva)
	    			viraAtras(bot, &fezCurva, &numeroCurvas);

	    		//ROTACAO(90)

	    		//Frente bloqueada, segue esquerda
	    		if(numeroCurvas == 1 && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);

	    		//Frente e direita bloqueada, segue direita
	    		else if(numeroCurvas == 1 && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);

	    		//Frente,direita e esquerda bloqueada, vira atras
	    		else if(numeroCurvas == 1 && !fezCurva)
	    			viraAtras(bot, &fezCurva, &numeroCurvas);

	    		//ROTACAO(-90)
	    		
	    		//Frente bloqueada, segue direita
	    		if(numeroCurvas == -1 && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);

	    		//Frente e direita bloqueada, segue esquerda
	    		else if(numeroCurvas == -1 && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		
	    		
	    		if((numeroCurvas == -2 || numeroCurvas == 2) && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);
	    		else if((numeroCurvas == -2 || numeroCurvas == 2) && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		
	    		
	    		/*if(bot->getBumper(0)){
	    			bot->move(-1);
	    			bot->sleepMilliseconds(300);
	    			bot->rotate(15);
	    			bot->sleepMilliseconds(600);
	    		}
	    		if(bot->getBumper(1)){
	    			bot->move(-1);
	    			bot->sleepMilliseconds(300);
	    			bot->rotate(15);
	    			bot->sleepMilliseconds(600);
	    		}
	    		if(bot->getBumper(2)){
	    			bot->move(1);
	    			bot->sleepMilliseconds(300);
	    			bot->rotate(15);
	    			bot->sleepMilliseconds(600);
	    		}
	    		if(bot->getBumper(3)){
	    			bot->move(1);
	    			bot->sleepMilliseconds(300);
	    			bot->rotate(15);
	    			bot->sleepMilliseconds(600);
	    		}*/
	    		
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