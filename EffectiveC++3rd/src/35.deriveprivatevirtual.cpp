#include <iostream>
using namespace std;

class base {
    public:
        void use() {
            cout << "base"  << endl;
            cout << a << endl;
            pri();
        }
        void change() {
            a = 3;
        }
    private:
        virtual void pri() {
            cout << "hi" << endl;
            cout << a << endl;
        }
        int a = 0;
};

class derived : public base {
;
};


int main() {
    derived d;
    d.use();
    d.change();
    d.use();
    system("pause");
    return 0;
}