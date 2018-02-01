#define SHELDON 1
#define AMY 2
#define JARA 3
#define LENGTH_MAX 2147483647
#define NULL_NODE 0




bool verbose = false;

/**
 * Find starting node of a person of ID. Node index is [ 1..NodesCount ]
 * @param g
 * @param ID
 * @return 
 */
int findStartNode(const CGraph& g, int ID) {
    for (int i = 0; i < g.getNodeCounter(); i++) {
        t_node tmp = g.getNode(i + 1);
        if (tmp.characterid == ID)
            return i + 1;
    }
    return -1;
}

int * d;
int * p;

vector<t_edge> * edgesArray; // Pole vektoru, kazda polozka pole obsahuje id hran, prislusici danemu vrcholu

/**
 * 
 * @param openNodes
 * @return Index of element in openNodes [0..openNodes.size-1]
 */
int findMinDU(vector<int>openNodes) {
    int min = -1;
    int minIndex = -1;

    for (unsigned int i = 0; i < openNodes.size(); i++) {
        if (d[openNodes[i]] < min || min == -1) {
            min = d[openNodes[i]];
            minIndex = i;
        }
    }

    if (min == LENGTH_MAX) {
        return -1;
    }

    return minIndex;
}

/**
 * Finds edge connectng edgeFrom -> edgeTo. 
 * @param edgeFrom
 * @param edgeTo
 * @param g
 * @return Index of edge [1..edgeCount]
 */
int getEdgeNumber(int edgeFrom, int edgeTo, const CGraph& g) {
    for (int i = 1; i <= g.getEdgeCounter(); i++) {
        t_edge e = g.getEdge(i);
        if (e.sourceIndex == edgeFrom && e.destinationIndex == edgeTo) {
            return i;
        }
    }

    return -1;
}

vector<t_edge> getEdges(int edgeFrom, const CGraph& g) {
    return edgesArray[edgeFrom];
}

t_edge getEdge(int edgeFrom, int edgeTo, const CGraph& g) {

    for (unsigned int i = 0; i < edgesArray[edgeFrom].size(); i++) {
        if (edgesArray[edgeFrom][i].destinationIndex == edgeTo) {
            return edgesArray[edgeFrom][i];
        }
    }

    t_edge n;
    n.destinationIndex = -1;
    n.sourceIndex = -1;
    n.value = -1;
    return n;
}

void relax(int u, int v, const CGraph& g) {
    int newVal = d[u] + getEdge(u, v, g).value;

    if (d[v] > newVal) {
        d[v] = newVal;
        p[v] = u;
    }
}

void printD(const CGraph& g) {
    cout << "d[]:" << endl;
    for (int i = 1; i <= g.getNodeCounter(); i++) {
        cout << "  " << i << "\t" << d[i] << endl;
    }
    cout << endl << endl;
    //    cout << " ***** d[] done *****" << endl;
}

void printOpenNodes(vector<int> openNodes) {
    cout << "open nodes:" << endl;
    for (unsigned int i = 0; i < openNodes.size(); i++) {
        cout << "  " << openNodes[i] << endl;
    }
}

int * countDijkstra(const CGraph& g, int startNodeNum) {
    if (verbose) {
        cout << endl << endl << endl << endl << endl;
        cout << "countDijkstra (" << startNodeNum << ")" << endl;
    }

    d = new int[g.getNodeCounter() + 1];
    p = new int[g.getNodeCounter() + 1];

    d[0] = -1;
    p[0] = -1;

    // InitPaths
    for (int i = 1; i <= g.getNodeCounter(); i++) {
        d[i] = LENGTH_MAX;
        p[i] = NULL_NODE;
    }
    d[startNodeNum] = 0;

    //    printD(g);

    // Algorithm
    vector<int> openNodes;
    //    vector<int> closedNodes;

    for (int i = 1; i <= g.getNodeCounter(); i++) {
        openNodes.push_back(i);
    }

    int cnt = 0;
    while (openNodes.size() > 0) {
        if (verbose) {
            cout << " ------ while iteration " << cnt++ << endl;
            printOpenNodes(openNodes);
        }

        int index = findMinDU(openNodes);
        if (index == -1) { // No connected node found, only in infinite distance
            break;
        }

        int nodeNum = openNodes[index];

        if (verbose) cout << "selected node #" << nodeNum << "  (len " << d[nodeNum] << ")" << endl;

        openNodes.erase(openNodes.begin() + index);
        //        closedNodes.push_back(nodeNum);

        vector<t_edge> neighbors = getEdges(nodeNum, g);
        for (unsigned int i = 0; i < neighbors.size(); i++) {
            relax(nodeNum, neighbors[i].destinationIndex, g);
        }

        if (verbose) printD(g);
    }

    if (verbose) {
        cout << "-----------------------------------------" << endl;
        cout << "End of Dijkstra" << endl;
    }

    int nodeCount = g.getNodeCounter();
    int * res = new int[nodeCount + 2];
    for (int i = 1; i <= g.getNodeCounter(); i++) {
        res[i] = d[i];
        if (verbose)cout << "  " << i << ": " << d[i] << endl;
    }

    if (verbose)cout << "-----------------------------------------" << endl;

    delete [] d;
    delete [] p;


    return res;
}

