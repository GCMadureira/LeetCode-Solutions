// simple imitation of a LL(1) parser (I am sleepy so it is pretty bad if I do say so myself)
// 0ms

#include <string>
using namespace std;

/*
very scuffed grammar I came up with

expr -> term expr'

expr' -> ('+' | '-') term expr' | E

term -> INT | '(' expr ')' | '-' term
*/

class Solution {
public:
    string input;
    int index;
    
    int calculate(const string& s) {
        input = s;
        index = 0;

        return expr();
    }

    long expr() {
        long termResult = term();
        return nextExpr(termResult);
    }

    long nextExpr(long currentValue) {
        while(index < input.size() && input[index] == ' ') ++index;

        if(input[index] == '+') {
            ++index;
            long termResult = term();
            return nextExpr(currentValue + termResult);
        }
        else if(input[index] == '-') {
            ++index;
            long termResult = term();
            return nextExpr(currentValue - termResult);
        }
        else {
            return currentValue;
        }
    }

    long term() {
        while(index < input.size() && input[index] == ' ') ++index;

        if(input[index] == '(') {
            ++index;
            long exprResult = expr();
            ++index;
            return exprResult;
        }
        else if(input[index] == '-') {
            ++index;
            return -term();
        }
        else {
            long result = 0;
            while(index < input.size() && input[index] >= '0' && input[index] <= '9') result = result*10 + (input[index++] - '0');
            return result;
        }
    }
};