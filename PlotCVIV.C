//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <vector>
//#include "TGraph.h"

using namespace std;

void PlotIV(Int_t style = 1, Int_t device = 1)
{
  // PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, 1E16
  // PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, 1E16
  // PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, 5E15
  // PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, 5E15

  TString sensorname;
  if(style == 1)
    {
      if(device == 1)
	sensorname = "PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, -20C";
      if(device == 2)
	sensorname = "PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, -20C";
      if(device == 4)
	sensorname = "PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, -20C";
      if(device == 5)
	sensorname = "PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, -20C";
    }
  if(style == 2)
    sensorname = "Pixel 0,0, -20C";

  TCanvas *c1 = new TCanvas("c1","c1");
  TH2F *h2; 
  if(style == 1)
    h2 = new TH2F("h2","h2",2,0,350,2,1E-13,2E-6);
  if(style == 2)
    h2 = new TH2F("h2","h2",2,0,350,2,1E-13,3E-9);
  h2->SetStats(0);
  h2->SetTitle(sensorname);
  h2->SetYTitle("I [A]");
  h2->SetXTitle("V [V]");
  h2->Draw();
  TLegend *l1;
  if(style == 1)
    l1 = new TLegend(0.6,0.1,0.9,0.4);
  if(style == 2)
    l1 = new TLegend(0.6,0.6,0.9,0.9);

  std::vector<string> filenames;

  if(style == 1)
    {
      if(device == 1)
        {
          filenames.push_back("data_00_IV_LGAD1.csv");
          filenames.push_back("data_22_IV_LGAD1.csv");
          filenames.push_back("data_44_IV_LGAD1.csv");
          filenames.push_back("data_preirrad_00_IV_LGAD1.csv");
          filenames.push_back("data_preirrad_22_IV_LGAD1.csv");
          filenames.push_back("data_preirrad_44_IV_LGAD1.csv");
        }
      if(device == 2)
	{
	  filenames.push_back("data_00_IV_LGAD2.csv");
	  filenames.push_back("data_22_IV_LGAD2.csv");
	  filenames.push_back("data_44_IV_LGAD2.csv");
	  filenames.push_back("data_preirrad_00_IV_LGAD2.csv");
	  filenames.push_back("data_preirrad_22_IV_LGAD2.csv");
	  filenames.push_back("data_preirrad_44_IV_LGAD2.csv");
	}
      if(device == 4)
	{
	  filenames.push_back("data_00_IV_LGAD4.csv");
	  filenames.push_back("data_22_IV_LGAD4.csv");
	  filenames.push_back("data_44_IV_LGAD4.csv");
	  filenames.push_back("data_preirrad_00_IV_LGAD4.csv");
	  filenames.push_back("data_preirrad_22_IV_LGAD4.csv");
	  filenames.push_back("data_preirrad_44_IV_LGAD4.csv");
	}
      if(device == 5)
	{
	  filenames.push_back("data_00_IV_LGAD5.csv");
	  filenames.push_back("data_22_IV_LGAD5.csv");
	  filenames.push_back("data_44_IV_LGAD5.csv");
	  filenames.push_back("data_preirrad_00_IV_LGAD5.csv");
	  filenames.push_back("data_preirrad_22_IV_LGAD5.csv");
	  filenames.push_back("data_preirrad_44_IV_LGAD5.csv");
	}
    }

  if(style == 2)
    {
      filenames.push_back("data_preirrad_00_IV_LGAD4.csv");                                                                                                     
      filenames.push_back("data_preirrad_00_IV_LGAD1.csv");                                                                                                        
      filenames.push_back("data_preirrad_00_IV_LGAD5.csv");                                                                                                        
      filenames.push_back("data_preirrad_00_IV_LGAD2.csv");
    }


  for(Int_t x=0; x< filenames.size(); x++)
    {
      
      fstream ifs(filenames[x], ios::in);

      string line, word;
      std::vector<string> row;
      std::vector<double> ip,v;
      //  TVectorD ip, v;

      ip.clear();
      v.clear();
      row.clear();
      
      int i = 0;
      
      if(ifs.is_open())
	{
	  while(getline(ifs,line) && i < 5000)
	    {
	      if(i > 0)
		{
		  row.clear();
		  
		  stringstream str(line);
		  
		  while(getline(str, word, ','))
		    row.push_back(word);
		  
		  std::cout << row[0] << ", " << row[2] << std::endl;
		  ip.push_back(std::stod(row[2]));
		  v.push_back(std::stod(row[0]));
		}
	      i++;
	    }
	}
      
      Int_t n = ip.size();
      TGraph *gr1 = new TGraph(n,&(v[0]),&(ip[0]));
      TString legendlabel;

      if(style == 1)
	{
	  if(x < 3)
	    {
	      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(x+1);
	      TString pix = Form("%d",2*x);
	      if(device == 4 || device == 1)
		legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 1E16 p/cm2";
	      if(device == 2 || device == 5)
		legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 5E15 p/cm2";
	      l1->AddEntry(gr1,legendlabel);
	    }
	  if(x >=3)
	    {
	      gr1->SetMarkerStyle(4); gr1->SetMarkerColor(x-3+1);
	      TString pix = Form("%d",2*(x-3));
	      legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 0 p/cm2";
	      l1->AddEntry(gr1,legendlabel);
	    }
	}

      if(style == 2)
	{
	  legendlabel = "Pixel 0,0, #Phi_{max} = 0 p/cm2";

	  if(x == 0)
	    {
	      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(4);
	      l1->AddEntry(gr1,legendlabel);                                                                                                                    
	    }
	  if(x == 1)
	    {
	      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(5);
	      l1->AddEntry(gr1,legendlabel);
	    }
	  if(x == 2)
	    {
	      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(6);
	      l1->AddEntry(gr1,legendlabel);
	    }
	  if(x == 3)
	    {
	      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(8);
	      l1->AddEntry(gr1,legendlabel);
	    }
	}
      gr1->SetLineWidth(0);
      gr1->Draw("Psame");
    }

  c1->SetLogy();
  c1->SetGridx();
  c1->SetGridy();
  l1->Draw("same");
}

