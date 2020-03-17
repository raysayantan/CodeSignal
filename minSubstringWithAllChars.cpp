/*
You have two strings, s and t. The string t contains only unique elements. Find and return the minimum consecutive substring of 
s that contains all of the elements from t.
It's guaranteed that the answer exists. If there are several answers, return the one which starts from the smallest index.
Example
For s = "adobecodebanc" and t = "abc", the output should be
minSubstringWithAllChars(s, t) = "banc".
Input/Output
[execution time limit] 0.5 seconds (cpp)
[input] string s
A string consisting only of lowercase English letters.
Guaranteed constraints:
0 ≤ s.length ≤ 100.
[input] string t
A string consisting only of unique lowercase English letters.
Guaranteed constraints:
0 ≤ t.length ≤ min(26, s.length).
[output] string
*/
std::string minSubstringWithAllChars(std::string s, std::string t) {
    map<char,int> m1;
    int lenT = t.length();
    int lenS = s.length();
    vector<int> pos{-1,-1};
    if(t =="") return "";
    if(s == t) return s;

    for(int i = 0; i < lenT; i++){
        m1[t[i]] = -1;
    }

    int cnt = lenT;
    bool flag = false;
    //now loop through the source string
    for(int i = 0; i < lenS; i++){
        auto it = m1.find(s[i]);
        if(it != m1.end()){
            if(cnt > 0){
                m1[s[i]] = i;
                cnt--;
            } else {
                m1[s[i]] = i;
            }
        }
        if(cnt == 0) flag = true;

        if(flag){
            int minVal = 101;
            int maxVal = -1;
            for(auto it = m1.begin(); it != m1.end(); it++){
                if(minVal > it->second){
                    minVal = it->second;
                } 
                if(maxVal < it->second){
                    maxVal = it->second;
                }
            }
            if(pos[0] == -1){
                pos[0] = minVal;
                pos[1] = maxVal;
            } else {
                if(maxVal - minVal < pos[1] - pos[0]){
                    pos[0] = minVal;
                    pos[1] = maxVal;
                }
            }
        }
    }
    return s.substr(pos[0], pos[1] - pos[0] + 1);
}
