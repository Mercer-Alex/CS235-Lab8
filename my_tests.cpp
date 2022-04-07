#include "AugmentedIntervalTree.h"

int main() {
    AugmentedIntervalTree<int> tree;

    test("is empty", tree.is_empty(), true);
    vector<Interval<int>> queryTest = {Interval<int>(3, 10), Interval<int>(4, 8), Interval<int>(5, 8), Interval<int>(5, 10)};
    vector<Interval<int>> emptyQuery;
    string emptyString = "";
    string temp = "   [5, 10)<[5, 10)>\n"
                      "[5, 8)<[5, 10)>";

    test("add interval 5, 8", tree.add(5, 8), true);
    test("add interval 5, 10", tree.add(5, 10), true);

    test("compare tree structure", tree.to_string(), tree.to_string());

    test("add interval, 4, 8", tree.add(4, 8), true);
    test("add interval 1, 2 again", tree.add(1, 2), true);
    test("add interval 3, 10", tree.add(3, 10), true);

    test("query for point 5", tree.query(5), queryTest);
    test("query for point 43", tree.query(43), emptyQuery);

    cout << tree.to_string();

    tree.clear();
    test("testing emtpy string", tree.to_string(), emptyString);

    return 0;
}