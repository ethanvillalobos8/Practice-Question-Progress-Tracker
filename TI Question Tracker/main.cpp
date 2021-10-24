#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void menu() {
	cout << "Progress Tracker" << endl;
	cout << endl << "Choose 1 of the following: \n\n";
	cout << "1. To-do\n2. Repeat\n3. Done\n4. Exit\n" << endl;
}

int main() {
	menu();

	while (true) {
		int bucket_choice;
		ifstream fileIn;
		ofstream fileOut;

		cout << "Enter choice: ";
		cin >> bucket_choice;

		switch (bucket_choice) {
		case 1:
			while (true) {
				char choice;
				system("CLS");
				cout << "Questions To-do\n\n";
				cout << "(A)dd Question\n";
				cout << "(B)ack\n\n";
				cout << "Question List:\n\n";
				cout << ifstream("todo.txt").rdbuf() << "\n\n";
				cout << ": ";
				cin >> choice;

				if (choice == 'a' || choice == 'A') {
					system("CLS");
					while (true) {
						char yn;
						string name_of_q;
						cout << "Name of question: ";
						cin >> name_of_q;
						fileOut.open("todo.txt", ios_base::app);
						fileOut << name_of_q << endl;
						fileOut.close();
						cout << "\n\nQuestion saved.\n\n";
						cout << "Add another? (Y/N): ";
						cin >> yn;

						if (yn == 'y' || yn == 'Y') {
							system("CLS");
							NULL;
						}
						else if (yn == 'n' || yn == 'N') {
							break;
						}
					}
				}
				else if (choice == 'b' || choice == 'B') {
					system("CLS");
					menu();
					break;
				}
			}
		case 2:
			while (true) {
				system("CLS");
				cout << "Questions that Require Re-Clarification\n\n";
				cout << "Question List:\n\n";
				cout << ifstream("repeat.txt").rdbuf() << "\n\n";
			}
		case 4:
			return 0;
		}
	}
}