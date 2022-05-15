//============================================================================
// Description : Hash Table
//============================================================================

#include <fstream>
#include <unordered_map>
#include <string>
#include <iostream>

#include <iostream>

#include "Store.h"

using namespace std;

int main() {

   cout << "Ryan Test " << endl; 
   
   Store myStore;
   
   myStore.initInventory("dataList.txt");
   myStore.addToCart(1,4);
   myStore.addToCart(5,3);
   if (abs(myStore.getTotal() - 101.90) < .001) {
      cout<<"Cart total is correct"<<endl;
   }
   else {
      cout <<"Cart total expected $101.90 actual: "<<myStore.getTotal();
   }
}
