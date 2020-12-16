#include "Header.h"
#include "ListPayer.h"
#include "Inputs.h"
#include "Time.h"

Time::Time(int end_seconds, int start_seconds)
{
	this->start_seconds = start_seconds;
	this->end_seconds = end_seconds;
}

Time::~Time()
{

}

int Time::get_minutes()
{
	int check = (end_seconds - start_seconds) % 60;
	if (check == 0)
		return (((end_seconds - start_seconds) / 60));
	else
		return (((end_seconds - start_seconds) / 60) + 1);

}