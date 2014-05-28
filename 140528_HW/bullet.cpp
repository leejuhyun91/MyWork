#include "bullet.h"



Bullet::Bullet()
: radius(2)
, speed(5)
, theta(0)
{	
}
Bullet::~Bullet()
{	
}

void Bullet::SetPosition(const Point& p)
{
	center = p;
}
void Bullet::SetRadius(const LONG& r)
{
	radius = r;
}
void Bullet::SetSpeed(const LONG& s)
{
	speed = s;
}
void Bullet::GetCenter() const
{
	return center;
}