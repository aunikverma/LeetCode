class Solution {
    public int distinctSubseqII(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;
        int Mod = 1000000007;
        HashMap<Character, Integer> mp = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            char ch = s.charAt(i - 1);
            dp[i] = (dp[i - 1] * 2) % Mod;
            if (mp.containsKey(ch)) {
                int last_ind = mp.get(ch);
                dp[i] = (dp[i] - dp[last_ind - 1] + Mod) % Mod;
            }
            mp.put(ch, i);
        }
        dp[n] = (dp[n] - 1 + Mod) % Mod;
        return dp[n];
    }
}