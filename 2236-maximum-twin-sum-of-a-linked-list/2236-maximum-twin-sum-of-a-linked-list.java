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
    public int pairSum(ListNode head) {

        List<Integer> sumList=new ArrayList();

        ListNode slow = new ListNode(0, head);
        ListNode fast = head;

        while (fast!=null && fast.next!=null){
            slow=slow.next;
            sumList.add(slow.val);
            fast=fast.next.next;
        }
        System.out.println(sumList);
        int i=sumList.size()-1;
        int max=0;
        int temp=0;

        while (slow.next!=null){
            slow=slow.next;
            temp=slow.val+sumList.get(i);
            if (temp > max){
                max = temp;
            }
            i--;
        }
        return max;

        
    }
}