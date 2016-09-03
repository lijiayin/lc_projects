#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
    	vector<int> twoSum(vector<int>& nums, int target) {
    		vector <int> res(2);
            map<int,int> value_map;
            int value_needed;
    		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
    			value_needed = target - *it;
    			map<int,int>::iterator j_it = value_map.find(value_needed);
    			if (j_it != value_map.end()){
    				//the other value is found
    				res[0] = j_it->second;
    				res[1] = it - nums.begin();
    				return res;
    			}
    			map<int,int>::iterator search_it = value_map.find(*it);
    			if (j_it == value_map.end()){
    				//insert value to hash table
    				value_map[*it] = it - nums.begin();
    			}

    		}
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