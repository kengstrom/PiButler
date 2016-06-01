/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimerQueue.h
 * Author: Marie
 *
 * Created on den 4 mars 2016, 14:39
 */

#ifndef TIMERQUEUE_H
#define TIMERQUEUE_H

class TimerQueue {
public:
    TimerQueue();
    TimerQueue(const TimerQueue& orig);
    virtual ~TimerQueue();
    void start();
private:

};

#endif /* TIMERQUEUE_H */

