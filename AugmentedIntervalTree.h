//
// Created by mercera on 3/21/22.
//

#ifndef INTERVAL_TREE_LAB_AUGMENTEDINTERVALTREE_H
#define INTERVAL_TREE_LAB_AUGMENTEDINTERVALTREE_H

#include "IntervalTree.h"

template<class T>
class AugmentedIntervalTree: public IntervalTree<T> {
protected:

    /*
     * You'll need to delete this node and its children in your destructor
     */
    Node<T>* root;

    /*
     * You don't need to do anything with this method.
     * It's a helper method for the public to_string method down below.
     */
    string _to_string(Node<T>* const& node, int depth) const {
        stringstream ss;
        if (node->right != nullptr) {
            ss << _to_string(node->right, depth+1);
        }
        for (int i = 0; i < depth; i++) {
            ss << "   ";
        }
        ss << node->interval;
        ss << "<" << node->min_max << ">" << endl;
        if (node->left != nullptr) {
            ss << _to_string(node->left, depth+1);
        }
        return ss.str();
    }

public:
    AugmentedIntervalTree() : root(nullptr) {}
    /*
     * Normally, a base class should manage all of its variables,
     * (i.e. delete root and its children)
     * but one purpose of this project is to let you figure that part out,
     * so, the child class should delete any relevant state.
     */
    ~AugmentedIntervalTree() {
        cout << "destructor" << endl;
    }

    /*
     * Should delete all the intervals in the tree
     */
    void clear() {
        cout << "clearing" << endl;
    }
    /*
     * Returns true if there are no intervals in the tree
     */
    bool is_empty() const {
        cout << "empty?" << endl;
        return true;
    }
    /*
     * Add an interval to the tree
     * Make sure you update the min and max bounds on each node touched!
     */
    bool add(T const& lower, T const& upper) {
        cout << "adding" << endl;
        return true;
    }
    /*
     * Query for ALL intervals that overlap the given point
     * The output vector must be sorted
     * Hint: perform the binary search using an inorder traversal
     */
    vector<Interval<T>> query(T const& point) const {
        cout << "query" << endl;
    }
    /*
     * Remove the interval defined by the given lower and upper bounds
     * Be sure to update the min and max bounds for each node touched!
     */
    bool remove(T const& lower, T const& upper) {
        cout << "removing" << endl;
        return true;
    }

    /*
     * A handy method for visualizing the structure of the tree
     * You don't need to override this, but you may find it useful
     *   in writing tests and debugging
     */
    string to_string() const {
        if (root == nullptr) { return ""; }
        return _to_string(root, 0);
    }
};



#endif //INTERVAL_TREE_LAB_AUGMENTEDINTERVALTREE_H
