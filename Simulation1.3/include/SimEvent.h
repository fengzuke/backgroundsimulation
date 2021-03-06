//*********************************************
//  This is auto generated by G4gen 0.6
//                                  author:Qian

#ifndef SimEvent_h
#define SimEvent_h

#include "TVector3.h"
#include "TObject.h"
#include "TMap.h"
#include "TObjString.h"
#include "Verbose.hh"
#include <map>

#include "SimTrack.h"
#include "SimDeposit.h"

class SimEvent : public TObject
{

public:
  SimEvent() { MyClear(); }
  virtual ~SimEvent() {}

  void SetPDGID(int pdgId) { fPDGID = pdgId; }
  void SetTrueEnergy(double energy) { fEnergy0 = energy; }
  void SetMomentumX(double px) { fPx0 = px; }
  void SetMomentumY(double py) { fPy0 = py; }
  void SetMomentumZ(double pz) { fPz0 = pz; }
	void SetPhoelecMomentumX(double px) {pepx = px;}
	void SetPhoelecMomentumY(double py) {pepy = py;}
	void SetPhoelecMomentumZ(double pz) {pepz = pz;}
        void SetPEPositionX(double posx) {position_x = posx;}
        void SetPEPositionY(double posy) {position_y = posy;}
        void SetPEPositionZ(double posz) {position_z = posz;}
	void SetEventGasEnergy(double anaVal) {IEnergy += anaVal;}
	void SetEventCoincidence1Energy(double anaVal) {CoinEnergy1 += anaVal;}
	void SetEventCoincidence2Energy(double anaVal) {CoinEnergy2 += anaVal;}
	void SetEventBeWindowsEnergy(double Val) {BeWindowsEnergy += Val;}
	void SetStepLength(double Val) {StepLength += Val;}
	void SetNumCrossBe(int Val)  {NumCrossBe +=Val;}
	void SetGaussCheck(double val) {GaussCheck = val;}
	//void SetSaveZ(double Val) {positionZ = Val;}
	void SetNewPolarizationX (double val) {fNpolax = val;}
	void SetNewPolarizationY (double val) {fNpolay = val;}
  int GetPDGID() { return fPDGID; }
  double GetTrueEnergy() { return fEnergy0; }
	double GetEventGasEnergy() {return IEnergy;}
	double GetEventBeWindowsEnergy() {return BeWindowsEnergy;}
	double GetNumCrossBe() {return NumCrossBe;}
	double GetStepLength()  {return StepLength;}
	//double GetSaveZ()  {return positionZ;}
  TVector3 GetMomentumDir() { return TVector3(fPx0, fPy0, fPz0); }
  TVector3 GetPEDirection() { return TVector3(pepx, pepy, pepz); }
  TVector3 GetPEPosition() { return TVector3(position_x, position_y, position_z); }

public:
  inline void MyClear();
  inline void MyMapClear(TMap *);

//$DataIncGlobalFunc$

  // SD Functions
  //________________________________
  // for WindowSD SD
  void AddWindowSDDeposit(Int_t tID, SimDeposit *aDep)
  {
    SimTrack *aTrack = GetWindowSDTrack(tID);

    Int_t Ndep = fWindowSDDeposits->GetSize();
    fWindowSDDeposits->Add(new TObjString(Form("%d",Ndep)), aDep);

    aTrack->addDeposit(Ndep, aDep);
  }

  SimTrack* GetWindowSDTrack(Int_t tID)
  {
    SimTrack* aTrack = (SimTrack *)fWindowSDTracks->GetValue(Form("%d",tID));

    if(aTrack==0) {
      aTrack = new SimTrack();
      aTrack->SetTrackID( tID );
      fWindowSDTracks->Add(new TObjString(Form("%d",tID)), aTrack);
    }
    return aTrack;
  }

  SimDeposit* GetWindowSDDeposit(Int_t tID)
  {
    SimDeposit* aDeposit = (SimDeposit *)fWindowSDDeposits->GetValue(Form("%d", tID));
    return aDeposit;
  }

