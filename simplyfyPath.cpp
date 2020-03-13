/*
Given an absolute file path (Unix-style), shorten it to the format /<dir1>/<dir2>/<dir3>/....

Here is some info on Unix file system paths:

/ is the root directory; the path should always start with it even if it isn't there in the given path;
/ is also used as a directory separator; for example, /code/fights denotes a fights subfolder in the code folder in the root directory;
this also means that // stands for "change the current directory to the current directory"
. is used to mark the current directory;
.. is used to mark the parent directory; if the current directory is root already, .. does nothing.
Example

For path = "/home/a/./x/../b//c/", the output should be
simplifyPath(path) = "/home/a/b/c".

Here is how this path was simplified:
* /./ means "move to the current directory" and can be replaced with a single /;
* /x/../ means "move into directory x and then return back to the parent directory", so it can replaced with a single /;
* // means "move to the current directory" and can be replaced with a single /.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string path

A line containing a path presented in Unix style format. All directories in the path are guaranteed to consist only of English letters.

Guaranteed constraints:
1 ≤ path.length ≤ 5 · 104.

[output] string

The simplified path.
*/
std::string simplifyPath(std::string path) {
    stack<string> dir;
    stringstream ss(path);
    while(ss.good()){
        string token;
        getline(ss, token, '/');
        if(token == "."){
            continue;
        } else if(token == ".."){
            if(!dir.empty())
                dir.pop();
        } else if(token == "/"){
            continue;
        } else if(token == " " || token == ""){
            continue;
        } else {
            dir.push(token);
        }
        token.clear();
    }

    string res = "";
    while(!dir.empty()){
        if(res != "")
            res = "/" + res;
        res = dir.top() + res;
        dir.pop();
    }
    res = "/" + res;

    return res;
}
