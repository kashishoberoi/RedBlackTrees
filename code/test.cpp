#include"rb_tree.h"
#include <iostream>
using namespace std;


int main()
{
	rb_tree<char> t1,t2;
	int ch=1;
	do
	{
		cout<<"Enter value:"<<endl;
		char val;
		cin>>val;
		t1.insert(val);
		//t1.print();
		t1.inorder_print(t1.root);
		cout<<"Do you want to continue? Y(1)/N(0)";
		cin>>ch;
	}while(ch==1);
}
