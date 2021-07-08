// ********************************************************************
//
#include "TApplication.h"
#include "TROOT.h"
#include "TFile.h"
#include "TSystem.h"
#include "TTree.h"
#include "TKey.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF2.h"
#include "TH3F.h"
#include "TPolyLine3D.h"
#include "TPolyMarker3D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TView.h"
//
#include "SimEvent.h"
#include "G4ios.hh"
#include <iostream>
#include "Riostream.h"
#include "MyHistMathLibrary.h"

#include "time.h"

void WriteRoot();
void ReadRoot();

TString fFileName;
TH2D *fhitXY;
TH2D *fhitXZ;
TH2D *fhitYZ;
TH2D *fSmearXY;
TH2D *fSmearXZ;
TH2D *fSmearYZ;
TH3D *fAllXYZ;

TH2D *fVXY;
TH2D *fVXZ;
TH2D *fVYZ;
TH1D *fIEnergy;
TH1D *fmomXY;
TH1D *fmomYZ;
TH1D *fmomXZ;
TH1D *fmomp;
TH1D *fBeEnergy;
TH1D *fStepLength;
TH1D *fNumCrossBe;
TH1D *fProject;

TCanvas *c1;
TCanvas *c2;
TCanvas *c3;
TCanvas *c4;
TCanvas *c5;
//TCanvas *c6;

int verbose = 0;
TString binFile("./mcsim.data"); //MC simulated *.data file

const int NX = 72;
const int NY = 72;
const double spaRes = 0.05;   //default: 0.07
const double lenPit = 0.08;
const double conFac = 10000 / 30E-6; //gain/W_avg*(??DAQ??)

int main(int argc, char **argv)
{
    //TApplication theApp("App", &argc, argv); //批量注释

    fFileName = TString("tmp.root");

    // initialize ROOT
    TSystem ts;
    gSystem->Load("libSimEventDict");

    if (argc < 2)
        G4cout << "Missing name of the file to read! Read " << fFileName << " instead." << G4endl;
    else
        fFileName = argv[1]+TString(".root");
		G4cout << " Read " << fFileName << G4endl;
    ReadRoot();

    //theApp.Run();  //批量注释
    return 0;
}
//
//  TFile fo(argv[1]);
//
//  std::vector<ExP01TrackerHit*>* hits;
//  fo.GetListOfKeys()->Print();
//
//  TIter next(fo.GetListOfKeys());
//  TKey *key;
//  //double tot_en;
//  while ((key=(TKey*)next()))
//  {
//    fo.GetObject(key->GetName(), hits);
//
//    //tot_en = 0;
//    if(verbose) G4cout << "Collection: " << key->GetName() << G4endl;
//    if(verbose) G4cout << "Number of hits: " << hits->size() << G4endl;
//    for (size_t i=0;i!=hits->size();i++)
//    {
//      (*hits)[i]->Print();
//    }
//  }

void WriteRoot()
{
    if (verbose >= 0)
        G4cout << "---> Write to " << fFileName << " root file." << G4endl;

    TFile *fRootFp = new TFile(fFileName, "recreate");

    SimEvent *fEvent = new SimEvent();
    TTree *fTree1 = new TTree("sim", "Tree of GasTPC events");

    fTree1->Branch("SimEvent", "SimEvent", &fEvent, 32000, 99);
    //for(int i=0; i<9; i++) fEvent->SetTime(i, 10*i);

    fTree1->Fill();
    fEvent->Clear();

    fRootFp->Write();
    fRootFp->Close();
}

