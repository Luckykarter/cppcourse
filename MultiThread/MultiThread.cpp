// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

mutex m;
condition_variable cv;
map<int, bool>processed;
map<int, bool>go;
const int THREADS = 15;
vector<thread> threads;
void single_thread(const int&);

void start_all() {
    for (auto& g : go) g.second = true;
}

void initiate_threads() {
    for (int i = 1; i <= THREADS; ++i) {
        threads.push_back(thread(single_thread, i));
        go[i] = false;
        processed[i] = false;
    }
}
void fire_threads() {
    for (auto& t : threads) t.join();
}
bool all_done() {
    return all_of(processed.begin(), processed.end(), [](pair<int, bool>x) -> bool {return x.second;});
}


void single_thread(const int& id) {
    unique_lock<mutex>lock(m);
    cv.wait(lock, [id] {return go[id] || processed[id];});
    if (!processed[id])
        cout << "thread " << id << " processed" << endl;
    processed[id] = true;
    lock.unlock();
    cv.notify_all();
}

int main()
{
    cout << "start processing" << endl;
    initiate_threads();
    cout << "threads are waiting. Start?" << endl;
    char prompt;
    cin >> prompt;
    
    if (tolower(prompt) == 'y') {
        
        start_all();
        cv.notify_all();
        //lock_guard<mutex> lock(m);

        //wait for threads
        unique_lock<mutex> lock(m);
        cv.wait(lock, [] {return all_done();});
        //cv.wait(lock, all_done());
        
    }
    else {
        for (auto& p : processed) p.second = true;
        cv.notify_all();
    }
    cout << "we are done" << endl;
    fire_threads();
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project g> Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
