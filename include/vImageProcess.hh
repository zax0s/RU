/*!
  \file
  \ingroup  dynamic
  \brief    Declaration of class vImageProcess
*/

#ifndef VIMAGEPROCESS_HH
#define VIMAGEPROCESS_HH 1

#include "ImageSpace.hh"


/*!
  \class   vImageProcess
  \brief   This is the mother class of image processing classes
  \details This class is a virtual one, in the sense that it cannot be used on its own \n
           Its children are implementations of actual image processing models. \n

           //TODO: Define these functions
           All children must implement the following pure virtual functions: \n
            - ReadAndCheckConfigurationFile(): read specific options from a configuration file \n
            - ReadAndCheckOptionsList(): read specific options from a string \n
            - ShowHelp(): print helps about the projector specifications \n
            - Initialize(): initialize specific data of the projector (if required) \n
            - CheckParameters(): Check the initialization of the parameters (if required) \n

            - EstimateModelParameters() : (virtual only)  \n
                                          Estimate any temporal functions or coefficients  \n
                                          related to the dynamic model (if required) \n
            - EstimateImageWithModel(): Fit the dynamic model to the series of dynamic images
*/

class vImageProcess {
  // -----------------------------------------------------------------------------------------
  // Constructor & Destructor
public:
  /*!
    \fn      vImageProcess::vImageProcess
    \brief   Constructor of vImageProcess. Simply set all data members to default values.
  */
  vImageProcess();

  /*!
    \fn      vImageProcess::~vImageProcess
    \brief   Destructor of vImageProcess.
  */
  virtual ~vImageProcess();

  // -----------------------------------------------------------------------------------------
  // Public member functions related to the initialization of the model
public:
  /*!
  \fn      vImageProcess::SetImageSpace
  \param   ap_ImageSpace
  \brief   Set the image space for getting access to input/output images and their dimensions
*/
  inline void SetImageSpace(ImageSpace *ap_ImageSpace) { mp_ImageSpace = ap_ImageSpace; }

  /*!
  \fn      vImageProcess::Initialize
  \brief   A public function used to initialize the ImageProcess model
  \details This function does not take any parameter and is used to initialize everything
           that is generic and required for all ImageProcesses.
           At the end, it calls the pure virtual InitializeSpecific() function implemented by children ImageProcesses.
  \return  0 if success, other value otherwise.
  */
  int Initialize();

  /*!
    \fn      vImageProcess::InitializeSpecific() = 0
    \brief   A private function used to initialize everything specific to the child ImageProcess model
    \details This function is used to initialize everything specific to the ImageProcess that should be
             initialized. It is called by the Initialize() function. It is pure virtual so is
             implemented only by children.
    \return  An integer reflecting the initialization status; 0 if run normally, another value
             otherwise.
  */
  virtual int InitializeSpecific(const string& process_options) = 0;

  /*!
  \fn      vImageProcess::ApplyProcess() = 0
  \brief   A private function used to initiate the process
  \details This is a pure virtual function so it is implemented only by children.
  \return  An integer reflecting the initialization status; 0 if run normally, another value
           otherwise.
*/
  virtual int ApplyProcess() = 0;

  /*!
    \fn      vImageProcess::ShowHelpModelSpecific
    \brief   This function is used to print out specific help about the ImageProc   ess model and its options. It is
             pure virtual and implemented by children.
  */
  virtual void ShowHelpModelSpecific() = 0;

  /*!
    \fn      vImageProcess::ShowHelp
    \brief   This function is used to print out general help about ImageProcessing models and their generic options.
  */
  void ShowHelp();

  // -----------------------------------------------------------------------------------------
  // Data members
protected:
  ImageSpace* mp_ImageSpace;                     /*!< Pointer to the ImageSpace object in use */
  int m_repetations;                             /*!< Number of iterations/repetitions of the applications of the process */
  string process_parameters;                     /*!< The process parameter details provided by the user */

};
#endif