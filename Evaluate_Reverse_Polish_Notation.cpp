class Solution {
public:
    
    bool isOperator(string &oper)
    {
        if(oper=="+"||oper=="-"||oper=="/"||oper=="*")
            return true;
        return false;
    }
    
    int arithmeticOperation(int &num1,int &num2,string &oper)
    {
        if(oper=="+")
            return num1+num2;
        if(oper=="-")
            return num2-num1;
        if(oper=="*")
            return num1*num2;
        return num2/num1;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int>operandStack;
        for(auto token:tokens)
        {
            if(isOperator(token))
            {
                int num1=operandStack.top();
                operandStack.pop();
                int num2=operandStack.top();
                operandStack.pop();
                operandStack.push(arithmeticOperation(num1,num2,token));
            }
            else
            {
                operandStack.push(stoi(token));
            }
        }
        return operandStack.top();
    }
};