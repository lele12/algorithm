#include <queue>
#include <iostream>

using namespace std;

class MyStack{
public:
    MyStack(){}
    void push(int x){
        while(!q1.empty()){
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1.push(x);
        while(!q2.empty()){
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
    }
    int pop(){
        int x = q1.front();
        q1.pop();
        return x;
    }
    int top(){
        return q1.front();
    }
    bool empty(){
        return q1.empty();
    }
    private:
    queue<int> q1;
    queue<int> q2;
};

int main(){
    MyStack s;

    system("pause");
    return 0;
}