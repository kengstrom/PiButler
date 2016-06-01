/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TellstickLib.cpp
 * Author: Karl
 * 
 * Created on den 29 februari 2016, 15:28
 */

#include "TellstickLib.h"

TellstickLib::TellstickLib() {
    tdInit();
    callbackId = tdRegisterDeviceEvent( reinterpret_cast<TDDeviceEvent>(&TellstickLib::deviceEventCallback), this );
}

TellstickLib::TellstickLib(const TellstickLib& orig) {
}

TellstickLib::~TellstickLib() {
    tdUnregisterCallback(callbackId);
    tdClose();
}

void TellstickLib::deviceEvent(int deviceId, int method, const char* data) {
    if (method == TELLSTICK_TURNON) {
        printf("ON event from device %i\n", deviceId);
    } else if (method == TELLSTICK_TURNOFF) {
        printf("OFF event from device %i\n", deviceId);
    } else {
        printf("Unknown event from device %i\n", deviceId);
    }    
}

void TellstickLib::deviceEventCallback(int deviceId, int method, const char* data, int callbackId, void* context) {
    TellstickLib *tl = reinterpret_cast<TellstickLib *>(context);
    if(tl) {
        tl->deviceEvent(deviceId, method, data);
    }
}

bool TellstickLib::UpdateSensors() {
    char protocol[DATA_LENGTH], model[DATA_LENGTH];
    int sensorId = 0, dataTypes = 0;
    char value[DATA_LENGTH];
    char timeBuf[80];
    time_t timestamp = 0;
    bool sensorsChanged = false;;

    while(tdSensor(protocol, DATA_LENGTH, model, DATA_LENGTH, &sensorId, &dataTypes) == TELLSTICK_SUCCESS) {
        Sensor sTemp;
        double temp = 0.0;
        double humi = 0.0;
        auto it = sensors.find(sensorId);
        if (it == sensors.end()) {
            sensors[sensorId] = Sensor(sensorId);
        }
        if (dataTypes & TELLSTICK_TEMPERATURE) {
            tdSensorValue(protocol, model, sensorId, TELLSTICK_TEMPERATURE, value, DATA_LENGTH, (int *)&timestamp);
            temp = atof(value);
        }
        if (dataTypes & TELLSTICK_HUMIDITY) {
            tdSensorValue(protocol, model, sensorId, TELLSTICK_HUMIDITY, value, DATA_LENGTH, (int *)&timestamp);
            humi = atof(value); 
        }
        if(sensors[sensorId].UpdateSensor(temp, humi, timestamp))
        {
            sensorsChanged = true;
        }
    }
    if( sensorsChanged ) {
        for(auto item : sensors) {
            cout << "Sensors changed!!!!" << endl;
            cout << item.second.toString() << endl;
        }
    }
    return sensorsChanged;
}