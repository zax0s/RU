/*!
  \file
  \ingroup main_program
  \brief  PositrigoRU: Command line interface for the Reconstruction Unit of the Positrigo Device \n
          It reads/parses/checks the command-line options, initialize classes with the correct set of input and options, launch and schedule reconstructions.
*/

#include <iostream>
using namespace std;

/*!
  \fn      ShowHelp()
  \brief   Display main command line options of RU program
*/
void ShowHelp()
{

  cout << endl;
  cout << "Usage:  PositrigoRU  -df file.data  -recon type -it iter  [settings]" << endl;
  cout << endl;
  cout << "[Mandatory parameters]:" << endl;
  cout << "  --help,-h,-help      : Print out this help page." << endl;

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

  //TODO: Develop all reconstruction related scheduling functions
  //      For example within an object named (SchedulingManager)

  //TODO: Develop the reconstruction platform. The platform can be called internally from the scheduler or using this
  //      command line interface. An input of the data file or files UID number need to be provided with the -df option
  //      followed by the reconstruction options and settings
  //      An image dimensions option needs to be provided within the input of "settings", which will initialise an image
  //      with these dimensions before the reconstruction. Alternatively an input image can be provided, as the initial
  //      image before reconstruction. An ImageSpace class will be used for storing all image related data.


  //TODO: Develop an ImageProcessingManager. This manager will manage the different image processing components and apply
  //      them on the requested image.
  //   -- An abstract/virtual image processing component will be defined, to describe the generic functions of a component.
  //   -- Specific image processing components will be then implemented as children classes.
  //   -- The ImageProcessingManager will create children classes that inherit from the virtual component,
  //        based on the requested image processing operation and its specific options.
  //   -- The ImageProcessingManager will then execute the processing operation and record the output of that into the
  //        ImageSpace class


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
    // Unknown option!
    // --------------------------------------------------------------------------------
    else
    {
      cout << "***** PositrigoRU() -> Unknown option '" << option << "' !" << endl;
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}
