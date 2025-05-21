/*
*******************************************************************************
compile with g++ -o random_abc random_abc.cpp
run with ./random_abc
*******************************************************************************
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <cstdlib>
#include <random>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;
#define ll long long
#define vecint vector<int>
#define vecstr vector<string>
#define vecll vector<long long>
#define vecbl vector<bool>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;

struct ContestConfig {
    int start_year;
    const int start_month;
    const int start_day;
    const int start_contest_number;
    const int contest_interval_days;
};



void get_current_contest_number(int &held_cnt) {
    const ContestConfig config = {2025, 5, 17, 406, 7};

    tm tm_start = {}; //初期化
    tm_start.tm_year = config.start_year - 1900; // 年は1900年からのオフセット
    tm_start.tm_mon = config.start_month;
    tm_start.tm_mday = config.start_day;
    time_t start_time = mktime(&tm_start);
    int contest_interval_days = config.contest_interval_days;
    int start_contest_number = config.start_contest_number;

    //今日の日付を取得
    time_t now = time(nullptr);

    int days_passed = 0;



    int add = days_passed / contest_interval_days;


    held_cnt = start_contest_number + add; // 数が合わない　明日ここを修正する
    
}

void random_value(int contestant_cnt, int &random_number) {
    random_number = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, contestant_cnt);
    random_number = dis(gen);
}


int main() {
    int held_cnt = 0;

    get_current_contest_number(held_cnt);
    cout << "the current number of contests held is " << held_cnt << endl; //show now contestant number
    // cout << "now: " << time(nullptr) << endl; // debug

    // cout << "if that number is not correct, please input 1. (otherwise input 0)" << endl; // ask if the number is correct
    // int choose = 0;
    // cin >> choose;

    // if (choose == 1) {
    //     cout << "please input the number of contests" << endl; // input correct contest number
    //     cin >> held_cnt;
    // } else {
    //     cout << "ok. please wait..." << endl; // if the number is correct, continue
    // }

    if (held_cnt <= 0) {
        cout << "Invalid number of contests." << endl;
        return 1;
    }

    int random_number;
    random_value(held_cnt, random_number);


    // 3桁ゼロ埋めで出力
    cout << "thanks. you should solve problem number " << setfill('0') << setw(3) << random_number << "!" << endl;
    cout << "it will transition automatically. please wait..." << endl;

    //open target website (3桁ゼロ埋め)
    ostringstream oss;
    oss << "https://atcoder.jp/contests/abc" << setfill('0') << setw(3) << random_number;
    string url = oss.str();
    cout << url << endl; //debug
    system(("xdg-open " + url).c_str());

    return 0;
}