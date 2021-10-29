#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <iomanip>
#include <stdio.h>
using namespace std;

void System() {
	if (system("CLS")) system("clear");
}

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
	cout << "Rate yourself on a scale of 1-5 based on the following questions:\n\n";
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

void Move(int c, int s, int q) {
	if (c == 1) {
		if (s == 1 || s == 2) {
			ofstream of("todo.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("todo.txt");
			int count = 0;
			while (getline(inf, line)) {
				if (count == q - 1) {
					of << line << endl;
					cout << "This question has stayed in To-do" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}
			inf.close();
			of.close();
			temp.close();
		}
		else if (s == 3 || s == 4) {
			ofstream of("repeat.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("todo.txt");
			int count = 0;
			while (getline(inf, line)) {
				if (count == q - 1) {
					of << line << endl;
					cout << "This question has been moved to Repeat" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}
			inf.close();
			of.close();
			temp.close();
		}
		else if (s == 5) {
			ofstream of("done.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("todo.txt");
			int count = 0;
			while (getline(inf, line)) {
				if (count == q - 1) {
					of << line << endl;
					cout << "This question has been moved to Done" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}
			inf.close();
			of.close();
			temp.close();
		}
		remove("todo.txt");
		system("pause");
		int result;
		result = rename("temp.txt", "todo.txt");
		if (result == 0)
			NULL;
		else
			perror("\nInternal error: data transfer unsucsessful");
		system("pause");
	}
	else if (c == 2) {
		if (s == 1) {
			ofstream of("todo.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("repeat.txt");
			int count = 0;
			while (getline(inf, line)) {
				if (count == q - 1) {
					of << line << endl;
					cout << "This question has been moved to To-do" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}
			inf.close();
			of.close();
			temp.close();
		}
		else if (s == 5) {
			ofstream of("done.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("repeat.txt");
			int count = 0;
			while (getline(inf, line)) {
				if (count == q - 1) {
					of << line << endl;
					cout << "This question has been moved to Done" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}
			inf.close();
			of.close();
			temp.close();
		}
		remove("repeat.txt");
		system("pause");
		int result;
		result = rename("temp.txt", "repeat.txt");
		if (result == 0)
			NULL;
		else
			perror("\nInternal error: data transfer unsucsessful");
		system("pause");
	}
	else if (c == 3) {
		if (s == 1) {
			ofstream of("todo.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("done.txt");
			int count = 0;
			while (getline(inf, line)) {
				if (count == q - 1) {
					of << line << endl;
					cout << "This question has been moved to To-do" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}
			inf.close();
			of.close();
			temp.close();
		}
		else if (s == 3) {
			ofstream of("repeat.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("done.txt");
			int count = 0;
			while (getline(inf, line)) {
				if (count == q - 1) {
					of << line << endl;
					cout << "This question has been moved to Repeat" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}
			inf.close();
			of.close();
			temp.close();
		}
	remove("done.txt");
	int result;
	result = rename("temp.txt", "done.txt");
	if (result == 0)
		NULL;
	else
		perror("\nInternal error: data transfer unsucsessful");
	system("pause");
	}
}

int line_number(int c, int i) {
	string line;
	switch (c) {
	case 1: {
		ifstream file("todo.txt");
		while (getline(file, line)) {
			i++;
		}
		file.close();
		break;
	}
	case 2: {
		ifstream file2("repeat.txt");
		while (getline(file2, line)) {
			i++;
		}
		file2.close();
		break;
	}
	case 3: {
		ifstream file3("done.txt");
		while (getline(file3, line)) {
			i++;
		}
		file3.close();
		break;
	}
	}
	i = i - 2;
	return i;
}

int main() {
	menu();

	while (true) {
		int bucket_choice;
		char choice;
		int qNum;
		int lNum = 1;
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
				fileOut << left << setw(3) << setw(20) << "Name" << setw(20) << "Data Structure" << setw(20) << "Difficulty" << setw(20) << "Score" << endl << endl;
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
				file.close();
				cout << ": ";
				cin >> choice;

				if (choice == 'a' || choice == 'A') {
					System();
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
						fileOut << left << setw(5) << line_number(bucket_choice, lNum) << setw(20) << name_of_q << setw(20) << name_of_ds << setw(20) << difficulty << setw(20) << '?' << endl;
						fileOut.close();
						cout << "\n\nQuestion saved.\n\n";
						cout << "Add another? (Y/N): ";
						cin >> yn;

						if (yn == 'y' || yn == 'Y') {
							System();
							NULL;
						}
						else if (yn == 'n' || yn == 'N') {
							break;
						}
					}
				}
				else if (choice == 's' || choice == 'S') {
					System();
					int score;
					while (true) {
						cout << "Which question do you want to score?\n";
						cout << "Question #: ";
						cin >> qNum;
						qNum = qNum + 2;
						System();

						evaluate();

						cout << "Set Score for question " << qNum - 2 << ": ";
						cin >> score;
						fstream file("todo.txt");
						GotoLine(file, qNum);
						double pos = file.tellp();
						file.seekp(pos + 65);
						file << score;
						file.close();
						break;
					}
					Move(bucket_choice, score, qNum);
				}
				else if (choice == 'b' || choice == 'B') {
					System();
					menu();
					break;
				}
			}
			break;
		case 2:
			while (true) {
				while (true) {
					System();
					cout << "Questions that Require Re-Clarification\n\n";
					cout << "(R)e-Evaluate\n";
					cout << "(M)ove to\n";
					cout << "(B)ack\n\n";
					fstream file("repeat.txt");
					GotoLine(file, 3);
					string line3;
					file >> line3;
					if (line3 == "") {
						cout << "There are no questions to display.\n\n";
					}
					else {
						cout << ifstream("repeat.txt").rdbuf() << "\n\n";
					}
					file.close();
					cout << ": ";
					cin >> choice;

					if (choice == 'r' || choice == 'R') {
						System();
						int score;
						while (true) {
							cout << "Which question do you want to re-score?\n";
							cout << "Question #: ";
							cin >> qNum;
							qNum = qNum + 2;
							System();

							evaluate();

							cout << "Set Score for question " << qNum - 2 << ": ";
							cin >> score;
							fstream file("repeat.txt");
							GotoLine(file, qNum);
							double pos = file.tellp();
							file.seekp(pos + 60);
							file << score;
							file.close();
							break;
						}
						Move(bucket_choice, score, qNum);
					}
					break;
				}
				if (choice == 'm' || choice == 'M') {
					System();
					int score;
					while (true) {
						cout << "Which question do you want to move?\n\n";
						cout << "Question #: ";
						cin >> qNum;
						qNum = qNum + 2;
						System();
						while (true) {
							cout << "Where do you want to move question " << qNum << " to?\n\n";
							cout << "1. To-do\n";
							cout << "2. Done\n\n";
							cout << ": ";
							cin >> score;
							if (score == 1) {
								break;
							}
							else if (score == 2) {
								score = score + 3;
								break;
							}
							else {
								cout << "Invalid input. Please try again.\n\n";
								system("pause");
							}
						}
						break;
						System();
					}
					Move(bucket_choice, score, qNum);
				}
				else if (choice == 'b' || choice == 'B') {
					System();
					menu();
					break;
				}
			}
			break;
		case 3:
			while (true) {
				while (true) {
					System();
					cout << "Questions that I've Nailed\n\n";
					cout << "(M)ove to\n";
					cout << "(B)ack\n\n";
					fstream file("done.txt");
					GotoLine(file, 3);
					string line3;
					file >> line3;
					if (line3 == "") {
						cout << "There are no questions to display.\n\n";
					}
					else {
						cout << ifstream("done.txt").rdbuf() << "\n\n";
					}
					file.close();
					cout << ": ";
					cin >> choice;
					if (choice == 'm' || choice == 'M') {
						System();
						int score;
						while (true) {
							cout << "Which question do you want to move?\n\n";
							cout << "Question #: ";
							cin >> qNum;
							qNum = qNum + 2;
							System();
							while (true) {
								cout << "Where do you want to move question " << qNum << " to?\n\n";
								cout << "1. To-do\n";
								cout << "2. Repeat\n\n";
								cout << ": ";
								cin >> score;
								if (score == 1) {
									break;
								}
								else if (score == 2) {
									score = score + 1;
									break;
								}
								else {
									cout << "Invalid input. Please try again.\n\n";
									system("pause");
								}
							}
							break;
							System();
						}
						Move(bucket_choice, score, qNum);
					}
					else if (choice == 'b' || choice == 'B') {
						System();
						menu();
						break;
					}
				}
				break;
			}
			break;
		case 4:
			return 0;
			break;
		}
	}
}