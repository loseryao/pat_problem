//----------------------------------------------------------2015-4-10--------------------------------------------------------------------
//----------------------------------------------------------list×ÔÊµÏÖ-------------------------------------------------------------------
#include<iostream>
#include<list>
#include<cstdlib>
#include<string>
using namespace std;
typedef struct node
{
	char x;
	node *next;
}node;
class mylist
{
private:
	node *head = new node;
	int length = 0;
	node *r = head;
	void insert(node *n);
public:
	char get(int i);
	int push_back(char c);
	bool empty();
	int push_front(char c);
	void pop_back();
	void pop_front();
	void sort();
	node* begin();
	node* end();
	int size();
	void print();
};
int mylist::push_back(char c)
{

	node *newnode = new node();
	newnode->x = c;
	newnode->next = 0;
	r->next = newnode;
	r = newnode;
	length++;
	return length;
}
void mylist::print()
{
	node* begin = head->next;
	while (begin)
	{
		cout << begin->x << " ";
		begin = begin->next;
	}
}
int mylist::size()
{
	return length;
}
node* mylist::begin()
{
	return head->next;
}
node* mylist::end()
{
	return r;
}
bool mylist::empty()
{
	if (length == 0)return true;
	else return false;
}
void mylist::pop_back()
{
	delete r;
	length--;
}
char mylist::get(int i)
{
	node *s = head;
	int j = 1;
	if (length < i)return -1;
	while (j != i + 1)
	{

		s = s->next;
		j++;
	}
	return s->x;
}
void mylist::sort()
{
	node* i = head->next;
	node* j;
	int count = 0;
	while (i)
	{
		j = head->next;
		while (j)
		{
			if (i->x < j->x)
			{

				int temp = i->x;
				i->x = j->x;
				j->x = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
int mylist::push_front(char c)
{
	node *l = head;
	node *newnode = new node();
	newnode->x = c;
	newnode->next = head->next;
	head->next = newnode;
	length++;
	return length;


}
void mylist::pop_front()
{
	node *l = head->next;
	head->next = head->next->next;
	delete l;
	length--;
}
int main()
{
	mylist mylis;
	mylis.push_back('1');
	mylis.push_back('3');
	mylis.push_back('2');
	mylis.push_front('4');
	string s;
	for (int i = 0; i < 10000; i++)
	{
		s += (rand() % 10 + '0');

	}
	for (int i = 0; i < s.length(); i++)
	{
		mylis.push_back(s[i]);
	}
	mylis.print();
	mylis.sort();
	mylis.print();

}

