/**
 * Leetcode : https://leetcode.com/problems/basic-calculator-ii/description/
 * 
*/


/**
 * 
 * Explaination : stack is used
 * 
 * Watch video = https://www.youtube.com/watch?v=B6cfSz-Ir_c
 * 
 * 
*/

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int cur = 0;
        char lastSign = '+';
        stack<int>st;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                cur = cur * 10 + (ch - '0');
            } 
            if ((!(ch >= '0' && ch <= '9') && ch != ' ' )|| i == s.size()-1){
                if(lastSign == '+'){
                    st.push(cur);
                } else if(lastSign == '-'){
                    st.push(cur * -1);
                } else if(lastSign == '*'){
                    int temp = st.top();
                    st.pop();
                    st.push(temp * cur);
                } else if(lastSign == '/'){
                    int temp = st.top();
                    st.pop();
                    st.push(temp / cur);
                }
                cur = 0;
                lastSign = ch;
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;

    }
};