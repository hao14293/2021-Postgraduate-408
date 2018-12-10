//#include <bits/stdc++.h>
//using namespace std;
//
//const int maxn = 1e5 + 10;
//
//struct Node{
//    char id[55];
//    int score;
//}node[maxn], s1[maxn], s2[maxn];
//
//Node asd;
//
//struct N3{
//    int room;
//    int ren;
//}num[maxn], endd[maxn];
//
//bool cmpp(const N3& a, const N3& b) {
//    if(a.ren != b.ren)
//        return a.ren > b.ren;
//    else return a.room < b.room;
//}
//
//bool cmp1(const Node& a, const Node& b) {
//    if(a.score != b.score)
//        return a.score > b.score;
//    else return strcmp(a.id, b.id) < 0;
//}
//
//int main() {
//    int N, M;
//    scanf("%d%d", &N, &M);
//    int zlr = 0;
//    for(int i = 1; i <= N; i ++) {
//        scanf("%s%d", asd.id, &asd.score);
//        if(asd.score >= 0 && asd.score <= 100) {
//            zlr ++;
//            node[zlr].score = asd.score;
//            strcpy(node[zlr].id, asd.id);
//        }
//    }
//
//
//    for(int t = 1; t <= M; t ++) {
//        int x;
//        char op[55];
//        scanf("%d %s", &x, op);
//        if(x == 1) {
//            int cnt1 = 0;
//            for(int i = 1; i <= zlr; i ++) {
//                if(node[i].id[0] == op[0]) {
//                    cnt1 ++;
//                    strcpy(s1[cnt1].id, node[i].id);
//                    s1[cnt1].score = node[i].score;
//                }
//            }
//            printf("Case %d: %d %s\n", t, x, op);
//            if(cnt1 == 0)
//                printf("NA\n");
//            else {
//                sort(s1 + 1, s1 + 1 + cnt1, cmp1);
//                for(int i = 1; i <= cnt1; i ++)
//                    printf("%s %d\n", s1[i].id, s1[i].score);
//            }
//        } else if(x == 2) {
//            int lx = strlen(op);
//            int c;
//            int renshu = 0, zf = 0;
//            for(int i = 1; i <= zlr; i ++) {
//                c = 0;
//                for(int j = 0; j < lx; j ++)
//                    if(node[i].id[j + 1] == op[j])
//                        c ++;
//                if(c == lx) {
//                    renshu ++;
//                    zf += node[i].score;
//                }
//            }
//            printf("Case %d: %d %s\n", t, x, op);
//            if(renshu == 0)
//                printf("NA\n");
//            else {
//                printf("%d %d\n", renshu, zf);
//            }
//        } else if(x == 3){
//            for(int kk = 0; kk < maxn; kk ++) {
//                endd[kk].ren = 0;
//                endd[kk].room = 0;
//                num[kk].ren = 0;
//                num[kk].room = 0;
//            }
//            int lc = strlen(op);
//            int d = 0;
//            int nnn = 0;
//            int naa = 0;
//            for(int i = 1; i <= zlr; i ++) {
//                d = 0;
//                for(int j = 0; j < lc; j ++) {
//                    if(node[i].id[j + 4] == op[j])
//                        d ++;
//                }
//                if(d == 6) {
//                    naa ++;
//                    int rec = 0;
//                    for(int h = 1; h <= 3; h ++)
//                        rec = rec * 10 + (node[i].id[h] - '0');
//                    num[rec].room = rec;
//                    num[rec].ren ++;
//                }
//            }
//            printf("Case %d: %d %s\n", t, x, op);
//            if(naa == 0)
//                printf("NA\n");
//            else {
//                for(int r = 0; r <= 999; r ++) {
//                    if(num[r].ren != 0) {
//                        nnn ++;
//                        endd[nnn].ren = num[r].ren;
//                        endd[nnn].room = num[r].room;
//                    }
//                }
//                sort(endd + 1, endd + 1 + nnn, cmpp);
//                for(int u = 1; u <= nnn; u ++)
//                    printf("%d %d\n", endd[u].room, endd[u].ren);
//            }
//        } else printf("Case %d: %d %s\nNA\n", t, x, op);
//    }
//    return 0;
//}


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct stu {
    string id;
    int sco;
};
struct site {
    string siteId;
    int cnt;
};
bool cmp1(const stu &a, const stu &b) {
    return a.sco == b.sco ? a.id < b.id : a.sco > b.sco;
}
bool cmp2(const site &a, const site &b) {
    return a.cnt == b.cnt ? a.siteId < b.siteId : a.cnt > b.cnt;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<stu> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].id >> v[i].sco;
    for (int i = 1; i <= k; i++) {
        int num;
        scanf("%d", &num);
        if (num == 1) {
            string level;
            cin >> level;
            printf("Case %d: %d %s\n", i, num, level.c_str());
            vector<stu> ans;
            for (int i = 0; i < n; i++) {
                if (v[i].id[0] == level[0])
                    ans.push_back(v[i]);
            }
            sort(ans.begin(), ans.end(),cmp1);
            for (int i = 0; i < ans.size(); i++)
                printf("%s %d\n", ans[i].id.c_str(), ans[i].sco);
            if (ans.size() == 0) printf("NA\n");
        } else if (num == 2) {
            int cnt = 0, sum = 0;
            int siteId;
            cin >> siteId;
            printf("Case %d: %d %d\n", i, num, siteId);
            vector<stu> ans;
            for (int i = 0; i < n; i++) {
                if (v[i].id.substr(1, 3) == to_string(siteId)) {
                    cnt++;
                    sum += v[i].sco;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
            else printf("NA\n");
        } else if (num == 3) {
            string date;
            cin >> date;
            printf("Case %d: %d %s\n", i, num, date.c_str());
            vector<site> ans;
            unordered_map<string, int> m;
            for (int i = 0; i < n; i++) {
                if (v[i].id.substr(4, 6) == date) {
                    string tt = v[i].id.substr(1, 3);
                    m[tt]++;
                }
            }
            for (auto it : m)
                ans.push_back({it.first, it.second});
            sort(ans.begin(), ans.end(),cmp2);
            for (int i = 0; i < ans.size(); i++)
                printf("%s %d\n", ans[i].siteId.c_str(), ans[i].cnt);
            if (ans.size() == 0) printf("NA\n");
        }
    }
    return 0;
}

