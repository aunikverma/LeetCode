// class Solution {
// public:
//     bool canConstruct(string r, string m) {
//         unordered_map<char, int> mp;
//         for (char c : m) {
//             mp[c]++;
//         }
//         for (char c : r) {

//             if (mp.find(c) == mp.end() || mp[c] == 0) {
//                 return false;
//             } 
//             else {
//                 --mp[c];
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> youssef;
        
        for(int i=0;i<magazine.size();i++){
            youssef[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(youssef[ransomNote[i]]>0){
                youssef[ransomNote[i]]--;
            }
            else{return false;}
        }
        return true;
    }
};