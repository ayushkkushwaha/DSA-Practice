class Solution {
public:
    bool isValid(string s) {

        int size = s.size();

        if (size <= 1)
            return false;

        stack<char> st;
        char top;

        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            } else {
                if(st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if (i == ')' && top != '(') {
                    return false;
                } else if (i == '}' && top != '{') {
                    return false;
                } else if (i == ']' && top != '[') {
                    return false;
                }
            }
        }

        return st.empty();
    }
};