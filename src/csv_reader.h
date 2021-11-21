#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "node.h"

// class CSVReader {
//     public:
//         static void read_csv(std::string filename);
//     private:
//         /**
//          * disallows the instantiation of this class.
//          * Basically a jank version of Java static classes.
//          **/
//         CSVReader() {}
// };

/**
 * waaay better codestyle for C++ non-member fns
 * 
 * https://stackoverflow.com/questions/9321/how-do-you-create-a-static-class-in-c
 */
namespace CSVReader
{
    void read_csv_to_graph(std::string filename);

} // namespace CSVReader
