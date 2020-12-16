#pragma once
#include "Header.h"
#include "Inputs.h"
#include "ListPayer.h"

class Time
{
private:
	int start_seconds;
	int end_seconds;
public:
	Time(int, int);
	~Time();
	int get_minutes();
};

