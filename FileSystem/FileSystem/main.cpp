//
//  main.cpp
//  FileSystem
//
//  Created by Egor Wexler on 06/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;
namespace fs = std::__fs::filesystem;

fs::path baseDir(".");
map<string, string> arguments;
map<string, string> PROMPTS = {
    {"-b", "Enter base directory: "},
    {"-d", "Enter directory: "},
    {"-f", "Enter filename: "}
};

void showUsage() {
    cerr    << "Usage:\n"
            << "\t-b Base directory\n"
            << "\t-h help\n"
            << "\t-d directory name\n"
            << "\t-f filename\n";
}

bool getArguments(const int& argc, const char* argv[]) {
    for(int i = 1; i < argc; ++i) {
        if((string)argv[i] == "-h"){
            showUsage();
            return false;
        }
        arguments.insert({argv[i], argv[++i]});
    }
    return true;
}

void read_dir(fs::path dir = baseDir) {
    if(is_directory(dir)) {
        int sw = 0;
        cout << dir << " contains: " << endl;
        for_each(fs::directory_iterator(dir), fs::directory_iterator(), [&](auto d) {
            cout << d.path().string();
            if(sw%2 == 0) {
              cout << "\t";
              if(d.path().string().length() < 8) cout << "\t";
            }
            else cout << "\n";
            ++sw;
        });
        if(sw%2 != 0) cout << "\n";
    }
    
    // Other ways to iterate
//    auto it = fs::directory_iterator(p);
//    while (it != fs::directory_iterator()) {
//        cout << it->path().string() << endl;
//        ++it;
//    }
   // cout << endl;
    
    //    vector<fs::directory_entry> v;
    //    copy(fs::directory_iterator(p), fs::directory_iterator(), back_inserter(v));
   // for(const auto& t: v) cout << (t).path().string() << endl;
    
}

void create_dir(fs::path dirName) {
    fs::path pp = baseDir / dirName;
    
    //cout << "Create directory: " << pp << endl;
    try {
        if(create_directory(pp)) {
            cout << "Directory " << pp << " created" << endl;
           // rename(pp, dirName);
        } else {
            cout << "Directory " << pp << " already exists" << endl;
        }
    } catch(fs::filesystem_error &e) {
        __1::cerr << e.what() << endl;
    }
}

string getName(string key) {
    string name;
    if (arguments.find(key) == arguments.end()){
        cout << PROMPTS[key];
        cin >> name;
    } else name = arguments[key];
    
    if (key=="-f" && name.find(".txt") == string::npos) name += ".txt";
    return name;
};

template<typename T>
void write_file(fs::path& path, vector<T>& content) {
    fs::path fpath = baseDir / path;
    ofstream ofs{fpath};
    copy(content.begin(), content.end(), ostream_iterator<T>(ofs, "\n"));
    ofs.close();
    cout << "File " << fpath << " created" << endl;
}

int main(int argc, const char * argv[]) {

    if(!getArguments(argc, argv)) return 0;
    baseDir = getName("-b");

    read_dir();

    vector<int> v1(10, 0);

    int increment = 0;
    for_each(v1.begin(), v1.end(), [&](int& i) { ++increment; i+= increment;});

    string dirName = getName("-d");
    create_dir(fs::path(dirName));
    //read_dir();

    string fileName = getName("-f");

    fs::path fpath(dirName);
    fpath /= fs::path(fileName);
    write_file(fpath, v1);
    
    return 0;
}
