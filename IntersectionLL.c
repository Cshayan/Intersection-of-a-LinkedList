//Programme to find the intersection point of two linked list
#include<stdio.h>
#include<stdlib.h>
//structure declaration
struct node
{
    int data;
    struct node *next;
};
//display function to print the list
void display(struct node *start1)
{

    struct node *curr=start1;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
//function counts the length of the list
int countLength(struct node *start)
{
    struct node *curr=start;
    int len=1;
    while(curr!=NULL)
    {
        len++;
        curr=curr->next;
    }
    return len;
}
// function finds the intersection of the lists
void findIntersection(struct node *start1,struct node *start2)
{
    struct node *curr1=start1,*curr2=start2;

    int len1=countLength(curr1);
    int len2=countLength(curr2);

    int d,flag=0;
    if(len1>len2)
        d=len1-len2;
    else
        d=len2-len1;

    if(len1>len2)
        {
            while(d>0)
            {
                curr1=curr1->next;
                d--;
            }
        }
     else
     {
         while(d>0)
         {
             curr2=curr2->next;
             d--;
         }
     }

     while(curr1!=NULL&&curr2!=NULL)
     {
         if(curr1==curr2)
         {
             flag=1;
             break;
         }
         curr1=curr1->next;
         curr2=curr2->next;
     }
     if(flag==1)
     {
         printf("\nIntersection is present at the node having value %d\n\n\n",curr1->data);
     }
     else{
        printf("\nNo intersection is present\n\n");
     }
}
int main()
{
/*Below is the implementation of creation of two linked
  list having an intersection
  1st:-10->12->13->14->15
  2nd:-5->6->14->15
*/
    struct node *start1,*start2,*temp;

    start2=(struct node *)malloc(sizeof(struct node));
    start2->data=5;

    start1=(struct node *)malloc(sizeof(struct node));
    start1->data=10;

    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=12;
    start1->next=temp;

    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=13;
    start1->next->next=temp;

    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=6;
    start2->next=temp;

    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=14;
    start1->next->next->next=temp;
    start2->next->next=temp;

    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=15;
    start2->next->next->next=temp;
    start2->next->next->next->next=NULL;

    printf("\n1st list is:-\n");
    display(start1);
    printf("\n2nd list is:-\n");
    display(start2);

    findIntersection(start1,start2);

}