string getHourStr(int time) {
    ostringstream oss;

    //    string res = "";
    if (time / 60 < 10) {
        oss << "0" << (time / 60);
    } else {
        oss << (time / 60);
    }

    oss << ":";
    if (time % 60 < 10) {
        oss << "0" << (time % 60);
    } else {
        oss << time % 60;
    }

    //    cout << "[gHS: "<<res<<"]";

    return oss.str();
}

void fillNeighborsArray(const CGraph& g) {
    edgesArray = new vector<t_edge>[g.getNodeCounter() + 2];

    for (int i = 1; i <= g.getEdgeCounter(); i++) {
        edgesArray[g.getEdge(i).sourceIndex].push_back(g.getEdge(i));
    }
}

void printNeighborsArray(const CGraph& g) {
    cout << " ------------------------------------- " << endl;
    cout << "Neighbors:" << endl;

    for (int i = 1; i <= g.getNodeCounter(); i++) {
        //        cout << "[ "<<i<<" ]"<<endl;
        for (unsigned int j = 0; j < edgesArray[i].size(); j++) {
            t_edge e = edgesArray[i][j];
            cout << "  " << e.sourceIndex << " -> " << e.destinationIndex << " (" << e.value << ")" << endl;
        }
    }

    cout << " ------------------------------------- " << endl;
}

bool meeting(const CGraph& g, ostream& os) {

    //    cout << " NODES: " << endl;
    //    for (int i = 1; i <= g.getNodeCounter(); i++) {
    //        cout << i << "\t" << g.getNode(i).characterid << " - " << g.getNode(i).startTime << endl;
    //    }

    fillNeighborsArray(g);
    //    printNeighborsArray(g);

    //    return false;

    int sheldonStartNode = findStartNode(g, SHELDON);
    int amyStartNode = findStartNode(g, AMY);
    int jaraStartNode = findStartNode(g, JARA);

    int * sheldonTimes = countDijkstra(g, sheldonStartNode);
    int * amyTimes = countDijkstra(g, amyStartNode);
    int * jaraTimes = countDijkstra(g, jaraStartNode);




    double*arrivalTimes = new double[g.getNodeCounter() + 1];

    double minWaitTime = -1;
    int minArrivalTime = -1;

    for (int i = 1; i <= g.getNodeCounter(); i++) {

        if (sheldonTimes[i] == LENGTH_MAX || amyTimes[i] == LENGTH_MAX || jaraTimes[i] == LENGTH_MAX) {
            arrivalTimes[i] = -1;
            continue;
        }

        sheldonTimes[i] += g.getNode(sheldonStartNode).startTime;
        amyTimes[i] += g.getNode(amyStartNode).startTime;
        jaraTimes[i] += g.getNode(jaraStartNode).startTime;


        if (i % 5 == 0) {
            arrivalTimes[i] = -1;
            continue;
        }

        if (amyTimes[i] < sheldonTimes[i] || amyTimes[i] < jaraTimes[i]) {
            arrivalTimes[i] = -1;
            continue;
        }

        if (sheldonTimes[i] > 60 * 24 || jaraTimes[i] > 60 * 24 || amyTimes[i] > 60 * 24) {
            arrivalTimes[i] = -1;
            continue;
        }

        double waitTime = ((double) ((amyTimes[i] - sheldonTimes[i]) + (amyTimes[i] - jaraTimes[i]))) / 2;
        arrivalTimes[i] = waitTime;

        if (minWaitTime == -1 || waitTime < minWaitTime) {
            minWaitTime = waitTime;
            minArrivalTime = amyTimes[i];
        } else if (waitTime == minWaitTime) {
            if (minArrivalTime == -1 || amyTimes[i] < minArrivalTime) {
                minArrivalTime = amyTimes[i];
            }
        }
    }

    if (minWaitTime == -1) {
        delete [] edgesArray;
        delete [] arrivalTimes;
        delete [] sheldonTimes;
        delete [] amyTimes;
        delete [] jaraTimes;
        return false;
    }



    for (int i = 1; i <= g.getNodeCounter(); i++) {
        if (arrivalTimes[i] == minWaitTime && amyTimes[i] == minArrivalTime) {
            if (sheldonTimes[i] <= jaraTimes[i]) {
                os << i << "::Sheldon:" << getHourStr(sheldonTimes[i]);
                os << ", Kren:" << getHourStr(jaraTimes[i]);
                os << ", Amy:" << getHourStr(amyTimes[i]) << endl;
            } else {
                os << i << "::Kren:" << getHourStr(jaraTimes[i]);
                os << ", Sheldon:" << getHourStr(sheldonTimes[i]);
                os << ", Amy:" << getHourStr(amyTimes[i]) << endl;
            }
        }
    }

    delete [] edgesArray;
    delete [] arrivalTimes;
    delete [] sheldonTimes;
    delete [] amyTimes;
    delete [] jaraTimes;

    return true;
}
