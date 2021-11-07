#include "main.h"

int main() {
	main_menu();

	while (true) {
		int bucket_choice;
		int question_num;
		int line_num = 1;
		char tab_choice;
		ifstream fileIn;
		ofstream fileOut;

		//loops main_menu in case user's input is invalid.
		while (true) {
			cout << "Enter choice: ";
			cin >> bucket_choice;

			if (bucket_choice == 1 || bucket_choice == 2 || bucket_choice == 3) {
				break;
			}
			else {
				cout << "\nInvalid input, please try again.\n\n";
				system("pause");
				system_clear();
				main_menu();
			}
		}

		// switch statement to identify user choice and proceeds with actions accordingly.
		switch (bucket_choice) {
		case 1:
			while (true) {
				system_clear();
				cout << "Questions To-do\n\n";
				cout << "(A)dd Question\n";
				cout << "(S)core Question\n";
				cout << "(D)elete Question\n";
				cout << "(B)ack\n\n";
				
				fstream file("todo.txt");
				GotoLine(file, 3);
				string line3;
				file >> line3;

				if (line3 == "") {
					cout << "There are no questions to display.\n\n";
				}
				else cout << ifstream("todo.txt").rdbuf() << "\n\n";

				file.close();
				cout << ": ";
				cin >> tab_choice;

				if (tab_choice == 'a' || tab_choice == 'A') {
					system_clear();
					while (true) {
						char yes_no;
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
						fileOut << left << setw(5) << line_number(bucket_choice, line_num) << setw(20) << name_of_q << setw(20) << name_of_ds << setw(20) << difficulty << setw(20) << '?' << endl;
						fileOut.close();

						cout << "\n\nQuestion saved.\n\n";
						cout << "Add another? (Y/N): ";
						cin >> yes_no;

						if (yes_no == 'y' || yes_no == 'Y') {
							system_clear();
							NULL;
						}
						else if (yes_no == 'n' || yes_no == 'N') {
							break;
						}
					}
				}
				else if (tab_choice == 's' || tab_choice == 'S') {
					int score = 679936354;
					while (true) {
						fstream file("todo.txt");
						GotoLine(file, 3);
						string line3;
						file >> line3;

						if (line3 == "") {
							system_clear();
							cout << "There are no questions to score.\n\n";
							system("pause");
							break;
						}
						else {
							cout << "\nWhich question do you want to score?\n\n";
							cout << "Question #: ";
							cin >> question_num;
							question_num = question_num + 2;
							system_clear();

							self_evaluate();

							cout << "Set Score for question " << question_num - 2 << ": ";
							cin >> score;

							fstream file("todo.txt");
							GotoLine(file, question_num);
							double pos = file.tellp();
							file.seekp(pos + 65);
							file << score;
							file.close();
							break;
						}
						file.close();
					}
					if (score == 1 || score == 2) {
						cout << "This question has stayed in To-do" << endl;

					}
					else if (score == 3 || score == 4 || score == 5) {
						move_feature(bucket_choice, score, question_num);
					}
					else if (score == 679936354) {
						NULL;
					}
				}
				else if (tab_choice == 'd' || tab_choice == 'D') {
					while (true) {
						fstream file("todo.txt");
						GotoLine(file, 3);
						string line3;
						file >> line3;

						if (line3 == "") {
							system_clear();
							cout << "There are no questions to delete.\n\n";
							system("pause");
							break;
						}
						else {
							cout << "\nWhich question do you want to delete?\n\n";
							cout << "Question #: ";
							cin >> question_num;
							question_num = question_num + 2;
							system_clear();
						}
						system_clear();
						file.close();
						delete_feature(bucket_choice, question_num);
						break;
					}
				}
				else if (tab_choice == 'b' || tab_choice == 'B') {
					system_clear();
					main_menu();
					break;
				}
			}
			break;
		case 2:
			while (true) {
				while (true) {
					system_clear();
					cout << "Questions that Require Re-Clarification\n\n";
					cout << "(R)e-Evaluate\n";
					cout << "(M)ove to\n";
					cout << "(D)elete Question\n";
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
					cin >> tab_choice;

					if (tab_choice == 'r' || tab_choice == 'R') {
						int score = 679936354;
						while (true) {
							fstream file("repeat.txt");
							GotoLine(file, 3);
							string line3;
							file >> line3;

							if (line3 == "") {
								system_clear();
								cout << "There are no questions to re-score.\n\n";
								system("pause");
								break;
							}
							else {
								cout << "\nWhich question do you want to re-score?\n\n";
								cout << "Question #: ";
								cin >> question_num;
								question_num = question_num + 2;
								system_clear();

								self_evaluate();

								cout << "Set Score for question " << question_num - 2 << ": ";
								cin >> score;

								fstream file("repeat.txt");
								GotoLine(file, question_num);
								double pos = file.tellp();
								file.seekp(pos + 65);
								file << score;
								file.close();
								break;
							}
						}
						if (score == 679936354) {
							NULL;
						}
						else {
							move_feature(bucket_choice, score, question_num);
						}
					}
					break;
				}
				if (tab_choice == 'm' || tab_choice == 'M') {
					int score = 679936354;
					while (true) {
						fstream file("repeat.txt");
						GotoLine(file, 3);
						string line3;
						file >> line3;

						if (line3 == "") {
							system_clear();
							cout << "There are no questions to move.\n\n";
							system("pause");
							break;
						}
						else {
							cout << "\nWhich question do you want to move?\n\n";
							cout << "Question #: ";
							cin >> question_num;
							question_num = question_num + 2;
							system_clear();

							while (true) {
								cout << "Where do you want to move question " << question_num << " to?\n\n";
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
							system_clear();
						}
						file.close();
					}
					if (score == 679936354) {
						NULL;
					}
					else {
						move_feature(bucket_choice, score, question_num);
					}
				}
				else if (tab_choice == 'd' || tab_choice == 'D') {
					while (true) {
						fstream file("repeat.txt");
						GotoLine(file, 3);
						string line3;
						file >> line3;

						if (line3 == "") {
							system_clear();
							cout << "There are no questions to delete.\n\n";
							system("pause");
							break;
						}
						else {
							cout << "\nWhich question do you want to delete?\n\n";
							cout << "Question #: ";
							cin >> question_num;
							question_num = question_num + 2;
							system_clear();
						}
						system_clear();
						file.close();
						delete_feature(bucket_choice, question_num);
						break;
					}
				}
				else if (tab_choice == 'b' || tab_choice == 'B') {
					system_clear();
					main_menu();
					break;
				}
			}
			break;
		case 3:
			while (true) {
				while (true) {
					system_clear();
					cout << "Questions that I've Nailed\n\n";
					cout << "(M)ove to\n";
					cout << "(D)elete Question\n";
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
					cin >> tab_choice;

					if (tab_choice == 'm' || tab_choice == 'M') {
						int score = 679936354;
						while (true) {
							fstream file("done.txt");
							GotoLine(file, 3);
							string line3;
							file >> line3;

							if (line3 == "") {
								system_clear();
								cout << "There are no questions to move.\n\n";
								system("pause");
								break;
							}
							else {
								cout << "\nWhich question do you want to move?\n\n";
								cout << "Question #: ";
								cin >> question_num;
								question_num = question_num + 2;
								system_clear();

								while (true) {
									cout << "Where do you want to move question " << question_num << " to?\n\n";
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
								system_clear();
							}
							file.close();
						}
						if (score == 679936354) {
							NULL;
						}
						else {
							move_feature(bucket_choice, score, question_num);
						}
					}
					else if (tab_choice == 'd' || tab_choice == 'D') {
						while (true) {
							fstream file("done.txt");
							GotoLine(file, 3);
							string line3;
							file >> line3;

							if (line3 == "") {
								system_clear();
								cout << "There are no questions to delete.\n\n";
								system("pause");
								break;
							}
							else {
								cout << "\nWhich question do you want to delete?\n\n";
								cout << "Question #: ";
								cin >> question_num;
								question_num = question_num + 2;
								system_clear();
							}
							system_clear();
							file.close();
							delete_feature(bucket_choice, question_num);
							break;
						}
					}
					else if (tab_choice == 'b' || tab_choice == 'B') {
						system_clear();
						main_menu();
						break;
					}
				}
				break;
			}
			break;
		}
	}
}