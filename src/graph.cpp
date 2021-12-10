#include "graph.h"

Graph::Graph(string features_file, string edges_file) {
    std::cout << "entered graph ctor" << std::endl;

    std::fstream fin_features(features_file);
    std::fstream fin_edges(edges_file);

    // checks that file is not in fail state (complains if file does not open properly)
    if (fin_features.fail() || fin_edges.fail()) {
        std::cerr << "Error - Failed to open both files" << std::endl;
        exit(-1);
    }

    // // for ease of iteration
    // bool mature;
    // int lifetime;
    // string created_at;
    // string updated_at;
    // bool dead_acc;
    // bool affiliate;
    //fin_features >> views >> mature >> lifetime >> created_at >> updated_at >> numeric_id >> dead_acc >> language >> affiliate;
    //std::cout << views << mature << lifetime << created_at << updated_at << numeric_id << dead_acc << language << affiliate << std::endl;
    
    string feature_line, feature;

    // determined by looking at CSV
    int feat_id_col = 5;
    int feat_view_col = 0;
    int feat_lang_col = 7;

    // O(n) time
    bool is_on_feature_headers = true;
    while (getline(fin_features, feature_line)) {
        // prevents headers from getting read in
        if (is_on_feature_headers) {
            is_on_feature_headers = false;
            continue;
        }

        std::stringstream s(feature_line);

        vector<string> features;

        while(getline(s, feature, ',')) {
            features.push_back(feature);
        }

        // to be placed in each node
        int numeric_id = std::stoi(features[feat_id_col]);
        int views = std::stoi(features[feat_view_col]);
        string language = features[feat_lang_col];

        //std::cout << "Node: " << numeric_id << " " << views << " " << language << std::endl;

        data_map[numeric_id] = Node(numeric_id, views, language);


    }

    string edge_line, id;
    // secondary maps
    //unordered_map< int, Edge > tmp_map2;
    //unordered_map< int, Edge > tmp_map1;
    // O(m) time
    bool is_on_edge_headers = true;
    while (getline(fin_edges, edge_line)) {
        // prevents headers from getting read in
        if (is_on_edge_headers) {
            is_on_edge_headers = false;
            continue;
        }

        std::stringstream s(edge_line);

        // iterates thru ONE row (id1, id2)
        vector<int> node_ids;
        // O(1) time bc its literally 2 elements
        // why is this showing an error??
        while(getline(s, id, ',')) {
            node_ids.push_back(std::stoi(id));
        }

        // for (int &i : node_ids) {
        //     std::cout << i << std::endl;
        // }
        // std::cout << std::endl;

        // TODO:  figure out a way to update the inner maps as opposed to replacing them.

        Node tmp_node_1 = data_map[node_ids[0]];
        Node tmp_node_2 = data_map[node_ids[1]];
        double weight = ((double) tmp_node_1.get_views() + (double) tmp_node_2.get_views()) / 2.0;

        Edge temp_edge1 = Edge(tmp_node_1, tmp_node_2, weight);
        Edge temp_edge2 = Edge(tmp_node_2, tmp_node_1, weight);

        // tmp map is holding previous src's dest vals, and then getting added onto for current src vals
        // tmp_map1[node_ids[1]] = temp_edge1;
        // adj_list[node_ids[0]] = tmp_map1;

        //unordered_map< int, unordered_map< int, Edge> > adj_list;
       if (adj_list[node_ids[0]].size() == 0) {

           // add direction from node_ids[0] -> node_ids[1]
           unordered_map< int, Edge > tmp_map1;
           tmp_map1.insert({node_ids[1], temp_edge1});
           adj_list[node_ids[0]] = tmp_map1;

           // add direction from node_ids[1] -> node_ids[0]
           unordered_map< int, Edge > tmp_map2;
           tmp_map2.insert({node_ids[0], temp_edge2});
           adj_list[node_ids[1]] = tmp_map2;

       } else {
           adj_list[node_ids[0]].insert({node_ids[1], temp_edge1});
           adj_list[node_ids[1]].insert({node_ids[0], temp_edge2});
       }

        /*
        if adj_list[node_ids[0]] does not have a map:
            make a tmp_map, add the first (int, Edge) pair to map
        if adj_list[node_ids[0]] has a map already:
            add another (int, Edge) pair to the map
        */

        //Edge temp_edge2 = Edge(tmp_node_2, tmp_node_1, weight);

        // tmp_map2[node_ids[0]] = temp_edge2;
        // adj_list[node_ids[1]] = tmp_map2;

        // num_id_1 follows num_id_2 on twitch
        
    }

    std::cout << "exit graph ctor" << std::endl;

}

void Graph::print_adj_list() {

    unordered_map< int, unordered_map< int, Edge> >::iterator it;

    for (it = adj_list.begin(); it != adj_list.end(); ++it) {
        unordered_map< int, Edge> map = it->second;
        std::cout << "src: " << it->first << std::endl;
        for (auto it2 = map.begin(); it2 != map.end(); ++it2) {
            std::cout << " dest: " << it2->first << std::endl;
        }
    }
}

bool Graph::hasNode(int nodeID) {
    return data_map.find(nodeID) != data_map.end(); 
}

unordered_map<int, Node> Graph::getData_map() {
    return data_map;
}

unordered_map< int, unordered_map< int, Graph::Edge> > Graph::getAdj_list() {
    return adj_list;
}

// make a print edges fn

