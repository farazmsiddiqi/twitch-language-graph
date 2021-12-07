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

        // /** 
        //  * A flag determining whether the user has set their account to 'mature' (profanity, nsfw, etc).
        //  **/
        // bool mature;

        // /** 
        //  * An integer representing the amount of days since account creation (updated_at - created_at). 
        //  **/
        // int life_time;

        // /** 
        //  * A string containing the date the account was created ( [m]m/[d]d/yy ). 
        //  **/
        // string created_at;

        // /** 
        //  * When this node's data was last updated ( [m]m/[d]d/yy ). 
        //  **/
        // string updated_at;

        // /**
        //  * bool representing whether the account is active or not.
        //  * 
        //  * An inactive [(dead)] account is defined as an account
        //  * that has had no login, viewing, or broadcasting activity
        //  * for at least twelve months.
        //  * 
        //  * https://blog.twitch.tv/en/2017/01/06/username-rename-recycling-policy-update-882431cb966b/
        //  **/
        // bool dead_account; 

        // /**
        //  * bool representing whether the account is an affiliate or not.
        //  * 
        //  * AFFILIATE REQUIREMENTS
        //  * 1. At least 500 total minutes broadcast in the last 30 days
        //  * 2. At least 7 unique broadcast days in the last 30 days
        //  * 3. An average of 3 concurrent viewers or more over the last 30 days
        //  * 4. At least 50 Followers
        //  * 
        //  * https://help.twitch.tv/s/article/joining-the-affiliate-program?language=en_US#:~:text=Affiliate%20Eligibility,-The%20criteria%20for&text=At%20least%20500%20total%20minutes,At%20least%2050%20Followers
        //  **/
        // bool affiliate; 
};
