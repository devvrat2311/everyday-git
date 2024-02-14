#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b; 
  b = temp;
}

void insertion_sort(vector<int> &a)
{
  int n = a.size();

  for(int j = 1; j < n; j++){
    int key = a[j];
    //insert a[j] into the sorted sequence a[1...j-1]
    int i = j - 1;
    //in the pseudocode from CLRS the 1-indexed arrays are used instead of 0-indexed so here we should use i >= 0
    while(i >= 0 and a[i] > key) //if you want to sort the array in descending order, you may change '>' to '<'
    {
      a[i+1] = a[i];
      i = i - 1;
    }
    a[i+1] = key;
  }
}

void insertion_sort_descending(vector<int> &a)
{
  int n = a.size();
  
  for(int j = 1; j < n; j++) {
    int key = a[j];

    int i = j - 1;

    while(i >= 0 and a[i] < key)
    {
      a[i+1] = a[i];
      i = i - 1;
    }
    a[i+1] = key;
  }
}

int main() {
  int n; 
  cout << "enter the number of terms you want to sort: ";
  cin >> n;

  vector<int> arr(n);

  cout << endl;
  cout << "enter the numbers that you want to sort: ";
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  //insertion_sort(arr);

  // cout << "The sorted array is: ";
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }

  insertion_sort_descending(arr);
  

  cout << "The decreasing sorted array is: ";
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  
  return 0;
}
