/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 11 de diciembre de 2020, 01:09 PM
 */

#include <cstdlib>

#include "csv.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    csv* prueba = new csv("prototipoChikito.csv", true);
    prueba->print_data();
    delete prueba;//*/
    return 0;
}

