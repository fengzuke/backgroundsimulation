#ifndef GasSD_h
#define GasSD_h 1

#include "G4VSensitiveDetector.hh"
#include <vector>

class G4Step;
class G4HCofThisEvent;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/// Gas sensitive detector class
///
/// The hits are accounted in hits in ProcessHits() function which is called
/// by Geant4 kernel at each step. A hit is created with each step with non zero 
/// energy deposit.

class GasSD : public G4VSensitiveDetector
{
  public:
    GasSD(G4String);
    virtual ~GasSD();
  
    // methods from base class
    virtual void   Initialize(G4HCofThisEvent* hitCollection);
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
    virtual void   EndOfEvent(G4HCofThisEvent* hitCollection);

  private:
  int n;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
