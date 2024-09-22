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
    void organize(int arr[]);
    void display();
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
    Node* curr;
    int lanetrack[MAX_LANES];
    int user_lane;
    int totalLanes;
};

#include "lapSwim.cpp"

#endif // LAPSWIM_H
