/*
You have been given a string s, which is supposed to be a sentence. However, someone forgot to put spaces between the different words, and for some reason they capitalized the first letter of every word. Return the sentence after making the following amendments:

Put a single space between the words.
Convert the uppercase letters to lowercase.
Example

For s = "CodesignalIsAwesome", the output should be
amendTheSentence(s) = "codesignal is awesome";
For s = "Hello", the output should be
amendTheSentence(s) = "hello".
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string s

A string containing uppercase and lowercase English letters.

Guaranteed constraints:
3 ≤ s.length ≤ 100.

[output] string

The amended sentence.
*/
std::string amendTheSentence(std::string s) {
    int l = s.length();
    char output[200];
    int k = 0;
    for(int i = 0; i < l; i++){
        //cout<<s[i]<<endl;
        if(s[i] >= 'a' && s[i] <= 'z'){
            output[k++] = s[i];
            //cout<<"output "<<output[k-1]<<endl;
            continue;
        } else {
            if(s[i] >= 'A' && s[i] <= 'Z'){
                if(i != 0)
                    output[k++] = ' ';
                output[k++] = s[i] - ('A' - 'a');
            }
        }
        //cout<<"output "<<output[k-1]<<endl;
    }

    output[k] = '\0';

    //cout<<output<<endl;
    return output;
}
