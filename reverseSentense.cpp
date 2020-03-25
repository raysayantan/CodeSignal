/*
Reverse the order of words in a given string sentence. You can assume that sentence does not have any leading, trailing or repeating spaces.

Example

For sentence = "Man bites dog", the output should be
reverseSentence(sentence) = "dog bites Man".

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string sentence

A string consisting of letters and spaces.

Guaranteed constraints:
1 ≤ sentence.length ≤ 2 · 104.

[output] string
*/
std::string reverseSentence(std::string sentence) {
    stack<string> strContainer;
    stringstream ss(sentence);
    string output = "";
    if(sentence == "") return "";
    while(ss.good()){
        string str;
        getline(ss, str,' ');
        strContainer.push(str);
    }

    while(!strContainer.empty()){
        if(output !="") output += " ";
        output += strContainer.top();
        strContainer.pop();
    }

    return output;
}
