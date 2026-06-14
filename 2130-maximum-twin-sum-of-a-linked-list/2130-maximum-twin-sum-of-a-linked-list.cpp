/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        int result = 0;
        int i = 0; int j = 0;
        while(head != NULL)
        {
            values.push_back(head->val);
            head = head -> next;
            j++;
        }
        j--;

        while(i < j)
        {
            int sum = values[i] + values[j];
            if(result < sum)
            {
                result = sum;
            }
            i++;
            j--;
        }
        return result;
    }
};