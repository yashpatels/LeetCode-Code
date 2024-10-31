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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode();
        dummy.next = head;

        ListNode temp = head;
        int len=0;

        while (temp!=null) {
            temp = temp.next;
            len++;
        }

        int k=len-n;
        temp=dummy;
        ListNode dummy1 = head;
        
        while(k!=0) {
            temp=temp.next;
            k--;
        }
        if (temp.next!=null) temp.next=temp.next.next;
        return dummy.next;
    }
}