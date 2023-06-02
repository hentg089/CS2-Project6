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

   void processArrival();
   void processDeparture();

   int getSmallestLine();

public:
   Simulation() = default;
   virtual ~Simulation() = default;

   void simulate();
};

#endif
