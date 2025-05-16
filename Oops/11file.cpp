#include<bits/stdc++.h>
using namespace std;
// int main(){
//     ofstream fout;
//     fout.open("abc.txt");
//     fout<<"Hefsdfdgllo"<<endl;
//     fout.close();
//     return 0;
// }
// int main(){
//     ifstream fin;
//     fin.open("vec1.txt");
//     string s;
//     while(!fin.eof()){
//         fin>>s;
//         cout<<s<<endl;
//         // ch=fin.get();ch=fin.get();
//     }
//     fin.close();
//     return 0;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> vec(n);
//     for(int i=0;i<n;i++){
//         cin>>vec[i];
//     }
//     ofstream fout;
//     fout.open("vec1.txt");
//     fout<<"Original Data :"<<endl;
//     for(auto each:vec){
//         fout<<each<<" ";
//     }
//     sort(vec.begin(),vec.end());
//     fout<<endl;
//     fout<<"Sorted Data :"<<endl;
//     for(auto each:vec)
//         fout<<each<<" ";
//     fout.close();
//     cout<<"Done"<<endl;
//     return 0;
// }
// Home work 
int main(){
    int val;
    vector<int> vec;
    ifstream fin;
    fin.open("vec.txt");
    fin.seekg(1);
    while(!fin.eof()){
        fin>>val;
        vec.push_back(val);
        cout<<val<<endl;
    }
    fin.close();
    sort(vec.begin(),vec.end());
    ofstream fout;
    fout.open("aaaa.txt");
    fout.seekp(20);
    fout<<"Sorted Data :"<<endl;
    for(auto each:vec)
        fout<<each<<" ";
    fout.close();
    cout<<"Done"<<endl;
    return 0;
}