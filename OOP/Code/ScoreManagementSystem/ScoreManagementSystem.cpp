// Author:STEVEN
//
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

class Student {
       public:
	int s_id;
	string s_name;
	int s_math_score;
	int s_eng_score;
	int s_ave_score;
};

class System {
       public:
	Student stus[50];
	int mark = 0;
	int math_ave_score = 0;
	int eng_ave_score = 0;

	int inputNumber() {
		cout << "Please input index number: ";
		int number = 0;
		cin >> number;
		cout << endl;
		return number;
	}

	void showMenu() {
		cout << "| Welcome to Score Management System! |" << endl
		     << endl
		     << "1. Add" << endl
		     << "2. Show" << endl
		     << "3. Sort" << endl
		     << "4. Download" << endl
		     << "5. Quit" << endl
		     << endl;
	}

	void addUser() {
		cout << "Please input student's id: ";
		Student stu;
		cin >> stu.s_id;
		cout << "Please input student's name: ";
		cin >> stu.s_name;
		cout << "Please input student's math score: ";
		cin >> stu.s_math_score;
		cout << "Please input student's English score: ";
		cin >> stu.s_eng_score;
		int ave_score = (stu.s_math_score + stu.s_eng_score) / 2;
		stu.s_ave_score = ave_score;
		stus[mark] = stu;
		mark += 1;
		cout << endl << "【Add user successifully!】" << endl << endl;
	}

	void showUser() {
		if (mark == 0) {
			cout << "【No data!】" << endl << endl;
		} else {
			cout << "ID\t\tNAME\t\tMATH\t\tENGLISH\t\tAVERAGE"
			     << endl;
			int math_score = 0;
			int eng_score = 0;
			for (int i = 0; i < mark; i++) {
				math_score += stus[i].s_math_score;
				eng_score += stus[i].s_eng_score;
				cout << stus[i].s_id << "\t" << stus[i].s_name
				     << "\t\t" << stus[i].s_math_score << "\t\t"
				     << stus[i].s_eng_score << "\t\t"
				     << stus[i].s_ave_score << endl;
			}
			cout << endl;
			math_ave_score = math_score / (mark);
			eng_ave_score = eng_score / (mark);
			cout << "Average score of math is: " << math_ave_score
			     << endl;
			cout << "Average score of English is: " << eng_ave_score
			     << endl
			     << endl;
		}
	}

	void download() {
		if (mark == 0) {
			cout << "【No data!】" << endl << endl;
		} else {
			cout << "Where you want to download(Current path with "
				"n): ";
			string dir_path;
			string file_path;
			cin >> dir_path;
			if (dir_path == "n") {
				file_path = "Information.txt";
			} else {
				file_path = dir_path + "Information.txt";
			}
			cout << endl;
			int math_score = 0;
			int eng_score = 0;
			ofstream fout(file_path);
			fout << "ID\t\t\tNAME\t\tMATH\t\tENGLISH\t\tAVERAGE"
			     << endl;
			for (int i = 0; i < mark; i++) {
				math_score += stus[i].s_math_score;
				eng_score += stus[i].s_eng_score;
				fout << stus[i].s_id << "\t" << stus[i].s_name
				     << "\t\t" << stus[i].s_math_score
				     << "\t\t\t" << stus[i].s_eng_score
				     << "\t\t\t" << stus[i].s_ave_score << endl;
			}
			fout << endl;
			math_ave_score = math_score / (mark);
			eng_ave_score = eng_score / (mark);
			fout << "Average score of math is: " << math_ave_score
			     << endl;
			fout << "Average score of English is: " << eng_ave_score
			     << endl
			     << endl;
			fout.close();
			cout << "【Download successifully!】" << endl;
			cout << endl;
		}
	}

	static bool idCmpare(const Student& a, const Student& b) {
		return a.s_id < b.s_id;
	}
	static bool nameCmpare(const Student& a, const Student& b) {
		return a.s_name < b.s_name;
	}
	static bool mathCmpare(const Student& a, const Student& b) {
		return a.s_math_score < b.s_math_score;
	}
	static bool engCmpare(const Student& a, const Student& b) {
		return a.s_eng_score < b.s_eng_score;
	}
	static bool aveCmpare(const Student& a, const Student& b) {
		return a.s_ave_score < b.s_ave_score;
	}

	void sortView() {
		if (mark == 0) {
			cout << "【No data!】" << endl << endl;
		} else {
			cout << "1. ID" << endl
			     << "2. NAME" << endl
			     << "3. MATH" << endl
			     << "4. ENGLISH" << endl
			     << "5. AVERAGE" << endl
			     << endl;
			cout << "Soring by: ";
			int number = 0;
			cin >> number;
			cout << endl;
			if (number == 1) {
				sort(stus, stus + mark, idCmpare);
			} else if (number == 2) {
				sort(stus, stus + mark, nameCmpare);
			} else if (number == 3) {
				sort(stus, stus + mark, mathCmpare);
			} else if (number == 4) {
				sort(stus, stus + mark, engCmpare);
			} else if (number == 5) {
				sort(stus, stus + mark, aveCmpare);
			}
			cout << "ID\t\tNAME\t\tMATH\t\tENGLISH\t\tAVERAGE"
			     << endl;
			for (int i = 0; i < mark; i++) {
				cout << stus[i].s_id << "\t" << stus[i].s_name
				     << "\t\t" << stus[i].s_math_score << "\t\t"
				     << stus[i].s_eng_score << "\t\t"
				     << stus[i].s_ave_score << endl;
			}
			cout << endl;
			cout << "【Sort successifully!】" << endl << endl;
		}
	}
};

int main() {
	cout << endl;

	System sys;
	sys.showMenu();
	while (true) {
		int num = sys.inputNumber();
		if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) {
			cout << "【Wrong input!】" << endl << endl;
		} else {
			switch (num) {
				case 1:
					sys.addUser();
					break;
				case 2:
					sys.showUser();
					break;
				case 3:
					sys.sortView();
					break;
				case 4:
					sys.download();
					break;
				case 5:
					break;
			}
			if (num == 5) {
				cout << "【Thanks Using!】" << endl;
				break;
			}
		}
	}

	cout << endl;
	return 0;
}
