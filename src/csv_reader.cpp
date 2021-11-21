#include "csv_reader.h"

// void CSVReader::read_csv(std::string filename) {

// }

namespace CSVReader
{
    void read_csv_to_graph(std::string filename) {
        std::fstream fin(filename);

        // checks that file is not in fail state (complains if file does not open properly)
        if (fin.fail()) {
            std::cerr << "Error - Failed to open " << filename << std::endl;
            exit(-1);
        }

        // at this point, we can either add data to a node vector, or straight up add it to a graph.
        // i'll think about which makes more sense, and whether we need a node vector in the first place.

    }
} // namespace CSVReader

