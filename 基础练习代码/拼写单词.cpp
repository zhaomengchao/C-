class Solution {
public:
    int charsCount[26];
    int countCharacters(vector<string>& words, string chars) {
        int ret = 0;
        for (auto& c:chars)
            charsCount[c - 'a']++;
        
        for (auto& word:words) {
            int tempCharsCount[26];
            copy(begin(charsCount), end(charsCount), begin(tempCharsCount));
            bool isValid = true;
            for (auto& w:word) {
                if (tempCharsCount[w - 'a'] == 0) {
                    isValid = false;
                    continue;
                }
                tempCharsCount[w - 'a']--;
            }
            
            if (isValid)
                ret += word.size();
        }
        
        return ret;
    }
};