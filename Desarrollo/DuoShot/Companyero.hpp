/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Companyero.hpp
 * Author: sergio
 *
 * Created on 27 de marzo de 2017, 11:11
 */

#ifndef COMPANYERO_HPP
#define COMPANYERO_HPP
#include "Motor/Render.hpp"
#include "Mapa.hpp"
#include "Motor/Camera.hpp"
#include <math.h>       /* atan2 */
#include <iostream>
#include <sstream>
using namespace std;
const float PI2 = 3.14159265;
const float speed2 = 300.f;
class Companyero {
public:
     Companyero();
    Companyero(const Companyero& orig);
    virtual ~Companyero();
    void tecladoCompanyero();
    void drawCompanyero(Render * window);
    void updateCompanyero(Render * window,float posX,float posY,mapa * mapa, Camera * camera,float posEnemx,float posEnemy);
    void perseguir(float posX, float posY, float &speedx, float &speedy, float factor);
    void disparo(Render * window);
    void cambiarArma();
    void vida();
    sf::Sprite * getCompanyero();

private:
    sf::Sprite * _survivor2,* _vida,*_objective, *_bala;
    sf::Texture * _textSurvivor2,* _textVida,*_textBala,*_textObj;
    sf::Clock frameClock, updatepath;
    bool _disparo, _colision;
    int _cantVida;
    float movX, movY, factor, speedx, speedy;
};

#endif /* COMPANYERO_HPP */

