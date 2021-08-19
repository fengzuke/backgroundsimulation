//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: GasSD.cc 87359 2014-12-01 16:04:27Z gcosmo $
//
/// \file GasSD.cc
/// \brief Implementation of the GasSD class

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
n=0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool GasSD::ProcessHits(G4Step* astep, G4TouchableHistory*)
{  
	G4AnalysisManager* analysismanager = G4AnalysisManager::Instance();
	G4Track* track = astep->GetTrack();
	int pdgID = track->GetDefinition()->GetPDGEncoding();
	int ParentID = track->GetParentID();
	int StepID = track->GetCurrentStepNumber();
	G4String thisVolume = track->GetVolume()->GetName();
	if ( thisVolume != "Gas" )
	{
		return false;
	}

    double edep = astep->GetTotalEnergyDeposit();
	double Ek = astep->GetPreStepPoint()->GetKineticEnergy();

  if ( ParentID==1 && astep->IsFirstStepInVolume() )
	{
	  n+=1;
      analysismanager->FillNtupleDColumn(0,Ek);
      analysismanager->FillNtupleDColumn(1,n);
	  analysismanager->AddNtupleRow();
	}

  if (edep==0.) return false;


  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GasSD::EndOfEvent(G4HCofThisEvent*)
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
