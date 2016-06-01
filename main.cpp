/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Marie
 *
 * Created on den 29 februari 2016, 15:25
 */

#include <cstdlib>

#include "TellstickLib.h"
#include <iostream> 
#include <thread>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TellstickLib tLib;
    int i = 0 ;
    while (true) {
        cout << "Iteration " << i << "\n";
        tLib.UpdateSensors();
        this_thread::sleep_for(10s);
        i++;
    }
    return 0;
}

