#include "graph.h"

Graph::Graph(string features_file, string edges_file) {

    std::fstream fin_features(features_file);
    std::fstream fin_edges(edges_file);

    // checks that file is not in fail state (complains if file does not open properly)
    if (fin_features.fail() || fin_edges.fail()) {
        std::cerr << "failed to open " << features_file << " or " << edges_file << std::endl;
        exit(-1);
    }

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

        data_map[numeric_id] = Node(numeric_id, views, language);


    }

    string edge_line, id;
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
        while(getline(s, id, ',')) {
            node_ids.push_back(std::stoi(id));
        }

        Node tmp_node_1 = data_map[node_ids[0]];
        Node tmp_node_2 = data_map[node_ids[1]];
        double weight = ((double) tmp_node_1.get_views() + (double) tmp_node_2.get_views()) / 2.0;

        Edge temp_edge1 = Edge(tmp_node_1, tmp_node_2, weight);
        Edge temp_edge2 = Edge(tmp_node_2, tmp_node_1, weight);

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
    }

}


Graph::Graph(string features_file, string edges_file, string lang) {

    std::fstream fin_features(features_file);
    std::fstream fin_edges(edges_file);

    // checks that file is not in fail state (complains if file does not open properly)
    if (fin_features.fail() || fin_edges.fail()) {
        std::cerr << "failed to open " << features_file << " or " << edges_file << std::endl;
        exit(-1);
    }

    string feature_line, feature;

    // determined by looking at CSV
    int feat_id_col = 5;
    int feat_view_col = 0;
    int feat_lang_col = 7;
    int feat_lifetime_col = 2;

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
            features.push_back(feature); // views, mature, ...
        }

        // to be placed in each node
        int numeric_id = std::stoi(features[feat_id_col]);
        int views = std::stoi(features[feat_view_col]);
        string language = features[feat_lang_col];
        int lifetime = std::stoi(features[feat_lifetime_col]);

        if (language.compare(lang) == 0) {
            data_map[numeric_id] = Node(numeric_id, views, language);
        }
    }

    string edge_line, id;
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
        while(getline(s, id, ',')) {
            node_ids.push_back(std::stoi(id));
        }

        /*
            The try-catch prevents tmp_nodes 
            from being created when the node_ids 
            do not exist in the data_map.
        */
        try {
            Node tmp_node_1 = data_map.at(node_ids[0]);
            Node tmp_node_2 = data_map.at(node_ids[1]);
            double weight = ((double) tmp_node_1.get_views() + (double) tmp_node_2.get_views()) / 2.0;

            Edge temp_edge1 = Edge(tmp_node_1, tmp_node_2, weight);
            Edge temp_edge2 = Edge(tmp_node_2, tmp_node_1, weight);

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

        } catch (...) { // catch all errors
            continue;
        }
    }

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

bool Graph::has_node(int nodeID) {
    return data_map.find(nodeID) != data_map.end(); 
}

unordered_map<int, Node> Graph::get_data_map() {
    return data_map;
}

 unordered_map< int, unordered_map< int, Graph::Edge> > Graph::get_adj_list() {
    return adj_list;
}

// make a print edges fn 