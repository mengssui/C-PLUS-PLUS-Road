/*
 * @Descripttion: 
 * @version: 0.1
 * @Author: Mengbw
 * @Date: 2021-08-05 19:38:27
 * @LastEditors: Mengbw
 * @LastEditTime: 2021-08-05 19:46:39
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdint>

using namespace std;
#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
		cout << "Base ctor ";
       Function();
    }

    virtual void Function()
    {
        cout << "Base::Fuction" << endl;
    }
    virtual ~Base()
    {
		cout << "Base dtor";
        Function();
    }
};

class A : public Base
{
public:
    A()
    {
		cout << "A ctor ";
      Function();
    }

    virtual void Function()
    {
        cout << "A::Function" << endl;
    }
    ~A()
    {
		cout << "A dtor";
        Function();
    }
};

int main()
{
    Base* a = new Base;
    delete a;
    cout << "-------------------------" <<endl;
    Base* b = new A;//语句1
    delete b;
}
//输出结果
//Base::Fuction
//Base::Fuction
//-------------------------
//Base::Fuction
//A::Function
//Base::Fuction

