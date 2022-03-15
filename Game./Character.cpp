#include "Character.h"
Character::Character(){}

Character::Character(string name, double topSpeed, double handling, double acceleration)
: Entity(name){
    m_topSpeed = topSpeed;
    m_handling = handling;
    m_acceleration = acceleration;
}

Character::~Character(){}

double Character::GetCurLocation(){return m_curLocation;}

void Character::SetCurLocation(double curLocation){m_curLocation = curLocation;}

double Character::GetCurSpeed(){return m_curSpeed;}

void Character::SetCurSpeed(double curSpeed){m_curSpeed = curSpeed;}

double Character::GetTopSpeed(){return m_topSpeed;}

double Character::GetHandling(){return m_handling;}

double Character::GetAcceleration(){return m_acceleration;}

void Character::SpecialMove(double){}

bool Character::GetSpecialMove(){return m_specialMove;}

void Character::SetSpecialMove(bool specialMove){m_specialMove = specialMove;}

void Character::CalcSpeed(double gas){

    // ensures user doesnt go above their own top speed
    if (m_curSpeed < m_topSpeed){
        m_curSpeed += m_acceleration * m_handling;
    }
    if (m_curSpeed > m_topSpeed){
        m_curSpeed = m_topSpeed;
    }
    
    m_curSpeed = m_curSpeed * gas;
}

void Character::Tick(double maxSpeedTrack){
    
    // if user goes faster then the track and they dont use their special move then they crash 
    if ((m_curSpeed > maxSpeedTrack) and GetSpecialMove() == false){
        cout << GetType() << " (" << GetName() << ") " << m_curSpeed << " vs Max: " << maxSpeedTrack << endl;
        cout << GetType() << " (" << GetName() << ") has crashed!" << endl;
        m_curSpeed = 0;
    }
    m_curLocation += m_curSpeed;
}  

bool Character::GetCrash(){return m_crash;}
  
void Character::SetCrash(bool crash){m_crash = crash;}
