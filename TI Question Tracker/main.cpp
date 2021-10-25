#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <iomanip>
using namespace std;

// menu function displays initial menu when called. returns nothing so type void is
// used.
void menu() {
	cout << "Progress Tracker" << endl;
	cout << endl << "Choose 1 of the following: \n\n";
	cout << "1. To-do\n2. Repeat\n3. Done\n4. Exit\n" << endl;
}

// loops, sets the seek pointer of "file" to the beginning of line "num"
fstream& GotoLine(fstream& file, unsigned int num) {
	file.seekg(ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

void evaluate() {
	int score1, score2, score3, score4, score_total;

	cout << "Self Score Evaluation\n\n";
	cout << "Rate yourself on a scale of 1-5 based on the follwoing questions:\n\n";
	cout << "1. Did you need hints? (1-5): ";
	cin >> score1;
	cout << "2. Did you finish within 30 minutes? (1-5): ";
	cin >> score2;
	cout << "3. Was the solution optimal? (1-5): ";
	cin >> score3;
	cout << "4. Were there any bugs? (1-5): ";
	cin >> score4;

	score_total = (score1 + score2 + score3 + score4) / 4;
	cout << "\n\nYour final score for this problem is " << score_total << "\n\n";
}

int main() {
	menu();

	while (true) {
		int bucket_choice;
		char choice;
		int qNum;
		ifstream fileIn;
		ofstream fileOut;

		cout << "Enter choice: ";
		cin >> bucket_choice;

		// switch to identify user choice and proceeds with actions accordingly.
		switch (bucket_choice) {
		case 1:
			while (true) {
				system("CLS");
				cout << "Questions To-do\n\n";
				cout << "(A)dd Question\n";
				cout << "(S)core Question\n";
				cout << "(B)ack\n\n";
				/*
				fileOut.open("todo.txt", ios_base::app);
				fileOut << left << setw(20) << "Name" << setw(20) << "Data Structure" << setw(20) << "Difficulty" << setw(20) << "Score" << endl << endl;
				fileOut.close();
				*/
				fstream file("todo.txt");
				GotoLine(file, 3);
				string line3;
				file >> line3;
				if (line3 == "") {
					cout << "There are no questions to display.\n\n";
				}
				else {
					cout << ifstream("todo.txt").rdbuf() << "\n\n";
				}
				cout << ": ";
				cin >> choice;

				if (choice == 'a' || choice == 'A') {
					system("CLS");
					while (true) {
						char yn;
						string name_of_q;
						string name_of_ds;
						string difficulty;
						cout << "Name of question: ";
						cin >> name_of_q;
						cout << "Name of data structure: ";
						cin >> name_of_ds;
						cout << "Difficulty: ";
						cin >> difficulty;
						fileOut.open("todo.txt", ios_base::app);
						fileOut << left << setw(20) << name_of_q << setw(20) << name_of_ds << setw(20) << difficulty << setw(20) << '?' << endl;
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
				else if (choice == 's' || choice == 'S') {
					system("CLS");
					while (true) {
						int score;
						cout << "Which question do you want to score?\n";
						cout << "Question #: ";
						cin >> qNum;
						qNum = qNum + 2;
						system("CLS");

						evaluate();

						cout << "Set Score for question " << qNum - 2 << ": ";
						cin >> score;
						fstream file("todo.txt");
						GotoLine(file, qNum);
						double pos = file.tellp();
						file.seekp(pos + 60);
						file << score;
						break;
					}
				}
				else if (choice == 'b' || choice == 'B') {
					system("CLS");
					menu();
					break;
				}
			}
			break;
		case 2:
			while (true) {
				system("CLS");
				cout << "Questions that Require Re-Clarification\n\n";
				cout << "(R)e-Evaluate\n";
				cout << "(M)ove to\n\n";
				cout << "Question List:\n\n";
				fstream file("repeat.txt");
				GotoLine(file, 3);
				string line3;
				file >> line3;
				if (line3 == "") {
					cout << "There are no questions to display.\n\n";
				}
				else {
					cout << ifstream("todo.txt").rdbuf() << "\n\n";
				}
				cout << ": ";
				cin >> choice;
				break;
			}
			break;
		case 3:
			while (true) {
				system("CLS");
				cout << "Questions that I've Nailed\n\n";
				cout << "Question List:\n\n";
				cout << ifstream("done.txt").rdbuf() << "\n\n";
				break;
			}
			break;
		case 4:
			return 0;
			break;
		}
	}
}