#include "Arma.h"

Arma::Arma(){
   //Cargo la imagen donde reside la textura del sprite
   textura_arma.loadFromFile("resources/armas_final.png");
   this->setTexture(textura_arma);

   this->setTextureRect(sf::IntRect(0, 0*92, 126, 91));
   // Lo dispongo en el centro de la pantalla
   this->setPosition(90, 320);
   this->armaSeleccionada=1;
   this->ang_Bala=0;
   this->vel_Bala=0.f;
}

void Arma::cambiarArma(int num){
    if(num==1){
        //Cargo la imagen donde reside la textura del sprite
        textura_arma.loadFromFile("resources/armas_final.png");
        this->setTextureRect(sf::IntRect(0, 0*92, 126, 91));
        this->vel_Bala=1000.f;
    }
    if(num==2){
        textura_arma.loadFromFile("resources/armas_final.png");
        this->setTextureRect(sf::IntRect(0, 4*92, 126, 91));
        this->vel_Bala=1200.f;
    }
    if(num==3){
       textura_arma.loadFromFile("resources/armas_final.png");
       this->setTextureRect(sf::IntRect(0, 2*92, 126, 91));
       this->vel_Bala=5000.f;    
    }
    if(num==4||num==5||num==6||num==7){
       textura_arma.loadFromFile("resources/armas_final.png");
       this->setTextureRect(sf::IntRect(0, 6*92, 159, 91));
       this->vel_Bala=10.f;
    }
    
    this->setTexture(textura_arma);   
    this->armaSeleccionada=num;
}
int Arma::getArma(){
    return this->armaSeleccionada;
}
