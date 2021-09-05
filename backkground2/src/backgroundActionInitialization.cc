#include "backgroundActionInitialization.hh"
#include "backgroundPrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

backgroundActionInitialization::backgroundActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

backgroundActionInitialization::~backgroundActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void backgroundActionInitialization::BuildForMaster() const
{
  RunAction* runAction = new RunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void backgroundActionInitialization::Build() const
{
  SetUserAction(new backgroundPrimaryGeneratorAction);

  RunAction* runAction = new RunAction;
  SetUserAction(runAction);
  
  EventAction* eventAction = new EventAction(runAction);
  SetUserAction(eventAction);
 
  SteppingAction* steppingAction = new SteppingAction(eventAction);
  SetUserAction(steppingAction);
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
