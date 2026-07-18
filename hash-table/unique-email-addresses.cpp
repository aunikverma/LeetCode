class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(string &email : emails)
        {
            string cl;
            for(char c : email)
            {
                if(c == '+' || c == '@')
                    break;
                if(c == '.')
                    continue;
                cl += c;
            }
            cl += email.substr(email.find('@'));
            st.insert(cl);
        }
        return st.size();
    }
};