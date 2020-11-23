class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        
        for(string word: words) {
            string str = "";
            for(char c: word) {
                int idx = c - 'a';
                str.append(code[idx]);
            }
            s.insert(str);
        }
        
        return s.size();
    }
};