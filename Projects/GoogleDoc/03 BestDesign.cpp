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
    vector<DocumentElement *> getElements(){
        return elements;
    }
};
class DocumentRenderer{
    Document *doc;
    public:
    DocumentRenderer(Document *doc){
        this->doc=doc;
    }
    string renderDocument(){
        string renderedDoc="";
        for(auto each:doc->getElements())
            renderedDoc+=each->render();
        return renderedDoc;
    }
};
class DocumentEditor{
    Document *document;
    public:
    DocumentEditor(Document *document){
        this->document=document;
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
};
class Persistence{
    public:
    virtual void save(Document *doc)=0;
};
class SaveToFile:public Persistence{
    public:
    void save(Document *doc) override{
        DocumentRenderer *renderer=new DocumentRenderer(doc);
        ofstream fout;
        fout.open("doc.txt");
        fout<<renderer->renderDocument();
        fout.close();
        cout<<"Saved to doc.txt"<<endl;
    }
};
int main(){
    Document *doc=new Document();
    Persistence *storage=new SaveToFile();
    DocumentEditor *editor=new DocumentEditor(doc);
    DocumentRenderer *renderer=new DocumentRenderer(doc);
    editor->addText("Hello World");
    editor->addNewLine();
    editor->addImage("logo.png");
    editor->addNewLine();
    editor->addText("Logo ABC");
    editor->addNewLine();
    editor->addText("LC");
    editor->addNewLine();
    cout<<renderer->renderDocument();
    storage->save(doc);
    return 0;
}