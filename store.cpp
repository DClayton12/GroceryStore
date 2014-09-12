/*
 * Darnel Clayton
 * 7/12/2014
 * CS162
 * Assignment 2
 * Overview: This program emulates shopping at a grocery store. I track items in inventory with array or item pointers and bool array. In stock list is displayed with display(), Out of stock/in shopping cart list is displayed with viewCart().
 */

#include <iostream>
#include "storeinterface.h"
using std::cin;
using std::cout;
using std::endl;
using grocer::item;
using grocer::menu;

int main(){
double total=0.00,userPay=0.00;

item mango(16.99,"Mango","Ripe mango ready to eat! Great with the smallest pinch of sugar.",17.99);
item brownrice(9.99,"Brown Rice","Brown Jasmine Rice. Possibilities are endless. One pound bag..",10.99);
item coconut(5.49,"Coconut","It's a coconut! Enjoy!",5.99);
item spice(15.99,"Spice","Jar and shaker of Caribbean Classic Style Spices. Spice up your life.",17.99);
item *itemPTR[4]={&mango,&brownrice,&coconut,&spice};
bool show_International[5]={true,true,true,true,true};//This array of bool valriables will serve to display items in current inventory, and items Out of Stock/in shopping cart.

item kale(15.99,"Kale"," Green superfood, great for smoothies! Many vitamins for brain power \"The MIND is a powerful tool\"",17.99);
item tomato(16.75,"Red Tomato","Did you know a tomato is a fruit?",23.25);
item spinach(20.20,"Green Spinach","The finest spinach to be had. Be strong like Popeye!",33.55);
item carrot(10.99,"Carrot","It's a carrot. Chop it up to make baby carrots.",19.75);
item *producePTR[4]={&kale,&tomato,&spinach,&carrot};
bool show_Produce[5]={true,true,true,true,true};

item redcake(18.35,"Red Velvet Cake","This cake is red. Tastes like Chocolate.",22.59);
item bluecake(15.99,"Blue Velvet Cake", "This cake is blue. Tastes like Chocolate.",22.29);
item donuts(13.99,"Gray Jeans","Slim fitting jeans.",15.99);
item cookies(21.75,"Cookie Assortment","Assortment of cookies made from the best cookie dough. Ever.",29.99);
item *bakeryPTR[4]={&redcake,&bluecake,&donuts,&cookies};
bool show_Bakery[5]={true,true,true,true,true};

menu(total,itemPTR,show_International,producePTR,show_Produce,bakeryPTR,show_Bakery);
return 0;
}

