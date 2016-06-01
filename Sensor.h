/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sensor.h
 * Author: Marie
 *
 * Created on den 4 mars 2016, 09:36
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <time.h>
#include <string>

const int DATA_LENGTH = 20;
using namespace std;

class Sensor {
public:
    Sensor();
    Sensor(int id);
    //Sensor(const Sensor& orig);
    virtual ~Sensor();
    bool UpdateSensor(double t, double h, time_t time);
    string toString();
private:
    int id;
    string name;
    double temp;
    double hum;
    time_t timestamp;
};

#endif /* SENSOR_H */

