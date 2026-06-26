class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<long long> st;

        for (string s : tokens) {

            if (s == "+" || s == "-" || s == "*" || s == "/") {

                long long b = st.top();
                st.pop();

                long long a = st.top();
                st.pop();

                long long ans = 0;

                if (s == "+")
                    ans = a + b;

                else if (s == "-")
                    ans = a - b;

                else if (s == "*")
                    ans = a * b;

                else
                    ans = a / b;

                st.push(ans);

            } 
            else {
                st.push(stoll(s));
            }
        }

        return st.top();
    }
};