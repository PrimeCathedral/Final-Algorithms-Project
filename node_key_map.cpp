#include <iostream> 
#include "Node.hpp"
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<Node<int>, int> MyMap;
    Node<int> MyNode {Node<int>(7)};

    MyMap[MyNode] = 3;
    //cout << MyMap[MyNode] << endl;

    for (const auto& pair : MyMap) {
        cout << pair.first.get_color() << endl;
    }
    return 0;
}