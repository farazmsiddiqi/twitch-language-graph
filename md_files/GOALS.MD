# Goals

#### **Leading Question**:
We want to determine **which major European language has the largest community on Twitch**. We define community as a connected component where each user has a direct OR non-direct follower relationship with every other user in the community. This data will show the biggest European community on Twitch, and will highlight how specific accounts have the potential to get more recognition solely based on their native language. This is because specific languages have a larger community than other languages—-highlighting a relationship between the popularity of a language and the size of its Twitch community. Our data could be the justification for a campaign to provide real-time translation to Twitch accounts that speak less Twitch-popular languages in order to provide more inter-connectivity across cultural/language barriers, and provide a larger audience to those who speak less Twitch-popular languages. The conclusion of this project has the potential to highlight the connectivity of Twitch streamers who speak different languages and promote ideals of equality on Twitch.

#### **Dataset Acquisition**:
 We have decided to use the Twitch Gamers Social Network (twitch-gamers) dataset located within the Stanford Large Network Dataset Collection (http://snap.stanford.edu/data/). We will download this database locally on our laptops. This data has two spreadsheets. The first spreadsheet, ‘large_twitch_edges’, denotes a mutual follower relationship between two nodes. The second spreadsheet, ‘large_twitch_features’, denotes the attributes of a specific node such as language, view count, account age, etc. We will read in our CSVs by building our own CSV reader in the graph constructor. We will build a graph of the nodes (users) themselves using an adjacency list. We will need to check for incident edges when creating our BFS algorithm. We can read in the column of unique node IDs, their language, and viewer count, and store it in a vector that associates a node_id to a node object (data_map). We will have checks in place to skip over any extraneous values (null, negative  values, etc) when constructing our vectors, hashmaps, and graphs.

#### **Graph Algorithms**:
 The first algoritm we will use is BFS, a level order traversal to analyze our graphed dataset. This works by visiting neighboring nodes on the same level first, and then traversing through the next level of nodes by adding adjacent nodes to a queue. Since this is a level-order BFS traversal, the target runtime is optimal at O(n), where n is the number of vertices. We will take our data from two separate CSVs. The first CSV describes intra-node attributes, while the second CSV describes inter-node relationships. We will use an adjacency list to build a graph of our users from these CSVs. In order to implement the path finding algorithm, we will use Dijkstra’s Algorithm. This will involve us checking, at each node, the minimum weighted path required to reach our destination. This path finding algorithm takes O(mlogn) time where m is the number of edges, and n is the number of vertices. Our final algorithm will be the Kosaraju-Sharir Algorithm (a Strongly Connected Component Algorithm). This algorithm will find the largest strongly connected component in our dataset, and return the size of the largest connected component for a specific language. From there, we will calculate the number of nodes in each strongly connected component. The runtime of the Kosaraju algorithm is O(m + n).

#### **Timeline**:
###### The timeline for the project includes splitting the project into multiple weeks worth of work with respect to deadlines.

**First 3 Weeks**: 
Mid-Point Check In (Nov 29th - Dec 1st): 
    *(Due: Nov 15th)* Get data from the CSV and build the main graph, hashmap of {nodes to feature vector} 
    *(Due: Nov 22nd)* Build the BFS traversal algorithm and collect the average number of views per streamer and store data in their respective language group 
**Last 2 Weeks**:

    *(Dec 10th)* Finish Final Presentation:
        *(Due: Dec 6th)* Complete the implementation of the Dijkstra’s Algorithm pathfinder and see the average distance between social circles who speak different languages.
        *(Due: Dec 6th)* Complete Kosaraju's algorithm to find the largest CC for each european language.
        *(Dec 8)* Finish Powerpoint

    *(Dec 10)* Finish Practicing
    *(Due: Dec 13th)* Finish Written Report:
        Work on written report using a shared doc and explain out process while doing it. **Have a rough draft by Dec 8th**. 
        **Final draft revisions due Dec 11th**
