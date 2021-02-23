#include "RooFitResult.h"
using namespace RooFit;
void workspace(){
  gROOT->SetBatch();
  gSystem->Load("libHiggsAnalysisCombinedLimit.so");
  RooWorkspace wspace("wspace","wspace");

  //---------------------------------------------------------------
  //-------- 3Mu channel ------------------------------------------- 
  //---------------------------------------------------------------

 
  // Output file and workspace
  TFile *fIn = new TFile("REPLACE_FILE_FAIL");
  
  TFile *fOut = new TFile("param_ws.root","RECREATE");
  
  RooRealVar var("REPLACE_VAR","REPLACE_VAR",REPLACE_XMIN,REPLACE_XMAX);

  RooArgList vars(var);
  
  // ---------------------------- CONTROL REGION -------------------------------------------------------------------//


  TH1F*  data_th1 = (TH1F*)fIn->Get("data_obs");
  RooDataHist data_hist("data_obs_CR","Data observed",vars,data_th1);
  wspace.import(data_hist);

  TH1F*  mu_th1 = (TH1F*)fIn->Get("jpsi_mu");
  RooDataHist mu_hist("mc_mu_CR","Mu observed",vars,mu_th1);
  wspace.import(mu_hist);

  /*
  TH1F*  mu_ctau_up_th1 = (TH1F*)fIn->Get("mu_ctau_UP");
  RooDataHist mu_hist_UP("mc_mu_ctauUp_CR","Mu observed",vars,mu_ctau_up_th1);
  wspace.import(mu_hist_UP);
  
  TH1F*  tau_ctau_up_th1 = (TH1F*)fIn->Get("tau_ctau_UP");
  RooDataHist tau_hist_UP("mc_tau_ctauUp_CR","Tau observed",vars,tau_ctau_up_th1);
  wspace.import(tau_hist_UP);
  
  TH1F*  mu_ctau_down_th1 = (TH1F*)fIn->Get("mu_ctau_DOWN");
  RooDataHist mu_hist_DOWN("mc_mu_ctauDown_CR","Mu observed",vars,mu_ctau_down_th1);
  wspace.import(mu_hist_DOWN);
  
  TH1F*  tau_ctau_down_th1 = (TH1F*)fIn->Get("tau_ctau_DOWN");
  RooDataHist tau_hist_DOWN("mc_tau_ctauDown_CR","Mu observed",vars,tau_ctau_down_th1);
  wspace.import(tau_hist_DOWN);
  */

  TH1F*  tau_th1 = (TH1F*)fIn->Get("jpsi_tau");
  RooDataHist tau_hist("mc_tau_CR","tau observed",vars,tau_th1);
  wspace.import(tau_hist);

  TH1F*  chic0_th1 = (TH1F*)fIn->Get("chic0_mu");
  RooDataHist chic0_hist("chic0_CR","tau observed",vars,chic0_th1);
  wspace.import(chic0_hist);

  TH1F*  chic1_th1 = (TH1F*)fIn->Get("chic1_mu");
  RooDataHist chic1_hist("chic1_CR","tau observed",vars,chic1_th1);
  wspace.import(chic1_hist);

  TH1F*  chic2_th1 = (TH1F*)fIn->Get("chic2_mu");
  RooDataHist chic2_hist("chic2_CR","tau observed",vars,chic2_th1);
  wspace.import(chic2_hist);

  TH1F*  hc_mu_th1 = (TH1F*)fIn->Get("hc_mu");
  RooDataHist hc_mu_hist("hc_mu_CR","tau observed",vars,hc_mu_th1);
  wspace.import(hc_mu_hist);

  TH1F*  jpsi_hc_th1 = (TH1F*)fIn->Get("jpsi_hc");
  RooDataHist jpsi_hc_hist("jpsi_hc_CR","tau observed",vars,jpsi_hc_th1);
  wspace.import(jpsi_hc_hist);

  TH1F*  psi2s_mu_th1 = (TH1F*)fIn->Get("psi2s_mu");
  RooDataHist psi2s_mu_hist("psi2s_mu_CR","tau observed",vars,psi2s_mu_th1);
  wspace.import(psi2s_mu_hist);

  TH1F*  psi2s_tau_th1 = (TH1F*)fIn->Get("psi2s_tau");
  RooDataHist psi2s_tau_hist("psi2s_tau_CR","tau observed",vars,psi2s_tau_th1);
  wspace.import(psi2s_tau_hist);



  TH1F*  comb_th1 = (TH1F*)fIn->Get("onia");
  RooDataHist comb_hist("mc_comb_CR","Comb observed",vars,comb_th1);
  wspace.import(comb_hist);

  


  TH1F*  misid_th1 = (TH1F*)fIn->Get("fakes");
  std::vector<RooRealVar> bins; 
  for(int i=1; i<=data_th1->GetNbinsX(); i++){
    stringstream s;
    s << i;
    string mystring1 = "misid_CR_bin" + s.str();
    string mystring2 = "Background yield in control region, bin " + s.str();
    RooRealVar bin(mystring1.c_str(),mystring2.c_str(),misid_th1->GetBinContent(i),0,data_th1->GetBinContent(i));
    
    bins.push_back(bin);
  }
    
  RooArgList bkg_CR_bins;
  for(int i=0; i<data_th1->GetNbinsX(); i++){
    bkg_CR_bins.add(bins[i]);
  }


  RooParametricHist p_bkg("mis_id_CR", "Background PDF in control region",var,bkg_CR_bins,*data_th1);
  RooAddition p_bkg_norm("misid_CR_norm","Total Number of events from background in signal region",bkg_CR_bins);


  // -------------------------------------------------------------------------------------------------------------//
  // ---------------------------- SIGNAL REGION -----------------------------------------------------------------//

  TFile *fInSR = new TFile("REPLACE_FILE_PASS");

  TH1F*  data_SRth1 = (TH1F*)fInSR->Get("data_obs");
  RooDataHist data_SRhist("data_obs_SR","Data observed",vars,data_SRth1);
  wspace.import(data_SRhist);


  TH1F*  mu_SRth1 = (TH1F*)fInSR->Get("jpsi_mu");
  RooDataHist mu_SRhist("mc_mu_SR","Mu observed",vars,mu_SRth1);
  wspace.import(mu_SRhist);

  /*
  TH1F*  tau_ctau_up_SRth1 = (TH1F*)fInSR->Get("tau_ctau_UP");
  RooDataHist tau_histSR_UP("mc_tau_ctauUp_SR","Tau observed",vars,tau_ctau_up_SRth1);
  wspace.import(tau_histSR_UP);
  

  
  TH1F*  mu_ctau_up_SRth1 = (TH1F*)fInSR->Get("mu_ctau_UP");
  RooDataHist mu_histSR_UP("mc_mu_ctauUp_SR","Mu observed",vars,mu_ctau_up_SRth1);
  wspace.import(mu_histSR_UP);


  TH1F*  mu_ctau_down_SRth1 = (TH1F*)fInSR->Get("mu_ctau_DOWN");
  RooDataHist mu_histSR_DOWN("mc_mu_ctauDown_SR","Mu observed",vars,mu_ctau_down_SRth1);
  wspace.import(mu_histSR_DOWN);

  TH1F*  tau_ctau_down_SRth1 = (TH1F*)fInSR->Get("tau_ctau_DOWN");
  RooDataHist tau_histSR_DOWN("mc_tau_ctauDown_SR","Tau observed",vars,tau_ctau_down_SRth1);
  wspace.import(tau_histSR_DOWN);
  */

  TH1F*  tau_SRth1 = (TH1F*)fInSR->Get("jpsi_tau");
  RooDataHist tau_SRhist("mc_tau_SR","Tau observed",vars,tau_SRth1);
  wspace.import(tau_SRhist);

  TH1F*  chic0_SRth1 = (TH1F*)fInSR->Get("chic0_mu");
  RooDataHist chic0_SRhist("chic0_SR","tau observed",vars,chic0_SRth1);
  wspace.import(chic0_SRhist);

  TH1F*  chic1_SRth1 = (TH1F*)fInSR->Get("chic1_mu");
  RooDataHist chic1_SRhist("chic1_SR","tau observed",vars,chic1_SRth1);
  wspace.import(chic1_SRhist);

  TH1F*  chic2_SRth1 = (TH1F*)fInSR->Get("chic2_mu");
  RooDataHist chic2_SRhist("chic2_SR","tau observed",vars,chic2_SRth1);
  wspace.import(chic2_SRhist);

  TH1F*  hc_mu_SRth1 = (TH1F*)fInSR->Get("hc_mu");
  RooDataHist hc_mu_SRhist("hc_mu_SR","tau observed",vars,hc_mu_SRth1);
  wspace.import(hc_mu_SRhist);

  TH1F*  jpsi_hc_SRth1 = (TH1F*)fInSR->Get("jpsi_hc");
  RooDataHist jpsi_hc_SRhist("jpsi_hc_SR","tau observed",vars,jpsi_hc_SRth1);
  wspace.import(jpsi_hc_SRhist);

  TH1F*  psi2s_mu_SRth1 = (TH1F*)fInSR->Get("psi2s_mu");
  RooDataHist psi2s_mu_SRhist("psi2s_mu_SR","tau observed",vars,psi2s_mu_SRth1);
  wspace.import(psi2s_mu_SRhist);

  TH1F*  psi2s_tau_SRth1 = (TH1F*)fInSR->Get("psi2s_tau");
  RooDataHist psi2s_tau_SRhist("psi2s_tau_SR","tau observed",vars,psi2s_tau_SRth1);
  wspace.import(psi2s_tau_SRhist);


  TH1F*  comb_SRth1 = (TH1F*)fInSR->Get("onia");
  RooDataHist comb_SRhist("mc_comb_SR","Comb observed",vars,comb_SRth1);
  wspace.import(comb_SRhist);


  RooRealVar TF("TF","Transfer factor",REPLACE_FR/(1-REPLACE_FR)); 
  TF.setConstant(); 


  std::vector<RooFormulaVar> bins_SR; 
  for(int i=1; i<=data_th1->GetNbinsX(); i++){
    stringstream s;
    s << i;
    string mystring1 = "misid_SR_bin" + s.str();
    string mystring2 = "Background yield in signal region, bin " + s.str();

    RooFormulaVar bin(mystring1.c_str(),mystring2.c_str()," @0*@1",RooArgList(TF,bins[i-1]));
    bins_SR.push_back(bin);
  }

  RooArgList bkg_SR_bins;
  for(int i=0; i<data_th1->GetNbinsX(); i++){
    bkg_SR_bins.add(bins_SR[i]);
  }

  RooParametricHist p_SRbkg("mis_id_SR", "Background PDF in signal region",var,bkg_SR_bins,*data_SRth1);
  RooAddition p_SRbkg_norm("misid_SR_norm","Total Number of events from background in signal region",bkg_SR_bins);
  // -------------------------------------------------------------------------------------------------------------//

  // import the pdfs
  wspace.import(p_bkg);
  wspace.import(p_bkg_norm,RooFit::RecycleConflictNodes());
  wspace.import(p_SRbkg);
  wspace.import(p_SRbkg_norm,RooFit::RecycleConflictNodes());
  fOut->cd();
  wspace.Write();

  // Clean up
  fOut->Close();
  fOut->Delete();

}
