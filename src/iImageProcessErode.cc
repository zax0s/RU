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
  m_kernelSizeXY=-1;
  m_nbVoxPadX=-1;
  m_nbVoxPadY=-1;
  mp_kernel=NULL;
}
iImageProcessErode::~iImageProcessErode(){


}


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
  cout << "Using Kernel size" << m_kernelSize << endl;
  // Initialise kernel - In this implementation we assume an isotropic and square kernel of 1s
  m_kernelSizeXY=m_kernelSize*m_kernelSize;
  mp_kernel = new float[m_kernelSizeXY];
  for (int v=0;v<m_kernelSizeXY;v++) mp_kernel[v]=1;

  // We allocate a padded image for the processing- We pad the image with the size of the kernel minus 1 ( in X and Y )
  m_nbVoxPadX=mp_ImageSpace->GetNbVoxX() + m_kernelSize -1 ;
  m_nbVoxPadY=mp_ImageSpace->GetNbVoxY() + m_kernelSize -1 ;
  mp_paddedImage = new float[m_nbVoxPadX*m_nbVoxPadY];
  // initialise with zero
  for (int v=0;v<(m_nbVoxPadX*m_nbVoxPadY);v++) mp_paddedImage[v]=1;

  // Set the offsets ( we devide the integer m_kernelSize with 2 to get the offset for the paddded image side )
  int m_offsetY = m_kernelSize / 2;
  int m_offsetX = m_kernelSize / 2;

  // Copy the working image into the allocated padded image space
  for (int y=0;y<mp_ImageSpace->GetNbVoxY();y++)
  {
    // Pad coordinate Y
    int pady = y + m_offsetY;
    for (int x=0;x<mp_ImageSpace->GetNbVoxX();x++)
    {
      // Pad coordinate X
      int padx = x + m_offsetX;
      // Calculate index of original image space
      int idx_orig = y*mp_ImageSpace->GetNbVoxX()+x;
      // Calculate index of padded image space
      int idx_pad = pady*m_nbVoxPadX+padx;
      // Copy the image between the two indexes
      mp_paddedImage[idx_pad] = mp_ImageSpace->mp_image[idx_orig];
    }
  }

  // Copy input image to output image before applying the kernel

  // Start erosion operation to save to output image
  for (int y=0;y<mp_ImageSpace->GetNbVoxY();y++)
  {
    // Pad coordinate Y
    int pady = y + m_offsetY;
    for (int x=0;x<mp_ImageSpace->GetNbVoxX();x++)
    {
      // Pad coordinate X
      int padx = x + m_offsetX;
      // Calculate index of original image space
      int idx_orig = y*mp_ImageSpace->GetNbVoxX()+x;
      // Calculate index of padded image space (the central pixel location where the kernel operation will be applied)
      int idx_pad = pady*m_nbVoxPadX+padx;

      // Inner loops on kernel dimensions
      int idx_kernel=0;
      for (int ky=0;ky<m_kernelSize;ky++)
      {
        // Pad Y Coordinate for kernel
        int ky_pad = (y + ky) * m_nbVoxPadX;
        for (int kx=0;kx<m_kernelSize;kx++)
        {
          // Pad X Coordinate for kernel
          int kx_pad = (x + kx);
          //Apply contributions
          mp_ImageSpace->mp_outputImage[idx_orig] += mp_paddedImage[idx_pad] * mp_kernel[idx_kernel];
          idx_kernel++;
        }
      }
    }
  }

  cout << " iImageProcessErode::ApplyProcess() -> Applying erosion " << endl;


  return 0;
}
