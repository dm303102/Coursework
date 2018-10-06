/* **********************************************************************
 *   Program:  main.cc
 *   Author: Doug Morgan
 *   Class: CS 404
 *   Date: 2-18-07
 *   Description:  The main function initializes the image data through 
 *                 command line parameters. It initializes the Union-Find
 *                 class and stores and processes image info by looping 
 *                 through every row and column in ProcImg and comparing 
 *                 each pixel with its neighbors while merging them into
 *                 sets and tracking there color and location.
 *
 *   Known Bugs:
 ******************************************************************* */

#include<iostream>
//#include "image.h"
#include "ImgProc.h"

int threshold = 200;
int correctedness = 4;

int rows;
int cols;

void ProcImg(UnionFind &PixelSets, Image &img);
int index(int row, int col);

using namespace std;

int main(int argc, char** argv)
{
  Image img;
  Image result;
  UnionFind UF;

  //process command line parameters
  if(argc == 1)
    {}
  else if(argc == 3)
    sscanf(argv[2], "%d", &threshold);
  else if(argc == 5)
    {
      sscanf(argv[2], "%d", &threshold);
      sscanf(argv[4], "%d", &correctedness);
    }
  else
    {
      cerr<<"Invalid parameters\nusage: prog2 -t num -c num\n";
      exit(1);
    }

  OpenGraphicFile(cin, img);
  rows = img.rows;
  cols = img.cols;
  result.construct(img.rows, img.cols, img.dims);
  ThresholdFilter(img, result, threshold);
  //WritePNMFile(result, "result.ppm", "");
  ProcImg(UF, result);
  UF.Stats();

  return 0;
}

void ProcImg(UnionFind &PixelSets, Image &img)
{
  int temp;
  // process image array
  for(size_t i=0; i<img.rows; ++i) {
    for(size_t j=0; j<img.cols; ++j) {
      {
	temp = index(i,j);
        PixelSets.MakeSet(temp, img);

        if(j>0) //left element exists
          {
            if((int)img(i,j,0) == (int)img(i,j-1,0))
	      //not already unioned
	      if(PixelSets.Find(index(i,j)) != PixelSets.Find(index(i,j-1))) 
		 PixelSets.Union(temp,index(i,j-1));
          }
        if(i>0) //top element exists
          {
            if((int)img(i,j,0) == (int)img(i-1,j,0))
	      if(PixelSets.Find(index(i,j)) != PixelSets.Find(index(i-1,j)))
		PixelSets.Union(temp,index(i-1,j));
          }
      }
    }
  }
}

int index(int row, int col)
{
  return ((row*cols)+col);
}
