/*
Given an encoded string, return its corresponding decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times. Note: k is guaranteed to be a positive integer.

Note that your solution should have linear complexity because this is what you will be asked during an interview.

Example

For s = "4[ab]", the output should be
decodeString(s) = "abababab";

For s = "2[b3[a]]", the output should be
decodeString(s) = "baaabaaa";

For s = "z1[y]zzz2[abc]", the output should be
decodeString(s) = "zyzzzabcabc".

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string s

A string encoded as described above. It is guaranteed that:

the string consists only of digits, square brackets and lowercase English letters;
the square brackets form a regular bracket sequence;
all digits that appear in the string represent the number of times the content in the brackets that follow them repeats, i.e. k in the description above;
there are at most 20 pairs of square brackets in the given string.
Guaranteed constraints:
0 ≤ s.length ≤ 80.

[output] string
*/
std::string decodeString(std::string s) {
    stack<string> st;
    int len = s.length();
    string result = "";
    int i = 0;
    if(len == 0) return "";
    if(len == 1) return s;

    while(i < len){
        if(s[i] >= 'a' && s[i] <= 'z'){
            st.push((string(1,s[i])));
        } else if(s[i] >= '0' && s[i] <= '9'){
            string digits = "";
            while(s[i] >= '0' && s[i] <= '9'){
                digits += string(1,s[i]);
                i++;
            }
            st.push(digits);
            i--;
        } else if(s[i] == '['){
            st.push(string(1,s[i]));
        } else if(s[i] == ']'){
            string str ="";
            string temp = "";
            while(st.top() != "["){
                str = st.top() + str;
                st.pop();
            }
            st.pop();
            int num = stoi(st.top());
            st.pop();
            int i = 1;
            temp = str;
            while(i < num){
                temp += str;
                i++;
            }
            st.push(temp);
        }
        i++;
    }
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }
    return result;
}
