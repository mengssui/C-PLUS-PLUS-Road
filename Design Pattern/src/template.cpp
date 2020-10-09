//模板方法的代码
//统一试题，每个人有不同的答案

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace abouttestpaper {
// 抽象的试卷类
class TestPaper {
	public:
		~TestPaper() { }
		void question1() {
			cout << "Q1: What's your name? " << endl;
			cout << "Myname is " << setName() << endl;
		}

		void question2() {
			cout << "Q2: How old are you? " << endl;
			cout << "I am " << setAge() << " years old! " << endl;
		}

		void question3() {
			cout << "Q3: Where are you from? " <<endl;
			cout << "I come from " << setCountry() << endl;
		}

		void allQuestion() {
			cout << "****** ABOUT PEOPLE " << setName() << " ******"<< endl;
			question1();
			question2();
			question3();
			cout << "**************" << endl;
		}
	protected:
	//定义为虚函数，子类来override
		virtual string setName() = 0;
		virtual string setCountry() = 0;
		virtual int setAge() = 0;
};

//甲的试卷
class TestPaperA : public TestPaper {
	string setName() override {
		return "Jia";
	}
	string setCountry() override {
		return "China";
	}
	int setAge() override {
		return 18;
	}

};
//乙的试卷
class TestPaperB : public TestPaper {
	string setName() override {
		return "Yi";
	}
	string setCountry() override {
		return "US";
	}
	int setAge() override {
		return 21;
	}
};

}

using namespace abouttestpaper;

int main() {

	TestPaper* mypaper = new TestPaperA;
	mypaper -> allQuestion();

	mypaper = new TestPaperB;

	cout << endl;
	mypaper -> allQuestion();
	delete mypaper;
	system("pause");
	return 0;
}