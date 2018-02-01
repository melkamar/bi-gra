#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <list>
#include <stdint.h>

using namespace std;
#endif /* __PROGTEST__ */

#include <sstream>

#define FRESH 0
#define CLOSED 1

class CVertex {
public:

    void addEdge(CVertex * edgeTo) {
        neighbors.push_back(edgeTo);
    }

    int getDegree() {
        return neighbors.size();
    }

    void deleteEdge(int neighborId) {
        CVertex * neighbor = NULL;
        for (int i = neighbors.size() - 1; i >= 0; i--) {
            if (neighbors[i]->getId() == neighborId) {
                neighbor = neighbors[i];
                neighbors.erase(neighbors.begin() + i);
                break;
            }
        }
        neighbor->rmEdg(this->id);
    }

    CVertex(int pId) : id(pId) {
        //        neighbors = new vector<CVertex*>();
    }

    int getId() {
        return id;
    }

    void printNeighbors() {
        cout << "Neighbors of [" << id << "]: " << endl;
        for (unsigned int i = 0; i < neighbors.size(); i++) {
            cout << "  - " << neighbors[i]->getId() << endl;
        }
    }

    void rmEdg(int neighborId) {
        //        cout << "["<<id<<"] rmEdg ("<<neighborId<<")"<<endl;
        for (int i = (int) neighbors.size() - 1; i >= 0; i--) {
            if (neighbors[i]->id == neighborId) {
                neighbors.erase(neighbors.begin() + i);
            }
        }
    }

    int id;
    vector<CVertex*> neighbors;
};

int * verticesColor;

void DFS(CVertex * vertex) {
    //    cout << "  DFS ("<<vertex->id<<") "<< (verticesColor[vertex->id]==CLOSED?"CLOSED":"OPEN")<<endl;

    if (verticesColor[vertex->id] == CLOSED) return;

    verticesColor[vertex->id] = CLOSED;
    for (int i = 0; i < vertex->getDegree(); i++) {
        DFS(vertex->neighbors[i]);
    }
}

bool isConnectedGraph(CVertex** vertices, int vertexNr) {
    verticesColor = new int[vertexNr];
    for (int i = 0; i < vertexNr; i++) {
        verticesColor[i] = FRESH;
    }

    DFS(vertices[0]);

    for (int i = 0; i < vertexNr; i++) {
        if (verticesColor[i] == FRESH) {
            delete[]verticesColor;
            return false;
        }
    }

    delete[]verticesColor;
    return true;
}

bool trasa(const char * inFile, const char * outFile) {
    ifstream input(inFile, ifstream::in);
    ofstream output(outFile, ofstream::out);

    int vertexNr;
    int edgeNr;

    input >> vertexNr >> edgeNr;
    if (edgeNr == 0) {
        return false;
    }

    cout << "Vertices: " << vertexNr << endl << "Edges: " << edgeNr << endl;

    CVertex ** vertices = new CVertex*[vertexNr];
    for (int i = 0; i < vertexNr; i++) {
        vertices[i] = new CVertex(i);
    }

    for (int i = 0; i < edgeNr; i++) {
        int vertexA;
        int vertexB;

        input >> vertexA >> vertexB;

        vertices[vertexA]->addEdge(vertices[vertexB]);
        vertices[vertexB]->addEdge(vertices[vertexA]);
    }

    for (int i = 0; i < vertexNr; i++) {
        vertices[i]->printNeighbors();
        cout << endl;
    }

    /* Check if graph is connected. If not, return FALSE */
    if (!isConnectedGraph(vertices, vertexNr)) {
        cout << "Graph not connected." << endl;
        return false;
    } else {
        cout << "Graph is connected."<<endl;
    }


    /* Find vertices with odd degrees and save them */
    vector<int> oddVerticesIds;
    for (int i = 0; i < vertexNr; i++) {
        if (vertices[i]->getDegree() % 2 != 0) {
            oddVerticesIds.push_back(i);
        }
    }

    if (oddVerticesIds.size() > 2) {
        cout << ">2 odd-degree vertices. Cannot be solved." << endl;
        return false;
    } else {
        cout << "Vertices OK. Can be solved."<<endl;
    }

    /* If there are odd-degree vertices, start the path with one of them */
    CVertex * startingVertex;
    if (oddVerticesIds.size() > 0) {
        startingVertex = vertices[oddVerticesIds[0]];
    } else {
        startingVertex = vertices[0];
    }

    /* Initializing algorithm*/
    vector<CVertex*> stack;
    vector<int> path;

    stack.push_back(startingVertex);

    /* Algorithm */
    while (!stack.empty()) {
        CVertex * tmp = stack.back();

        if (tmp->getDegree() > 0) {
            //            CVertex * neighbor = tmp->neighbors.back();
            CVertex * neighbor = tmp->neighbors.front();
            stack.push_back(neighbor);
            tmp->deleteEdge(neighbor->id);

            cout << "Deleted edge " << tmp->id << " - " << neighbor->id << endl;
            tmp->printNeighbors();
            neighbor->printNeighbors();
        } else {
            path.push_back(tmp->getId());
            stack.pop_back();
        }
    }

    cout << "PATH: " << endl;
    output << path.size()<<endl;
    for (unsigned int i = 0; i < path.size(); i++) {
        cout << "  " << path[i] << endl;
        output << path[i] << endl;
    }

    /* Deleting vertex array */
    for (int i = 0; i < vertexNr; i++) {
        delete vertices[i];
    }
    delete [] vertices;

    input.close();
    output.close();

    return true;
}


#ifndef __PROGTEST__

int main(int argc, char * argv []) {

    for (int i = 1; i <= 5; i++) {
        ostringstream inputstr; 
        ostringstream outputstr; 
        inputstr << "/mnt/DATA/Dropbox/cvut/predmety/GRA/progtest/ukol-1/dist/Debug/GNU-Linux-x86/input" <<i<< ".txt";
        outputstr << "/mnt/DATA/Dropbox/cvut/predmety/GRA/progtest/ukol-1/dist/Debug/GNU-Linux-x86/output" <<i<<".txt";
        cout << trasa(inputstr.str().c_str(), outputstr.str().c_str()) << endl;
    }
    
//    cout << trasa("/mnt/DATA/Dropbox/cvut/predmety/GRA/progtest/ukol-1/dist/Debug/GNU-Linux-x86/input3.txt",
//            "/mnt/DATA/Dropbox/cvut/predmety/GRA/progtest/ukol-1/dist/Debug/GNU-Linux-x86/output1.txt") << endl;
    return 0;
}
#endif /* __PROGTEST__ */