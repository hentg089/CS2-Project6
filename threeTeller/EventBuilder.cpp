//
// Created by markh on 4/13/2023.
//

#include "EventBuilder.h"
#include <iostream>
#include <sstream>

EventBuilder::EventBuilder() {
    do{
        std::string filename;
        std::cout << "Enter a filename: " << std::endl;
        getline(std::cin, filename);
        inputFile.open(filename);
    }while(!inputFile.is_open());
}

Event EventBuilder::createArrivalEvent(int number, int lineNumber) {
    Event newEvent;
    newEvent.setType(EventType::ARRIVAL);

    std::string line;

    if(std::getline(inputFile, line)){
        newEvent.setCustomerNumber(number);
        newEvent.setLine(lineNumber);
        std::istringstream iss(line);
        std::string item;

        std::getline(iss, item, ' ');
        newEvent.setTime(std::stoi(item));

        std::getline(iss, item, ' ');
        newEvent.setDuration(std::stoi(item));
    }else{
        newEvent.setType(EventType::NONE);
    }

    return newEvent;
}

Event EventBuilder::createDepartureEvent(const Time &currentEventTime, const Time &transactionLength, int number,
                                         int lineNumber) {
    Event newEvent;

    newEvent.setType(EventType::DEPARTURE);
    newEvent.setTime(currentEventTime + transactionLength);
    newEvent.setDuration(transactionLength);
    newEvent.setCustomerNumber(number);
    newEvent.setLine(lineNumber);

    return newEvent;
}