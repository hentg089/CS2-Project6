//Mark Hentges 5814125 Part 2: Three Teller (004)


#ifndef SIMULATION_
#define SIMULATION_

#include "Event.h"
#include "EventBuilder.h"
#include "Statistics.h"

class Simulation {
private:
   Event currentEvent;
   EventBuilder eventBuilder;
   LinkedQueue<Event> line1;
   LinkedQueue<Event> line2;
   LinkedQueue<Event> line3;
   PriorityQueue<Event> eventList;
   Statistics stats;
   int number = 1;

   void processArrival();
   void processDeparture();

   int getShortestLine();
public:
   Simulation() = default;
   virtual ~Simulation() = default;

   void simulate();
};

#endif
