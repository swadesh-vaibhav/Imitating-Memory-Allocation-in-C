#include<stdio.h>
#include "header.h"
void create_list()
{
        int key;
        printf("The sequence number of the newly created list is: %d\n",n+1);
        printf("Enter key value to be inserted in the newly created list-%d:\n",n+1);
        scanf("%d",&key);
        int index=pop();
        if(index==-1)
                printf("FAILURE: MEMORY NOT AVAILABLE\n");
        else if(n<6)
        {
                head[n]=index;
                arr[head[n]]=key;
                arr[head[n]+1]=-1;
                arr[head[n]+2]=-1;
                n++;
                printf("SUCCESS\n");
        }
        else printf("You have reached the maximum list limit\n");
}
int pop()
{
    if(freehead==-1)
        return -1;
    if(arr[freehead+1]==-1)
    {
        int tmp=freehead;
        freehead=-1;
        return tmp;
    }
    int trav=freehead;
    freehead=arr[freehead+1];
    arr[freehead+2]=-1;
    return trav;
}
int push(int index)
{
    int trav=freehead;
    if(trav==-1)
    {
        freehead=index;
        arr[index+1]=-1;
        arr[index+2]=-1;
        return index;
    }
    arr[index+1]=freehead;
    arr[freehead+2]=index;
    freehead=index;
    arr[index+2]=-1;
    return trav;
}
int add_element(int m, int key)
{
    int index=pop();
    int trav;
    trav=head[m-1];
    if(index==-1)
        return -1;
    else if(trav==-1)
    {
        head[m-1]=index;
        arr[head[m-1]]=key;
        arr[head[m-1]+1]=-1;
        arr[head[m-1]+2]=-1;
        return index;
    }
    else if((arr[head[m-1]]>key))
    {
        arr[index]=key;
        arr[index+1]=head[m-1];
        arr[head[m-1]+2]=index;
        head[m-1]=index;
        arr[index+2]=-1;
        return index;
    }
    else
    {
        while(arr[trav]<key&&arr[trav+1]!=-1)
            trav=arr[trav+1];
        if(arr[trav+1]==-1&&arr[trav]<key)
        {
            arr[trav+1]=index;
            arr[index+2]=trav;
            arr[index]=key;
            arr[index+1]=-1;
            return index;

        }
        else
        {
            arr[index]=key;
            arr[index+1]=trav;
            arr[index+2]=arr[trav+2];
            arr[arr[trav+2]+1]=index;
            arr[trav+2]=index;
            return index;
        }
    }
}
int delete_element(int key, int m)
{
    if(head[m-1]==-1)
        return -2;
    else
    {
        int trav;
        trav=head[m-1];
        if(arr[trav+1]==-1)
        {
           if(arr[trav]==key)
           {
               head[m-1]=-1;
               push(trav);
               return trav;
           }
           else return -1;
        }
        if(arr[trav]==key)
        {
            head[m-1]=arr[trav+1];
            arr[arr[trav+1]+2]=-1;
            push(trav);
            return trav;
        }
        while(arr[trav]!=key&&arr[trav+1]!=-1)
            trav=arr[trav+1];
        if(arr[trav+1]!=-1)
        {
            arr[arr[trav+2]+1]=arr[trav+1];
            arr[arr[trav+1]+2]=arr[trav+2];
            push(trav);
            return trav;
        }
        else if(arr[trav]==key)
        {
            arr[arr[trav+2]+1]=-1;
            push(trav);
            return trav;
        }
        else return -1;
    }
}
void display_all()
{
    int i;
    for(i=0;i<n&&head[i]!=-2;i++)
    {
        printf("\n\n\nElements of list- %d are:\n\nkey\tnext\tprev\n\n",i+1);
        if(arr[head[i]+1]==-1&&arr[head[i]+2]==-1)
        {
            printf("%d\tNIL\tNIL\n",arr[head[i]]);
            continue;
        }
        if(head[i]==-1)
            continue;
        int trav=head[i];
        printf("%d\t%d\tNIL\n",arr[trav],arr[trav+1]);
        if(arr[trav+1]==-1)
            continue;
        trav=arr[trav+1];
        while(arr[trav+1]!=-1)
        {
            printf("%d\t%d\t%d\n",arr[trav],arr[trav+1],arr[trav+2]);
            trav=arr[trav+1];
        }
        printf("%d\tNIL\t%d\n",arr[trav],arr[trav+2]);
    }
}
void display_arr()
{
    int i=0;
    printf("KEY\tNEXT\tPREV\t\n");
    for(i=0;i<30;i+=3)
        printf("%d\t%d\t%d\n",arr[i],arr[i+1],arr[i+2]);
}
int count_single(int m)
{
    if(head[m-1]<0)
        return head[m-1];
    int trav=head[m-1];
    int count=1;
    while(arr[trav+1]!=-1)
    {
        trav=arr[trav+1];
        count++;
    }
    return count;
}
int count_total()
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(head[i]<0)
            continue;
        count+=count_single(i+1);
    }
    return count;
}
int display_heads()
{
    int i=0;
    for(i=0;i<6;i++)
        printf("\n%d",head[i]);
    return 0;
}
void display_free()
{
    printf("[");
    if(freehead==-1)
        ;
    else
    {
        int trav=freehead;
        while(arr[trav+1]!=-1)
        {
            printf("%d, ",trav);
            trav=arr[trav+1];
        }
        printf("%d",trav);
    }
    printf("]");
}
void defragment()
{
    int homo=maximum();
    int lumo=minimum();
    if(homo<0||lumo<0)
        printf("\nSUCCESS\n");
    else
    {
        while(homo>lumo)
        {
            if(arr[lumo+2]==-1)
            {
                freehead=homo;
            }
            else
                arr[arr[lumo+2]+1]=homo;
            if(arr[homo+2]==-1)
            {
                int i;
                for(i =0;i<n;i++)
                {
                    if(head[i]==homo)
                        break;
                }
                head[i]=lumo;
            }
            else
                arr[arr[homo+2]+1]=lumo;
            if(arr[lumo+1]==-1)
            {
                ;
            }
            else arr[arr[lumo+1]+2]=homo;
            if(arr[homo+1]==-1)
            {
                ;
            }
            else arr[arr[homo+1]+2]=lumo;
            int tmp;
            tmp=arr[lumo];
            arr[lumo]=arr[homo];
            arr[homo]=tmp;
            tmp=arr[lumo+1];
            arr[lumo+1]=arr[homo+1];
            arr[homo+1]=tmp;
            tmp=arr[lumo+2];
            arr[lumo+2]=arr[homo+2];
            arr[homo+2]=tmp;
            homo=maximum();
            lumo=minimum();
        }
        printf("SUCCESS");
    }

}
int maximum()
{
    int homo=head[0],trav;
    for(trav=head[0],glob=0;glob<n;glob++)
    {
        if(head[glob]<0)
            continue;
        trav=head[glob];
        if(head[glob]>homo)
            homo=head[glob];
        while(arr[trav+1]!=-1)
        {
            trav=arr[trav+1];
            if(trav>homo)
                homo=trav;
        }
    }
    /*printf("max: %d",homo);*/
    return homo;
}
int minimum()
{
    int trav=freehead;
    int lumo=trav;
    if(freehead==-1) return -1;
    while(arr[trav+1]!=-1)
    {
        if(arr[trav+1]<lumo)
            lumo=arr[trav+1];
        trav=arr[trav+1];
    }
    /*printf("min: %d",lumo);*/
    return lumo;
}
