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


Node* findTailOfLL(Node* head) {

    Node* temp = head;
    while (temp->next != NULL) {

        temp = temp->next;

    }

    return temp;

}


Node* insertElement(Node* head, int val, int index, int n) {

    if (index > n) {

        return NULL;

    }

    Node* newNode = createNode(val, NULL);

   
    if (index == 0) {

        newNode->next = head;
        return newNode;

    }

    Node* prev = NULL;
    Node* temp = head;
    int cnt = 0;

   
    while (temp != NULL && cnt < index) {

        prev = temp;
        temp = temp->next;
        cnt++;

    }

    if (cnt == index) {

        prev->next = newNode;
        newNode->next = temp;

    }

    return head;

}


void printLL(Node* head) {

    Node* temp = head;

    while (temp != NULL) {

        printf("\n%d ", temp->data);
        temp = temp->next;

    }
    
}

int main() {

    int n, index, val;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 0) {

        printf("Enter valid input\n");
        return 0;

    }

    int* arr = (int*)malloc(sizeof(int) * n);
 
    for (int i = 0; i < n; i++) {

        printf("Enter the value at index %d: ", i);
        scanf("%d", &arr[i]);

    }

    printf("Enter the value of the node to be inserted: ");
    scanf("%d", &val);

    if (n != 0) {

        printf("Enter the index at which it should be inserted: ");
        scanf("%d", &index);

    } 
    
    else {

        index = 0; 

    }

    if (index < 0 || index > n) {

        printf("Enter valid input\n");

    } 
    
    else {

        Node* head = convertArrtoLL(arr, n);
        head = insertElement(head, val, index, n);

        printf("The linked list data is:\n");
        printLL(head);

    }

    free(arr);
    return 0;

}

