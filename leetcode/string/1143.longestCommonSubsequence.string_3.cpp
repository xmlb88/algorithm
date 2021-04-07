#include <iostream>
#include <string>
using namespace std;

// 递归
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    return dp(text1, text2, m - 1, n - 1);
}

int dp(string text1, string text2, int i, int j) {
    // base case
    if (i == -1 || j == -1) {
        return 0;
    }

    if (text1[i] == text2[j]) {
        return dp(text1, text2, i - 1, j - 1) + 1;
    } else {
        return max(dp(text1, text2, i - 1, j), dp(text1, text2, i, j - 1));
    }
}


// 备忘录
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> memo(m, vector<int> (n, -1));
    return dp(text1, text2, m - 1, n - 1, memo);
}

int dp(string text1, string text2, int i, int j, vector<vector<int>>& memo) {
    // base case
    if (i == -1 || j == -1) return 0;

    if (memo[i][j] != -1) return memo[i][j];
    if (text1[i] == text2[j]) {
        memo[i][j] = dp(text1, text2, i - 1, j - 1, memo) + 1;
    } else {
        memo[i][j] = max(dp(text1, text2, i, j - 1, memo), dp(text1, text2, i - 1, j, memo));
    }

    return memo[i][j];
}

// 超时
// "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny"
// "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan"

// dp数组迭代
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}


// review 2020年10月28日10:01:30
vector<vector<int>> memo;
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    memo.resize(m, vector<int> (n, -1));
    return dp(text1, 0, text2, 0);
}

int dp(string s1, int i, string s2, int j) {
    // base case
    if (i == s1.length() || j == s2.length()) return 0;
    // 之前被计算过
    if (memo[i][j] != -1) return memo[i][j];

    // 根据s1[i]和s2[j]的情况做选择
    if (s1[i] == s2[j]) {
        // s1[i]和s2[j]必然在lcs中
        memo[i][j] = 1 + dp(s1, i + 1, s2, j + 1);
    } else {
        // s1[i]和s2[j]至少一个不在lcs中
        memo[i][j] = max(dp(s1, i + 1, s2, j), dp(s1, i, s2, j + 1));
    }
    return memo[i][j];
}

// 迭代
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// review 2020年10月29日09:33:01
vector<vector<int>> memo;
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    memo.resize(m, vector<int> (n, -1));

}

int dp(string text1, int i, string text2, int j) {
    int m = text1.size(), n = text2.size();
    if (i == m || j == n) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    if (text1[i] == text2[j]) {
        memo[i][j] = 1 + dp(text1, i + 1, text2, j + 1);
    } else {
        mrmo[i][j] = max(dp(text1, i + 1, text2, j), dp(text1, i, text2, j + 1));
    }

    return memo[i][j];
}

// 方法2 迭代
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// LCS 
// review 2021年4月7日11:39:30
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}