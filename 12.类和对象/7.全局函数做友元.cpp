#include <iostream>
#include <string>
using namespace std;

// 在程序里， 有些私有属性也想让类外的特殊的一些函数访问, 就需要用到友元
// 友元关键字 friend

class Building {
    // 友元关键字 friend
    friend void test(Building &bd);
    friend void test1(Building *bd);
    
    public:
        string sittingRoom; // 客厅

        Building() {
            sittingRoom = "客厅";
            badRoom = "卧室";
        }

    private:
        string badRoom; //卧室

};

void test(Building &bd) {
    cout << "全局函数访问： " << bd.sittingRoom << endl;
    cout << "全局函数访问： " << bd.badRoom << endl;
};

void test1(Building *bd) {
    
    cout << "quan: " << bd->sittingRoom << endl;
    cout << "quan: " << bd->badRoom << endl;

}

int main() {
    Building bd;
    test(bd);
    test1(&bd);
    return 0;
}