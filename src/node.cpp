#include "node.h"

bool Node::makefile_test_func() {
    return true;
}

Node::Node() {
    numeric_id = -1;
    views = 0;
    language = "";
}

Node::Node(int id, int num_views, string lang) {
    numeric_id = id;
    views = num_views;
    language = lang;
}