#include<bits/stdc++.h>
using namespace std;
class DocumentEditor{
    vector<string> elements;
    public:
    void addText(string text){
        elements.push_back(text);
    }
    void addImage(string path){
        elements.push_back(path);
    }
    string renderDocument(){
        string renderedDoc="";
        for(auto each:elements){
            if(each.length()>=4 && each.substr(each.length()-4,4)==".png")
                renderedDoc+="[IMG]"+each+"\n";
            else
                renderedDoc+=each+"\n";
        }
        return renderedDoc;
    }
    void saveToFile(){
        ofstream fout;
        fout.open("doc.txt");
        fout<<renderDocument();
        fout.close();
        cout<<"Saved to doc.txt"<<endl;
    }
};
int main(){
    DocumentEditor app;
    app.addText("Hello World");
    app.addImage("logo.png");
    app.addText("Logo ABC");
    app.addText("LC");
    app.renderDocument();
    app.saveToFile();
    return 0;
}