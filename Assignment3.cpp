#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

class Container
{
	public:
		Container()
		{
			container = 0;
		}

		//copy constructor
		Container(const Container &c)
		{
			container = c.container;
		}

		//move constructor
		Container(Container &&c)
		{
			container = c.container;
			c.container = 0;
		}

		~Container(){}

		//copy destructor
		//~Container(const Container &c){}

		//move destructor
		//~Container(Container &&c){}

		void set(int input)
		{
			container = input;
		}

		int get()
		{
			return container;
		}

	private:
		int container;
};

int main()
{
	Container *c1 = new Container();
	c1->set(4);
	Container *c2 =	new Container();
	c2->set(100);
	Container *c3 = new Container();
	c3->set(76);
	Container *c4 =	c1;
	Container *c5 = c2;
	Container *c6 = new Container();
	c6->set(55);
	Container *c7 = new Container();
	c7->set(33);

	Container *array[] = {c1, c2, c3, c4, c5, c6, c7};
	vector<Container> v (array, array+7);

	vector<Container>::iterator it = find_if(v.begin(), v.end(), [](Container it)->bool{return it.get()>76;});
	cout<<it->get()<<endl;
	return 0;
}
