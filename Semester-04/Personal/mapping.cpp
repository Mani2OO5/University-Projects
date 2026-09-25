#include <iostream>
#include <string>
#include <map>

using namespace std;

    map <string , string> graph;

    graph["you"]    = ["Alice","Bob","Claire"];
    graph["Alice"]  = ["Peggy"];
    graph["Bob"]    = ["Anuj","Peggy"];
    graph["Claire"] = ["Thom","Johny"];
    graph["Peggy"]  = [];
    graph["Anuj"]   = [];
    graph["Thom"]   = [];
    graph["Johny"]  = [];