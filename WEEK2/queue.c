#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


Node* implementationOfLLUsingQueue(Node* head, int n) {

    int* queue = (int*)malloc(sizeof(int) * n);
    int front = -1;

    Node* temp1 = head;
    Node* temp2 = head;


    while (temp1 != NULL) {
        queue[++front] = temp1->data;
        temp1 = temp1->next;
    }

    front = 0;
    
    while (front >= 0 && temp2 != NULL) {
        temp2->data = queue[front++];
        temp2 = temp2->next;
    }

    free(queue);
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
    clock_t start, end;
    double cpu_time_used;

    start = clock();
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

    head = implementationOfLLUsingQueue(head, n);
    printf("The linked list after using queue is: ");
    printLL(head);
    printf("The front element of the linked list is: %d", head->data);
    
    end = clock();
    cpu_time_used = (double)(end - start)/CLOCKS_PER_SEC;

    printf("\nThe time taken by cpu is : %f seconds", cpu_time_used);

    free(arr);

    return 0;

}


