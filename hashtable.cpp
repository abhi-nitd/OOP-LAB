#include<iostream>

using namespace std;
class sllnode
{
	public:
	int info;
	sllnode* next;
	
	sllnode(void)
	{
	info=0;
	next=NULL;
	cout<<"Constructor 1 node"<<endl;
	}	
	sllnode(int x,sllnode *p)
	{
		info=x;
		next=p;
		cout<<"Constructor 2 node"<<endl;
	}
	~sllnode()
	{
		cout<<"sllnode desctructor "<<endl;
	}
};
class sllist
{
public:
	sllnode * head;
	int lncount;
	sllist(void)
	{
		head=NULL;
		lncount=0;
		cout<<"Constructor 1 list"<<endl;
	}
	sllist(sllnode *p,int n)
	{
		lncount=n;
		head=p;
		cout<<"Constructor 2 list"<<endl;
	}
	void insbeg(int x);
	int delbeg(void);
	int search(int x);
	void dispsll(void);
	~sllist();
};

class hash_table
{
public:
	 sllist *ht;
	 int htsize;
	 //int iterator;
	 hash_table(int t)
	 {
	 	ht=new sllist[t];
	 	htsize=t;
	 }
	void inshash(int x)	 
	{
		int pos=x%htsize;
		ht[pos].insbeg(x);
	}
	void searchhash(int x)
	{
		int pos=x%htsize;
		//cout<<pos<<endl;
		int p=ht[pos].search(x);
		if (p==-1)
		{
			cout<<"Not Found"<<endl;
		}
		else
		{
			cout<<"found at index "<<pos<<" element number "<<p<<endl;
		}
	}
	~hash_table()
	{
		
			if (ht!=NULL)
			delete []ht;
			
		cout<<"hash_table desctructor"<<endl;
	}

};
void sllist::insbeg(int x)
{
	head=new sllnode(x,head);
	lncount++;
}
int sllist:: delbeg(void)
{
	sllnode *a=head;
	head=head->next;
	int n=a->info;
	delete []a;
	lncount--;
	return n;
}
int sllist::search(int x)
{
	int cnt;
	cnt=0;
	sllnode *t=head;
	while(t!=NULL)
	{
		cnt++;
		if(t->info==x)
		{
			return cnt;
		}
			t=t->next;
		
	}
	return -1;
}
sllist::~sllist()
{
	//while(head !=NULL)
	//{
		//delbeg();
	cout<<"The list destructor"<<endl;
	sllnode *p=head;
	while(p!=NULL)
	{
		head=p->next;
		delete p;
		p=head;
	}

}
void sllist:: dispsll()
{
	sllnode *t=head;
	cout<<"["<<lncount<<"]";
	while(t!=NULL)
	{
		cout<<"->"<<t->info;	
		t=t->next;
	}
	cout<<endl;

}


int main(void)
{
	int size;
	cout<<"Enter the size of hash_table"<<endl;
	cin>>size;
	hash_table h(size);
	int n;
	cout<<"enter the nunmber of inputs"<<endl;
	cin>>n;
	int x;
	cout<<"enter the numbers"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		h.inshash(x);
	}
	cout<<"input complete"<<endl;
	int ct;
	cout<<"enter the number of searches"<<endl; 
	cin>>ct;
	for(int i=0;i<ct;i++)
	{
		cout<<"enter the number to be searched"<<endl;
		cin>>x;
		h.searchhash(x);
	}
	for(int i=0;i<h.htsize;i++)
	{
		cout<<"["<<i<<"]"<<"->";
		h.ht[i].dispsll();
	}
	return 0;
}