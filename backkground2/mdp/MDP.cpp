#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TF1.h>
#include <TRandom3.h>
#include <TString.h>
#include <TVector3.h>
#include <iostream>
#include <fstream>

using namespace std;




Double_t myfunction(Double_t *x, Double_t *par)
{
   Float_t T =x[0];
   Double_t f = 4.29/0.33/0.3077*pow((0.3077+par[0])/T, 0.5);
   return f;
}
void MDP()
{
    TCanvas *MDP = new TCanvas("MDP", "MDP",903,373,700,500);
    MDP->Range(-2500.001,-0.01799153,122500,0.2532403);
    MDP->SetFillColor(0);
    MDP->SetBorderMode(0);
    MDP->SetBorderSize(2);
    MDP->SetGridx();
    MDP->SetGridy();
    MDP->SetFrameBorderMode(0);
    MDP->SetFrameBorderMode(0);
    // TF1 *f1 = new TF1("myfunc",myfunction,0,1000000,1);
    // f1->SetParameters(0.127+0.0104,100000000000);
    // f1->SetParNames("constant");
    // f1->Draw("");

    TF1 *f2 = new TF1("myfunc",myfunction,0,1000000,1);
    f2->SetParameters(0.0615+0.0104+0.006252+0.004968+0.000471,100000000000);
    f2->SetParNames("constant");
    f2->Draw();

    TF1 *f3 = new TF1("myfunc",myfunction,0,1000000,1);
    f3->SetParameters(0.05132+0.0104+0.006252+0.004968,100000000000);
    f3->SetParNames("constant");
    f3->Draw("same");

    TF1 *f4 = new TF1("myfunc",myfunction,0,1000000,1);
    f4->SetParameters(0.0332+0.0104+0.006252,100000000000);
    f4->SetParNames("constant");
    f4->Draw("same");


    //f1->SetLineColor(6);
    f2->SetLineColor(3);
    f3->SetLineColor(4);
    f4->SetLineColor(5);

    //f1->GetXaxis()->SetTitle("T/s");
    //f1->GetYaxis()->SetTitle("MDP");


    //f1->GetYaxis()->SetRangeUser(0,1);

    TLegend *legend=new TLegend(0.5,0.5,0.8,0.8);
    //legend->AddEntry(f1,"Field of view:90");
    legend->AddEntry(f2,"Field of view:60");
    legend->AddEntry(f3,"Field of view:50");
    legend->AddEntry(f4,"Field of view:40");

    legend->Draw();
}
