//*************************************************************
// File: MapGraph.cc
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
#include "MapGraph.h"
#include<math.h>
#include<limits>
#include<iostream>

using namespace std;

//*************************************************************
// Function: bool MapGraph::add(int num, const string s1, 
//                              const int x, const int y)
//
// Purpose: adds the a new vertex to headnodes and ajacency_lists
// with the parameter city data
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
bool MapGraph::add(int num, const string s1, const int x, const int y)
{
    list<pair<int, double> > tmp;  //dummy list to add to adjacency_lists
    int v;  //index of added vertex
    int i;
    
    //add new vertex to headnodes and adjacency_lists
    headnodes.push_back(make_pair(make_pair(s1, num), make_pair(x,y)));
    adjacency_lists.push_back(tmp);
    
    //update all other vertices with current being added
    v = headnodes.size() - 1;

    for(i=0; i<v; i++)
    {
	adjacency_lists[i].push_back(
	    make_pair(v, coor_to_weight(headnodes[v].second.first,
					headnodes[v].second.second,
					headnodes[i].second.first,
					headnodes[i].second.second)));
    }
   
    //update added vertex with all other vertices
    for(i=0; i<v; i++)
    {
	adjacency_lists[v].push_back(
	    make_pair(i, coor_to_weight(headnodes[v].second.first,
					headnodes[v].second.second,
					headnodes[i].second.first,
					headnodes[i].second.second)));
    }
}


void MapGraph::build_tree()
{
  int v1, v2;  //the vertices forming an added edge
  double smallest = double(INT_MAX);  //smallest edge not in min_tree
  list<pair<int,double> >::const_iterator list_itr;

  tree_length = 0;

  //copy headnodes to min_tree
  init_tree();

  //intialize visited boolean array
  visited = new bool[headnodes.size()];
  for(int i = 0; i < headnodes.size(); ++i)
    visited[i] = false;

  visited[0] = true;

  //until n-1 edges in min_tree
  for(int e=0; e<headnodes.size()-1; e++)
    {
      for(int i = 0;i <headnodes.size();i++)
	{
	  if(visited[i])
	    {
	      for(list_itr = adjacency_lists[i].begin();
		  list_itr != adjacency_lists[i].end();
		  list_itr++)
		{
		  if(list_itr->second < smallest && !visited[list_itr->first])
		    {
		      smallest = list_itr->second;
		      v1 = i;  //vertex already in visited set
		      v2 = list_itr->first;  //vertex connecting smallest edge
		    }
		}
	    }
	}
      //Add smallest edge to min_tree
      min_tree[v1].second.push_back(make_pair(v2, smallest));
      min_tree[v2].second.push_back(make_pair(v1, smallest));
      visited[v2] = true;
      tree_length += smallest;

      smallest = INT_MAX;
    }
  delete [] visited;
}

void MapGraph::tour(bool verbose)
{
  list<pair<int, double> >::const_iterator adj_itr;
  double length = 0;

  visited = new bool[min_tree.size()];
  for(int i = 0; i < headnodes.size(); ++i)
    visited[i] = false;

  //verbose output
  if(verbose)
    {
      //total cost of tree
      cout<<tree_length;

      //list of edges
      for(int i = 0; i < min_tree.size(); i++)
	{
	  for(adj_itr = adjacency_lists[i].begin();
	      adj_itr != adjacency_lists[i].end();
	      adj_itr++)
	    {
	      cout<<i <<";" <<min_tree[adj_itr->first].first.second;
	    }
	}

      //total cost of tour
      tour_rec(0, length, false);
      cout<<length;

      //tour
      tour_rec(0, length, true);
    }
  else
    {
      tour_rec(0, length, true);
    }
  delete [] visited;
}

void MapGraph::tour_rec(int vertex, double& length, bool output)
{
  list<pair<int, double> >::const_iterator adj_itr;

  visited[vertex] = true;
  if(output)
    {
      cout<<min_tree[vertex].first.second <<";";
    }

  for(adj_itr = min_tree[vertex].second.begin();
      adj_itr != min_tree[vertex].second.end();
      adj_itr++)
    {
      if(!visited[adj_itr->first])
      {
	length += adj_itr->second;
	tour_rec(adj_itr->first, length, output);
      }
    }
}
   
void MapGraph::print_graph()
{
    list<pair<int, double> >::const_iterator adj_itr;

    for(int i=0; i<headnodes.size(); i++)
    {
      cout<<headnodes[i].first.first <<"(" <<headnodes[i].first.second 
	  <<"): \n";

	for(adj_itr = adjacency_lists[i].begin();
	    adj_itr != adjacency_lists[i].end();
	    adj_itr++)
	{
	    cout<<"(ind: " <<adj_itr->first <<", weight: " 
		<<adj_itr->second <<")\n";
	}

	cout<<endl;
    }
}

void MapGraph::print_tree()
{
  list<pair<int, double> >::const_iterator adj_itr;

  for(int i=0; i<min_tree.size(); i++)
    {
      cout<<min_tree[i].first.first <<"(" <<min_tree[i].first.second <<"): \n";

      for(adj_itr = min_tree[i].second.begin();
	  adj_itr != min_tree[i].second.end();
	  adj_itr++)
        {
	  cout<<"(ind: " <<adj_itr->first <<", weight: "
	      <<adj_itr->second <<")\n";
        }

      cout<<endl;
    }
}
	
double MapGraph::coor_to_weight(const int x1, const int y1, const int x2, const int y2)
{
    return sqrt(pow(double(x1-x2), 2.0) + pow(double(y1-y2), 2.0));
}

int MapGraph::position(const string& target)
{
  for(int i = 0; i < headnodes.size(); i++)
    {
      if(target == headnodes[i].first.first)
        return i;
    }
  return -1;
}

void MapGraph::init_tree()
{
  list<pair<int, double> > tmp;  //dummy list to add to min_tree

  for(int i = 0; i<headnodes.size(); i++)
    min_tree.push_back(make_pair(make_pair(headnodes[i].first.first, 
					   headnodes[i].first.second), tmp));
}
				       
