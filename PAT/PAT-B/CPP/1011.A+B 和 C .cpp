#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long int a, b, c;
        cin >> a >> b >> c;
        string result;
        result = a+b>c?"true":"false";
        cout<<"Case #"<< i+1 << ": " << result << endl;
    }
    return 0;
}
