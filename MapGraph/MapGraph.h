//*************************************************************
// File: MapGraph.h
//
// Description: Constructs a graph in adjacnecy list form
// from a map file reading in a city number, name and x and y 
// coordinates. Then it computes a minimum distance spanning
// tree and outputs a tour of the city graph
//
// Author: Doug Morgan
// Email: dm303102@ohiou.edu
//
// Date: 11-01-05
//*************************************************************
#ifndef MAP_GRAPH
#define MAP_GRAPH


#include<vector>
#include<utility>
#include<list>
#include<string>

class MapGraph
{
public:
    //*************************************************************
    // Function:
    //
    // Purpose: 
    //
    // Parameters:
    //
    // Member/Global variables: 
    //
    // Preconditions:
    //
    // Postconditions:
    //
    // Time analysis: 
    //*************************************************************
    bool add(int num, const std::string s1, const int x, const int y);
    void build_tree();
    int position(const std::string& target);
    void tour(bool verbose);
    void tour_rec(int vertex, double& length, bool output);
    void print_graph();
    void print_tree();
private:
    //Graph represented in adjacency list form 
    std::vector<std::pair<std::pair<std::string, int>, 
      std::pair<int, int> > > headnodes;

    std::vector<std::list<std::pair<int, double> > > adjacency_lists;

    //Minimum Cost Spanning Tree Represented in adjacncy list form
    std::vector<std::pair<std::pair<std::string, int>, 
      std::list<std::pair<int, double> > > > min_tree;

    double tree_length;

    bool* visited;

    double coor_to_weight(const int x1, const int y1, 
			  const int x2, const int y2);
    void init_tree();
};
#endif
