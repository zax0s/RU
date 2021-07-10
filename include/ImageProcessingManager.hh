/*!
  \file
  \ingroup  image_processing
  \brief    Declaration of class ImageProcessingManager
*/

#ifndef IMAGEPROCESSINFMANAGER
#define IMAGEPROCESSINFMANAGER_HH 1


#include <iostream>
#include "ImageSpace.hh"
using namespace std;

/*!
  \class   ImageProcessingManager
  \brief   This class holds all the generic functions to manage image processing modules/operations
  \details The manager is created by default within the main program and used when called upon with the approriate options
*/

class ImageProcessingManager
{
  // Constructor & Destructor
  public:
  /*!
  \brief   ImageProcessingManager constructor.
           Initialize the member variables to their default values.
*/
  ImageProcessingManager();

  /*!
    \brief   ImageProcessingManager destructor.
  */
  ~ImageProcessingManager();


  /*!
    \fn      ImageProcessingManager::Initialise
    \brief   Initilise after construction and perform checks
  */
  int Initialize(const string& image_processing_options);

  /*!
    \fn      ImageProcessingManager::RunProcess
    \brief   Run the image process
  */
  int Process(const string& image_processing_options);

  // -------------------------------------------------------------------
  // Data members
  private:
  ImageSpace* mp_ImageSpace;                 /*!< Pointer to the ImageSpace object (already in use) */
  // TODO: Change to allow for multiple ImageProcessing objects to be applied;
  //vImageProcess* mp_ImageProcess;          /*!< ImageProcess model object (virtual) */
  bool m_useProcessing;                      /*!< Flag indicating that use of a dynamic model is enabled or not*/

};
#endif