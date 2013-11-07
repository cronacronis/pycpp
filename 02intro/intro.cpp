#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <list>

using namespace std;

int main(){
  // numbers
  const int AGE = 26;
  const double PI = 3.14159;

  // strings
  string firstName ,middleName, lastName;
  size_t pos = 0;
  string s = "Rutherford Birchard Hayes";
  string delimiter = " ";
  // copy
  string copied = s;
  // you have to declar the array as a pointer
  string *token = new string[3];
  int i = 0;
  while((pos = copied.find(delimiter)) != string::npos){
    token[i] = copied.substr(0, pos);
    //cout << i << " banme "<< pos << " - " << copied.substr(0, pos) << endl;
    copied.erase(0, pos + delimiter.length());
    i++;
  }
  token[2] = copied;

  firstName = token[0];
  middleName = token[1];
  lastName = token[2];
  string s2;
  s2.append(firstName+delimiter+middleName+delimiter+lastName);
  // Rutherford Birchard Hayes
  if(s.compare(s2) == 0){
    cout << "yes!!!";
  }else{
    cout  << "nooooooo";
  }
  cout << endl;
  // list
  vector<string> beatles;
  beatles.push_back("John");
  beatles.push_back("Paul");
  beatles.push_back("George");
  beatles.push_back("Ringo");
  vector<string>::iterator it = beatles.begin();
  // while(it != beatles.end()){
  //   cout << *it << endl;
  //   it++;
  // }
  for(it=beatles.begin();it !=beatles.end();it++){
    cout << "Hello "<< *it << endl;
  }

  int const ages[] = {18, 21, 28, 21, 22, 18, 19, 34, 9};
  int len = sizeof(ages)/sizeof(int);
  //cout << "len=> " << len << endl;
  // setは重複なし
  set<int> uniqueAges;
  set<int>::iterator it4;

  for(i=0; i < len; i++){
    uniqueAges.insert(ages[i]);
  }

  for(set<int>::iterator it=uniqueAges.begin();it!=uniqueAges.end();it++){
    cout << (*it) <<endl;
  }

  // The typical way to check for existence in many STL containers is:
/*
  const bool is_in = uniqueAges.find(18) != uniqueAges.end();
  if(is_in)
    cout <<"There is an 18-year-old present!"<<endl;
    */

  if(uniqueAges.find(18) != uniqueAges.end()){
    cout <<"There is an 18-year-old present!"<<endl;
  }

  list<int> orderedUniqueAges;
  list<int>::iterator it3;

  for(it4= uniqueAges.begin();it4!= uniqueAges.end();it4++)
    orderedUniqueAges.push_back(*it4);

  /*
  for(it3=orderedUniqueAges.begin();it3!=orderedUniqueAges.end();it3++)
    cout<<*it3<< endl;
  */

  // dictonary
  map<string,long> netWorth;

  netWorth["Donald Trump"] = 3000000000;
  netWorth["Bill Gates"] = 58000000000;
  netWorth["Tom Cruise"] = 40000000;
  netWorth["Joe Postdoc"] = 20000;

  // iterating over key-value pairs:
  for(map<string,long>::iterator ii=netWorth.begin(); ii!=netWorth.end(); ii++){
    //cout << (*ii).first <<" - "<< (*ii).second << endl;
    if((*ii).second < 1000000)
      cout <<"haha " << (*ii).first << " is not a millionaire"<< endl;
  }
  // testing dict membership
  map<string,long>::iterator iii = netWorth.find("Tom Cruise");
  if(iii != netWorth.end()){
    cout<<"show me the money!"<<endl;
  }

  return 0;
}
/*
yes!!!
Hello John
Hello Paul
Hello George
Hello Ringo
34
9
18
19
22
28
There is an 18-year-old present!
haha Joe Postdoc is not a millionaire
show me the money!
*/
