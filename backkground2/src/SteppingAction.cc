#include "SteppingAction.hh"
#include "EventAction.hh"
#include "backgroundDetectorConstruction.hh"

#include "g4root.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* astep)
{
	G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
	G4Track* track = astep->GetTrack();
	int pdgID = track->GetDefinition()->GetPDGEncoding();
	int ParentID = track->GetParentID();
	int StepID = track->GetCurrentStepNumber();
	G4String thisVolume = track->GetVolume()->GetName();
	G4String Material = track->GetMaterial()->GetName();
	double length=astep->GetStepLength();
	double Ek = astep->GetPreStepPoint()->GetKineticEnergy();
	G4ThreeVector momDir = track->GetMomentumDirection();
	double astepdEdx = astep->GetTotalEnergyDeposit();
	G4String Volume=astep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();
	
	if(pdgID==0)
	{
		//G4cout<<"pdgid="<<pdgID<<G4endl;
		G4cout<<Volume<<" Material:"<<Material<<" Thickness:"<<length<<"mm"<<G4endl; 
	}
	//if ( ParentID==1 && astep->IsFirstStepInVolume() && Volume=="BeWindow")
	// if ( ParentID==0 && Volume=="BeWindow" && astepdEdx>0)
	// { 
    //   double theta=180/3.1415926*momDir*G4ThreeVector(0,0-1)/(sqrt(momDir*momDir)*sqrt(G4ThreeVector(0,0-1)*G4ThreeVector(0,0-1)));
    //   analysismanager->FillNtupleDColumn(1,1,theta);
	//   analysismanager->AddNtupleRow(1);
	// }
	// if ( ParentID==0 && Volume=="Gas" && astepdEdx>0)
	// {
	//   G4cout << "***************************************************************" << G4endl;
	//   double theta=180/3.1415926*momDir*G4ThreeVector(0,0-1)/(sqrt(momDir*momDir)*sqrt(G4ThreeVector(0,0-1)*G4ThreeVector(0,0-1)));
    //   analysismanager->FillNtupleDColumn(3,1,theta);
	//   analysismanager->AddNtupleRow(3);
	// }
	// if ( ParentID==1 && astep->IsFirstStepInVolume() && Volume=="Gas" )
	// {
	//   G4String GeneName = track->GetCreatorProcess()->GetProcessName();
	//   G4cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<thisVolume << G4endl;
	//   G4cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<GeneName << G4endl;
    //   analysismanager->FillNtupleDColumn(2,1,Ek);
	//   analysismanager->AddNtupleRow(2);
	// }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

