#include <stdio.h> 
#include <malloc.h> 
#include <stdlib.h> 
// C Structure for employee... 
struct Employee 
{ 
struct Employee *llink; // Left link of node 
int ssn;                
// Info.. of employee 
char name[50]; 
float sal; 
struct Employee *rlink; // Right link of node 
}; 
typedef struct Employee *NODE; 
int count = 0;      
// to count total number of employees 
NODE first = NULL;  // Start with empty list.. 
NODE createNode();  // Creating temp node with data 
void createDll();   // Creating emp DLL by inserting at end 
void insertFront(); // Inserting at front of the list 
void insertEnd();   // inserting at the end of the list 
void deleteFront(); // Deleting node at front of list 
void deleteEnd();   // delelting node at end of list 
void displayDll();  // displaying the list of employees 
int main() 
{ 
int ch; 
DSA Lab Manual_________________________________________________________ 
    while (1) 
    { 
        printf("\n1.Create Emp DLL \n2.insert Front \n3.Insert End \n4.Delete Front \n5.Delete 
End \n6.Display DLL \n7.Exit\n Enter Your Choice: "); 
        scanf("%d", &ch); 
        switch (ch) 
        { 
        case 1: 
            createDll(); // Create a DLL by inserting end 
            break; 
        case 2: 
            insertFront(); // inserting front of list 
            break; 
        case 3: 
            insertEnd(); // Inserting end of the list 
            break; 
        case 4: 
            deleteFront(); // delete front of the list 
            break; 
        case 5: 
            deleteEnd(); // delete end of the list 
            break; 
        case 6: 
            displayDll(); 
            break; 
        case 7: 
            exit(0); 
        } 
    } 
    return 0; 
} 
NODE createNode() 
{ 
    NODE temp; 
    temp = malloc(sizeof(struct Employee)); // allocate memory for new node 
    printf("Enter emp SSN: \t");            // read all the details of emp 
    scanf("%d", &temp->ssn); 
    printf("Enter emp Name: \t"); 
    scanf("%s", temp->name); 
    printf("Enter emp Salary: \t"); 
    scanf("%f", &temp->sal); 
    temp->llink = NULL; // make new node left and right link NULL 
    temp->rlink = NULL; 
    count++;     // increment the count when new node is created.. 
    return temp; // return newly created node with data 
} 
void createDll() 
{ 
    int i, n; 
    NODE temp, cur; // creating DLL by inserting end of the list 
DSA Lab Manual_________________________________________________________ 
    // Number of employees to create a list 
    printf("\n Enter number of Employees:"); 
    scanf("%d", &n); 
    // Create n number of employees list.. 
    for (i = 0; i < n; i++) 
    { 
        printf("Enter Employee[%d] Details:\n", i + 1); 
        temp = createNode(); // Get new node with data 
        if (first == NULL)   // if no nodes in list temp node is first node 
        { 
            first = temp; 
        } 
        else 
        { 
            cur = first;               // take cur is reference node to insert at last 
            while (cur->rlink != NULL) // repeat till end of list 
            { 
                cur = cur->rlink; // traverse to next node 
            } 
            cur->rlink = temp; // attach temp to last node with rLink 
            temp->llink = cur; // store second last node address in last node 
        } 
    } 
    // call diplay of the list 
    displayDll(); 
} 
void insertFront() 
{ 
    NODE temp; 
    temp = createNode(); // Get new node with data 
    first->llink = temp; // store address of temp node in first node left link 
    temp->rlink = first; // insert front of the list by linking right of temp with first 
    first = temp;        // Make temp as first node 
    displayDll(); 
} 
void insertEnd() 
{ 
    NODE cur = first; 
    // Create a new node with data 
    NODE temp = createNode(); 
    // Insert at end of the function 
    while (cur->rlink != NULL) 
    { 
        cur = cur->rlink; // Move to Last node 
    } 
    cur->rlink = temp; // Insert last rlink 
    temp->llink = cur; // store prev node llink in last node 
    count++;           // Increment the count when new node inserted.. 
    displayDll(); 
} 
DSA Lab Manual_________________________________________________________ 
void deleteFront() 
{ 
    NODE cur; 
    cur = first->rlink; // store second node in current node 
    free(first);        // delete front i.e first node 
    first = cur;        // make second node as first node after deletion 
    //   (or) use the below statements 
    // first->llink=NULL; 
    // first=first->rlink; 
    first->llink = NULL; //  Make first node left link NULL 
    count--;             // when node is deleted 
    displayDll(); 
} 
void deleteEnd() 
{ 
    NODE cur, prev;            // Prev stores the second last node 
    cur = first;               // take cur as reference to delete last node 
    while (cur->rlink != NULL) // repeat till end of the list 
    { 
        prev = cur;       // Store second last node in cur node 
        cur = cur->rlink; // Move to next node 
    } 
    free(cur);          // delete the last Node 
    prev->rlink = NULL; // Make last node rlink null to get end of the list. 
    count--;            // decrement the count when node is deleted 
    displayDll(); 
} 
void displayDll() 
{ 
    int count = 0; 
    NODE cur;          // take cur node as reference to populate data 
    cur = first;       // Make use of cur as first 
    if (first == NULL) // if first is null list is empty... 
    { 
        printf("\n List is Empty!"); 
        return; 
    } 
    // Display the heading part of details.... 
    printf("\n SSN \t Name \t\t Salary  \n"); 
    while (cur != NULL) 
    { 
        printf("%d \t %s \t\t %f  \n ", cur->ssn, cur->name, cur->sal); 
        cur = cur->rlink; // move to the next node till end of list.. 
        count++;          // increment the count to get total count of nodes 
    } 
    printf("\n Total Num of employees:%d\n ", count); // Dispaly total count of Emps... 
}