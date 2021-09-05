#include "G4Run.hh"
#include "G4RunManager.hh"
#include "Verbose.hh"
#include "g4root.hh"
#include "RunActionMessenger.hh"

#include "GasSD.hh"
#include "BeWindowSD.hh"

#include "RunAction.hh"
#include "EventAction.hh"
#include "backgroundPrimaryGeneratorAction.hh"
#include "backgroundDetectorConstruction.hh"

RunAction::RunAction()
    : G4UserRunAction()
{
	runmessenger = new RunActionMessenger(this);
}

RunAction::~RunAction()
{
	delete runmessenger;
	delete G4AnalysisManager::Instance(); 
}

void RunAction::datastore()
{
	G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
	analysismanager->SetFirstH1Id(1);
	analysismanager->SetFirstH2Id(1);
	analysismanager->SetFirstH3Id(1);
	
	analysismanager->SetFirstNtupleId(1);
	analysismanager->SetFirstNtupleColumnId(1);
	
	analysismanager->CreateNtuple("BeWindow", "Ntuple");
	analysismanager->CreateNtupleDColumn("BeWindowEdep");
	analysismanager->FinishNtuple(1);
	
	analysismanager->CreateNtuple("Gas", "Ntuple");
	analysismanager->CreateNtupleDColumn("GasEdep");
	//analysismanager->CreateNtupleDColumn("theta");	
	analysismanager->FinishNtuple(2);

	analysismanager->CreateNtuple("gastheta", "Ntuple");
	analysismanager->CreateNtupleDColumn("theta");
	analysismanager->FinishNtuple(3);

	
}

void RunAction::BeginOfRunAction(const G4Run* arun)
{
	outputfilename="./data/result.root";
	G4cout << "Run " << arun->GetRunID() << " start." << G4endl;
	G4cout << "--------------------------------Run start----------------------------------" << G4endl;
	G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
	analysismanager->OpenFile(outputfilename);
	datastore();
}

void RunAction::EndOfRunAction(const G4Run* run)
{
	G4int numberofevents = run->GetNumberOfEvent();
	G4cout << "------------------End of run total number of events = " << numberofevents << G4endl;
	G4cout << "---------------------------------Run end-----------------------------------" << G4endl;
	G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
	G4cout << "\n====>In total " << analysismanager->GetNtuple(2)->entries() << " Events have been stored." << G4endl;
	analysismanager->Write();
	analysismanager->CloseFile();
// G4int numberofevents = run->GetNumberOfEvent();
// G4cout << "------------------End of run total number of events = " << numberofevents << G4endl;
// G4cout << "---------------------------------Run end-----------------------------------" << G4endl;
// G4cout << "------------------Total number of events has been stored= " << n << G4endl;
}

void RunAction::SetOutPutFileName(G4String newvalue)
{
	G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
	if ( outputfilename != newvalue )
	{
		analysismanager->OpenFile(newvalue);
	}
}
