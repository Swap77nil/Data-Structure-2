# Data-Structure-2<br>
Program 1:<br>
----------------------------------------------------<br>
1.Write a C++ program to implement singly linked list<br>
#include<iostream><br>
#include<cstdlib><br>
using namespace std;<br>
struct node<br>
{<br>
int info;<br>
struct node *next;<br>
}*start;<br>
class single_llist<br>
{<br>
public:<br>
node* create_node(int);<br>
void insert_begin();<br>
void insert_last();<br>
void insert_pos();<br>
void delete_begin();<br>
void delete_last();<br>
void delete_pos();<br>
void search();<br>
void display();<br>
single_llist()<br>
{<br>
start = NULL;<br>
}<br>
};<br>
.0<br>
int main()<br>
{<br>
int choice;<br>
single_llist sl,s2;<br>
start = NULL;<br>
do<br>
{<br>
cout<<"1.Insert at first"<<endl;<br>
cout<<"2.Insert at last"<<endl;<br>
cout<<"3.Insert at position"<<endl;<br>
cout<<"4.Delete at first"<<endl;<br>
cout<<"5.Delete at Last"<<endl;<br>
cout<<"6.Delete at position"<<endl;<br>
cout<<"7.Search"<<endl;<br>
cout<<"8.Display"<<endl;<br>
cout<<"9.Exit "<<endl;<br>
cout<<"Enter your choice :";<br>
cin>>choice;<br>
switch(choice)<br>
{<br>
case 1: sl.insert_begin();<br>
sl.display();<br>
break;<br>
case 2: sl.insert_last();<br>
sl.display();<br>
break;<br>
case 3: sl.insert_pos();<br>
sl.display();<br>
break;<br>
case 4: s2.delete_begin();<br>
sl.display();<br>
break;<br>
case 5: s2.delete_last();<br>
sl.display();<br>
break;<br>
case 6: sl.delete_pos();<br>
sl.display();<br>
break;<br>
case 7:sl.search();<br>
sl.display();<br>
break;<br>
case 8:sl.display();<br>
break;<br>
case 9:exit(0);<br>
break;<br>
default:cout<<"Wrong choice...???"<<endl;<br>
break;<br>
}<br>
}<br>
while(choice != 9);<br>
}<br>
node *single_llist::create_node(int value)<br>
{<br>
struct node *temp, *s;<br>
temp = new(struct node);<br>
if (temp == NULL)<br>
{<br>
cout<<"Memory not allocated"<<endl;<br>
return 0;<br>
}<br>
else<br>
{<br>
temp->info = value;<br>
temp->next = NULL;<br>
return temp;<br>
}<br>
}<br>
void single_llist::insert_begin()<br>
{<br>
int value;<br>
cout<<"Enter the value to be inserted : ";<br>
cin>>value;<br>
struct node *temp, *s;<br>
temp = create_node(value);<br>
if (start == NULL)<br>
{<br>
start = temp;<br>
start->next = NULL;<br>
cout<<temp->info<<" is inserted at first in the empty list"<<endl;<br>
}<br>
else<br>
{<br>
s = start;<br>
start = temp;<br>
start->next = s;<br>
cout<<temp->info<<" is inserted at first"<<endl;<br>
}<br>
}<br>
void single_llist::insert_last()<br>
{<br>
int value;<br>
cout<<"Enter the value to be inserted : ";<br>
cin>>value;<br>
struct node *temp, *s;<br>
temp = create_node(value);<br>
if (start == NULL)<br>
{<br>
start = temp;<br>
start->next = NULL;<br>
cout<<temp->info<<" is inserted at last in the empty list"<<endl;<br>
}<br>
else<br>
{<br>
s = start;<br>
while (s->next != NULL)<br>
{<br>
s = s->next;<br>
}<br>
temp->next = NULL;<br>
s->next = temp;<br>
cout<<temp->info<<" is inserted at last"<<endl;<br>
}<br>
}<br>
void single_llist::insert_pos()<br>
{<br>
int value, pos, counter = 0, loc = 1;<br>
struct node *temp, *s, *ptr;<br>
s = start;<br>
while (s != NULL)<br>
{<br>
s = s->next;<br>
counter++;<br>
}<br>
if (counter == 0){}<br>
else<br>
{<br>
cout<<"Enter the postion from "<<loc<<" to "<<counter+1<<" : ";<br>
cin>>pos;<br>
s = start;<br>
if(pos == 1)<br>
{<br>
cout<<"Enter the value to be inserted : ";<br>
cin>>value;<br>
temp = create_node(value);<br>
start = temp;<br>
start->next = s;<br>
cout<<temp->info<<" is inserted at first"<<endl;<br>
}<br>
else if (pos > 1 && pos <= counter)<br>
{<br>
cout<<"Enter the value to be inserted : ";<br>
cin>>value;<br>
temp = create_node(value);<br>
for (int i = 1; i < pos; i++)<br>
{<br>
ptr = s;<br>
s = s->next;<br>
}<br>
ptr->next = temp;<br>
temp->next = s;<br>
cout<<temp->info<<" is inserted at position "<<pos<<endl;<br>
}<br>
else if (pos == counter+1)<br>
{<br>
cout<<"Enter the value to be inserted : ";<br>
cin>>value;<br>
temp = create_node(value);<br>
while (s->next != NULL)<br>
{<br>
s = s->next;<br>
}<br>
temp->next = NULL;<br>
s->next = temp;<br>
cout<<temp->info<<" is inserted at last"<<endl;<br>
}<br>
else<br>
{<br>
cout<<"Positon out of range...!!!"<<endl;<br>
}<br>
}<br>
}<br>
void single_llist::delete_begin()<br>
{<br>
if (start == NULL){}<br>
else<br>
{<br>
struct node *s, *ptr;<br>
s = start;<br>
start = s->next;<br>
cout<<s->info<<" deleted from first"<<endl;<br>
free(s);<br>
}<br>
}<br>
void single_llist::delete_last()<br>
{<br>
int i, counter = 0;<br>
struct node *s, *ptr;<br>
if (start == NULL){}<br>
else<br>
{<br>
s = start;<br>
while (s != NULL)<br>
{<br>
s = s->next;<br>
counter++;<br>
}<br>
s = start;<br>
if (counter == 1)<br>
{<br>
start = s->next;<br>
cout<<s->info<<" deleted from last"<<endl;<br>
free(s);<br>
}<br>
else<br>
{<br>
for (i = 1;i < counter;i++)<br>
{<br>
ptr = s;<br>
s = s->next;<br>
}<br>
ptr->next = s->next;<br>
cout<<s->info<<" deleted from last"<<endl;<br>
free(s);<br>
}<br>
}<br>
}<br>
void single_llist::delete_pos()<br>
{<br>
int pos, i, counter = 0, loc = 1;<br>
struct node *s, *ptr;<br>
s = start;<br>
while (s != NULL)<br>
{<br>
s = s->next;<br>
counter++;<br>
}<br>
if (counter == 0){}<br>
else<br>
{<br>
if (counter == 1)<br>
{<br>
cout<<"Enter the postion [ SAY "<<loc<<" ] : ";<br>
cin>>pos;<br>
s = start;<br>
if (pos == 1)<br>
{<br>
start = s->next;<br>
cout<<s->info<<" deleted from first"<<endl;<br>
free(s);<br>
}<br>
else<br>
cout<<"Position out of range...!!!"<<endl;<br>
}<br>
else<br>
{<br>
cout<<"Enter the postion from "<<loc<<" to "<<counter<<" : ";<br>
cin>>pos;<br>
s = start;<br>
if (pos == 1)<br>
{<br>
start = s->next;<br>
cout<<s->info<<" deleted from first"<<endl;<br>
free(s);<br>
}<br>
else if (pos > 1 && pos <= counter)<br>
{<br>
for (i = 1;i < pos;i++)<br>
{<br>
ptr = s;<br>
s = s->next;<br>
}<br>
ptr->next = s->next;<br>
if(pos == counter)<br>
{cout<<s->info<<" deleted from last"<<endl;<br>
free(s);}<br>
else<br>
{cout<<s->info<<" deleted from postion "<<pos<<endl;<br>
free(s);}<br>
}<br>
else<br>
cout<<"Position out of range...!!!"<<endl;<br>
}<br>
}<br>
}<br>
void single_llist::search()<br>
{<br>
int value, loc = 0, pos = 0, counter = 0;<br>
struct node *s;<br>
s = start;<br>
while (s != NULL)<br>
{<br>
s = s->next;<br>
counter++;<br>
}<br>
if (start == NULL){}<br>
else<br>
{<br>
cout<<"Enter the value to be searched : ";<br>
cin>>value;<br>
struct node *s;<br>
s = start;<br>
while (s != NULL)<br>
{<br>
pos++;<br>
if (s->info == value)<br>
{<br>
loc++;<br>
if(loc == 1)<br>
cout<<"Element "<<value<<" is found at position "<<pos;<br>
else if(loc <= counter)<br>
cout<<" , "<<pos;<br>
}<br>
s = s->next;<br>
}<br>
cout<<endl;<br>
if (loc == 0)<br>
cout<<"Element "<<value<<" not found in the list"<<endl;<br>
}<br>
}<br>
void single_llist::display()<br>
{<br>
struct node *temp;<br>
if (start == NULL)<br>
cout<<"Linked list is empty...!!!"<<endl;<br>
else<br>
{<br>
cout<<"Linked list contains : ";<br>
temp = start;<br>
while (temp != NULL)<br>
{<br>
cout<<temp->info<<" ";<br>
temp = temp->next;<br>
}<br>
cout<<endl;<br>
}<br>
}<br>

