#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> umap;
    for(int i = 0; i < phone_book.size(); i++){
        umap[phone_book[i]] = phone_book[i].size();
    }
    
    int n = phone_book.size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int o = 0;
            if(umap[phone_book[j]] < umap[phone_book[i]] || i == j){
                continue;
            }
            else{
                for(int k = 0; k < umap[phone_book[i]]; k++){
                    if(phone_book[i][k] != phone_book[j][k] ){
                        break;
                    }
                    else{
                        o += 1;
                    }
                }
            }
            if(o == umap[phone_book[i]]){
                return false;
            }
        }
    }
    
    return answer;
}