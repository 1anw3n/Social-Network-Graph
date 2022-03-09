#include <iostream>
#include "graphGenerator.h"
#include "graphOperator.h"
using namespace std;

int main() {
    Graph g;
    
    ifstream eifs("PA2_input/edges.txt");
    ifstream hifs("PA2_input/hobbies.txt");
    //ifstream eifs("test/edges.txt");  //for tests
    //ifstream hifs("test/hobbies.txt"); // for tests
    
    GraphGenerator ggen(eifs, g);
    auto al = g.adjList;
    auto cp = g.cp;
    /*for (size_t i = 0; i < al.size(); i++) {
        cout << "adjList[" << i << "]: ";
        for (auto edge : al.at(i)) {
            cout << "<" << edge.first << "," << edge.second << "> " << endl;
        }
    }

    cout << "------------" << endl;*/
    int count, ttl(0);
    for (size_t i = 0; i < cp.size(); i++) {
        count = 0;
        cout << "cp[" << i << "]:" << endl;
        for (auto map : cp.at(i).c) {
            cout << map.first << ":<";
            for (auto edge : map.second) {
                cout << edge.first << ":" << edge.second << ",";
            }
            cout << ">" << endl;
            count++;
        }
        cout << "--------------count:" << count << endl;
        ttl += count;
    }
    cout << "--------------ttl:" << ttl << endl;
    
    /*cout << "The average degree:" << endl;
    cout << "stub" << endl;
    cout << "The vertex with the highest degree" << endl;
    cout << "stub" << endl;
    cout << "The number of connected components:" << endl;
    cout << "stub" << endl;
    cout << "The diameter, radius, and center(s) of each components" << endl;
    //probable for loop
    cout << "The ratio between the number of open and closed triangles:" << endl;
    cout << "stub" << endl;
    cout << "The closest node:" << endl;
    cout << "stub" << endl;
    cout << "A cLosEsT wIth tHe hIgHeSt iNtErEst:" << endl; //fix
    cout << "stub" << endl;
    cout << "The pair of nodes x and y" << endl;
    cout << "stub" << endl;*/

    eifs.close();
    hifs.close();
    cout << "end" << endl;
	return 0;
}