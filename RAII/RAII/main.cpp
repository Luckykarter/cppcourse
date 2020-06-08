//
//  main.cpp
//  RAII
//
//  Created by Egor Wexler on 07/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class dem {
private:
    int id;
public:
    explicit dem(const int& i) : id(i) {
        cout << "dem with id " << id << " constructed" << endl;
    }
    
    ~dem() {
        cout << "dem with id " << id << " destructed" << endl;
    }
    
};

void test() {
    int test;
    cin >> test;
    if (test > 0) throw runtime_error("bad code!");
    else cout << "all is fine" << endl;
}

int main(int argc, const char * argv[]) {
    dem d1(1);
    dem d2(2);
    dem d3(3);
    try {
        test();
    } catch (runtime_error & e) {
        cout << e.what() << endl;
    }
    

    
    
}
