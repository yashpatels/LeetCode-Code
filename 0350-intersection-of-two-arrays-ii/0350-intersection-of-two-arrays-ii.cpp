class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        sort(nums1.begin(), nums1.end());

        sort(nums2.begin(), nums2.end());


        int n1=0;
        int n2=0;

        while (n1<nums1.size() && n2<nums2.size()) {

            if (nums1[n1] == nums2[n2]) {
                ans.push_back(nums1[n1]);
                n1++;
                n2++;
            } else if (nums1[n1] > nums2[n2]) {
                n2++;
            } else {
                n1++;
            }

        }
        return ans;
    }
};