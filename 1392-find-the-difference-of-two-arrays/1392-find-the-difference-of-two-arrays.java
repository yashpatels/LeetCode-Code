class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {

        HashMap<Integer, Integer> n1 = new HashMap<>();
        HashMap<Integer, Integer> n2 = new HashMap<>();

        List<Integer> a1 = new ArrayList();
        List<Integer> a2 = new ArrayList();

        for (int j=0; j<nums2.length; j++){
            n2.put(nums2[j], nums2[j]);
        }

        for (int i=0; i<nums1.length; i++){
            if (!n2.containsValue(nums1[i])){
                a1.add(nums1[i]);
                n2.put(nums1[i], nums1[i]);

            }
            n1.put(nums1[i], nums1[i]);
        }

        for (int i=0; i<nums2.length; i++){
            if (!n1.containsValue(nums2[i])){
                a2.add(nums2[i]);
                n1.put(nums2[i], nums2[i]);
            }
        }

        List<List<Integer>> ans = new ArrayList();
        ans.add(a1);
        ans.add(a2);

        return ans;
        
    }
}