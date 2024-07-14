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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        ListNode merged = new ListNode();
        ListNode temp = merged;

        ListNode temp1 = list1;
        ListNode temp2 = list2;

        while (temp1!=null && temp2!=null){
            temp.next = new ListNode();
            temp=temp.next;
            if (temp1.val > temp2.val){
                temp.val = temp2.val;
                temp2 = temp2.next;
            } else {
                temp.val = temp1.val;
                temp1 = temp1.next;
            }
        }
        if (temp1 == null){
            temp.next = temp2;
        }
        if (temp2 == null){
            temp.next = temp1;
        }

        return merged.next;
        
    }
}