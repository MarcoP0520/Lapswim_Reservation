//
// Created by marco on 9/24/2024.
//
#ifndef POOLTRACKER_H
#define POOLTRACKER_H

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const string exitcode = "3x1t";
const int MAX_LANES = 1;


inline void displayOptions(){
    std::cout<<"\n\n                                                     ----------------------\n";
    std::cout<<"                                                     Public Community Pool\n";
    std::cout<<"                                                     ----------------------\n\n";
    std::cout<<"                                                       ---------------\n";
    std::cout<<"                                                       [Reserve a Lane] - 'reserve'\n";
    std::cout<<"                                                       ---------------\n\n";
    std::cout<<"                                                     --------------------\n";
    std::cout<<"                                                     [Close a reservation]- 'close'\n";
    std::cout<<"                                                     --------------------\n\n";
    std::cout<<"                                                     --------------------\n";
    std::cout<<"                                                     [View the Wait list]- 'waitlist'\n";
    std::cout<<"                                                     --------------------\n\n\n\n";
}

//SwimLane Error Messages
class alreadyreserved {
public:
    string Msg() {
        return "Lane Unavailable\n";
    }
};
class notreserved {
public:
    string Msg() {
        return "No reservation in this lane\n";
    }
};
class invalidpassword {
public:
    string Msg() {
        return "Invalid Password, too many failed attempts\n";
    }
};
class incorrectpassword {
public:
    string Msg() {
        return "Incorrect Password, too many failed attempts\n";
    }
};
class namenotfound {
    public:
    string Msg() {
        return "Name not found\n";
    }
};
class isempty {
    public:
    string Msg() {
        return "Waitlist is empty\n";
    }
};
class waitlistfull {

    public:
    string Msg() {
        return "Sorry Waitlist is full, Try again later \n";
    }
};



template<class T>
class WaitList {
    public:
    WaitList();
    ~WaitList();
    void displayWaitList();
    void add_waitlist();
    string remove_waitlist();
    bool full();
    bool contains(string name);
    bool empty();
    private:
    struct Node {
        string name;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    Node* itercurr;
    int total;

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
    bool full();
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

