//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"
SwimLanes<int> swimLanes;
WaitList<int> waitList;
string userchoice = "";

int main() {

    while (userchoice != exitcode) {
        displayOptions();
        cin>>userchoice;

        if(userchoice.substr(0,4) == "rese") {
            swimLanes.displayLanes();
            if(swimLanes.full()) {
                cout<<"All lanes are full would you like to join the Wait list [Y,N]?\n ";
                cin>>userchoice;
                if(userchoice == "y" || userchoice == "Y") {
                    try {
                        waitList.add_waitlist();
                    }
                    catch(waitlistfull error) {
                        cout<< error.Msg();
                    }

                }
                main();
            }
            else {
                cout<<"Enter lane to reserve: ";
                cin>>userchoice;
                try {
                    swimLanes.addrsrv(stoi(userchoice));
                }
                catch(alreadyreserved error){
                    cout<<error.Msg();
                }
                catch(invalidpassword error){
                    cout<<error.Msg();
                }
                catch(invalid_argument error) {
                    cout<<"Lane is invalid";
                }
            }
        }
        else if(userchoice.substr(0,3) == "clo") {
            if(swimLanes.empty()) {
                cout<<"No reserved lanes were found";
            }
            else {
                swimLanes.displayLanes();
                cout<<"Enter lane to close: ";
                cin>>userchoice;
                try {
                    swimLanes.removeLane(stoi(userchoice));
                }
                catch(notreserved error) {
                    cout<<error.Msg();
                }
                catch(incorrectpassword error) {
                    cout<<error.Msg();
                }
                catch(invalid_argument error) {
                    cout<<"Lane is invalid";
                }
                if(!waitList.empty()) {
                    swimLanes.displayLanes();
                    waitList.remove_waitlist();
                    cout<<"Enter lane to reserve: ";
                    cin>>userchoice;
                    try {
                        swimLanes.addrsrv(stoi(userchoice));
                    }
                    catch(alreadyreserved error){
                        cout<<error.Msg();
                    }
                    catch(invalidpassword error){
                        cout<<error.Msg();
                    }
                    catch(invalid_argument error) {
                        cout<<"Lane is invalid";
                    }
                }


            }
        }
        else if(userchoice.substr(0,4) == "wait") {
            try {
                waitList.displayWaitList();
            }
            catch(isempty error) {
                cout<<error.Msg();
            }
        }
    }
}
