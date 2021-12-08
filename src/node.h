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
        Node() {
            numeric_id = 0;
            views = 0;
            language = "";
        }

        Node(int id, int num_views, string lang) {
            numeric_id = id;
            views = num_views;
            language = lang;
        }

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

        // setters

        void set_views(int num_views) {
            views = num_views;
        }

        void set_numeric_id(int id) {
            numeric_id = id;
        }

        void set_language(string lang) {
            language = lang;
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
