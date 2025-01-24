#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {

    int data;
    struct Node* next;

};


struct Node* createNode(int val, struct Node* temp) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp;
    return newNode;

}


struct Node* convertArrtoLL(int arr[], int n) {

    if (n == 0) return NULL;

    struct Node* head = createNode(arr[0], NULL);
    struct Node* temp1 = head;

    for (int i = 1; i < n; i++) {
        struct Node* temp2 = createNode(arr[i], NULL);
        temp1->next = temp2;
        temp1 = temp2;
    }

    return head;

}


struct Node* reverseLL(struct Node* head) {

    if (head == NULL || head->next == NULL) return head;

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        struct Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;

}


struct Node* implementationOfLLUsingQueue(struct Node* head, int n) {

    int* queue = (int*)malloc(sizeof(int) * n);
    int front = -1;

    struct Node* temp1 = head;
    struct Node* temp2 = head;


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


void printLL(struct Node* head) {

    struct Node* temp = head;
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

    struct Node* head = convertArrtoLL(arr, n);

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


