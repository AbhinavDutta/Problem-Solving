#include <bits/stdc++.h>
using namespace std;
//implemented using pointers instead of linked lists
class node
{
	public:
	int data;
	node* left;	node* right; node* up;
	node()
	{
		left=right=up=nullptr;
		data=-1e9;
	}
};
class heap
{
	public:
	node* top;	int size;
	deque<node*> q;
	heap()
	{
		top=nullptr;
		size=0;
		q.clear();
	}
	void showq()
	{
		for(auto x:q)
		{
			cout<<x->data<<" ";
		}
		cout<<endl;
	}
	void add(int x)
	{
		size++;
		node* curr=new node;	curr->data=x;
		if(q.size()==0)
		{
			top=curr;
			q.push_back(top);
		}
		else
		{
			node* leaf=q.front();
			curr->up=leaf;
			q.push_back(curr);
			if(leaf->left==nullptr)
			{
				leaf->left=curr;	
				if(leaf->right!=nullptr)
				q.pop_front();
			}
			else if(leaf->right==nullptr)
			{
				leaf->right=curr;	
				if(leaf->left!=nullptr)
				q.pop_front();
			}
			siftup(curr);
		}
	}
	void pop()
	{
		assert(size>0);	size--;
		if(size==0)  //the last element cannot be deleted with usual logic
		{
			delete(top);
			return;
		}
			
		node* leaf=q.back();	q.pop_back();
		top->data=leaf->data;
		node* par=leaf->up;  //not valid if leaf is the top node
		if(par->left==leaf)
		{
			par->left=nullptr;
			if(par->right!=nullptr)
			q.push_front(par);
		}
		else
		{
			par->right=nullptr;
			if(par->left!=nullptr)
			q.push_front(par);
		}
		delete(leaf);
		siftdown(top);
	}

	int gettop()
	{
		assert(size>0);
		return top->data;
	}		
		
	void siftup(node* curr)
	{
		if(curr->up==nullptr)
		return;
		if(curr->data > curr->up->data)
		{
			int tmp=curr->data;
			curr->data=curr->up->data;
			curr->up->data=tmp;
			siftup(curr->up);
		}
	}
	void siftdown(node* curr)
	{
		bool done=false;
		if(curr->left!=nullptr)
		{
			done=true;
			if(curr->left->data>curr->data)
			{
				int tmp=curr->left->data;
				curr->left->data=curr->data;
				curr->data=tmp;
				siftdown(curr->left);
			}
		}
		else if(curr->right!=nullptr&&!done)
		{
			if(curr->right->data>curr->data)
			{
				int tmp=curr->right->data;
				curr->right->data=curr->data;
				curr->data=tmp;
				siftdown(curr->right);
			}
		}
	}
	void show_as_tree(node*  itr)
	{
		if(itr==nullptr)
		return;
		cout<<itr->data<<" ";
		if(itr->left!=nullptr)
		cout<<itr->left->data<<" ";
		if(itr->right!=nullptr)
		cout<<itr->right->data;
		cout<<endl;
		show_as_tree(itr->left);
		show_as_tree(itr->right);
	}
};

int main()
{
	heap h;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		h.add(x);
	}
	while(h.size>0)
	{
		cout<<h.gettop()<<" ";
		h.pop();
	}
}
	
