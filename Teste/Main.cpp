#include <iostream>
#include "libs/EdubotLib.hpp"

void viraDireita(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);
void viraEsquerda(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);
void viraAtras(EdubotLib* bot, bool* fezCurva,int* numeroCurvas);

int main(){
	bool fezCurva = false;
	bool estadoCurva = false;
	int numeroCurvas = 0;
   
    EdubotLib *bot = new EdubotLib();
    const float DIST_SONARES = 0.06;
    
    
    if(bot->connect()){ 
	    while(bot->isConnected()){
	    		bot->sleepMilliseconds(200);
	    		float frente = bot->getSonar(3);
    			float direita = bot->getSonar(6);
    			float esquerda = bot->getSonar(0);
	    		/*bot->move(1);
	    		do{
	    			
	    		}while(bot->getSonar(3) > 0.5);*/
	    		bot->move(0.2);
	    		do{
	    			
	    		}while(bot->getSonar(3) > DIST_SONARES);
    			
    			frente = bot->getSonar(3);
    			direita = bot->getSonar(6);
    			esquerda = bot->getSonar(0);
    			std::cout << "FRENTE:"<< frente << std::endl;
    			std::cout << "ESQUEDA:"<< esquerda << std::endl;
    			std::cout << "DIREITA:"<< direita << std::endl;
			
			
			
			//ROTACAO(0)
	    		if(numeroCurvas == 0 && direita > DIST_SONARES && frente < DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);
	    		else if(numeroCurvas == 0 && direita < DIST_SONARES && frente < DIST_SONARES && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		else if(numeroCurvas == 0 && direita < DIST_SONARES && frente < DIST_SONARES && esquerda < DIST_SONARES && !fezCurva)
	    			viraAtras(bot, &fezCurva, &numeroCurvas);

	    		//ROTACAO(90)
	    		if(numeroCurvas == 1 && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		else if(numeroCurvas == 1 && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);

	    		//ROTACAO(-90)
	    		if(numeroCurvas == -1 && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);
	    		else if(numeroCurvas == -1 && direita < DIST_SONARES && frente < DIST_SONARES && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		
	    		
	    		if((numeroCurvas == -2 || numeroCurvas == 2) && frente < DIST_SONARES && direita > DIST_SONARES && !fezCurva)
	    			viraDireita(bot, &fezCurva, &numeroCurvas);
	    		else if((numeroCurvas == -2 || numeroCurvas == 2) && frente < DIST_SONARES && esquerda > DIST_SONARES && !fezCurva)
	    			viraEsquerda(bot, &fezCurva, &numeroCurvas);
	    		
	    		
	    		std::cout << "SENTIDO ROTACAO:"<< numeroCurvas << std::endl;
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