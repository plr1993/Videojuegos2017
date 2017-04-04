/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: sergio
 * 
 * Created on 25 de marzo de 2017, 18:29
 */

#include "Menu.hpp"
#include "Motor/Render.hpp"

Menu::Menu() {
    //Inicializas el rectangulo de prueba
    _rectPrueba = new sf::RectangleShape;
    _rectPrueba->setSize(sf::Vector2f(100, 50));
    _rectPrueba->setOutlineColor(sf::Color::Red);
    _rectPrueba->setOutlineThickness(5);
    _rectPrueba->setPosition(10, 20);
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

//Aqui pintamos todo lo del menu, recibo por parametro la ventana si nos no puedes pintar
void Menu::drawMenu(Render* window) {
    //Pintamos el rectangulo
    //Le tienes que pasar el rectangulo, para ello se lo pasas con el *_rectPrueba...para acceder al rectangulo en memoria
    //Si le pasas _rectPrueba, le estas pasando un puntero y no vale.
    window->getWindow()->draw(*_rectPrueba); 
}
