//Mark Hentges 5814124 Part 1:One Teller


#include "Simulation.h"
#include <iostream>

void Simulation::simulate() {
    Event newEvent = eventBuilder.createArrivalEvent(1);
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
    bool lineIsEmpty = line.isEmpty();

    line.enqueue(currentEvent);

    eventList.dequeue();

    if(lineIsEmpty){
        Event newEvent = eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                           currentEvent.getDuration(), currentEvent.getNumber());
        eventList.enqueue(newEvent);
    }

    Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1);

    if(newEvent.getType() != EventType::NONE){
        eventList.enqueue(newEvent);
    }
}

void Simulation::processDeparture() {
    line.dequeue();

    eventList.dequeue();

    if(!line.isEmpty()){
        Event hold = line.peekFront();
        eventList.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), hold.getDuration(), hold.getNumber()));
    }
}