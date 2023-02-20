// ven a list, List1={A1,A2,A3,……..An-1, An} with data, reorder it to {A1, An, A2, An-1, …..} without using any extra space.

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

// function for reorder the list
void reorder(struct node *head)
{
    struct node *prev = head;
    struct node *current = head->next;
    struct node *temp = current;

    while (current->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp->next->next = current;
        prev->next = temp->next;
        temp->next = NULL;
        prev = current;
        current = current->next;
        temp = current;
    }
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

    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    reorder(head);
    
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}