Program 2:
-------	--------------------------------------------------
2.Write a C++ program to implement doubly linked list.
#include<stdio.h>
	#include<stdlib.h>
	struct node
	{
	struct node *prev;
	struct node *next;
	int data;
	};
	struct node *head;
	void insertion_beginning();
	void insertion_last();
	void insertion_specified();
	void deletion_beginning();
	void deletion_last();
	void deletion_specified();
	void display();
	void search();
	int main ()
	{
	int choice =0;
	while(choice != 9)
	{
	printf("\nChoose one option from the following list ...\n");
	printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");
	printf("\nEnter your choice?\n");
	scanf("\n%d",&choice);
	switch(choice)
	{
	case 1:
	insertion_beginning();
	break;
	case 2:
	insertion_last();
	break;
	case 3:
	insertion_specified();
	break;
	case 4:
	deletion_beginning();
	break;
	case 5:
	deletion_last();
	break;
	case 6:
	deletion_specified();
	break;
	case 7:
	search();
	break;
	case 8:
	display();
	break;
	case 9:
	exit(0);
	break;
	default:
	printf("Please enter valid choice..");
	}
	}
	}
	void insertion_beginning()
	{
	struct node *ptr;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
	printf("\nOVERFLOW");
	}
	else
	{
	printf("\nEnter Item value");
	scanf("%d",&item);
	
	if(head==NULL)
	{
	ptr->next = NULL;
	ptr->prev=NULL;
	ptr->data=item;
	head=ptr;
	}
	else
	{
	ptr->data=item;
	ptr->prev=NULL;
	ptr->next = head;
	head->prev=ptr;
	head=ptr;
	}
	printf("\nNode inserted\n");
	}
	}
	void insertion_last()
	{
	struct node *ptr,*temp;
	int item;
	ptr = (struct node *) malloc(sizeof(struct node));
	if(ptr == NULL)
	{
	printf("\nOVERFLOW");
	}
	else
	{
	printf("\nEnter value");
	scanf("%d",&item);
	ptr->data=item;
	if(head == NULL)
	{
	ptr->next = NULL;
	ptr->prev = NULL;
	head = ptr;
	}
	else
	{
	temp = head;
	while(temp->next!=NULL)
	{
	temp = temp->next;
	}
	temp->next = ptr;
	ptr ->prev=temp;
	ptr->next = NULL;
	}
	}
	printf("\nnode inserted\n");
	}
	void insertion_specified()
	{
	struct node *ptr,*temp;
	int item,loc,i;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
	printf("\n OVERFLOW");
	}
	else
	{
	temp=head;
	printf("Enter the location");
	scanf("%d",&loc);
	for(i=0;i<loc;i++)
	{
	temp = temp->next;
	if(temp == NULL)
	{
	printf("\n There are less than %d elements", loc);
	return;
	}
	}
	printf("Enter value");
	scanf("%d",&item);
	ptr->data = item;
	ptr->next = temp->next;
	ptr -> prev = temp;
	temp->next = ptr;
	temp->next->prev=ptr;
	printf("\nnode inserted\n");
	}
	}
	void deletion_beginning()
	{
	struct node *ptr;
	if(head == NULL)
	{
	printf("\n UNDERFLOW");
	}
	else if(head->next == NULL)
	{
	head = NULL;
	free(head);
	printf("\nnode deleted\n");
	}
	else
	{
	ptr = head;
	head = head -> next;
	head -> prev = NULL;
	free(ptr);
	printf("\nnode deleted\n");
	}
	}
	void deletion_last()
	{
	struct node *ptr;
	if(head == NULL)
	{
	printf("\n UNDERFLOW");
	}
	else if(head->next == NULL)
	{
	head = NULL;
	free(head);
	printf("\nnode deleted\n");
	}
	else
	{
	ptr = head;
	if(ptr->next != NULL)
	{
	ptr = ptr -> next;
	}
	ptr -> prev -> next = NULL;
	free(ptr);
	printf("\nnode deleted\n");
	}
	}
	void deletion_specified()
	{
	struct node *ptr, *temp;
	int val;
	printf("\n Enter the data after which the node is to be deleted : ");
	scanf("%d", &val);
	ptr = head;
	while(ptr -> data != val)
	ptr = ptr -> next;
	if(ptr -> next == NULL)
	{
	printf("\nCan't delete\n");
	}
	else if(ptr -> next -> next == NULL)
	{
	ptr ->next = NULL;
	}
	else
	{
	temp = ptr -> next;
	ptr -> next = temp -> next;
	temp -> next -> prev = ptr;
	free(temp);
	printf("\nnode deleted\n");
	}
	}
	void display()
	{
	struct node *ptr;
	printf("\n printing values...\n");
	ptr = head;
	while(ptr != NULL)
	{
	printf("%d\n",ptr->data);
	ptr=ptr->next;
	}
	}
	void search()
	{
	struct node *ptr;
	int item,i=0,flag;
	ptr = head;
	if(ptr == NULL)
	{
	printf("\nEmpty List\n");
	}
	else
	{
	printf("\nEnter item which you want to search?\n");
	scanf("%d",&item);
	while (ptr!=NULL)
	{
	if(ptr->data == item)
	{
	printf("\nitem found at location %d ",i+1);
	flag=0;
	break;
	}
	else
	{
	flag=1;
	}
	i++;
	ptr = ptr -> next;
	}
	if(flag==1)
	{
	printf("\nItem not found\n");
	}
	}
	}

