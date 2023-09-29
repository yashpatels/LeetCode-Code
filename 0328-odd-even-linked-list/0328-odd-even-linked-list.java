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
    public ListNode oddEvenList(ListNode head) {

        ListNode odd = new ListNode (0,head);
        ListNode even = new ListNode();
        ListNode temp = even;
        ListNode prev;

        while (odd!=null && odd.next!=null){
            odd = odd.next;
            if (odd.next!=null){
                ListNode tempx = new ListNode(odd.next.val);
                temp.next=tempx;
                temp = temp.next;
            
            // System.out.println(odd.next.val);
                odd.next = odd.next.next;
            }
        }
        even=even.next;
        // return head;
        // odd=even;
        odd.next=even;
        return head;

    }
}