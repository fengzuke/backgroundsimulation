#include "g4root.hh"
#include "GasSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "EventAction.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GasSD::GasSD(G4String name) 
 : G4VSensitiveDetector(name)
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GasSD::~GasSD() 
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GasSD::Initialize(G4HCofThisEvent* hce)
{
theta=1000;
Edep=0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool GasSD::ProcessHits(G4Step* astep, G4TouchableHistory*)
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
	double edep = astep->GetTotalEnergyDeposit();
	double Ek = astep->GetPreStepPoint()->GetKineticEnergy();
	G4String Volume=astep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();
	G4ThreeVector position = astep->GetPreStepPoint()->GetPosition();
    Edep+=astepdEdx;
	if ( ParentID==0 && Volume=="GasSD" && astepdEdx>0  )
	{
	  theta=180/3.1415926*momDir*G4ThreeVector(0,0-1)/(sqrt(momDir*momDir)*sqrt(G4ThreeVector(0,0-1)*G4ThreeVector(0,0-1)));
	  G4cout<<"######################"<<position<<G4endl;
	}
  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GasSD::EndOfEvent(G4HCofThisEvent* hce)
{
G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
if (theta!=1000)
{

	analysismanager->FillNtupleDColumn(3,1,theta);
	analysismanager->AddNtupleRow(3);
}
if (Edep>=0.002 && Edep<=0.01)
{
	analysismanager->FillNtupleDColumn(2,1,Edep);
	analysismanager->AddNtupleRow(2);
}

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
