//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"


int main() {
    SwimLanes<int> swimLanes;
    WaitList<int> waitList;


    swimLanes.displayLanes();
    try {
        swimLanes.addrsrv(3);
    }
    catch(alreadyreserved error) {
        cout<<error.Msg()<<endl;
    }
    catch(invalidpassword error) {
        cout<<error.Msg()<<endl;
    }
    swimLanes.displayLanes();
    try {
        swimLanes.removeLane(3);
    }
    catch(notreserved error) {
        cout<<error.Msg()<<endl;
    }
    catch(incorrectpassword error) {
        cout<<error.Msg()<<endl;
    }

    main();
}
