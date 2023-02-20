#include<iostream>
#include<queue>
using namespace std;
class Stack {
queue<int> q1, q2;
public:
void pop()
{
if (q1.empty())
return;
// Leave one element in q1 and push others in q2.
while (q1.size() != 1) {
q2.push(q1.front());
q1.pop();
}
// Pop the only left element from q1
q1.pop();
// swap the names of two queues
queue<int> q = q1;
q1 = q2;
q2 = q;
}
void push(int x) { 
q1.push(x); 
q1.push(x); 
}
int top()
{
if (q1.empty())
return -1;
while (q1.size() != 1) {
q2.push(q1.front());
q1.pop();
}
// last pushed element
int temp = q1.front();
// to empty the auxiliary queue after last operation
q1.pop();
// push last element to q2
q2.push(temp);
// swap the two queues names
queue<int> q = q1;
q1 = q2;
q2 = q;
return temp;
}
int size() { 
return q1.size(); 
}
};
// Driver code
int main()
{
Stack s;
s.push(1);
s.push(2);
s.push(3);
cout << "current size of stack : " << s.size() << endl;
cout << "top of stack : " << s.top() << endl;
s.pop();
cout << "top of stack after pop : " << s.top() << endl;
s.pop();
cout << "top of stack after again pop : " << s.top() << endl;
cout << "current size of stack after pop : " << s.size() << endl;
return 0;
}

/*
Time Complexity :
• Push Operation: O(1), as on each operation the new element is added at the end of the queue.
• Pop Operation : O(N). As,on each pop operation ,all the elements are popped out from the queue(q1)
 except the last element and pushed into the queue(q2).
 */