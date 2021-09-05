#ifndef backgroundActionInitialization_h
#define backgroundActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class backgroundActionInitialization : public G4VUserActionInitialization
{
  public:
    backgroundActionInitialization();
    virtual ~backgroundActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
