/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.cpp
 * Author: sergio
 * 
 * Created on 26 de abril de 2017, 19:17
 */

#include "Estado.hpp"

Estado::Estado() {
    _estado = 0;
}

Estado::Estado(const Estado& orig) {
}

Estado::~Estado() {
}

int Estado::getEstado() {
    return _estado;
}

void Estado::setEstado(int i) {
    this->_estado = i;
}


