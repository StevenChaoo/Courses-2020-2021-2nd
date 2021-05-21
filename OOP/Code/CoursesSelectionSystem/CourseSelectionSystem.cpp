// Author: StevenChaoo
//
#include <iostream>
#include "class.h"
#include "student.h"
using namespace std;
int main() {
	course A;
	student B[10];	// 10个学生
	int stucnt = 0;
	int dengluflag = -1;
	while (1) {
		int SW;
		cout << "欢迎来到选课系统,请选择编号进行操作" << endl;
		cout << "1.注册账号" << endl;
		cout << "2.登陆已有账号" << endl;
		cin >> SW;
		switch (SW) {
			case 1:
				char temp[20];
				cout << "请输入注册学号账号" << endl;
				scanf("%s", temp);
				B[stucnt].setxuehao(temp);
				cout << "请输入登陆验证密码" << endl;
				scanf("%s", temp);
				B[stucnt].setyanz(temp);
				cout << "注册成功,注册信息如下" << endl;
				B[stucnt].checkC();
				stucnt++;
				break;
			case 2:
				char temp1[10];
				cout << "请输入学号账号" << endl;
				scanf("%s", temp);
			go1:
				cout << "请输入登陆验证密码" << endl;
				scanf("%s", temp1);
				for (int i = 0; i < stucnt; i++) {
					if (B[i].xuehaopipei(temp) == true) {
						if (B[i].yanzpipei(temp1) ==
						    true) {
							cout << "登陆成功"
							     << endl;
							dengluflag = i;
						} else {
							cout << "验证密码错误，"
								"重试"
							     << endl;
							goto go1;
						}
					}
				}
				if (dengluflag < 0)
					cout << "学号不存在" << endl;
				break;
			default:
				break;
		}
		if (dengluflag >= 0)
			while (1) {
				system("clean");
				int SW1 = 0;
				cout << "欢迎登陆，请选择功能编号" << endl;
				cout << "1.课程信息录入" << endl;
				cout << "2.课程信息修改" << endl;
				cout << "3.课程信息删除" << endl;
				cout << "4.课程信息浏览" << endl;
				cout << "5.开始选课" << endl;
				cout << "6.选课结果查询" << endl;
				cin >> SW1;
				switch (SW1) {
					char temp[20];
					case 1:
						A.getinf();
						break;
					case 2:
						A.reinf();
						break;
					case 3:
						A.deinf();
						break;
					case 4:
						A.printfc();
						break;
					case 5:
						A.printfc();
						cout << "请输入要选的课程编号"
						     << endl;
						scanf("%s", temp);
						B[dengluflag].choiceC(temp);
						cout << "选课成功" << endl;
						break;
					case 6:
						system("clean");
						int sw = 0;
						cout << "1."
							"按学号查询学生选课情况"
						     << endl;
						cout << "2."
							"按课程查询学生选课情况"
						     << endl;
						cin >> sw;
						switch (sw) {
							case 1:
								cout << "请输入"
									"学号"
								     << endl;
								scanf("%s",
								      temp);
								for (int i = 0;
								     i < stucnt;
								     i++) {
									if (B[i].xuehaopipei(
										temp))
										B[i].checkC();
								}
								break;
							case 2:
								char temp62[20];
								cout << "请输入"
									"查询课"
									"程编号"
								     << endl;
								scanf("%s",
								      temp62);
								cout << "选择此"
									"门课程"
									"的学号"
									"有"
								     << endl;
								for (int i = 0;
								     i < stucnt;
								     i++) {
									for (
									    int j =
										1;
									    j <=
									    B[i].kecnt;
									    j++) {
										char temp1
										    [20];
										B[i].getkc(
										    j,
										    temp1);
										if (strcmp(
											temp1,
											temp62) ==
										    0)
											cout
											    << B[i].xuehao
											    << ",";
									}
								}
								cout << endl;
								break;
						}
						break;
				}
				system("clean");
			}
		system("clean");
	}

	return 0;
}
