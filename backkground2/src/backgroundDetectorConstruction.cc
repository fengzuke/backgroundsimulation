#include "backgroundDetectorConstruction.hh"
#include "G4Material.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

#include "G4SDManager.hh"
#include "GasSD.hh"
#include "BeWindowSD.hh"

#include "G4PhysicalConstants.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

backgroundDetectorConstruction::backgroundDetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ 
DefineMaterials();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

backgroundDetectorConstruction::~backgroundDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* backgroundDetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  G4Material* Ne_50_DME_50   = nist->FindOrBuildMaterial("Ne_50_DME_50");
  G4Material* ceramics   = nist->FindOrBuildMaterial("ceramics");
  G4Material* Kovar   = nist->FindOrBuildMaterial("Kovar");
  G4Material* G4_Be = nist->FindOrBuildMaterial("G4_Be");
  G4Material* SSteel = nist->FindOrBuildMaterial("SSteel");
  G4Material* Scintillator = nist->FindOrBuildMaterial("Scintillator");
  G4Material* Aluminium = nist->FindOrBuildMaterial("Aluminium");
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;
  //     
  // World
  //  
  G4double world_sizeXYZ = 8000 * mm;
  G4Material* G4_Galactic = nist->FindOrBuildMaterial("G4_Galactic");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        G4_Galactic,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
  //     
  // Detector
  //
  G4double detector_sizeX = 40 * mm;
  G4double detector_sizeY = 40 * mm;
  G4double detector_sizeZ = 21 * mm;

  G4Box* solidDetector =    
    new G4Box("Detector",                       //its name
       0.5*detector_sizeX, 0.5*detector_sizeY, 0.5*detector_sizeZ);     //its size
      
  G4LogicalVolume* logicDetector =                         
    new G4LogicalVolume(solidDetector,       //its solid
                        G4_Galactic,         //its material
                        "Detector");         //its name
                                   
  G4VPhysicalVolume* physDetector = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(0,0,0),       //at (0,0,0)
                      logicDetector,         //its logical volume
                      "Detector",            //its name
                      logicWorld,            //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking

  //     
  // Detector2
  //


    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(44,0,0),       //at (0,0,0)
                      logicDetector,         //its logical volume
                      "Detector",            //its name
                      logicWorld,            //its mother  volume
                      false,                 //no boolean operation
                      1,                     //copy number
                      checkOverlaps);        //overlaps checking


  //     
  // Scintillator1
  //
  G4double Scintillator1_sizeX = 46 * mm;
  G4double Scintillator1_sizeY = 84 * mm;
  G4double Scintillator1_sizeZ = 15 * mm;

  G4Box* solidScintillator1 =    
  new G4Box("Scintillator1",                       //its name
       0.5*Scintillator1_sizeX, 0.5*Scintillator1_sizeY, 0.5*Scintillator1_sizeZ);     //its size

  //G4Tubs* solidScintillator1 = new G4Tubs("Scintillator1",0.,Scintillator1_sizeR,0.5*Scintillator1_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicScintillator1 =                         
    new G4LogicalVolume(solidScintillator1,            //its solid
                        Scintillator,        //its material
                        "logicScintillator1");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(-1,0,37.6),         //at (0,0,0)
                    logicScintillator1,                //its logical volume
                    "Scintillator1",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //     
  // Scintillator1_copy
  //
  G4RotationMatrix* rm = new G4RotationMatrix();
 rm->rotateZ(180*deg);  
  new G4PVPlacement(rm,                       //no rotation
                    G4ThreeVector(45,0,37.6),         //at (0,0,0)
                    logicScintillator1,                //its logical volume
                    "Scintillator1",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    1,                       //copy number
                    checkOverlaps);          //overlaps checking

  //     
  // Scintillator1_hole
  //
  G4double Scintillator1_hole_sizeR = 5 * mm;
  G4double Scintillator1_hole_sizeH = 15 * mm;

  G4Tubs* solidScintillator1_hole = new G4Tubs("Scintillator1_hole",0.,Scintillator1_hole_sizeR,0.5*Scintillator1_hole_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicScintillator1_hole =                         
    new G4LogicalVolume(solidScintillator1_hole,            //its solid
                        G4_Galactic,        //its material
                        "logicScintillator1_hole");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(1,0,0),         //at (0,0,0)
                    logicScintillator1_hole,                //its logical volume
                    "Scintillator1_hole",                   //its name
                    logicScintillator1,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  //     
  // Scintillator2
  //
  G4double Scintillator2_sizeX = 46 * mm;
  G4double Scintillator2_sizeY = 84 * mm;
  G4double Scintillator2_sizeZ = 15 * mm;

  G4Box* solidScintillator2 =    
  new G4Box("Scintillator2",                       //its name
       0.5*Scintillator2_sizeX, 0.5*Scintillator2_sizeY, 0.5*Scintillator2_sizeZ);     //its size

  //G4Tubs* solidScintillator2 = new G4Tubs("Scintillator2",0.,Scintillator2_sizeR,0.5*Scintillator2_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicScintillator2 =                         
    new G4LogicalVolume(solidScintillator2,            //its solid
                        Scintillator,        //its material
                        "logicScintillator2");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(-1,0,22.6),         //at (0,0,0)
                    logicScintillator2,                //its logical volume
                    "Scintillator2",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //     
  // Scintillator2_copy
  //
               
  new G4PVPlacement(rm,                       //no rotation
                    G4ThreeVector(45,0,22.6),         //at (0,0,0)
                    logicScintillator2,                //its logical volume
                    "Scintillator2",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    1,                       //copy number
                    checkOverlaps);          //overlaps checking

  //     
  // Scintillator2_hole
  //
  G4double Scintillator2_hole_sizeR = 5 * mm;
  G4double Scintillator2_hole_sizeH = 15 * mm;

  G4Tubs* solidScintillator2_hole = new G4Tubs("Scintillator2_hole",0.,Scintillator2_hole_sizeR,0.5*Scintillator2_hole_sizeH,0.*deg,360.*deg);

  //G4Tubs* solidScintillator2_hole = new G4Tubs("Scintillator2_hole",0.,Scintillator2_hole_sizeR,0.5*Scintillator2_hole_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicScintillator2_hole =                         
    new G4LogicalVolume(solidScintillator2_hole,            //its solid
                        G4_Galactic,        //its material
                        "logicScintillator2_hole");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(1,0,0),         //at (0,0,0)
                    logicScintillator2_hole,                //its logical volume
                    "Scintillator2_hole",                   //its name
                    logicScintillator2,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  


  //     
  // Top_SSteel
  //
  G4double Kovar_holeR = 5 * mm;
  G4double Kovar_sizeR = 19 * mm;
  G4double Kovar_sizeH = 3.1 * mm;

  G4Tubs* solidKovar = new G4Tubs("Kovar",Kovar_holeR,Kovar_sizeR,0.5*Kovar_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicKovar =                         
    new G4LogicalVolume(solidKovar,            //its solid
                        SSteel,        //its material
                        "Kovar");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(0,0,8.55 * mm),         //at (0,0,0)
                    logicKovar,                //its logical volume
                    "Kovar",                   //its name
                    logicDetector,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  // BeWindow
  //
  G4double BeWindow_sizeR = 5 * mm;
  G4double BeWindow_sizeH = 0.05 * mm;

  G4Tubs* solidBeWindow = new G4Tubs("BeWindow",0.,BeWindow_sizeR,0.5*BeWindow_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicBeWindow =                         
    new G4LogicalVolume(solidBeWindow,            //its solid
                        G4_Be,        //its material
                        "logicBeWindow");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(0,0,7.025),         //at (0,0,0)
                    logicBeWindow,                //its logical volume
                    "BeWindow",                   //its name
                    logicDetector,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
  //     
  // Ceramics
  //
  G4double Ceramics_sizeR = 15.25 * mm;
  G4double Ceramics_sizeH = 14 * mm;

  G4Tubs* solidCeramics = new G4Tubs("Ceramics",0.,Ceramics_sizeR,0.5*Ceramics_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicCeramics =                         
    new G4LogicalVolume(solidCeramics,            //its solid
                        ceramics,        //its material
                        "Ceramics");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicCeramics,                //its logical volume
                    "Ceramics",                   //its name
                    logicDetector,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                     

  //     
  // Gas
  //
  G4double Gas_sizeR = 13.75 * mm;
  G4double Gas_sizeH = 14 * mm;

  G4Tubs* solidGas = new G4Tubs("Gas",0.,Gas_sizeR,0.5*Gas_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicGas =                         
    new G4LogicalVolume(solidGas,            //its solid
                        Ne_50_DME_50,        //its material
                        "logicGas");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicGas,                //its logical volume
                    "Gas",                   //its name
                    logicCeramics,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //     
  // GasSD
  //
  G4double GasSD_sizeXY = 6 * mm;
  G4double GasSD_sizeZ = 14 * mm;

  G4Box* solidGasSD =    
  new G4Box("GasSD",                       //its name
       0.5*GasSD_sizeXY, 0.5*GasSD_sizeXY, 0.5*GasSD_sizeZ);     //its size

  //G4Tubs* solidGasSD = new G4Tubs("GasSD",0.,GasSD_sizeR,0.5*GasSD_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicGasSD =                         
    new G4LogicalVolume(solidGasSD,            //its solid
                        Ne_50_DME_50,        //its material
                        "logicGasSD");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicGasSD,                //its logical volume
                    "GasSD",                   //its name
                    logicGas,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  // //     
  // // TopHole
  // //
  // G4double KovarHole_sizeR = 5 * mm;
  // G4double KovarHole_sizeH = 3.1 * mm;

  // G4Tubs* solidKovarHole = new G4Tubs("KovarHole",0.,KovarHole_sizeR,0.5*KovarHole_sizeH,0.*deg,360.*deg);
      
  // G4LogicalVolume* logicKovarHole =                         
  //   new G4LogicalVolume(solidKovarHole,            //its solid
  //                       G4_Galactic,        //its material
  //                       "KovarHole");              //its name
               
  // new G4PVPlacement(0,                       //no rotation
  //                   G4ThreeVector(0,0,0),         //at (0,0,0)
  //                   logicKovarHole,                //its logical volume
  //                   "KovarHole",                   //its name
  //                   logicKovar,           //its mother  volume
  //                   false,                   //no boolean operation
  //                   0,                       //copy number
  //                   checkOverlaps);          //overlaps checking
  //     


  // //     
  // // KovarCollimation
  // //
  // G4double KovarCollimation_sizeR = 6 * mm;
  // G4double KovarCollimation_sizeH = 15.32 * mm;

  // G4Tubs* solidKovarCollimation = new G4Tubs("KovarCollimation",0.,KovarCollimation_sizeR,0.5*KovarCollimation_sizeH,0.*deg,360.*deg);
      
  // G4LogicalVolume* logicKovarCollimation =                         
  //   new G4LogicalVolume(solidKovarCollimation,            //its solid
  //                       Kovar,        //its material
  //                       "KovarCollimation");              //its name
               
  // new G4PVPlacement(0,                       //no rotation
  //                   G4ThreeVector(0,0,14.66),         //at (0,0,14.66)
  //                   logicKovarCollimation,                //its logical volume
  //                   "KovarCollimation",                   //its name
  //                   logicDetector,           //its mother  volume
  //                   false,                   //no boolean operation
  //                   0,                       //copy number
  //                   checkOverlaps);          //overlaps checking
  // //     
  // // Collimation
  // //
  // G4double Collimation_sizeR = 5 * mm;
  // G4double Collimation_sizeH = 15.32* mm;

  // G4Tubs* solidCollimation = new G4Tubs("Collimation",0.,Collimation_sizeR,0.5*Collimation_sizeH,0.*deg,360.*deg);
      
  // G4LogicalVolume* logicCollimation =                         
  //   new G4LogicalVolume(solidCollimation,            //its solid
  //                       G4_Galactic,        //its material
  //                       "Collimation");              //its name
               
  // new G4PVPlacement(0,                       //no rotation
  //                   G4ThreeVector(0,0,0),         //at (0,0,0)
  //                   logicCollimation,                //its logical volume
  //                   "Collimation",                   //its name
  //                   logicKovarCollimation,           //its mother  volume
  //                   false,                   //no boolean operation
  //                   0,                       //copy number
  //                   checkOverlaps);          //overlaps checking
  

  //     
  // Bottom Kovar2
  //
  G4double Kovar2_sizeR = 20 * mm;
  G4double Kovar2_sizeH = 3 * mm;

  G4Tubs* solidKovar2 = new G4Tubs("Kovar2",0.,Kovar2_sizeR,0.5*Kovar2_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicKovar2 =                         
    new G4LogicalVolume(solidKovar2,            //its solid
                        Kovar,        //its material
                        "Kovar2");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(0,0,-8.5 * mm),         //at (0,0,0)
                    logicKovar2,                //its logical volume
                    "Kovar2",                   //its name
                    logicDetector,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  //     
  // shield1
  //
  G4double shield1_sizeX = 4 * mm;
  G4double shield1_sizeY = 84 * mm;
  G4double shield1_sizeZ = 50 * mm;

  G4Box* solidshield1 =    
  new G4Box("shield1",                       //its name
       0.5*shield1_sizeX, 0.5*shield1_sizeY, 0.5*shield1_sizeZ);     //its size

  //G4Tubs* solidshield1 = new G4Tubs("shield1",0.,shield1_sizeR,0.5*shield1_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicshield1 =                         
    new G4LogicalVolume(solidshield1,            //its solid
                        Aluminium,        //its material
                        "logicshield1");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(-26,0,10),         //at (0,0,0)
                    logicshield1,                //its logical volume
                    "shield1",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(70,0,10),         //at (0,0,0)
                    logicshield1,                //its logical volume
                    "shield1",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    1,                       //copy number
                    checkOverlaps);          //overlaps checking


  //     
  // shield2
  //
  G4double shield2_sizeX = 100 * mm;
  G4double shield2_sizeY = 4 * mm;
  G4double shield2_sizeZ = 50 * mm;

  G4Box* solidshield2 =    
  new G4Box("shield2",                       //its name
       0.5*shield2_sizeX, 0.5*shield2_sizeY, 0.5*shield2_sizeZ);     //its size

  //G4Tubs* solidshield2 = new G4Tubs("shield2",0.,shield2_sizeR,0.5*shield2_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicshield2 =                         
    new G4LogicalVolume(solidshield2,            //its solid
                        Aluminium,        //its material
                        "logicshield2");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(22,44,10),         //at (0,0,0)
                    logicshield2,                //its logical volume
                    "shield2",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(22,-44,10),         //at (0,0,0)
                    logicshield2,                //its logical volume
                    "shield2",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    1,                       //copy number
                    checkOverlaps);          //overlaps checking


  //     
  // shield_bottom
  //
  G4double shield_bottom_sizeX = 100 * mm;
  G4double shield_bottom_sizeY = 92 * mm;
  G4double shield_bottom_sizeZ = 4 * mm;

  G4Box* solidshield_bottom =    
  new G4Box("shield_bottom",                       //its name
       0.5*shield_bottom_sizeX, 0.5*shield_bottom_sizeY, 0.5*shield_bottom_sizeZ);     //its size

  //G4Tubs* solidshield_bottom = new G4Tubs("shield_bottom",0.,shield_bottom_sizeR,0.5*shield_bottom_sizeH,0.*deg,360.*deg);
      
  G4LogicalVolume* logicshield_bottom =                         
    new G4LogicalVolume(solidshield_bottom,            //its solid
                        Aluminium,        //its material
                        "logicshield_bottom");              //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(22,0,-17),         //at (0,0,0)
                    logicshield_bottom,                //its logical volume
                    "shield_bottom",                   //its name
                    logicWorld,           //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                  



  G4SDManager *SDManager = G4SDManager::GetSDMpointer();
  G4String BeWindowSDname = "aBeWindowSD";
  BeWindowSD* aBeWindowSD = new BeWindowSD(BeWindowSDname);
  SDManager->AddNewDetector(aBeWindowSD);
  // Setting aBeWindowSD to all logical volumes with the same name 
  // of "logicBeWindow".
  //SetSensitiveDetector("logicBeWindow", aBeWindowSD, true);
  logicBeWindow->SetSensitiveDetector(aBeWindowSD);


  G4String GasSDname = "aGasSD";
  GasSD* aGasSD = new GasSD(GasSDname);
  SDManager->AddNewDetector(aGasSD);
  // Setting aGasSD to all logical volumes with the same name 
  // of "logicGas".
  //SetSensitiveDetector("logicGas", aGasSD, true);
  logicGasSD->SetSensitiveDetector(aGasSD);


 
 
  logicWorld->SetVisAttributes (G4VisAttributes::GetInvisible());
  logicDetector->SetVisAttributes (G4VisAttributes::GetInvisible());

  auto GasVisAtt= new G4VisAttributes(G4Colour(1.0,1.0,1.0));
  // GasVisAtt->SetVisibility(true);
  GasVisAtt->SetForceAuxEdgeVisible(true);
  logicGas->SetVisAttributes (G4VisAttributes::GetInvisible());//->SetVisAttributes(GasVisAtt);  

  auto GasSDVisAtt= new G4VisAttributes(G4Colour(1.0,0.3,1.0));
  // GasSDVisAtt->SetVisibility(true);
  GasSDVisAtt->SetForceAuxEdgeVisible(true);
  logicGasSD->SetVisAttributes (G4VisAttributes::GetInvisible());//->SetVisAttributes(GasSDVisAtt);  

  // auto KovarHoleVisAtt= new G4VisAttributes(G4Colour(0,0,0));
  // KovarHoleVisAtt->SetForceWireframe(true);
  // logicKovarHole->SetVisAttributes(KovarHoleVisAtt);  

  auto KovarVisAtt= new G4VisAttributes(G4Colour(0.5,0.1,1.0));
  KovarVisAtt->SetForceAuxEdgeVisible(true);
  logicKovar->SetVisAttributes(KovarVisAtt); 
  

  // auto KovarCollimationVisAtt= new G4VisAttributes(G4Colour(0.3,0.1,0));
  // KovarCollimationVisAtt->SetForceWireframe(true);
  // logicKovarCollimation->SetVisAttributes(KovarCollimationVisAtt); 

  auto Kovar2VisAtt= new G4VisAttributes(G4Colour(0.5,0.1,1.0));
  Kovar2VisAtt->SetForceAuxEdgeVisible(true);
  logicKovar2->SetVisAttributes(Kovar2VisAtt); 
  
  auto Scintillator1VisAtt= new G4VisAttributes(G4Colour(0.4,0.1,0.8));
  Scintillator1VisAtt->SetForceAuxEdgeVisible(true);
  logicScintillator1->SetVisAttributes(Scintillator1VisAtt);

  auto Scintillator1_holeVisAtt= new G4VisAttributes(G4Colour(0.4,0.9,0.8));
  Scintillator1_holeVisAtt->SetForceWireframe(true);
  logicScintillator1_hole->SetVisAttributes(Scintillator1_holeVisAtt);

  auto Scintillator2VisAtt= new G4VisAttributes(G4Colour(0.2,0.5,0.5));
  Scintillator2VisAtt->SetForceAuxEdgeVisible(true);
  logicScintillator2->SetVisAttributes(Scintillator2VisAtt);

  auto Scintillator2_holeVisAtt= new G4VisAttributes(G4Colour(0.4,0.9,0.8));
  Scintillator2_holeVisAtt->SetForceWireframe(true);
  logicScintillator2_hole->SetVisAttributes(Scintillator2_holeVisAtt);

  auto CeramicsVisAtt= new G4VisAttributes(G4Colour(0.3,0.1,0));
  // CeramicsVisAtt->SetVisibility(true);
  CeramicsVisAtt->SetForceWireframe(true);
  logicCeramics->SetVisAttributes(CeramicsVisAtt); 

  auto BeWindowVisAtt= new G4VisAttributes(G4Colour(0.3,0.7,1));
  // BeWindowVisAtt->SetVisibility(true);
  BeWindowVisAtt->SetForceWireframe(true);
  logicBeWindow->SetVisAttributes(BeWindowVisAtt); 

  auto shield1VisAtt= new G4VisAttributes(G4Colour(1,0.1,0.8));
  shield1VisAtt->SetForceWireframe(true);
  logicshield1->SetVisAttributes(shield1VisAtt);

  auto shield2VisAtt= new G4VisAttributes(G4Colour(1,0.1,0.8));
  shield2VisAtt->SetForceWireframe(true);
  logicshield2->SetVisAttributes(shield2VisAtt);

  auto shield_bottomVisAtt= new G4VisAttributes(G4Colour(1,0.1,0.8));
  shield_bottomVisAtt->SetForceWireframe(true);
  logicshield_bottom->SetVisAttributes(shield_bottomVisAtt);
  

  // auto CollimationVisAtt= new G4VisAttributes(G4Colour(1.0,0,1.0));
  // // CollimationVisAtt->SetVisibility(true);
  // CollimationVisAtt->SetForceAuxEdgeVisible(true);
  // logicCollimation->SetVisAttributes (G4VisAttributes::GetInvisible());//->SetVisAttributes(CollimationVisAtt); 
  
  //
  //always return the physical World
  //
  return physWorld;
}

void backgroundDetectorConstruction::DefineMaterials()
{
  //This function illustrates the possible ways to define materials

  G4String symbol;        //a=mass of a mole;
  G4double a, z, density; //z=mean number of protons;

  G4int ncomponents, natoms;
  G4double fractionmass;
  G4double temperature, pressure;

  //-----------------------------------------------------------------------------
  // define Elements
  //
  G4Element *H = new G4Element("Hydrogen", symbol = "H", z = 1, a = 1.01 * g / mole);
  G4Element *He = new G4Element("Helium", symbol = "He", z = 2., a = 4.00 * g / mole);
  G4Element *C = new G4Element("Carbon", symbol = "C", z = 6, a = 12.01 * g / mole);
  G4Element *elN = new G4Element("Nitrogen", symbol = "N", z = 7, a = 14.01 * g / mole);
  G4Element *O = new G4Element("Oxygen", symbol = "O", z = 8, a = 16.00 * g / mole);
  G4Element *F = new G4Element("Fluorine", symbol = "F", z = 9, a = 19.00 * g / mole);
  G4Element *Ne = new G4Element("Neon", symbol = "Ne", z = 10, a = 20.08 * g / mole);
  G4Element *Na = new G4Element("Sodium", symbol = "Na", z = 11, a = 22.99 * g / mole);
  G4Element *Al = new G4Element("Aluminium", symbol = "Al", z = 13, a = 26.98 * g / mole);
  G4Element *Si = new G4Element("Silicon", symbol = "Si", z = 14, a = 28.09 * g / mole);
  G4Element *P = new G4Element("Phosphorus", symbol = "P", z = 15., a = 30.973762 * g / mole);
  G4Element *S = new G4Element("Sulfur", symbol = "S", z = 16., a = 32.066 * g / mole);
  G4Element *Ar = new G4Element("Argon", symbol = "Ar", z = 18, a = 39.95 * g / mole);
  G4Element *Ga = new G4Element("calcium", symbol = "Ga", z = 20, a = 40.08 * g / mole);
  G4Element *Cr = new G4Element("Chrome", symbol = "Cr", z = 24, a = 51.996 * g / mole);
  G4Element *Mn = new G4Element("Manganese", symbol = "Mn", z = 25., a = 54.94 * g / mole);
  G4Element *Fe = new G4Element("Iron", symbol = "Fe", z = 26, a = 55.845 * g / mole);
  G4Element *Co = new G4Element("Cobalt", symbol = "Co", z = 27, a = 58.933 * g / mole);
  G4Element *Ni = new G4Element("Nickel", symbol = "Ni", z = 28, a = 58.693 * g / mole);
  G4Element *Cu = new G4Element("Copper", symbol = "Cu", z = 29., a = 63.546 * g / mole);
  G4Element *Br = new G4Element("Bromine", symbol = "Br", z = 35, a = 79.904 * g / mole);
  G4Element *Zr = new G4Element("Zirconium", symbol = "Zr", z = 40., a = 91.22 * g / mole);
  G4Element *Mo = new G4Element("Molybdenum", symbol = "Mo", z = 42., a = 95.94 * g / mole);
  G4Element *Y = new G4Element("Yttrium", symbol = "Y", z = 39, a = 88.91 * g / mole);
  G4Element *I = new G4Element("Iodine", symbol = "I", z = 53, a = 126.90 * g / mole);
  G4Element *Xe = new G4Element("Xenon", symbol = "Xe", z = 54, a = 131.29 * g / mole);
  G4Element *La = new G4Element("Lanthanum", symbol = "La", z = 57, a = 138.9055 * g / mole);
  G4Element *Ce = new G4Element("Cerium", symbol = "Ce", z = 58, a = 140.12 * g / mole);
  G4Element *Lu = new G4Element("Lutetium", symbol = "Lu", z = 71, a = 174.97 * g / mole);
  G4Element *W = new G4Element("Tungsten", symbol = "W", z = 74, a = 183.850 * g / mole);
  G4Element *eNe = G4NistManager::Instance()->FindOrBuildElement("Ne");
  G4Element *eH = G4NistManager::Instance()->FindOrBuildElement("H");
  G4Element *eC = G4NistManager::Instance()->FindOrBuildElement("C");
  G4Element *eO = G4NistManager::Instance()->FindOrBuildElement("O");

  G4Isotope *GdIsotope1 = new G4Isotope("Gd_152", 64, 152, 152.0 * g / mole);
  G4Isotope *GdIsotope2 = new G4Isotope("Gd_154", 64, 154, 154.0 * g / mole);
  G4Isotope *GdIsotope3 = new G4Isotope("Gd_155", 64, 155, 155.0 * g / mole);
  G4Isotope *GdIsotope4 = new G4Isotope("Gd_156", 64, 156, 156.0 * g / mole);
  G4Isotope *GdIsotope5 = new G4Isotope("Gd_157", 64, 157, 157.0 * g / mole);
  G4Isotope *GdIsotope6 = new G4Isotope("Gd_158", 64, 158, 158.0 * g / mole);
  G4Isotope *GdIsotope7 = new G4Isotope("Gd_160", 64, 160, 160.0 * g / mole);

  G4Element *Gd = new G4Element("Gadolinium", "Gd", 7);
  Gd->AddIsotope(GdIsotope1, 100.0 * 0.002 * 152 / 157.318 * perCent);
  Gd->AddIsotope(GdIsotope2, 100.0 * 0.022 * 154 / 157.318 * perCent);
  Gd->AddIsotope(GdIsotope3, 100.0 * 0.149 * 155 / 157.318 * perCent);
  Gd->AddIsotope(GdIsotope4, 100.0 * 0.206 * 156 / 157.318 * perCent);
  Gd->AddIsotope(GdIsotope5, 100.0 * 0.157 * 157 / 157.318 * perCent);
  Gd->AddIsotope(GdIsotope6, 100.0 * 0.247 * 158 / 157.318 * perCent);
  Gd->AddIsotope(GdIsotope7, 100.0 * 0.217 * 160 / 157.318 * perCent);

  //-----------------------------------------------------------------------------
  // define simple materials
  //
  new G4Material("H2Liq", z = 1, a = 1.01 * g / mole, density = 70.8 * mg / cm3);
  new G4Material("Beryllium", z = 4, a = 9.01 * g / mole, density = 1.848 * g / cm3);
  new G4Material("Aluminium", z = 13, a = 26.98 * g / mole, density = 2.700 * g / cm3);
  new G4Material("Silicon", z = 14, a = 28.09 * g / mole, density = 2.330 * g / cm3);
  new G4Material("Iron", z = 26, a = 55.85 * g / mole, density = 7.870 * g / cm3);
  new G4Material("Copper", z = 29, a = 63.55 * g / mole, density = 8.960 * g / cm3);
  new G4Material("Germanium", z = 32, a = 72.61 * g / mole, density = 5.323 * g / cm3);
  new G4Material("Silver", z = 47, a = 107.87 * g / mole, density = 10.50 * g / cm3);
  new G4Material("Tungsten", z = 74, a = 183.85 * g / mole, density = 19.30 * g / cm3);
  new G4Material("Gold", z = 79, a = 196.97 * g / mole, density = 19.32 * g / cm3);
  new G4Material("Lead", z = 82, a = 207.19 * g / mole, density = 11.35 * g / cm3);

  //-----------------------------------------------------------------------------
  // define scintillator
  // 定义闪烁体
  G4Material *CH = new G4Material("Plastic", density = 1.04 * g / cm3, ncomponents = 2);
  CH->AddElement(C, natoms = 1);
  CH->AddElement(H, natoms = 1);

  G4Material *NaI = new G4Material("NaI", density = 3.67 * g / cm3, ncomponents = 2);
  NaI->AddElement(Na, natoms = 1);
  NaI->AddElement(I, natoms = 1);
  NaI->GetIonisation()->SetMeanExcitationEnergy(452 * eV);

  G4Material *LaBr3 = new G4Material("LaBr3", density = 5.06 * g / cm3, ncomponents = 2);
  LaBr3->AddElement(La, natoms = 1);
  LaBr3->AddElement(Br, natoms = 3);

  G4Material *LSO = new G4Material("Lu2SiO5", 7.4 * g / cm3, 3);
  LSO->AddElement(Lu, 2);
  LSO->AddElement(Si, 1);
  LSO->AddElement(O, 5);

  G4Material *GAGG = new G4Material("GAGG", density = 6.63 * g / cm3, ncomponents = 4);
  GAGG->AddElement(Gd, natoms = 3);
  GAGG->AddElement(Al, natoms = 2);
  GAGG->AddElement(Ga, natoms = 3);
  GAGG->AddElement(O, natoms = 12);

  // LYSO:Ce,   Assuming Lu2(x-1)Y2(x)SiO5:Ce. x=10%, Ce=5%.
  // So, Ce=5%, LYSO=95%.(mole faction) => mass fraction: Ce=0.19%, LYSO=99.91%
  // then for LYSO, the same as above
  G4Material *Scint_mat = new G4Material("Scint", density = 7.4 * g / cm3, ncomponents = 4);
  Scint_mat->AddElement(Lu, 71 * perCent);
  Scint_mat->AddElement(Si, 7 * perCent);
  Scint_mat->AddElement(O, 18 * perCent);
  Scint_mat->AddElement(Y, 4 * perCent);

  G4Material *LYSO = new G4Material("LYSO", density = 7.4 * g / cm3, ncomponents = 2);
  LYSO->AddMaterial(Scint_mat, 99.81 * perCent);
  LYSO->AddElement(Ce, 0.19 * perCent);

  //-----------------------------------------------------------------------------
  // define metal
  // 定义金属
  G4Material *Graphite = new G4Material("Graphite", density = 1.7 * g / cm3, ncomponents = 1);
  Graphite->AddElement(C, fractionmass = 1.);

  //Havar 合金
  G4Material *Havar = new G4Material("Havar", density = 8.3 * g / cm3, ncomponents = 5);
  Havar->AddElement(Cr, fractionmass = 0.1785);
  Havar->AddElement(Fe, fractionmass = 0.1822);
  Havar->AddElement(Co, fractionmass = 0.4452);
  Havar->AddElement(Ni, fractionmass = 0.1310);
  Havar->AddElement(W, fractionmass = 0.0631);

  G4Material *Kovar = new G4Material("Kovar", density = 8.17 * g / cm3, ncomponents = 12);
  Kovar->AddElement(Ni, fractionmass = 29 * perCent);
  Kovar->AddElement(Co, fractionmass = 17 * perCent);
  Kovar->AddElement(Mn, fractionmass = 0.5 * perCent);
  Kovar->AddElement(Si, fractionmass = 0.2 * perCent);
  Kovar->AddElement(S, fractionmass = 0.025 * perCent);
  Kovar->AddElement(Cr, fractionmass = 0.2 * perCent);
  Kovar->AddElement(Cu, fractionmass = 0.2 * perCent);
  Kovar->AddElement(Mo, fractionmass = 0.2 * perCent);
  Kovar->AddElement(Zr, fractionmass = 0.1 * perCent);
  Kovar->AddElement(P, fractionmass = 0.025 * perCent);
  Kovar->AddElement(C, fractionmass = 0.06 * perCent);
  Kovar->AddElement(Fe, fractionmass = 52.49 * perCent);

  G4Material *SSteel = new G4Material("SSteel", density = 7.7 * g / cm3, ncomponents = 3);
  SSteel->AddElement(Fe, fractionmass = 88 * perCent);
  SSteel->AddElement(Co, fractionmass = 8 * perCent);
  SSteel->AddElement(C, fractionmass = 4 * perCent);

  G4Material *ceramics = new G4Material("ceramics", density = 2.88 * g / cm3, ncomponents = 2);
  ceramics->AddElement(Al, natoms = 2);
  ceramics->AddElement(O, natoms = 3);

  G4Material *Scintillator = new G4Material("Scintillator", density = 1.190 * g / cm3, ncomponents = 3);
  Scintillator->AddElement(C, natoms = 5);
  Scintillator->AddElement(H, natoms = 8);
  Scintillator->AddElement(O, natoms = 2);

  //-----------------------------------------------------------------------------
  // define water
  // 定义水
  G4Material *H2O = new G4Material("Water", density = 1.000 * g / cm3, ncomponents = 2);
  H2O->AddElement(H, natoms = 2);
  H2O->AddElement(O, natoms = 1);
  H2O->GetIonisation()->SetMeanExcitationEnergy(78 * eV);

  G4Material *steam = new G4Material("WaterSteam", density = 1.0 * mg / cm3, ncomponents = 1);
  steam->AddMaterial(H2O, fractionmass = 1.);
  steam->GetIonisation()->SetMeanExcitationEnergy(71.6 * eV);

  //-----------------------------------------------------------------------------
  // example of vacuum
  // 定义真空
  density = universe_mean_density; //from PhysicalConstants.h
  pressure = 3.e-18 * pascal;
  temperature = 2.73 * kelvin;
  new G4Material("Galactic", z = 1, a = 1.01 * g / mole, density, kStateGas, temperature, pressure);

  //-----------------------------------------------------------------------------
  // JUNO & Dayabay etc. related
  //
  G4Material *LS = new G4Material("LS", 0.859 * g / cm3, 5);
  LS->AddElement(C, 0.87924);
  LS->AddElement(H, 0.1201);
  LS->AddElement(O, 0.00034);
  LS->AddElement(elN, 0.00027);
  LS->AddElement(S, 0.00005);

  G4Material *ESR = new G4Material("ESR", 1.0 * g / cm3, 2);
  ESR->AddElement(H, 2. * 1.00794 / (12.0107 + 2. * 1.00794));
  ESR->AddElement(C, 12.0107 / (12.0107 + 2. * 1.00794));

  G4Material *Tyvek = new G4Material("Tyvek", 0.94 * g / cm3, 2);
  Tyvek->AddElement(C, 2);
  Tyvek->AddElement(H, 4);

  G4Material *Acrylic = new G4Material("Acrylic", 1.18 * g / cm3, 3);
  Acrylic->AddElement(C, 0.59984);
  Acrylic->AddElement(H, 0.08055);
  Acrylic->AddElement(O, 0.31961);

  G4Material *GdLS = new G4Material("GdDopedLS", 0.8602 * g / cm3, 6);
  GdLS->AddElement(C, 0.87705);
  GdLS->AddElement(H, 0.12051);
  GdLS->AddElement(O, 0.00109);
  GdLS->AddElement(Gd, 0.0010315);
  GdLS->AddElement(elN, 0.00027);
  GdLS->AddElement(S, 0.00005);

  //-----------------------------------------------------------------------------
  // define air
  // 定义空气
  G4Material *Air = new G4Material("Air", density = 1.290 * mg / cm3, ncomponents = 2);
  Air->AddElement(elN, fractionmass = 0.7);
  Air->AddElement(O, fractionmass = 0.3);

  G4Material *Air20 = new G4Material("Air20", density = 1.205 * mg / cm3, ncomponents = 2, kStateGas, 293. * kelvin, 1. * atmosphere);
  Air20->AddElement(elN, fractionmass = 0.7);
  Air20->AddElement(O, fractionmass = 0.3);

  //-----------------------------------------------------------------------------
  // define argon and xenon
  // 定义氩气和氙气
  new G4Material("ArgonGas", z = 18, a = 39.948 * g / mole, density = 1.782 * mg / cm3, kStateGas, 273.15 * kelvin, 1 * atmosphere);
  new G4Material("XenonGas", z = 54, a = 131.29 * g / mole, density = 5.458 * mg / cm3, kStateGas, 293.15 * kelvin, 1 * atmosphere);

  new G4Material("Ar_P0_1", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 0.1, kStateGas, 293.15 * kelvin, atmosphere * 1.5);
  new G4Material("Ar_P0_3", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 0.3, kStateGas, 293.15 * kelvin, atmosphere * 1.5);
  new G4Material("Ar_P0_5", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 0.5, kStateGas, 293.15 * kelvin, atmosphere * 1.5);
  new G4Material("Ar_P0_8", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 0.8, kStateGas, 293.15 * kelvin, atmosphere * 1.5);
  new G4Material("Ar_P1_0", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 1.0, kStateGas, 293.15 * kelvin, atmosphere * 1.5);
  new G4Material("Ar_P2_0", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 2.0, kStateGas, 293.15 * kelvin, atmosphere * 2.0);
  new G4Material("Ar_P2_5", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 2.5, kStateGas, 293.15 * kelvin, atmosphere * 2.5);
  new G4Material("Ar_P3_0", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 3.0, kStateGas, 293.15 * kelvin, atmosphere * 3.0);
  new G4Material("Ar_P3_5", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 3.5, kStateGas, 293.15 * kelvin, atmosphere * 3.5);
  new G4Material("Ar_P4_0", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 4.0, kStateGas, 293.15 * kelvin, atmosphere * 4.0);
  new G4Material("Ar_P5_0", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 5.0, kStateGas, 293.15 * kelvin, atmosphere * 5.0);
  new G4Material("Ar_P10_0", z = 18, a = 39.95 * g / mole, 1.782 * mg / cm3 * 10.0, kStateGas, 293.15 * kelvin, atmosphere * 10.0);

  new G4Material("Xe_P10_0", z = 54, a = 131.29 * g / mole, 5.48536 * mg / cm3 * 10.0, kStateGas, 293.15 * kelvin, atmosphere * 10.0);

  G4Material *lAr = new G4Material("liquidArgon", density = 1.390 * g / cm3, ncomponents = 1);
  lAr->AddElement(Ar, natoms = 1);

  G4Material *lXe = new G4Material("liquidXenon", density = 2.942 * g / cm3, ncomponents = 1);
  lXe->AddElement(Xe, natoms = 1);


  //-----------------------------------------------------------------------------
  // my concern of gas
  //
  // define higher pressure of Argon
  //

  //-----------------------------------------------------------------------------
  // examples of gas
  //
  G4Material *CO2 = new G4Material("CarbonicGas", density = 1.977 * mg / cm3, ncomponents = 2);
  CO2->AddElement(C, natoms = 1);
  CO2->AddElement(O, natoms = 2);

  G4Material *CF4 = new G4Material("CF4", density = 3.720 * mg / cm3, ncomponents = 2);
  CF4->AddElement(C, natoms = 1);
  CF4->AddElement(F, natoms = 4);

  G4Material *CF4_P3 = new G4Material("CF4_P3_0", density = 3.0 * 3.720 * mg / cm3, ncomponents = 2);
  CF4_P3->AddElement(C, natoms = 1);
  CF4_P3->AddElement(F, natoms = 4);

  G4Material *CF4_P5 = new G4Material("CF4_P5_0", density = 5.0 * 3.720 * mg / cm3, ncomponents = 2);
  CF4_P5->AddElement(C, natoms = 1);
  CF4_P5->AddElement(F, natoms = 4);

  G4Material *CF4_P10 = new G4Material("CF4_P10_0", density = 10.0 * 3.720 * mg / cm3, ncomponents = 2);
  CF4_P10->AddElement(C, natoms = 1);
  CF4_P10->AddElement(F, natoms = 4);

  //double rho_DME=0.00197, rho_He=0.0001786, rho_Ne=0.000825, rho_CF4=0.00372;
  G4Material *DME = new G4Material("DME", density = 0.00191855 * g / cm3, ncomponents = 3);//https://pubchem.ncbi.nlm.nih.gov/
  DME->AddElement(H, natoms = 6);
  DME->AddElement(C, natoms = 2);
  DME->AddElement(O, natoms = 1);

  //-----------------------------------------------------------------------------
  // examples of gas mixture
  //
  G4Material *ArCO2 = new G4Material("ArgonCO2", density = 1.8223 * mg / cm3, ncomponents = 2);
  ArCO2->AddElement(Ar, fractionmass = 0.7844);
  ArCO2->AddMaterial(CO2, fractionmass = 0.2156);

  //---------------- He:DME = 20:80 -------------------
  G4Material *He_20_DME_80 = new G4Material("He_20_DME_80", density = 0.001932 * g / cm3, ncomponents = 2);
  He_20_DME_80->AddElement(He, fractionmass = 2.7 * perCent);
  He_20_DME_80->AddMaterial(DME, fractionmass = 97.3 * perCent);

  G4Material *He_20_DME_80_P0_5 = new G4Material("He_20_DME_80_P0_5", density = 0.001932 * 0.5 * g / cm3, ncomponents = 2);
  He_20_DME_80_P0_5->AddElement(He, fractionmass = 2.7 * perCent);
  He_20_DME_80_P0_5->AddMaterial(DME, fractionmass = 97.3 * perCent);

  G4Material *He_20_DME_80_P0_6 = new G4Material("He_20_DME_80_P0_6", density = 0.001932 * 0.6 * g / cm3, ncomponents = 2);
  He_20_DME_80_P0_6->AddElement(He, fractionmass = 2.7 * perCent);
  He_20_DME_80_P0_6->AddMaterial(DME, fractionmass = 97.3 * perCent);

  G4Material *He_20_DME_80_P0_7 = new G4Material("He_20_DME_80_P0_7", density = 0.001932 * 0.7 * g / cm3, ncomponents = 2);
  He_20_DME_80_P0_7->AddElement(He, fractionmass = 2.7 * perCent);
  He_20_DME_80_P0_7->AddMaterial(DME, fractionmass = 97.3 * perCent);

  G4Material *He_20_DME_80_P0_8 = new G4Material("He_20_DME_80_P0_8", density = 0.001932 * 0.8 * g / cm3, ncomponents = 2);
  He_20_DME_80_P0_8->AddElement(He, fractionmass = 2.7 * perCent);
  He_20_DME_80_P0_8->AddMaterial(DME, fractionmass = 97.3 * perCent);

  //---------------- Ne:DME = 80:20 -------------------
  G4Material *Ne_80_DME_20 = new G4Material("Ne_80_DME_20", density = 0.00104371 * g / cm3, ncomponents = 2);
  Ne_80_DME_20->AddElement(Ne, fractionmass = 63.492 * perCent);
  Ne_80_DME_20->AddMaterial(DME, fractionmass = 36.508 * perCent);

  G4Material *Ne_80_DME_20_P0_5 = new G4Material("Ne_80_DME_20_P0_5", density = 0.00104371 * 0.5 * g / cm3, ncomponents = 2);
  Ne_80_DME_20_P0_5->AddElement(Ne, fractionmass = 63.492 * perCent);
  Ne_80_DME_20_P0_5->AddMaterial(DME, fractionmass = 36.508 * perCent);
	
  G4Material *Ne_80_DME_20_P0_6 = new G4Material("Ne_80_DME_20_P0_6", density = 0.00104371 * 0.6 * g / cm3, ncomponents = 2);
  Ne_80_DME_20_P0_6->AddElement(Ne, fractionmass = 63.492 * perCent);
  Ne_80_DME_20_P0_6->AddMaterial(DME, fractionmass = 36.508 * perCent);

  G4Material *Ne_80_DME_20_P0_7 = new G4Material("Ne_80_DME_20_P0_7", density = 0.00104371 * 0.7 * g / cm3, ncomponents = 2);
  Ne_80_DME_20_P0_7->AddElement(Ne, fractionmass = 63.492 * perCent);
  Ne_80_DME_20_P0_7->AddMaterial(DME, fractionmass = 36.508 * perCent);

  G4Material *Ne_80_DME_20_P0_8 = new G4Material("Ne_80_DME_20_P0_8", density = 0.00104371 * 0.8 * g / cm3, ncomponents = 4);
  Ne_80_DME_20_P0_8->AddElement(eNe, natoms = 4);
  Ne_80_DME_20_P0_8->AddElement(eC, natoms = 2);
  Ne_80_DME_20_P0_8->AddElement(eH, natoms = 6);
  Ne_80_DME_20_P0_8->AddElement(eO, natoms = 1);

  //---------------- Ne:CF4 = 95:5 -------------------
  G4Material *Ne_95_CF4_5 = new G4Material("Ne_95_CF4_5", density = 0.00104119 * g / cm3, ncomponents = 2);
  Ne_95_CF4_5->AddElement(Ne, fractionmass = 82.14 * perCent);
  Ne_95_CF4_5->AddMaterial(CF4, fractionmass = 17.86 * perCent);

  G4Material *Ne_95_CF4_5_P0_5 = new G4Material("Ne_95_CF4_5_P0_5", density = 0.00104119 * 0.5 * g / cm3, ncomponents = 2);
  Ne_95_CF4_5_P0_5->AddElement(Ne, fractionmass = 82.14 * perCent);
  Ne_95_CF4_5_P0_5->AddMaterial(CF4, fractionmass = 17.86 * perCent);

  G4Material *Ne_95_CF4_5_P0_6 = new G4Material("Ne_95_CF4_5_P0_6", density = 0.00104119 * 0.6 * g / cm3, ncomponents = 2);
  Ne_95_CF4_5_P0_6->AddElement(Ne, fractionmass = 82.14 * perCent);
  Ne_95_CF4_5_P0_6->AddMaterial(CF4, fractionmass = 17.86 * perCent);

  G4Material *Ne_95_CF4_5_P0_7 = new G4Material("Ne_95_CF4_5_P0_7", density = 0.00104119 * 0.7 * g / cm3, ncomponents = 2);
  Ne_95_CF4_5_P0_7->AddElement(Ne, fractionmass = 82.14 * perCent);
  Ne_95_CF4_5_P0_7->AddMaterial(CF4, fractionmass = 17.86 * perCent);

  G4Material *Ne_95_CF4_5_P0_8 = new G4Material("Ne_95_CF4_5_P0_8", density = 0.00104119 * 0.8 * g / cm3, ncomponents = 2);
  Ne_95_CF4_5_P0_8->AddElement(Ne, fractionmass = 82.14 * perCent);
  Ne_95_CF4_5_P0_8->AddMaterial(CF4, fractionmass = 17.86 * perCent);

  //G4cout << *(G4Material::GetMaterialTable()) << G4endl;
  G4Material *Ne_50_DME_50 = new G4Material("Ne_50_DME_50", density = 0.00143522 * 1.4 *g / cm3, ncomponents =2);
  Ne_50_DME_50->AddElement(Ne, fractionmass = 35.714 * perCent);
  Ne_50_DME_50->AddMaterial(DME, fractionmass = 64.286 * perCent);

  G4Material *Ne_P1 = new G4Material("Ne_P1", density = 1 * 0.836 * mg / cm3, ncomponents = 1);
  Ne_P1->AddElement(Ne, natoms = 1);
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
