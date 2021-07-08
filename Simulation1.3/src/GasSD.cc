//*********************************************
//  This is auto generated by G4gen 0.6
//                                  author:Qian


#include "GasSD.hh"
#include "GasHit.hh"
#include "SimEvent.h"
#include "SimTrack.h"
#include "MyAnalysisManager.hh"

#include "G4TouchableHistory.hh"
#include "G4HCofThisEvent.hh"
#include "G4SystemOfUnits.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ios.hh"
#include "G4LossTableManager.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "Verbose.hh"
#include "g4root.hh"

GasSD::GasSD(G4String name) : G4VSensitiveDetector(name)
{
  if (verbose)
    G4cout << "====>GasSD::GasSD(G4String name)" << G4endl;

  collectionName.insert("GasSDCollection");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GasSD::~GasSD()
{
	if (verbose)
    G4cout << "====>GasSD::~GasSD(G4String name)" << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GasSD::Initialize(G4HCofThisEvent *)
{
  if (verbose)
    G4cout << "====>GasSD::Initialize(G4HCofThisEvent *)" << G4endl;

  fHitsCollection = new GasHitCollection(SensitiveDetectorName, collectionName[0]);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

G4bool GasSD::ProcessHits(G4Step *aStep, G4TouchableHistory *)
{
  
  if (verbose)
    G4cout << "====>GasSD::ProcessHits(G4Step *aStep, G4TouchableHistory *)" << G4endl;

  G4double dE       = aStep->GetTotalEnergyDeposit();
  G4double stepl    = aStep->GetStepLength();
  G4bool isFirstDep = aStep->IsFirstStepInVolume();
  //G4double edelta = aStep->GetDeltaEnergy();
  //G4double eNonIoniz = aStep->GetNonIonizingEnergyDeposit();

  G4StepPoint *preStepPoint  = aStep->GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
  G4ThreeVector prePos  = preStepPoint->GetPosition();
  G4ThreeVector postPos = postStepPoint->GetPosition();

  G4Track *aTrack = aStep->GetTrack();
  G4int trackID   = aTrack->GetTrackID();
  G4int prodID    = aTrack->GetParentID();
  G4int pdgID     = aTrack->GetDefinition()->GetPDGEncoding();
  G4int StepNo    = aTrack->GetCurrentStepNumber();
  G4ParticleDefinition *particleType = aTrack->GetDefinition();

	if ((dE == 0 || stepl == 0 )&& StepNo != 1)
		return false;
		
	//G4double cTrackLength = aTrack->GetTrackLength();
	//G4cout<<"...... "<<cTrackLength<<" "<<stepl<<G4endl;
  if (particleType == G4Gamma::Gamma() && dE > 0)
  {
    // usually dE is 0 for gammas, for the last step of a gamma track,
    // if dE > 0., it is the last step of the gamma track (no new particle is generated),
    // then treat this dE as a 'virtual' electron
    G4LossTableManager *manager = G4LossTableManager::Instance();
    stepl = manager->GetRange(G4Electron::Electron(), dE, aTrack->GetMaterialCutsCouple());
	//akaakaaka = akaakaaka+1;
	//G4cout<<"!!!!!!!!!!  "<<akaakaaka<<G4endl;
  }


  //------------------------------
  // save hits to the collection
  // so we can save the hits later
  SDHit = new GasHit(aStep);
  fHitsCollection->insert(SDHit);

  //------------------------------
  // save tracks to the collection
  // if the step is the first step of a track
  if (StepNo == 1)
  {
    aStep->SetFirstStepFlag();

    G4ThreeVector momDir = preStepPoint->GetMomentumDirection();
    G4double Ek = preStepPoint->GetKineticEnergy();

    SimTrack *aSimTrack = MyAnalysisManager::GetInstance()->GetSimEvent()->GetGasSDTrack(trackID);
    aSimTrack->SetPDGID(pdgID);
    aSimTrack->SetInitPx(momDir.x());
    aSimTrack->SetInitPy(momDir.y());
    aSimTrack->SetInitPz(momDir.z());
    aSimTrack->SetInitEk(Ek);
    aSimTrack->SetInitX(prePos.x());
    aSimTrack->SetInitY(prePos.y());
    aSimTrack->SetInitZ(prePos.z());
    //aSimTrack->SetInitT(preStepPoint->GetLocalTime());    //Time since the track was created
    aSimTrack->SetInitT(preStepPoint->GetGlobalTime()); //Time since the event in which the track belongs was created
    //aSimTrack->SetInitT(preStepPoint->GetProperTime()); //Proper time in the rest frame of the particle
  }

  //------------------------------
  // Last step of the track
  if (postStepPoint->GetKineticEnergy() == 0.)
  {
    G4ThreeVector momDir = postStepPoint->GetMomentumDirection();

    SimTrack *aSimTrack = MyAnalysisManager::GetInstance()->GetSimEvent()->GetGasSDTrack(trackID);
    aSimTrack->SetExitPx(momDir.x());
    aSimTrack->SetExitPy(momDir.y());
    aSimTrack->SetExitPz(momDir.z());
    aSimTrack->SetExitX(postPos.x());
    aSimTrack->SetExitY(postPos.y());
    aSimTrack->SetExitZ(postPos.z());
    //aSimTrack->SetExitT(postStepPoint->GetLocalTime());
    aSimTrack->SetExitT(postStepPoint->GetGlobalTime());
    //aSimTrack->SetExitT(postStepPoint->GetProperTime());
  }

  //------------------------------
  // Save the hit to the deposit
  aDep = new SimDeposit();
  aDep->SetPreX(prePos.x());
  aDep->SetPreY(prePos.y());
  aDep->SetPreZ(prePos.z());
  aDep->SetPreT(preStepPoint->GetGlobalTime());
  aDep->SetPostX(postPos.x());
  aDep->SetPostY(postPos.y());
  aDep->SetPostZ(postPos.z());
  aDep->SetPostT(postStepPoint->GetGlobalTime());
  aDep->SetStepLength(stepl);
  aDep->SetEdep(dE);
  aDep->SetTrackID(trackID);
  aDep->SetPDGID(pdgID);
  aDep->SetProducerID(prodID);
  aDep->SetFirstDeposit( isFirstDep );

	G4ThreeVector trackSavePosZ = aTrack->GetVertexPosition();
	//fEvent->SetSaveZ(trackSavePosZ.z());
  // add the MC deposit into the SimEvent
  SimEvent *fEvent = MyAnalysisManager::GetInstance()->GetSimEvent();
  fEvent->SetEventGasEnergy(dE);
  fEvent->SetStepLength(stepl);
  fEvent->AddGasSDDeposit( trackID, aDep );

  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
void GasSD::EndOfEvent(G4HCofThisEvent *HCE)
{
	if (verbose)
		G4cout << "====>GasSD::EndOfEvent(G4HCofThisEvent *HCE)" << G4endl;

  static G4int HCID = -1;
	if (HCID < 0)
		HCID = GetCollectionID(0);
	HCE->AddHitsCollection(HCID, fHitsCollection);
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GasSD::clear()
{
	delete aDep;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GasSD::DrawAll()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GasSD::PrintAll()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
