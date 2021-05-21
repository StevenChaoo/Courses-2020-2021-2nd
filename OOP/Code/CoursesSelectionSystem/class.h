#include <vector>

class course {
       public:
	int cnt = 0;  //已添加课程数量
	std::vector<struct kc> C;

       public:
	course();
	void printfc();
	void reinf();
	void deinf();
	void getinf();
};
