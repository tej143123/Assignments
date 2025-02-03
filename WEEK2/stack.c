#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    
    int data;
    struct Node* next;
    
} Node;


Node* createNode(int val, Node* temp) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = temp;
    return newNode;
    
}


Node* convertArrtoLL(int arr[], int n) {
    
    if (n == 0) return NULL;

    Node* head = createNode(arr[0], NULL);
    Node* temp1 = head;

    for (int i = 1; i < n; i++) {
        Node* temp2 = createNode(arr[i], NULL);
        temp1->next = temp2;
        temp1 = temp2;
    }

    return head;
    
}


Node* reverseLL(Node* head) {
    
    if (head == NULL || head->next == NULL) return head;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
    
}


Node* implementationOfLLUsingStack(Node* head, int n) {
    
    int* stack = (int*)malloc(sizeof(int) * n);  
    int top = -1;  

    Node* temp1 = head;
    Node* temp2 = head;

    
    while (temp1 != NULL) {
        stack[++top] = temp1->data;
        temp1 = temp1->next;
    }

    
    while (top >= 0 && temp2 != NULL) {
        temp2->data = stack[top--];
        temp2 = temp2->next;
    }

    free(stack);  
    return head;
    
}


void printLL(Node* head) {
    
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}


int main() {
    
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size for the array.\n");
        return 0;
    }

    int* arr = (int*)malloc(sizeof(int) * n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the value of arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    Node* head = convertArrtoLL(arr, n);

    printf("The original linked list is: ");
    printLL(head);

    head = implementationOfLLUsingStack(head, n);
    printf("The linked list after using stack is: ");
    printLL(head);
    printf("The top element of the linked list is: %d", head->data);

    head = reverseLL(head);
    printf("\nThe linked list after reversing is: ");
    printLL(head);
    printf("The top element of the linked list is: %d", head->data);


    free(arr);  

    return 0;
    
}

