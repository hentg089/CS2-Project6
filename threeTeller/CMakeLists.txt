cmake_minimum_required(VERSION 3.24)
project(threeTeller)

set(CMAKE_CXX_STANDARD 17)

add_executable(threeTeller LinkedSortedList.cpp LinkedQueue.cpp LinkedList.cpp PriorityQueue.cpp PrecondViolatedExcep.cpp
        Statistics.cpp Simulation.h Statistics.h project6.cpp Simulation.cpp Event.cpp EventBuilder.cpp)
