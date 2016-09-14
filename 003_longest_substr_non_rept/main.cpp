class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int s_len = s.length();
    	int l_index = 0;
    	int r_index = 0;
    	int max_len = 0;
    	int tmp_len;

		unordered_map<char,int> hash;
    	if (s_len <= 1){
    		return s_len;
    	}
    	
    	r_index = 0; 
    	
    	while (r_index < s_len){

    		if (hash.find(s[r_index]) == hash.end() or hash[s[r_index]] == 0){
    			hash[s[r_index]] = 1;
    			tmp_len = r_index - l_index + 1;
    		}
    		else {
    			while(s[r_index] != s[l_index]){
    			    hash[s[l_index]] = 0;
    				l_index++;
    			}
    			//hash[s[r_index]] = 0;
    			l_index++;
    			tmp_len = r_index - l_index + 1;
    		}
    		if (tmp_len >= max_len) {
    			max_len = tmp_len;
    		}
    		r_index++;
    	}
    	return max_len;
    }
};

//better version
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int s_len = s.length();
    	int l_index = 0;
    	int r_index = 0;
    	int max_len = 0;
    	int tmp_len;

		unordered_map<char,int> hash;
    	if (s_len <= 1){
    		return s_len;
    	}
    	
    	while (r_index < s_len){

    		if (hash.find(s[r_index]) == hash.end() or hash[s[r_index]] < l_index){
    			tmp_len = r_index - l_index + 1;
    		}
    		else {
    			l_index = hash[s[r_index]] + 1;
    			tmp_len = r_index - l_index + 1;
    		}
    		hash[s[r_index]] = r_index;
    		if (tmp_len >= max_len) {
    			max_len = tmp_len;
    		}
    		r_index++;
    	}
    	return max_len;
    }
};