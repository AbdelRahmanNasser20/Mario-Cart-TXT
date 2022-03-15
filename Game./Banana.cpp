#include "Banana.h"

Banana::Banana(){}

Banana::~Banana(){}

string Banana::GetType(){return "Banana";}

ostream& Banana::operator<<(ostream& output){
    output << "a Banana";
    return output;
}
