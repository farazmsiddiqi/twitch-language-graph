# Results

#### **Structure and Team Process**:
 We tackled the project by first getting data from the CSV to build the main graph and the hashmap of {nodes to feature vector}. Our implementation included building the BFS traversal algorithm to collect the average number of views per streamer and store data in their respective language group. This was done in the first two weeks and later, we implemented Dijkstra’s Algorithm pathfinder to see the average distance between social circles who speak different languages. Upon successful completion of the previous algorithms, our group hit a road block. Our inital thought process was to calculate the average number of views per social circle using the Eulerian path for the largest cycle. The problem is, with our previous implementation of BFS and the connectivity of our data set, using a Eulerian path was not useful as there are not that many connected components in our graph and did not fit our leading question. Ultimately we decided to update our project proposal to utilize a more applicable algorithm, the Kosaraju's Algorithm, to find the largest strongly connected component in our dataset, and return the size of the largest non-English, major European language, community. Overall, the algorithms were implemented in a timely fashion and fulfills all requirements of the final project. 

#### **Graph Implementation**:
 To prove that the graph worked, we first needed to ensure that the makefile works. By ensuring that the makefile works, we can prove that the code compiles, making it possible for the other algorithms to work. We first create the graph pulled from the CSV file using an adjacency list and create vectors to store the source and destination keys. We then compare the newly populated vectors that use data from the graph and adjacency list with hard coded vectors to ensure that populating the graph and adjacency list worked. This is the first step in ensuring our program works as intended. 
 
<p align="center">
  <img src="/images/two.png" height="50%" width="50%" />
  <img src="/images/three.png" height="50%" width="50%"/>
</p>

#### **Breadth First Search Algorithm (BFS)**:
 To prove that the BFS algorithm worked, we implemented several test cases to access its accuracy. From these tests cases we found that the BFS worked as intended as our algorithm is intended to visit neighboring nodes on the same level first, and then traverse through the next level of nodes by level. Second, a hashmap was instantiated to associate each node (user) with a set of features (languages, etc). From there, an adjacency list was used to build a graph of our users. To test, we first called the bfs() method in the Algorithm class. Then, we called the get_data_map() to prove that this algorithm worked. We compared each index in the resulting vector to the respective node. The order which it stored the nodes proved that our BFS algorithm worked.

<p align="center">
  <img src="/images/one.png" height="50%" width="50%" /> 
  <img src="/images/four.png" height="50%" width="50%" />
</p>

#### **Dijkstra's Algorithm**:
 In order to implement the path finding algorithm, we used Dijkstra’s Algorithm. This involved us checking, at each node, the minimum weighted path required to reach our destination. This path finding algorithm takes O(mlogn) time where m is the number of edges, and n is the number of vertices. To ensure that this worked, and the algorithm acted as intended, we created multiple test cases to assess its accuracy. As a baseline test, we made sure that the graph still worked with Dijkstra's Algorithm as without it working in the makefile, nothing else would work. We proceeded to test our algorithms on the two datasets, both of which are different in sizes. First, we made a graph object that can read in our data set. Second, we ran our algorithm by calling the Dijkstra’s Algorithm method in the Algorithm class on two different data maps from the graph. We tested the accuracy of the algorithm by ensuring that each index in the resulting minimum weighted path matched the data set as a inital tester. We repeated this test for the larger data set which secured that our algorithm was working as intended. 

<p align="center">
  <img src="/images/five.png" height="50%" width="50%" /> 
</p>

 #### **Kosarajus's Algorithm**:
 Finally after hours of researching, we implemented the Kosaraju-Sharir Algorithm (a Strongly Connected Component Algorithm). This algorithm found the largest strongly connected component in our dataset, and returned the size of the largest connected component for a specific language. From there, we calculated the number of nodes in each strongly connected component. The runtime of the Kosaraju algorithm is O(m + n). We made test cases to test the accuracy of our algorithm and this included calling the Kosaraju-Sharir method in the Algorithm class and creating a new Graph to read in our data file. This returned the size of the biggest strongly connected component. This was run on a smaller data set so we could manually calculate the size of the biggest strongly connected component. In this case, it did return the correct size of the biggest strongly connected component. 

 <p align="center">
  <img src="/images/six.png" height="50%" width="50%" /> 
</p>
 
 #### **Final Thoughts**:
 All in all, this project has taught our group many valuable lessons. First, time managment is key in doing any project, especially on projects that require weeks of work and need proper and consitent communication between teammates. Second, is adaptability. It is worth noting moving forward, we should be prepared for our initial plan to not go as expected. Throughout our final project process, we hit many road bumps, with many being that our original idea could not support our given data set we the way our data set is laid out, many algorithms would not work or would be very inefficient. At the end of our project, to answer our leading question, __% percent of Twitch's largest community speaks the same language, and the size of Twitch's largest community is __. To ensure that these answers are correct, we ran all of our test cases and found out that all algorithms and methods worked as intended. Overall, this project tested our knowledge of data structures and algorithms, but also brought upon an experience that will stick with us for a lifetime. 

 <p align="center">
  <img src="/images/final.jpeg" height="75%" width="75%" /> 
</p>



