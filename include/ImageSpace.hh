/*!
  \file
  \ingroup  CoreUtilities
  \brief    Declaration of class ImageSpace
*/

#ifndef IMAGESPACE_HH
#define IMAGESPACE_HH 1

#include <iostream>
using namespace std;

/*!
  \class   ImageSpace
  \brief   This class holds all the matrices in the image domain that are then used in reconstruction and image processing
  \details Image matrices are public and can be directly accessed from each classes. \n
           It also includes many functions for initializating, reseting, or deforming the images. \n
           Mandatory Reconstruction image matrices : \n
           WorkingImage:                  1 pointer: 1: 3D/2D voxels \n
           MaskImage:              1 pointer: 1: 3D/2D voxels \n
           OutputImage:            1 pointer: 1: 3D/2D voxels \n
*/
class ImageSpace
{
  // Constructor & Destructor
  public:
  /*!
    \brief   ImageSpace constructor.
             Initialize the member variables to their default values.
  */
  ImageSpace();

  /*!
    \brief   ImageSpace destructor.
  */
  ~ImageSpace();

  /*!
    \fn      ImageSpace::Initialise
    \brief   Initilise after construction and perform checks
  */
  int Initialize(int dimx, int dimy, const string& path_to_image_filename, const string& path_to_mask_filename);

  /*!
    \fn      ImageSpace::CopyInputToOutput
    \brief   Copy the Input Image to the Output
  */
  inline void CopyInputToOutput()
  {
    for (int v=0; v<m_nbVoxXY; v++) mp_outputImage[v] = mp_image[v];
  }

  /*!
  \fn      ImageSpace::CopyMaskToOutput
  \brief   Copy the Mask Image to the Output
*/
  inline void CopyMaskToOutput()
  {
    for (int v=0; v<m_nbVoxXY; v++) mp_outputImage[v] = mp_maskImage[v];
  }

  /*!
    \fn      ImageSpace::WriteOutput
    \brief   Copy the Input Image to the Output
  */
  int WriteOutput(const string& path_to_output, const string& suffix="");

  /*!
  \fn      public inline ImageSpace::GetNbVoxX()
  \brief   Get the number of voxels along the X axis
  \return  m_nbVoxX
*/
  inline int GetNbVoxX()
  {return m_nbVoxX;}

  /*!
  \fn      public inline ImageSpace::GetNbVoxY()
  \brief   Get the number of voxels along the Y axis
  \return  m_nbVoxY
  */
    inline int GetNbVoxY()
    {return m_nbVoxY;}

  /*!
  \fn      public inline ImageSpace::GetNbVoxX()
  \brief   Get the number of voxels along the XY plane
  \return  m_nbVoxXY
  */
    inline int GetNbVoxXY()
    {return m_nbVoxXY;}


  // public pointers to allow access to images from other classes
  float*   mp_image; /*!< Working image in reconstruction and input for processing,
                              1: 3D/2D voxels */

  float*   mp_outputImage; /*!< Reconstructed image or output from processing,
                              1: 3D/2D voxels */

  float*   mp_maskImage; /*!< Mask binary image,
                              1: 3D/2D voxels */



  // -------------------------------------------------------------------
  // Data members
public:


private:
  int m_nbVoxX;                             /*!< The number of voxels along the X axis */
  int m_nbVoxY;                             /*!< The number of voxels along the Y axis */
  int m_nbVoxXY;                            /*!< The number of voxels in a slice */
  
  bool m_loadedImage;                       /*!< Flag indicating if an input image has been loaded */
  bool m_loadedMask;                        /*!< Flag indicating if a mask image has been loaded */

};

#endif