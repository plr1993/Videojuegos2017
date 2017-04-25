/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   eRender.cpp
 * Author: sergio
 * 
 * Created on 14 de marzo de 2017, 14:12
 */

#include "Render.hpp"

Render::Render(float x, float y) {
    window = new sf::RenderWindow(sf::VideoMode(x, y), "DuoShot");
}

Render::Render(const Render& orig) {}

Render::~Render() {
    delete window;
}

sf::RenderWindow* Render::getWindow() {
    return window;
}

void Render::setWindow(float x, float y) {
    sf::Vector2u vector(sf::Vector2u(x, y));
    window->setSize(vector);
    
}

