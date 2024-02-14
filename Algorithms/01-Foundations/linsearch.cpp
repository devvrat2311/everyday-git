#include<iostream>

int linsearch(int arr[], int n, int key)
{
  for(int j = 0; j < n; j++){
    if(arr[j] == key)
      return j;
  }
  return -1;
}

int main() {

  int n;
  std::cin >> n;
  int arr[n];

  for(int i = 0; i < n; i++){
  std::cin >> arr[i];
  }

  int value;
  std::cout << "enter the value that you want to find";
  std::cin  >> value;

  std::cout << linsearch(arr,n,value);

  return 0;
}
