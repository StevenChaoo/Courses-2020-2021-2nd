#include "student.h"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

student::student(char* _xuehao, char* _yanz) {
	kecnt = 0;
	yixuankec[0] = 0;
	if (_xuehao != NULL)
		strcpy(xuehao, _xuehao);
	if (_yanz != NULL)
		strcpy(yanz, _yanz);
}

void student::choiceC(char* _bianhao)  //选课功能
{
	int i = 0;
	for (i = 0; i < 256; i++) {
		if (yixuankec[i] == 0) {
			if (kecnt != 0) {
				yixuankec[i] = ',';
				i++;
			}
			break;
		}
	}
	strcpy(yixuankec + i, _bianhao);  //此处没有判断i是否越界
	kecnt++;
}
void student::checkC()	//查询功能
{
	printf("学号：%s\n", xuehao);
	printf("登陆验证：%s\n", yanz);
	printf("已选课程编号：%s\n", yixuankec);
}
void student::getkc(int cnt, char* temp) {
	char temp1[10];
	int c = 0;
	for (int i = 0, j = 0; i < 256; i++) {
		if (yixuankec[i] != 0 && yixuankec[i] != ',') {
			temp1[j] = yixuankec[i];
			j++;
		} else	// yixuankec[i] == ',' \0
		{
			c++;
			temp1[j] = 0;
			if (c == cnt) {
				strcpy(temp, temp1);
				return;
			}
			j = 0;
		}
	}
}

void student::setyanz(char* _yanz)  //重新设置验证码
{
	strcpy(yanz, _yanz);
	// cout << "设置成功" << endl;
}
void student::setxuehao(char* _xuehao)	//设置学号
{
	strcpy(xuehao, _xuehao);
	// cout << "申请成功" << endl;
}

bool student::xuehaopipei(char* _xuehao)  //学号是否匹配
{
	if (strcmp(xuehao, _xuehao) == 0)
		return true;
	else
		return false;
}
bool student::yanzpipei(char* _yanz)  //验证码是否匹配
{
	if (strcmp(yanz, _yanz) == 0)
		return true;
	else
		return false;
}
