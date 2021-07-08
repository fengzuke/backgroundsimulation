//*********************************************
//  This is auto generated by G4gen 0.6
//                                  author:Qian

#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "Verbose.hh"
#include "G4UIcmdWith3Vector.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "MyGunMessenger.hh"
#include "MyGunAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyGunMessenger::MyGunMessenger(MyGunAction *Gun)
    : G4UImessenger(),
      fAction(Gun)
{
    if (verbose)
        G4cout << "====>MyGunMessenger::MyGunMessenger(MyGunAction *Gun)" << G4endl;

    fGunDir = new G4UIdirectory("/MySimulation/gun/");
    fGunDir->SetGuidance("gun control");

    gunEngCmd = new G4UIcmdWithADoubleAndUnit("/MySimulation/gun/energy", this);
    gunEngCmd->SetGuidance("Set the particle energy");
    gunEngCmd->SetParameterName("Energy", true, true);
    gunEngCmd->SetDefaultUnit("keV");

    gunDirCmd = new G4UIcmdWith3Vector("/MySimulation/gun/direction", this);
    gunDirCmd->SetGuidance("Set particle direction.");
    gunDirCmd->SetParameterName("Vx", "Vy", "Vz", true, true);
    //gunDirCmd->SetRange("Vx>=-1.&&Vx<=1.&&Vy>=-1.&&Vy<=1.&&Vz>=-1.&&Vz<=1.");

    gunPosCmd = new G4UIcmdWith3VectorAndUnit("/MySimulation/gun/position", this);
    gunPosCmd->SetGuidance("Set starting position of the particle.");
    gunPosCmd->SetParameterName("X", "Y", "Z==0", true, true);
    gunPosCmd->SetDefaultUnit("mm");

    gunPolCmd = new G4UIcmdWith3Vector("/MySimulation/gun/polarization", this);
    gunPolCmd->SetGuidance("Set the polarization of the particle.");
    gunPolCmd->SetParameterName("Px", "Py", "Pz", true, true);
    gunPolCmd->SetRange("Pz==0.");

	gunPartPolarCmd = new G4UIcmdWithADouble("/MySimulation/gun/partpolarization", this);
    gunPartPolarCmd->SetGuidance("Set the Elliptical Partially polarized of all particle.");
    gunPartPolarCmd->SetParameterName("percentage", true, true);
    gunPartPolarCmd->SetRange("percentage <=1 && percentage >=0");

	gunGausSigmaCmd = new G4UIcmdWithADouble("/MySimulation/gun/gaussSigma", this);
    gunGausSigmaCmd->SetGuidance("set the angle of gaussian because of waggle satellite of all particle.");
    gunGausSigmaCmd->SetParameterName("Gsigma", true, true);
    gunGausSigmaCmd->SetRange("Gsigma >=0");

    fRootFileCmd = new G4UIcmdWithAString("/MySimulation/gun/setRootName", this);
    fRootFileCmd->SetGuidance("set name for the root file");

    fTxtFileCmd = new G4UIcmdWithAString("/MySimulation/gun/setTxtName", this);
    fTxtFileCmd->SetGuidance("set name for the txt file");

    fProgFileCmd = new G4UIcmdWithAString("/MySimulation/gun/setProgName", this);
    fProgFileCmd->SetGuidance("set name for the progress file");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyGunMessenger::~MyGunMessenger()
{
    delete gunEngCmd;
    delete gunDirCmd;
    delete gunPosCmd;
    delete gunPolCmd;
	delete gunPartPolarCmd;
	delete gunGausSigmaCmd;

    delete fRootFileCmd;
    delete fProgFileCmd;
    delete fTxtFileCmd;
    delete fGunDir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyGunMessenger::SetNewValue(G4UIcommand *command,
                                 G4String newValue)
{
    if (verbose)
        G4cout << "void MyGunMessenger::SetNewValue(G4UIcommand* command,G4String newValue)" << G4endl;

    if (command == gunEngCmd)
        fAction->SetGunEnergy(gunEngCmd->GetNewDoubleValue(newValue));
    if (command == gunDirCmd)
        fAction->SetGunDirection(gunDirCmd->GetNew3VectorValue(newValue));
    if (command == gunPosCmd)
        fAction->SetGunPosition(gunPosCmd->GetNew3VectorValue(newValue));
    if (command == gunPolCmd)
        fAction->SetGunPolarization(gunPolCmd->GetNew3VectorValue(newValue));    
	if (command == gunPartPolarCmd)
        fAction->SetGunEllipPolar(gunPartPolarCmd->GetNewDoubleValue(newValue));
	if (command == gunGausSigmaCmd)
        fAction->SetGunGaussSigma(gunGausSigmaCmd->GetNewDoubleValue(newValue));

    if (command == fRootFileCmd)
        fAction->SetRootFileName(newValue);
    if (command == fProgFileCmd)
        fAction->SetProgFileName(newValue);
    if (command == fTxtFileCmd)
        fAction->SetTxtFileName(newValue);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
