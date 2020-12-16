#include "Header.h"
#include "ListPayer.h"
#include "Inputs.h"


Inputs::Inputs()
{
	surname = new char[50];
	phone_number = new char[50];
	tariff = 1.0;
	discount = 0.0;
	all_seconds_start = 0;
	all_seconds_end = 0;
	date = new char[50];
	sign = new char[50];
	pay_date = new char[50];
}

Inputs::~Inputs()
{
	delete[] surname;
	delete[] phone_number;
	delete[] date;
	delete[] sign;
	delete[] pay_date;
}

int Inputs::input_seconds_start()
{
	int hours;
	int minutes;
	int seconds;

	cout << "What time did that user start the speaking?\n";

	while (true)
	{
		cout << "Hours -> ";
		cin >> hours;
		if (hours > 24 || hours < 0)
		{
			cout << "Incorrect input! Try again!\n";
		}
		else
			break;
	}

	while (true)
	{
		cout << "Minutes -> ";
		cin >> minutes;
		if (minutes > 59 || minutes < 0)
		{
			cout << "Incorrect input! Try again!\n";
		}
		else
			break;
	}

	while (true)
	{
		cout << "Seconds -> ";
		cin >> seconds;
		if (seconds > 59 || seconds < 0)
		{
			cout << "Incorrect input! Try again!\n";
		}
		else
			break;
	}

	all_seconds_start += ((hours * 60 * 60) + (minutes * 60) + seconds);

	return all_seconds_start;
}

int Inputs::get_seconds_start()
{
	return all_seconds_start;
}

int Inputs::input_seconds_end()
{
	int hours;
	int minutes;
	int seconds;

	cout << "What time did that user finish the speaking?\n";

	while (true)
	{
		cout << "Hours -> ";
		cin >> hours;
		if (hours > 24 || hours < 0)
		{
			cout << "Incorrect input! Try again!\n";
		}
		else
			break;
	}

	while (true)
	{
		cout << "Minutes -> ";
		cin >> minutes;
		if (minutes > 59 || minutes < 0)
		{
			cout << "Incorrect input! Try again!\n";
		}
		else
			break;
	}

	while (true)
	{
		cout << "Seconds -> ";
		cin >> seconds;
		if (seconds > 59 || seconds < 0)
		{
			cout << "Incorrect input! Try again!\n";
		}
		else
			break;
	}

	system("CLS");

	all_seconds_end += ((hours * 60 * 60) + (minutes * 60) + seconds);

	return all_seconds_end;
}

int Inputs::get_seconds_end()
{
	return all_seconds_end;
}

float Inputs::input_discout()
{
	while (true)
	{
		cout << "Personal Discout(%) of this user = ";
		cin >> discount;
		if (discount > 100 || discount < 0)
			cout << "Incorrect input! Try again!\n";
		else
			break;
	}
	return discount;
}

float Inputs::get_disount()
{
	return discount;
}

float Inputs::input_tariff()
{
	while (true)
	{
		cout << "Tariff of this user (cost per min) = ";
		cin >> tariff;
		if (tariff <= 0)
			cout << "Incorrect input! Try again!\n";
		else
			break;
	}
	return tariff;
}

char* Inputs::input_phone()
{
	cout << "Plaese input the phone number -> ";
	cin.getline(phone_number, 50, '\n');
	return phone_number;
}


float Inputs::toString(int minutes, float discount)
{
	float myprice = (1.0f - (discount / 100.0f));
	if (discount == 0)
		return (minutes * tariff);
	else
		return (minutes * tariff * myprice);
}

char* Inputs::date_input()
{
	cout << "Plaese input the date of creating this list -> ";
	cin.getline(date, 50, '\n');
	return date;
}

char* Inputs::sign_pay()
{
	system("CLS");
	bool checker = true;
	char choice;
	while (checker == true)
	{
		cout << "Please specify a payment method\n";
		cout << "1. By cash\n";
		cout << "2. By card\n";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case'1':
		{
			strcpy_s(sign, 50, "Cash");
			checker = false;
			break;
		}
		case'2':
		{
			strcpy_s(sign, 50, "Card");
			checker = false;
			break;
		}
		default: cout << "Incorrect input! Try again!\n";
			break;
		}
	}
	return sign;
}

float Inputs::payed()
{
	system("CLS");
	while (true)
	{
		cout << "How much payed this user before he started speaking: ";
		cin >> payed_money;
		if (payed_money >= 0)
		{
			return payed_money;
		}
		else
		{
			cout << "Incorrect input! Try again!\n";
		}
	}
}

char* Inputs::date_of_pay()
{
	cin.ignore();
	cout << "Plaese input the date of pay -> ";
	cin.getline(pay_date, 50, '\n');
	return pay_date;
}

char* Inputs::input_surname()
{
	cout << "Please input the Surname -> ";
	cin.getline(surname, 50, '\n');
	return surname;
}
