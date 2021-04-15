vector<int> solve(vector<int>& nums) {
  vector<int> res;
  if (nums.size() <= 1) return res;
  int n = nums.size();
  for (int i = 0; i != n; ++i) {
    bool a = i == 0 || nums[i] > nums[i - 1], b = i == n - 1 || nums[i] > nums[i + 1];
    if (a && b) res.push_back(i);
  }

  return res;
}