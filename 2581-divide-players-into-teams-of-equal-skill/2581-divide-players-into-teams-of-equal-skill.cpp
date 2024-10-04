class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;

        sort(skill.begin(), skill.end());

        int left=0;
        int right=skill.size()-1;

        int sum = skill[left]+skill[right];
        while (left<right) {

            if (skill[left]+skill[right] != sum) return -1;

            ans+=(long long)(skill[left]*skill[right]);

            left++;
            right--;
        }

        return ans;
    }
};