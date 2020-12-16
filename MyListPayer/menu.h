#pragma once
#include "Header.h"
#include "ListPayer.h"
#include "Inputs.h"
#include "Time.h"

class menu
{
public:
	menu()
	{
		int ID;
		ListPayer list;
		char choice;
		bool checker = true;
		bool checker_two = true;
		while (checker == true)
		{
			cout << "Choose what you wanna do:\n";
			cout << "1. Creat a list\n";
			cout << "0. Quit\n";
			cin >> choice;
			cin.ignore();
			system("CLS");
			switch (choice)
			{
			case'1':
			{
				list.date_input();
				checker = true;
				system("CLS");

				cout << "Now please input the first user\n";
				list.push_back();
				cout << "You have successfully entered the user in the database\n\n";
				while (checker == true)
				{
					cout << "Choose what you wanna do:\n";
					cout << "1. Add a new user\n";
					cout << "2. Show the set list of useres\n";
					cout << "3. Check the date of creating the list\n";
					cout << "4. Delete the first user\n";
					cout << "5. Delete all users and clear the list\n";
					cout << "6. Learn the ammount of users in the list\n";
					cout << "7. Delete the certain user\n";
					cout << "8. Check total cost of all users\n";
					cout << "0. Quit\n";
					cin >> choice;
					cin.ignore();
					system("CLS");
					switch (choice)
					{
					case'1':
					{
						list.push_back();
						system("CLS");
						cout << "You have successfully entered the user in the database\n\n";
						break;
					}
					case'2':
					{
						list.display();
						break;
					}
					case'3':
					{
						cout << "The date of creating the list: " << list.get_date() << endl << endl;
						break;
					}
					case'4':
					{
						list.fix_id(); // провожу сортировку id юзеров, чтобы не нарушался порядок
						list.pop_front();
						cout << "You have successfully deleted the first user in the list\n\n";
						break;
					}
					case'5':
					{
						list.clear();
						cout << "You have successfully deleted all users from the database\n\n";
						break;
					}
					case'6':
					{
						cout << "The ammount of users in the list now is: " << list.get_size() << endl;
						break;
					}
					case'7':
					{
						while (checker_two == true)
						{
							cout << "Input user's ID you want to remove from the list\n";
							cin >> ID;
							if (ID < 0)
							{
								cout << "Incorrect input! Try again!\n";
							}
							else
							{
								list.removeAt(ID);
								checker_two = false;
							}
						}
						cout << "You have successfully deleted the user\n\n";
						break;
					}
					case'8':
					{
						list.credit_check();
						break;
					}
					case'0':
					{
						checker = false;
						break;
					}
					default:
					{
						cout << "Incorrect input. Try again!\n";
						break;
					}
					}
				}
			}
			case'0': checker = false;
				break;
			default: cout << "Incorrect input! Try again!\n";
				break;
			}
		}
	}
};

