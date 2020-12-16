#pragma once
#include "Header.h"
#include "ListPayer.h"
#include "Time.h"

class Inputs
{
private:
	int all_seconds_start;
	int all_seconds_end;
	float discount;
	float tariff;
	char* surname;
	char* phone_number;
	char* date;
	char* sign;
	float payed_money;
	char* pay_date;
public:
	int input_seconds_start();
	int get_seconds_start();
	int input_seconds_end();
	int get_seconds_end();
	float input_discout();
	float get_disount();
	float input_tariff();
	char* input_surname();
	char* input_phone();
	float toString(int, float);
	char* date_input();
	char* sign_pay();
	float payed();
	char* date_of_pay();
	Inputs();
	~Inputs();
};

