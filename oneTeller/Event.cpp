//Mark Hentges 5814124 Part 1:One Teller

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

bool Event::operator<(const Event &rhs) const {
    return time < rhs.time;
}

bool Event::operator>(const Event &rhs) const {
    return time > rhs.time;
}

bool Event::operator<=(const Event &rhs) const {
    return time <= rhs.time;
}

bool Event::operator>=(const Event &rhs) const {
    return time >= rhs.time;
}

bool Event::operator==(const Event &rhs) const {
    return time == rhs.time;
}

bool Event::operator!=(const Event &rhs) const {
    return time != rhs.time;
}