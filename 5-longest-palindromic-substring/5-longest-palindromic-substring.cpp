class Solution {
public:
    int findString(string s, int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j] ){
            i--;
            j++;
        }
        return j-i-1;   
    }
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        for(int i=0; i<s.size(); i++){
            int oddLen = findString(s,i,i);
            int evenLen = findString(s,i,i+1);
            cout<<oddLen<<" "<<evenLen<<endl;
            if(oddLen > maxLen){
                maxLen = oddLen;
                start = i - (oddLen/2);
                
            }
            if(evenLen > maxLen){
                maxLen = evenLen;
                start = i - (evenLen/2) + 1;
            }
        }
        return s.substr(start,maxLen);
    }
};