#include<iostream>
#include<vector>

void displayVectorVals(std::vector<int> &a) {
  for(int i = 0; i < a.size(); i++){
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

void takeVectorVals(std::vector<int> &a)
{
  for(int i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
}

void binAddition(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c)
{
  std::vector<int> rem(c.size());

  for(int i = 0; i < c.size(); i++){
    if(i > 0){
      c[c.size() - 1 - i] = a[a.size() - 1 - i] + b[b.size() - 1 - i] + rem[rem.size() - i] ;
    }
    else {
      c[c.size() - 1 - i] = a[a.size() - 1 - i] + b[b.size() - 1 - i];
    }
    //c[c.size() - i] = c[c.size() - i] % 2;
    rem[rem.size() - 1 - i] = c[c.size() - 1 - i] / 2;
  }

  for(int i = 0; i < c.size(); i++){
    c[i] = c[i] % 2;
  }

  displayVectorVals(c);
  std::cout << std::endl;

  std::cout << "The remainders were: ";
  displayVectorVals(rem);
}

void binAdditionV2(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c)
{
  int carry = 0;
  for(int i = a.size() - 1; i >= 0; --i)
  {
    int sum = a[i] + b[i] + carry;
    c[i+1] = sum % 2;
    carry = sum / 2;
  }

  c[0] = carry;
}



int main() {

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  takeVectorVals(a);
  std::vector<int> b(n);
  takeVectorVals(b);
  std::vector<int> c(n+1);
  std::vector<int> d(n+1);

  binAddition(a, b, c);

  binAdditionV2(a,b,d);

  displayVectorVals(d);

  return 0;
}
