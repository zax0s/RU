/*!
  \file
  \ingroup  ImageSpace
  \brief    Implementation of class ImageSpace
*/

#include "../include/ImageSpace.hh"
#include <cstddef>
#include <iostream>
#include <fstream>
using namespace std;

ImageSpace::ImageSpace()
{
  m_loadedImage=false;
  m_loadedMask=false;
  m_nbVoxX=-1;
  m_nbVoxY=-1;
  m_nbVoxXY=-1;
  mp_image=NULL;
  mp_outputImage=NULL;
  mp_maskImage=NULL;
}
ImageSpace::~ImageSpace()
{
  // Dealocate images if initialised
  // Test the pointer existence if not NULL
  if (mp_image!=NULL) if (mp_image) delete (mp_image);
  if (mp_outputImage!=NULL) if (mp_outputImage) delete (mp_outputImage);
  if (mp_maskImage!=NULL) if (mp_maskImage) delete (mp_maskImage);
}

// =====================================================================
// Initialise and set parameters
// =====================================================================

int ImageSpace::Initialize(int dimx, int dimy, const string& path_to_image_filename, const string& path_to_mask_filename)
{
  cout << "ImageSpace::Initialize() -> Initialising" << endl;

  // Setting input dimensions
  m_nbVoxX=dimx;
  m_nbVoxY=dimy;
  m_nbVoxXY=m_nbVoxX*m_nbVoxY;

  // Set flags
  if (!path_to_image_filename.empty()) m_loadedImage=true;
  if (!path_to_mask_filename.empty()) m_loadedMask=true;

  // Check if dimensions are valid
  if ((m_nbVoxX<=0)||(m_nbVoxY<=0))
  {
    cout << "****** ImageSpace::Initialize() -> Invalid dimension options" << endl;
    return 1;
  }

  // Allocate memory for the input, mask and output images
  mp_image = new float[m_nbVoxXY];
  mp_maskImage = new float[m_nbVoxXY];
  mp_outputImage = new float[m_nbVoxXY];

  // TODO: Switch these reading functions to support the final image format (Interfile, nifti, or other)
  // If files provided, use them to read the images to memory
  if (m_loadedImage)
  {
    // Allocate temporary reading buffer
    float* bytes = (float*)malloc(m_nbVoxXY*sizeof(float));
    ifstream afile;
    afile.open(path_to_image_filename.c_str(), ios::binary | ios::in);
    afile.read((char*)bytes, m_nbVoxXY*sizeof(float));
    if (!afile.good())
    {
      if (afile.eof()) cout << "***** ImageSpace::ReadImageData() -> Not enough data in the provided image file !" << endl;
      else cout <<"***** ImageSpace::ReadImageData() -> An error occurred while reading from the provided image file !" << endl;
      free(bytes);
      return 1;
    }
    // Copy buffered image to image variable and free the buffer
    for (int v=0; v<m_nbVoxXY; v++) mp_image[v]=bytes[v];
    free(bytes);
  }
  // For no provided input image, initialise everywhere with 1
  else
  {
    for (int v=0; v<m_nbVoxXY; v++) mp_image[v] = 1.;
  }

  // If files provided, use them to read the images to memory
  if (m_loadedMask)
  {
    // Allocate temporary reading buffer
    float* bytes = (float*)malloc(m_nbVoxXY*sizeof(float));
    ifstream afile;
    afile.open(path_to_mask_filename.c_str(), ios::binary | ios::in);
    afile.read((char*)bytes, m_nbVoxXY*sizeof(float));
    if (!afile.good())
    {
      if (afile.eof()) cout << "***** ImageSpace::ReadImageData() -> Not enough data in the provided image file !" << endl;
      else cout <<"***** ImageSpace::ReadImageData() -> An error occurred while reading from the provided image file !" << endl;
      free(bytes);
      return 1;
    }
    // Copy buffered image to image variable and free the buffer
    for (int v=0; v<m_nbVoxXY; v++) mp_maskImage[v]=bytes[v];
    free(bytes);
  }
    // For no provided input image, initialise everywhere with 0
  else
  {
    for (int v=0; v<m_nbVoxXY; v++) mp_maskImage[v] = 0.;
  }

  // Check if mask values are valid (0s and 1s only)
  for (int v=0; v<m_nbVoxXY; v++)
  {
    if ((mp_maskImage[v]>1)|(mp_maskImage[v]<0))
    {
      cout <<"***** ImageSpace::ReadImageData() -> Invalid mask value encountered !" << endl;
      return 1;
    }
  }

return 0;
}

// =====================================================================
// Write Output
// =====================================================================

int ImageSpace::WriteOutput(const string& path_to_output, const string& suffix)
{
  // Get the path to the output directory
  string OutputFilePath;
  string OutputFileName;
  string OutputImageFullPath;

   // Extract the path from the header file name
  size_t last_slash = path_to_output.find_last_of("/");
  if (last_slash==string::npos)
  {
    OutputFilePath = "";
    OutputImageFullPath = path_to_output;
  }
  else
  {
    OutputFilePath = path_to_output.substr(0, last_slash + 1);
    OutputFileName = path_to_output.substr(last_slash + 1);
    OutputImageFullPath = OutputFilePath+"/"+OutputFileName;
  }
  // If suffix provided for the output image, add in final Output file name
  string final_suffix;
  if (!suffix.empty()) final_suffix="_"+suffix;
  OutputImageFullPath = OutputImageFullPath+final_suffix + ".img";
  cout << "ImageSpace::WriteOutput() -> Output image will be written at " << OutputImageFullPath << endl;

  // Finally write the output image to file
  FILE* pFile = fopen(OutputImageFullPath.c_str(), "wb");
  fwrite(mp_outputImage, sizeof(float), m_nbVoxXY, pFile);
  fclose(pFile);

  return 0;
}