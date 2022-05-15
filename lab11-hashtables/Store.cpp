#include <fstream>
#include "Store.h"

#include <iostream>
using namespace std;


Store::Store() {
   cartTotal = 0; 

}

void Store::initInventory(std::string dataFile) {

   ifstream file;
   file.open(dataFile);

   uint32_t itemNum;
   float price;

   if (file.is_open()) 
   {
      while (!file.eof()) 
      {
         uint32_t itemNum;
         float price;
         file >> itemNum >> price;
         inventory.insert(std::pair<uint32_t, float>(itemNum, price));
      }
   }
   else {
      cout << "File not found" << endl;
   }
   file.close(); 
}

void Store::clearCart() {
   cartTotal = 0;
}

void Store::addToCart(uint32_t itemNum, uint32_t quantity) {

   if (inventory.find(itemNum) != inventory.end()) {
      cartTotal += (inventory[itemNum] * quantity);
   }
   else {
      cout << "Item not found" << endl;
   }
}

float Store::getCost(uint32_t itemNum) {

   if (inventory.find(itemNum) != inventory.end()) {
      return inventory[itemNum];
   }
   else {
      cout << "Item not found" << endl;
      return -1;
   }
}

float Store::getTotal() {
   return cartTotal;
}