#include <bits/stdc++.h>
using namespace std;

class laptop
{
    // By default private
    int price;
    float weight;

public:
    // Constructor
    laptop()
    {
        cout << "Constructor called" << endl;
        this->price = 10;
        this->weight = 1;
    }
    // Parameterized constructor
    laptop(int price, float weight)
    {
        this->price = price;
        this->weight = weight;
    }
    void setPrice(int p)
    {
        price = p;
    }
    void setWeight(float w)
    {
        weight = w;
    }
    int getPrice()
    {
        return price;
    }
    float getWeight()
    {
        return weight;
    }
};

int main()
{
    // laptop l1;
    // l1.setPrice(32000);
    // l1.setWeight(1.7);
    // cout << l1.getPrice() << endl;
    // cout << l1.getWeight() << endl;

    // // Creating dynamically
    // laptop *l2 = new laptop;
    // // 1st way
    // (*l2).setPrice(50000);
    // (*l2).setWeight(1.3);
    // cout << "Price of l2 : " << (*l2).getPrice() << endl;
    // cout << "Weight of l2 : " << (*l2).getWeight() << endl;
    // // Another way, using arrow (Only for pointers)
    // l2->setPrice(55000);
    // l2->setWeight(1.35);
    // cout << "Price of l2 : " << l2->getPrice() << endl;
    // cout << "Weight of l2 : " << l2->getWeight() << endl;

    // laptop l3;
    // cout << l3.getPrice() << endl;
    // cout << l3.getWeight() << endl;
    // laptop l3 = {50000, 1.3};
    laptop l3(50000, 1.3);
    cout << l3.getPrice() << endl;
    cout << l3.getWeight() << endl;

    // Copy constructor: copy l3 to l4
    laptop l4(l3);
    cout << l3.getPrice() << endl;
    cout << l3.getWeight() << endl;

    return 0;
}