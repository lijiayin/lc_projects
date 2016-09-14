class Solution {
public:
	bool isPalindrome(string s, int l_ind, int r_ind) {
		if (r_ind < l_ind) 
			return false;
		while ((r_ind - l_ind) > 1) {
			if (s[r_ind]  != s[l_ind])
				return false;
			else {
				r_ind--;
				l_ind++;
			}
		}
		if (s[r_ind] != s[l_ind])
			return false;
		else return true;
	}
    string longestPalindrome(string s) {
    	int s_len = s.length();
    	int max_len = 1;
    	int max_l = 0;
    	string res; 
    	for (int i = 0; i < s_len; i++) {
    		for (int j = i + 1; j < s_len; j++)
    			if (isPalindrome(s, i, j)) {
    				int tmp_len = j - i + 1;
    				if (max_len < tmp_len) {
    					max_len = tmp_len;
    					max_l = i;
    				}
    			}
    	}
    	res = s.substr(max_l, max_len);
    	return res;
        
    }
};