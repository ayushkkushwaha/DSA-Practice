class Solution {
public:
    void genPos(int open, int close, string temp, int n, vector<string>& res) {

        if (temp.size() == n * 2) {
            res.push_back(temp);
            return;
        }

        cout << open << " " << close << endl;

        if (open < n) {
            temp.push_back('(');
            genPos(open + 1, close, temp, n, res);
            temp.pop_back();
        }

        if (open > close) {
            temp.push_back(')');
            genPos(open, close + 1, temp, n, res);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        genPos(0, 0, "", n, res);

        return res;
    }
};