/*
Given an array strings, determine whether it follows the sequence given in the patterns array. In other words, there should be no i and j for which strings[i] = strings[j] and patterns[i] ≠ patterns[j] or for which strings[i] ≠ strings[j] and patterns[i] = patterns[j].

Example

For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
areFollowingPatterns(strings, patterns) = true;
For strings = ["cat", "dog", "doggy"] and patterns = ["a", "b", "b"], the output should be
areFollowingPatterns(strings, patterns) = false.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.string strings

An array of strings, each containing only lowercase English letters.

Guaranteed constraints:
1 ≤ strings.length ≤ 105,
1 ≤ strings[i].length ≤ 10.

[input] array.string patterns

An array of pattern strings, each containing only lowercase English letters.

Guaranteed constraints:
patterns.length = strings.length,
1 ≤ patterns[i].length ≤ 10.

[output] boolean

Return true if strings follows patterns and false otherwise.
*/
bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {
    map<string,vector<int>> strContainer;
    map<string,vector<int>> ptrContainer;

    int strSize = strings.size();
    int ptrSize = patterns.size();

    for(int i = 0; i < strSize; i++){
        (strContainer[strings[i]]).push_back(i);
    }

    for(int i = 0; i < ptrSize; i++){
        (ptrContainer[patterns[i]]).push_back(i);
    }

    for(auto it = strContainer.begin(); it != strContainer.end(); it++){
        vector<int> indx = it->second;
        if(indx.size() >= 2){
            for(int i = 1; i < indx.size(); i++){
                if(patterns[indx[i]] != patterns[indx[i-1]]) return false;
            }
        }
    }

    for(auto it = ptrContainer.begin(); it != ptrContainer.end(); it++){
        vector<int> indx = it->second;
        if(indx.size() >= 2){
            for(int i = 1; i < indx.size(); i++){
                if(strings[indx[i]] != strings[indx[i-1]]) return false;
            }
        }
    }

    return true;
}
