//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"



template<class T>
SwimLanes<T>::SwimLanes() {

    userChoice = 0;

}

template<class T>
SwimLanes<T>::~SwimLanes() {}

template<class T>
void SwimLanes<T>::Emptydisplay() {}

template<class T>
void SwimLanes<T>::Reserveddisplay() {}

template<class T>
void SwimLanes<T>::addLane(int lane) {}

template<class T>
void SwimLanes<T>::removeLane(int lane) {}

template<class T>
bool SwimLanes<T>::empty() {
    return false;
}

template<class T>
int SwimLanes<T>::returnLane() {
    return 0;
}

template<class T>
int SwimLanes<T>::password() {
    return 1234;
}


template class SwimLanes<int>;
