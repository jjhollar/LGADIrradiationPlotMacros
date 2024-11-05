void BeamSpotGaussianTwoD()
{
  TH2F *h2 = new TH2F("h2","h2",250,-20,20,250,-20,20);

  /* JH plots from final IRRAD BPM data, sum of histograms */
  /*
    5E15
 FCN=633.876 FROM MIGRAD    STATUS=CONVERGED      72 CALLS          73 TOTAL
                     EDM=1.98871e-10    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     2.21570e+04   1.33392e+02   1.29432e+00   7.24230e-08
   2  Mean        -3.52873e-01   1.77344e-02   2.09934e-04   1.05255e-03
   3  Sigma        3.59292e+00   1.32951e-02   1.12976e-05  -2.75673e-03
 FCN=723.272 FROM MIGRAD    STATUS=CONVERGED      56 CALLS          57 TOTAL
                     EDM=1.16233e-06    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     2.04116e+04   1.34466e+02   1.30476e+00  -1.02706e-05
   2  Mean         1.15827e-01   1.80827e-02   2.37596e-04  -6.13642e-02
   3  Sigma        3.71614e+00   1.65081e-02   1.39492e-05  -4.96977e-01
 FCN=892.189 FROM MIGRAD    STATUS=CONVERGED      66 CALLS          67 TOTAL
                     EDM=9.54347e-09    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     2.46548e+04   1.38855e+02   1.59650e+00   3.58923e-07
   2  Mean         4.98150e-01   1.72006e-02   2.39448e-04   7.64950e-03
   3  Sigma        3.69701e+00   1.28176e-02   1.23734e-05  -4.61301e-02
 FCN=839.781 FROM MIGRAD    STATUS=CONVERGED      66 CALLS          67 TOTAL
                     EDM=1.02331e-11    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     2.33993e+04   1.46142e+02   1.52088e+00   1.72974e-08
   2  Mean         2.90732e-01   1.67116e-02   2.36607e-04  -2.22944e-04
   3  Sigma        3.63920e+00   1.54087e-02   1.42377e-05   2.55748e-03
  */

  /* Buggy version in integral profiles */
  /*
    5E15
     FCN=633.876 FROM MIGRAD    STATUS=CONVERGED      72 CALLS          73 TOTAL
                     EDM=1.98871e-10    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     2.21570e+04   1.33392e+02   1.29432e+00   7.24230e-08
   2  Mean        -3.52873e-01   1.77344e-02   2.09934e-04   1.05255e-03
   3  Sigma        3.59292e+00   1.32951e-02   1.12976e-05  -2.75673e-03
 FCN=723.272 FROM MIGRAD    STATUS=CONVERGED      56 CALLS          57 TOTAL
                     EDM=1.16233e-06    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     2.04116e+04   1.34466e+02   1.30476e+00  -1.02706e-05
   2  Mean         1.15827e-01   1.80827e-02   2.37596e-04  -6.13642e-02
   3  Sigma        3.71614e+00   1.65081e-02   1.39492e-05  -4.96977e-01

   1E16
 FCN=11898 FROM MIGRAD    STATUS=CONVERGED      70 CALLS          71 TOTAL
                     EDM=9.39763e-09    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     5.68376e+05   6.96334e+02   2.87105e+01   1.79783e-08
   2  Mean         5.08802e-01   3.34774e-03   1.76647e-04  -4.09677e-02
   3  Sigma        3.48143e+00   2.68283e-03   1.02187e-05   1.69533e-01
 FCN=22680.9 FROM MIGRAD    STATUS=CONVERGED      66 CALLS          67 TOTAL
                     EDM=3.61286e-11    STRATEGY= 1      ERROR MATRIX ACCURATE 
  EXT PARAMETER                                   STEP         FIRST   
  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
   1  Constant     5.38046e+05   6.66013e+02   3.61411e+01  -5.32167e-09
   2  Mean        -5.59809e-02   3.64108e-03   2.67746e-04  -2.04124e-03
   3  Sigma        3.97038e+00   3.30393e-03   1.46272e-05   2.72031e-03
  */

  // 1E16 profile
  float meanx = 4.98150e-01;
  float sigmax = 3.69701e+00;
  float meany = 2.90732e-01;
  float sigmay = 3.63920e+00;
  // 5E15 profile
  //  float meanx = -3.52873e-01;
  //  float sigmax = 3.59292e+00;
  //  float meany = 1.15827e-01;
  //  float sigmay = 3.71614e+00;

  /* Sima plots - average by eye */
  /*
  float meanx = -0.3;                                                                                                                                                               
  float sigmax = 2.5;                                                                                                                                                              
  float meany = 0.1;                                                                                                                                                               
  float sigmay = 2.5;                                                                                                                                                              
  */

  /* BPM  snapshot #2
  float meanx = 0.03;
  float sigmax = 4.47;
  float meany = 0.41;
  float sigmay = 3.86;
  */

  /* BPM2, July 19 */
  /*
  float meanx = 0.81;                                                        
  float sigmax = 3.96;                                                        
  float meany = 0.29;                                                      
  float sigmay = 4.03;                                                        
  */

  TRandom rnd;

  for(Int_t x = 0; x < 100000000; x++)
    {
      float spotx = 0;
      float spoty = 0;

      spotx = rnd.Gaus(meanx,sigmax);
      spoty = rnd.Gaus(meany,sigmay);
      
      h2->Fill(spotx,spoty);
    }

  TCanvas *c1 = new TCanvas("c1","c1",600,600);

  // JH, Nov. 4
  h2->Sumw2();
  h2->Scale(1.0/h2->GetMaximum());
  
  h2->SetStats(0); 
  h2->SetTitle("Sensor position relative to beamspot"); 
  h2->SetXTitle("x");
  h2->SetYTitle("y");
  h2->Draw("col");

  float shift = 1.0;
  float xlow = -0.65+shift;
  float xhigh = (5*1.3+shift)-0.65;
  float ylow = -0.65+shift;
  float yhigh = (5*1.3+shift)-0.65;

  TLine *linesx[16], *linesy[16];

  for(Int_t xl=0; xl < 5; xl++)
    {
      linesx[xl] = new TLine(xlow+(xl*1.3),ylow,xlow+(xl*1.3),yhigh);
      linesx[xl]->SetLineWidth(3); linesx[xl] ->SetLineColor(6);
      linesx[xl]->Draw("same");
    }
  for(Int_t yl=0; yl < 5; yl++)
    {
      linesx[yl] = new TLine(xlow,ylow+(yl*1.3),xhigh,ylow+(yl*1.3));
      linesx[yl]->SetLineWidth(3); linesx[yl] ->SetLineColor(6);
      linesx[yl]->Draw("same");
    }


  TBox *b1 = new TBox(xlow,ylow,xhigh,yhigh);
  b1->SetLineColor(6); b1->SetLineWidth(3); b1->SetFillColor(0); b1->SetFillStyle(0);
  b1->Draw("same");

  TBox *b6 = new TBox(-2.5,-2.5,2.5,2.5);
  b6->SetLineColor(6); b6->SetLineWidth(3); b6->SetFillColor(0); b6->SetFillStyle(0);
  //  b6->Draw("same");

  float foil1 = h2->Integral(h2->GetXaxis()->FindBin(-2.5),h2->GetXaxis()->FindBin(2.5),h2->GetYaxis()->FindBin(-2.5),h2->GetYaxis()->FindBin(2.5));
  float foil2 = h2->Integral(h2->GetXaxis()->FindBin(xlow),h2->GetXaxis()->FindBin(xlow+6.5),h2->GetYaxis()->FindBin(ylow),h2->GetYaxis()->FindBin(ylow+6.5));

  float maxrad = h2->Integral(h2->GetXaxis()->FindBin(xlow),h2->GetXaxis()->FindBin(xlow+1.3),h2->GetYaxis()->FindBin(ylow),h2->GetYaxis()->FindBin(ylow+1.3));
  float minrad = h2->Integral(h2->GetXaxis()->FindBin(xhigh-1.3),h2->GetXaxis()->FindBin(xhigh),h2->GetYaxis()->FindBin(yhigh-1.3),h2->GetYaxis()->FindBin(yhigh));
  float peakrad = h2->Integral(h2->GetXaxis()->FindBin(-0.65),h2->GetXaxis()->FindBin(-0.65+1.3),h2->GetYaxis()->FindBin(-0.65),h2->GetYaxis()->FindBin(-0.65+1.3));
  //  float rad3 = h2->Integral(h2->GetXaxis()->FindBin(xlow),h2->GetXaxis()->FindBin(xlow+1.3),h2->GetYaxis()->FindBin(yhigh-1.3),h2->GetYaxis()->FindBin(yhigh));
  //  float rad4 = h2->Integral(h2->GetXaxis()->FindBin(xhigh-1.3),h2->GetXaxis()->FindBin(xhigh),h2->GetYaxis()->FindBin(ylow),h2->GetYaxis()->FindBin(ylow+1.3));
  float federicorad = h2->Integral(h2->GetXaxis()->FindBin(-2.5),h2->GetXaxis()->FindBin(2.5),h2->GetYaxis()->FindBin(-2.5),h2->GetYaxis()->FindBin(2.5));
  std::cout << "Peak (1.3*1.3 at 0,0) = " << peakrad << std::endl;
  std::cout << "Max pixel rad (1.3*1.3) = " << maxrad << ", Min pixel rad (1.3*1.3)" << minrad << std::endl; //", " << rad3 << ", " << rad4 << std::endl;
  //  std::cout << federicorad << " (Federico)" << std::endl;
  std::cout << "Foil1 (5*5) = " << foil1 << std::endl;
  std::cout << "Foil2 (7*7) = " << foil2 << std::endl;
  std::cout << "All bins" << std::endl;

  std::cout << "Foil1 cm-2 = " << foil1 * (10*10) / (5*5) << std::endl;
  std::cout << "Max pixel cm-2 = " << maxrad * (10*10) / (1.3*1.3) << std::endl;
  std::cout << "Foil2 cm-2 = " << foil2 * (10*10) / (7*7) << std::endl;

  TH2F *hradprof = new TH2F("hradprof","hradprof",5,0,6.5,5,0,6.5);

  for(Int_t xpix = 0; xpix < 5; xpix++)
    {
      for(Int_t ypix = 0; ypix < 5; ypix++)
	{
	  float binrad = h2->Integral(h2->GetXaxis()->FindBin(xlow+(xpix*1.3)),h2->GetXaxis()->FindBin(xlow+(xpix*1.3)+1.3),h2->GetYaxis()->FindBin(ylow+(ypix*1.3)),h2->GetYaxis()->FindBin(ylow+(ypix*1.3)+1.3));
	  std::cout << "\t" << xpix << ", " << ypix << " = " << binrad << std::endl;

	  hradprof->SetBinContent(xpix+1,ypix+1,binrad/maxrad);
	}
    }
  TCanvas *c2 = new TCanvas("c2","c2",600,600);
  hradprof->SetXTitle("LGAD pixel [X]");
  hradprof->SetYTitle("LGAD pixel [Y]");
  hradprof->SetStats(0);
  hradprof->SetTitle("Pixel dose/Maximum pixel dose");
  hradprof->Draw("colztext");

  TBox *pix1 = new TBox(0,0,1.3,1.3); 
  pix1->SetLineWidth(3); pix1->SetLineColor(2); pix1->SetLineStyle(2); pix1->SetFillStyle(0); pix1->Draw("same");
  TBox *pix2 = new TBox(2.6,2.6,3.9,3.9);
  pix2->SetLineWidth(3); pix2->SetLineColor(2); pix2->SetLineStyle(2); pix2->SetFillStyle(0); pix2->Draw("same");
  TBox *pix3 = new TBox(5.2,5.2,6.5,6.5);
  pix3->SetLineWidth(3); pix3->SetLineColor(2); pix3->SetLineStyle(2); pix3->SetFillStyle(0); pix3->Draw("same");


  //Foil1 cm-2 = 1.04906e+08
  //Max pixel cm-2 = 1.38832e+08
  //Foil2 cm-2 = 4.49419e+07
  //Foil1 cm-2 = 1.06196e+08
  //Max pixel cm-2 = 1.30036e+08
  //Foil2 cm-2 = 3.65548e+07
  

  TH1F *hfoil = new TH1F("hfoil","hfoil",2,0,2);
  hfoil->SetBinContent(1,(1.15)/(5.15));
  hfoil->SetBinError(1,0.0221);
  hfoil->SetBinContent(2,(1.15+1.49)/(5.15+5.97));
  hfoil->SetBinError(2,0.0167);
  hfoil->SetLineColor(1); hfoil->SetLineWidth(2); hfoil->SetMarkerStyle(20); hfoil->SetMarkerColor(1);

  TH1F *hbpm = new TH1F("hbpm","hbpm",2,0,2);
  hbpm->SetBinContent(2,4.49419/ 10.4906);
  hbpm->SetBinContent(1,3.65548/10.6196);
  hbpm->SetLineColor(2); hbpm->SetLineWidth(2);

  TCanvas *c3 = new TCanvas("c3","c3",600,600);
  hbpm->SetMaximum(1.0); hbpm->SetMinimum(0);
  hbpm->SetYTitle("Ratio of dose (sensor center/beam center)");
  hbpm->GetXaxis()->SetBinLabel(1,"5E15");
  hbpm->GetXaxis()->SetBinLabel(2,"1E16");
  hbpm->SetStats(0);
  hbpm->SetTitle(0);
  hbpm->Draw("hist");
  hfoil->Draw("Esame");

  TLegend *lx = new TLegend(0.4,0.6,0.9,0.9);
  lx->AddEntry(hfoil,"From foil measurements");
  lx->AddEntry(hbpm,"From BPM measurements");
  lx->Draw("same");
  
}
