#include "Toad.h"

Toad::Toad(){}

Toad::Toad(string name, double topSpeed, double handling, double acceleration) 
: Character(name, topSpeed, handling, acceleration){}

Toad::~Toad(){}

void Toad::SpecialMove(double trackspeed){
    
    double maxDriftSpeed = 40.0;
    if (trackspeed <= maxDriftSpeed){
        cout << GetName() << " is drifting on the track piece going " << trackspeed << " m/s"<< endl;
        SetCurSpeed(trackspeed);
        SetSpecialMove(true);
        return;
    }
    SetSpecialMove(false);
}

string Toad::GetType(){return "Toad";}

ostream& Toad::operator<<(ostream& output){
output << "Toad (" << GetName() << ") has gone  " << GetCurLocation() << " meters and is currently going "<< GetCurSpeed() << " m/s";
return output;
}
