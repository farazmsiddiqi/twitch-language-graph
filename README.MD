<div id="top"></div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="http://snap.stanford.edu/data/twitch_gamers.html">
    <img src="twitch.png" alt="Logo" width="300" height="300">
  </a>

<h3 align="center">The Largest European-Originated Language Communities on Twitch</h3>

  <p align="center">
    We want to determine <b>which major European language has the largest community on Twitch</b>. We define community as a connected component where each user has a direct OR non-direct follower relationship with every other user in the community. This data will show the biggest European community on Twitch, and will highlight how specific accounts have the potential to get more recognition solely based on their native language. 
    <br />
    <a href="https://github-dev.cs.illinois.edu/cs225-fa21/snmehta2-athev2-dhanker2-farazms2/tree/master/md_files"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://www.youtube.com/watch?v=kpTG84i-u50">Link to final presentation</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#Location-of-code">Location of code</a>
      <ul>
        <li><a>Major Code</a></li>
        <li><a>Data</a></li>
        <li><a>Results</a></li>
      </ul>
    </li>
    <li>
      <a href="#how-to-run-our-code">How to run our code</a>
      <ul>
        <li><a>Commands to run the assignments</a></li>
        <li><a>Selecting input/output locations</a></li>
      </ul>
    </li>
    <li>
      <a href="#testing-suite">Testing Suite</a>
      <ul>
        <li><a>Description</a></li>
        <li><a>How to build and run the test suite</a></li>
        <li><a>How to reproduce tests</a></li>
      </ul>
    </li>
  </ol>
</details>



<!-- Location of our code -->
## Location of code
* #### Major code location
  The code is broken up into seperate subsections located within their respective folders, much like the organization of our MPs was.

  Under the `cs225` folder, under `make` we have our Make file for the project saved as `cs225.mk`.

  Under the `src` folder, we have six files primarily related to our algorithm implementations, our graph implemtations, and the node class. 

    * The `algorithm.cpp` and `algorithm.h` contain the implementation and declaration of the BFS, Dijkstras, and the Kosaraju algorithms. 

    * The `graph.cpp` and `graph.h` files contain the creation and implemenation of our graph class, as well as ways to print and get our adjacency list. These files contain edges, and the declarations and usage of our adjacency list.

    * The `node.cpp` and `node.h` files contain our node constructors and numerous get methods for each of our nodes in the dataset. This includes get methods for views, languages, and numeric ids. We have also created the set methods for those. 

  Under the `tests` folder, we have custom made tests for our graph creation as well as tests for Djikstras BFS, and our Kosaraju's a;gorithms. 

  Our `main.cpp` file is located outside all folders mentioend above and is placed independently. 


  
  
