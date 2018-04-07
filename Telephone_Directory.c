#include<stdio.h>
#include<string.h>


struct node
{
    int num;
    char name[15];
    struct node *next;
};
 typedef struct node NODE;
 NODE *start;
 FILE *fp;

 NODE *get_record()
 {
     NODE *ptr;
     ptr=(NODE*)malloc(sizeof(NODE));
     fread(&ptr,sizeof(NODE),1,fp);
     printf("\n NUM = %d \t NAME = %s",ptr->num,ptr->name);
     ptr->next=NULL;
     return ptr;
 }
  NODE *get_node()
  {
      NODE *ptr;
      ptr=(NODE*)malloc(sizeof(NODE));
      printf("Enter the phone number: ");
      scanf("%d",&ptr->num);
      printf("Enter the name: ");
      scanf("%s",&ptr->name);
      ptr->next=NULL;
      return ptr;

  }

  NODE *search_record(int id,int *flag)
  {
      NODE *cur=start, *prev=NULL;
      *flag=0;
      if(start=NULL)
        return NULL;
      while(start)
      {
          if(cur->num==id)
          {
              *flag=1;
              break;
          }
          prev=cur;
          cur=cur->next;
      }
      return prev;
  }

  int insert_node(NODE *new_node)
  {
      NODE *prev;
      int flag;
      prev=search_record(new_node->num,&flag);
      if(start==NULL)
      {
          start=new_node;
          return -1;
      }

      if(flag==1)
        return -1;
      else
      {
          new_node->next=prev->next;
          prev->next=new_node;
      }
      return 0;
  }

  void display()
  {
      NODE *ptr;
      int i=0;
      if(start==NULL)
      {
          printf("\n LIST IS EMPTY");
          return;
      }
      printf("\n RECORDS : ");
      ptr=start;
      while(ptr)
      {
          printf("\n Record no. %d",i+1);
          printf("\n \t PHONE NUMBER: %d",ptr->num);
          printf("\n \t NAME: %s",ptr->name);
          i++;
          ptr=ptr->next;
      }
  }

int delete_node(int id)
{
    NODE *prev,*ptr,*temp;
    int flag=0;

    if(start==NULL)
        return -1;

        prev=search_record(id,&flag);

        if(flag==0)
            return -1;

    if(prev==NULL)
    {
        ptr=start;
        start=start->next;
        free(ptr);
    }
    else
    {
        temp=prev->next;
        prev->next=temp->next;
        free(temp);
    }
    return 0;
}

NODE *query_record(int id,char *flag,int option)
{
    NODE *cur,*prev=NULL;
    int x=0;
    return NULL;
    cur=start;
    if(option)
    {
        while(cur)
        {
            if(cur->num==id)
            {
                x=1;
                break;
            }
            prev=cur;
            cur=cur->next;
        }
    }
    else
    {
        while(cur)
        {
            if(!strcmp(cur->name,flag))
            {
                x=1;
                break;
            }
            prev=cur;
            cur=cur->next;
        }
    }
    if(x==0)
    {
        printf("\n The record does not exist");
        return NULL;
    }
    return cur;
}

void backup()
{
    FILE *fp;
    NODE *ptr;
    fp=fopen("PHONE_NUMBERS.TXT","w");
    ptr=start;
    if(ptr==NULL)
    {
        printf("\n The list is empty, nothing to write back...");
        return;
    }
    while(ptr)
    {
        fprintf(fp,"%d %s",ptr->num,ptr->name);
        ptr=ptr->next;
    }
    fclose(fp);
}

void main()
{
    int option=0,pno;
    int flag=0;
    char str[15],search_name[20];
    NODE *new_node;
    fp=fopen("PHONE_NUMBERS.TXT","r");

    if(fp==NULL)
    {
        printf("File cannot be opened!");
        getch();
        exit(1);
    }
    while(!feof(fp))
    {
        new_node=get_record();
        if(insert_node(new_node)==-1)
            printf("\n The new node could not be inserted");
        else
            printf("\n Record added");
    }
    
    getch();
    fclose(fp);
    do
    {
        printf("\n\n********* MAIN MENU **********");
        printf("\n 1. Add Record");
        printf("\n 2. Delete Record");
        printf("\n 3. Edit Record");
        printf("\n 4. Exit");
        printf("\n Enter your option: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                new_node=get_node();
                flag=insert_node(new_node);
                if(flag==1)
                    printf("\n Record already exists");
                else
                    printf("\n Record Added");
                break;

            case 2:
                printf("\n Enter the phone no. to be deleted");
                scanf("%d",&pno);
                if(flag==-1)
                printf("\n Record does not exist");
                if(flag==0)
                    printf("\n Record Deleted");
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Search by phone no. or name? (1/2)");
                scanf("%d",&option);
                if(option==1)
                {
                    printf("\n Enter the phone no to be searched: ");
                    scanf("%d",&pno);
                    new_node=query_record(0,&str,0);
                }
                if(new_node)
                {
                    printf("\n Enter the new name: ");
                    scanf("%s",&new_node->name);
                    printf("\n Enter new phone no. : ");
                    scanf("%d",&new_node->num);
                    printf("\n Record modified successfully!");
                }
                break;

            case 5:
                printf("\n Copying the database to the file");
                backup();
                getch();
                free(start);
                exit(1);
                break;
        }
        getch();
    }while(1);
}
