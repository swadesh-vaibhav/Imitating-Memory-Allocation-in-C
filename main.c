#include<stdio.h>
#include "header.h"
int main()
{
        int choice=1;
        int i;
        for(i=1;i<max-3;i+=3)
            arr[i]=i+2;
        arr[max-2]=-1;
        for(i=5;i<max;i+=3)
            arr[i]=i-5;
        arr[2]=-1;
        for(i=0;i<6;i++)
            head[i]=-2;
        n=0;
        freehead=0;
        while(choice)
        {
                printf("\n\nSelect an option:\n1. Create a new list\n2. Insert a new element in a given list in sorted order\n3. Delete an element from a given a list\n4. Count total elements excluding free list\n5. Count total elements of a list\n6. Display all lists\n7. Display free list\n8. Perform defragment\n9. Press 0 to exit\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 0: exit(0);
                        case 1: create_list();
                                break;
                        case 2: printf("\nList you want to insert in:");
                                int key,m;
                                scanf("%d",&m);
                                if(m>n)
                                {
                                    printf("\nList has not been created\n");
                                    break;
                                }
                                printf("\nEnter the key value:");
                                scanf("%d",&key);
                                int i= add_element(m,key);
                                if(i==-1)
                                    printf("FAILURE:MEMORY NOT AVAILABLE\n");
                                else printf("SUCCESS\n");
                                break;
                        case 3: printf("\nList you want to delete from:");
                                scanf("%d",&m);
                                if(m>n||m<0)
                                    printf("\nList does not exist\n");
                                else
                                {
                                    printf("\nEnter the key value:");
                                    scanf("%d",&key);
                                    int flag=delete_element(key, m);
                                    if(flag==-1)
                                    {
                                        printf("\n FAILURE:ELEMENT NOT THERE\n");
                                    }
                                    else if(flag==-2)
                                    {
                                        printf("\nFAILURE:LIST EMPTY");
                                    }
                                    else
                                    {
                                        printf("\nSUCCESS\n");
                                    }
                                }
                                break;
                        case 4: printf("\nTotal number of nodes in all lists are: %d",count_total());
                                break;
                        case 5: printf("\nEnter the list number:");
                                scanf("%d",&m);
                                int count=count_single(m);
                                if(count==-1)
                                {
                                    printf("0");
                                    break;
                                }
                                if(count==-2)
                                {
                                    printf("\nList doesn't exist\n");
                                    break;
                                }
                                printf("\nTotal number of nodes in list %d are %d\n",m,count);
                                break;
                        case 6: display_all();
                                break;
                        case 7: printf("\nElements of free list are:\n");
                                display_free();
                                break;
                        case 8: defragment();
                                break;
                        /*case 9: display_arr();
                                break;
                        case 10:display_heads();
                                break;
                        case 11:printf("\nmax:\n%d\n",maximum());
                                break;
                        case 12:printf("\nmin:\n%d\n",minimum());
                                break;*/
                        default:printf("\n Enter a valid option\n");
                                break;
                }
        }
    return 0;
}
