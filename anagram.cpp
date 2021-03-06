#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

bool anagram(const char *str1, const char *str2)
{
    bool flag = true;
    int index_of_char[26];
    fill_n(index_of_char, 26, 0);
    int i=0,index,sum=0;
    while(str1[i]!='\0')
    {
        if(str1[i]==' ')
        i++;
        else
        {
            index = (int)str1[i] - 65;
            if( index > 25)
            index -= 32;
            index_of_char[index]++;
            sum+=index;
            i++;
        }
    }
    index=i=0;
    while(str2[i]!='\0')
    {
        if(str2[i]==' ')
        i++;
        else
        {
            index = (int)str2[i] - 65;
            if( index > 25)
            index -= 32;
            index_of_char[index]--;
            sum-=index;
            i++;
        }
    }
    index=i=0;
    while(index_of_char[i] == 0)
        i++;
    if(sum != 0 || i < 26)
    flag = false;
    return flag;
}

int main()
{
    char str1[100], str2[100];
    cout<<"\nEnter the first string: ";
    gets(str1);
    cout<<"\nEnter the second string: ";
    gets(str2);
    if(anagram(str1,str2))
    cout<<"\nThey are anagrams!";
    else
    cout<<"\nThey are not anagrams!";
    return 0;
}
