//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"

template<class T>
WaitList<T>::WaitList() {
    head = nullptr;
    tail = nullptr;
    total =0;
    itercurr= nullptr;
}

template<class T>
WaitList<T>::~WaitList() {
    Node* tmp = head;
    while (tmp != nullptr) {
            head = tmp->next;
            delete tmp;
            tmp = head;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T>
void WaitList<T>::displayWaitList() {
    itercurr = head;
    int counter = 1;
    if(empty()) {
        throw isempty();

    }
    cout<<"WAITLIST:     \n\n";
    while (itercurr != nullptr) {

        cout<<"     "<<counter <<" - "<<itercurr->name<<endl;
        itercurr = itercurr->next;
        counter++;
    }
}

template<class T>
bool WaitList<T>::contains(string name) {
    itercurr = head;
    while (itercurr != nullptr) {
        if(itercurr->name == name) {
            return true;
        }
        itercurr = itercurr->next;
    }
    return false;
}

template<class T>
void WaitList<T>::add_waitlist(string name) {
    if(isFull()) {
        throw waitlistfull();
    }

    Node* newNode = new Node();
    newNode->name = name;

    if(head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        ++total;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = nullptr;
    tail = newNode;
    ++total;
}

template<class T>
void WaitList<T>::remove_waitlist() {
    if(empty()) {
        throw isempty();
    }
    Node* tmp = head;
    if(tmp->next != nullptr) {
        head = tmp->next;
        delete tmp;
        --total;
        return;
    }
    delete tmp;
    head = nullptr;
    tail = nullptr;
    --total;
}

template<class T>
bool WaitList<T>::isFull() {
    return total >= MAX_LANES;
}

template<class T>
bool WaitList<T>::empty() {
    return head == nullptr;
}

template class WaitList<int>;