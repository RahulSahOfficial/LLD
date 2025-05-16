#include<bits/stdc++.h>
using namespace std;
class Product{
    public:
    string name;
    int price;
    Product(string name,int price):name(name),price(price){}
};
class ShoppingCart{
    public:
    vector<Product *> cartItems;
    void addProduct(Product *p){
        cartItems.push_back(p);
    }
    int calculateTotalPrice () const{
        int totalPrice=0;
        for(auto each:cartItems)
            totalPrice+=each->price;
        return totalPrice;
    }
    void display(){
        cout<<"Cart Items : "<<endl;
        for(auto each:cartItems){
            cout<<each->name<<" : $"<<each->price<<endl;
        }
        cout<<"Total : $"<<calculateTotalPrice()<<endl;
    }
};
class CartPrintInvoice{
    const ShoppingCart *sc;
    public:
    CartPrintInvoice(ShoppingCart *sc):sc(sc){}
    void printInvoice() const{
        cout<<"\n\nPrinting Invoice : "<<endl;
        for(auto each:sc->cartItems)
            cout<<each->name<<" : $"<<each->price<<endl;
        cout<<"Total : $"<<sc->calculateTotalPrice()<<endl;
        cout<<"Thankyou Visit Again!!!"<<endl;
    }
};
//abstract class
// made const so the db persistance cannot change the cart items only read
class DBPersistence{
    public:
    const ShoppingCart *sc;
    virtual void save() const =0;
};
class SaveToSQLDB:public DBPersistence{
    public:
    SaveToSQLDB(ShoppingCart *sc){
        this->sc=sc;
    }
    void save() const override{
        cout<<"Saved to SQL DB"<<endl;
    }
};
class SaveToMongoDB:public DBPersistence{
    public:
    SaveToMongoDB(ShoppingCart *sc){
        this->sc=sc;
    }
    void save() const override{
        cout<<"Saved to MongoDB"<<endl;
    }
};
class SaveToFile:public DBPersistence{
    public:
    SaveToFile(ShoppingCart *sc){
        this->sc=sc;
    }
    void save() const override{
        cout<<"Saved to File"<<endl;
    }
};
int main(){
    Product *watch=new Product("Rolex",33000);
    Product *iphone=new Product("Iphone",399);
    Product *laptop=new Product("Dell Inspiron",1299);
    ShoppingCart *sc=new ShoppingCart();
    sc->addProduct(watch);
    sc->addProduct(iphone);
    sc->addProduct(laptop);
    sc->display();
    CartPrintInvoice *printer=new CartPrintInvoice(sc);
    printer->printInvoice();

    DBPersistence *sqlDB=new SaveToSQLDB(sc);
    DBPersistence *mongoDB=new SaveToMongoDB(sc);
    DBPersistence *file=new SaveToFile(sc);
    sqlDB->save();
    mongoDB->save();
    file->save();
    
    delete sqlDB;
    delete mongoDB;
    delete file;
    delete printer;
    delete sc;
    delete watch;
    delete iphone;
    delete laptop;
    return 0;
}