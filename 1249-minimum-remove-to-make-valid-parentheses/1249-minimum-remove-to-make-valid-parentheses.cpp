class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> myStack;
        string str = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                myStack.push({'(', str.size()});
            else if(s[i] == ')') {
                if(myStack.empty())
                    continue;
                else if(myStack.top().first == '(')
                    myStack.pop();
            }
            str += s[i];
        }
        while(!myStack.empty()) {
            string left = "", right = "";
            left = str.substr(0, myStack.top().second);
            if(myStack.top().second+1 < str.length())
                right = str.substr(myStack.top().second+1, str.length()-myStack.top().second);
            str = left+right;
            myStack.pop();
        }
        
        return str;
    }
};