Program 3:
-------------------------------------------------------------------------------------------------------------------------------
3.Write a C++ program to split the linked list into two halves such that the element ???e??? should be the first element of second list.
#include<iostream>
using namespace std;
struct Node{
int value;
struct Node *next;
};
struct Node* head = NULL;
struct Node* sHead = NULL;
struct Node* temp = NULL;
void insert(int new_data){
struct Node* new_node = new Node(); //(struct Node*)malloc(sizeof(struct Node));
new_node->value = new_data;
new_node->next = head;
head = new_node;
}
int n;
int ele;
int splitIndex;
int main(){
int i;
cout<<"Enter number of elements you want in the list\t";
cin>>n;
cout<<"Enter elements :" <<endl;
for(i=0;i<n;i++){
cin>>ele;
insert(ele);
}
cout<<"\nList of elements : "<<endl;
Node *t;
t = head;
while(t != NULL){
cout<<t->value<<"\t";
t = t->next;
}
cout<<"\n\nEnter the position you want the list to split ";
cin>>splitIndex;
while(splitIndex < 0 || splitIndex > n-1){
cout<<"Invalid position. Try again."<<endl;
cin>>splitIndex;
}
temp = head;
for(i=0;i<=splitIndex;i++){
if(i==splitIndex-1){
Node *tN;
tN = temp->next;
sHead = tN;
temp->next = NULL;
break;
}
temp = temp->next;
}
temp = head;
if(temp == NULL){
cout<<"\nFirst list is empty"<<endl;
}else{
cout<<"\n\nFirst list element "<<endl;
while(temp != NULL){
cout<<temp->value<<"\t";
temp = temp->next;
}
}
temp = sHead;
if(temp == NULL){
cout<<"\nSecond list is empty"<<endl;
}else{
cout<<"\n\nSecond list elements "<<endl;
while(temp != NULL){
cout<<temp->value<<"\t";
temp = temp->next;
}
}
return 0;
}

