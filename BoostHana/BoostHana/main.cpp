//
//  main.cpp
//  BoostHana
//
//  Created by Egor Wexler on 03/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMyAge(int& a){
    return a >= 13 && a <= 19;
}

int main(int argc, const char * argv[]) {
 
    auto myAge = [](int a) -> bool {return a >= 13 && a <= 19;};
    
    vector<int> ages = { 1, 2, 14, 15, 23, 43, 34, 23, 20, 14, 15, 18, 19, 99, 100};
    
    vector<int> ages1(count_if(ages.begin(), ages.end(), myAge));
    
    copy_if(ages.begin(), ages.end(), ages1.begin(), myAge);
    
    for (auto i: ages1) cout << i << " ";
    cout << endl;
    
    
    
    
}
