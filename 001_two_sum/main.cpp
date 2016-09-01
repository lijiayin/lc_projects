#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
    	vector<int> twoSum(vector<int>& nums, int target) {
    		vector <int> res;
        	for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
        		for (vector<int>::iterator j = i + 1; j != nums.end(); j++){
        			if (*i + *j == target){
        				res.push_back(*i);
        				res.push_back(*j);
        				return res;
        			}
        		}
        	}
        }
};

int main(){

	int value[] = {1,2,3,4,5};
	vector<int> input(value, value + sizeof(value) / sizeof(int) );
	int my_target = 9;
	Solution sol;
	vector<int> res = sol.twoSum(input, my_target);
	for (vector<int>::iterator i = res.begin(); i != res.end(); i++){
		cout<< *i <<endl;
	}
}
