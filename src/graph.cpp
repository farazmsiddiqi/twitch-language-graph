#include "graph.h"

Graph::Graph(string features_file, string edges_file) {
    std::cout << "entered graph constructor" << std::endl;
    std::fstream fin(features_file);

    // checks that file is not in fail state (complains if file does not open properly)
    if (fin.fail()) {
        std::cerr << "Error - Failed to open " << features_file << std::endl;
        exit(-1);
    }

    // to be placed in each node
    int views, numeric_id;
    string language;

    bool mature;
    int lifetime;
    string created_at;
    string updated_at;
    bool dead_acc;
    bool affiliate;


    int counter = 0;

    while (fin >> views >> mature >> lifetime >> created_at >> updated_at >> numeric_id >> dead_acc >> language >> affiliate && counter < 8) {
        if (counter < 5) {
            std::cout << views << mature << lifetime << std::endl;
        }
        ++counter;
    }

    
    
}