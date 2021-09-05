#include "g4root.hh"
#include "BeWindowSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "EventAction.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

BeWindowSD::BeWindowSD(G4String name) 
 : G4VSensitiveDetector(name)
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

BeWindowSD::~BeWindowSD() 
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void BeWindowSD::Initialize(G4HCofThisEvent* h)
{
Btheta=1000.;
BeEdep=0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool BeWindowSD::ProcessHits(G4Step* astep, G4TouchableHistory*)
{  
	double astepdEdx = 0.;
	G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
	G4Track* track = astep->GetTrack();
	int pdgID = track->GetDefinition()->GetPDGEncoding();
	int ParentID = track->GetParentID();
	int StepID = track->GetCurrentStepNumber();
	G4String thisVolume = track->GetVolume()->GetName();
	G4String Material = track->GetMaterial()->GetName();
	double length=astep->GetStepLength();
	G4ThreeVector momDir = track->GetMomentumDirection();
	astepdEdx = astep->GetTotalEnergyDeposit();
	double Ek = astep->GetPreStepPoint()->GetKineticEnergy();
	G4String Volume=astep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();
    BeEdep+=astepdEdx;
	if ( ParentID==0 && astepdEdx>0)
	{
	  Btheta=180/3.1415926*momDir*G4ThreeVector(0,0-1)/(sqrt(momDir*momDir)*sqrt(G4ThreeVector(0,0-1)*G4ThreeVector(0,0-1)));
	  G4cout<<"###############################"<<astepdEdx<<G4endl;
	}
    return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void BeWindowSD::EndOfEvent(G4HCofThisEvent* h)
{
G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
if (BeEdep >= 0.002 && BeEdep <= 0.01)
{
	analysismanager->FillNtupleDColumn(1,1,BeEdep);
	analysismanager->AddNtupleRow(1);
}

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
