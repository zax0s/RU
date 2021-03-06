/*!
  \file
  \ingroup  CoreUtilities
  \brief    Declaration of children class iImageProcessErode
*/

#ifndef IIMAGEPROCESSERODE
#define IIMAGEPROCESSERODE_HH 1

#include "vImageProcess.hh"
#include <iostream>
using namespace std;

/*!
  \class   iImageProcessErode
  \brief   This child class holds all the specific functions needed to perform erosion on a 2D binary image
*/

class iImageProcessErode : public vImageProcess
 {
public:
  /*!
  \fn      iImageProcessErode::iImageProcessErode
  \brief   Constructor of iImageProcessErode. Simply set all data members to default values.
*/
  iImageProcessErode();
  /*!
    \fn      iImageProcessErode::~iImageProcessErode
    \brief   Destructor of iImageProcessErode
  */
  ~iImageProcessErode();

public:
  /*!
  \fn      iImageProcessErode::ApplyProcess()
  \brief   A private function used to initiate the process
  \return  An integer reflecting the initialization status; 0 if run normally, another value
           otherwise.
*/
  int ApplyProcess();
  /*!
  \fn      iImageProcessErode::InitializeSpecific()
  \brief   A private function used to initialize everything specific to the child iImageProcessErode model
  \return  An integer reflecting the initialization status; 0 if run normally, another value
           otherwise.
*/
  int InitializeSpecific(const string& process_options);
  /*!
    \fn      vImageProcess::ShowHelpModelSpecific
    \brief   This function is used to print out specific help about the ImageProcess model and its options. It is
             pure virtual and implemented by children.
  */
  void ShowHelpModelSpecific();


  // -----------------------------------------------------------------------------------------
  // Data members
private:
  int m_kernelSize;           /*!< Kernel size (1dimension of 2D kernel) for erosion */
  int m_kernelSizeXY;         /*!< Kernel 2D plane size for erosion */
  int m_nbVoxPadX;            /*!< number of voxels in X direction of padded image */
  int m_nbVoxPadY;            /*!< number of voxels in Y direction of padded image */
  float* mp_kernel;           /*!< 2D Kernel (structuring element) for erosion */
  float* mp_paddedImage;      /*!< 2D padded image to be used during application of erosion */


};


#endif
