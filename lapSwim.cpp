//
// Created by marco on 9/24/2024.
//
#include "poolTracker.h"



template<class T>
SwimLanes<T>::SwimLanes() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < MAX_LANES; j++) {
            tracker[i][j] = "";
        }
    }
    total = 0;
}

template<class T>
SwimLanes<T>::~SwimLanes() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < MAX_LANES; j++) {
            tracker[i][j] = "";
        }
    }
}

template<class T>
void SwimLanes<T>::displayEmpty(int lane) {
    std::cout<<"                               ------------------------------------------\n";
    std::cout<<"Lane: "<<lane+1<<"                                          EMPTY\n";
    std::cout<<"                               -------------------------------------------\n";
}

template<class T>
void SwimLanes<T>::displayRsrvd(int lane) {
    std::cout<<"                               ------------------------------------------\n";
    std::cout<<"Lane: "<<lane+1<<"                        /////////////////Reserved//////////////////   -"<< tracker[name_row][lane]<<"\n";
    std::cout<<"                               -------------------------------------------\n";
}
template<class T>
void SwimLanes<T>::displayLanes() {
    for(int i = 0; i < MAX_LANES; i++) {
        if(tracker[lane_row][i] == "") {
            displayEmpty(i);
        }
        if(tracker[lane_row][i] != "") {
            displayRsrvd(i);
        }
    }
}


template<class T>
void SwimLanes<T>::addrsrv(int lane) {
    string name;
  if(!validLane(lane)) {
      throw alreadyreserved();
  }
    cout<<"Enter Name: ";
    cin>>name;
    pass = password();

    tracker[lane_row][lane-1]= to_string(lane);
    tracker[name_row][lane-1]= name;
    tracker[pass_row][lane-1]= pass;

    total++;
    screenClear();
    cout<<"         Lane "<<lane<<" has been reserved!"<<endl;
    cout<<"                   have a great swim "<< name<<endl;
    this_thread::sleep_for(chrono::seconds(4));
    screenClear();
}

template<class T>
void SwimLanes<T>::removeLane(int lane) {
    if(validLane(lane)) {
        throw notreserved();
    }
   if(askpassword(lane)) {
       tracker[lane_row][lane-1]= "";
       tracker[name_row][lane-1]= "";
       total--;
       screenClear();
       cout<<"Reservation has been removed, Have a great day!"<<endl;
       this_thread::sleep_for(chrono::seconds(4));
       screenClear();


   }
}

template<class T>
bool SwimLanes<T>::empty() {
    return total == 0;
}

template<class T>
void SwimLanes<T>::screenClear() {
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
}

template<class T>
bool SwimLanes<T>::validLane(int lane) {
    if(lane > MAX_LANES || lane < 1) {
        return false;
    }
    if(tracker[lane_row][lane-1]!="") {
            return false;
    }

    return true;
}

template<class T>
string SwimLanes<T>::password() {
    string password;
    int loop_count = 0;

    while(loop_count != 3) {
        cout << "Please enter a 4-digit password: ";
        cin >> password;

        // Check length of password
        if (password.length() != 4) {
            cout << "Invalid password length. It must be exactly 4 digits." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            loop_count++;
            continue;
        }

        bool isValid = true;
        for (int i = 0; i < password.length(); i++) {
            if (!isdigit(password[i])) {
                cout << "Password can only contain numbers." << endl;
                this_thread::sleep_for(chrono::seconds(3));
                isValid = false;
                break;
            }
        }
        if (isValid) {
            return password;
        }
        loop_count++;
    }
    throw invalidpassword();
}




template<class T>
bool SwimLanes<T>::askpassword(int lane) {
    int correctCheck = 0;
    while(correctCheck != 3) {
        cout<<"Enter password: "<<endl;
        cin>>pass;
        if(pass == tracker[pass_row][lane-1]) {
            return true;
        }
        screenClear();
        cout<<"Incorrect password"<<endl;
        this_thread::sleep_for(chrono::seconds(3));
        screenClear();
        correctCheck++;
    }
    throw incorrectpassword();
}


template class SwimLanes<int>;
