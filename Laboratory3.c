#include <iostream>
#include<functional>
#include<algorithm>
#include<vector>

int main() {
  std::cout << "Hello World!\n";
  
  /*
  * Lambda expressions
  */
  
  //Lambda function that sums up two numbers
  std::function<int(int, int)> sum = [](int a, int b) -> int
  {
    return a+b;
  };
  
  //Lambda function that tests if a number (int) is odd
  std::function<bool(int)> isOdd = [](int n) -> bool
  {
    return (n % 2) != 0;
  };
  
  std::cout<<sum(3,3)<<std::endl;
  std::cout<<isOdd(3)<<std::endl;
  
  
  
  
  
  /*
  * std::copy
  */
  std::vector<int> a = {1,2,3,4,5,6,7,8,9};
  std::vector<int> b ;
  std::copy(a.begin(), a.end(), std::back_inserter(b));
  
  //Copy the first 4 entries from a vector if integers
  std::vector<int> c ;
  std::copy(a.begin(), a.begin()+4, std::back_inserter(c));
  
  //Copy the first 4 entries from a vector if integers
  std::vector<int> d ;
  std::copy(a.end()-4, a.end(), std::back_inserter(d));
  
  for(auto it: d)
  {
    std::cout<<it<<" ";
  }
  std::cout<<std::endl;
  
  
  
  
  
  
  /*
  * std::copy_if
  */
  std::vector<int> e (a.size());
  auto it = std::copy_if(a.begin(), a.end(), e.begin(), [](int i)
  {return i>4;});
  e.resize(std::distance(e.begin(),it));  //shrink container to new size
  
  
  
  
  
  
  
  /*
  * find_if
  */
  std::vector<int>::iterator i = std::find_if (a.begin(), a.end(), [](int i){return i%2==0;});
  std::cout<<"First even number "<<*i<<std::endl;
  
  
  
}