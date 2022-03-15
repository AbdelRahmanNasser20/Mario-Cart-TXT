#include "Obstacle.h"

Obstacle::Obstacle(){}

Obstacle::Obstacle(string color){
m_color = color;}

Obstacle::~Obstacle(){}

string Obstacle::GetColor(){return m_color;}

void Obstacle::SetColor(string color){m_color = color;}
