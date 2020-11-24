class Solution {
private:
    int getPrecedence(char op) {
        if(op == '*' || op == '/') 
            return 1;
        
        return 0;
    }
    
    int performOperation(char op, int op1, int op2) {
        switch(op) {
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            default:
                return 0;
        }
    }
public:
    int calculate(string s) {
        stack<int> operandStack;
        stack<char> operatorStack;
        int n = s.size();
        
        for(int i = 0; i < n; ++i) {
            if(isdigit(s[i])) {
                int num = 0;
                while(i < n && isdigit(s[i])) {
                    num *= 10;
                    num += s[i] - '0';
                    i++;
                }
                i--;
                operandStack.push(num);
            } else if(s[i] != ' ') {
                int chPrecedence = getPrecedence(s[i]);
                
                while(!operatorStack.empty() && chPrecedence <= getPrecedence(operatorStack.top())) {
                    char op = operatorStack.top(); operatorStack.pop();
                    int op2 = operandStack.top(); operandStack.pop();
                    int op1 = operandStack.top(); operandStack.pop();
                    
                    operandStack.push(performOperation(op, op1, op2));
                }
                
                operatorStack.push(s[i]);
            }
        }
        
        while(!operatorStack.empty()) {
            char op = operatorStack.top(); operatorStack.pop();
            int op2 = operandStack.top(); operandStack.pop();
            int op1 = operandStack.top(); operandStack.pop();

            operandStack.push(performOperation(op, op1, op2));
        }
        
        return operandStack.top();
    }
};