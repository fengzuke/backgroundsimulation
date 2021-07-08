// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME SimEvent
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/home/fzk/track/Simulation1.3/include/SimEvent.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_SimDeposit(void *p = 0);
   static void *newArray_SimDeposit(Long_t size, void *p);
   static void delete_SimDeposit(void *p);
   static void deleteArray_SimDeposit(void *p);
   static void destruct_SimDeposit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimDeposit*)
   {
      ::SimDeposit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SimDeposit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SimDeposit", ::SimDeposit::Class_Version(), "SimDeposit.h", 11,
                  typeid(::SimDeposit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SimDeposit::Dictionary, isa_proxy, 4,
                  sizeof(::SimDeposit) );
      instance.SetNew(&new_SimDeposit);
      instance.SetNewArray(&newArray_SimDeposit);
      instance.SetDelete(&delete_SimDeposit);
      instance.SetDeleteArray(&deleteArray_SimDeposit);
      instance.SetDestructor(&destruct_SimDeposit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimDeposit*)
   {
      return GenerateInitInstanceLocal((::SimDeposit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SimDeposit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SimTrack(void *p = 0);
   static void *newArray_SimTrack(Long_t size, void *p);
   static void delete_SimTrack(void *p);
   static void deleteArray_SimTrack(void *p);
   static void destruct_SimTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimTrack*)
   {
      ::SimTrack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SimTrack >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SimTrack", ::SimTrack::Class_Version(), "SimTrack.h", 14,
                  typeid(::SimTrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SimTrack::Dictionary, isa_proxy, 4,
                  sizeof(::SimTrack) );
      instance.SetNew(&new_SimTrack);
      instance.SetNewArray(&newArray_SimTrack);
      instance.SetDelete(&delete_SimTrack);
      instance.SetDeleteArray(&deleteArray_SimTrack);
      instance.SetDestructor(&destruct_SimTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimTrack*)
   {
      return GenerateInitInstanceLocal((::SimTrack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SimTrack*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SimEvent(void *p = 0);
   static void *newArray_SimEvent(Long_t size, void *p);
   static void delete_SimEvent(void *p);
   static void deleteArray_SimEvent(void *p);
   static void destruct_SimEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimEvent*)
   {
      ::SimEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SimEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SimEvent", ::SimEvent::Class_Version(), "", 56,
                  typeid(::SimEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SimEvent::Dictionary, isa_proxy, 4,
                  sizeof(::SimEvent) );
      instance.SetNew(&new_SimEvent);
      instance.SetNewArray(&newArray_SimEvent);
      instance.SetDelete(&delete_SimEvent);
      instance.SetDeleteArray(&deleteArray_SimEvent);
      instance.SetDestructor(&destruct_SimEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimEvent*)
   {
      return GenerateInitInstanceLocal((::SimEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SimEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr SimDeposit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimDeposit::Class_Name()
{
   return "SimDeposit";
}

//______________________________________________________________________________
const char *SimDeposit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimDeposit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimDeposit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimDeposit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimDeposit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimDeposit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimDeposit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimDeposit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SimTrack::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimTrack::Class_Name()
{
   return "SimTrack";
}

//______________________________________________________________________________
const char *SimTrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimTrack*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimTrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimTrack*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimTrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimTrack*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimTrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimTrack*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SimEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimEvent::Class_Name()
{
   return "SimEvent";
}

//______________________________________________________________________________
const char *SimEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SimEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SimEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void SimDeposit::Streamer(TBuffer &R__b)
{
   // Stream an object of class SimDeposit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SimDeposit::Class(),this);
   } else {
      R__b.WriteClassBuffer(SimDeposit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimDeposit(void *p) {
      return  p ? new(p) ::SimDeposit : new ::SimDeposit;
   }
   static void *newArray_SimDeposit(Long_t nElements, void *p) {
      return p ? new(p) ::SimDeposit[nElements] : new ::SimDeposit[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimDeposit(void *p) {
      delete ((::SimDeposit*)p);
   }
   static void deleteArray_SimDeposit(void *p) {
      delete [] ((::SimDeposit*)p);
   }
   static void destruct_SimDeposit(void *p) {
      typedef ::SimDeposit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SimDeposit

//______________________________________________________________________________
void SimTrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class SimTrack.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SimTrack::Class(),this);
   } else {
      R__b.WriteClassBuffer(SimTrack::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimTrack(void *p) {
      return  p ? new(p) ::SimTrack : new ::SimTrack;
   }
   static void *newArray_SimTrack(Long_t nElements, void *p) {
      return p ? new(p) ::SimTrack[nElements] : new ::SimTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimTrack(void *p) {
      delete ((::SimTrack*)p);
   }
   static void deleteArray_SimTrack(void *p) {
      delete [] ((::SimTrack*)p);
   }
   static void destruct_SimTrack(void *p) {
      typedef ::SimTrack current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SimTrack

//______________________________________________________________________________
void SimEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class SimEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SimEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(SimEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimEvent(void *p) {
      return  p ? new(p) ::SimEvent : new ::SimEvent;
   }
   static void *newArray_SimEvent(Long_t nElements, void *p) {
      return p ? new(p) ::SimEvent[nElements] : new ::SimEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimEvent(void *p) {
      delete ((::SimEvent*)p);
   }
   static void deleteArray_SimEvent(void *p) {
      delete [] ((::SimEvent*)p);
   }
   static void destruct_SimEvent(void *p) {
      typedef ::SimEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SimEvent

namespace {
  void TriggerDictionaryInitialization_SimEvent_Impl() {
    static const char* headers[] = {
"0",
0
    };
    static const char* includePaths[] = {
"/home/fzk/geant4/g4.10.03/geant4.10.03-install/include/Geant4",
"/usr/include/qt4",
"/usr/include/qt4/QtCore",
"/usr/include/qt4/QtGui",
"/usr/include/qt4/QtOpenGL",
"/home/fzk/track/Simulation1.3/include",
"/home/fzk/geant4/g4.10.03/geant4.10.03-install/include/Geant4",
"/home/fzk/root/root6-build/include",
"/home/fzk/root/root6-build/include/",
"/home/fzk/track/Simulation1.3/7.6/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SimEvent dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$SimDeposit.h")))  __attribute__((annotate("$clingAutoload$SimTrack.h")))  SimDeposit;
class __attribute__((annotate("$clingAutoload$SimTrack.h")))  SimTrack;
class SimEvent;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SimEvent dictionary payload"

#ifndef G4_STORE_TRAJECTORY
  #define G4_STORE_TRAJECTORY 1
#endif
#ifndef G4VERBOSE
  #define G4VERBOSE 1
#endif
#ifndef G4UI_USE
  #define G4UI_USE 1
#endif
#ifndef G4VIS_USE
  #define G4VIS_USE 1
#endif
#ifndef G4UI_USE_TCSH
  #define G4UI_USE_TCSH 1
#endif
#ifndef G4INTY_USE_XT
  #define G4INTY_USE_XT 1
#endif
#ifndef G4VIS_USE_RAYTRACERX
  #define G4VIS_USE_RAYTRACERX 1
#endif
#ifndef G4INTY_USE_QT
  #define G4INTY_USE_QT 1
#endif
#ifndef G4UI_USE_QT
  #define G4UI_USE_QT 1
#endif
#ifndef G4VIS_USE_OPENGLQT
  #define G4VIS_USE_OPENGLQT 1
#endif
#ifndef G4VIS_USE_OPENGLX
  #define G4VIS_USE_OPENGLX 1
#endif
#ifndef G4VIS_USE_OPENGL
  #define G4VIS_USE_OPENGL 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
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

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"SimDeposit", payloadCode, "@",
"SimEvent", payloadCode, "@",
"SimTrack", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SimEvent",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SimEvent_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SimEvent_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SimEvent() {
  TriggerDictionaryInitialization_SimEvent_Impl();
}
