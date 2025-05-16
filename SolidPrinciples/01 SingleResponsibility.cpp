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
    int totalPrice;
    ShoppingCart(){
        totalPrice=0;
    }
    void addProduct(Product *p){
        cartItems.push_back(p);
        totalPrice+=p->price;
    }
    void calcTotalPrice(){
        totalPrice=0;
        for(auto each:cartItems)
            totalPrice+=each->price;
    }
    void display(){
        cout<<"Cart Items : "<<endl;
        for(auto each:cartItems){
            cout<<each->name<<" : $"<<each->price<<endl;
        }
        cout<<"Total : $"<<totalPrice<<endl;
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
        cout<<"Total : $"<<sc->totalPrice<<endl;
        cout<<"Thankyou Visit Again!!!"<<endl;
    }
};
class CartDBStorage{
    const ShoppingCart *sc;
    public:
    CartDBStorage(ShoppingCart *sc):sc(sc){}
    void saveToDB() const {
        cout<<"\n\nSaved in DB.."<<endl;
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
    CartPrintInvoice *cpi=new CartPrintInvoice(sc);
    cpi->printInvoice();
    CartDBStorage *cdbs=new CartDBStorage(sc);
    cdbs->saveToDB();
    
    delete cdbs;
    delete cpi;
    delete sc;
    delete watch;
    delete iphone;
    delete laptop;
    return 0;
}