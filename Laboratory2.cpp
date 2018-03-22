#include <iostream>
#include <vector>
#include <tuple>
#include <forward_list>
#include <queue>
#include <functional>

using namespace std;

struct S{
 
};

void foo(int a)
{
 	std::cout<<"foo"<<std::endl;
}

void foo(const char *a)
{
 	std::cout<<"bar"<<std::endl;
}

int main() {
	std::cout << "Hello World!\n";
	  
	/*
	* ex1
	* auto, decltype
	*/
	  
	int i;
	const int ci = 6;
	const int& cri = i;
	const S* p = new S();
	  
	auto a = i;
	auto b = ci;    //b va fi doar tipul de baza, int aici, nu si const
	auto c = cri;
	auto d = p;
	  
	decltype(i) e;
	decltype(ci) f = 5; //const int => initializez cu variabila
	decltype(cri) g = i; //const int& => adresa
	decltype(p) h;
	  
	decltype((i)) v = a;
	  
	/*
	* 2
	* NULL, nullptr
	* nullprt e doar pt pointeri, nu pt int si double
	*/
	  
	foo(0);
	//foo(NULL); //in functie de compilator NULL va fi considerat fie 0, fie ambiguu
	  
	  
	/*
	* 3
	* std::vector
	*/
	  
	vector<int> array {1, 2, 3};
	for(auto iterator: array) cout<<iterator<<" ";
	  
	//begin si end returneaza iterator, un pointer adica, trebuie dereferentiat
	//front si back returneaza valoarea
	  
	*array.begin() = 11;
	*(array.end()-1) = 11;
	  
	for(auto iterator: array) cout<<iterator<<" ";
	  
	array.front() = 10;
	array.back() = 10;
	  
	for(auto iterator: array) cout<<iterator<<" ";
	  
	/*
	* 4
	* tuple
	*/
	  
	tuple<int,char> boo(10,'x');
	auto bar =make_tuple("test", 1, 2, "alt test");
	cout<<endl<<"boo contains: "<<get<0>(boo)<<" "<<get<1>(boo)<<endl;
	cout<<"bar contains: "<<get<3>(bar)<<endl;
	  
	/*
	* 
	* assignment page 13
	*/
	  
	/*
	* 5
	* Containers
	* forward_list
	* priority_que
	*
	*/
	  
	forward_list<int> list = {1, 2, 3, 4, 5, 6};
	  
	for(auto it = list.begin(); it != list.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
	    
	int vect[] = {6,9,0,1,2,5,3,7,6,10};
	  
	priority_queue<int,vector<int>,greater<int>> pq(vect,vect+10);
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	  
	  
	/* BONUS ASSIGNEMNT:
	*   propriul Container
	*   begin, end
	*/
}

//auto poate sa infereze orice tip mai putin const si referinte
//daca vrem sa fie asa, declaram auto const, respectiv auto &

//decltype infereaza si const, ca sa nu fie eroare la compilare, variabilele trebuie initializate

//decltype(()) ia adresa variabilei inferate, eroare daca nu este initializata variabila noua
