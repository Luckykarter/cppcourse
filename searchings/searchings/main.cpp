//
//  main.cpp
//  searchings
//
//  Created by Egor Wexler on 06/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    
    string s;
    vector<vector<string>> res;
    vector<string> r;
    vector<string>::iterator b;
    sort(products.begin(), products.end());
    
    for (char c: searchWord) {
        r.clear();
        s += c;
        b = products.begin();
        
        while(true) {
            b = find(b, products.end(), s);
            if(b == products.end()) break;
            r.push_back(*b);
        }
        if(!r.empty()) res.push_back(r);
    }
    
    return res;
    
    
}

template<typename T>
T cont(T v) {
    return v;
}

template<typename T>
void printV(T v){
    for_each(v.begin(), v.end(), [](auto c) {cout << c << " ";});
    cout << endl;
}

template<typename T, typename ... Args>
void printV(T first, Args ... args) {
    printV(first);
    printV(args ...);
}

template<typename T, typename ... Args>
T cont(T first, Args ... args) {
    return first + cont(args ...);
}

int main(int argc, const char * argv[]) {

    
    vector<int> vn = {1, 2, 3, 4};
    int sum = accumulate(vn.begin(), vn.end(), 1, multiplies<int>());
    cout << sum << endl;
    //string s1 = "quick", s2 = "brown", s3 = "fox", s4 = "jumps";
    //auto t = cont(s1, s2, s3, s4);
    
    vector<string> a1 = {"quick", "brown", "fox"}, a2 = {"jumps", "over", "the", "lazy", "dog"};
    
    printV(a1, a2, a1, a1, a2);
    
    
    
    //if(s1 == s2.substr(0, s1.size())) cout << "yes, prefix";
    //else cout << "no!" << endl;
    
}
