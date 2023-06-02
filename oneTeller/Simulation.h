//Mark Hentges 5814124 Part 1:One Teller

#ifndef SIMULATION_
#define SIMULATION_

#include "Event.h"
#include "EventBuilder.h"
#include "Statistics.h"

class Simulation {
private:
   Event currentEvent;
   EventBuilder eventBuilder;
   LinkedQueue<Event> line;
   PriorityQueue<Event> eventList;
   Statistics stats;

   /**processes the arrival of a new person
    * @pre we need there to be currentEvent init and eventList to have stuff
    * @post more object is eventList
    */
   void processArrival();
   /** Process departure events
    * @pre stuff in line and eventList
    * @post adds departure event
    */
   void processDeparture();

public:
    /** constructs default simulation
     * @pre none
     * @post none simulation object constructed
     */
   Simulation() = default;

   /**default constuctor
    * @post object is destructed
    */
   virtual ~Simulation() = default;
    /** starts the simulation
     * @pre none
     * @post simulation is carried out
     */
   void simulate();
};

#endif
