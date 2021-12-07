#include "graph.h"

Graph::Graph(string features_file, string edges_file) {
    std::cout << "entered graph constructor" << std::endl;
    std::fstream fin_features(features_file);
    std::fstream fin_edges(edges_file);

    // checks that file is not in fail state (complains if file does not open properly)
    if (fin_features.fail() || fin_edges.fail()) {
        std::cerr << "Error - Failed to open both files" << std::endl;
        exit(-1);
    }

    // to be placed in each node
    int views, numeric_id;
    string language;

    // for ease of iteration
    bool mature;
    int lifetime;
    string created_at;
    string updated_at;
    bool dead_acc;
    bool affiliate;

    //while (fin_features >> views >> mature >> lifetime >> created_at >> updated_at >> numeric_id >> dead_acc >> language >> affiliate) {}

    string edge_line, id;

    // O(m) time
    int edge_csv_line_counter = 0;
    while (getline(fin_edges, edge_line)) {
        // prevents headers from getting read in
        if (edge_csv_line_counter == 0) {
            continue;
        }
        edge_csv_line_counter += 1;

        std::stringstream s(edge_line);

        // iterates thru ONE row (id1, id2)
        vector<int> node_ids;
        // O(1) time bc its literally 2 elements
        while(getline(s, id, ",")) {
            node_ids.push_back(std::stoi(id));
        }

        // at this point, we have access to num_id_1 --> node_ids[0] and num_id_2 --> node_ids[1] from edges.csv
        Node tmp_node_1 = Node(node_ids[0], 0, "");
        Node tmp_node_2 = Node(node_ids[1], 0, "");

        double weight = ((double) tmp_node_1.get_views() + (double) tmp_node_2.get_views()) / 2.0;

        // DICT IMPL: adj_list[tmp_node_1].push_back(pair<Node, double>(tmp_node_2, weight));

        // num_id_1 follows num_id_2 on twitch

        // if node doesnt exist in node_vec
        vector< pair<Node, double> > tmp_vec;

        // how do I construct the adjacency list??????
        tmp_vec.push_back(std::make_pair(tmp_node_1, weight));
        tmp_vec.push_back(std::make_pair(tmp_node_2, weight));
        adj_list.push_back(tmp_vec);

    }


    int feature_csv_line_counter = 0;
    while (fin_features >> views >> mature >> lifetime >> created_at >> updated_at >> numeric_id >> dead_acc >> language >> affiliate) {
        // prevents headers from getting read in
        if (feature_csv_line_counter == 0) {
            continue;
        }
        feature_csv_line_counter += 1;

        Node tmp_node = Node(numeric_id, 0, "");
    }





    
}