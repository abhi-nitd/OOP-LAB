#include<bits/stdc++.h>
using namespace std; 
  
string findDiff(string str1,string str2)
{   
    int j=0;
    string temp;
    if(isSmaller(str1,str2))
    {
        temp=strcpy(str1);
        str1=strcpy(str2);
        str2=strcpy(temp);
    }
    string str = ""; 
    int n1 = strlen(str1);
    int n2 = strlen(str2); 
    int diff = n1 - n2; 
    int carry=0;
    for (int i=n2-1; i>=0; i--) 
    { 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str[j]=(sub+'0');
        j++;
     }
     for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str[j]='9';
            j++; 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0)
            str[j]=(sub+'0');
            j++;
          carry = 0; 
    
    } 
    reverseStr(str);
    return str;

}   


void reverseStr(string& str) 
{ 
    int n = str.length();
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

bool isSmaller(string str1, string str2) 
{ 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 
int main()
{
	string str1,str2;
	cout<<"Enter the first number"<<endl;
	cin>>str1;
	cout<<"Enter the second number"<<endl;
	cin>>str2;
	cout<<"the difference is "<<findDiff(str1,str2);
	return 0;
}