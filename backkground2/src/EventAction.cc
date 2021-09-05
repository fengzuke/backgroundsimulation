#include "G4Event.hh"
#include "G4RunManager.hh"
#include "Verbose.hh"

#include "RunAction.hh"
#include "EventAction.hh"

EventAction::EventAction(RunAction*)
    : G4UserEventAction()
{}


EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event *evt)
{

}

void EventAction::EndOfEventAction(const G4Event *evt)
{

}
