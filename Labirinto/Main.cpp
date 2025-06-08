#include <iostream>
#include "libs/EdubotLib.hpp"

void viraDireita(EdubotLib* bot, bool* fezCurva);
void viraEsquerda(EdubotLib* bot, bool* fezCurva);
void viraAtras(EdubotLib* bot, bool* fezCurva);

int main(){
	bool fezCurva = false;
	bool estadoCurva = false;
	int numeroVoltas = 0;
   
    EdubotLib *bot = new EdubotLib();
    if(bot->connect()){ 
	    while(bot->isConnected()){
	    		bot->move(0.5);
	    		bot->sleepMilliseconds(1000);
	    		do{
	    			if(bot->getSonar(6)>0.5 && !estadoCurva){
	    			viraDireita(bot,&fezCurva);
	    			estadoCurva = true;
	    			}
	    			if(bot->getSonar(6)>0.5 && bot->getSonar(3)>0.5 && bot->getSonar(0)>0.5 && !estadoCurva ){
	    			viraAtras(bot,&fezCurva);
	    			estadoCurva = true;
	    			}
	    			
	    		}while(!fezCurva);
	    		fezCurva = false;
	    		estadoCurva = false;
	    }
    		 bot->disconnect();
    }
    	
    else{
        std::cout << "Could not connect on robot!" << std::endl;
    }
    return 0;
}

void viraDireita(EdubotLib* bot,bool* fezCurva){
	
	bot->sleepMilliseconds(600);
	bot->rotate(90);
	bot->sleepMilliseconds(1800);
	*fezCurva = true;
}

void viraEsquerda(EdubotLib* bot,bool* fezCurva){
	
	bot->sleepMilliseconds(500);
	bot->rotate(-90);
	bot->sleepMilliseconds(1800);
	*fezCurva = true;
}

void viraAtras(EdubotLib* bot,bool* fezCurva){
	
	bot->sleepMilliseconds(500);
	bot->rotate(180);
	bot->sleepMilliseconds(1800);
	*fezCurva = true;
}