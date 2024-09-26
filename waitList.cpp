//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"

template<class T>
WaitList<T>::WaitList() {
    head = nullptr;
    tail = nullptr;
    prev = nullptr;
    itercurr= nullptr;
}

template<class T>
WaitList<T>::~WaitList() {
}

template<class T>
void WaitList<T>::add_waitlist(string name) {
}

template<class T>
void WaitList<T>::remove_waitlist(string name) {
}

template<class T>
int WaitList<T>::get_total() {
}

template<class T>
bool WaitList<T>::empty() {
    return head == nullptr;
}

template class WaitList<int>;