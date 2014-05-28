#pragma once

#include "BaseType.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Draw();

	void SetPosition(const Point& p);
	void SetRadius(const LONG& r);
	void SetSpeed(const LONG& s);
	void GetCenter() const;

private:
	Point center;
	LONG radius;
	LONG speed;
	LONG theta;


}