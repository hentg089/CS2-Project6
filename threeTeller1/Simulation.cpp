//Mark Hentges 5814125 Part 2: Three Teller (004)

#include "Simulation.h"

void Simulation::simulate() {
    Event newEvent = eventBuilder.createArrivalEvent(number++, 1);
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
    bool lineIsEmpty;
    int shortestLine;
    switch(getShortestLine()){
        case 1:
            lineIsEmpty = line1.isEmpty();
            line1.enqueue(currentEvent);
            shortestLine = 1;
            break;
        case 2:
            lineIsEmpty = line2.isEmpty();
            line2.enqueue(currentEvent);
            shortestLine = 2;
            break;
        case 3:
            lineIsEmpty = line3.isEmpty();
            line3.enqueue(currentEvent);
            shortestLine = 3;
            break;
    }

    eventList.dequeue();

    if(lineIsEmpty){
        Event newEvent = eventBuilder.createDepartureEvent(
                currentEvent.getTime(), currentEvent.getDuration(),
                currentEvent.getNumber(), currentEvent.getLine());
        eventList.enqueue(newEvent);
    }

    Event newEvent = eventBuilder.createArrivalEvent(number++, getShortestLine());
    if(newEvent.getType() != EventType::NONE){
        eventList.enqueue(newEvent);
    }
}

void Simulation::processDeparture() {
    int currentLine;
    switch(currentEvent.getLine()){
        case 1:
            line1.dequeue();
            currentLine = 1;
            break;
        case 2:
            line2.dequeue();
            currentLine = 2;
            break;
        case 3:
            line3.dequeue();
            currentLine = 3;
            break;
    }

    eventList.dequeue();

    switch(currentLine){
        case 1:
            if(!line1.isEmpty()){
                Event hold = line1.peekFront();
                Event newEvent = eventBuilder.createDepartureEvent(currentEvent.getTime(),
                       hold.getDuration(), hold.getNumber(), hold.getLine());
                eventList.enqueue(newEvent);
            }
            break;
        case 2:
            if(!line2.isEmpty()){
                Event hold = line2.peekFront();
                Event newEvent = eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                                   hold.getDuration(), hold.getNumber(), hold.getLine());
                eventList.enqueue(newEvent);
            }
            break;
        case 3:
            if(!line3.isEmpty()){
                Event hold = line3.peekFront();
                Event newEvent = eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                                   hold.getDuration(), hold.getNumber(), hold.getLine());
                eventList.enqueue(newEvent);
            }
            break;
    }

}

int Simulation::getShortestLine() {
    if(line1.getLength() <= line2.getLength() && line1.getLength() <= line3.getLength()){
        return 1;
    }else if (line2.getLength() <= line1.getLength() && line2.getLength() <= line3.getLength()){
        return 2;
    }else{
        return 3;
    }
}