// lapSwim.h
#ifndef LAPSWIM_H
#define LAPSWIM_H

#include <iostream>
using namespace std;

const int MAX_LANES = 5;

template<class T>
class swimmingLane {
public:
    swimmingLane();
    ~swimmingLane();
    void addlist(int value);
    void Emptydisplay();
    void Reserveddisplay();
    void addLane(int lane);
    void removeLane(int lane);
    bool isLane(int lane);
    int returnLane();
    int password();

private:
    struct Node {
        T lane;
        T pass;
        Node* next;
    };
    Node* head;
    Node* tail;
    Node* prev;
    Node* itercurr;
    int lanetrack[MAX_LANES];
    int userChoice;
    int totallanes;
};

//Definitions
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
swimmingLane<T>::~swimmingLane() {


}


template<class T>
void swimmingLane<T>::Emptydisplay() {
}

template<class T>
void swimmingLane<T>::Reserveddisplay() {
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


#endif // LAPSWIM_H
