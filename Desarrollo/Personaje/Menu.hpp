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
#include "Motor/Render.hpp"

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    void drawMenu(Render * window);
private:
    sf::RectangleShape * _rectPrueba;

};

#endif /* MENU_HPP */

