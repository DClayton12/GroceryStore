/*
 * Darnel Clayton
 * 7/12/2014
 * CS162
 * Assignment 2
 */

#ifndef STOREINTERFACE_H
#define STOREINTERFACE_H
using std::string;
namespace grocer{
class item{
private:
	double price,salePrice;
	string name,description;
public:
	item(double cost,string title,string detail, double discount);
        void setPrice(double &cost);
	void setSale(double &discount);
	void setName(string &title);
	void setDescription(string &detail);
	double getPrice();
	double getSale();
	string getName();
	string getDescription();
};
void menu(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);
void optionCheck(int &x);
void doubleCheck(double &x);
void userExit(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);
void international(double &total,int &selection,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);

void produce(double &total,int &selection,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);

void bakery(double &total,int &selection,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);
void ringUp(double &total,item *itemPTR[], int &selection,bool show_International[]);
void ringupProduce(double &total,item *producePTR[], int &selection,bool show_Produce[]);
void ringupBakery(double &total,item *bakeryPTR[], int &selection,bool show_Bakery[]);
void displayItem(item *itemPTR[], int &selection);
void addInternational2Cart(double &total, item *itemPTR[], int &selection, bool show_International[]);
void addProduce2Cart(double &total, item *itemPTR[], int &selection, bool show_Produce[]);
void addBakery2Cart(double &total,item *itemPTR[], int &selection, bool show_Bakery[]);
void viewCart(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);
void checkOUT(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);
void clearCart(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]);
}
#endif
