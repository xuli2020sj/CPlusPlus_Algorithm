#include "src/DataStructure/Tree.h"
#include <iostream>
#include <memory>


using namespace datastructure;
using namespace std;
int main() {
    Tree xTree;
    xTree.insert(4);
    xTree.insert(8);
    xTree.insert(1);
    xTree.insert(3);
    xTree.insert(9);
    xTree.insert(7);

    Tree xTree2;
    xTree2.insert(8);
    xTree2.insert(1);
    xTree2.insert(3);
    xTree2.insert(4);
    xTree2.insert(9);
    xTree2.insert(7);
    cout << xTree2.equals(xTree2) << endl;
    cout << "preOrderTraverse" << endl;
    xTree.preOrderTraverse();
    cout << "end" << endl;
    cout << "min value in the tree: " << xTree.minVal() << endl;
    cout << "height is: " << xTree.height() << endl;
    return 0;
}
