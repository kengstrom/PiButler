/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimerQueue.cpp
 * Author: Marie
 * 
 * Created on den 4 mars 2016, 14:39
 */

#include "TimerQueue.h"
#include <thread>

using namespace std;

TimerQueue::TimerQueue() {
}

TimerQueue::TimerQueue(const TimerQueue& orig) {
}

TimerQueue::~TimerQueue() {
}

void TimerQueue::start() {
    bool running = true;
    while( running ) {
        this_thread::sleep_for(1s);
    } 
}