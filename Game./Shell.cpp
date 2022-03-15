#include "Shell.h"
Shell::Shell(){}

Shell::~Shell(){}

string Shell::GetType(){return "Shell";}

ostream& Shell::operator<<(ostream& output){
    output << "a Shell";
    return output;
}
