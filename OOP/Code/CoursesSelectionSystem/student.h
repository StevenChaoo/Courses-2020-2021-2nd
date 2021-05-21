class student {
       public:
	char yixuankec[256];
	char yanz[10] = "000000";
	char xuehao[20];
	int kecnt = 0;	//已选课程数目
       public:
	student(char* _xuehao = 0, char* _yanz = 0);
	void choiceC(char* _bianhao);	  //选课功能
	void checkC();			  //查询功能
	void getkc(int cnt, char* temp);  //返回第cnt个课程的编号
	void setyanz(char* _yanz);	  //重新设置验证码
	void setxuehao(char* _xuehao);	  //设置学号
	bool xuehaopipei(char* _xuehao);  //学号是否匹配
	bool yanzpipei(char* _yanz);	  //验证码是否匹配
};

