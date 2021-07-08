#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include <unistd.h>
#include <stdio.h>
#include "iostream"
#include "TH2F.h"
#include "TCanvas.h"
#include "Riostream.h"
#include "TGraph.h"
#include "TSpectrum.h"


using namespace RooFit;
using namespace std;

const int NX = 72;
const int NY = 72;

const double spaRes = 0.05;   //default: 0.07 min:0.02
const double lenPit = 0.08;

TCanvas *c1 = new TCanvas("c1", "c1", 720, 720);
TH2D *fSmearXY = new TH2D("fSmearXY", "fSmearXY", NX, 0, 71, NY, 0, 71);

void read()
{
    const int nXpixel = 72;
    const int nYpixel = 72;
    int x,y,x2[72],y2[72];
    unsigned short z[72*72];
    int mx,my;
    unsigned short data,gg,ldata[72][72];

   ifstream infileSig("mcsim.data", ios::binary);
    if (!infileSig){
       cout<<"Can not open file"<<endl;
       return;
    }
       cout<<"==>Reading "<<endl;
    int ji=0;  
    while(infileSig.good())
    {
         mx= ji*1000 +1;
         my= (ji+1)*1000;
         char mdatName[100];
         sprintf(&mdatName[0],"%d-%dframe.data",mx,my);	  
        ofstream oftest(mdatName, ios::binary);
        for (int k=0; k<1000; k++)
        {
            fSmearXY->Reset();
            memset(z,0,sizeof(z));
            for ( int l=0; l<(nXpixel*nYpixel); l++)
            {
            infileSig.read((char *)(&data), sizeof(data));
            x2[l/72]=l/72;
            y2[l%72]=l%72;
            z[l]=data;
            }
            for ( int m=0; m<(nXpixel*nYpixel); m++)
            {
            fSmearXY->Fill(m/72,m%72,z[m]);
            }
            c1->cd();
            fSmearXY->Draw("colz");
            if(k<50) 
            {
            c1->SaveAs(Form("c%d.png",k));
            }
	    }
       ji = ji+1;    
    }
}
