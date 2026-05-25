#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val = 0, ListNode *next = nullptr)
        : val(val),
          next(next)
    {
    }
};

ListNode *make_list(std::vector<int> const &array)
{
    ListNode *head = nullptr, *tail = nullptr;
    for (int x : array)
    {
        if (!head)
        {
            head = tail = new ListNode(x);
            continue;
        }

        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return head;
}

void deallocate_list(ListNode *&head)
{
    if (!head)
    {
        return;
    }

    deallocate_list(head->next);
    delete head;
    head = nullptr;
}

void print_list(ListNode const *head)
{
    ListNode const *curr = head;
    while (curr)
    {
        std::cerr << curr->val << ' ';
        curr = curr->next;
    }
    std::cerr << '\n';
}

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        return reverse_k_group(head, k);
    }

private:
    ListNode *reverse_k_group(ListNode *head, int k)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *second_group = head;
        int not_in_first_group_cnt = k;
        for (int i = 1; i <= k && second_group; ++i)
        {
            --not_in_first_group_cnt;
            second_group = second_group->next;
        }

        if (not_in_first_group_cnt > 0)
        {
            return head;
        }

        ListNode *old_head = head;
        head = reverse_upto(head, second_group);
        old_head->next = reverse_k_group(second_group, k);
        return head;
    }

    ListNode *reverse_upto(ListNode *head, ListNode *upto)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *new_head = upto;
        while (head != upto)
        {
            ListNode *next_head = head->next;
            head->next = new_head;
            new_head = head;
            head = next_head;
        }
        return new_head;
    }
};

int main(int argc, char **argv)
{
    ListNode *list = make_list({1, 2, 3, 4, 5});
    int k = 2;
    Solution solution;
    ListNode *result = solution.reverseKGroup(list, k);
    print_list(result);

    deallocate_list(result);
}
