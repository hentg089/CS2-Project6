//Mark Hentges 5814124 Part 1:One Teller


#include "EventBuilder.h"
#include <iostream>
#include <cassert>
#include <sstream>

EventBuilder::EventBuilder() {
    do{
        std::string filename;
        std::cout << "Enter a filename: " << std::endl;
        getline(std::cin, filename);
        input_file.open(filename);
    }while(!input_file.is_open());
}

Event EventBuilder::createArrivalEvent(int customerNumber) {
    Event newEvent;
    newEvent.setType(EventType::ARRIVAL);

    std::string line;

    if(std::getline(input_file, line)){
        newEvent.setCustomerNumber(customerNumber);
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

Event EventBuilder::createDepartureEvent(Time currentEventTime, Time transactionLength, int customerNumber) {
    Event newEvent;

    newEvent.setType(EventType::DEPARTURE);
    newEvent.setTime(currentEventTime + transactionLength);
    newEvent.setDuration(transactionLength);
    newEvent.setCustomerNumber(customerNumber);

    return newEvent;
}