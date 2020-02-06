/*
Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.

Example

For s = "abacabad", the output should be
firstNotRepeatingCharacter(s) = 'c'.

There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

For s = "abacabaabacaba", the output should be
firstNotRepeatingCharacter(s) = '_'.

There are no characters in this string that do not repeat.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string s

A string that contains only lowercase English letters.

Guaranteed constraints:
1 ≤ s.length ≤ 105.

[output] char

The first non-repeating character in s, or '_' if there are no characters that do not repeat.
*/
char firstNotRepeatingCharacter(std::string s) {
    int l = s.length();
    int countArr[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char result = '_';

    for(int i = 0; i < l; i++){
        countArr[s[i] -'a']++;
    }

    for(int i = 0; i < l; i++){
        if(countArr[s[i] - 'a'] == 1){
            result = s[i];
            break;
        }
    }

    return result;
}
