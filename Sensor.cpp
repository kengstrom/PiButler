/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sensor.cpp
 * Author: Marie
 * 
 * Created on den 4 mars 2016, 09:36
 */

#include "Sensor.h"
#include <sstream>
#include <iostream> 

using namespace std;

Sensor::Sensor() {
}
Sensor::Sensor(int id) : id(id) {
    
}
//Sensor::Sensor(const Sensor& orig) {
//}

Sensor::~Sensor() {
}

bool Sensor::UpdateSensor(double t, double h, time_t time) {
    bool valuesChanged = false;
    if(t != temp) {
        cout << "Temp changed!!!" << endl;
        temp = t;
        valuesChanged = true;
    }
    if(h != hum) {
        cout << "Hum. changed!!!" << endl;
        hum = h;
        valuesChanged = true;
    }
    if( time != timestamp) {
        cout << "Timestamp changed!!!" << endl;
        timestamp = time;
        valuesChanged = true;
    }
    if (valuesChanged) {
        // TODO: We got new values... Maybe we should notify this or save them
    }
    return valuesChanged;
}

string Sensor::toString() {
    char timeBuf[80];
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
    stringstream ss;
    ss << "Id: " << id << "\tName: " << name << "\tTemp: " << temp << "\tHum: " << hum << "\tTime: " << timeBuf;
    return ss.str();
}