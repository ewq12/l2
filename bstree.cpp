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
		   friend class queuelist;	
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
		   void deleteNode(int);
		   void countNodes();
		   int countNodes(node*);
		   void countleafNodes();
		   int countleafNodes(node*);
		   void search(int);
		   node *search(node*,int);
		   
		   
};
class queuelist
{
	node *front,*rear;
	public:queuelist()
		   {
		   	  front=rear=NULL;
		   }  
		   void enqueue(node*);
		   node *dequeue();
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
				if(dt<temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
						temp=temp->left;
				}
				else if(dt>temp->data)
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
void tree::countNodes()
{
	int count=countNodes(root);
	cout<<"Total no. of nodes : "<<count;
}
int tree::countNodes(node *temp)
{
	static int count=0;
	if(temp!=NULL)
	{
		count++;
		countNodes(temp->left);
		countNodes(temp->right);
	}
	return count;
}
void tree::countleafNodes()
{
	int count=countleafNodes(root);
	cout<<"No. of leaf nodes : "<<count;
}
int tree::countleafNodes(node *temp)
{
	static int countLeaf=0;
	if(temp==NULL)
		return countLeaf;
	if(temp->left==NULL && temp->right==NULL)
		return ++countLeaf;
	countleafNodes(temp->left);
	countleafNodes(temp->right);		
}
void tree::search(int n)
{
	node *temp=search(root,n);
	if(temp!=NULL)
		cout<<"Element Found";
	else
		cout<<"Element Not Found";	
}
node* tree::search(node *temp,int n)
{
	if(temp!=NULL)
	{
		if(temp->data==n)
			return temp;
		if(n<temp->data)
		{
			return search(temp->left,n);
		}
		else if(n>temp->data)
		{
			return search(temp->right,n);
		}
	}
	return NULL;
}
void tree::deleteNode(int n)
{
	node *temp=root,*parent=NULL,*father,*r,*son;
	while((temp->data!=n) && (temp!=NULL))
	{
		if(n<temp->data)
		{
			parent=temp;
			temp=temp->left;
		}
		else if(n>temp->data)
		{
			parent=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		cout<<"\nNumber Not Found";
		return;
	}
	if(temp->left==NULL)
	{
		r=temp->right;
	}
	else if(temp->right==NULL)
	{
		r=temp->left;
	}
	else
	{
		father=temp;
		r=father->right;
		son=r->left;
		while(son!=NULL)
		{
			father=r;r=son;son=r->left;
		}
		if(father!=temp)
		{
			father->left=r->right;
			r->right=temp->right;
		}
		r->left=temp->left;
	}
	if(parent==NULL)
		root=r;
	else
	{
		if(temp==parent->left)
			parent->left=r;
		else
			parent->right=r;	
	}
	delete temp;	
}
int queuelist::Isempty()
{
	if(front==NULL && rear==NULL)
		return 1;
	else
		return 0;	
}
void queuelist::enqueue(node *newnode)
{
	if(Isempty())
		front=rear=newnode;
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
node *queuelist::dequeue()
{
	node* temp=front,*temp1=NULL;
	if(Isempty())
	{
		return NULL;
	}
	else
	{
		temp1=temp;
		temp=temp->next;
		front=temp;
		temp=temp1;
		delete temp1;
		return temp;		
	}
}
/*void tree::displaylevel()
{
	
}*/
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
			if(dt<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=newnode;
					break;
				}
				else
					temp=temp->left;
			}
			else if(dt>temp->data)
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
main()
{
	tree lt,lt1;
	int z,ele;
	while(2)
	{
		cout<<"\n Enter the choice : \n 1.Create \n 2.Recursive Preorder \n 3.Recursive Inorder \n 4.Recursive Postorder \n 5.Insert \n 6.Delete \n 7.Search \n";
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
			case 6:cout<<"\n Enter the number you want to delete : ";
				   cin>>ele;
				   lt.deleteNode(ele);
				   break;	
			case 7:cout<<"\n Enter the number to be searched : ";
				   cin>>ele;
				   lt.search(ele);
				   break;  	   	 	      
		}
	}
}
