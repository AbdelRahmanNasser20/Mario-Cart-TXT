#include "Entity.h"
Entity::Entity(){}

Entity::Entity(string name){m_name = name;}

Entity::~Entity(){}

string Entity::GetName(){return m_name;}

void Entity::SetName(string name){m_name = name;}
