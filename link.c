#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
int data;
struct Node *next;
} Node;
Node *createNode(int value)
{
Node *newNode = malloc(sizeof(Node));
if (newNode == NULL)
{
printf("Memory allocation failed.\n");
return NULL;
}
newNode->data = value;
newNode->next = NULL;
return newNode;
}
void insertEnd(Node **head, int value)
{
Node *newNode = createNode(value);
if (newNode == NULL)
return;
if (*head == NULL)
{
*head = newNode;
return;
}
Node *current = *head;
while (current->next != NULL)
current = current->next;
current->next = newNode;
}
void display(Node *head)
{
Node *current = head;
printf("Linked List: ");
while (current != NULL)
{
printf("%d", current->data);
if (current->next != NULL)
printf(" -> ");
current = current->next;
}
printf(" -> NULL\n");
}
void freeList(Node *head)
{
Node *current;
while (head != NULL)
{
current = head;
head = head->next;
free(current);
}
}
int main(void)
{
Node *head = NULL;
int values[] = {10, 20, 30, 40, 50};
int n = sizeof(values) / sizeof(values[0]);
for (int i = 0; i < n; i++)
insertEnd(&head, values[i]);
display(head);
freeList(head);
return 0;
}