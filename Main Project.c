#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct warehouse
{
    int boxnumber;
    char name[100];
    char amount[500];
    struct warehouse *next;

}*head;
void insert(int boxnumber, char* name, char* amount)
{
    struct warehouse * warehouse = (struct warehouse *) malloc(sizeof(struct warehouse));
    warehouse->boxnumber = boxnumber;
    strcpy(warehouse->name, name);
    strcpy(warehouse->amount, amount);
    warehouse->next = NULL;

    if(head==NULL)
    {
        head = warehouse;
    }
    else
    {
    warehouse->next = head;
    head = warehouse;
    }

}
void search(int boxnumber)
{
    struct warehouse * temp = head;
     while(temp!=NULL)
    {
    if(temp->boxnumber==boxnumber)
    {
    printf("Box Number: %d\n", temp->boxnumber);
    printf("Product Name: %s\n", temp->name);
    printf("Total amount: %s\n", temp->amount);
    return;
    }
        temp = temp->next;
  }
    printf("Box with this number %d is not found !!!\n", boxnumber);
}
void update(int boxnumber)
{

    struct warehouse * temp = head;
    while(temp!=NULL)
        {
        if(temp->boxnumber==boxnumber){
            printf("Record with that box number %d Found !!!\n", boxnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new amount number: ");
            scanf("%s", temp->amount);
            return;
        }
        temp = temp->next;

    }
    printf("Box with this number %d is not found !!!\n", boxnumber);

}
void Delete(int boxnumber)
{
    struct warehouse * temp1 = head;
    struct warehouse * temp2 = head;
    while(temp1!=NULL)
        {
        if(temp1->boxnumber==boxnumber){

        printf("Record with box number %d Found !!!\n", boxnumber);

    if(temp1==temp2)
        {
         head = head->next;
        free(temp1);
        }
    else{
        temp2->next = temp1->next;
        free(temp1);
        }

        printf("Record Successfully Deleted !!!\n");
        return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

         }
    printf("That box %d is not found !!!\n", boxnumber);

}
void display()
{
    struct warehouse * temp = head;
    while(temp!=NULL)
        {
        printf("Box Number: %d\n", temp->boxnumber);
        printf("Product Name: %s\n", temp->name);
        printf("amount: %s\n", temp->amount);
        temp = temp->next;

    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char amount[500];
    int boxnumber;

    do
    {


 system("color B");

        printf("\t\t************************************************\n");
    printf("\t\t---        Warehouse Box Details Manager     ---\n");
    printf("\t\t************************************************\n\n");

    printf("\n\n\t\t\t\t*---  MENU ---*\t\n\n");

printf("Press 1 to insert box details\nPress 2 to search for box details\nPress 3 to delete box details\nPress 4 to update box details\nPress 5 to display all box details");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
case 1:
    printf("Enter box number: ");
    scanf("%d", &boxnumber);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter amount number: ");
    scanf("%s", amount);
    insert(boxnumber, name, amount);
    system("cls");
                break;
case 2:
    printf("Enter box number to search: ");
    scanf("%d", &boxnumber);
    search(boxnumber);
                break;
case 3:
    printf("Enter box number to delete: ");
    scanf("%d", &boxnumber);
    Delete(boxnumber);
    break;
case 4:
    printf("Enter box number to update: ");
    scanf("%d", &boxnumber);
    update(boxnumber);
                break;
case 5:
    display();
    break;
        }

    } while (choice != 0);
}
