/*!
  \file
  \ingroup  dynamic
  \brief    Implementation of class vImageProcess
*/

#include "../include/vImageProcess.hh"

/*
  \fn vImageProcess
  \brief Constructor of vImageProcess. Simply set all data members to default values.
*/
vImageProcess::vImageProcess()
{
  mp_ImageSpace=NULL;
  m_repetations=-1;
  process_parameters="";
}
vImageProcess::~vImageProcess(){ }

// =====================================================================
// Show generic help
// =====================================================================
/*
  \fn ShowHelp
  \brief Print out general help about image processes
*/
void vImageProcess::ShowHelp()
{
  // Nothing to show at the moment that is generic to all processes
  cout << "   The following input options are common to all image processes: to be defined ...." << endl;
}

// =====================================================================
// Initialise
// =====================================================================

/*
  \fn      vImageProcess::Initialize()
  \brief   A public function used to initialize the image process
  \return  An integer reflecting the initialization status; 0 if no problem, another value otherwise.
*/
int vImageProcess::Initialize()
{
  //TODO: To change that and use user input

  // By default we initialise the number of repetitions to apply the process to 1;
  m_repetations=1;
return 0;

}

