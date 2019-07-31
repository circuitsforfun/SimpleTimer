#include <iostream>
#include "SimpleTimer.hpp"

using namespace std;

void task1(const string &out)
{
    cout << out.c_str() << endl;
}

int main() {

    // store the result of a call to std::bind
    //Timer t1(bind(task1, "hello"), 1000);
    //Timer t2(bind(task1, "bye"), 2000);

    // or

    // store a lambda
    std::function<void()> f_task_hello = []() { task1("hello"); };
    std::function<void()> f_task_bye = []() { task1("bye"); };

    Timer t1(f_task_hello, 1000);
    Timer t2(f_task_bye, 2000);

    t1.start();
    t2.start();

    // Do other stuff
    std::this_thread::sleep_for(chrono::seconds(10));

    t1.stop();
    t2.stop();

    return 0;
}