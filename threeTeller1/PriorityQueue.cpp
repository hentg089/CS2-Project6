//Mark Hentges 5814125 Part 2: Three Teller (004)


/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Implementation file for a sorted list-based implementation of the
 *  ADT priority queue.
 *
 *  Adapted from page 432 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 14 Mar 2023
 *
 *  @version 7.0 */

#include <memory>

#include "PriorityQueue.h"


template <typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
   : sListPtr(std::make_unique<LinkedSortedList<ItemType>>() ) {
}

template <typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& pq)
   : sListPtr(std::make_unique<LinkedSortedList<ItemType>>(*(pq.sListPtr)) ) {
}

template <typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {

   return sListPtr->isEmpty();
}

template <typename ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {

   return sListPtr->insertSorted(newEntry);
}

template <typename ItemType>
bool PriorityQueue<ItemType>::dequeue() {

   return sListPtr->remove(1 );
}

template <typename ItemType>
ItemType PriorityQueue<ItemType>::peekFront() const {

   return sListPtr->getEntry(1 );
}
