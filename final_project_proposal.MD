#Final Project Proposal

#### **Leading Question**:
 Our leading question is twofold. We want to **determine the correlation between a Twitch user's account language and the number of views they get**. From there, we want to determine **how many connections it takes to connect a twitch user who speaks a specific language to a twitch user who does not speak that language**. Essentially, we want to determine if a Twitch user’s account being listed under a certain language is correlated with a higher view count, and we want to see *how many connections* it takes for a twitch user to be connected with a foriegn language speaker. Our data could be the basis of a campaign to provide real-time translation to Twitch accounts that speak foreign languages in order to provide more interconnectivity across cultural/language barriers. This analytics tool will be used to visualize platform language disparities on Twitch. If we find that a specific language corresponds to a higher view count, this data can be used to lobby for stronger real-time translations for languages that have lesser viewer counts. This conclusion of this project has the potential to increase viewership for minorities facing a language barrier, spur career growth, and promote ideals of equality on Twitch.
#### **Dataset Acquisition**:
 We have decided to use the Twitch Gamers Social Network (twitch-gamers) dataset located within the Stanford Large Network Dataset Collection (http://snap.stanford.edu/data/). We will download this database locally on our laptops and view a truncated version of the dataset on Excel. This will suffice because at no time will we have to visually see the full, raw dataset. This data has two spreadsheets, one containing nodes with the largest edge counts between them (‘large_twitch_edges’) , and another one with the characteristics of each Twitch user like language, view count, account age, etc (‘large_twitch_features’). We will read in our CSV using our own file reader that we build from the C++ STL. We will build a graph of the nodes (users) themselves using an adjacency list. We will need to check for incident edges when figuring out how many followers each account has. We can read in the column of unique node IDs, their language, viewer count, account age, and every other column described in either spreadsheet, and store it in a vector that associates with a node (user) through a hashmap. We will first use the unique node IDs in the large_twitch_edges and cross reference with any language spoken by them in the large_twitch_features dataset. Should we see a correlation between those two things, we will then see if the higher-connection-count nodes that speak a certain language also happen to have a higher viewer count. 
We will have checks in place to skip over any extraneous values (null, negative values, etc) when constructing our vectors, hashmaps, and graphs. 
#### **Graph Algorithms**:
 We will start by using the BFS traversal to analyze our graphed dataset. We will specifically implement a level-order traversal where we visit neighboring nodes on the same level first, and then traverse through the next level of nodes by level. The input we expect to take in is CSV of features, and node connections. From there, we will create a hashmap from node id to feature vector. This associates each node (user) with a set of features (languages, etc). From there, we will use an adjacency list to build a graph of our users. Our CSV file will determine which users are connected. The output will range, based on the language input, of how many views a user is expected to get (for example, a German user may get anywhere from 50-100 views, while an English user may get around 20-6,000 views). In order to implement the path finding algorithm, in this case Dijkstra’s Algorithm, we will check the smallest number of edges needed to reach the social circle of another Twitch user who speaks a different language. This social circle will be implemented using the largest circle we can make, and this is through the Eulerian path. This large circle will be made using languages. After finding social circles for every language, we will calculate the average view count for each circle and see if a language corresponds to a higher view count. 

#### **Timeline**:
###### The timeline for the project includes splitting the project into multiple weeks worth of work with respect to deadlines.

**First 3 Weeks**: 
Mid-Point Check In (Nov 29th - Dec 1st): 
    *(Due: Nov 15th)* Get data from the CSV and build the main graph, hashmap of {nodes to feature vector} 
    *(Due: Nov 22nd)* Build the BFS traversal algorithm and collect the average number of views per streamer and store data in their respective language group 
**Last 2 Weeks**:

    *(Dec 10th)* Finish Final Presentation:
        *(Due: Dec 6th)* Complete the implementation of the Dijkstra’s Algorithm pathfinder and see the average distance between social circles who speak different languages.
        *(Due: Dec 6th)* After finding connections, calculate the average number of views per social circle. Social circle is calculated using the Eulerian path for the largest cycle. 
        *(Dec 8)* Finish Powerpoint

    *(Dec 10)* Finish Practicing
    *(Due: Dec 13th)* Finish Written Report:
        Work on written report using a shared doc and explain out process while doing it. **Have a rough draft by Dec 8th**. 
        **Final draft revisions due Dec 11th**
