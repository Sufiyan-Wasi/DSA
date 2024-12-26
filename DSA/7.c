#include <stdio.h> 
struct student 
{ 
int rollno; 
char usn[20]; 
char name[50]; 
struct student *link; 
}; 
typedef struct student *NODE; 
int count = 0; // To count total no of nodes in a list.. 
NODE createNode(); 
void CreateSLL(); // Creating list by inserting fornt 
void DisplaySLL(); 
void InsertFront(); 
void InsertEnd(); 
void DeleteFront(); 
void DeleteEnd(); 
NODE first = NULL; 
int main() 
{ 
int ch; 
    while(1) 
    { 
        printf("1.CreateSLL \n2.DisplaySLL \n3.Insert front \n4.Insert End \n5.Delete Front\n6.Delete End \n7.Exit\nEnter Your Choice:"); 
        scanf("%d", &ch); 
        switch (ch) 
        { 
        case 1: 
            CreateSLL(); 
            break; 
        case 2: 
            DisplaySLL(); 
            break; 
        case 3: 
            InsertFront(); 
            break; 
        case 4: 
            InsertEnd(); 
            break; 
        case 5: 
            DeleteFront(); 
            break; 
        case 6: 
            DeleteEnd(); 
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
    temp = malloc(sizeof(struct student)); 
    printf("\n Enter Roll Number:"); 
    scanf("%d", &temp->rollno); 
    printf("\n Enter Usn:"); 
    scanf("%s", temp->usn); 
    printf("\n Enter Student Name:"); 
    scanf("%s", temp->name);    
    temp->link = NULL; 
    count++;            
    return temp;      
} 
void CreateSLL() 
{  
    int i, n; 
    NODE temp; 
    printf("\n Enter number of students:"); 
    scanf("%d", &n); 
    for (i = 0; i < n; i++) 
    { 
        printf("Enter Student %d details:", i + 1); 
        temp = createNode();
        if (first == NULL)  
        { 
            first = temp;  
        } 
        else 
        { 
            temp->link = first; 
            first = temp; 
        } 
        printf("Student node inserted at Front of List \n"); 
    } 
    DisplaySLL(); 
} 
void DisplaySLL() 
{ 
    NODE cur = first; 
    if (first == NULL) 
    { 
        printf("\n Student List is empty!"); 
        return; 
    } 
    printf("\nStudents List:\n"); 
    printf("----------------------------------------------\n"); 
    while (cur != NULL) 
    { 
        printf("%d\t%s\t%s\n",cur->rollno, cur->usn, cur->name); 
        cur = cur->link; 
    } 
    printf("\n"); 
    printf("Total Number of students: %d \n", count); 
} 
void InsertFront() 
{ 
    NODE temp = createNode(); 
    temp->link = first; 
    first = temp; 
    DisplaySLL(); 
} 
void InsertEnd() 
{ 
    NODE temp, cur;       
    cur = first;              
    while (cur->link != NULL) 
    { 
        cur = cur->link; 
    } 
    temp = createNode();
    cur->link = temp;    
    printf("Studnet Node inserted at end of the list!\n"); 
    DisplaySLL(); 
} 
void DeleteFront() 
{ 
    NODE cur; 
    cur = first->link;
    free(first);      
    first = cur;      
    printf("Node deleted front of the list!\n"); 
    count--;
    DisplaySLL(); 
} 
void DeleteEnd() 
{ 
    NODE cur, prev;   
    cur = first;    
    if (first == NULL) 
    { 
        printf("Student list is empty!\n"); 
        return; 
    } 
    if (first->link == NULL)
    { 
        free(first); 
    } 
    while (cur->link != NULL) 
    { 
        prev = cur;      
        cur = cur->link; 
    } 
    free(cur);          
    prev->link = NULL; 
    printf("Node deleted end of the list!\n"); 
    count--; 
    DisplaySLL(); 
}