Program 4:
---------------------------------------------------------------------------------------------------------------------------------
4.Find the subset of a given set S = {S1,S2,S3,?????????,Sn} OF ???n??? positive integers whose sum is equal to a given positive integer d.
#include<iostream>
using namespace std;
int s[10],d,n,set[10],count=0;
void display(int);
int flag = 0;
int main()
{
 int subset(int,int);
 int i;
  cout<<"ENTER THE NUMBER OF THE ELEMENTS IN THE SET : ";
 cin>>n;
 cout<<"ENTER THE SET OF VALUES : ";
 for(i=0;i<n;i++)
   cin>>s[i];
 cout<<"ENTER THE SUM : ";
 cin>>d;
 cout<<"THE PROGRAM OUTPUT IS: ";
 subset(0 , 0);
 if(flag == 0)
 cout<<"There is no solution";
 }
int subset(int sum,int i)
{
if(sum == d)
{
 flag = 1;
 display(count);
 return 0;
}
if(sum>d || i>=n)
return 1;
else
{
 set[count]=s[i];
 count++;
 subset(sum+s[i],i+1);
 count--;
 subset(sum,i+1);
}
}
void display(int count)
{
 int i;
 cout<<"\t{";
 for(i=0;i<count;i++)
 cout<<set[i];
 cout<<"}";
}
	
