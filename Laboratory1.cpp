#include<iostream>

class Human
{
	public:
		Human(){}
		~Human(){}
		std::string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		void setName(std::string name)
		{
			this->name = name;
		}
		void setAge(int age)
		{
			this->age = age;
		}

	private:
		std::string name;
		int age;
};

class Car
{
	public:
		Car(){}
		~Car(){}

		/*
		virtual void move()
		{
			std::cout<<"Generic car moves\n";
		}
		*/

		virtual void move() = 0;	//clasa devine abstracta
};

class Dacia: public Car
{
	public:
		Dacia(){}
		~Dacia(){}
		void move()
		{
			std::cout<<"Dacia moves\n";
		}
};

int main()
{
	Human *h1 = new Human();
	Human *h2 = new Human();
	Human *h3 = new Human();
	Human *h4 = new Human();

	h1->setName("Alexandra");
	h1->setAge(21);

	std::cout<<h1->getName() + "\n";
	std::cout<<h1->getAge()<<std::endl;

	Car *dacia = new Dacia();
	dacia->move();
}
