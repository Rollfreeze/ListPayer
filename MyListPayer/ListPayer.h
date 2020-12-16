#pragma once
#include "Header.h"
#include "Inputs.h"
#include "Time.h"

class Bill
{
public:
	char* surname;
	char* phone;
	char* sign_of_payment;
	float tariff;
	float discount;
	float pay_sum;
	int minutes;
	int begin_seconds;
	int end_seconds;
	int user_id;
	float payed;
	float balance;
	char* pay_date;
	Bill* pNext;
	Bill()
	{
		this->phone = new char[50];
		this->surname = new char[50];
		this->sign_of_payment = new char[50];
		this->pay_date = new char[50];
	}
	~Bill()
	{
		delete[] phone;
		delete[] surname;
		delete[] sign_of_payment;
		delete[] pay_date;
	}
};

class ListPayer
{
private:
	Bill* head;
	int size;
	char* date;
	float credit;
	float payed_credit;
public:
	ListPayer()
	{
		head = NULL;
		size = 0;
		date = new char[50];
	}
	~ListPayer()
	{
		clear();
		delete[] date;
	}
	void push_back();
	void display();
	int get_size();
	char* get_date();
	void date_input();
	void pop_front(); //удаление первого элемента
	void clear(); // удаление всех пользователей

	void fix_id();
	void removeAt(int);

	void credit_check();
	//Bill& operator[](const int index);
};

