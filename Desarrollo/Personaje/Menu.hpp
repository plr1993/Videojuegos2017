/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.hpp
 * Author: sergio
 *
 * Created on 25 de marzo de 2017, 18:29
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Motor/Render.hpp"

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    void drawMenu(Render * window);
    void updateMenu(Render * window);

private:
    sf::Font * _fuente;
    sf::Texture *_fondo1, *_fondo2, *_subfondo1, *_subfondo2, *_titulo, *_botones;
    sf::Sprite *_sfondo1, *_sfondo2, *_ssubfondo1, *_ssubfondo2, *_stitulo;
    sf::Sprite *_botonJugar1, *_botonJugar2, *_botonJugar3, *_botonJugar4;
    sf::Sprite *_botonOp1, *_botonOp2, *_botonOp3, *_botonOp4;
    sf::Sprite *_botonSa1, *_botonSa2, *_botonSa3, *_botonSa4;
    sf::Clock frameClock;
    int fon=1;
    int aux=0;
    int aux2=0;
    int aux3=0;
    double p1=0.5;
    double p2=0.5;
    int pos=0;
};

#endif /* MENU_HPP */

