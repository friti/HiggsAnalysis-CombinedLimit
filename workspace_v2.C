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

  TH1F*  mu_th1 = (TH1F*)fIn->Get("mu");
  RooDataHist mu_hist("mc_mu_CR","Mu observed",vars,mu_th1);
  wspace.import(mu_hist);

  
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
  

  TH1F*  tau_th1 = (TH1F*)fIn->Get("tau");
  RooDataHist tau_hist("mc_tau_CR","tau observed",vars,tau_th1);
  wspace.import(tau_hist);

  TH1F*  chic0_th1 = (TH1F*)fIn->Get("chic0");
  RooDataHist chic0_hist("chic0_CR","tau observed",vars,chic0_th1);
  wspace.import(chic0_hist);

  TH1F*  chic1_th1 = (TH1F*)fIn->Get("chic1");
  RooDataHist chic1_hist("chic1_CR","tau observed",vars,chic1_th1);
  wspace.import(chic1_hist);

  TH1F*  chic2_th1 = (TH1F*)fIn->Get("chic2");
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



  TH1F*  comb_th1 = (TH1F*)fIn->Get("comb");
  RooDataHist comb_hist("mc_comb_CR","Comb observed",vars,comb_th1);
  wspace.import(comb_hist);

  


  TH1F*  misid_th1 = (TH1F*)fIn->Get("mis_id");
  RooRealVar bin1("misid_CR_bin1","Background yield in control region, bin 1",misid_th1->GetBinContent(1),0,data_th1->GetBinContent(1));
  RooRealVar bin2("misid_CR_bin2","Background yield in control region, bin 2",misid_th1->GetBinContent(2),0,data_th1->GetBinContent(2));
  RooRealVar bin3("misid_CR_bin3","Background yield in control region, bin 3",misid_th1->GetBinContent(3),0,data_th1->GetBinContent(3));
  RooRealVar bin4("misid_CR_bin4","Background yield in control region, bin 4",misid_th1->GetBinContent(4),0,data_th1->GetBinContent(4));
  RooRealVar bin5("misid_CR_bin5","Background yield in control region, bin 5",misid_th1->GetBinContent(5),0,data_th1->GetBinContent(5));
  RooRealVar bin6("misid_CR_bin6","Background yield in control region, bin 6",misid_th1->GetBinContent(6),0,data_th1->GetBinContent(6));
  RooRealVar bin7("misid_CR_bin7","Background yield in control region, bin 7",misid_th1->GetBinContent(7),0,data_th1->GetBinContent(7));
  RooRealVar bin8("misid_CR_bin8","Background yield in control region, bin 8",misid_th1->GetBinContent(8),0,data_th1->GetBinContent(8));
  RooRealVar bin9("misid_CR_bin9","Background yield in control region, bin 9",misid_th1->GetBinContent(9),0,data_th1->GetBinContent(9));
  RooRealVar bin10("misid_CR_bin10","Background yield in control region, bin 10",misid_th1->GetBinContent(10),0,data_th1->GetBinContent(10));
  RooRealVar bin11("misid_CR_bin11","Background yield in control region, bin 11",misid_th1->GetBinContent(11),0,data_th1->GetBinContent(11));
  RooRealVar bin12("misid_CR_bin12","Background yield in control region, bin 12",misid_th1->GetBinContent(12),0,data_th1->GetBinContent(12));
  RooRealVar bin13("misid_CR_bin13","Background yield in control region, bin 13",misid_th1->GetBinContent(13),0,data_th1->GetBinContent(13));
  RooRealVar bin14("misid_CR_bin14","Background yield in control region, bin 14",misid_th1->GetBinContent(14),0,data_th1->GetBinContent(14));
  RooRealVar bin15("misid_CR_bin15","Background yield in control region, bin 15",misid_th1->GetBinContent(15),0,data_th1->GetBinContent(15));
  

  RooArgList bkg_CR_bins;
  bkg_CR_bins.add(bin1);
  bkg_CR_bins.add(bin2);
  bkg_CR_bins.add(bin3);
  bkg_CR_bins.add(bin4);
  bkg_CR_bins.add(bin5);
  bkg_CR_bins.add(bin6);
  bkg_CR_bins.add(bin7);
  bkg_CR_bins.add(bin8);
  bkg_CR_bins.add(bin9);
  bkg_CR_bins.add(bin10);
  bkg_CR_bins.add(bin11);
  bkg_CR_bins.add(bin12);
  bkg_CR_bins.add(bin13);
  bkg_CR_bins.add(bin14);
  bkg_CR_bins.add(bin15);

  RooParametricHist p_bkg("mis_id_CR", "Background PDF in control region",var,bkg_CR_bins,*data_th1);
  RooAddition p_bkg_norm("misid_CR_norm","Total Number of events from background in signal region",bkg_CR_bins);


  // -------------------------------------------------------------------------------------------------------------//
  // ---------------------------- SIGNAL REGION -----------------------------------------------------------------//

  TFile *fInSR = new TFile("REPLACE_FILE_PASS");

  TH1F*  data_SRth1 = (TH1F*)fInSR->Get("data_obs");
  RooDataHist data_SRhist("data_obs_SR","Data observed",vars,data_SRth1);
  wspace.import(data_SRhist);


  TH1F*  mu_SRth1 = (TH1F*)fInSR->Get("mu");
  RooDataHist mu_SRhist("mc_mu_SR","Mu observed",vars,mu_SRth1);
  wspace.import(mu_SRhist);


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
  

  TH1F*  tau_SRth1 = (TH1F*)fInSR->Get("tau");
  RooDataHist tau_SRhist("mc_tau_SR","Tau observed",vars,tau_SRth1);
  wspace.import(tau_SRhist);

  TH1F*  chic0_SRth1 = (TH1F*)fInSR->Get("chic0");
  RooDataHist chic0_SRhist("chic0_SR","tau observed",vars,chic0_SRth1);
  wspace.import(chic0_SRhist);

  TH1F*  chic1_SRth1 = (TH1F*)fInSR->Get("chic1");
  RooDataHist chic1_SRhist("chic1_SR","tau observed",vars,chic1_SRth1);
  wspace.import(chic1_SRhist);

  TH1F*  chic2_SRth1 = (TH1F*)fInSR->Get("chic2");
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


  TH1F*  comb_SRth1 = (TH1F*)fInSR->Get("comb");
  RooDataHist comb_SRhist("mc_comb_SR","Comb observed",vars,comb_SRth1);
  wspace.import(comb_SRhist);


  RooRealVar TF("TF","Transfer factor",REPLACE_FR/(1-REPLACE_FR)); 
  TF.setConstant(); 


  RooFormulaVar SRbin1("misid_SR_bin1","Background yield in control region, bin 1"," @0*@1",RooArgList(TF,bin1));
  RooFormulaVar SRbin2("misid_SR_bin2","Background yield in control region, bin 2","@0*@1",RooArgList(TF,bin2));
  RooFormulaVar SRbin3("misid_SR_bin3","Background yield in control region, bin 3","@0*@1",RooArgList(TF,bin3));
  RooFormulaVar SRbin4("misid_SR_bin4","Background yield in control region, bin 4","@0*@1",RooArgList(TF,bin4));
  RooFormulaVar SRbin5("misid_SR_bin5","Background yield in control region, bin 5","@0*@1",RooArgList(TF,bin5));
  RooFormulaVar SRbin6("misid_SR_bin6","Background yield in control region, bin 6","@0*@1",RooArgList(TF,bin6));
  RooFormulaVar SRbin7("misid_SR_bin7","Background yield in control region, bin 7","@0*@1",RooArgList(TF,bin7));
  RooFormulaVar SRbin8("misid_SR_bin8","Background yield in control region, bin 8","@0*@1",RooArgList(TF,bin8));
  RooFormulaVar SRbin9("misid_SR_bin9","Background yield in control region, bin 9","@0*@1",RooArgList(TF,bin9));
  RooFormulaVar SRbin10("misid_SR_bin10","Background yield in control region, bin 10","@0*@1",RooArgList(TF,bin10));
  RooFormulaVar SRbin11("misid_SR_bin11","Background yield in control region, bin 11","@0*@1",RooArgList(TF,bin11));
  RooFormulaVar SRbin12("misid_SR_bin12","Background yield in control region, bin 12","@0*@1",RooArgList(TF,bin12));
  RooFormulaVar SRbin13("misid_SR_bin13","Background yield in control region, bin 13","@0*@1",RooArgList(TF,bin13));
  RooFormulaVar SRbin14("misid_SR_bin14","Background yield in control region, bin 14","@0*@1",RooArgList(TF,bin14));
  RooFormulaVar SRbin15("misid_SR_bin15","Background yield in control region, bin 15","@0*@1",RooArgList(TF,bin15));

  RooArgList bkg_SR_bins;
  bkg_SR_bins.add(SRbin1);
  bkg_SR_bins.add(SRbin2);
  bkg_SR_bins.add(SRbin3);
  bkg_SR_bins.add(SRbin4);
  bkg_SR_bins.add(SRbin5);
  bkg_SR_bins.add(SRbin6);
  bkg_SR_bins.add(SRbin7);
  bkg_SR_bins.add(SRbin8);
  bkg_SR_bins.add(SRbin9);
  bkg_SR_bins.add(SRbin10);
  bkg_SR_bins.add(SRbin11);
  bkg_SR_bins.add(SRbin12);
  bkg_SR_bins.add(SRbin13);
  bkg_SR_bins.add(SRbin14);
  bkg_SR_bins.add(SRbin15);

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
