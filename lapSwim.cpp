//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"



template<class T>
SwimLanes<T>::SwimLanes() {
    for(int i = 0; i < MAX_LANES; i++) {
            tracker[lane_row][i] = 0;
    }
    total = 0;
}

template<class T>
SwimLanes<T>::~SwimLanes() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < MAX_LANES; j++) {
            tracker[i][j] = 0;
        }
    }
}

template<class T>
void SwimLanes<T>::Emptydisplay() {

}

template<class T>
void SwimLanes<T>::Reserveddisplay() {

}

template<class T>
void SwimLanes<T>::addrsrv(int lane,string name, int password) {

}

template<class T>
void SwimLanes<T>::removeLane(int lane) {

}

template<class T>
bool SwimLanes<T>::empty() {


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
