#include<iostream>
using namespace std;

class Property
{
	public:
		//normal constructor
		Property(std::string a, double s) : address(a), sourface(s){}

		//copy constructor
		Property(const Property &p)
		{
			address = p.address;
			sourface = p.sourface;
		}
	
		//deconstructor
		virtual ~Property()
		{
			std::cout<<"Property deleted\n";
		}

		//abstract method
		virtual double totalAmount() = 0;
		double getSourface()
		{
			return sourface;
		}
		std::string getAddress()
		{
			return address;
		}
		void getInfo()
		{
			std::cout<<"Adress: "<<getAddress()<<" Total Amount: "<<totalAmount()<<endl;
		}

	private:
		std::string address;
		double sourface;
};

class PlotOfLand : public Property
{
	public:
		//normal constructor
		PlotOfLand(std::string a, double s, int r) : Property(a,s), category(r) {}

		//copy constructor
		PlotOfLand(const PlotOfLand &p) : Property(p) {}

		double totalAmount()
		{
			return (350*getSourface())/category;
		}
		void getInfo()
		{
			std::cout<<"\t\tPlot of Land"<<endl;
			Property::getInfo();
			std::cout<<"Category: "<<category<<endl;
		}

	private:
		int category;
};

class Building : public Property
{
	public:
		//normal constructor
		Building(std::string a, double s) : Property(a,s) {}

		//copy constructor
		Building(const Building &p) : Property(p) {}

		double totalAmount()
		{
			return 500*getSourface();
		}
		void getInfo()
		{
			std::cout<<"\t\tBuilding"<<endl;
			Property::getInfo();
		}
};

int main()
{
	int category;

	std::cout<<"The category for Silistra is: ";
	std::cin>>category;

	PlotOfLand *p1 = new PlotOfLand("Silistra", 100, category);
	PlotOfLand *p2 = new PlotOfLand("Sagului", 50, 4);
	PlotOfLand *p3 = p1;
	PlotOfLand *p4 = p2;

	p1->getInfo();
	p2->getInfo();
	p3->getInfo();
	p4->getInfo();

	Building *b1 = new Building("Aradului", 70);
	Building *b2 = new Building("Bucovinei", 100);
	Building *b3 = b1;
	Building *b4 = b2;

	b1->getInfo();
	b2->getInfo();
	b3->getInfo();
	b4->getInfo();
	
}
