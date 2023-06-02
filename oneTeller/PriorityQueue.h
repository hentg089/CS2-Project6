//Mark Hentges 5814124 Part 1:One Teller

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Header file for a sorted list-based implementation of the ADT
 *  priority queue.
 *
 *  Adapted from page 431 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 14 Mar 2023
 *
 *  @version 7.0 */

#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include <memory>

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.cpp"

/** @class PriorityQueue PriorityQueue.h "PriorityQueue.h"
 *
 *  Specification of a sorted list-based ADT priority queue. */
template <typename ItemType>
class PriorityQueue : public PriorityQueueInterface<ItemType> {
private:
   std::unique_ptr<LinkedSortedList<ItemType>> sListPtr;

public:
   PriorityQueue();

   PriorityQueue(const PriorityQueue<ItemType>& pq);

   ~PriorityQueue() override = default;

   bool isEmpty() const override;

   bool enqueue(const ItemType& newEntry) override;

   /**deques the item with smallest tiem value
    * @pre none
    * @post sListPTr is smaller
    * @return whether it worked or not
    */
   bool dequeue() override;

   /**gets the highest priority item based on minimal time value
    * @pre has to not be empty
    * @post none
    * @return minimal time item
    */
   ItemType peekFront() const override;
};


#endif
