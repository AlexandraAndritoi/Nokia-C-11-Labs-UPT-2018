#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define N 4

int main()
{
	vector< pair<int,int> > vect;

	int arr1[] = {5, 79, 96, 10};
	int arr2[] = {2,  3,  4,  5};

	int i;
	for(i=0; i<N; i++)
		vect.push_back( make_pair(arr1[i], arr2[i]) );

	for(i=0; i<N; i++)
		cout<<vect[i].first<<"\t"<<vect[i].second<<endl;

	sort(vect.begin(), vect.end());

	cout<<endl;

	for(i=0; i<N; i++)
	{
		if(vect[i].second %2 != 0)
			vect[i].second = 0;
		cout<<vect[i].first<<"\t"<<vect[i].second<<endl;
	}

	return 0;
	
}
