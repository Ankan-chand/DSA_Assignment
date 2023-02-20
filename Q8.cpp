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

void josephus(struct node *head, int m)
{
    struct node *prev = NULL, *current = head;

    while (current->next != current)
    {
        int count = 1;
        while (count != m)
        {
            prev = current;
            current = current->next;
            count++;
        }

        prev->next = current->next;
        // cout<<"prev "<<prev->data<<endl;
        // cout<<"current "<<current->data<<endl;
        cout << "deleted " << current->data << endl;
        free(current);
        current = prev->next;
    }

    cout << current->data << endl;
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
    head->next->next->next->next->next->next->next->next->next->next = head;

    int m;
    cin >> m;

    josephus(head, m);
}