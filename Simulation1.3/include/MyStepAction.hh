//*********************************************
//  This is auto generated by G4gen 0.6
//                                  author:Qian

#ifndef MyStepAction_h
#define MyStepAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4LogicalVolume;

class MyStepAction : public G4UserSteppingAction
{
public:
  MyStepAction();
  virtual ~MyStepAction();

  virtual void UserSteppingAction(const G4Step *);
	//G4int theSumFromBe = 1;
	G4ThreeVector postPoint;

private:
	/*G4LogicalVolume* fAnticShieldVolume;
	G4LogicalVolume* fAnticShieldVolume2;
	G4LogicalVolume* fBeWindowsVolume;
	G4LogicalVolume* fGasVolume;*/
};

#endif
