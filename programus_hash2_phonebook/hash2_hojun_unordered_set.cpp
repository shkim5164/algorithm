#include<iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
void unprint(unordered_set<string> us){
    for(auto i=us.begin();i!=us.end();i++){
        cout<<*i<<'\n';
    }
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    int minsize = 1000001;
    int minind = -1;
    string mins = "";
    unordered_set<string> us(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size();i++){
        if(minsize>phone_book[i].length()){
            minsize = phone_book[i].length();
            minind = i;
        }
    }
    string str;
    string substring;
    for(int i=0;i<phone_book.size();i++){
        str = phone_book[i];
        if(i==minind)
            continue;
        for(int j=minsize;j<str.length();j++){
            for(int k=0;k<j;k++)
                substring.push_back(str[k]);
            if(us.find(substring) != us.end())
                return false;
            substring.clear();
        }
    }

    //unprint(us);
    return answer;
}