void ReadRoot()
{
    if (verbose >= 0)
        G4cout << "---> Reading from " << fFileName << " root file." << G4endl;

    //---- init canvas ----
    //
    c1 = new TCanvas("c1", "c1", 1440, 720);
    c2 = new TCanvas("c2", "c2", 1440, 720);
    c3 = new TCanvas("c3", "c3", 1440, 720);
    c4 = new TCanvas("c4", "c4", 1440, 720);
    c5 = new TCanvas("c5", "c5", 1440, 720);

    //c6 = new TCanvas("c6", "c6", 720, 720);
	//TView *view = TView::CreateView(6);
	//view->SetRange(-1,-1,-1,1,1,1);

    c1->Divide(2, 2);
    c5->Divide(1, 3);
	c4->Divide(2, 2);

    //---- init histogram ----
    //
    double pi = TMath::Pi();
    
    fVXY = new TH2D("fVXY", "fVXY", 100, -1, 1, 100, -1, 1);
    fVXZ = new TH2D("fVXZ", "fVXZ", 100, -1, 1, 100, -1, 1);
    fVYZ = new TH2D("fVYZ", "fVYZ", 100, -1, 1, 100, -1, 1);
	
	

    fhitXY = new TH2D("fhitXY", "fhitXY", NX, -lenPit * 36, lenPit * 36, NY, -lenPit * 36, lenPit * 36);
    fhitXZ = new TH2D("fhitXZ", "fhitXZ", NX, -lenPit * 36, lenPit * 36, NY, -lenPit * 72, 0);
    fhitYZ = new TH2D("fhitYZ", "fhitYZ", NX, -lenPit * 36, lenPit * 36, NY, -lenPit * 36, lenPit * 36);
	//fAllXYZ =new TH3F("fAllXYZ", "fAllXYZ", 40, -1, 1, 40, -1, 1, 40, -1, 1);

	//TPolyMarker3D *pm3d1 = new TPolyMarker3D();
	
    fIEnergy = new TH1D("fIEnergy", "GasEnergy", 100, 0, 16);
    fmomXY = new TH1D("fmomXY", "XY", 100, -pi, pi);
    fmomYZ = new TH1D("fmomYZ", "YZ", 100, -pi, pi);
    fmomXZ = new TH1D("fmomXZ", "XZ", 100, -pi, pi);

    fSmearXY = new TH2D("fSmearXY", "fSmearXY", NX, -lenPit * 36, lenPit * 36, NY, -lenPit * 36, lenPit * 36);
    fSmearXZ = new TH2D("fSmearXZ", "fSmearXZ", NX, -lenPit * 36, lenPit * 36, NY, -lenPit * 72, 0);
    fSmearYZ = new TH2D("fSmearYZ", "fSmearYZ", NX, -lenPit * 36, lenPit * 36, NY, -lenPit * 36, lenPit * 36);
	
	fmomp = new TH1D("momentum", "emomentum", 100,0,1);
	fBeEnergy = new TH1D("Bewindows", "Beenergy", 100,0,1);
	fStepLength = new TH1D("StepLength", "StepLength", 50,0,10);

	double initPosZ =0;
	int const Nbins = 110;
	double bins[Nbins];
	for (int i=0; i<Nbins; i++){
			bins[i]= -5.5 + 0.1*i;
	}  
	//fStepLength = new TH1F("positionOfZ", "positionOfZ", Nbins-1,bins);
	//fNumCrossBe = new TH1F("NumCrossBe", "NumberCrossBe", 10,0,10);
	fProject = new TH1D("xyStepLength", "xyStepLength", 50,0,1);
	//int effectCounts = 0;

    //---- init output file ----
    //
    unsigned short data[NX][NY];
    std::ofstream ofSignal;
    ofSignal.open(binFile.Data(), std::ios::binary);

    //---- init root file to read ----
    //
    TFile *fRootFp = new TFile(fFileName);
    if (!fRootFp->IsOpen())
    {
        G4cout << "---> Can't open " << fFileName << "." << G4endl;
        return;
    }

    SimEvent *fEvent = 0;
    TTree *fTree1 = (TTree *)fRootFp->Get("sim");
    fTree1->SetBranchAddress("SimEvent", &fEvent);

    //---- process data-reading ----
    //
    clock_t start = clock();
	int rates = fTree1->GetEntries();
    G4cout << "> There are " << rates << " events stored." << G4endl;
	double serchEnergy = 0;
	double entirelyAbsorb = 0;

    //TPolyLine3D *pl3d[rates];
    for (int i = 0; i < fTree1->GetEntries(); i++)
    {
        if (verbose >= 0 && i % 100 == 0)
        {
            clock_t stop = clock();
            G4cout << "> No. " << i << " event: " << (double)(stop - start) / CLOCKS_PER_SEC << " s passed." << G4endl;
            start = stop;
        }
		//int fCounts = 0;
        // 0. reset all histogram
        fTree1->GetEntry(i);
        fhitXY->Reset();
        fhitXZ->Reset();
        fhitYZ->Reset();

        // 1. the global information of the fEvent
        if (verbose > 0)
        {
            G4cout << ">  PdgID : " << fEvent->GetPDGID() << G4endl;
            G4cout << ">  Energy: " << fEvent->GetTrueEnergy() << G4endl;
            G4cout << ">  Moment: (" << fEvent->GetMomentumDir().x() << ", "
                   << fEvent->GetMomentumDir().y() << ", "
                   << fEvent->GetMomentumDir().z() << ") " << G4endl;
        }

        double PEDDirectionX = fEvent->GetPEDirection().x();
        double PEDDirectionY = fEvent->GetPEDirection().y();
        double PEDDirectionZ = fEvent->GetPEDirection().z();
        double ay1 = 0, ay2 = 0, ay3 = 0, ay4 = 0, ay5 = 0, ay6 = 0;

        double k1 = (PEDDirectionX == 0) ? 1000 : PEDDirectionY / PEDDirectionX; //斜率
        if (PEDDirectionY >= 0 && PEDDirectionX >= 0)
        { //四个象限分别讨论
            ay1 = k1;
            ay2 = atan(ay1);
        }
        else if (PEDDirectionY <= 0 && PEDDirectionX >= 0)
        {
			ay1 = k1;
            ay2 = atan(ay1);
            
        }
        else if (PEDDirectionY >= 0 && PEDDirectionX <= 0)
        {
            ay2 = atan(k1);
            ay2 = pi + ay2;
        }
        else if (PEDDirectionY <= 0 && PEDDirectionX <= 0)
        {
            ay2 = atan(k1);
            ay2 = ay2 - pi;
        }

        double k2 = (PEDDirectionY == 0) ? 1000 : PEDDirectionZ / PEDDirectionY; //斜率
        if (PEDDirectionZ >= 0 && PEDDirectionY >= 0)
        { //四个象限分别讨论
            ay3 = k2;
            ay4 = atan(ay3);
        }
        else if (PEDDirectionZ <= 0 && PEDDirectionY >= 0)
        {
            ay3 = k2;
            ay4 = atan(ay3);
        }
        else if (PEDDirectionZ >= 0 && PEDDirectionY <= 0)
        {
            ay4 = atan(k2);
            ay4 = pi + ay4;
        }
        else if (PEDDirectionZ <= 0 && PEDDirectionY <= 0)
        {
            ay4 = atan(k2);
            ay4 = ay4 - pi;
        }

        double k3 = (PEDDirectionX == 0) ? 1000 : PEDDirectionZ / PEDDirectionX; //斜率
        if (PEDDirectionZ >= 0 && PEDDirectionX >= 0)
        { //四个象限分别讨论
            ay5 = k3;
            ay6 = atan(ay5);
        }
        else if (PEDDirectionZ <= 0 && PEDDirectionX >= 0)
        {
			ay5 = k3;
            ay6 = atan(ay5);
        }
        else if (PEDDirectionZ >= 0 && PEDDirectionX <= 0)
        {
            ay6 = atan(k3);
            ay6 = pi + ay6;
        }
        else if (PEDDirectionZ <= 0 && PEDDirectionX <= 0)
        {
            ay6 = atan(k3);
            ay6 = ay6 - pi;
        }

		double fmomment = sqrt(pow(PEDDirectionX,2)+pow(PEDDirectionY,2));
		//double fmomment = fEvent->GetTrueEnergy();
		//fmomment = fmomment*1000;
		//if (fmomment = 14)  continue;
		//if (fmomment<1){G4cout<<"!!!!!!!!!! "<<fmomment<<G4endl;}
		if (PEDDirectionX !=0 && PEDDirectionY!=0 && PEDDirectionZ !=0)
			fmomp->Fill(fmomment);

        double aEnergy = fEvent->GetEventGasEnergy();
        aEnergy = aEnergy * 1000;
        if (aEnergy !=0)
        fIEnergy->Fill(aEnergy);
		if ( aEnergy > serchEnergy )
			serchEnergy = aEnergy;

		double BeWindowsEnergy = fEvent->GetEventBeWindowsEnergy();
		BeWindowsEnergy = BeWindowsEnergy*1000;
		if (BeWindowsEnergy !=0)
			fBeEnergy->Fill(BeWindowsEnergy);
	
		//double startPosiZ = fEvent->GetSaveZ();
		//G4cout<<"=======  "<<startPosiZ<<G4endl;
		//if (startPosiZ>=-8 && startPosiZ<=8)
		//	fStepLength->Fill(startPosiZ);
		//pm3d1->SetPoint(i, PEDDirectionX, PEDDirectionY, PEDDirectionZ);

		//pl3d[i] = new TPolyLine3D(2);
		//pl3d[i]->SetPoint(0, 0, 0, 0);
		//pl3d[i]->SetPoint(1, PEDDirectionX, PEDDirectionY, PEDDirectionZ);

		 if (PEDDirectionX == 0 && PEDDirectionY == 0 && PEDDirectionZ == 0) {continue;}
			else {
				fmomXY->Fill(ay2);
				fmomYZ->Fill(ay4);
				fmomXZ->Fill(ay6);

				fVXY->Fill(PEDDirectionX, PEDDirectionY);
				gStyle->SetOptStat(111111);
				fVYZ->Fill(PEDDirectionY, PEDDirectionZ);
				fVXZ->Fill(PEDDirectionX, PEDDirectionZ);

				//fAllXYZ->Fill(PEDDirectionX, PEDDirectionY, PEDDirectionZ);

				double GasStepLength = fEvent->GetStepLength();
				if (GasStepLength !=0)
				fStepLength->Fill(GasStepLength);

				double fsinTheta = fabs(PEDDirectionZ)/sqrt(pow(PEDDirectionX,2)+pow(PEDDirectionY,2)+pow(PEDDirectionZ,2));
				double fcosTHeta = sqrt(pow(PEDDirectionX,2)+pow(PEDDirectionY,2))/sqrt(pow(PEDDirectionX,2)+pow(PEDDirectionY,2)+pow(PEDDirectionZ,2));
				//double xyLength = GasStepLength * sqrt(1-pow(fsinTheta,2));
				double xyLength = GasStepLength * fcosTHeta;
				//if (xyLength>0.33941125)  //(0.08*3)^2 *2
				//	effectCounts++;
				fProject->Fill(xyLength);
			}
			
		double TheNumCrossBe = fEvent->GetNumCrossBe();
		if (TheNumCrossBe !=0)
			fNumCrossBe->Fill(TheNumCrossBe);
		//G4cout<<"------------- "<<GasStepLength<<G4endl;
        // 2. read tracks information
        TMap *trkMap1 = fEvent->GetGasSDTrackMap();
        TMap *depMap1 = fEvent->GetGasSDDepositMap();

        TMap *trkMap2 = fEvent->GetWindowSDTrackMap();
        TMap *depMap2 = fEvent->GetWindowSDDepositMap();

        if (verbose)
            G4cout << ">-----Tracks in Gas : " << trkMap1->GetSize() << " tracks." << G4endl;

        TObject *tempObj = 0;
        TIterator *it = trkMap1->MakeIterator();
        while ((tempObj = it->Next()))
        {
            TObjString *obj = dynamic_cast<TObjString *>(tempObj);
            SimTrack *trk = dynamic_cast<SimTrack *>(trkMap1->GetValue(obj));
            if (verbose > 1)
            {
                G4cout << ": \t-------------------------" << G4endl;
                G4cout << ": \t-PdgID :" << trk->GetPDGID() << G4endl;
                G4cout << ": \t TrkID :" << trk->GetTrackID() << G4endl;
                G4cout << ": \t Mass  :" << trk->GetInitMass() << G4endl;
                G4cout << ": \t Ek    :" << trk->GetInitEk() << G4endl;
                G4cout << ": \t Edep  :" << trk->GetEdep() << G4endl;
                G4cout << ": \t IniPx :" << trk->GetInitPx() << G4endl;
                G4cout << ": \t IniPy :" << trk->GetInitPy() << G4endl;
                G4cout << ": \t IniPz :" << trk->GetInitPz() << G4endl;
                G4cout << ": \t IniX  :" << trk->GetInitX() << G4endl;
                G4cout << ": \t IniY  :" << trk->GetInitY() << G4endl;
                G4cout << ": \t IniZ  :" << trk->GetInitZ() << G4endl;
                G4cout << ": \t IniT  :" << trk->GetInitT() << G4endl;
                G4cout << ": \t ExtPx :" << trk->GetExitPx() << G4endl;
                G4cout << ": \t ExtPy :" << trk->GetExitPy() << G4endl;
                G4cout << ": \t ExtPz :" << trk->GetExitPz() << G4endl;
                G4cout << ": \t ExtX  :" << trk->GetExitX() << G4endl;
                G4cout << ": \t ExtY  :" << trk->GetExitY() << G4endl;
                G4cout << ": \t ExtZ  :" << trk->GetExitZ() << G4endl;
                G4cout << ": \t ExtT  :" << trk->GetExitT() << G4endl;
                G4cout << ": \t Length:" << trk->GetTrackLength() << G4endl;
            }

            std::vector<Int_t> stepIdx = trk->GetStepIdx();
            if (verbose)
                G4cout << ": \t-Deposits in this track : " << stepIdx.size() << " hits." << G4endl;

            for (int j = 0; j < (int)stepIdx.size(); j++)
            {
                SimDeposit *dep = dynamic_cast<SimDeposit *>(depMap1->GetValue(Form("%d", stepIdx[j])));
                if (verbose > 1)
                {
                    G4cout << ": \t----hit  : " << j << G4endl;
                    G4cout << ": \t  PdgID  : " << dep->GetPDGID() << G4endl;
                    G4cout << ": \t  TrkID  : " << dep->GetTrackID() << G4endl;
                    G4cout << ": \t  ProdID : " << dep->GetProducerID() << G4endl;
                    G4cout << ": \t  IniPx  : " << dep->GetPrePx() << G4endl;
                    G4cout << ": \t  IniPy  : " << dep->GetPrePy() << G4endl;
                    G4cout << ": \t  IniPz  : " << dep->GetPrePz() << G4endl;
                    G4cout << ": \t  IniX   : " << dep->GetPreX() << G4endl;
                    G4cout << ": \t  IniY   : " << dep->GetPreY() << G4endl;
                    G4cout << ": \t  IniZ   : " << dep->GetPreZ() << G4endl;
                    G4cout << ": \t  IniT   : " << dep->GetPreT() << G4endl;
                    G4cout << ": \t  ExtPx  : " << dep->GetPostPx() << G4endl;
                    G4cout << ": \t  ExtPy  : " << dep->GetPostPy() << G4endl;
                    G4cout << ": \t  ExtPz  : " << dep->GetPostPz() << G4endl;
                    G4cout << ": \t  ExtX   : " << dep->GetPostX() << G4endl;
                    G4cout << ": \t  ExtY   : " << dep->GetPostY() << G4endl;
                    G4cout << ": \t  ExtZ   : " << dep->GetPostZ() << G4endl;
                    G4cout << ": \t  ExtT   : " << dep->GetPostT() << G4endl;
                    G4cout << ": \t  Edep   : " << dep->GetEdep() << G4endl;
                    G4cout << ": \t  Length : " << dep->GetStepLength() << G4endl;
                }
                fhitXY->Fill(dep->GetPostX(), dep->GetPostY(), dep->GetEdep() * conFac);
				//if (j == 0)  initPosZ = dep->GetPostZ();
				//fAllXYZ->Fill(dep->GetPostX(), dep->GetPostY(), dep->GetPostZ()-initPosZ, dep->GetEdep() * conFac);
				//fCounts++;
				//G4cout<<"see this edep "<<fCounts<<" "<<dep->GetEdep()<<G4endl;
                //fhitXZ->Fill(dep->GetPostX(), dep->GetPostZ(), dep->GetEdep() * conFac);
                //fhitYZ->Fill(dep->GetPostY(), dep->GetPostZ(), dep->GetEdep() * conFac);
            }
        }

        SmearingGaus(fhitXY, fSmearXY, spaRes);

        for (int _i = 0; _i < NX; _i++)
            for (int _j = 0; _j < NY; _j++)
            {
                data[_i][_j] = (unsigned short)(fSmearXY->GetBinContent(_i + 1, _j + 1));
            }

        ofSignal.write((char *)(&data), sizeof(data));
    }
    
	//G4cout<<"=== "<<effectCounts<<G4endl;
    ofSignal.close();

    fRootFp->Close();

	/*std::ofstream outf;
	outf.open("num.txt",std::ios::app);  //数据储存文件	
	int numEntirelyAbsorb = fIEnergy->GetMaximumBin();
	entirelyAbsorb = fIEnergy->GetBinContent(numEntirelyAbsorb);
	outf<<serchEnergy<<" ";
	outf<<entirelyAbsorb/1000000<<" ";
	outf<<rates/1000000<<std::endl;  //注意analysismanager的输出条件 */
    c1->cd(1);
    fVXY->Draw("colz");
	//double yyy = fVXY->GetRMS(1);
	//double yyyz = fVXY->GetRMS(2);
	//G4cout<<"---- "<<yyy<<" "<<yyyz<<G4endl;
    c1->cd(2);
    fVXZ->Draw("colz");
    c1->cd(3);
    fVYZ->Draw("colz");
    c1->cd(4);
    fmomp->Draw();
    c1->Modified();
    c1->Update();

	TFile outfilei2("test.root","RECREATE");
	fmomp->Write();
	outfilei2.Close();

    c2->cd();
    fhitXY->Draw("colz");
	//fStepLength->Draw();
    //fStepLength->GetXaxis()->SetTitle("mm");
    //fStepLength->GetYaxis()->SetTitle("counts");
    c2->Modified();
    c2->Update();

    c3->cd();
    fSmearXY->Draw("colz");
    c3->Modified();
    c3->Update();

    c4->cd(1);
    fIEnergy->Draw();
    fIEnergy->GetXaxis()->SetTitle("keV");
    fIEnergy->GetYaxis()->SetTitle("counts");
	c4->cd(2);
	fBeEnergy->Draw();
    fBeEnergy->GetXaxis()->SetTitle("keV");
    fBeEnergy->GetYaxis()->SetTitle("counts");
	c4->cd(3);
	fStepLength->Draw();
    fStepLength->GetXaxis()->SetTitle("mm");
    fStepLength->GetYaxis()->SetTitle("counts");
	c4->cd(4);
	//fNumCrossBe->Draw();
	fProject->Draw();
	fProject->GetXaxis()->SetTitle("mm");
    fProject->GetYaxis()->SetTitle("counts");
    c4->Modified();
    c4->Update();

    c5->cd(1);
    fmomXY->Draw();
    fmomXY->GetXaxis()->SetTitle("rad");
    fmomXY->GetYaxis()->SetTitle("counts");
    c5->cd(2);
    fmomYZ->Draw();
    fmomYZ->GetXaxis()->SetTitle("rad");
    fmomYZ->GetYaxis()->SetTitle("counts");
    c5->cd(3);
    fmomXZ->Draw();
    fmomXZ->GetXaxis()->SetTitle("rad");
    fmomXZ->GetYaxis()->SetTitle("counts");
    c5->Modified();
    c5->Update();
	
	/*c6->cd();
	fAllXYZ->Draw("lego");
	fAllXYZ->GetXaxis()->SetTitle("X");
	fAllXYZ->GetYaxis()->SetTitle("Y");
	fAllXYZ->GetZaxis()->SetTitle("Z");*/
	//pm3d1->SetMarkerSize(2);
	//pm3d1->SetMarkerColor(4);
	//pm3d1->SetMarkerStyle(2);
	//pm3d1->Draw();
	/*for (int i = 0; i < rates; i++){
		
		pl3d[i]->SetLineWidth(2);
		pl3d[i]->SetLineColor(4);
		pl3d[i]->Draw();
		}*/
	
    //TString sss1 = fFileName + TString(".jpg");
    //c2->SaveAs(sss1);
}
