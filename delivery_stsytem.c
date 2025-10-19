#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for the delivery point
typedef struct {
    char address[50];
    float distance;
} Delivery;

struct deliveryNode{
    Delivery data;
    struct deliveryNode *nextPtr;
}; 
typedef struct deliveryNode DeliveryNode;

// struct for pointers (front and back)
typedef struct {
    DeliveryNode *frontPtr;
    DeliveryNode *backPtr;
} DeliveryList;

// function prototypes
DeliveryList createDeliveryList();
void addDeliveryAtBack(DeliveryList *listPtr, Delivery data);
void addDeliveryAtFront(DeliveryList *listPtr, Delivery data);
Delivery removeDeliveryFromFront(DeliveryList *listPtr);
int isEmpty(DeliveryList list);
void clearDeliveryList(DeliveryList *listPtr);

// ================== Main ==================
int main(void){
    DeliveryList myList = createDeliveryList();  // create empty list
    Delivery temp;
    int choice;

    while(1){
        printf("Add delivery where? (1 - front; 2 - back; otherwise - exit): ");
        scanf("%d", &choice);

        if(choice != 1 && choice != 2){
            break;
        }

        printf("Enter delivery address: ");
        scanf(" %[^\n]", temp.address); // read string with spaces
        printf("Enter delivery distance: ");
        scanf("%f", &temp.distance);

        if(choice == 1){
            addDeliveryAtFront(&myList, temp);
        } else {
            addDeliveryAtBack(&myList, temp);
        }
    }

    printf("\nNow removing all the deliveries:\n");
    while(!isEmpty(myList)){
        Delivery removed = removeDeliveryFromFront(&myList);
        printf("Delivery to %s with distance %.2f removed from front\n", removed.address, removed.distance);
    }

    printf("List is empty\n");

    return 0;
}


// ================== Functions ==================
DeliveryList createDeliveryList(){
    // initialise empty struct and return it
    DeliveryList List;
    List.frontPtr = NULL;
    List.backPtr = NULL;
    return List;
}

void addDeliveryAtBack(DeliveryList *listPtr, Delivery data){
    // create a new node using malloc and add to end of the list 
    DeliveryNode *first_delivery = malloc(sizeof(DeliveryNode));

    // check if malloc failed 
    if(first_delivery == NULL){
        printf("MALLOC FAILED, SORRY\n");
        return;  // fixed: void function cannot return 1
    }

    // load data into the struct
    first_delivery->data = data;
    first_delivery->nextPtr = NULL;

    if(listPtr->frontPtr == NULL){
        // the list is empty 
        listPtr->frontPtr = first_delivery;
        listPtr->backPtr = first_delivery;
    } else {
        // slot a struct at the back because not empty
        listPtr->backPtr->nextPtr = first_delivery;
        listPtr->backPtr = first_delivery;
    }
}

void addDeliveryAtFront(DeliveryList *listPtr, Delivery data){
    // create the structure 
    DeliveryNode *first_node = malloc(sizeof(DeliveryNode));

    if(first_node == NULL){
        printf("MALLOC FAILED\n");
        return;  // fixed: void function cannot return 1
    }

    // add data to the node
    first_node->data = data;
    first_node->nextPtr = NULL;

    // check if the list is empty so both front and back point to the first_node
    if(listPtr->frontPtr == NULL){  // fixed: comparison (==), not assignment
        // empty list 
        listPtr->frontPtr = first_node;
        listPtr->backPtr = first_node;
    } else {
        // list is not empty, add to the front
        first_node->nextPtr = listPtr->frontPtr;
        listPtr->frontPtr = first_node;
    }
}

Delivery removeDeliveryFromFront(DeliveryList *listPtr){
    Delivery Value; // Store the Delivery struct

    // Check if the list is empty before accessing
    if (listPtr->frontPtr == NULL) {
        printf("List is empty, cannot remove.\n");
        Delivery empty;
        strcpy(empty.address, "EMPTY");
        empty.distance = 0.0;
        return empty;  // fixed dummy Delivery
    }

    // Store the value from the first node
    Value = listPtr->frontPtr->data;

    // Create a temp pointer (no malloc needed)
    DeliveryNode *temp = listPtr->frontPtr;

    // Move front pointer to next node
    listPtr->frontPtr = listPtr->frontPtr->nextPtr;

    // If list became empty, update backPtr too
    if (listPtr->frontPtr == NULL) {
        listPtr->backPtr = NULL;
    }

    // Free the removed node
    free(temp);

    // Return the stored data
    return Value;
}

int isEmpty(DeliveryList list){
    if(list.frontPtr == NULL){
        // list is empty
        printf("---EMPTY---\n");
        return 1;
    }
    return 0;  // fixed: return 0 if not empty
}

void clearDeliveryList(DeliveryList *listPtr){
    // check if empty first before clearing
    if (isEmpty(*listPtr)) {
        printf("ALREADY EMPTY\n");
    } else {
        // traverse through whole list and free them up
        DeliveryNode *temp;

        while (listPtr->frontPtr != NULL) {
            temp = listPtr->frontPtr;                      // store the current node
            listPtr->frontPtr = listPtr->frontPtr->nextPtr; // move to next node
            free(temp);                                    // free the old one
        }

        // after freeing all nodes, reset backPtr
        listPtr->backPtr = NULL;
    }
}

