#include "lapSwim.h"

template<class T>
swimmingLane<T>::swimmingLane() {
    head = nullptr;
    tail = nullptr;
    itercurr = nullptr;
    totallanes = 0;
    userChoice = 0;
    for (int i = 0; i < MAX_LANES; i++) {
        lanetrack[i] = 0;
    }
}

template<class T>
swimmingLane<T>::~swimmingLane() {}

template<class T>
void swimmingLane<T>::Emptydisplay() {}

template<class T>
void swimmingLane<T>::Reserveddisplay() {}

template<class T>
void swimmingLane<T>::addLane(int lane) {}

template<class T>
void swimmingLane<T>::removeLane(int lane) {}

template<class T>
bool swimmingLane<T>::isLane(int lane) {
    return false;
}

template<class T>
int swimmingLane<T>::returnLane() {
    return 0;
}

template<class T>
int swimmingLane<T>::password() {
    return 1234;
}


template class swimmingLane<int>;
