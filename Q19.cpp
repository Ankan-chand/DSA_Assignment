#include<iostream> 
#include<queue> 
#include<stack>
using namespace std;

void reverseKElements(queue<int> &queue, int k) {
    if (k < 0 || k >= queue.size() || queue.empty()) {
        cout<<"Invalid Input"<<endl;
        return;
    }
    
    int n = queue.size();
    
    // remove first k elements of queue and push in stack
    stack<int> st;
    for (int i = 0; i < k; i++) {
        int curr = queue.front();
        queue.pop();
        st.push(curr);
    }
    
    // Pop out elements from stack and add to the end of the queue
    for (int i = 0; i < k; i++) {
        int curr = st.top();
        st.pop();
        queue.push(curr);
    }
    
    // Remove first (n - k) elements of the queue and add them to the end
    for (int i = 0; i < n - k; i++) {
        int curr = queue.front();
        queue.pop();
        queue.push(curr);
    }
    
    // Print the elements of the queue
    for (int i = 0; i < n; i++) {
        int curr = queue.front();
        queue.pop();
        cout<<curr<<" ";
        queue.push(curr);
    }
    cout<<endl;
}
int main() {
    // Example 1
    queue<int> q1;
    int k1 = 3;
    q1.push(10);
    q1.push(15);
    q1.push(31);
    q1.push(17);
    q1.push(12);
    q1.push(19);
    q1.push(2);
    reverseKElements(q1, k1);
}