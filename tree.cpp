#include<iostream>
using namespace std;
class node
{
	int data;
	node *right,*left,*next;
	
	public:node(int n)
		   {
		   		data=n;
		   		right=left=NULL;
		   		next=NULL;
		   }
		   friend class tree;
		   friend class stklist;	
};
class tree
{
	node *root;
	public:tree()
		   {
		   	 root=NULL;
		   }
		   void create();
		   void rec_preorder();
		   void rec_preorder(node*);
		   void rec_inorder();
		   void rec_inorder(node*);
		   void rec_postorder();
		   void rec_postorder(node*);
		   void insert();
		   void preorder();
		   void inorder();
		   void postorder();
		   void copy(tree &);
		   node* copy(node *);
		   void mirror(tree &);
		   node* mirror(node *);
		   
		   
};
class stklist
{
	node* top;
	public:stklist()
		   {
		   	  top=NULL;
		   }  
		   void push(node*);
		   node *pop();
		   node *peek();
		   int Isempty();
		
}s;
void tree::create()
{
	int i,n,dt;
	char ch,choice;
	node *temp=root;
	do
	{
		cout<<"\n Enter data : ";
		cin>>dt;
		node *newnode=new node(dt);
		if(root==NULL)
			root=temp=newnode;
		else
		{
			temp=root;
			while(2)
			{
				cout<<"\n Enter l for left OR r for right of "<<temp->data<<" ";
				cin>>ch;
				if(ch=='l')
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
						temp=temp->left;
				}
				else if(ch=='r')
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						break;
					}
					else
						temp=temp->right;
				}
			}
		}
		cout<<"\n Any more node? ";
		cin>>choice;	
	}while(choice=='y' || choice=='Y');
}
void tree::rec_preorder()
{
	rec_preorder(root);
}
void tree::rec_preorder(node *currnode)
{
	if(currnode!=NULL)
	{
		cout<<currnode->data<<" ";      /*V*/
		rec_preorder(currnode->left);  /*L*/
		rec_preorder(currnode->right); /*R*/
	}
}
void tree::rec_inorder()
{
	rec_inorder(root);
}
void tree::rec_inorder(node *currnode)
{
	if(currnode!=NULL)
	{
		rec_inorder(currnode->left);      /*L*/
		cout<<currnode->data<<" "; 		/*V*/
		rec_inorder(currnode->right); /*R*/
	}
}
void tree::rec_postorder()
{
	rec_postorder(root);
}
void tree::rec_postorder(node *currnode)
{
	if(currnode!=NULL)
	{
		rec_postorder(currnode->left);     /*L*/
		rec_postorder(currnode->right);  /*R*/
		cout<<currnode->data<<" "; 	   /*V*/
	}
}
void tree::preorder()
{
	node *temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			s.push(temp);
			temp=temp->left;	
		}
		if(s.Isempty())
			break;
		temp=s.pop();	
		temp=temp->right;
	}
}
void tree::inorder()
{
	node *temp=root;
	while(1)
	{
		while(temp!=NULL)
		{	
			s.push(temp);
			temp=temp->left;	
		}
		if(s.Isempty())
			break;
		temp=s.pop();
		cout<<temp->data<<" ";	
		temp=temp->right;
	}
}
void tree::postorder()
{
	node *temp=root;
	node *prev=NULL;
	s.push(temp);
	while(2)
	{
		if(s.Isempty())
			break;
		temp=s.peek();
		if(!prev || prev->left==temp || prev->right==temp)
		{
			if(temp->left!=NULL)
				s.push(temp->left);
			else if(temp->right!=NULL)
				s.push(temp->right);
			else
			{
				cout<<temp->data<<" ";
				temp=s.pop();
			}			
		}
		else if(temp->left==prev)
		{
			if(temp->right!=NULL)
				s.push(temp->right);
			else
			{
				cout<<temp->data<<" ";
				temp=s.pop();
			}	
		}
		else if(temp->right==prev)
		{
			cout<<temp->data<<" ";
			temp=s.pop();
		}		
		prev=temp;	
	}
}
int stklist::Isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;	
}
void stklist::push(node *newnode)
{
	if(top==NULL)
		top=newnode;
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
node *stklist::pop()
{
	node* temp=s.top,*temp1=NULL;
	if(Isempty())
	{
		return NULL;
	}
	else
	{
		temp1=temp;
		temp=temp->next;
		top=temp;
		return temp1;
		delete temp1;
	}
}
node* stklist::peek()
{
	if(Isempty())
		return NULL;
	else
		return top;		
}
void tree::insert()
{
	int i,n,dt;
	char ch,choice;
	node *temp=root;
	cout<<"\n Enter data : ";
	cin>>dt;
	node *newnode=new node(dt);		
	if(root==NULL)
		root=temp=newnode;
	else
	{
		temp=root;
		while(2)
		{
			cout<<"\n Enter l for left OR r for right of "<<temp->data<<" ";
			cin>>ch;
			if(ch=='l')
			{
				if(temp->left==NULL)
				{
					temp->left=newnode;
					break;
				}
				else
					temp=temp->left;
			}
			else if(ch=='r')
			{
				if(temp->right==NULL)
				{
					temp->right=newnode;
					break;
				}
				else
					temp=temp->right;
			}
		}
	}
}
void tree::copy(tree &t)
{
	t.root=copy(root);
}
node* tree::copy(node *root)
{
	node *root1;
	if(root!=NULL)
	{
		root1=new node(root->data);
		root1->left=copy(root->left);
		root1->right=copy(root->right);
		return root1;
	}
}
void tree::mirror(tree &t)
{
	t.root=mirror(root);
}
node* tree::mirror(node *root)
{
	node *root1;
	if(root!=NULL)
	{
		root1=new node(root->data);
		root1->left=copy(root->right);
		root1->right=copy(root->left);
		return root1;
	}
}
main()
{
	tree lt,lt1;
	int z;
	while(2)
	{
		cout<<"\n Enter the choice : \n 1.Create \n 2.Recursive Preorder \n 3.Recursive Inorder \n 4.Recursive Postorder \n 5.Insert \n 6.Preorder \n 7.Inorder \n 8.Postorder \n 9.Copy \n 10.Mirror \n";
		cin>>z;
		switch(z)
		{
			case 1:lt.create();
				   break;
		 	case 2:lt.rec_preorder();
		 	 	   break;
		 	case 3:lt.rec_inorder();
			       break;
			case 4:lt.rec_postorder();
			       break;	    	   
		 	case 5:lt.insert(); 
			       break;
			case 6:lt.preorder();
			       break;   
			case 7:lt.inorder();
				   break; 
			case 8:lt.postorder();
				   break;	  
			case 9:lt.copy(lt1);
				   lt1.rec_inorder();
				   break;
			case 10:lt.mirror(lt1);
			  		lt1.rec_inorder();
				    break;   	      
		}
	}
}