  TMap *GetWindowSDTrackMap() {return fWindowSDTracks;}
  TMap *GetWindowSDDepositMap() {return fWindowSDDeposits;}
  
  //________________________________
  // for GasSD SD
  void AddGasSDDeposit(Int_t tID, SimDeposit *aDep)
  {
    SimTrack *aTrack = GetGasSDTrack(tID);

    Int_t Ndep = fGasSDDeposits->GetSize();
    fGasSDDeposits->Add(new TObjString(Form("%d",Ndep)), aDep);

    aTrack->addDeposit(Ndep, aDep);
  }

  SimTrack* GetGasSDTrack(Int_t tID)
  {
    SimTrack* aTrack = (SimTrack *)fGasSDTracks->GetValue(Form("%d",tID));

    if(aTrack==0) {
      aTrack = new SimTrack();
      aTrack->SetTrackID( tID );
      fGasSDTracks->Add(new TObjString(Form("%d",tID)), aTrack);
    }
    return aTrack;
  }

  SimDeposit* GetGasSDDeposit(Int_t tID)
  {
    SimDeposit* aDeposit = (SimDeposit *)fGasSDDeposits->GetValue(Form("%d", tID));
    return aDeposit;
  }

  TMap *GetGasSDTrackMap() {return fGasSDTracks;}
  TMap *GetGasSDDepositMap() {return fGasSDDeposits;}
  
 

private:
  // global variables
  int fPDGID;
  double fEnergy0;
  double fPx0;
  double fPy0;
  double fPz0;
	double pepx;
	double pepy;
	double pepz;
        double position_x, position_y, position_z;
	double IEnergy;
	double CoinEnergy1;
	double CoinEnergy2;
	double BeWindowsEnergy;
	double StepLength;
	double NumCrossBe;
	double fNpolax;
	double fNpolay;
	double GaussCheck;
	//double positionZ;

  //...... need to be added, one for one event
  
//$DataIncGlobalDef$

  // SD variables
  TMap *fWindowSDTracks = NULL;
  TMap *fWindowSDDeposits = NULL;

  TMap *fGasSDTracks = NULL;
  TMap *fGasSDDeposits = NULL;





  ClassDef(SimEvent, 1)
};

inline void SimEvent::MyClear()
{
  fPDGID = -999;
  fEnergy0 = 0.;
  fPx0 = 0.;
  fPy0 = 0.;
  fPz0 = 0.;
	pepx = 0.;
	pepy = 0.;
	pepz = 0.;
        position_x = 0.;position_y = 0.;position_z = 0.;
	IEnergy = 0;
	CoinEnergy1 = 0.;
	CoinEnergy2 = 0.;
	BeWindowsEnergy = 0.;
	StepLength = 0.;
	NumCrossBe = 0.;
	fNpolax = -1;
	fNpolay = -1;
	GaussCheck = -999;
	//positionZ = 0.;

  if(fWindowSDTracks == NULL)
    fWindowSDTracks = new TMap();
  else
    MyMapClear(fWindowSDTracks);

  if(fWindowSDDeposits == NULL)
    fWindowSDDeposits = new TMap();
  else
    MyMapClear(fWindowSDDeposits);

  if(fGasSDTracks == NULL)
    fGasSDTracks = new TMap();
  else
    MyMapClear(fGasSDTracks);

  if(fGasSDDeposits == NULL)
    fGasSDDeposits = new TMap();
  else
    MyMapClear(fGasSDDeposits);


}

inline void SimEvent::MyMapClear(TMap *mp)
{
  TIterator *it = mp->MakeIterator();
  TObject* tempObj=0;
  while((tempObj = it->Next()))
  {
    TObjString *obj = dynamic_cast<TObjString *>(tempObj);
    SimTrack* trk = dynamic_cast<SimTrack *>(mp->GetValue(obj));
    SimDeposit* dep = dynamic_cast<SimDeposit *>(mp->GetValue(obj));
    if(trk!=NULL) delete trk;
    if(dep!=NULL) delete dep;
  }    
  mp->Clear();
}
#endif
