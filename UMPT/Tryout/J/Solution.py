
s = input()
t = "michigan"
n = len(s)
mod = int(1e9 + 7)
dp = [[0 for i in range(n)] for j in range (8) ]
for i in range(8) :
  for j in range(n) :
    if j != 0 :
      dp[i][j] = dp[i][j-1]
    p = dp[i - 1][j - 1] if (i !=0 and j!=0) else 1
    if t[i] == s[j]:
      # print(t[i], s[j],i,j)
      dp[i][j] += p
    # print(dp[i][j])
    dp[i][j] = int(dp[i][j]) % mod
    # print(dp[i][j])
# print(dp)
# print(s)
print(dp[7][n-1])