// Q. Check whether the given linked list is either NULL-terminated or ends in cycle(cyclic).


#include<iostream>
using namespace std;

//structure of a node

struct node
{
    int data;
    struct node *next;
};

//function to create a node

struct node *newNode(int data)
{
    struct node *NODE = new struct node;
    NODE -> data = data;
    NODE -> next = NULL;

    return NODE;
}


/*This function takes head pointer as a input and return type is boolean.
  It returns true if the linkedlist is cyclic otherwise false */

bool checkCyclic(struct node *head)
{
    //if the linkedlist is empty then it is also a circular linkedlist
    if(head == NULL)
        return true;
    
    //for traversing the linklist
    struct node *temp;

    //next node of head
    temp = head -> next;
    
    //loop will terminated if the linkedlist is circular or it is null ended
    while (temp != NULL && temp != head)
    {
        temp = temp -> next;
    }

    //to check the reason of termination of the loop
    bool resn = temp == head;
    
    return resn;
}

int main()
{
    //for null linkedlist
    struct node *head = NULL;

    //for NULL terminated linkedlist
    head = newNode(5);
    head -> next = newNode(8);
    head -> next ->next = newNode(6);
    head -> next ->next -> next = newNode(14);

    //for circular linkedlist
    head -> next ->next -> next = head;


    bool check = checkCyclic(head);

    if(check)
        cout<<"This is a cyclic linkedlist"<<endl;
    
    else
        cout<<"The linkedlist is NULL terminated"<<endl;

    return 0;
}


// Time complexity -> O(n)