void PlotCV(Int_t style = 1, Int_t device = 1)
{
  // PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, 1E16                                                                                        
  // PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, 1E16                                                                                         
  // PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, 5E15                                                                                         
  // PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, 5E15                                                                                        

  TString sensorname;
  if(style == 1)
    {
      if(device == 1)
	sensorname = "PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, 1E16";
      if(device == 2)
	sensorname = "PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, 5E15";
      if(device == 3)
	sensorname = "PPS_LGAD_03 FBK UFSD4 W18 GR3_0 T9 6-4, -20C";
      if(device == 4)
	sensorname = "PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, 1E16, -20C";
      if(device == 5)
	sensorname = "PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, 5E15";
    }

  TCanvas *c1 = new TCanvas("c1","c1");
  TH2F *h2;
  if(style == 1)
    h2 = new TH2F("h2","h2",2,0,70,2,2E-5,2);
  if(style == 2)
    h2 = new TH2F("h2","h2",2,0,150,2,1E-12,1E-8);
  h2->SetStats(0);
  h2->SetTitle(sensorname);
  h2->SetYTitle("C^{-2} [pF^{-2}]");
  h2->SetXTitle("V [V]");
  h2->Draw();
  TLegend *l1;
  if(style == 1)
    //    l1 = new TLegend(0.6,0.1,0.9,0.4);
    l1 = new TLegend(0.1,0.6,0.4,0.9);

  if(style == 2)
    l1 = new TLegend(0.6,0.6,0.9,0.9);

  std::vector<string> filenames;

  if(style == 1 && device == 1)
    {
      filenames.push_back("data_00_CV_LGAD1_100Hz-10C.csv");
      filenames.push_back("data_22_CV_LGAD1_100Hz-10C.csv");
      filenames.push_back("data_44_CV_LGAD1_100Hz-10C.csv");

      filenames.push_back("data_00_CV_LGAD1_100Hz-20C.csv");
      filenames.push_back("data_22_CV_LGAD1_100Hz-20C.csv");

      filenames.push_back("data_44_CV_LGAD1_100Hz-0C.csv");
    }
  if(style == 1 && device == 3)
    {
      filenames.push_back("data_preirrad_00_CV_LGAD3_-20C.csv");
      filenames.push_back("data_preirrad_22_CV_LGAD3_-20C.csv");
      filenames.push_back("data_preirrad_44_CV_LGAD3_-20C.csv");
    }
  if(style == 1 && device == 4)
    {
      //      filenames.push_back("data_00_CV_LGAD4_100Hz-10C.csv");
      filenames.push_back("data_00_CV_LGAD4_100Hz-20C.csv");
      filenames.push_back("data_22_CV_LGAD4_100Hz-20C.csv");
      filenames.push_back("data_44_CV_LGAD4_100Hz-20C.csv");
      filenames.push_back("data_preirrad_00_CV_LGAD4_10000Hz-20C.csv");
      filenames.push_back("data_preirrad_22_CV_LGAD4_10000Hz-20C.csv");
      filenames.push_back("data_preirrad_44_CV_LGAD4_10000Hz-20C.csv");
    }
  if(style == 1 && device == 5)
    {
      filenames.push_back("data_00_CV_LGAD5_100Hz-0C.csv");
      filenames.push_back("data_22_CV_LGAD5_100Hz-0C.csv");
      filenames.push_back("data_44_CV_LGAD5_100Hz-5C.csv");
      filenames.push_back("data_00_CV_LGAD5_100Hz-20C.csv");
    }

  for(Int_t x=0; x< filenames.size(); x++)
    {

      fstream ifs(filenames[x], ios::in);

      string line, word;
      std::vector<string> row;
      std::vector<double> c,v;
      //  TVectorD ip, v;                                                                                                                                                       

      c.clear();
      v.clear();
      row.clear();

      int i = 0;

      if(ifs.is_open())
        {
          while(getline(ifs,line) && i < 5000)
            {
              if(i > 0)
                {
                  row.clear();

                  stringstream str(line);

                  while(getline(str, word, ','))
                    row.push_back(word);

		  std::cout << row[0] << ", " << row[1] << std::endl;
		  float cinv = 1.0/((std::stod(row[1])*1E12)*(std::stod(row[1])*1E12));
                  c.push_back(cinv);
                  v.push_back(std::stod(row[0]));
                }
              i++;
            }
        }

      Int_t n = c.size();
      TGraph *gr1 = new TGraph(n,&(v[0]),&(c[0]));
      TString legendlabel;

      if(device == 1)
	{
	  if(x < 3)
	    {
	      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(x+1);
	      TString pix = Form("%d",2*x);
	      legendlabel = "Pixel " + pix + "," + pix + ", -10C";
	      l1->AddEntry(gr1,legendlabel);
	    }
	  if(x >=3 && x < 5)
	    {
	      gr1->SetMarkerStyle(4); gr1->SetMarkerColor(x-3+1);
	      TString pix = Form("%d",2*(x-3));
	      legendlabel = "Pixel " + pix + "," + pix + ", -20C";
	      l1->AddEntry(gr1,legendlabel);
	    }
	  if(x == 5)
	    {
	      gr1->SetMarkerStyle(23); gr1->SetMarkerColor(x-5+1);
	      TString pix = Form("%d",2*(x-5));
	      legendlabel = "Pixel " + pix + "," + pix + ", 0C";
	      l1->AddEntry(gr1,legendlabel);
	    }
	}
      if(device == 3)
	{
          if(x < 3)
            {
              gr1->SetMarkerStyle(4); gr1->SetMarkerColor(x+1);
              TString pix = Form("%d",2*x);
              legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 0 p/cm2";
              l1->AddEntry(gr1,legendlabel);
	    }
	}
      if(device == 4)
	{
          if(x < 3)
            {
              gr1->SetMarkerStyle(20); gr1->SetMarkerColor(x+1);
              TString pix = Form("%d",2*x);
	      legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 1E16 p/cm2";
              l1->AddEntry(gr1,legendlabel);
            }
          if(x >=3)
            {
              gr1->SetMarkerStyle(4); gr1->SetMarkerColor(x-3+1);
              TString pix = Form("%d",2*(x-3));
              legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 0 p/cm2";
              l1->AddEntry(gr1,legendlabel);
            }
	}
      if(device == 5)
	{
          if(x < 2)
            {
              gr1->SetMarkerStyle(23); gr1->SetMarkerColor(x+1);
              TString pix = Form("%d",2*x);
              legendlabel = "Pixel " + pix + "," + pix + ", -10C";
              l1->AddEntry(gr1,legendlabel);
            }
	  if(x == 2)
	    {
	      gr1->SetMarkerStyle(21); gr1->SetMarkerColor(3);
              legendlabel = "Pixel 4,4, -5C";
              l1->AddEntry(gr1,legendlabel);
	    }
	  if(x == 3)
            {
              gr1->SetMarkerStyle(4); gr1->SetMarkerColor(1);
              legendlabel = "Pixel 0,0, -20C";
              l1->AddEntry(gr1,legendlabel);
            }

	}
      gr1->SetLineWidth(0);
      gr1->Draw("Psame");
    }
     
  c1->SetLogy();
  c1->SetGridx();
  c1->SetGridy();
  l1->Draw("same");
}

