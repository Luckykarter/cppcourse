// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void disp_v(const T& v) {
    if (!v.size()) return;
    for (auto e : v) { cout << e << " "; }
    cout << endl;
}

template <typename T>
const bool is_prime(const T& num) {
    if (num <= 1) return false;
    
    for (T l = 2; l < num; ++l) {
        if (num % l == 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool is_even_tens(T& n) {
    if (n < 10) return false;
    return ((n / 10) % 2) == 0;
}

const bool isTrue(const bool& b) {
    return b;
}

const bool isOdd(const int& n) {
    return n % 2 != 0;
}

int main()
{
    // prime numbers < 100
    vector<int> v1 = { 83, 84, 88, 53, 43, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };

    disp_v(v1);
    sort(v1.begin(), v1.end());
    disp_v(v1);

    int n = 83;
    // binary search works only on sorted containers
    if (binary_search(v1.begin(), v1.end(), n)) cout << "found " << n << endl;
    else cout << "not found " << n << endl;

    //all of
    if (all_of(v1.begin(), v1.end(), is_prime<int>)) {
        cout << "all are prime numbers" << endl;
    }
    else
    {
        cout << "not all are prime numbers" << endl;
    }

    vector<bool> b1 = { true, true, true };
    if (none_of(b1.begin(), b1.end(), [](bool b) -> bool {return b;}))
        cout << "all are true" << endl;
    else
        cout << "not all are true" << endl;
     
    //any_of
    //none_of
    cout << endl << "FIND: " << endl;
    //FIND

    vector<int>::iterator it = find(v1.begin(), v1.end(), 5); // returns iterator
    size_t index = it - v1.begin();
    cout << "found " << *it << " at position " << index << endl;

    // conditional search
    //find_if_not
   
    it = find_if(v1.begin(), v1.end(), [](auto n) -> bool {return n % 2 == 0;}); //find first even number
    index = it - v1.begin();
    cout << "first even number is " << *it << " found at position " << index << endl;

    //count
    auto c = count(v1.begin(), v1.end(), 7);
    cout << "found " << c << " occurences of seven" << endl;

    c = count_if(v1.begin(), v1.end(), isOdd);
    cout << "found " << c << " odd numbers" << endl;

    // replace
    replace(v1.begin(), v1.end(), 47, 999);
    disp_v(v1);

    //replace_if(v1.begin(), v1.end(), isOdd, 0);
    disp_v(v1);

    //remove

    vector<int>::iterator ir = remove(v1.begin(), v1.end(), 999);
    if (ir == v1.end()) cout << "no elements removed" << endl;
    else v1.resize(ir - v1.begin());

    disp_v(v1);

    ir = remove_if(v1.begin(), v1.end(), [](int n) -> bool {return n % 2 == 0;});
    if (ir == v1.end()) cout << "no elements removed" << endl;
    else v1.resize(ir - v1.begin());

    disp_v(v1);

    // remove non-unique items
    ir = unique(v1.begin(), v1.end());
    if (ir == v1.end()) cout << "no elements removed" << endl;
    else v1.resize(ir - v1.begin());
    disp_v(v1);

    // copy 
    vector<int> v2(v1.size(), 0);
    disp_v(v2);
    
    copy(v1.begin(), v1.end(), v2.begin());
    // copy_n - copies n elements
    disp_v(v2);

    reverse_copy(v1.begin(), v1.end(), v2.begin());
    disp_v(v2);

    reverse(v2.begin(), v2.end()); // reverse in-place
    disp_v(v2);

    // fill - fills container with elements
    fill(v1.begin(), v1.end() - 15, 100);
    // fill_n  -fills n elements
    disp_v(v1);

    //generate - fills using function
    generate(v2.begin(), v2.end(), []() -> int {return rand() % 100;});
    disp_v(v2);

    //partition - splits the container accoring to a given condition
    partition(v1.begin(), v1.end(), is_even_tens<int>);
    disp_v(v1);

    size_t sz = count_if(v1.begin(), v1.end(), is_even_tens<int>);
    vector<int> v3(sz), v4(v1.size() - sz);

    // split and copy into two vectors based on a predicate function
    partition_copy(v1.begin(), v1.end(), v3.begin(), v4.begin(), is_even_tens<int>);

    disp_v(v1);
    disp_v(v3);
    disp_v(v4);

    //sort
    sort(v1.begin(), v1.end());
    sort(v3.begin(), v3.end());
    disp_v(v1);
    disp_v(v3);

    //merge - merges two sorted sequences into one
    v4.resize(v1.size() + v3.size()); //v4 stays sorted
    merge(v1.begin(), v1.end(), v3.begin(), v3.end(), v4.begin());
    disp_v(v4);

    //binary search
    if (binary_search(v1.begin(), v1.end(), 100)) cout << "found number 100" << endl;
    else cout << "100 not found" << endl;
    it = lower_bound(v1.begin(), v1.end(), 47);
    cout << "lower bound " << *it << endl;

    //upper bound
    // both bounds as a pair
    pair<vector<int>::iterator, vector<int>::iterator> pr = equal_range(v4.begin(), v4.end(), 41);
    cout << "lower bound " << *pr.first << endl;
    cout << "upper bound " << *pr.second << endl;


}


