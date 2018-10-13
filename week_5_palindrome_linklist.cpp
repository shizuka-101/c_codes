//Link List check a palindrome week 5

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

struct Node
{
	char data;
	struct Node* next;
};

Node* create_node(char d)
{
		cout<<"hi";
		Node* pntr;
		
		//temp_node = new Node;
		pntr= (Node *) malloc(sizeof(Node));
		if(!pntr)
			{
				cout<<"Cannot create new node\n";
				return NULL;
			}
		else
		{
			pntr->data =d;
			pntr->next = NULL;
			return pntr;
		}
}
Node* insert_link_list(Node *head, Node* tmp)
{
	 if(tmp==NULL)
	 {
		 return head;
	 }
	 else
	 if(head==NULL)
	 {
		 head=tmp;
	 }
	 else
	 {
		 Node *ptr =  head;
		 while(head->next!=NULL)
		 {
			 head=head->next;
		 }
		 head->next = ptr;
	 }
	 
	 return head;
}

Node* reverse_ll(Node *ptr)
{
	Node *previous, *current, *next_ptr;
	
	previous = NULL;
	current = ptr;
	
	
	while(current !=NULL)
	{
		next_ptr = current->next;
		current->next = previous;
		previous = current;
		current = next_ptr;
	}
	return previous;
}

bool isPalindrome(Node *head)
{
	if(head == NULL)
		return false;
	else
	{
		Node* temp=reverse_ll(head);
		
		while(head&&temp)
		{
			if(head->data == temp->data)
			{
				head=head->next;
				temp=temp->next;
			}
			else
			return false;
		}
	}
	return true;
}
int main()
{
	Node* head;
	string temp;
	
	cout<<"Enter the data and 1 to terminate the input";
	cin>>temp;
	
	int len = temp.length();
	int i=0;
	
	cout<<"length of string is :"<<len;
	
	while(i<len)
	{
		Node* tmp = create_node(temp[i]);
		if(tmp==NULL)
			{
				cout<<"BUFFER OVERFLOW....";
				return 0;
			}
		head = insert_link_list(head,tmp);
		++i;
	}
	
	if(isPalindrome(head))
		cout<<"Link List is palindrome\n";
	else
		cout<<"Not a palindrome \n";
		
	return 0;
}
