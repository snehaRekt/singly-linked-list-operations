#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
    int value;
    struct Node *next;
};

// Append a node at the end
void appendNode(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    // If list is empty
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert a node at the beginning
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// Display all nodes
void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Delete the first node
void deleteFirst(struct Node **head)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node with a specific key
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If head needs to be deleted
    if (temp != NULL && temp->value == key)
    {
        deleteFirst(head);
        return;
    }

    // Find node with the given key
    while (temp != NULL && temp->value != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("⚠️ Key not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Delete the last node
void deleteLast(struct Node **head)
{
    if (*head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Insert a node at the end (duplicate of appendNode)
void insertAtEnd(struct Node **head, int value)
{
    appendNode(head, value); // reuse appendNode
}

// Delete node at a specific position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("⚠️ Position out of bounds.\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Add a node at a specific position
void AddAtPosition(struct Node **head, int position, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("⚠️ Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Get valid user choice
int getUserChoice()
{
    int choice;
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ; // clear buffer
        printf("⚠️ Invalid input. Please enter a number: ");
    }
    return choice;
}

// Get integer input with prompt
int getIntegerInput(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1)
    {
        while (getchar() != '\n')
            ;
        printf("⚠️ Invalid input. Please enter a number: ");
    }
    return value;
}

// Free all nodes in the list
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Count the number of nodes in the list
int countNodes(struct Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int main()
{
    struct Node *head = NULL;
    int choice, value, pos;

    printf("🔗 Singly Linked List - Menu Driven Program\n");

    while (1)
    {
        // Display menu
        printf("\n========= MENU =========\n");
        printf("1. Append Node\n");
        printf("2. Insert At Beginning\n");
        printf("3. Traverse List\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Insert At End\n");
        printf("7. Delete Node By Value\n");
        printf("8. Delete Node At Position\n");
        printf("9. Add Node At Position\n");
        printf("10. Count Nodes\n");
        printf("11. Exit\n");
        printf("========================\n");

        choice = getUserChoice();

        switch (choice)
        {
        case 1:
            value = getIntegerInput("Enter value to append: ");
            appendNode(&head, value);
            break;
        case 2:
            value = getIntegerInput("Enter value to insert at beginning: ");
            insertAtBeginning(&head, value);
            break;
        case 3:
            traverse(head);
            break;
        case 4:
            deleteFirst(&head);
            break;
        case 5:
            deleteLast(&head);
            break;
        case 6:
            value = getIntegerInput("Enter value to insert at end: ");
            insertAtEnd(&head, value);
            break;
        case 7:
            value = getIntegerInput("Enter value to delete: ");
            deleteNode(&head, value);
            break;
        case 8:
            pos = getIntegerInput("Enter position to delete: ");
            deleteAtPosition(&head, pos);
            break;
        case 9:
            pos = getIntegerInput("Enter position to insert at: ");
            value = getIntegerInput("Enter value to insert: ");
            AddAtPosition(&head, pos, value);
            break;
        case 10:
            printf("✅ Total Nodes: %d\n", countNodes(head));
            break;
        case 11:
            printf("Exiting and freeing memory...\n");
            freeList(head);
            exit(0);
        default:
            printf("⚠️ Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
