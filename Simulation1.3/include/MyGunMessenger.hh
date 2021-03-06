//*********************************************
//  This is auto generated by G4gen 0.6
//                                  author:Qian

#ifndef MyGunMessenger_h
#define MyGunMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class G4UIdirectory;
class G4UIcmdWithoutParameter;
class G4UIcmdWithADouble;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class MyGunAction;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3Vector;
class G4UIcmdWith3VectorAndUnit;


//-------------------------------
// MyGunMessenger class that defines commands for MyGunAction.
class MyGunMessenger : public G4UImessenger
{
  public:
    MyGunMessenger(MyGunAction *);
    ~MyGunMessenger();

    virtual void SetNewValue(G4UIcommand *, G4String);

  private:
    MyGunAction *fAction;

    G4UIdirectory *fGunDir;

	G4UIcmdWithADoubleAndUnit* gunEngCmd;
	G4UIcmdWith3Vector* gunDirCmd;
	G4UIcmdWith3Vector* gunPolCmd;
	G4UIcmdWith3VectorAndUnit* gunPosCmd;
	G4UIcmdWithADouble* gunPartPolarCmd;
	G4UIcmdWithADouble* gunGausSigmaCmd;

  G4UIcmdWithAString* fRootFileCmd;
  G4UIcmdWithAString* fTxtFileCmd;
  G4UIcmdWithAString* fProgFileCmd; 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
