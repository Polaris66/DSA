/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        vector<Node *> Original_List;
        Original_List.push_back(head);

        vector<Node *> New_List;

        Node *Head = new Node(head->val);
        New_List.push_back(Head);
        Node *temp = head;
        Node *Prev = Head;

        while ((temp->next) != nullptr)
        {
            temp = temp->next;
            Original_List.push_back(temp);
            Node *Next = new Node(temp->val);
            Prev->next = Next;
            Prev = Next;
            New_List.push_back(Prev);
        }

        int n = Original_List.size();
        for (int i = 0; i < n; i++)
        {
            Node *original_node = Original_List[i];
            Node *New_node = New_List[i];
            if (original_node->random == nullptr)
            {
                New_node->random == nullptr;
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (original_node->random == Original_List[j])
                    {
                        New_node->random = New_List[j];
                        break;
                    }
                }
            }
        }

        return Head;
    }
};
// @lc code=end
