#include<iostream>
#include<fstream>
#include "MapGraph.h"

using namespace std;

int string_to_int(const string& s1);

int
main(int argc, char* argv[])
{
    MapGraph M;
    ifstream fin;
    string tmp, city;
    int x, y, i, num;
    bool verbose = false;
      
    if(argc > 2)
    {
	cout<<"Invalid command line arguments\n";
	exit(1);
    }

    for(i=1; i<argc; i++)
    {
	if(argv[i] != "-verbose")
	    fin.open(argv[i]);
	else
	    verbose = true;
    }

    if(fin.fail())
    {
	cout<<"Error opening " <<argv[i];
	exit(1);
    }

    //build graph from map file
    while(!fin.eof())
    {
	getline(fin, tmp, ';');  //read city number
	num = string_to_int(tmp);

	getline(fin, tmp, ';');  //read city name
	city = tmp;

	getline(fin, tmp, ';');  //read state

	getline(fin, tmp, ';');  //read x coordinate
	x = string_to_int(tmp);

	getline(fin, tmp);  //read y coordinate
	y = string_to_int(tmp);

	if(!fin.eof())
	    M.add(num, city, x, y);
    }


    //build minimum distance tree 
    M.build_tree();

    cout<<"\nHere is the graph:\n\n";
    M.print_graph();

    cout<<"\nHere is the Minimum Spanning Tree:\n\n";
    M.print_tree();

    //output tour
    M.tour(verbose);

    return 0;
}

int string_to_int(const string& s1)
{
    return atoi(s1.c_str());
}
