/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TellstickLib.h
 * Author: Marie
 *
 * Created on den 29 februari 2016, 15:28
 */

#ifndef TELLSTICKLIB_H
#define TELLSTICKLIB_H

#include <iostream> 
#include <map>
#include <telldus-core.h>
#include "Sensor.h"

using namespace std;

class TellstickLib {
public:
    TellstickLib();
    TellstickLib(const TellstickLib& orig);
    virtual ~TellstickLib();
    void deviceEvent(int deviceId, int method, const char *data);
    static void deviceEventCallback(int deviceId, int method, const char *data, int callbackId, void *context);
    bool UpdateSensors();
private:
    int callbackId;
    map<int,Sensor> sensors;
};

#endif /* TELLSTICKLIB_H */

