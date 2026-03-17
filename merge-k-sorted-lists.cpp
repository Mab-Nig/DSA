#include <iostream>
#include <queue>
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
    ListNode *mergeKLists(std::vector<ListNode *> const &lists)
    {
        return merge_k_lists(lists);
    }

private:
    ListNode *merge_k_lists(std::vector<ListNode *> const &lists)
    {
        struct ItersCmp
        {
            bool operator()(ListNode const *node_1, ListNode const *node_2)
            {
                if (!node_1 || !node_2)
                {
                    return node_1;
                }

                return node_1->val > node_2->val;
            }
        };

        std::vector<ListNode *> iterators;
        for (auto list : lists)
        {
            iterators.push_back(list);
        }

        std::priority_queue<ListNode *, std::vector<ListNode *>, ItersCmp> pq;
        for (auto iter : iterators)
        {
            pq.push(iter);
        }

        std::vector<int> result;
        while (!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();

            if (!top)
            {
                continue;
            }

            result.push_back(top->val);
            pq.push(top->next);
        }
        return make_list(result);
    }

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

    friend int main(int argc, char **argv);
};

int main(int argc, char **argv)
{
    Solution solution;
    std::vector<ListNode *> lists = {solution.make_list({1, 4, 5}),
                                     solution.make_list({1, 3, 4}),
                                     solution.make_list({2, 6})};
    for (auto list : lists)
    {
        print_list(list);
    }
    ListNode *merged_list = solution.mergeKLists(lists);
    print_list(merged_list);

    for (auto list : lists)
    {
        deallocate_list(list);
    }
    deallocate_list(merged_list);
}
