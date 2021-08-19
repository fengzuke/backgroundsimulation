#include "RunActionMessenger.hh"
#include "RunAction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4ios.hh"
#include "Randomize.hh"

RunActionMessenger::RunActionMessenger(RunAction* runact)
:	G4UImessenger(),
	runaction(runact)
{
	runDirectory = new G4UIdirectory("/RunAction/");
	runDirectory->SetGuidance("UI commands specific to this example.");
	DefineDataStoreFileNameCmd = new G4UIcmdWithAString("/RunAction/SetDataStoreFileName", this);
	DefineDataStoreFileNameCmd->SetGuidance("Define the data store file name.");
	DefineDataStoreFileNameCmd->SetParameterName("fileName", true);
	DefineDataStoreFileNameCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
}

RunActionMessenger::~RunActionMessenger()
{
	delete DefineDataStoreFileNameCmd;
	delete runDirectory;
}

void RunActionMessenger::SetNewValue(G4UIcommand* command, G4String newvalue)
{
	if ( command == DefineDataStoreFileNameCmd )
	{
		runaction->SetOutPutFileName(newvalue);
	}
}