Program 5:
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
5.Write a program to create a WAP to store a k keys into an array of size n at the location compute using a hash function, loc=key%n, where k<=n and key takes values from [1 to m], m>n. Handle the collision using Linear Probing technique.
#include <bits/stdc++.h>

using namespace std;

void Insert(int ary[],int hFn, int Size)

{

int element,pos,n=0;

cout<<"Enter key element to insert\n";

cin>>element;

pos = element%hFn;

while(ary[pos]!= INT_MIN)

{

if(ary[pos]== INT_MAX)

break;

pos = (pos+1)%hFn;

n++;

if(n==Size)

break;

}

if(n==Size)

cout<<"Hash table was full of elements\nNo Place to insert this element\n\n";

else

ary[pos] = element;    //Inserting element

}



void Delete(int ary[],int hFn,int Size)

{

int element,n=0,pos;

cout<<"Enter element to delete\n";

cin>>element;

pos = element%hFn;

while(n++ != Size)

{

if(ary[pos]==INT_MIN)

{

cout<<"Element not found in hash table\n";

break;

}

else if(ary[pos]==element)

{

ary[pos]=INT_MAX;

cout<<"Element deleted\n\n";

break;

}

else

{

pos = (pos+1) % hFn;

}

}

if(--n==Size)

cout<<"Element not found in hash table\n";

}

void Search(int ary[],int hFn,int Size)

{

int element,pos,n=0;

cout<<"Enter element you want to search\n";

cin>>element;

pos = element%hFn;

while(n++ != Size)

{

if(ary[pos]==element)

{

cout<<"Element found at index "<<pos<<"\n";

break;

}

else if(ary[pos]==INT_MAX ||ary[pos]!=INT_MIN)

pos = (pos+1) %hFn;

}

if(--n==Size)

cout<<"Element not found in hash table\n";

}

