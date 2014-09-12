/*
 * Darnel Clayton
 * 7/12/2014
 * CS162
 * Assignment 2
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "storeinterface.h"
using std::cin;
using std::cout;
using std::endl;

namespace grocer{
item::item(double cost,string title,string detail, double discount){
	setPrice(cost);
	setName(title);
	setDescription(detail);
	setSale(discount);}
void item::setPrice(double &cost){price=cost;}
void item::setSale(double &discount){salePrice=discount;}
void item::setName(string &title){name=title;}
void item::setDescription(string &detail){description=detail;}
double item::getPrice(){return price;}
double item::getSale(){return salePrice;}
string item::getName(){return name;}
string item::getDescription(){return description;}

void menu(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
int selection=0;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   ***** Welcome to the C++ Grocery Store *****\n"
"\n"
"Shopping Guide:\n"
"        -Select category of clothing\n"
"\t-Compare prices\n"
"\t-Review Descriptions\n"
"\t-Pay with Cash or Credit (Pay with Cash and receive change!)\n"
"\n"
"Select [1] to enter the INTERNATIONAL AISLE  \n"
"Select [2] to enter the PRODUCE AISLE\n"
"Select [3] to enter the BAKERY AISLE\n"
"Select [4] to view your SHOPPING CART\n"
"Select [5] to exit the C++ GROCERY STORE\n"
"\n"
"** Current Cart total is: $"<<total<<"**\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
    int option = 0;
    while (option != 5) {
        cin>>option;
        optionCheck(option);
	switch(option) {
            case 1:
                international(total,selection,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
                break;
            case 2:
                produce(total,selection,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
                break;
            case 3:
                bakery(total,selection,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
                break;
            case 4:
                viewCart(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
                break;
            case 5:
		userExit(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
	}   
    }
}
void userExit(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
int pick=0;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"              *****THANK YOU FOR VISITING!*****\n"
"   *****PLEASE COME AGAIN!  ENJOY YOUR DAY!*****\n"
"\n"
" *****SELECT [1],[2],[3] OR,[4] TO RETURN TO THE MAIN MENU*****\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>pick;
optionCheck(pick);
if(pick==1||pick==2||pick==3||pick==4){
menu(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
if(pick==5){
exit(EXIT_FAILURE);}
}
void optionCheck(int &x){
        while(cin.fail()){//Check that input in numerical and 1 or 2. Will loop till input is satisfactory.
        cin.fail();
        cout<<"ERROR: Selection must be either [1],[2],[3],[4],OR [5].\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;}//Re-enter input.
        while(x<1||x>5){
        cin.fail();
        cout<<"ERROR: option must be either [1],[2],[3],[4],OR [5].\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;}//Re-enter input.
}
void international(double &total,int &selection,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   ***** YOU ARE IN THE INTERNATIONAL AISLE!*****\n"
"   ***** ONLY AVAILABLE ITEMS ARE SHOWN *****\n";
for(int i=0;i<4;i++){
if(show_International[i]==true){
cout<<endl<<"   *****Select ["<<i+1<<"] for the item below*****  "<<endl;
displayItem(itemPTR,i);}
}
cout<<"\n"
"** Current Cart total is: $"<<total<<"   **\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>selection;
optionCheck(selection);
if(show_International[selection-1]==true){
if(selection==1||selection==2||selection==3||selection==4){
ringUp(total,itemPTR, selection,show_International);}
}
if(show_International[selection-1]==false){
international(total,selection,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
if(selection==5){
menu(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
}
void produce(double &total,int &selection,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   ***** YOU ARE IN THE PRODUCE AISLE!*****\n"
"   ***** ONLY AVAILABLE ITEMS ARE SHOWN *****\n";
for(int i=0;i<4;i++){
if(show_Produce[i]==true){
cout<<endl<<"   *****Select ["<<i+1<<"] for the item below*****  "<<endl;
displayItem(producePTR,i);}
}
cout<<"\n"
"** Current Cart total is: $"<<total<<"   **\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>selection;
optionCheck(selection);
if(show_Produce[selection-1]==true){
if(selection==1||selection==2||selection==3||selection==4){
ringupProduce(total,producePTR, selection,show_Produce);}
}
if(show_Produce[selection-1]==false){
produce(total,selection,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
if(selection==5){
menu(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
}
void bakery(double &total,int &selection,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   ***** YOU ARE IN THE BAKERY AISLE!*****\n"
"   ***** ONLY AVAILABLE ITEMS ARE SHOWN *****\n";
for(int i=0;i<4;i++){
if(show_Bakery[i]==true){
cout<<endl<<"   *****Select ["<<i+1<<"] for the item below*****  "<<endl;
displayItem(bakeryPTR,i);}
}
cout<<"\n"
"** Current Cart total is: $"<<total<<"   **\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>selection;
optionCheck(selection);
if(show_Bakery[selection-1]==true){
if(selection==1||selection==2||selection==3||selection==4){
ringupBakery(total,bakeryPTR, selection,show_Bakery);}
}
if(show_Bakery[selection-1]==false){
bakery(total,selection,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
if(selection==5){
menu(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
}
void ringUp(double &total,item *itemPTR[], int &selection,bool show_International[]){
int option=0;
cout<<"  *~*~*~*   YOU SELECTED AN ITEM!   *~*~*~*\n"
"        *****   \""<<itemPTR[selection-1]->getName()<<"\"   *****\n"
"Description: \""<<itemPTR[selection-1]->getDescription()<<"\"\n"
"Sale Price: "<<itemPTR[selection-1]->getSale()<<"\n"
"Price: $"<<itemPTR[selection-1]->getPrice()<<"\n"
"\n   *~*~*~*   ADD TO YOUR CART?   *~*~*~*\n"
"Select [1],[2],[3] OR,[4] to add this item to your cart.\n"
"Select [5] to cancel the item.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
cin>>option;
optionCheck(option);
if(option==1||option==2||option==3||option==4){
addInternational2Cart(total,itemPTR, selection,show_International);}
if(option==5){
return;}
}
void ringupProduce(double &total,item *producePTR[], int &selection,bool show_Produce[]){
int option=0;
cout<<"  *~*~*~*   YOU SELECTED AN ITEM!   *~*~*~*\n"
"        *****   \""<<producePTR[selection-1]->getName()<<"\"   *****\n"
"Description: \""<<producePTR[selection-1]->getDescription()<<"\"\n"
"Sale Price: "<<producePTR[selection-1]->getSale()<<"\n"
"Price: $"<<producePTR[selection-1]->getPrice()<<"\n"
"\n   *~*~*~*   ADD TO YOUR CART?   *~*~*~*\n"
"Select [1],[2],[3] OR,[4] to add this item to your cart.\n"
"Select [5] to cancel the item.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
cin>>option;
optionCheck(option);
if(option==1||option==2||option==3||option==4){
addProduce2Cart(total,producePTR, selection,show_Produce);}
if(option==5){
return;}
}
void ringupBakery(double &total,item *bakeryPTR[], int &selection,bool show_Bakery[]){
int option=0;
cout<<"  *~*~*~*   YOU SELECTED AN ITEM!   *~*~*~*\n"
"        *****   \""<<bakeryPTR[selection-1]->getName()<<"\"   *****\n"
"Description: \""<<bakeryPTR[selection-1]->getDescription()<<"\"\n"
"Price: $"<<bakeryPTR[selection-1]->getPrice()<<"\n"
"Sale Price: "<<bakeryPTR[selection-1]->getSale()<<"\n"
"\n   *~*~*~*   ADD TO YOUR CART?   *~*~*~*\n"
"Select [1],[2],[3] OR,[4] to add this item to your cart.\n"
"Select [5] to cancel the item.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
cin>>option;
optionCheck(option);
if(option==1||option==2||option==3||option==4){
addBakery2Cart(total,bakeryPTR, selection,show_Bakery);}
if(option==5){
return;}
}
void displayItem(item *itemPTR[], int &selection){
cout<<"        *****   \""<<itemPTR[selection]->getName()<<"\"   *****\n"
"Description: \""<<itemPTR[selection]->getDescription()<<"\"\n"
"Suggested Store Price: $"<<itemPTR[selection]->getSale()<<"\n"
"Sale Price: $"<<itemPTR[selection]->getPrice()<<"\n"<<endl;}

void addInternational2Cart(double &total, item *itemPTR[], int &selection, bool show_International[]){
if(selection!=5){
show_International[selection-1]=false;}//Item is now in cart and out of inventory
total=total+itemPTR[selection-1]->getPrice();
cout<<"New total is: $"<<total<<endl;
return;}

void addProduce2Cart(double &total, item *producePTR[], int &selection, bool show_Produce[]){
if(selection!=5){show_Produce[selection-1]=false;}//OOS
total=total+producePTR[selection-1]->getPrice();
cout<<"New total is: $"<<total<<endl;
return;}

void addBakery2Cart(double &total,item *bakeryPTR[], int &selection, bool show_Bakery[]){
if(selection!=5){show_Bakery[selection-1]=false;}//OOS
total=total+bakeryPTR[selection-1]->getPrice();
cout<<"New total is: $"<<total<<endl;
return;}

void viewCart(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
char empty='n';//Empty Cart. Set bools to true. Total =$0.00
cout<<"\t      *****YOU ARE NOW IN YOUR SHOPPING CART*****\n"
"Contents:\n"
"\n"
"ITEMS FROM INTERNATIONAL AISLE:\n";
for(int i=0;i<=4;i++){//only show items shopper selected AND confirmed to place in cart.
if(show_International[i]==false){
cout<<"        *****   \""<<itemPTR[i]->getName()<<"\"  $"<<itemPTR[i]->getPrice()<<"    *****\n";}
}
cout<<"\n"
"ITEMS FROM PRODUCE AISLE:\n";
for(int i=0;i<=4;i++){
if(show_Produce[i]==false){
cout<<"        *****   \""<<producePTR[i]->getName()<<"\"  $"<<producePTR[i]->getPrice()<<"    *****\n";}
}
cout<<"\n"
"ITEMS FROM BAKERY AISLE:\n";
for(int i=0;i<=4;i++){
if(show_Bakery[i]==false){
cout<<"        *****   \""<<bakeryPTR[i]->getName()<<"\"  $"<<bakeryPTR[i]->getPrice()<<"    *****\n";}
}
cout<<"Total Cost is: $"<<total<<endl<<"Do you wish to empty your cart?"<<endl;
cout<<"Select [Y] to empty your cart. Select any other key to return to the main menu."<<endl;
cout<<"Select [P] to checkout and pay for the items in your cart."<<endl;

while(empty!='y'||empty!='Y'||empty!='p'||empty!='P'){
cin>>empty;
if(empty=='y'||empty=='Y'){
clearCart(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
if(empty=='p'||empty=='P'){
checkOUT(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
cout<<"Please input [Y] to empty cart OR [P] to process payment.\n";}
}

void checkOUT(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
double userMoney=0.00,userChange=0.00;
char pay='n';
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<"Select [C] to checkout and pay with a CREDIT CARD."<<endl;
cout<<"Select [D] to checkout and pay with CASH.";
while(pay!='c'||pay!='C'||pay!='d'||pay!='D'){
cin>>pay;

if(pay=='c'||pay=='C'){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<" $ "<<total<<" has been charged to your credit card. Thank you for shopping with us!"<<endl;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
total=0.00;
clearCart(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
userExit(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}

if(pay=='d'||pay=='D'){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<" $ "<<total<<" is the total cost Shopper. How much cash do you have to pay with?"<<endl;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;

cin>>userMoney;
doubleCheck(userMoney);
	while(userMoney<total){
	cout<<"Hello Shopper that is not enough money unfortunately. Please input more money."<<endl;
	cin>>userMoney;
	doubleCheck(userMoney);}
userChange=userMoney-total;
total=0.00;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<" $ "<<userChange<<" is your change! Thank you for shopping with us!"<<endl;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
clearCart(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
userExit(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
cout<<"Please input [C] to pay with credit card OR [D] to pay with cash and press [ENTER].\n";
}
}

void doubleCheck(double &x){
while(cin.fail())//Check that input in numerical. Will loop till input is satisfactory.
        {
        cin.fail();
        cout<<"ERROR: Input must be entered in numerical value .\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter input as an integer."<<endl;
        cin>>x;//Re-enter input.
        }
}  

void clearCart(double &total,item *itemPTR[],bool show_International[],item *producePTR[],bool show_Produce[],item *bakeryPTR[],bool show_Bakery[]){
total=0.00;
for(int i=0;i<5;i++){
show_International[i]=true;
show_Produce[i]=true;
show_Bakery[i]=true;}
cout<<"SHOPPING CART EMPTIED! 0 CONTENTS!"<<endl;
menu(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);}
}