void PlotOneCV(string thefile ="data_00_CV_LGAD1_100Hz-20C.csv")
{
  TString sensorname;

  TCanvas *c1 = new TCanvas("c1","c1");
  TH2F *h2;
  h2 = new TH2F("h2","h2",2,0,350,2,1E-13,2.5);

  h2->SetStats(0);
  h2->SetTitle(sensorname);

  h2->Draw();

  std::vector<string> filenames;

  filenames.push_back(thefile);

  for(Int_t x=0; x< filenames.size(); x++)
    {

      fstream ifs(filenames[x], ios::in);

      string line, word;
      std::vector<string> row;
      std::vector<double> c,v;
      //  TVectorD ip, v;                                                                                                                                                                                         
      c.clear();
      v.clear();
      row.clear();

      int i = 0;

      if(ifs.is_open())
        {
          while(getline(ifs,line) && i < 5000)
            {
              if(i > 0)
                {
                  row.clear();

                  stringstream str(line);

                  while(getline(str, word, ','))
                    row.push_back(word);

		  std::cout << row[0] << ", " << row[1] << std::endl;
                  c.push_back(std::stod(row[1]));
                  v.push_back(std::stod(row[0]));
                }
              i++;
            }
        }

      Int_t n = c.size();
      TGraph *gr1 = new TGraph(n,&(v[0]),&(c[0]));
      TString legendlabel;

      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(2);

      gr1->Draw("Psame");
    }

  c1->SetLogy();
  c1->SetGridx();
  c1->SetGridy();


}

