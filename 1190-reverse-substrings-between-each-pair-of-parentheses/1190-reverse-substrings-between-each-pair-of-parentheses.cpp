class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> m_strs;

        m_strs.push_back("");

        for (char ch : s) {
            if (ch == '(') {
                m_strs.push_back("");
            }
            else if (ch == ')') {
                string temp = m_strs.back();
                m_strs.pop_back();
                reverse(temp.begin(), temp.end());
                m_strs.back() += temp;
            }
            else {
                m_strs.back().push_back(ch);
            }
        }

        return m_strs[0];
    }
};