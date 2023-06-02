#Mark Hentges 5814125 Part 2: Three Teller (004)

cmake_minimum_required(VERSION 3.24)
project(threeTeller1)

set(CMAKE_CXX_STANDARD 17)

add_executable(threeTeller1 project6.cpp Event.cpp LinkedQueue.cpp Node.cpp LinkedSortedList.cpp PrecondViolatedExcep.cpp
        PriorityQueue.cpp Statistics.cpp EventBuilder.cpp Simulation.cpp)
