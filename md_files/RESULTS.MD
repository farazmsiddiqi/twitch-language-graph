# Results

#### **Structure and Team Process**:
 We tackled the project by first getting data from the CSVs to build the main graph. From there, we set up a node class and a graph class. We then read in our data into an adjacency list graph representation from two separate CSVs. We decided to use the adjacency list graph representation because it takes O(deg(v)) time to find incident edges——which is useful for finding followers in our Twitch dataset. Our implementation included building the BFS traversal algorithm to traverse through our Twitch dataset in BFS order. This was done in the first two weeks. Later, we implemented Dijkstra’s Algorithm to determine the number of links it takes to connect two users who are part of different european language communities. Finally, we implemented Kosaraju's Algorithm, to find the largest strongly connected component in each language community in our dataset, and return the size of the largest major European language community. Overall, the algorithms were implemented in a timely fashion and they fulfill all requirements of the final project.

#### **Graph Implementation**:
 To prove that the graph worked, we first needed to ensure that the makefile works. To do this, we executed some 'ping-pong' tests, which essentially allowed us to prove that the makefile we created was recognizing each new file that we made. Then, we tested our adjacency list implementation. We did this by creating a smaller dataset, and loading it into our graph representation. We then pre-determined what our adjacency list would look like by hand, and ran our graph implementation on the test data. After that, we ensured that the results matched up.
 
<p align="center">
  <img src="/images/two.png" height="50%" width="50%" />
  <img src="/images/three.png" height="50%" width="50%"/>
</p>

#### **Breadth First Search Algorithm (BFS)**:
 To prove that the BFS algorithm worked, we implemented several test cases to access its accuracy. We built our own test dataset, and determined a correct traversal order by hand. We then ran our BFS algorithm and ensured that it matched the solution we came up with. In context of our project, the BFS algorithm can traverse through our social networks of language communities, and return a BFS order of those communities. From these tests cases we found that the BFS worked as intended as our algorithm is intended to visit neighboring nodes on the same level first, and then traverse through the next level of nodes by level.



<p align="center">
  <img src="/images/one.png" height="50%" width="50%" /> 
  <img src="/images/four.png" height="50%" width="50%" />
</p>

#### **Dijkstra's Algorithm**:
 In order to implement the path finding algorithm, we used Dijkstra’s Algorithm. This involved us checking, at each node, the minimum weighted path required to reach our destination. This path finding algorithm takes O(mlogn) time where m is the number of edges, and n is the number of vertices. To ensure that this worked, and the algorithm acted as intended, we created multiple test cases to assess its accuracy. We created a smaller dataset to test Dijkstra's. We hand calculated the path which the algorithm should take, and ensured that our algorithm matched our result.

<p align="center">
  <img src="/images/five.png" height="50%" width="50%" /> 
</p>

 #### **Kosarajus's Algorithm**:
 Finally after hours of researching which algorithm to use, we implemented the Kosaraju-Sharir Algorithm (a Strongly Connected Component Algorithm). This algorithm finds the largest strongly connected component in our whichever dataset we pass in (we generated a sub-dataset for each major european language), and returns the size of the largest connected component for a specific language. From there, we calculated the number of nodes in each strongly connected component. The runtime of the Kosaraju algorithm is O(m + n). We made test cases to test the accuracy of our algorithm and this included calling the Kosaraju-Sharir method in the Algorithm class and creating a new Graph to read in our data file. This returned the size of the biggest strongly connected component. This was run on a smaller data set so we could manually calculate the size of the biggest strongly connected component. In this case, it did return the correct size of the biggest strongly connected component. 

 <p align="center">
  <img src="/images/six.png" height="50%" width="50%" /> 
</p>
 
 #### **Final Thoughts**:

Since the beginning of this project, we sought to answer a question: Which major European language has the largest community on Twitch?

We now have an answer. Using Kosaraju's algorithm on sub-datasets of each language community on Twitch, **we found that Italian was the largest major European language community on Twitch**. This conclusion has one qualification. For the English, German, French, Swedish, and Russian communities, the language-specific social networks that we generated for those languages were too big. Our computers could not calculate the size of the largest strongly connected component for each of these languages because our computers ran out of space. **This is NOT an issue with runtime.** The size of the dataset was simply too large. Because of this, we are assuming that the size of each of these communities is larger than our calculatable sizes, and hence these communities all have a larger presence than the Italian community.

 All in all, this project has taught our group many valuable lessons. First, time managment is key in doing any project, especially on projects that require weeks of work and need proper and consitent communication between teammates. Second, is adaptability. We had to deal with our group's tight finals schedules and meet diligently. Overall, this project tested our knowledge of data structures and algorithms, but also brought upon an experience that will stick with us for a lifetime. 

 <p align="center">
  <img src="/images/final.jpeg" height="75%" width="75%" /> 
</p>





