class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;

        bool ans;
        bool first=true;

        for (char x: expression) {

            if (x == '&' || x == '|' || x == '!') s.push(x);

            else if (x == '(' || x == ',') continue;

            else if (x == ')') {
                //pop and calculate;
                char operation;
                bool orAns=false;
                bool andAns=true;

                while (s.top() != '!' && s.top() != '|' && s.top() != '&') {
                    // cout << s.top() << " ";
                    if (s.top()=='t') {
                        orAns|=true;
                        andAns&=true;
                    } else {
                        orAns|=false;
                        andAns&=false;
                    }
                    s.pop();
                }
                // cout << endl;
                operation = s.top();
                s.pop();
                // cout << operation << " " << orAns << " " << andAns << endl;
                if (operation=='&') {
                    if (andAns==false) s.push('f');
                    else s.push('t');
                }
                else if (operation == '|') {
                    if (orAns==false) s.push('f');
                    else s.push('t');
                } else {
                    if (orAns==true) s.push('f');
                    else s.push('t');
                }
                // cout << s.top() << endl;
            }

            else {
                s.push(x);
            }

        }
        if (s.top()=='f') return false;
        else return true;
        // return s.top();
    }
};