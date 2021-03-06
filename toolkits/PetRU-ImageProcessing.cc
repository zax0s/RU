/*!
  \file
  \ingroup utilities
  \brief  This program is used as an interface to the image processing functions of the PETRU main program.
*/

#include <iostream>
#include "../include/ImageSpace.hh"
#include "../include/ImageProcessingManager.hh"
using namespace std;

/*!
  \fn      ShowHelp()
  \brief   Display main command line options of image processing toolkit
*/
void ShowHelp()
{
  cout << endl;
  cout << "Usage:  PETRU-ImageProcessing  -img input_image.hdr -out output_image.hdr -process operationID:processing_options " << endl;
  cout << endl;
  cout << "[Mandatory parameters]:" << endl;
  cout << "  -dout name           : Give the directory where the output image/images will be written" << endl;
  cout << "  -dimx x              : Give the number of voxels in the 1st dimension [Currently only 2D supported]." << endl;
  cout << "  -dimy y              : Give the number of voxels in the 2nd dimension [Currently only 2D supported]." << endl;
  cout << "  -process             : Give the name of the process to be applied on the input image" << endl;
  cout << "[Mandatory image input (at least one)]:" << endl;
  cout << "  -img input_image.hdr : Give an input image " << endl;
  cout << "  -mask mask_image.hdr : Give an input mask image (float image with 0s and 1s only)" << endl;
  cout << "[Optional parameters]:" << endl;
  cout << "  -help-process        : Show the list and description of all implemented processing operations" << endl;
  cout << "  --help,-h,-help      : Print out this help page." << endl;
  cout << endl;
}

/*!
  \fn      ShowHelp()
  \brief   Display main command line options of image processing toolkit
*/
void ShowHelpProccesses()
{
  cout << endl;
  cout << "  The available image processing options are: " << endl;
  cout << endl;
  cout << "  Erode (mask only): This is an erosion operation to be applied on the input binary mask.  " << endl;
  cout << "                     The size of the structuring element (isotropic square kernel) can be  " << endl;
  cout << "                     set as an option with a collon after the option (ex. -Erode:3).       " << endl;
  cout << "                     Only odd numbers are valid for the kernel size (default value: 3).    " << endl;
  cout << endl;
}

// =============================================================================================================================================
//                                                        M A I N     P R O G R A M
// =============================================================================================================================================

int main(int argc, char** argv)
{
  // No argument, then show help
  if (argc==1)
  {
    ShowHelp();
    exit(EXIT_SUCCESS);
  }

  // ============================================================================================================
  // Variables with their default values
  // ============================================================================================================
  // String to the input image filename
  string path_to_image_filename = "";
  // String to the mask image filename
  string path_to_mask_filename = "";
  // Output directory name.
  string path_dout = "";
  // String gathering the processing options
  string process_options = "";


  // Initialization of the voxel dimensions to -1;
  int nb_voxX=-1, nb_voxY=-1;


  // ============================================================================================================
  // Read command-line parameters
  // ============================================================================================================

  // Must manually increment the option index when an argument is needed after an option
  for (int i=1; i<argc; i++)
  {
    // Get the option as a string
    string option = (string)argv[i];

    // Show help
    if (option=="-h" || option=="--help" || option=="-help")
    {
      ShowHelp();
      exit(EXIT_SUCCESS);
    }
    // Show specific help for image processes
    if (option=="-help-process")
    {
      ShowHelpProccesses();
      exit(EXIT_SUCCESS);
    }
    // --------------------------------------------------------------------------------
    // Input image
    // --------------------------------------------------------------------------------

    else if (option=="-img")
    {
      if (i>=argc-1)
      {
        cout << "***** PETRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      path_to_image_filename = (string)argv[i+1];
      i++;
    }

    else if (option=="-mask")
    {
      if (i>=argc-1)
      {
        cout << "***** PETRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      path_to_mask_filename = (string)argv[i+1];
      i++;
    }

    // --------------------------------------------------------------------------------
    // Output image/images
    // --------------------------------------------------------------------------------

    // Name of the output directory
    else if (option=="-dout")
    {
      if (i>=argc-1)
      {
        cout << "***** PETRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      path_dout = argv[i+1];
      i++;
    }

    // --------------------------------------------------------------------------------
    // Dimensions: number of voxels
    // --------------------------------------------------------------------------------

    else if (option=="-dimx")
    {
      if (i>=argc-1)
      {
        cout << "***** PETRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      nb_voxX= atoi(argv[i+1]);
      i++;
    }

    else if (option=="-dimy")
    {
      if (i>=argc-1)
      {
        cout << "***** PETRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      nb_voxY= atoi(argv[i+1]);
      i++;
    }

    // --------------------------------------------------------------------------------
    // Processing options
    // --------------------------------------------------------------------------------

    else if (option=="-process")
    {
      if (i>=argc-1)
      {
        cout << "***** PETRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      process_options = (string)argv[i+1];
      i++;
    }


    // --------------------------------------------------------------------------------
    // Unknown option!
    // --------------------------------------------------------------------------------
    else
    {
      cout << "***** PETRU-ImageProcessing() -> Unknown option '" << option << "' !" << endl;
      exit(EXIT_FAILURE);
    }
  }

  //#ifdef DEBUG
  cout << endl;
  cout << "Usage:  PETRU-ImageProcessing  -img input_image.hdr -out output_image.hdr -process operationID:processing_options " << endl;
  cout << endl;
  cout << "Provided input options" << endl;
  cout << "  -img input_image.hdr : "<< path_to_image_filename << endl;
  cout << "  -dout name           : " << path_dout << endl;
  cout << "  -dimx x              : " << nb_voxX << endl;
  cout << "  -dimy y              : " << nb_voxY << endl;
  cout << "  -process             : " << process_options << endl;
  cout << "  -mask mask_image.hdr : " << path_to_mask_filename << endl;
  cout << endl;
  //#endif DEBUG

  // Check if at least one image has been provided
  if ((path_to_image_filename.empty())&&(path_to_mask_filename.empty()))
  {
    cout << "**PETRU-ImageProcessing() -> Provide at least one input image ! " << endl;
    exit(EXIT_FAILURE);
  }

  // ============================================================================================================
  // Allocate and load images ( if provided )
  // ============================================================================================================
  ImageSpace* p_ImageSpace = new ImageSpace();
  if (p_ImageSpace->Initialize(nb_voxX,nb_voxY,path_to_image_filename,path_to_mask_filename))
  {
    cout << "**PETRU-ImageProcessing() -> Something went wrong while initialising ImageSpace " << endl;
    exit(EXIT_FAILURE);
  }

  // ============================================================================================================
  // Initialise Processing manager
  // ============================================================================================================
  ImageProcessingManager* p_ImageProcessingManager = new ImageProcessingManager();
  // Set the Image Space to the manager
  p_ImageProcessingManager->SetImageSpace(p_ImageSpace);
  if (p_ImageProcessingManager->Initialize(process_options))
  {
    cout << "**PETRU-ImageProcessing() -> Something went wrong while initialising ImageProcessingManager " << endl;
    exit(EXIT_FAILURE);
  }

  // Apply the process (at the moment use default value of 1 iteration)
  p_ImageProcessingManager->Process(1);

  // Safe Output Image to provided directory
  if(!path_dout.empty())
  {
    p_ImageSpace->WriteOutput(path_dout);
  }

  return 0;
}


