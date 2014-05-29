﻿#pragma once

#include <windows.h>
#include "BaseType.h"
#include "Missile.h"

enum TankType { N1, N2, MAXTYPE };

class Tank
{
public :
	Tank();
	~Tank();

	void Attach(HWND);

	void Input(DWORD tick);
	void Update(DWORD tick);
	void Draw(HDC);

	void SetTankType(const TankType& type);
	void SetPosition(const Point& pt);
	void SetRadius(const LONG& r);
	void SetRotateSpeed(const LONG& s);
	void SetMoveSpeed(const LONG& s);
	Point GetCenter() const;

	void SetKeyboard(const int& left, 
					const int& right, 
					const int& fire,
					const int& forward,
					const int& backward);

private :
	void _changepoint();

private :
	HWND hOwner;

	int tank_type;

	Point center;
	LONG radius;

	LONG rotate_speed;
	LONG move_speed;
	Point ptEnd;

	float theta;

	DWORD input_dt;
	DWORD input_delay;

	int key_left;
	int key_right;
	int key_forward;
	int key_backward;
	int key_fire;
};
