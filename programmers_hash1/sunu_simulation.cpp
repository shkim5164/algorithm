#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string> result;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());    
    set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(),inserter(result, result.end()));
    answer = result[0];
    return answer;
}