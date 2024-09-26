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
    void add_waitlist(string name);
    void remove_waitlist(string name);
    int get_total();
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

//SwimLane Error Messages
class alreadyreserved {
public:
    string Msg() {
        return "Lane Already Reserved";
    }
};
class invalidpassword {
public:
    string Msg() {
        return "Invalid Password. Only use digits";
    }
};

//SwimLane Class
template<class T>
class SwimLanes {
public:
    SwimLanes();
    ~SwimLanes();
    void Emptydisplay();
    void Reserveddisplay();
    void addrsrv(int lane,string name, int password);
    void removeLane(int lane);
    bool empty();
    int returnLane();
    int password();

private:

    int tracker[2][MAX_LANES];
    int total;

    //
    int lane_row = 0;
    int name_row = 1;
    int pass_row = 2;
};




#endif

