#include "graph.h"

Graph::Graph(string features_file, string edges_file) {
    std::cout << "entered graph ctor" << std::endl;

    // std::fstream fin_features(features_file);
    // std::fstream fin_edges(edges_file);

    // // checks that file is not in fail state (complains if file does not open properly)
    // if (fin_features.fail() || fin_edges.fail()) {
    //     std::cerr << "Error - Failed to open both files" << std::endl;
    //     exit(-1);
    // }

    // // to be placed in each node
    // int views, numeric_id;
    // string language;

    // // for ease of iteration
    // bool mature;
    // int lifetime;
    // string created_at;
    // string updated_at;
    // bool dead_acc;
    // bool affiliate;

    // // O(n) time
    // bool is_on_feature_headers = true;
    // while (fin_features >> views >> mature >> lifetime >> created_at >> updated_at >> numeric_id >> dead_acc >> language >> affiliate) {
    //     // prevents headers from getting read in
    //     if (is_on_feature_headers) {
    //         is_on_feature_headers = false;
    //         continue;
    //     }
    //     // unordered_map< int, unordered_map< int, Edge> > adj_list;
    //     data_map[numeric_id] = Node(numeric_id, views, language);


    // }

    // string edge_line, id;

    // // O(m) time
    // bool is_on_edge_headers = true;
    // while (getline(fin_edges, edge_line)) {
    //     // prevents headers from getting read in
    //     if (is_on_edge_headers) {
    //         is_on_edge_headers = false;
    //         continue;
    //     }

    //     std::stringstream s(edge_line);

    //     // iterates thru ONE row (id1, id2)
    //     vector<int> node_ids;
    //     // O(1) time bc its literally 2 elements
    //     // why is this showing an error??
    //     while(getline(s, id, ",")) {
    //         node_ids.push_back(std::stoi(id));
    //     }

    //     //data_map[node_ids[0]] is a node

    //     Node tmp_node_1 = data_map[node_ids[0]];
    //     Node tmp_node_2 = data_map[node_ids[1]];
    //     double weight = ((double) tmp_node_1.get_views() + (double) tmp_node_2.get_views()) / 2.0;

    //     Edge temp_edge1 = Edge(tmp_node_1, tmp_node_2, weight);
    //     unordered_map< int, Edge > tmp_map1;
    //     tmp_map1[node_ids[1]] = temp_edge1;
    //     adj_list[node_ids[0]] = tmp_map1;

    //     Edge temp_edge2 = Edge(tmp_node_2, tmp_node_1, weight);
    //     unordered_map< int, Edge > tmp_map2;
    //     tmp_map1[node_ids[0]] = temp_edge2;
    //     adj_list[node_ids[1]] = tmp_map2;

    //     // num_id_1 follows num_id_2 on twitch
        

    //}

}