* #### Data location
  Under the `data` folder, we have the `README.txt` that contains a summary of our data. 
    * For the location of the actual data, click [here](http://snap.stanford.edu/data/twitch_gamers.html) for the website we used for the database. After you are on the page, navgiate down to the Files section and download the `twitch_gamers.zip` file. Then, go to the `data` folder and create a new folder called `real_data`. Now open up the downloaded zip file and move the `large_twitch_edges.csv` and the `large_twitch_features.csv` into the `real_data` folder and save them as seperate CSV files. You can now run our code as intended after saving to the appropriate folder. 




* #### Results location
  The results of our code are produced in the terminal after we run our program. We run the code by running `make clean`, then `make`, then `./main`. We will see here the largest connected components (or largest communities in Twitch) that speak the same European Language. 



<p align="right">(<a href="#top">back to top</a>)</p>



<!-- How to run our code -->
## How to run our code
* #### Commands to run to build and run project
  To build the project, you first need to run `git pull` in your terminal. 

  Then, run `make clean`.

  Then, we need to run `make` to build the project and the make file, then run `./main` to run the whole project.




* #### Defining input data and output locations for each method
  For each algorithm, the Nodes input is in the format `(numeric_id_1,numeric_id_2)`, taken from the edges dataset in our Data folder. The numeric id 1 and numeric id 2 are the starting and ending nodes connecting the largest edges in our dataset. The graphs are in the format  `(views,mature,life_time,created_at,updated_at,numeric_id,dead_account,language,affiliate)`, where views are the total views of that account, mature is whether the user is listed as mature or not, lifetime is the days the account has been active, created at is the data of creation, updated at is the data the account was last updated, numeric id is the id of the account, dead account is if the account is no longer active, and language is the primary language of the account. 


  
  *  BFS: The BFS algorithm takes in a graph, loaded in from BFS features and edges and/or Dijkstras edges and features CSV, and a Node. This outputs a vector of integers in the order they are traversed in from the source.
  *  Dijkstras: The Dijkstras algorithm takes in a graph, loaded in from a Dijkstras edges and features CSV, a starting node, and an ending node. This outputs a vector of integers in the reverse order they were visited in from destination to source.
  *  Kosarajus (SCC): This takes in a graph, loaded in from a SCC edges and features CSV, and outputs the size of the biggest strongly connected component in the dataset as an int. 

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Testing suite -->
## Testing suite
* #### Description
  We tested large and small data sets for each of our algorithms, as well as tested edge cases for each them. We have seperate test files for BFS, Dijkstras, our graph implemenation, and our strongly connected components (Kosaraju's) algorithms. 


* #### How to build and run the test suite
  To do this, we need to run `make` to build the suite, then run `./test` to run the whole suite.

* #### How to reproduce tests 
  In order to create and run your own test cases for this project, you will need to simply add on test cases, their names, and their weights to our existing test files. We have such files for our graphs, our Dijikstras, BFS, and Kosarajus. 

  To reproduce for BFS, you need to make your own graph from the test_data folder provided in the format 
  `Graph graph = Graph("data/test_data/test_large_features.csv", "data/test_data/test_large_edges.csv")` with the above line for the Dijkstras features and edges as well. Then, you need to create a Algorithm object such as `Algorithm algo`, as well as a Node object that such as `Node n = graph.get_data_map()[0]` that gets a certain index of the get_data_map that is created. Then, you need to make a vector of integers that you can parse using indeces in BFS. This is done like `vector<int> tester = algo.BFS(graph, n)`. 

  * To create the assertions for the test case, you can do vector.size() to make sure its the correct length, and then check if each index of your vector is at the correct number. This example is like 
  `REQUIRE(tester.size() == 17)`.
  `REQUIRE(tester[0] == 0)`.
  `REQUIRE(tester[1] == 15)`. 

  To reproduce Graph tests, you need to accurately test if the adjacency list works. This is again done by making your own graph from the test_data folder provided in the format 
  `Graph graph = Graph("data/test_data/test_large_features.csv", "data/test_data/test_large_edges.csv")`. Now, you need to make a vector of the correct source and a  vector of vectors for destination keys (in the form of tuples), such as `vector<int> correct_src_keys = {0, 1, 2, 3}`. You then create an empty vector for your own source keys, and an empty vector of vectors for the destination keys. You then create an adjacency list and load in the source and destination keys using a nested for loop. (See example in `test_graph_creation`). 

  * For the assertions, simply check if the correct source and destination keys are equal to your custom made vector and vector of vectors for the source and destination keys.

  To reproduce the Dijkstras tests, similar to how we tested BFS and the graphs, we ened to make a graph using the data in test_data. This is example is `Graph graph = Graph("data/test_data/Dijkstra_features.csv", "data/test_data/Dijkstra_edges.csv")`. Then, we make another Algorithm object just in BFS. We then create two node objects similar to `Node node1 = graph.get_data_map()`. We have two node objects in this case at different indices (like 0 and 2). We then create a vector and set it equal to with our Algorithm object (Dijkstras this time), and the made graph and two nodes: `vector<int> tester = algo.Dijkstra(graph, node1, node2)`. 

  * For the asstertions, check if the vector at certain indices (like 0, 2, or 3) are your desired number: `REQUIRE(tester[0] == 2)`.

  For the strongly connected components (or Kosaraju's Algoithm), the testing is very similar to our two other algorithms. We create a graph `Graph graph = Graph("data/test_data/SCC_features.csv", "data/test_data/SCC_edges.csv")` with the SCC edges and feautes instead of Dijikstras and BFS. We then create an algorithm object, and this time we make an integer instead of a vector. This integer (int) is set to the algorithm object's SCC graph: `int tester = algo.SCC(graph)`.
  * For the assertions, we set the "tester" equal to to a desired number.  




  

  



<p align="right">(<a href="#top">back to top</a>)</p>
