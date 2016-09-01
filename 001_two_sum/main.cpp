#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
    	vector<int> twoSum(vector<int>& nums, int target) {
    		vector <int> res(2);
    		bool found = false;
        	for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
        		for (vector<int>::iterator j = i + 1; j != nums.end(); j++){
        			if (*i + *j == target){
        				res[0]=i-nums.begin();
        				res[1]=j-nums.begin();
        				found = true;
        				break;
        			}
        		}
        		if (found){
        		    break;
        		}
        		
        	}
        	return res;
        }
};

int main(){

	int value[] = {3,2,4};
	vector<int> input(value, value + sizeof(value) / sizeof(int) );
	int my_target = 6;
	Solution sol;
	vector<int> res = sol.twoSum(input, my_target);
	for (vector<int>::iterator i = res.begin(); i != res.end(); i++){
		cout<< *i <<endl;
	}
}
