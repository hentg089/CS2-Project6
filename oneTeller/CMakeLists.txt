#Mark Hentges 5814124 Part 1:One Teller

cmake_minimum_required(VERSION 3.24)
project(oneTeller)

set(CMAKE_CXX_STANDARD 17)

add_executable(oneTeller Statistics.cpp project6.cpp PriorityQueue.cpp LinkedList.cpp LinkedQueue.cpp PrecondViolatedExcep.cpp
        LinkedSortedList.cpp Node.cpp Time.h EventType.h Event.cpp EventBuilder.cpp Simulation.cpp)
