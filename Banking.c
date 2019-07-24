#include<stdio.h>
#include<stdlib.h>
struct data
{
char name[20];
char phnum[20];
char accnum[20];
int amt;
char type[10];
char add[100];
};

struct node
{
struct data d;
struct node *next;
}*start =NULL;
struct node *loc,*temp,*new1,*prev;
void insert_atbeg(struct data ds)
{

	new1=(struct node*)malloc(sizeof(struct node));
	new1->d=ds;
	new1->next=start;
	start=new1;

}
void deleteNode(struct node **head_ref, char key[])
{
    // Store head node
    temp = *head_ref ;

    // If head node itself holds the key to be deleted
    if (temp != NULL &&(strcmp(temp->(d.accnum),key))==0)
    {
	*head_ref = temp->next;   // Changed head
	free(temp);               // free old head
	return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL &&strcmp(temp->(d.accnum),key)==0)
    {
	prev = temp;
	temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}
void deletionatbeg()
{
	if(start==NULL)
	printf("no node");
	else
	{
	temp=start;
	start=start->next;
	free(temp);
	}
}

struct node* search(char search_element[])
{
	struct node *ptr=start;
	while(ptr!=NULL&&strcmp(((ptr->(d.accnum)),search_element))==0)
	{
	ptr=ptr->next;
	}
	return(ptr);
}

void main()
{
int ch=0,n,ele,pos,mon,q;
char k[20];
char acc[20];
struct data da;
struct node *temp,*tem;
while(ch!=6)
{
	printf("\t\tenter the choice\n");
	printf("\t\t**********************************\n");
	printf("\t\t*1.creating new account          *\n");
	printf("\t\t*2.log in                        *\n");
	printf("\t\t*3.search an account             *\n");
	printf("\t\t*4.delete an account             *\n");
	printf("\t\t*5.delete entire entir account  *\n");
	printf("\t\t*6.exit                         *\n\t\t8.exit\n");
	printf("\t\t*********************************\n");
scanf("%d",&ch);

switch(ch)
{
	case 1:
		printf("enter the name\n ");
		gets(da.name);
		printf("enter the add\n");
		gets(da.add);
		printf("enter the phone number\n");
		gets(da.phnum);
		printf("enter the account type\n");
		gets(da.type);
		printf("enter the account number\n");
		gets(da.accnum);
		printf("account created successfully\n");


		insert_atbeg(da);
		break;

	case 2:
		printf("enter the account number\n");
		gets(k);
		tem=search(k);
		if(tem==NULL)
		{
		printf("account not present \n");
		}
		printf("1. deposit money \n");
		printf("2. widrawn money \n");
		scanf("%d",&q);
		if(q==1)
		{
		printf("enter the money do u want to add\n");
		scanf("%d",&mon);
		temp->(d.amt)+=mon;
		printf("money deposit successfull\n");
		}
		if(q==2)
		{
		printf("enter the money u want to widrawn\n");
		scanf("%d",&mon);
		if(temp->(d.amt)>mon)
		printf("not enough balanve error\n");
		else
		{
		temp->(d.amt)-=mon;
		printf("%d money is widrawn successfully\n",mon);
		}
		}
		break;
	case 3: printf("enter the account number\n");
		gets(k);
		tem=search(k);
		if(tem==NULL)
		{
		printf("account not present \n");
		}
		else
		{
		printf("name is ::::%s\n ",tem->(d.name));
		printf("the add is :::::%s\n",tem->(d.add));
		printf("phone number is ::::%s\n",tem->(d.phnum));
		printf(" the account type is :::%s\n",tem->(d.type));
		printf("account number is ::::%s\n",tem->(d.accnum));
		printf("current balance is ::::%d",tem->(d.amt));

		}
		break;


	case 4:

		printf("enter the account to be deleted \n");
		gets(acc);
		deleteNode(&start,acc);
		break;
		
	case 5:while(start!=NULL)
		{
		deletionatbeg();
		}
		printf("deleted successfully\n");
		break;

	case 6:
		exit(0);
		break;

}
}
}
/*
void traverse()
{
		if(start==NULL)
		printf("empty");
		else
		{
		temp=start;
		while(temp!=NULL)
		{
		printf("%d",temp->info);
		temp=temp->next;
		}
		}
}
	}
} 
