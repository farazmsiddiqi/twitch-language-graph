#pragma once

#include <iostream>
#include <string>

using std::string;

/**
 * This class will be used to hold a Node's data. 
 * DO NOT use this class to hold a vector of nodes. 
 * We will initialize a vector of nodes in another place.
 * 
 * Please remember and use **ALL** CS 126 codestyling.
 * 
 * Please remember to adhere to DRY coding, encapsulation,
 * variable naming, class design, object design, etc.
 * 
 **/
class Node {

    public:
        /**
         * Empty Node constructor. inits to default vals.
         **/
        Node();

        /**
         * Node ctor that sets values.
         **/
        Node(int id, int num_views, string lang);

        /**
         * tests to see if node class is linked with make file
         **/
        bool makefile_test_func();

        // getters
        int get_views() {
            return views;
        }

        int get_numeric_id() {
            return numeric_id;
        }

        string get_language() {
            return language;
        }

    private:

        /** 
         * The number of views a user's account has. 
         **/
        int views;

         /** 
         * unique node id (sequential, starting from 0). 
         **/
        int numeric_id; 

        /**
         * abbreviation representing the account native language (example: EN, RU, etc.). 
         **/
        string language;
};
