#include<iostream>
using namespace std;

void check_palindrom(string myStr){

    int start = 0;
    int end = myStr.size() - 1;

    while(start<end && myStr[start] == myStr[end])
    {
        start++;
        end--;
    }

    if(myStr[start] == myStr[end])
        cout<<"Palindrom"<<endl;
    else
        cout<<"Not Palindrom"<<endl;
}

int main(){
    string myStr = "abXba";
    
    check_palindrom(myStr);
    
}