/*!
  \file
  \ingroup  dynamic
  \brief    Implementation of class iImageProcessErode
*/

#include "../include/iImageProcessErode.hh"


/*
  \fn vImageProcess
  \brief Constructor of vImageProcess. Simply set all data members to default values.
*/
iImageProcessErode::iImageProcessErode(){
  m_kernelSize=-1;
}
iImageProcessErode::~iImageProcessErode(){ }





// =====================================================================
// Show specific help
// =====================================================================

/*
  \fn ShowHelp
  \brief Print out general help about image processes
*/
void iImageProcessErode::ShowHelpModelSpecific()
{
  // Nothing to show at the moment that is generic to all processes
  cout << "  This is the model used for the erosion of an input binary mask image" << endl;
  cout << "    it can be called using the -process:erosion option "<< endl;
  cout << "  By default a 3x3 structuring element (kernel) is used in the process of erosion" << endl;
  cout << "  Different size of kernel (limited to square and isotropic kernels) can be used; the desired value " << endl;
  cout << "    can be passed as an argument after the model option with a comma (ex. -process:erosion,3)  " << endl;
}

// =====================================================================
// Initialise specific options
// =====================================================================
/*
  \fn InitializeSpecific
  \brief Initialise specific options about image processes
*/
int iImageProcessErode::InitializeSpecific(const string& process_options)
{
  // Set default values
  m_kernelSize=3;

  if(!process_options.empty())
  {
    cout << "iImageProcessErode::InitializeSpecific() -> Specific option provided: '" << process_options << "'" << endl;
    // Set kernel size by user
    m_kernelSize = atoi(process_options.c_str());
  }
  else
  {
    cout << "iImageProcessErode::InitializeSpecific() -> No options provided; Using default settings" << endl;
  }
  return 0;
}

// =====================================================================
// Apply Process
// =====================================================================
/*
  \fn ApplyProcess
  \brief Apply erosion on working image
*/
int iImageProcessErode::ApplyProcess()
{
    cout << " iImageProcessErode::ApplyProcess() -> Applying erosion " << endl;




  return 0;
}
