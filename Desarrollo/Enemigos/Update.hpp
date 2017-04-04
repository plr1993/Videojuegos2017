/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Update.hpp
 * Author: sergio
 *
 * Created on 14 de marzo de 2017, 13:45
 */

#define UPDATE_HPP
#define UPDATE_HPP
#include "Juego.hpp"
#include <cstdlib>
#include <iostream>
#define WORLD_TICK_TIME 1/60
#define WORLD_TICK_TIME_IA 1/25

using namespace std;


class Update{
public:
    Update(); 
    Update(const Update& orig);
    virtual ~Update();
    void update();
    
private:
    Juego * juego;
};