void display(int ary[],int Size)

{

int i;

cout<<"Index\tValue\n";

for(i=0;i<Size;i++)

cout<<i<<"\t"<<ary[i]<<"\n";

}



int main()

{

int Size,hFn,i,choice;

cout<<"Enter size of hash table\n";

cin>>Size;

int ary[Size];

cout<<"Enter hash function [if mod 10 enter 10]\n";

cin>>hFn;

for(i=0;i<Size;i++)

ary[i]=INT_MIN;

do

{

cout<<"Enter your choice\n";

cout<<" 1-> Insert\n 2-> Delete\n 3-> Display\n 4-> Searching\n 0-> Exit\n";

cin>>choice;

switch(choice)

{

case 1:	Insert(ary,hFn,Size);

break;

case 2:	Delete(ary,hFn,Size);

break;

case 3:	display(ary,Size);

break;

case 4:	Search(ary,hFn,Size);

break;

default:cout<<"Enter correct choice\n";

break;

}

}while(choice);

return 0;

}

Program 6:
-----------------------------------------------------------------------
6.Write a program to Insert into and Delete from a Binary Search Tree.
#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node*left;
	struct node*right;
}*root;
class BST 
{ 
 public: 
 void insert(node *, node *); 
 void inorder(node *); 
 void postorder(node *); 
 void display(node *, int); 
 BST() 
 { 
 root = NULL; 
 } 
};
int main() 
{ 
 int choice, num; 
 BST bst; 
 node *temp; 
 while (1) 
 { 
cout<<"1.Insert Element "<<endl; 
 cout<<"2.Inorder Traversal"<<endl;  
 cout<<"3.Display"<<endl; 
 cout<<"4.Quit"<<endl; 
 cout<<"Enter your choice : "; 
 cin>>choice; 
 switch(choice) 
 { 
 case 1: 
 temp = new node; 
 cout<<"Enter the number to be inserted : "; 
 cin>>temp->info; 
 bst.insert(root, temp); 
 break;  
 case 2: 
 cout<<"Inorder Traversal of BST:"<<endl; 
 bst.inorder(root); 
 cout<<endl; 
 break; 
 case 3: 
 cout<<"Display BST:"<<endl; 
 bst.display(root,1); 
 cout<<endl; 
 break; 
 case 4: 
 exit(1); 
 default: 
 cout<<"Wrong choice"<<endl; 
 } 
 } 
} 
void BST::insert(node *tree, node *newnode) 
{ 
 if (root == NULL) 
 { 
 root = new node; 
 root->info = newnode->info; 
 root->left = NULL; 
 root->right = NULL; 
 cout<<"Root Node is Added"<<endl; 
 return; 
 } 
 if (tree->info == newnode->info) 
 { 
 cout<<"Element already in the tree"<<endl; 
 return; 
 } 
 if (tree->info > newnode->info) 
{ 
 if (tree->left != NULL) 
 { 
 insert(tree->left, newnode); 
 } 
 else 
 { 
 tree->left = newnode; 
 (tree->left)->left = NULL; 
 (tree->left)->right = NULL; 
 cout<<"Node Added To Left"<<endl; 
 return; 
 } 
 } 
 else 
 { 
 if (tree->right != NULL) 
 { 
 insert(tree->right, newnode); 
 } 
 else 
 { 
 tree->right = newnode; 
 (tree->right)->left = NULL; 
 (tree->right)->right = NULL; 
 cout<<"Node Added To Right"<<endl; 
 return; 
 } 
 } 
} 
void BST::inorder(node *ptr) 
{ 
 if (root == NULL) 
 { 
 cout<<"Tree is empty"<<endl; 
 return; 
 } 
 if (ptr != NULL) 
 { 
 inorder(ptr->left); 
 cout<<ptr->info<<" "; 
 inorder(ptr->right); 
 } 
} 
void BST::display(node *ptr, int level) 
{ 
 int i; 
 if (ptr != NULL) 
 { 
 display(ptr->right, level+1); 
 cout<<endl; 
 if (ptr == root) 
 cout<<"Root->: "; 
 else 
 { 
 for (i = 0;i < level;i++) 
 cout<<" "; 
 } 
 cout<<ptr->info; 
 display(ptr->left, level+1); 
 } 
}

