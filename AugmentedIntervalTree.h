//
// Created by mercera on 3/21/22.
//

#ifndef INTERVAL_TREE_LAB_AUGMENTEDINTERVALTREE_H
#define INTERVAL_TREE_LAB_AUGMENTEDINTERVALTREE_H

#include "IntervalTree.h"

template<class T>
class AugmentedIntervalTree: public IntervalTree<T> {
private:
    bool _add(Node<T>*& node, T const& lower, T const& upper) {
        if (node == nullptr) {
            Interval<T> interval(lower, upper);
            node = new Node<T>(interval);
            return true;
        } else {
            if (lower < node->min_max.lower) {
                node->min_max.lower = lower;
            }
            if (upper > node->min_max.upper) {
                node->min_max.upper = upper;
            }
            if (lower < node->interval.lower) {
                return _add(node->left, lower, upper);
            }
            else if (lower > node->interval.lower) {
                return _add(node->right, lower, upper);
            }
            else {
                if (upper > node->interval.upper) {
                    return _add(node->right, lower, upper);
                }
                else if (upper < node->interval.upper) {
                    return _add(node->left, lower, upper);
                }
            }
        }

        return false;
    }

    vector<Interval<T>> _query(Node<T>* const& node, T const& point) const {
        vector<Interval<T>> retVec;
        if (node == nullptr) {
            return  retVec;
        }
        if (node->left != nullptr && point >= node->left->min_max.lower && point < node->left->min_max.upper) {
            vector<Interval<T>> temp = _query(node->left, point);
            retVec.insert(retVec.end(), temp.begin(), temp.end());
        }
        if (point >= node->interval.lower && point < node->interval.upper) {
            retVec.push_back(node->interval);
        }
        if (node->right != nullptr && point >= node->right->min_max.lower && point < node->right->min_max.upper) {
            vector<Interval<T>> temp = _query(node->right, point);
            retVec.insert(retVec.end(), temp.begin(), temp.end());
        }
        return retVec;
    }
public:
    AugmentedIntervalTree() {
        this->root = nullptr;
    }
    /*
     * Normally, a base class should manage all of its variables,
     * (i.e. delete root and its children)
     * but one purpose of this project is to let you figure that part out,
     * so, the child class should delete any relevant state.
     */
    ~AugmentedIntervalTree() {
        clear();
    }

    void clear() override {
        _clear(this->root);
        this->root = nullptr;
    }
    void _clear(Node<T> *&node) {
        if (node == nullptr) {
            return;
        }
        _clear(node->left);
        _clear(node->right);
        delete node;
    }
    bool is_empty() const {
        return this->root == nullptr;
    }
    /*
     * Add an interval to the tree
     * Make sure you update the min and max bounds on each node touched!
     */
    bool add(T const& lower, T const& upper) {
        return _add(this->root, lower, upper);
    }

    /*
     * Query for ALL intervals that overlap the given point
     * The output vector must be sorted
     * Hint: perform the binary search using an inorder traversal
     */
    vector<Interval<T>> query(T const& point) const {
        return _query(this->root, point);
    }
    /*
     * Remove the interval defined by the given lower and upper bounds
     * Be sure to update the min and max bounds for each node touched!
     */
    bool remove(T const& lower, T const& upper) {
        cout << "removing" << endl;
        return true;
    }
};



#endif //INTERVAL_TREE_LAB_AUGMENTEDINTERVALTREE_H
