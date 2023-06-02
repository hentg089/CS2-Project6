//
// Created by markh on 4/11/2023.
//

#include "Event.h"

void Event::setCustomerNumber(int customerNumber) {
    this->customerNumber = customerNumber;
}

void Event::setDuration(Time duration)  {
    this->duration = duration;
}

void Event::setTime(Time time) {
    this->time = time;
}

void Event::setType(EventType type)  {
    this->type = type;
}

void Event::setLine(int lineNumber) {
    this->lineNumber = lineNumber;
}

EventType Event::getType() const{
    return type;
}

Time Event::getTime() const {
    return time;
}

Time Event::getDuration() const {
    return duration;
}

int Event::getNumber() const {
    return customerNumber;
}

int Event::getLine() const {
    return lineNumber;
}

bool Event::operator<(const Event &rhs) const {
    if(time == rhs.time && type != rhs.getType()){
        if(type == EventType::ARRIVAL){
            return true;
        }else{
            return false;
        }
    }
    return time < rhs.time;
}

bool Event::operator>(const Event &rhs) const {
    if(time == rhs.time && type != rhs.getType()){
        if(rhs.type == EventType::ARRIVAL){
            return true;
        }else{
            return false;
        }
    }
    return time > rhs.time;
}

bool Event::operator<=(const Event &rhs) const {
    return time <= rhs.time;
}

bool Event::operator>=(const Event &rhs) const {
    return time >= rhs.time;
}

bool Event::operator==(const Event &rhs) const {
    if(time == rhs.time && type != rhs.getType()){
        return false;
    }
    return time == rhs.time;
}

bool Event::operator!=(const Event &rhs) const {
    if(time == rhs.time && type != rhs.getType()){
        return true;
    }
    return time != rhs.time;
}