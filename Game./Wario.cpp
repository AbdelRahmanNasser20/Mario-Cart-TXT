#include "Wario.h"

Wario::Wario() : Character(){}

Wario::Wario(string name, double topSpeed, double handling, double acceleration) 
: Character(name, topSpeed, handling, acceleration){}

Wario::~Wario(){}

void Wario::SpecialMove(double trackspeed){

  double topSpeed = 90;
  double boostSpeed = topSpeed + 10;
    
    // if the wairo is going his top end speed, he will get a boost of +10 to his speed
    if (trackspeed >= boostSpeed and GetCurSpeed() >= topSpeed ){
        cout << GetName() << " boosted on the track piece and is going " << boostSpeed << " m/s"<< endl;
        SetCurSpeed(boostSpeed);
        SetSpecialMove(true);
        return;
    }
    // reset special move 
    SetSpecialMove(false);
}

string Wario::GetType(){return "Wario";}

ostream& Wario::operator<<(ostream& output){
    output << "Wario (" << GetName() << ") has gone  " << GetCurLocation() << " meters and is currently going "<< GetCurSpeed() << " m/s";
    return output;
    
}
