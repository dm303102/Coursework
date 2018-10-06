// Example image reading and writing code for pnm file images.
// And dealing with multidimensional images.
//
// Written by David M. Chelberg
// last-modified: Mon Feb 6 16:35:07 2007

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

// This is a VERY simple class
// A real image class should have more robust operators.
// DMC last-modified: Mon Feb 6 16:35:07 2007
class Image {
public:
  Image();
  Image(size_t nrows, size_t ncols, size_t ndims=1);
  Image(const Image &in);

  ~Image();

  // does the actual constructing work.
  void construct(size_t nrows, size_t ncols, size_t ndims=1);
  // Clears an array
  void clear(unsigned char clear_val=0);
  // Copies one array into another
  void copy(const Image &in);

  // Can use to index into a 2D image Image a; 
  // a(row, col) indexes into the element of the array.
  // The first version of the operator is for writing into the array
  // The second is to return the value of the array.
  unsigned char& operator()(const size_t row, const size_t col)
  {
    return (ar[row*cols+col]);
  }

  const unsigned char& operator()(const size_t row, const size_t col) const
  {
    return (ar[row*cols+col]);
  }

  // Can use to index into a 3D image Image a; 
  // a(row, col, index) indexes into the element of the array at location row, col.  Index allows for color imagees (index
  // 0 is red, 1 is green, 2 is blue).
  // The first version of the operator is for writing into the array
  // The second is to return the value of the array.
  unsigned char& operator()(const size_t row, const size_t col, const size_t index)
  {
    return (ar[row*cols*dims+col*dims+index]);
  }

  const unsigned char& operator()(const size_t row, const size_t col, const size_t index) const
  {
    return (ar[row*cols*dims+col*dims+index]);
  }
  unsigned char *ar;
  size_t rows;
  size_t cols;
  size_t dims;
  string comment;
};

// The following implement reading and writing PNM format files.
// The are rudimentary and do not check for many errors.
// Use the first one to read in an image, the second is mainly for internal purposes.
void OpenGraphicFile(istream& ins, Image &img);
// This one is a helper for the function above.
void ReadGraphicFile(istream &ins, Image &img);
// You can use this one to write out an image.
void WritePNMFile(Image &img, const string &filename, const string &comment);
// This one is a helper to the above routine.
void WritePNM(Image &img, ostream &outs, const string &comment);
#endif
