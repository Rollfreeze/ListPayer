#include "Header.h"
#include "ListPayer.h"
#include "Inputs.h"

void ListPayer::push_back()
{
	if (head == NULL)
	{
		head = new Bill;

		Inputs inputs;
		strcpy_s(head->phone, 50, inputs.input_phone());
		strcpy_s(head->surname, 50, inputs.input_surname());
		Time time(inputs.input_seconds_end(), inputs.input_seconds_start());
		head->tariff = inputs.input_tariff();
		head->discount = inputs.input_discout();
		strcpy_s(head->sign_of_payment, 50, inputs.sign_pay());
		head->begin_seconds = inputs.get_seconds_start();
		head->end_seconds = inputs.get_seconds_end();
		head->minutes = time.get_minutes();
		head->payed = inputs.payed();
		strcpy_s(head->pay_date, 50, inputs.date_of_pay());
		head->pay_sum = inputs.toString(time.get_minutes(), inputs.get_disount());
		head->user_id = size;
		head->balance = head->payed - head->pay_sum;

		head->pNext = NULL;
	}
	else
	{
		Bill* current = this->head;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Bill;

		Inputs inputs;
		strcpy_s(current->pNext->phone, 50, inputs.input_phone());
		strcpy_s(current->pNext->surname, 50, inputs.input_surname());
		Time time(inputs.input_seconds_end(), inputs.input_seconds_start());
		current->pNext->tariff = inputs.input_tariff();
		current->pNext->discount = inputs.input_discout();
		strcpy_s(current->pNext->sign_of_payment, 50, inputs.sign_pay());
		current->pNext->begin_seconds = inputs.get_seconds_start();
		current->pNext->end_seconds = inputs.get_seconds_end();
		current->pNext->minutes = time.get_minutes();
		current->pNext->payed = inputs.payed();
		strcpy_s(current->pNext->pay_date, 50, inputs.date_of_pay());
		current->pNext->pay_sum = inputs.toString(time.get_minutes(), inputs.get_disount());
		current->pNext->user_id = size;
		current->pNext->balance = current->pNext->payed - current->pNext->pay_sum;
	}
	
	size++;
}

void ListPayer::display()
{
	Bill* current = head;
	while (current)
	{
		cout << "User ID: " << current->user_id << endl;
		cout << "Surname: " << current->surname << endl;
		cout << "Phone number: " << current->phone << endl;
		cout << "Tariff (rubs per min): " << current->tariff << endl;
		cout << "Discount (in %): " << current->discount << endl;
		cout << "Sign of payment: " << current->sign_of_payment << endl;
		cout << "Spoken minutes: " << current->minutes << endl;
		cout << "Have to pay for the last speaking: " << current->pay_sum << endl;
		cout << "Already payed: " << current->payed << endl;
		cout << "Date of pay: " << current->pay_date << endl;
		cout << "Current state of the balance: " << current->balance << endl;
		cout << "-----------------------------------\n" << endl;
		current = current->pNext;
	}
}

int ListPayer::get_size()
{
	return size;
}

void ListPayer::date_input()
{
	Inputs inputs;
	strcpy_s(date, 50, inputs.date_input());
}

void ListPayer::pop_front()
{
	Bill* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

void ListPayer::clear()
{
	while (size)
	{
		pop_front();
	}
}

void ListPayer::fix_id()
{
	Bill* temp = head;
	while (temp->pNext != NULL)
	{
		temp->user_id = temp->user_id - 1;
		temp = temp->pNext;
	}
	temp->user_id = temp->user_id - 1;
}

void ListPayer::removeAt(int id)
{
	if (id == 0)
	{
		pop_front();
	}
	else
	{
		Bill* previous = this->head;
		for (int i = 0; i < id - 1; i++)
		{
			previous = previous->pNext;
		}

		Bill* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		size--;

		for (int i = id; i < size; i++)
		{
			previous->pNext->user_id = previous->pNext->user_id - 1;
			previous = previous->pNext;
		}
	}
}

void ListPayer::credit_check()
{
	credit = 0;
	payed_credit = 0;

	Bill* current = this->head;

	for (int i = 0; i < size; i++)
	{
		credit += current->pay_sum;
		payed_credit += current->payed;
		current = current->pNext;
	}

	cout << "Total cost of service is: " << credit << endl;
	cout << "Users payed: " << payed_credit << " / " << credit << endl << endl;
}

char* ListPayer::get_date()
{
	return date;
}

// в этом задании такая перегрузка неуместна, поскольку у нас много значений в одном узле, а не одно
/*
Bill& ListPayer::operator[](const int index)
{
	int counter = 0;
	Bill* current = first;
	while (current != NULL)
	{
		if (counter == index)
		{
			return current->
		}
		current = current->pNext;
		counter++;
	}
}
*/
