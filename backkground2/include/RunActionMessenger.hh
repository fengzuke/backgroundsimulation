#ifndef RunActionMessenger_h
#define RunActionMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class G4UIdirectory;
class G4UIcmdWithAString;
class RunAction;

class RunActionMessenger : public G4UImessenger
{
	public:
		RunActionMessenger(RunAction*);
		~RunActionMessenger();
		virtual void SetNewValue(G4UIcommand*, G4String);
	private:
		G4UIcmdWithAString* DefineDataStoreFileNameCmd;
		RunAction* runaction;
		G4UIdirectory* runDirectory;
};

#endif
