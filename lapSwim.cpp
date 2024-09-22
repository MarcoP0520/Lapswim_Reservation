#include "lapSwim.h"
template<class T>
swimmingLane<T>::swimmingLane() {
}

template<class T>
swimmingLane<T>::~swimmingLane() {
}

template<class T>
void swimmingLane<T>::organize(int lane[]) {
}

template<class T>
void swimmingLane<T>::display() {
    head->lane = 1;
    head->pass = 3455;
    std::cout<<head->lane<<std::endl;
}

template<class T>
void swimmingLane<T>::addLane(int lane) {
}

template<class T>
void swimmingLane<T>::removeLane(int lane) {
}

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
