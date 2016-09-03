/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	int checkLength(ListNode* l){
		int len = 0;
		ListNode *point = l;
		while(point->next){
			len ++;
			point = point->next;
		}
		return len;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *short_l, *long_l;
        if (checkLength(l1) < checkLength(l2)){
        	short_l = l1;
        	long_l = l2;
        }
        else{
        	short_l = l2;
        	long_l = l1;
        }
        ListNode *solution = new ListNode(0);
        ListNode *sol_point = solution;
        int carrier = 0;
        while(long_l){
        	if (short_l){
        		sol_point->val =  (short_l->val + long_l->val + carrier) % 10;
        		carrier = (short_l->val + long_l->val + carrier) / 10;
        		short_l = short_l->next;
            }
            else{
         		sol_point->val =  (long_l->val + carrier) % 10;
        		carrier = (long_l->val + carrier) / 10;        	
            }
            long_l = long_l->next;
            if (long_l){
        	    ListNode *sol_nex = new ListNode(0);
        	    sol_point->next = sol_nex;
        	    sol_point = sol_nex;
            }
            else if (carrier){
        	    ListNode *sol_nex = new ListNode(1);
        	    sol_point->next = sol_nex;
            }
        }
        return solution;
    }
};