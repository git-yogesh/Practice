#include <bits/stdc++.h>
using namespace std;

//next_num takes long int as input and returns long int as output
long int next_num(long int num) {
  long int temp = num, i, j, res = 0;
  std::vector<long int> v;

  //convert long int to vector
  while(temp) {
    v.push_back(temp % 10);
    temp /= 10;
  }
  //rearrange vector
  reverse(v.begin(), v.end());

  //1. Check if it's in ascending order
  for(i=0; i<v.size()-1; i++) {
    if(v[i] <= v[i+1]) continue;
    else break;
  }

  //If so, swap last two elements of the vector and convert back to long int
  //Return final result
  if(i==v.size()-1) {
    swap(v[v.size()-2], v[v.size()-1]);
    for(j=0; j<v.size(); j++) {
      res = res*10 + v[j];
    }
    return res;
  }

  //2. Check if it's in descending order
  for(i=0; i<v.size()-1; i++) {
    if(v[i] >= v[i+1]) continue;
    else break;
  }

  //If so, that is the max possible next number. Return it.
  if(i==v.size()-1) {
    return num;
  }

  //3. Check for decresing trend between two digits from the last digit
  //Eg: In 6165, 1<6.
  //Swap the first decresing trend with the next highest digit to its right
  //Swap 1 with 5 => 6561
  //Sort the elements to the right of this digit
  //Sort from 5 till end => 6516
  for(i=v.size()-1; i>0; i--) {
    if(v[i-1] < v[i]) {
      int min = v[i];
      int min_index = i;
      for(j=i; j<v.size(); j++) {
        if(v[j] < min && v[j] >= v[i-1]) {
          min = v[j];
          min_index = j;
        }
      }
      swap(v[i-1], v[min_index]);
      sort(v.begin()+i, v.end());
      break;
    }
  }

  //Return result
  for(j=0; j<v.size(); j++) {
    res = res*10 + v[j];
  }
  return res;
}

int main() {
  long int num;
  cin>>num;
  cout<<next_num(num);
  return 0;
}
