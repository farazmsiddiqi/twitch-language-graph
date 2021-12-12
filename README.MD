<div id="top"></div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="http://snap.stanford.edu/data/twitch_gamers.html">
    <img src="twitch.png" alt="Logo" width="300" height="300">
  </a>

<h3 align="center">Twitch Gamers and their Social Networks</h3>

  <p align="center">
    Our leading question is twofold. We want to determine the correlation between a Twitch user's account language and the number of views they get. From there, we  want to determine how many connections it takes to connect a twitch user who speaks a specific language to a twitch user who does not speak that language. 
    <br />
    <a href="https://github-dev.cs.illinois.edu/cs225-fa21/snmehta2-athev2-dhanker2-farazms2/tree/master/md_files_and_misc_documents"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://www.youtube.com/">View Demo (UPLOAD VIDEO)</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#linkage-and-location">Location of code</a>
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

  Under the [cs225](#heading-1 "Goto heading-1") folder, under [make](#heading-1 "Goto heading-1") we have our Make file for the project saved as [cs225.mk](#heading-1 "Goto heading-1").

  Under the [src](#heading-1 "Goto heading-1") folder, we have six files primarily related to our algortithm implementation, our graph implemtations, and the node class. 

    * The [algorithm.cpp](#heading-1 "Goto heading-1") and [algorithm.h](#heading-1 "Goto heading-1") contain the implementation and declaration of the BFS and Dijkstras algorithms. 

    * The [graph.cpp](#heading-1 "Goto heading-1") and [graph.h](#heading-1 "Goto heading-1") files contain the creation and implemenation of our graph class, as well as ways to print and get our adjacency list. These files contain edges, and the declarations and usage of our adjacency list.

    * The [node.cpp](#heading-1 "Goto heading-1") and [node.h](#heading-1 "Goto heading-1") files contain our node constructors and numerous get methods for each of our nodes in the dataset. This includes get methods for views, languages, and numeric ids. We have also created the set methods for those. 

  Under the [tests](#heading-1 "Goto heading-1") folder, we have custom made tests for our graph creation as well as tests for Djikstras and BFS. 

  Our [main.cpp](#heading-1 "Goto heading-1") file is located outside all folders mentioend above and is placed independently. 


  
  
* #### Data location
  Under the [data](#heading-1 "Goto heading-1") folder, we have the [README.txt](#heading-1 "Goto heading-1") that contains a summary of our data. 
    * For the location of the actual data, click [here](http://snap.stanford.edu/data/twitch_gamers.html) for the website we used for the database. After you are on the page, navgiate down to the Files section and download the [twitch_gamers.zip][large_twitch_edges.csv](#heading-1 "Goto heading-1") file. Then, go to the [data](#heading-1 "Goto heading-1") folder and create a new folder called [real_data][large_twitch_edges.csv](#heading-1 "Goto heading-1").  Now open up the downloaded zip file and move the [large_twitch_edges.csv](#heading-1 "Goto heading-1") and the [large_twitch_features.csv](#heading-1 "Goto heading-1") into the [real_data](#heading-1 "Goto heading-1") folder and save them as seperate CSV files. You can now run our code as intented after saving to the appropriate folder. 




* #### Results location 


<p align="right">(<a href="#top">back to top</a>)</p>



<!-- How to run our code -->
## How to run our code
* #### Commands to run the assignments
* #### Selecting input/output locations

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Testing suite -->
## Testing suite
* #### Description
* #### How to build and run the test suite
* #### How to reproduce tests 

<p align="right">(<a href="#top">back to top</a>)</p>


##### Template taken from: https://github.com/othneildrew/Best-README-Template