
class Solution
{
private: // shraddha mam
    bool equal(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        // character count
        int count[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            count[s1[i] - 'a']++;
        }
        int win_size = s1.length();
        for (int i = 0; i < s2.length(); i++)
        {
            int win_indx = 0;
            int indx = i;
            int count1[26] = {0};
            while (win_indx < win_size && indx < s2.length())
            {
                count1[s2[indx] - 'a']++;
                indx++;
                win_indx++;
            }
            if (equal(count, count1))
            {
                return true;
            }
        }
        return false;
    }
};