class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        
        string str = "";
        int num = 0;
        
        for(char c: s) {
            
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if(c == '[') {
                strStack.push(str);
                str = "";
                
                numStack.push(num);
                num = 0;
            } else if(c == ']') {
                string temp = str;
                
                str = strStack.top();
                strStack.pop();
                
                int count = numStack.top();
                numStack.pop();
                
                while(count-- > 0) {
                    str.append(temp);
                }
                
            } else {
                str += c;
            }
            
        }
        
        return str;
    }
};