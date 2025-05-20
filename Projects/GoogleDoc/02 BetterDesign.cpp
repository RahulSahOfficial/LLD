#include<bits/stdc++.h>
using namespace std;
class DocumentElement{
    public:
    virtual string render()=0;
};
class TextElement:public DocumentElement{
    string text;
    public:
    TextElement(string text){
        this->text=text;
    }
    string render() override {
        return text;
    }
};
class ImageElement:public DocumentElement{
    string imagePath;
    public:
    ImageElement(string imagePath){
        this->imagePath=imagePath;
    }
    string render() override {
        return "[IMG]"+imagePath;
    }
};
class NewLineElement:public DocumentElement{
    public:
    string render(){
        return "\n";
    }
};
class Document{
    vector<DocumentElement *> elements;
    public:
    void addElement(DocumentElement *newElement){
        elements.push_back(newElement);
    }
    string render(){
        string renderedDoc="";
        for(auto each:elements)
            renderedDoc+=each->render();
        return renderedDoc;
    }
};
class Persistence{
    public:
    virtual void save(string)=0;
};
class SaveToFile:public Persistence{
    public:
    void save(string data) override{
        ofstream fout;
        fout.open("doc.txt");
        fout<<data;
        fout.close();
        cout<<"Saved to doc.txt"<<endl;
    }
};
class DocumentEditor{
    Document *document;
    Persistence *storage;
    public:
    DocumentEditor(Document *document,Persistence *storage){
        this->document=document;
        this->storage=storage;
    }
    void addText(string text){
        document->addElement(new TextElement(text));
    }
    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }
    void addNewLine(){
        document->addElement(new NewLineElement());
    }
    string renderDocument(){
        return document->render();
    }
    void saveToFile(){
        storage->save(renderDocument());
    }
};
int main(){
    Document *doc=new Document();
    Persistence *storage=new SaveToFile();
    DocumentEditor *editor=new DocumentEditor(doc,storage);
    editor->addText("Hello World");
    editor->addNewLine();
    editor->addImage("logo.png");
    editor->addNewLine();
    editor->addText("Logo ABC");
    editor->addNewLine();
    editor->addText("LC");
    editor->addNewLine();
    cout<<editor->renderDocument();
    editor->saveToFile();
    return 0;
}