#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    char filename[40], ch, buf[100];
    fstream iofile, cpiofile;
    cout << "Please filename name:";
    cin >> filename;
    iofile.open(filename, ios::out);
    if (!iofile) {
        cerr << "Can not open " << filename;
        exit(1);
    }
    cout << "Please input text:\n";

    //第一种写入
    /*cin.get(ch);  //吃掉缓冲区回车
    while (cin.get(ch)) {
        if (ch == '#') {
            break;
        }
        iofile << ch;
    }*/

    //第二种写入
    cin>>buf;
    iofile<<buf;

    iofile.close();
    iofile.open(filename, ios::in);
    if (!iofile) {
        cerr << "Can not open " << filename;
        exit(2);
    }
    cout << "You input text is:\n";

//    第一种
    /*while (iofile.get(ch)) {
        cout << ch;
    }*/

//    第二种
    iofile>>buf;
    cout << buf;
    cout << endl;

    cout << "Please input copy file name:";
    cin >> filename;
    cpiofile.open(filename, ios::out);
    if (!cpiofile) {
        cerr << "Can not open " << filename;
        exit(3);
    }
    iofile.clear();  //重置状态
    iofile.seekg(ios::beg);  //回到文件开始处
    while (iofile.get(ch)) {
        cpiofile << ch;
    }
    cpiofile.close();
    iofile.close();
    return 0;
}
