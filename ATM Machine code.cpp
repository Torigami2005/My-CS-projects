#include <iostream>
#include <string>
using namespace std;

int main() {
	string firstName, lastName;
	char choice;
	const double transfee = 3.48;
	int account_number;
	double bankAcc = 5000;
	int withdraw, pin1, pin2;

	// register names
	cout << "Welcome to the ATM Machine!: \n";
	cout << "Please enter your account number: \n";
	cin >> account_number;
	cout << "Please enter your first name and last name: \n";
	cin >> firstName >> lastName;
	cout << "Enter 4 digit-pin: \n";
	cin >> pin1;
	while (pin1 <= 1000 || pin1 >= 10000) {
		cout << "Fail 4-digit pin. Enter again: \n";
		pin1 = 0;
		cin >> pin1;
	}
	cout << "Verify your 4-digit pin: \n";
	cin >> pin2;
	while (pin1 != pin2) {
		cout << "Fail to verify 4-digit pin. Enter again\n";
		cin >> pin2;
	}

	// ATM operations
	do {
		cout << "Welcome to your ATM machine!\n";
		cout << "Please choose from the menu below:\n";
		cout << "[W]ithdraw money\n";
		cout << "[C]heck balance\n";
		cout << "E[x]it\n";
		cin >> choice;
		// Withdraw
		if ((choice == 'W') || (choice == 'w')) {
			cout << "Enter any value to be withdrawn:\n";
			cin >> withdraw;

			while (withdraw % 100 != 0 || (withdraw +transfee) > bankAcc || withdraw <= 0) {
				cout << "Fail to withdraw! Amount should not be not enough or more than your current balance! (minimum of 100 php)" << endl;
				cin >> withdraw;
			}
			if (withdraw > 0 && (withdraw + transfee) <= bankAcc) {
				bankAcc -= withdraw + transfee;
				cout << "Withdraw successfully! Your account is: " << bankAcc << endl;
			}
			// Check Balance
		}
		else if ((choice == 'C') || (choice == 'c')) {
			cout << "-----------------------------------" << endl;
			cout << firstName << " " << lastName << "\t" << account_number << endl;
			cout << "-----------------------------------" << endl;
			cout << "Your current balance is: " << bankAcc << endl;
		}
		// Exit
		else if ((choice == 'X' || (choice == 'x'))) {
			cout << "Thank you for using the ATM Machine!\n" << endl;
			return 0;
		}
		else {
			cout << endl;
		}
	} while (bankAcc > 0);

}