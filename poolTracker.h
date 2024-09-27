//
// Created by marco on 9/24/2024.
//
#ifndef POOLTRACKER_H
#define POOLTRACKER_H

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


const int MAX_LANES = 5;

//SwimLane Error Messages
class alreadyreserved {
public:
    string Msg() {
        return "Lane Unavailable";
    }
};
class notreserved {
public:
    string Msg() {
        return "No reservation in this lane";
    }
};
class invalidpassword {
public:
    string Msg() {
        return "Invalid Password, too many failed attempts";
    }
};
class incorrectpassword {
public:
    string Msg() {
        return "Incorrect Password, too many failed attempts";
    }
};


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



//SwimLane Class
template<class T>
class SwimLanes {
public:
    SwimLanes();

    ~SwimLanes();

    void displayEmpty(int lane);
    void displayRsrvd(int lane);
    void displayLanes();
    void addrsrv(int lane);
    void removeLane(int lane);
    bool empty();
    void screenClear();
    bool validLane(int lane);
    string password();
    bool askpassword(int lane);

private:

    string tracker[3][MAX_LANES];
    string pass;
    int total;

    //rows for 2d list
    int lane_row = 0;
    int name_row = 1;
    int pass_row = 2;
};




#endif

