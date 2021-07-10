/*!
  \file
  \ingroup  ImageSpace
  \brief    Implementation of class ImageSpace
*/

#include "../include/ImageSpace.hh"
#include <cstddef>
#include <iostream>
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
    FILE* pmmap = fopen(path_to_image_filename.c_str(),"r");
    fread(mp_image,sizeof(float),m_nbVoxXY,pmmap);
    fclose(pmmap);
  }
  // For no provided input image, initialise everywhere with 1
  else
  {
    for (int v=0; v<m_nbVoxY; v++) mp_image[v] = 1.;
  }

  // If files provided , use them to read the images to memory
  if (m_loadedMask)
  {
    FILE* pmmap = fopen(path_to_image_filename.c_str(),"r");
    fread(mp_maskImage,sizeof(float),m_nbVoxXY,pmmap);
    fclose(pmmap);
  }
    // For no provided input image, initialise everywhere with 1
  else
  {
    for (int v=0; v<m_nbVoxY; v++) mp_maskImage[v] = 1.;
  }

return 0;
}