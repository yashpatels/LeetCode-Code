/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {

        ListNode ans = new ListNode (0);

        if (head==null) return null;
        if (head.next==null) return head;

        ListNode prev = ans;
        ListNode temp = head;
        int i=0;

        while (temp!=null && temp.next != null){
            System.out.println("prev: " +prev.val + " temp: " +temp.val);
            prev.next = temp.next;
            temp.next = prev.next.next;
            prev.next.next = temp;
            prev = temp;
            temp = temp.next;
        }
        return ans.next;
    }
}