Program 7:
----------------------------------------------------------------------------------------
7.Finding minimum and maximum from given unsorted array by using divide conquer method.
#include <iostream>
using namespace std;
void MinMax(int arr[], int low, int high, int &min, int &max)
{
if (low == high)
{
if (max < arr[low]) {           // comparison 1
max = arr[low];
}

if (min > arr[high]) {          // comparison 2
min = arr[high];
}
return;
}
if (high - low == 1)
{
if (arr[low] < arr[high])
{
if (min > arr[low])
{
min = arr[low];
}
if (max < arr[high])
{
max = arr[high];
}
}
else
{
if (min > arr[high])
{
min = arr[high];
}
if (max < arr[low])
{
max = arr[low];
}
}
return;
}
int mid = (low + high) / 2;
MinMax(arr, low, mid, min, max);
MinMax(arr, mid + 1, high, min, max);
}
int main()
{
int i, n, arr[50];
cout<<"Enter the number of elements : ";
cin>>n;
for( i = 0; i < n; i++ )
{
cout<<"Enter the element : ";
cin>>arr[i];
}
int max = arr[0], min = arr[0];
MinMax(arr, 0, n - 1, min, max);
cout<<"The minimum array element is "<<min<<endl;
cout<<"The maximum array element is "<<max;
}
	
Program 8:
------------------------------------------------------------------
8.Create a program to merge sort using divide and conquer array.
#include <iostream>
using namespace std;
// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
// We have low to mid and mid+1 to high already sorted.
int i, j, k, temp[high-low+1];
i = low;
k = 0;
j = mid + 1;
// Merge the two parts into temp[].
while (i <= mid && j <= high)
{
if (a[i] < a[j])
{
temp[k] = a[i];
k++;
i++;
}
else
{
temp[k] = a[j];
k++;
j++;
}
}
// Insert all the remaining values from i to mid into temp[].
while (i <= mid)
{
temp[k] = a[i];
k++;
i++;
}
// Insert all the remaining values from j to high into temp[].
while (j <= high)
{
temp[k] = a[j];
k++;
j++;
}
// Assign sorted data stored in temp[] to a[].
for (i = low; i <= high; i++)
{
a[i] = temp[i-low];
}
}
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
int mid;
if (low < high)
{
mid=(low+high)/2;
// Split the data into two half.
MergeSort(a, low, mid);
MergeSort(a, mid+1, high);
// Merge them to get sorted output.
Merge(a, low, high, mid);
}
}
int main()
{
int n, i;
cout<<"\nEnter the number of data element to be sorted: ";
cin>>n;
int arr[n];
for(i = 0; i < n; i++)
{
cout<<"Enter element : ";
cin>>arr[i];
}
MergeSort(arr, 0, n-1);
// Printing the sorted data.
cout<<"\nSorted Data ";
for (i = 0; i < n; i++)
cout<<"->"<<arr[i];
return 0;
}

Program 9:
---------------------------------------------------------------------------
9.Write a C++ program for solving the N-Queen???s Problem using backtracking.
#include<iostream>
using namespace std;
int grid[10][10];
//print the solution
void print(int n) {
for (int i = 0;i <= n-1; i++) {
for (int j = 0;j <= n-1; j++) {
cout <<grid[i][j]<< " ";
}
cout<<endl;
}
cout<<endl;
cout<<endl;
}
//function for check the position is safe or not
//row is indicates the queen no. and col represents the possible positions
bool isSafe(int col, int row, int n) {
//check for same column
for (int i = 0; i < row; i++) {
if (grid[i][col]) {
return false;
}
}
//check for upper left diagonal
for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
if (grid[i][j]) {
return false;
}
}
//check for upper right diagonal
for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
if (grid[i][j]) {
return false;
}
}
return true;
}
//function to find the position for each queen
//row is indicates the queen no. and col represents the possible positions
bool solve (int n, int row) {
if (n == row) {
print(n);
return true;
}
//variable res is use for possible backtracking
bool res = false;
for (int i = 0;i <=n-1;i++) {
if (isSafe(i, row, n)) {
grid[row][i] = 1;
//recursive call solve(n, row+1) for next queen (row+1)
res = solve(n, row+1) || res;//if res ==false then backtracking will occur
//by assigning the grid[row][i] = 0
grid[row][i] = 0;
}
}
return res;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cout<<"Enter the number of queen"<<endl;
cin >> n;
for (int i = 0;i < n;i++) {
for (int j = 0;j < n;j++) {
grid[i][j] = 0;
}
}
bool res = solve(n, 0);
if(res == false) {
cout << -1 << endl; //if there is no possible solution
} else {
cout << endl;
}
return 0;
}

