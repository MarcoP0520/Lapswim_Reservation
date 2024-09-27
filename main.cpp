//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"


int main() {
    SwimLanes<int> swimLanes;
    WaitList<int> waitList;



    try {
        swimLanes.addrsrv(1);
    }
    catch(alreadyreserved error) {
        cout<<error.Msg()<<endl;
    }
    catch(invalidpassword error) {
        cout<<error.Msg()<<endl;
    }
    swimLanes.displayRsrvd(0);
    try {
        swimLanes.removeLane(1);
    }
    catch(notreserved error) {
        cout<<error.Msg()<<endl;
    }
    catch(incorrectpassword error) {
        cout<<error.Msg()<<endl;
    }
    main();
}
