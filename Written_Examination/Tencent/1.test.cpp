class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param S ListNode类 val表示权值，next指向下一个元素
     * @return ListNode类
     */
    ListNode* solve(ListNode* s) {
      if (s == nullptr) return s;
      if (s->next == nullptr) return s;

      int minval = findmin(s);
      int findlastone = findlast(s, minval);
      if (findlastone == -1) return s;
      ListNode *tmp = rotate(s, findlastone);
      return tmp;
    }
private:
    int findmin(ListNode* s) {
      ListNode* cur = s;
      int minval = 0;
      while (cur) {
        if (cur->val < minval) minval = cur->val;
        cur = cur->next;
      }
      return minval;
    }

    int findlast(ListNode* s, int target) {
      ListNode *cur = s;
      int last = -1;
      int cnt = 1;
      while (s->next) {
        if (s->next->val != target) {
          s = s->next;
        } else {
          if (s->val > s->next->val) last = cnt + 1;
        }
        cnt++;
      }
      return last;
    }
    ListNode* rotate(ListNode* s, int t) {
      ListNode *cur = s;
      ListNode *tail = s;
      t--;
      while (--t) {
        cur = cur->next;
      }
      while (tail->next) {
        tail = tail ->next;
      }
      ListNode*tmp = cur->next;
      tail->next = s;
      tmp->next = nullptr;
      return tmp;
    }
};