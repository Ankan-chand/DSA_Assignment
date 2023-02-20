// Given a singly linked list, write a function to find root(n)th element, where n is the 
// number of elements in the list. Assume value of n is not known in advance. 

#include <iostream>
#include <cmath>
using namespace std;

//structure of the node
struct node
{
    int data;
    struct node *next;
};

//fuction to create a node
struct node *newNode(int data)
{
    struct node *NODE = new struct node;
    NODE -> data = data;
    NODE -> next = NULL;
    
    return NODE;
}

void root_node(struct node *head, int root){
    struct node *temp = head;
    // moving temp to root(n)th element
    for(int i = 1; i < root; i++)
    {
        temp = temp ->next;
    }
    if(temp != NULL)
        cout<<temp -> data<<endl;
}

int main(){
    
    // creating a linkedlist
    struct node *head = newNode(1);
    head -> next = newNode(2);
    head -> next -> next = newNode(3);
    head -> next -> next -> next = newNode(4);
    head -> next -> next -> next -> next = newNode(5);
    head -> next -> next -> next -> next -> next = newNode(6);
    head -> next -> next -> next -> next -> next -> next = newNode(7);
    head -> next -> next -> next -> next -> next -> next -> next = newNode(8);
    head -> next -> next -> next -> next -> next -> next -> next -> next = newNode(9);
    head -> next -> next -> next -> next -> next -> next -> next -> next ->next = newNode(10);

    // counting the number of nodes in the linkedlist
    int count = 0;
    struct node *temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }

    int root = floor(sqrt(count));

    root_node(head, root);

}