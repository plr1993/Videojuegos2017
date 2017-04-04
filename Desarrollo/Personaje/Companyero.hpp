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
#include <math.h>       /* atan2 */
#include <iostream>
#include <sstream>
using namespace std;

class Companyero {
public:
    Companyero();
    Companyero(const Companyero& orig);
    virtual ~Companyero();
    void tecladoCompanyero();
    void drawCompanyero(Render * window);
    void updateCompanyero(Render * window);
    void disparo(Render * window);
    void cambiarArma();
    void vida();
private:
    sf::Sprite * _vida;
    sf::Texture * _textVida;
    int _cantVida;
};

#endif /* COMPANYERO_HPP */

