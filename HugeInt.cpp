#include "HugeInt.h"
#include <string>
HugeInt::HugeInt(int v){
   string temp;
	stringstream ss;
	ss << v;
   ss >> temp;
   for(int i = 0;i < temp.length();++i){
		int t = 0;
		ss.str("");
		ss.clear();
      ss << temp.substr(i,1);
   	ss >> t;
		value.push_back(t);
       }

}

HugeInt::HugeInt(string str){
      stringstream ss;
      int t;
  for(int i = 0;i < str.length();++i){
      ss.str("");
	   ss.clear();
      ss << str.substr(i,1);
      ss >> t;
      value.push_back(t);
	
     }

}

ostream & operator << (ostream & out, const HugeInt &num){
for(int i = 0;i < num.value.size();++i){
	out << num.value.at(i);

}
return out;

}

istream & operator >> (istream & in,HugeInt &num){
string str;
in >> str;
if(str.length() != num.value.size() && num.value.size() != 0){
num.value.erase(num.value.begin(),num.value.end());
}
stringstream ss;
int t;
for(int i = 0;i < str.length();++i){
      ss.str("");
	   ss.clear();
      ss << str.substr(i,1);
      ss >> t;
      num.value.push_back(t);
	
     }
return in;
}

const HugeInt& HugeInt::operator= (const HugeInt &num){
	
value.erase(value.begin(),value.end());


for(int i = 0;i < num.value.size();++i){
          value.push_back(num.value.at(i));
     }
return *this;

}

 HugeInt  HugeInt::operator+ (HugeInt &num){
   HugeInt result;

result.value.erase(result.value.begin(),result.value.end());

int s;
if(value.size() > num.value.size()) s = value.size(); else s = num.value.size();
for(int i = 0;i < s;++i){
	result.value.push_back(0);

}

int carry = 0;
int add1 = 0;
int add2 = 0;
for(int i = 0 ;i < result.value.size();i++){
int v1_index = value.size() - i - 1;
int v2_index = num.value.size() - i - 1;
int v3_index = result.value.size() - i - 1;
if(v1_index >= 0 && v1_index < value.size()) add1 = value.at(v1_index); else add1 = 0;
if(v2_index >= 0 && v2_index < num.value.size()) add2 = num.value.at(v2_index); else add2 = 0;
result.value.at(v3_index) = add1 + add2 + carry;
carry = result.value.at(v3_index) / 10;
result.value.at(v3_index) = result.value.at(v3_index) % 10;
}
vector <int>::iterator theIterator = result.value.begin(); 
if(carry != 0) result.value.insert(theIterator,1,carry);

return result;
}

HugeInt HugeInt::operator-(HugeInt &num){
HugeInt result;
result.value.erase(result.value.begin(),result.value.end());

int carry = 0;
int sub1 = 0;
int sub2 = 0;
for(int i = 0;i < value.size();++i){
	result.value.push_back(0);

}
for(int i = 0 ;i < result.value.size();i++){
int v1_index = value.size() - i - 1;
int v2_index = num.value.size() - i - 1;
int v3_index = result.value.size() - i - 1;
if(v1_index >= 0 && v1_index < value.size()) sub1 = value.at(v1_index); else sub1 = 0;
if(v2_index >= 0 && v2_index < num.value.size()) sub2 = num.value.at(v2_index); else sub2 = 0;
if(sub1 - sub2 < 0 || sub1 - sub2 < carry){
	result.value.at(v3_index) = (sub1 + 10) - sub2 - carry;
	carry = 1;
}
else{
    result.value.at(v3_index) = sub1  - sub2 - carry;
	carry = 0;

}

}
int index = -1;
for(int i = 0;i < result.value.size() - 1;i++){
	if(result.value.at(i) == 0) index = i; else break;
}
if(index != -1)
{
	if(index == 0) result.value.erase(result.value.begin());
else result.value.erase(result.value.begin(),result.value.begin() + index + 1);
}

return result;
}
