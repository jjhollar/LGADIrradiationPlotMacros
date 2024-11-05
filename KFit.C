void KFit()
{
  /*
    LGAD1 irradiated 1E16
13,
37,
47,

    LGAD1 non-irradiated
45,
45,
45,


    LGAD4 irradiated 1E16
11,
33,
47,


    LGAD4 non-irradiated
45,
45,
45,

    LGAD2 irradiated 5E15
21,
39,
47,
    LGAD2 non-irradiated
45,
47,
45,



    LGAD5 irradiated 5E15
27,
45,
47,
    LGAD5 non-irradiated
47,
45,
47,
    
  */

  TH2F *h2 = new TH2F("h2","h2",2,2E14,2E16,2,0,1.2);
  h2->SetStats(0);
  h2->GetXaxis()->SetTitle("#Phi [p/cm^{2}]");
  h2->GetYaxis()->SetTitle("V(FD)/V(0)");
  h2->SetTitle("Acceptor removal fraction");
  h2->Draw();
  Float_t frac1[3] = {47.0/45.0,37.0/45,13.0/45.0};
  Float_t flu1[3] = {1.1E15,5E15,1.01E16};
  TGraph *fr1 = new TGraph(3,flu1,frac1);
  fr1->SetMarkerStyle(20); fr1->SetMarkerColor(2); fr1->SetMarkerSize(1.5);
  fr1->Draw("Psame");

  Float_t frac4[3] = {47/45.0,33.0/45.0,11.0/45.0};
  Float_t flu4[3] = {1E15,5E15,0.99E16};
  TGraph *fr4 = new TGraph(3,flu4,frac4);
  //fr4->SetMarkerStyle(21);
  fr4->SetMarkerStyle(20); fr4->SetMarkerColor(4); fr4->SetMarkerSize(1.5);
  fr4->Draw("Psame");

  Float_t frac2[3] = {47/45.0,45/47.0,27/45.0};
  Float_t flu2[3] = {4.95E14,2.5E15,5E15};
  TGraph *fr2 = new TGraph(3,flu2,frac2);
  //fr2->SetMarkerStyle(22);
  fr2->SetMarkerStyle(20); fr2->SetMarkerColor(6); fr2->SetMarkerSize(1.5);
  fr2->Draw("Psame");

  Float_t frac5[3] = {50.0/47,45.0/45,30/47.0};
  Float_t flu5[3] = {5E14,2.5E15,5E15};
  TGraph *fr5 = new TGraph(3,flu5,frac5);
  //fr5->SetMarkerStyle(23);
  fr5->SetMarkerStyle(20); fr5->SetMarkerColor(3); fr5->SetMarkerSize(1.5);
  fr5->Draw("Psame");

  TF1 *cfit = new TF1("cfit","TMath::Exp(-1.0 * [0] * x)",2E14,2E16);
  cfit->SetParameter(0,1E-16);
  //  fr4->Fit(cfit);
  //  cfit->Draw("same");

  fr1->SetLineWidth(0); fr2->SetLineWidth(0); fr4->SetLineWidth(0); fr5->SetLineWidth(0);

  TLegend *l1 = new TLegend(0.12,0.12,0.6,0.6);
  l1->AddEntry(fr1,"PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, -20C");
  l1->AddEntry(fr2,"PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, -20C");
  l1->AddEntry(fr4,"PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, -20C");
  l1->AddEntry(fr5,"PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, -20C");
  l1->SetLineWidth(0);
  l1->Draw("same");

  /*
        sensorname = "PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, -20C";
      if(device == 2)
        sensorname = "PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, -20C";
      if(device == 4)
        sensorname = "PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, -20C";
      if(device == 5)
        sensorname = "PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, -20C";
  */
  
  //  cfit->Draw("same");
}
