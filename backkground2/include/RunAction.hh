#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4RunManager.hh"

class RunActionMessenger;

class RunAction : public G4UserRunAction
{
	public:
		RunAction();
		~RunAction();
		void BeginOfRunAction(const G4Run*);
		void EndOfRunAction(const G4Run*);
		void SetOutPutFileName(G4String );
	private:
		void datastore();
		G4String outputfilename;
		RunActionMessenger* runmessenger;
		int number;
};

#endif
