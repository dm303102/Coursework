/* **********************************************************************
 *   Program:  ImgProc.h
 *   Author: Doug Morgan
 *   Class: CS 404
 *   Date: 2-18-07
 *   Description:  The header file containing the Thresholding function,
 *                 a node class for a pixel, a tree class to hold a tree
 *                 of connected pixels and a UnionFind class to implement
 *                 the Union-Find data structure with tree compression
 *                 and Union-by-rank.
 *                 
 *   Known Bugs: Only 4-correctedness is implemented
 ******************************************************************* */
#include "image.h"
#include <iostream>
#include <map>

#ifndef MORGAN_IMGPROC
#define MORGAN_IMGPROC

extern int rows;  //global image row count
extern int cols;  //global image column count

//Outputs and image file
void OutputFile(Image &img);

//Converts an image to black and white pixels depending on threshold
void ThresholdFilter(Image &source, Image &result, int threshold);

//computes the 2D reference row for index of a 1D array
int row(const int index);

//computes the 2D reference column for index of a 1D array
int col(const int index);

class Node
{
 public:
  Node() {parent = NULL;}

  //Constuctor to initialuze a node with a given pixel array index
  Node(const int ind) {index = ind; parent = NULL;}

  void set_index(int ind) {index = ind;}

  void set_parent(Node *ptr) {parent = ptr;}

  int get_index() {return index;}

  Node* get_parent() {return parent;}
 
 private:
  int index; //an index of the images pixel array
  Node *parent;
};

//Holds Data for a each tree i to compute output
class SetData
{
 public:

  SetData();

  SetData(int pixel, Image &source);

  int get_max_x() {return max_x;}

  int get_max_y() {return max_y;}

  int get_min_x() {return min_x;}

  int get_min_y() {return min_y;}

  void set_max_x(int num) {max_x = num;}

  void set_max_y(int num) {max_y = num;}

  void set_min_x(int num) {min_x = num;}

  void set_min_y(int num) {min_y = num;}

  int get_size() {return size;}

  void set_size(int num) {size = num;}

  int get_rank() {return rank;}

  void inc_rank() {rank++;}

  bool get_white() {return white;}

  void set_white(bool flag) {white = flag;}
 private:
  int max_x, max_y, min_x, min_y;  //boundary points of a pixel set
  int size;  //number of elements currently in the pixel set
  int rank;  //heuristic to compare smaller and larger pixel set trees
  bool white;  //the pixel set is white if true; else, it is black
};

class UnionFind
{
 public:
  //UnionFind()  

  void MakeSet(const int pix_ind, Image &img);

  int Find(int pix_ind);

  void Union(int pix_set1, int pix_set2);

  void Stats();
 private:
  std::map<int, SetData> set_data;
  std::map<int, Node> nodes;  //storage for all nodes
  std::map<int, Node*> SetTrees;  //trees representing pixel sets
};
#endif
