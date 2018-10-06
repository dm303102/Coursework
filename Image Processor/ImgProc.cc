/* **********************************************************************
 *   Program:  ImgProc.cc
 *   Author: Doug Morgan
 *   Class: CS 404
 *   Date: 2-18-07
 *   Description:  The file containing the Thresholding function,
 *                 a node class for a pixel, a tree class to hold a tree
 *                 of connected pixels and a UnionFind class to implement
 *                 the Union-Find data structure with tree compression
 *                 and Union-by-rank.
 *
 *   Known Bugs:
 ******************************************************************* */

#include "ImgProc.h"

void OutputFile(Image &img)
{
  // print data from main array
  for(size_t i=0; i<img.rows; ++i) {
    for(size_t j=0; j<img.cols; ++j) {
      for (size_t k=0; k<img.dims; ++k) {
	std::cout<<(int)img(i,j,k) <<"\n";
      }
    }
  }
}

void ThresholdFilter(Image &source, Image &result, int threshold)
{
  for(size_t i=0; i<source.rows; ++i) {
    for(size_t j=0; j<source.cols; ++j) {
      for (size_t k=0; k<source.dims; ++k)
	{
	  if((int)source(i,j,k) < threshold)
	    result(i,j,k) = (unsigned char)0;
	  else
	    result(i,j,k) = (unsigned char)255;
	}
    }
  }
}

SetData::SetData()
{
  max_x = 0;
  max_y = 0;
  min_x = 0;
  min_y = 0;
  size = 0;
  rank = 0;
  white = false;
}

SetData::SetData(int pixel, Image &source)
{
  max_x = col(pixel);
  max_y = row(pixel);
  min_x = col(pixel);
  min_y = row(pixel);
  size = 1;
  rank = 0;

  if(((int)source(row(pixel), col(pixel))) == 255)
    white = true;
  else
    white = false;
}

void UnionFind::MakeSet(const int pix_ind, Image &img)
{
  SetData *Data;
  SetData Init(pix_ind, img);

  Node node(pix_ind);
  Node *ptr;
  Node *tree;

  nodes[pix_ind] = node;  //make a new node
  ptr = &nodes[pix_ind];
  SetTrees[pix_ind] = ptr;  //make a tree with new node as the root
  set_data[pix_ind] = Init;  //make a new data set with pix_ind data
}

//collapsing find
int UnionFind::Find(int pix_ind)
{
  Node *ptr = &nodes[pix_ind];  //get node to find root
  Node *next = ptr;
  Node *root = ptr;  //used to collapse nodes to root

  while(root->get_parent() != NULL)
    root = root->get_parent();

  next = ptr->get_parent();
  while(next != NULL)
   {
    ptr->set_parent(root);
    ptr = next;
    next = ptr->get_parent();
   }

  return root->get_index();
}

//uses union by rank
void UnionFind::Union(int pix1, int pix2)
{
  int rt1 = Find(pix1);
  int rt2 = Find(pix2);
  int dest;  //Tree to be used for union
  int old;   //Tree appended to new tree
  SetData dat1 = set_data[rt1];
  SetData dat2 = set_data[rt2];
  int max_col1 = dat1.get_max_x();
  int min_col1 = dat1.get_min_x();
  int max_row1 = dat1.get_max_y();
  int min_row1 = dat1.get_min_y();
  int max_col2 = dat2.get_max_x();
  int min_col2 = dat2.get_min_x();
  int max_row2 = dat2.get_max_y();
  int min_row2 = dat2.get_min_y();
 
  Node *root1 = SetTrees[rt1];
  Node *root2 = SetTrees[rt2]; 
  int new_size = dat1.get_size() + dat2.get_size();


  if(dat1.get_rank() > dat2.get_rank())
    {
      root2->set_parent(root1);  //append smaller tree to root of the other
      dest = rt1;  //index used to update new tree data
      SetTrees[rt2] = NULL;  //NULL root pointer of appended tree in SetTrees
    }
  else if(dat1.get_rank() < dat2.get_rank())
    {
      root1->set_parent(root2);  //append smaller tree to root of the other
      dest = rt2;  //index used to update new tree data
      SetTrees[rt1] = NULL;  //NULL root pointer of appended tree in SetTrees
    }
  else //they are equal
    {
      root1->set_parent(root2);  //arbitrarily choose root2 as the new tree
      dest = rt2;  //index used to update new tree data
      SetTrees[rt1] = NULL;  //NULL root pointer of appended tree in SetTrees
      set_data[rt2].inc_rank();  //appending equals tree extends height by one
    }

  set_data[dest].set_size(new_size);  //add summed sizes to new tree data

  //Update boundaries
  if(max_col1 > max_col2)
    set_data[dest].set_max_x(max_col1);
  else
    set_data[dest].set_max_x(max_col2);
  if(min_col1 < min_col2)
    set_data[dest].set_min_x(min_col1);
  else
    set_data[dest].set_min_x(min_col2);
  if(max_row1 > max_row2)
    set_data[dest].set_max_y(max_row1);
  else
    set_data[dest].set_max_y(max_row2);
  if(min_row1 < min_row2)
    set_data[dest].set_min_y(min_row1);
  else
    set_data[dest].set_min_y(min_row2);
}

void UnionFind::Stats()
{
  int max = 0;
  int min;
  bool min_set = false; 
  int sum = 0;
  int total = 0;
  int min_x = 0;
  int min_y = 0;
  int max_x = 0;
  int max_y = 0;
  int white = 0;
  int black = 0;

  SetData *ptr;
  for(size_t i=0; i<(rows*cols); ++i)
    {
      if(SetTrees[i] != NULL)
	{
	  ptr = &set_data[i];
	  if(ptr->get_white() == true)
	    white++;
	  else
	    black++;
	  if(ptr->get_size() > max)
	    {
	      max = ptr->get_size();
	      max_x = (ptr->get_max_x() - ptr->get_min_x())/2;
	      max_y = (ptr->get_max_y() - ptr->get_min_y())/2;
	    }
	  if(ptr->get_size() < min || min_set == false)
	    {
	      min_set = true;
	      min = ptr->get_size();
              min_x = (ptr->get_max_x() - ptr->get_min_x())/2;
              min_y = (ptr->get_max_y() - ptr->get_min_y())/2;
	    }
	  sum += ptr->get_size();
	  total ++;
	}
    }

  std::cout<<"Found " <<black <<" black regions and " <<white;
  std::cout<<" white regions.\n";
  std::cout<<"Region\t\tArea(pixels)\tLocation (row, col)\n";
  std::cout<<"Largest\t\t" <<max <<"\t\t" <<max_y <<" " <<max_x <<"\n";
  std::cout<<"Smallest\t" <<min <<"\t\t" <<min_y <<" " <<min_x<<"\n";
  std::cout<<"Mean\t\t" <<(sum/total)<<"\n";
}

int row(const int index) 
{
  return (index%cols);
}

int col(const int index)
{
  return (index/cols);
}
