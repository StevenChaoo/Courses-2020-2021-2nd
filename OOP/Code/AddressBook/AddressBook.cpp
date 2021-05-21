// Author:STEVEN
//
#include <pthread.h>

#include <iostream>
using namespace std;

struct demo {
	int id;
	string name;
	string sex;
	int age;
	long tel;
	string location;
};

void ShowMenu() {
	/*
To show address book menu.
	*/
	cout << "| Welcome to address book! |" << endl
	     << endl
	     << "1. Add user" << endl
	     << "2. Show users" << endl
	     << "3. Delete user" << endl
	     << "4. Search user" << endl
	     << "5. Modify user" << endl
	     << "6. Clear all users" << endl
	     << "7. Quit" << endl
	     << endl;
}

int InputSelectNumber() {
	/*
To receive user's selected number.
	*/
	int select_number = 0;
	cout << "Please input the index number: ";
	cin >> select_number;
	cout << endl;
	return select_number;
}

void AddUser(demo users[], int &users_number) {
	/*
To add a new user.
	*/
	demo user;
	user.id = users_number;
	cout << "Please input the information of new user: " << endl;
	cout << "Name is ";
	cin >> user.name;
	cout << "Sex is ";
	cin >> user.sex;
	cout << "Age is ";
	cin >> user.age;
	cout << "Telephone number is ";
	cin >> user.tel;
	cout << "Location is ";
	cin >> user.location;
	users[users_number] = user;
	users_number++;
	cout << endl << "[!!!] Add Successifully!" << endl << endl;
}

void ShowUsers(demo users[], int users_number) {
	/*
To show all users.
	*/
	if (users_number != 0) {
		cout << "Name\tSex\tAge\tTelephone\tlocation" << endl;
		for (int i = 0; i < users_number; i++) {
			cout << users[i].name << "\t" << users[i].sex << "\t"
			     << users[i].age << "\t" << users[i].tel << "\t"
			     << users[i].location << endl;
		}
		cout << endl;
	} else {
		cout << "No user!" << endl << endl;
	}
}

void DeleteUser(demo users[], int &users_number) {
	/*
To delete a user.
	*/
	if (users_number != 0) {
		cout << "ID\tName\tSex\tAge\tTelephone\tlocation" << endl;
		for (int i = 0; i < users_number; i++) {
			cout << i << "\t" << users[i].name << "\t"
			     << users[i].sex << "\t" << users[i].age << "\t"
			     << users[i].tel << "\t" << users[i].location
			     << endl;
		}
		cout << endl;
		cout << "Please input the id of user you want to "
			"delete: ";
		int id = 0;
		cin >> id;
		for (int j = 0; j < users_number; j++) {
			if (j == users_number - 1 && id != j) {
				cout << endl << "Wrong input!" << endl << endl;
				break;
			} else if (id == j) {
				users[j] = users[users_number - 1];
				users_number--;
				cout << endl
				     << "[!!!] Delete successifully!" << endl
				     << endl;
				break;
			}
		}
	} else {
		cout << "No user!" << endl << endl;
	}
}

void SearchUser(demo users[], int users_number) {
	/*
To search a user.
	*/
	string name = "";
	cout << "Please input the name you want to search: ";
	cin >> name;
	cout << endl;
	for (int i = 0; i < users_number; i++) {
		if (i == users_number - 1 && name != users[i].name) {
			cout << "Wrong name!" << endl << endl;
		} else if (name == users[i].name) {
			cout << "Name\tSex\tAge\tTelephone\tlocation" << endl;
			break;
		}
	}
	for (int i = 0; i < users_number; i++) {
		if (name == users[i].name) {
			cout << users[i].name << "\t" << users[i].sex << "\t"
			     << users[i].age << "\t" << users[i].tel << "\t"
			     << users[i].location << endl;
		}
	}
	cout << endl;
}

void ModifyUser(demo users[], int users_number) {
	/*
To modufy user's information.
	*/
	if (users_number != 0) {
		cout << "ID\tName\tSex\tAge\tTelephone\tlocation" << endl;
		for (int i = 0; i < users_number; i++) {
			cout << i << "\t" << users[i].name << "\t"
			     << users[i].sex << "\t" << users[i].age << "\t"
			     << users[i].tel << "\t" << users[i].location
			     << endl;
		}
		cout << endl;
		cout << "Please input the id of user you want to "
			"modify: "
		     << endl;
		int id = 0;
		cin >> id;
		for (int j = 0; j < users_number; j++) {
			if (id == users_number - 1 && id != j) {
				cout << "Wrong input" << endl << endl;
			} else if (id == j) {
				demo user;
				cout << "Please input the information of new "
					"user: "
				     << endl;
				cout << "Name is ";
				cin >> user.name;
				cout << "Sex is ";
				cin >> user.sex;
				cout << "Age is ";
				cin >> user.age;
				cout << "Telephone number is ";
				cin >> user.tel;
				cout << "Location is ";
				cin >> user.location;
				users[j] = user;
				cout << endl
				     << "[!!!] Modify Successifully!" << endl
				     << endl;
			}
		}
	}
}

void ClearUsers(demo users[], int &users_number) {
	/*
To delete all users.
	*/
	users_number = 0;
	cout << "Deleted all users!" << endl << endl;
}

int main() {
	cout << endl;

	demo users[1000];
	int users_number = 0;
	ShowMenu();
	while (true) {
		int select_number = InputSelectNumber();
		if (select_number != 1 && select_number != 2 &&
		    select_number != 3 && select_number != 4 &&
		    select_number != 5 && select_number != 6 &&
		    select_number != 7) {
			cout << "Wrong input!" << endl << endl;
		} else {
			switch (select_number) {
				case 1:	 // Add a new user.
					AddUser(users, users_number);
					break;
				case 2:	 // Show all users.
					ShowUsers(users, users_number);
					break;
				case 3:	 // Delete a user.
					DeleteUser(users, users_number);
					break;
				case 4:	 // Search a user.
					SearchUser(users, users_number);
					break;
				case 5:	 // Modify a user.
					ModifyUser(users, users_number);
					break;
				case 6:	 // Clear all users.
					ClearUsers(users, users_number);
					break;
				case 7:	 // Quit.
					break;
			}
			if (select_number == 7) {
				break;
			}
		}
	}

	cout << endl;
	return 0;
}
