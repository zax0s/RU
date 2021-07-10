/*!
  \file
  \ingroup  image_processing
  \brief    Implementation of class ImageProcessingManager
*/

#include "../include/ImageProcessingManager.hh"
#include "../include/vImageProcess.hh"
#include "../include/iImageProcessErode.hh"
ImageProcessingManager::ImageProcessingManager()
{
  m_useProcessing=false;
  mp_ImageProcess=NULL;
  mp_ImageSpace=NULL;
}
ImageProcessingManager::~ImageProcessingManager()
{
  // Delete mp_ImageProcess objects
  //if (mp_ImageProcess) delete mp_ImageProcess;
}

// =====================================================================
// Initialise and set parameters
// =====================================================================
int ImageProcessingManager::Initialize(const string& image_processing_options)
{

  cout << "ImageProcessingManager::Initialize() -> Initialising" << endl;
  // Define position of colon for search within the provided image_processing_options
  size_t colon;
  // Define the provided ProcessID and its options (if any provided, after the colon in image_processing_options)
  string processID = "";
  string process_options = "";
  // Get the ImageProcessingOption and its properties
  // Check options
  if (image_processing_options=="")
  {
    // If no options have been provided then the manager will not perform anything
    return 0;
  }
  // Else read the image processing options
  else
  {
    // Search for a colon ":",
    colon = image_processing_options.find_first_of(":");
    // Case 1: we have a colon
    if (colon!=string::npos)
    {
      // Get the model name before the colon
      processID = image_processing_options.substr(0,colon);
      // Get the list of options after the collon
      process_options = image_processing_options.substr(colon+1);
    }
    else
    {
      // Get the model name
      processID = image_processing_options;
      // process_options is empty
      process_options = "";
    }
  }

  // Check the provided ImageProcess name against the available processes.
  // TODO: Find a better way to compare the strings against the available processing options.
  if (processID=="Denoise") {
    cout << "ImageProcessingManager::Initialize() -> Denoise process is not implemented yet !" << endl;}
    else if (processID == "Rotate"){
    cout << "ImageProcessingManager::Initialize() -> Rotate process is not implemented yet !" << endl;}
    else if (processID == "Erode"){
    cout << "ImageProcessingManager::Initialize() -> Erode process selected !" << endl;
    mp_ImageProcess = new iImageProcessErode();
    mp_ImageProcess->InitializeSpecific();
    }
    else if (processID == "Dilate"){
    cout << "ImageProcessingManager::Initialize() -> Dilate process is not implemented yet !" << endl;}
    else if (processID == "FindPerimeter"){
    cout << "ImageProcessingManager::Initialize() -> FindPerimeter process is not implemented yet !" << endl;}
    else{
    cout << "******ImageProcessingManager::Initialize() -> Unknown process '" << processID <<"' !" << endl;
    return 1;
    }

  return 0;
}


