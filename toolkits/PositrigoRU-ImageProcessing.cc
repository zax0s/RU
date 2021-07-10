/*!
  \file
  \ingroup utilities
  \brief  This program is used as an interface to the image processing functions of the PositrigoRU main program.
*/

#include <iostream>
using namespace std;

/*!
  \fn      ShowHelp()
  \brief   Display main command line options of image processing toolkit
*/
void ShowHelp()
{
  cout << endl;
  cout << "Usage:  PositrigoRU-ImageProcessing  -img input_image.hdr -out output_image.hdr -process operationID:processing_options " << endl;
  cout << endl;
  cout << "[Mandatory parameters]:" << endl;
  cout << "  -img input_image.hdr : Give an input image " << endl;
  cout << "  -dout name           : Give the directory where the output image/images will be written" << endl;
  cout << "  -process             : Give the name of the process to be applied on the input image" << endl;
  cout << "  -help-process        : Show the list and description of all implemented processing operations" << endl;
  cout << "  --help,-h,-help      : Print out this help page." << endl;
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
  // Output directory name.
  string path_dout = "";


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

    // --------------------------------------------------------------------------------
    // Input image
    // --------------------------------------------------------------------------------

    else if (option=="-img")
    {
      if (i>=argc-1)
      {
        cout << "***** PositrigoRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      path_to_image_filename = (string)argv[i+1];
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
        cout << "***** PositrigoRU-ImageProcessing() -> Argument missing for option: " << option << endl;
        exit(EXIT_FAILURE);
      }
      path_dout = argv[i+1];
      i++;
    }

    // --------------------------------------------------------------------------------
    // Unknown option!
    // --------------------------------------------------------------------------------
    else
    {
      cout << "***** PositrigoRU-ImageProcessing() -> Unknown option '" << option << "' !" << endl;
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}


