/*
Given an array of words and a length l, format the text such that each line has exactly l characters and is fully justified on both the left and the right. Words should be packed in a greedy approach; that is, pack as many words as possible in each line. Add extra spaces when necessary so that each line has exactly l characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right. For the last line of text and lines with one word only, the words should be left justified with no extra space inserted between them.

Example

For
words = ["This", "is", "an", "example", "of", "text", "justification."]
and l = 16, the output should be

textJustification(words, l) = ["This    is    an",
                               "example  of text",
                               "justification.  "]
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.string words

An array of words. Each word is guaranteed not to exceed l in length.

Guaranteed constraints:
1 ≤ words.length ≤ 150,
0 ≤ words[i].length ≤ l.

[input] integer l

The length that all the lines in the output array should be.

Guaranteed constraints:
1 ≤ l ≤ 60.

[output] array.string

The formatted text as an array containing lines of text, with each line having a length of l.
*/
std::vector<std::string> textJustification(std::vector<std::string> words, int l) {
    vector<string> container;
    vector<string> output;
    int rem = l;
    int len = words.size();
    bool isMultiWords = false;
    int lengthNeeded = 0;

    for(int i = 0; i < len; i++){
        int size = words[i].length();
        if(isMultiWords){
            lengthNeeded = size + 1;
        } else {
            lengthNeeded = size;
        }
        if(lengthNeeded <= rem){
            rem -= lengthNeeded;
            container.push_back(words[i]);
            isMultiWords = true;
        } else {
            int totWords = container.size();
            
            string resStr ="";
            if(totWords > 1){
                int remainingSpaces = rem + (totWords - 1);
                int betweenWords = remainingSpaces/(totWords -1);
                int remSpaces = remainingSpaces%(totWords - 1);
                int spaceCnt = 0;
                for(int i = 0; i < totWords; i++){
                    resStr += container[i];
                    if(spaceCnt < totWords-1){
                        for(int k = 0; k < betweenWords; k++){
                            resStr +=" ";
                        }
                        if(remSpaces) {
                            resStr += " ";
                            remSpaces--;
                        }
                    }
                    spaceCnt++;
                }
            } else {
                rem = l;
                for(int i = 0; i < totWords && rem > 0; i++){
                    resStr += container[i];
                    rem -=(container[i].length());
                    if(rem > 0){
                        resStr +=" ";
                        rem--;
                    }
             
                }
                for(int i = 0; i < rem; i++){
                    resStr +=" ";
                }
            }
            
            output.push_back(resStr);
            container.clear();
            container.push_back(words[i]);
            rem = l - words[i].length();
            isMultiWords = true;
        }
    }

    int totalWords = container.size();
    if(totalWords > 0){
        rem = l;
        string resStr = "";
        for(int i = 0; i < totalWords && rem > 0; i++){
            resStr += container[i];
            rem -=(container[i].length());
            if(rem > 0){
                resStr +=" ";
                rem--;
            }
             
        }
        for(int i = 0; i < rem; i++){
            resStr +=" ";
        }
        output.push_back(resStr);
    }
    return output;
}
