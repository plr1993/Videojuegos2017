/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: david96
 *
 * Created on 14 de febrero de 2017, 11:11
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define kVel 5

#include "Juego.h"

int main(){       
    Juego juego;
    juego.run();
    return 0;
}