//
// Created by markh on 4/11/2023.
//

#include "Simulation.h"
#include <iostream>

void Simulation::simulate() {
    Event newEvent = eventBuilder.createArrivalEvent(1, 1);
    if(newEvent.getType() == EventType::ARRIVAL){
        eventList.enqueue(newEvent);
        while(!eventList.isEmpty()){
            currentEvent = eventList.peekFront();


            if(currentEvent.getType() == EventType::ARRIVAL){
                processArrival();
            }else{
                processDeparture();
            }

            stats.addEvent(currentEvent);
        }
    }

    stats.reportStats();
}

void Simulation::processArrival() {
    bool line1IsEmpty = line1.isEmpty();
    bool line2IsEmpty = line2.isEmpty();
    bool line3IsEmpty = line3.isEmpty();

    if(line1.getLength() <= line2.getLength() && line1.getLength() <= line3.getLength()){
        line1.enqueue(currentEvent);
    }else if(line2.getLength() <= line1.getLength() && line2.getLength() <= line3.getLength()){
        line2.enqueue(currentEvent);
    }else{
        line3.enqueue(currentEvent);
    }

    eventList.dequeue();

    if(line1IsEmpty && line2IsEmpty && line3IsEmpty){
        Event newEvent = eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                           currentEvent.getDuration(),
                                                           currentEvent.getNumber(),
                                                           currentEvent.getLine());
        eventList.enqueue(newEvent);
    }

    Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1, getSmallestLine());

    if(newEvent.getType() != EventType::NONE){
        eventList.enqueue(newEvent);
    }
}

void Simulation::processDeparture() {
    switch(eventList.peekFront().getLine()){
        case  1:
            line1.dequeue();
            break;
        case 2:
            line2.dequeue();
            break;
        case 3:
            line3.dequeue();
            break;
    }

    eventList.dequeue();

    switch(eventList.peekFront().getLine()){
        case 1:
            if(!line1.isEmpty()){
                Event hold = line1.peekFront();
                eventList.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                                    hold.getDuration(),
                                                                    hold.getNumber(), hold.getLine()));
            }
            break;
        case 2:
            if(!line2.isEmpty()){
                Event hold = line2.peekFront();
                eventList.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                                    hold.getDuration(),
                                                                    hold.getNumber(), hold.getLine()));
            }
            break;
        case 3:
            if(!line3.isEmpty()){
                Event hold = line3.peekFront();
                eventList.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                                    hold.getDuration(),
                                                                    hold.getNumber(), hold.getLine()));
            }
    }
}

int Simulation::getSmallestLine() {
    if(line1.getLength() <= line2.getLength() && line1.getLength() <= line3.getLength()){
        return 1;
    }else if(line2.getLength() <= line1.getLength() && line2.getLength() <= line3.getLength()){
        return 2;
    }else{
        return 3;
    }
}