#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// clears screen for both mac and windows.
void system_clear() {
	if (system("CLS")) system("clear");
}

// menu function displays initial menu when called. returns nothing so type void is
// used.
void main_menu() {
	cout << "Skill & Progress Tracker" << endl;
	cout << endl << "Choose 1 of the following: \n\n";
	cout << "1. To-do\n2. Repeat\n3. Done\n" << endl;
}

// loops, sets the seek pointer of "file" to the beginning of line "num"
fstream& GotoLine(fstream& file, unsigned int num) {
	file.seekg(ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

void self_evaluate() {
	double score1, score2, score3, score4, score_total;

	cout << "Self Score Evaluation\n\n";
	cout << "Rate your performance on a scale of 1-5 based on the following questions:\n\n";
	cout << "1 - Below Expectations 2 - Needs Improvement 3 - Meets Expectations\n4 - Exceeds Expectations 5 - Spectacular Performance\n\n";
	cout << "1. I was able to complete the task without hints (1-5): ";
	cin >> score1;
	cout << "2. I was able to finish the task within 30 minutes (1-5): ";
	cin >> score2;
	cout << "3. The solution to the task was clean, efficient, and optimal (1-5): ";
	cin >> score3;
	cout << "4. There were no bugs or errors (1-5): ";
	cin >> score4;

	score_total = (score1 + score2 + score3 + score4) / 4.0;
	cout << "\n\nYour final score for this problem is " << score_total << " -> " << round(score_total) << "\n\n";
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
	case 4:
		ifstream file4("temp.txt");
		while (getline(file4, line)) {
			i++;
		}
		file4.close();
		break;
	}
	i = i - 2;
	return i;
}

// c = choice, s = score, and q = question number.
void move_feature(int c, int s, int q) {
	if (c == 1) {
		if (s == 3 || s == 4) {
			ofstream of("repeat.txt", ios_base::app);
			ofstream temp("temp.txt");
			string line;
			ifstream inf("todo.txt");
			int count = 0;

			while (getline(inf, line)) {
				if (count == q - 1) {
					of << left << setw(5) << line_number(2, 1) << line.substr(5, line.size()) << endl;
					cout << "\nThis question has been moved to Repeat\n" << endl;
				}
				else {
					if (!line_number(2, 1) || !line_number(2, 2)) {
						temp << left << setw(5) << line_number(2, 1) << line.substr(5, line.size()) << endl;
					}
					else {
						temp << line << endl;
					}
				}

				for (int j = 3; !temp.eof(); j++) {
					fstream file("temp.txt");
					GotoLine(file, j);
					string num;
					file >> num;
					double pos = file.tellp();
					file.seekp(pos - 1);
					if (num != "") {
						file << j - 2;
					}
					else {
						break;
					}
					file.close();
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
					of << left << setw(5) << line_number(3, 1) << line.substr(5, line.size()) << endl;
					cout << "\nThis question has been moved to Done\n" << endl;
				}
				else {
					temp << line << endl;
				}
				count++;
			}

			for (int j = 3; !temp.eof(); j++) {
				fstream file("temp.txt");
				GotoLine(file, j);
				string num;
				file >> num;
				double pos = file.tellp();
				file.seekp(pos - 1);
				if (num != "") {
					file << j - 2;
				}
				else {
					break;
				}
				file.close();
			}
			inf.close();
			of.close();
			temp.close();
		}
		remove("todo.txt");
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
					of << left << setw(5) << line_number(1, 1) << line.substr(5, line.size()) << endl;
					cout << "\nThis question has been moved to To-do\n" << endl;
				}
				else {
					if (!line_number(1, 1) || !line_number(1, 2)) {
						temp << left << setw(5) << line_number(1, 1) << line.substr(5, line.size()) << endl;
					}
					else {
						temp << line << endl;
					}
				}
				count++;
			}

			for (int j = 3; !temp.eof(); j++) {
				fstream file("temp.txt");
				GotoLine(file, j);
				string num;
				file >> num;
				double pos = file.tellp();
				file.seekp(pos - 1);

				if (num != "") {
					file << j - 2;
				}
				else {
					break;
				}
				file.close();
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
					of << left << setw(5) << line_number(3, 1) << line.substr(5, line.size()) << endl;
					cout << "\nThis question has been moved to Done\n" << endl;
				}
				else {
					if (!line_number(3, 1) || !line_number(3, 2)) {
						temp << left << setw(5) << line_number(3, 1) << line.substr(5, line.size()) << endl;
					}
					else {
						temp << line << endl;
					}
				}
				count++;
			}

			for (int j = 3; !temp.eof(); j++) {
				fstream file("temp.txt");
				GotoLine(file, j);
				string num;
				file >> num;
				double pos = file.tellp();
				file.seekp(pos - 1);

				if (num != "") {
					file << j - 2;
				}
				else {
					break;
				}
				file.close();
			}
			inf.close();
			of.close();
			temp.close();
		}
		remove("repeat.txt");
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
					of << left << setw(5) << line_number(1, 1) << line.substr(5, line.size()) << endl;
					cout << "\nThis question has been moved to To-do\n" << endl;
				}
				else {
					if (!line_number(1, 1) || !line_number(1, 2)) {
						temp << left << setw(5) << line_number(1, 1) << line.substr(5, line.size()) << endl;
					}
					else {
						temp << line << endl;
					}
				}
				count++;
			}

			for (int j = 3; !temp.eof(); j++) {
				fstream file("temp.txt");
				GotoLine(file, j);
				string num;
				file >> num;
				double pos = file.tellp();
				file.seekp(pos - 1);

				if (num != "") {
					file << j - 2;
				}
				else {
					break;
				}
				file.close();
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
					of << left << setw(5) << line_number(2, 1) << line.substr(5, line.size()) << endl;
					cout << "\nThis question has been moved to Repeat\n" << endl;
				}
				else {
					if (!line_number(2, 1) || !line_number(2, 2)) {
						temp << left << setw(5) << line_number(2, 1) << line.substr(5, line.size()) << endl;
					}
					else {
						temp << line << endl;
					}
				}
				count++;
			}

			for (int j = 3; !temp.eof(); j++) {
				fstream file("temp.txt");
				GotoLine(file, j);
				string num;
				file >> num;
				double pos = file.tellp();
				file.seekp(pos - 1);

				if (num != "") {
					file << j - 2;
				}
				else {
					break;
				}
				file.close();
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

void delete_feature(int c, int q) {
	if (c == 1) {
		ofstream temp("temp.txt");
		string line;
		ifstream inf("todo.txt");
		int count = 0;

		while (getline(inf, line)) {
			if (count == q - 1) {
				NULL;
			}
			else {
				if (!line_number(1, 1) || !line_number(1, 2)) {
					temp << left << setw(5) << line_number(1, 1) << line.substr(5, line.size()) << endl;
				}
				else {
					temp << line << endl;
				}
			}

			for (int j = 3; !temp.eof(); j++) {
				fstream file("temp.txt");
				GotoLine(file, j);
				string num;
				file >> num;
				double pos = file.tellp();
				file.seekp(pos - 1);

				if (num != "") {
					file << j - 2;
				}
				else {
					break;
				}
				file.close();
			}
			count++;
		}
		inf.close();
		temp.close();

		remove("todo.txt");
		int result;
		result = rename("temp.txt", "todo.txt");

		if (result == 0)
			NULL;
		else
			perror("\nInternal error: data transfer unsucsessful");
		cout << "This question has been deleted.\n\n";
		system("pause");
	}
	else if (c == 2) {
		ofstream temp("temp.txt");
		string line;
		ifstream inf("repeat.txt");
		int count = 0;

		while (getline(inf, line)) {
			if (count == q - 1) {
				NULL;
			}
			else {
				if (!line_number(2, 1) || !line_number(2, 2)) {
					temp << left << setw(5) << line_number(2, 1) << line.substr(5, line.size()) << endl;
				}
				else {
					temp << line << endl;
				}
			}

			for (int j = 3; !temp.eof(); j++) {
				fstream file("temp.txt");
				GotoLine(file, j);
				string num;
				file >> num;
				double pos = file.tellp();
				file.seekp(pos - 1);

				if (num != "") {
					file << j - 2;
				}
				else {
					break;
				}
				file.close();
			}
			count++;
		}
		inf.close();
		temp.close();

		remove("repeat.txt");
		int result;
		result = rename("temp.txt", "repeat.txt");

		if (result == 0)
			NULL;
		else
			perror("\nInternal error: data transfer unsucsessful");
		cout << "This question has been deleted.\n\n";
		system("pause");
	}
	else if (c == 3) {
	ofstream temp("temp.txt");
	string line;
	ifstream inf("done.txt");
	int count = 0;

	while (getline(inf, line)) {
		if (count == q - 1) {
			NULL;
		}
		else {
			if (!line_number(3, 1) || !line_number(3, 2)) {
				temp << left << setw(5) << line_number(3, 1) << line.substr(5, line.size()) << endl;
			}
			else {
				temp << line << endl;
			}
		}

		for (int j = 3; !temp.eof(); j++) {
			fstream file("temp.txt");
			GotoLine(file, j);
			string num;
			file >> num;
			double pos = file.tellp();
			file.seekp(pos - 1);

			if (num != "") {
				file << j - 2;
			}
			else {
				break;
			}
			file.close();
		}
		count++;
	}
	inf.close();
	temp.close();

	remove("done.txt");
	int result;
	result = rename("temp.txt", "done.txt");

	if (result == 0)
		NULL;
	else
		perror("\nInternal error: data transfer unsucsessful");
	cout << "This question has been deleted.\n\n";
	system("pause");
	}
}