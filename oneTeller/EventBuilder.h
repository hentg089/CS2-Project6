//
// Created by markh on 4/11/2023.
//

#ifndef ONETELLER_EVENTBUILDER_H
#define ONETELLER_EVENTBUILDER_H

#include <fstream>
#include "Event.h"

class EventBuilder {
private:
    std::fstream input_file;
public:
    /**reads if file we read from
     * @pre none
     * @post file to read from is open
     */
    EventBuilder();

    /**Create's a new arrival event
     * @pre need a file to be open
     * @post creates a new event
     * @param customerNumber is number iding the event
     * @return newly created event
     */
    Event createArrivalEvent(int customerNumber);

    /**creates a new departure event that correlates with an arrival event
     * @pre need an arrival event to contruct with
     * @post makes new departure event
     * @param currentEventTime added to transation length
     * @param transactionLength addeed to current event time to equal time
     * @param customerNumber number id associated with it
     * @return newly created event
     */
    Event createDepartureEvent(Time currentEventTime, Time transactionLength, int customerNumber);



};


#endif //ONETELLER_EVENTBUILDER_H