Program 10:
--------------------------------------------------------------------------------
10.Write a program to implement breadth first search for undirected graph (BFS).
#include<iostream>
#include <list>
 using namespace std;
 // This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;  
public:
Graph(int V);  // Constructor
  // function to add an edge to graph
void addEdge(int v, int w);
  // prints BFS traversal from a given source s
    void BFS(int s); 
};
 Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v???s list.
}
 void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
  // Create a queue for BFS
    list<int> queue;
  // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
         // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
	if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 // Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 cout << "Following is Breadth First Traversal "<< "(starting from vertex 2) \n";
    g.BFS(2);
 return 0;
}

Program 11:
-----------------------------------------------------------------------------
11.Write a program to implement depth first search for undirected graph (DFS).
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
map<int, bool> visited;
map<int, list<int>> adj;
void addEdge(int v, int w);
void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
adj[v].push_back(w);
adj[w].push_back(v);
}
void Graph::DFS(int v)
{
visited[v] = true;
cout << v << " ";
list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i)
if (!visited[*i])
DFS(*i);
}
int main()
{
Graph g;
g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 2);
g.addEdge(2, 0);
g.addEdge(2, 3);
g.addEdge(3, 3);
cout << "Following is Depth First Traversal"
" (starting from vertex 2) \n";
g.DFS(2);
return 0;
}
12.Write a program to implement Min Heap.
#include <iostream>
#include <conio.h>
using namespace std;
void min_heap(int *a, int m, int n){
int j, t;
t= a[m];
j = 2 * m;
while (j <= n) {
if (j < n && a[j+1] < a[j])
j = j + 1;
if (t < a[j])
break;
else if (t >= a[j]) {
a[j/2] = a[j];
j = 2 * j;
}
}
a[j/2] = t;
return;
}
void build_minheap(int *a, int n) {
int k;
for(k = n/2; k >= 1; k--) {
min_heap(a,k,n);
}
}
int main() {
int n, i;
cout<<"enter no of elements of array\n";
cin>>n;
int a[30];
for (i = 1; i <= n; i++) {
cout<<"enter element"<<" "<<(i)<<endl;
cin>>a[i];
}
build_minheap(a, n);
cout<<"Min Heap\n";
for (i = 1; i <= n; i++) {
cout<<a[i]<<endl;
}
getch();
}

13.Write a program to implement Max Heap Sort.
#include <iostream>
using namespace std;
void max_heap(int *a, int m, int n) {
int j, t;
t = a[m];
j = 2 * m;
while (j <= n) {
if (j < n && a[j+1] > a[j])
j = j + 1;
if (t > a[j])
break;
else if (t <= a[j]) {
a[j / 2] = a[j];
j = 2 * j;
}
}
a[j/2] = t;
return;
}
void build_maxheap(int *a,int n) {
int k;
for(k = n/2; k >= 1; k--) {
max_heap(a,k,n);
}
}
int main() {
int n, i;
cout<<"enter no of elements of array\n";
cin>>n;
int a[30];
for (i = 1; i <= n; i++) {
cout<<"enter elements"<<" "<<(i)<<endl;
cin>>a[i];
}
build_maxheap(a,n);
cout<<"Max Heap\n";
for (i = 1; i <= n; i++) {
cout<<a[i]<<endl;
}
}

