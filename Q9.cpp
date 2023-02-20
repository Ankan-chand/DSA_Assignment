// For a given k value (k>0) reverse blocks of nodes in the list

#include <iostream>
using namespace std;

// structure of the node
struct node
{
    int data;
    struct node *next;
};

// fuction to create a node
struct node *newNode(int data)
{
    struct node *NODE = new struct node;
    NODE->data = data;
    NODE->next = NULL;

    return NODE;
}

// function for reverse k blocks
struct node *reverseByk(struct node *head, int k, int length)
{
    // base case
    if (head == NULL)
        return NULL;
    else if( k > length)
        return head;

    struct node *prenode = NULL, *currentnode = head, *nextnode = head;

    int count = 0;

    while (count < k && currentnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prenode;
        prenode = currentnode;
        currentnode = nextnode;
        count++;
    }
    length = length - k;
    struct node *revhead = reverseByk(nextnode, k, length);
    head->next = revhead;

    return prenode;
}

int main()
{
    // creating a linkedlist
    struct node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);
    head->next->next->next->next->next->next->next->next = newNode(9);
    head->next->next->next->next->next->next->next->next->next = newNode(10);
    head->next->next->next->next->next->next->next->next->next->next = newNode(11);

    int k, count = 0;
    cin >> k;

    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;

    // passing head, k and length of the node
    head = reverseByk(head, k, count);

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}