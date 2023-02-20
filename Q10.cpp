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

int mergingNode(struct node *head1, struct node *head2, int c1, int c2)
{

    int dif, len;
    if (c1 > c2)
    {
        dif = c1 - c2;
        len = c1;
    }
    else
    {
        dif = c2 - c1;
        len = c2;
    }

    struct node *temp1 = head1;
    struct node *temp2 = head2;
    int count = 1;
    for (int i = 1; i < len; i++)
    {
        if (count > dif)
        {
            if (temp1->data == temp2->data)
                return temp1->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            temp1 = temp1->next;
        }
        count++;
    }
}

int main()
{
    // list1
    struct node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    head1->next->next->next->next->next->next->next->next = newNode(9);
    head1->next->next->next->next->next->next->next->next->next = newNode(10);

    // list2
    struct node *head2 = newNode(6);
    head2->next = newNode(7);
    head2->next->next = newNode(8);
    head2->next->next->next = newNode(9);
    head2->next->next->next->next = newNode(10);

    // length of list1
    struct node *temp = head1;
    int c1 = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c1++;
    }

    // length of list2
    temp = head2;
    int c2 = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c2++;
    }

    int myNode = mergingNode(head1, head2, c1, c2);
    cout << myNode << endl;
}