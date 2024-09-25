//
// Created by marco on 9/24/2024.
//
#ifndef POOLTRACKER_H
#define POOLTRACKER_H

#include <iostream>
using namespace std;

const int MAX_LANES = 5;

template<class T>
class WaitList {
    public:
    WaitList();
    ~WaitList();
    void add_waitlist(string n);
    void remove_waitlist(string n);
    int get_waitlist();
    bool empty();
    private:
    struct Node {
        string name;
        Node* next;
    };
    Node* head;
    Node* tail;
    Node* prev;
    Node* itercurr;

};

template<class T>
class SwimLanes {
public:
    SwimLanes();
    ~SwimLanes();
    void addlist(int value);
    void Emptydisplay();
    void Reserveddisplay();
    void addLane(int lane);
    void removeLane(int lane);
    bool empty();
    int returnLane();
    int password();

private:
    int tracker[3][MAX_LANES];
    string name;
    int userChoice;
    int total;
};




#endif

