#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insert(struct node *head, int value)
{
    struct node *t1, *temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    else
    {
        t1 = head;
        while (t1->next != NULL)
        {
            t1 = t1->next;
        }
        temp->data = value;
        temp->next = t1->next;
        t1->next = temp;
    }
    return head;
}
struct node *merge(struct node *head1, struct node *head2)
{
    struct node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
        temp->next = head2;
    return head1;
}
struct node *sort(struct node *head1)
{
    struct node *t1, *temp = head1;
    int count = 0;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    for (int i = count; i > 0; i--)
    {
        temp = head1;
        for (int j = 0; j < count; j++)
        {
            if (temp->next == NULL)
                break;
            if (temp->data > temp->next->data)
            {
                t1 = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t1;
            }
            temp = temp->next;
        }
    }

    return head1;
}
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int val, choice;
    while (1)
    {
        printf("enter choice\n 1.insert of first linked list\n 2.insert of second linked list\n 3.printing both the linked list\n 4.merge\n 5.sort\n 6.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("enter the value  to insert in head1:\n");
            scanf("%d", &val);
            head1 = insert(head1, val);
            display(head1);
            printf("\n");
            break;
        case 2:
            printf("enter the value  to insert in head2:\n");
            scanf("%d", &val);
            head2 = insert(head2, val);
            display(head2);
            printf("\n");
            break;
        case 3:
            printf("The linked list 1 is:\n");
            display(head1);
            printf("\n");
            printf("The linked list 2 is:\n");
            display(head2);
            printf("\n");
            break;
        case 4:
            printf("The merged linked list is:\n");
            head1 = merge(head1, head2);
            display(head1);
            printf("\n");
            break;
        case 5:
            printf("The sorted linked list is:\n");
            head1 = sort(head1);
            display(head1);
            printf("\n");
            break;
        case 6:
            return 0;
        }
    }
}