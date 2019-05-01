#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
using namespace std;

int judge(char l){
    if((l>='0'&&l<='9')||(l>='a'&&l<='z')||(l>='A'&&l<='Z'))
        return 1;
    return 0;
}

int main(){
    string s;
    //存放每个单词
    vector<string> T;	
    int N;
    cin>>N;
    getchar();
    string Q[N];
    for(int i = 0;i<N;++i)
        getline(cin,Q[i]);
    for(int K = 0;K<N;++K){
        T.clear();		//清空s
        s = Q[K];
        cout<<s<<endl<<"AI: ";	
        //注意要先输出一遍s  在这里坑了无数遍
        for(int i =0;i<(int)s.size();++i)	
        //大小写转化，？变为！
            if(s[i]=='?')
                s[i]='!';
            else if(s[i]>='A'&&s[i]<='Z'&&s[i]!='I')
                s[i] = 'a'+s[i]-'A';
		
        //单词分割	
        for(int i = 0;i<(int)s.size();){		
        //i在循环内部增加 
            string S=" ";
            if(s[i]==' ')		//空格跳过 
                i++;
            else if(judge(s[i])){		//如果是数字或者字母 
                while(judge(s[i])&&i<(int)s.size())
                    S+=s[i++];
                T.push_back(S);
            }else{
                S=""; 
                while(s[i]!=' '&&i<(int)s.size())		
                //不是数字，字母和空格，则是标点符号 
                    S+=s[i++];
                T.push_back(S);
            }
        }
		
        //将i和me替换为you
        for(int i =0;i<(int)T.size();++i){
            if(T[i]==" I"||T[i]==" me")
                T[i] = " you";
            else if(T[i]==" you"){		
            //将 can you和 could you替换为I can 
                if(T[i-1]==" can"){
                    T[i-1]=" I";
                    T[i]=" can";
                }else if(T[i-1]==" could"){
                    T[i]=" could";
                    T[i-1] = " I"; 
                }
            }
        } 

		for(int i = 0;i<(int)T.size();++i){
            if(i==0){
                if(T[0][0]==' '){
                    for(int j = 1;j<T[0].size();++j)
                        cout<<T[0][j];
                }else
                    cout<<T[i];
            }else
                cout<<T[i];
        }
        if(K!=N-1)
        cout<<endl;
    }
    return 0;
}
