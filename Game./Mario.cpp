#include "Mario.h"

Mario::Mario() : Character(){}

Mario::Mario(string name, double topSpeed, double handling, double acceleration) 
: Character(name, topSpeed, handling, acceleration){}

Mario::~Mario(){}

void Mario::SpecialMove(double trackSpeed){    
    if (GetCrash() == true){
        SetCrash(false);
        cout << GetName() << " has dodged the obstical" << endl;
    }
}

string Mario::GetType(){return "Mario";}

ostream& Mario::operator<<(ostream& output){
    output << "Mario (" << GetName() << ") has gone  " << GetCurLocation() << " meters and is currently going " << GetCurSpeed() << " m/s";
    return output;
    
}