void FitIV(Int_t device = 1, Int_t pixel = 0, Int_t rad = 0, Int_t fit = 1)
{
  // PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, 1E16                                                       
  // PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, 1E16                                                        
  // PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, 5E15                                                        
  // PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, 5E15                                                       
                                    

  TString sensorname;

  if(device == 1)
    sensorname = "PPS_LGAD_01 FBK UFSD4 W18 GR3_1 T9 6-4, -20C";
  if(device == 2)
    sensorname = "PPS_LGAD_02 FBK UFSD4 W18 GR3_1 T10 6-4, -20C";
  if(device == 4)
    sensorname = "PPS_LGAD_04 FBK UFSD4 W18 GR3_0 T10 6-4, -20C";
  if(device == 5)
    sensorname = "PPS_LGAD_05 FBK UFSD4 W18 GR3_0 T9 4-6, -20C";

  TCanvas *c2 = new TCanvas("C2","C2",400,200,400,400);
  
  TCanvas *c1 = new TCanvas("c1","c1",400,600);
  c1->Divide(1,2);
  TH2F *h2;
  h2 = new TH2F("h2","h2",2,0,350,2,1E-13,2.5);
  TH2F *h2f = new TH2F("h2f","h2f",2,0,350,2,0,0.05);
  TH2F *h2fb, *h2fc;
  if(rad == 0)
    {
      h2fb = new TH2F("h2fb","h2fb",2,0,350,2,0,0.07);
      //      h2fc = new TH2F("h2fc","h2fc",2,0,350,2,0,15);
      h2fc = new TH2F("h2fc","h2fc",2,0,150,2,0,15);
    }
  if(rad == 1)
    {
      h2fb = new TH2F("h2fb","h2fb",2,0,350,2,0,0.07);
      //      h2fc = new TH2F("h2fc","h2fc",2,0,350,2,0,15);
      h2fc = new TH2F("h2fc","h2fc",2,0,150,2,0,15);
    }

  h2->SetStats(0);
  h2->GetYaxis()->SetTitleSize(0.06);
  h2->GetXaxis()->SetTitleSize(0.04);
  h2->GetYaxis()->SetTitleOffset(0.7);
  h2->SetTitle(sensorname);
  h2f->SetStats(0);
  h2f->SetTitle(sensorname);
  h2f->SetXTitle("dI/dV");
  h2f->SetYTitle("V [V]");
  h2fb->SetStats(0);
  //  h2fb->SetTitle(sensorname);
  h2fb->SetTitle(0);
  h2fb->SetXTitle("#Delta I/#Delta V");
  h2fb->SetYTitle("V [V]");

  if(rad == 1)
    h2->SetYTitle("I [#muA]");
  if(rad == 0)
    h2->SetYTitle("I [nA]");
  h2f->SetYTitle("Derivative");
  h2fb->SetYTitle("Derivative");

  h2->SetXTitle("V [V]");
  c1->cd(1);
  h2->Draw();
  TLegend *l1;
  l1 = new TLegend(0.1,0.6,0.4,0.9);

  //  c1->cd(2);
  //  h2f->Draw();

  std::vector<string> filenames;

  if(device == 1)
    {
      if(pixel == 0 && rad == 1)
	filenames.push_back("data_00_IV_LGAD1.csv");
      if(pixel == 2 && rad == 1)
	filenames.push_back("data_22_IV_LGAD1.csv");
      if(pixel == 4 && rad == 1)
	filenames.push_back("data_44_IV_LGAD1.csv");
      if(pixel == 0 && rad == 0)
	filenames.push_back("data_preirrad_00_IV_LGAD1.csv");
      if(pixel == 2 && rad == 0)
	filenames.push_back("data_preirrad_22_IV_LGAD1.csv");
      if(pixel == 4 && rad == 0)
	filenames.push_back("data_preirrad_44_IV_LGAD1.csv");
    }
  if(device == 2)
    {
      if(pixel == 0 && rad == 1)
	filenames.push_back("data_00_IV_LGAD2.csv");
      if(pixel == 2 && rad == 1)
	filenames.push_back("data_22_IV_LGAD2.csv");
      if(pixel == 4 && rad == 1)
	filenames.push_back("data_44_IV_LGAD2.csv");
      if(pixel == 0 && rad == 0)
	filenames.push_back("data_preirrad_00_IV_LGAD2.csv");
      if(pixel == 2 && rad == 0)
	filenames.push_back("data_preirrad_22_IV_LGAD2.csv");
      if(pixel == 4 && rad == 0)
	filenames.push_back("data_preirrad_44_IV_LGAD2.csv");
    }
  if(device == 3)
    {
      if(pixel == 0 && rad == 0)
        filenames.push_back("data_preirrad_00_IV_LGAD3.csv");
      if(pixel == 2 && rad == 0)
        filenames.push_back("data_preirrad_22_IV_LGAD3.csv");
      if(pixel == 4 && rad == 0)
        filenames.push_back("data_preirrad_44_IV_LGAD3.csv");
    }
  if(device == 4)
    {
      if(pixel == 0 && rad == 1)
	filenames.push_back("data_00_IV_LGAD4.csv");
      if(pixel == 2 && rad == 1)
	filenames.push_back("data_22_IV_LGAD4.csv");
      if(pixel == 4 && rad == 1)
	filenames.push_back("data_44_IV_LGAD4.csv");
      if(pixel == 0 && rad == 0)
	filenames.push_back("data_preirrad_00_IV_LGAD4.csv");
      if(pixel == 2 && rad == 0)
	filenames.push_back("data_preirrad_22_IV_LGAD4.csv");
      if(pixel == 4 && rad == 0)
	filenames.push_back("data_preirrad_44_IV_LGAD4.csv");
    }
  if(device == 5)
    {
      if(pixel == 0 && rad == 1)
	filenames.push_back("data_00_IV_LGAD5.csv");
      if(pixel == 2 && rad == 1)
	filenames.push_back("data_22_IV_LGAD5.csv");
      if(pixel == 4 && rad == 1)
	filenames.push_back("data_44_IV_LGAD5.csv");
      if(pixel == 0 && rad == 0)
	filenames.push_back("data_preirrad_00_IV_LGAD5.csv");
      if(pixel == 2 && rad == 0)
	filenames.push_back("data_preirrad_22_IV_LGAD5.csv");
      if(pixel == 4 && rad == 0)
	filenames.push_back("data_preirrad_44_IV_LGAD5.csv");
    }

      fstream ifs(filenames[0], ios::in);
      int x = 0;

      string line, word;
      std::vector<string> row;
      std::vector<double> ip,v,kfit;

      //  TVectorD ip, v;                                                                                                                                                                                

      ip.clear();
      v.clear();
      row.clear();
      kfit.clear();

      int i = 0;
      float di = 0;
      float dv = 0;

      float vlast = 0.0;
      float vmax = 0;

      
      
      if(ifs.is_open())
        {
	  while(getline(ifs,line) && i < 5000)
            {
              if((i>5 && rad==0 && device!=3) || (i > 26 && rad==0 && device==3) || (i > 20 && rad==1))
                {
                  row.clear();

                  stringstream str(line);

                  while(getline(str, word, ','))
                    row.push_back(word);

		  //		  std::cout << row[0] << ", " << row[2] << std::endl;
		  if(std::stod(row[0]) > vlast)
		    {
		      if(rad == 1 && std::stod(row[2])>0)
			{
			  ip.push_back(std::stod(row[2]) * 1E6);
			}
		      if(rad == 0 && std::stod(row[2])>0 && (std::stod(row[0]) < 205))
			{
			  ip.push_back(std::stod(row[2]) * 1E9);
			}
		      if(std::stod(row[2]) > 0 && (rad==1 || (std::stod(row[0]) < 205)))
			{
			  v.push_back(std::stod(row[0]));
			  if(std::stod(row[0]) > vmax)
			    vmax = std::stod(row[0]);
			  vlast = std::stod(row[0]);
			}
		    }
		}
              i++;
            }
        }

      Int_t n = ip.size();
      TGraph *gr1 = new TGraph(n,&(v[0]),&(ip[0]));

      TString legendlabel;
      Int_t foundplateau = 0;

      if(x < 3)
	{
	  gr1->SetMarkerStyle(20); gr1->SetMarkerColor(x+1);
	  TString pix = Form("%d",2*x);
	  if(device == 4 || device == 1)
	    legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 1E16 p/cm2";
	  if(device == 2 || device == 5)
	    legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 5E15 p/cm2";
	  l1->AddEntry(gr1,legendlabel);
	}
      if(x >=3)
	{
	  gr1->SetMarkerStyle(4); gr1->SetMarkerColor(x-3+1);
	  TString pix = Form("%d",2*(x-3));
	  legendlabel = "Pixel " + pix + "," + pix + ", #Phi_{max} = 0 p/cm2";
	  l1->AddEntry(gr1,legendlabel);
	}

      TSpline5 *s;

      if(rad == 1)
	s = new TSpline5("s",gr1,0,350);
      if(rad == 0)
	s = new TSpline5("s",gr1,0,200);


      c1->cd(1);
      gr1->SetMarkerStyle(20); gr1->SetMarkerColor(1); gr1->Draw("Psame");                                                                   
      

      //      gr1a->SetMarkerStyle(20); gr1a->SetMarkerColor(1); gr1a->Draw("Psame");
      //      gr1b->SetMarkerStyle(20); gr1b->SetMarkerColor(1); gr1b->Draw("Psame");
      //      h2->GetXaxis()->SetLabelSize(0.07);
      //      h2->GetYaxis()->SetLabelSize(0.07);


      //      gr1->SetLineWidth(3);
      //      gr1->SetLineColor(4);
      //      gr1->SetMarkerStyle(20);
      //      gr1-> Draw("psame");

      s->SetLineColor(4); 
      s->SetLineWidth(2);
      s->Draw("same");

      //      c1->cd(2);
      std::vector<double> didv;
      std::vector<double> vfordidv;
      float derivative = 0.0;

      Int_t nstep = 0;
      Float_t thevfordidv = 0.0;
      Float_t maxvfordidv = 0.0;
      Float_t maxdifordidv = 0.0;
      Float_t maxderivative = 0.0;
      Float_t kfactor = 0.0;
      Float_t breakdownv = 0.0;
      Float_t kbreakdown = 0.0;
      Float_t breakdowndidv = 0.0;
      Float_t maxkforkfactor = 0.0;
      Float_t maxvforkfactor = 0.0;
      
      Float_t stepsize = 5.0;
      Float_t stepmin = 5.0;
      if(rad == 1)
	{
	  stepsize = 1.0;
	  stepmin = 1.0;
	  //	stepsize = 5.0;
	  // stepmin = 5.0;
	}
      
      for(Int_t xv = stepmin; xv < vmax; xv+=stepsize)
	{
          if((xv > stepmin && xv<350 && rad==0) || (xv > stepmin && xv<350 && rad==1))                                                       
	    {
	      if(1)
		{
		  derivative = (gr1->Eval(xv,s) - gr1->Eval(xv-stepsize,s))/stepsize;
		  if((rad == 0 && gr1->Eval(xv,s) > 1E-2) || (rad == 1 && gr1->Eval(xv,s) > 1E-5))
		    kfactor = derivative * xv/(gr1->Eval(xv,s));
		  else
		    kfactor = 0;
		  vfordidv.push_back(xv);
		  didv.push_back(derivative);
		  kfit.push_back(kfactor);
		  
		  if(xv < 60 && (kfactor>maxkforkfactor))                                                               
		    {                                                                                                                           
		      //                  if((rad == 0 && xv > 40) || (rad == 1))                                                                                
		      if(1)
			{                                                                                                                       
			  maxkforkfactor = kfactor;
			  
			  maxvforkfactor = xv;          
			}                                                                                                                       
		    }
		  if(xv < 60 && (derivative>maxderivative))
		    {
		      maxderivative = derivative;
		      maxvfordidv = xv;
		    }
		  if(xv > 60 && (kfactor>maxkforkfactor))
		    {
		      kbreakdown = kfactor;
		    }
		  if(xv > 60 && (derivative>maxderivative))
		    {
		      breakdowndidv = derivative;
		      breakdownv = xv;
		    }
		  nstep++;
		}
	    }
	}
      
      for(Int_t xvdidv = 0; xvdidv < didv.size(); xvdidv++)
	{
	  if(rad == 0 && vfordidv[xvdidv] > maxvfordidv && (didv[xvdidv] < maxderivative/2.0))
	    std::cout << didv[xvdidv] << ", " << vfordidv[xvdidv] << std::endl;
	  if(rad == 1 && vfordidv[xvdidv] > maxvfordidv && (didv[xvdidv] < maxderivative/3.0))
	    std::cout << didv[xvdidv] << ", " << vfordidv[xvdidv] << std::endl;

	}


      c1->cd(2);
      TGraph *grdidv = new TGraph(nstep,&(vfordidv[0]),&(didv[0]));
      h2fb->SetYTitle("#Delta I/#Delta V");                                                                                                          
      h2fb->GetYaxis()->SetTitleSize(0.06);                                                                                                                     
      h2fb->GetXaxis()->SetTitleSize(0.04);                                                                                                                     
      h2fb->GetYaxis()->SetTitleOffset(0.7);
      h2fb->SetXTitle("V [V]");                                                                                                                                 
      h2fb->Draw();
      grdidv->SetLineWidth(2); grdidv->SetLineColor(2);
      grdidv->Draw("lpsame");
      /*
      TLine *lop;
      if(rad == 0)
	{
	  lop = new TLine(0,maxderivative/2.0,350,maxderivative/2.0);
	}
      if(rad == 1)
	{
	  lop = new TLine(0,maxderivative/3.0,350,maxderivative/3.0);
	}
      lop->SetLineColor(1); lop->SetLineStyle(2); lop->SetLineWidth(2); lop->Draw("same");                                                                      
      */

      TBox *lop = new TBox(60,0,195,0.07);
      lop->SetFillColor(3); lop->SetFillStyle(3001);
      lop->Draw("same");
      

      c2->cd();
      h2fc->SetStats(0);
      h2fc->SetTitle(0);
      h2fc->SetYTitle("#Delta I/#Delta V #times V/I");
      h2fc->GetYaxis()->SetTitleSize(0.06);
      h2fc->GetXaxis()->SetTitleSize(0.04);
      h2fc->SetXTitle("V [V]");
      h2fc->Draw();
      TGraph *grkfit = new TGraph(nstep,&(vfordidv[0]),&(kfit[0]));
      //      TGraph *grkfit = new TGraph(nstep,&(v[0]),&(kfit[0]));                                                           
      grkfit->SetLineWidth(2); grkfit->SetLineColor(2);
      grkfit->Draw("lpsame");
      TFile *foutkfit = TFile::Open("kfitoutput.root","UPDATE");
      grkfit->Write("kfit1_4_0");
      foutkfit->Close();
      
      //      TLine *lop = new TLine(0,maxdifordidv,350,maxdifordidv);
      //      lop->SetLineColor(1); lop->SetLineStyle(2); lop->SetLineWidth(2); lop->Draw("same");

      std::cout << "VGL Maximum k = " << maxkforkfactor << " at V = " << maxvforkfactor << " V" << std::endl;
      std::cout << "Breakdown k = " << kbreakdown << " at V = " << breakdownv << " V" << std::endl;

}
