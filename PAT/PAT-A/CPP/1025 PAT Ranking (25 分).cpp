#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct student {
    long long int no;
    int score, finrank, local, localrank;
};
bool cmp1(student a, student b) {
    return a.score != b.score ? a.score > b.score : a.no < b.no;
}
int main() {
    int n, m;
    scanf("%d", &n);
    vector<student> fin;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        vector<student> v(m);
        for(int j = 0; j < m; j++) {
            scanf("%lld %d", &v[j].no, &v[j].score);
            v[j].local = i;
        }
        sort(v.begin(), v.end(), cmp1);
        v[0].localrank = 1;
        fin.push_back(v[0]);
        for(int j = 1; j < m; j++) {
            v[j].localrank = (v[j].score == v[j - 1].score) ? (v[j - 1].localrank) : (j + 1);
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp1);
    fin[0].finrank = 1;
    for(int j = 1; j < fin.size(); j++)
        fin[j].finrank = (fin[j].score == fin[j - 1].score) ? (fin[j - 1].finrank) : (j + 1);
    printf("%d\n", fin.size());
    for(int i = 0; i < fin.size(); i++)
        printf("%013lld %d %d %d\n", fin[i].no, fin[i].finrank, fin[i].local, fin[i].localrank);
    return 0;
}
