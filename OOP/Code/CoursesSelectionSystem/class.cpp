#include "class.h"
#include <string.h>
#include <iostream>
using namespace std;

struct kc {
	char bianhao[10];
	char name[20];
	int xueshi;
	int xuefen;
	char kaixueinf[10];
};

course::course() {}
void course::printfc() {
	printf("课程编号，课程名称，课程学时，课程学分，开学时间\n");
	for (int i = 0; i < cnt; i++) {
		printf("%s,%s,%d,%d,%s\n", C.at(i).bianhao, C.at(i).name,
		       C.at(i).xueshi, C.at(i).xuefen, C.at(i).kaixueinf);
	}
}
void course::reinf() {
	char temp[20];
	cout << "请输入课程的编号或者名称" << endl;
	scanf("%s", temp);
	int i = 0;
	for (i = 0; i < cnt; i++) {
		if (strcmp(C.at(i).bianhao, temp) == 0 ||
		    strcmp(C.at(i).name, temp) == 0)
			break;
	}
	printf("查询课程信息为%s,%s,%d,%d,%s\n", C.at(i).bianhao, C.at(i).name,
	       C.at(i).xueshi, C.at(i).xuefen, C.at(i).kaixueinf);
	cout << "请输入修改后的 "
		"课程编号，课程名称，课程学时，课程学分，开学时间（xxxx,x,x）"
	     << endl;
	scanf("%s", C.at(i).bianhao);
	scanf("%s", C.at(i).name);
	scanf("%d", &C.at(i).xueshi);
	scanf("%d", &C.at(i).xuefen);
	scanf("%s", C.at(i).kaixueinf);
	cout << "修改成功" << endl;
}
void course::deinf() {
	char temp[20];
	cout << "请输入课程的编号或者名称" << endl;
	scanf("%s", temp);
	int i = 0;
	for (i = 0; i < cnt; i++) {
		if (strcmp(C.at(i).bianhao, temp) == 0 ||
		    strcmp(C.at(i).name, temp) == 0)
			break;
	}
	printf("删除课程信息为%s,%s,%d,%d,%s\n是否确认删除?是输入1，不是输入0",
	       C.at(i).bianhao, C.at(i).name, C.at(i).xueshi, C.at(i).xuefen,
	       C.at(i).kaixueinf);
	int Isde = 0;
	cin >> Isde;
	if (Isde) {
		C.erase(C.begin() + i);	 //参数为迭代器地址
		cnt--;
		cout << "删除成功" << endl;
	}
}
void course::getinf() {
	int N = 0;
	cout << "请输入要录入的课程数量" << endl;
	cin >> N;
	for (int i = 0; i < N; i++) {
		struct kc a;
		cout << "请输入 "
			"课程编号，课程名称，课程学时，课程学分，开学时间（xxxx"
			".x.x）"
		     << endl;
		scanf("%s", a.bianhao);
		scanf("%s", a.name);
		scanf("%d", &a.xueshi);
		scanf("%d", &a.xuefen);
		scanf("%s", a.kaixueinf);
		// scanf("%s,%s,%d,%s,%d", a.bianhao, a.name, &a.xueshi,
		// a.kaixueinf, &a.xuefen);
		C.push_back(a);
		cnt++;
	}
	cout << "录入完成" << endl;
}
