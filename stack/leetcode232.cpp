#include <stack>
#include <iostream>

using namespace std;

class MyQueue{
public:
    MyQueue(){}
    void push(int x){
        while(!s1.empty()){
            int a = s1.top();
            s1.pop();
            s2.push(a);
        }
        while(!s2.empty()){
            int a = s2.top();
            s2.pop();
            s1.push(a);
        }
        s1.push(x);
    }
    int pop(){
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek(){
        return s1.top();
    }
    bool empty(){
        return s1.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main(){
    MyQueue s;
    s.push(1);
    s.push(2);
    cout << s.peek();
    cout << s.pop();
    cout << s.empty();
    system("pause");
    return 0;
}