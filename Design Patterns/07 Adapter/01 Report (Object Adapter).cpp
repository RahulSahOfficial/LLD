#include<bits/stdc++.h>
using namespace std;
class IReport{
    public:
    virtual string getJSONData()=0;
};
class XMLDataProvider{
    public:
    string getXMLData(){
        return "XML";
    }
};
class XMLDataProviderAdapter:public IReport{
    XMLDataProvider *pro;
    string XMLToJSON(string xml){
        return "JSON";
    }
    public:
    XMLDataProviderAdapter(XMLDataProvider *pro){
        this->pro=pro;
    }
    string getJSONData(){
        string xml=pro->getXMLData();
        string json=XMLToJSON(xml);
        return json;
    }
};
class Client{
    public:
    string getReport(IReport *rep){
        return rep->getJSONData();
    }
};
int main(){
    IReport *adapter=new XMLDataProviderAdapter(new XMLDataProvider());
    Client *client=new Client();
    cout<<client->getReport(adapter)<<endl;
    return 0;
}