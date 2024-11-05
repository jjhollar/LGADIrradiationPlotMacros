void PlotIV_Perugia(int scale=0)
{

  //  string filenames = inputname;
  std::vector<string> filenames;

  filenames.push_back("Sensore1/FBK_TI_Sens1_R0C0_20gradi_DiodeIV_prova_21_5_2024_9h42m44s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R2C0_20gradi_DiodeIV_200V_21_5_2024_9h57m24s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R0C0_20gradi_DiodeIV_prova_21_5_2024_9h43m49s.txt");  
  filenames.push_back("Sensore1/FBK_TI_Sens1_R2C0_20gradi_DiodeIV_200V_21_5_2024_9h58m27s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R0C0_20gradi_DiodeIV_prova_21_5_2024_9h44m57s.txt");  
  filenames.push_back("Sensore1/FBK_TI_Sens1_R3C0_20gradi_DiodeIV_200V_21_5_2024_10h0m24s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R0C0_20gradi_DiodeIV_prova_21_5_2024_9h46m21s.txt");  
  filenames.push_back("Sensore5/FBK_TI_Sens5_R1C0_20gradi_DiodeIV_rev_3_6_2024_8h59m40s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R1C0_20gradi_DiodeIV_200V_21_5_2024_9h55m43s.txt");   
  filenames.push_back("Sensore5/FBK_TI_Sens5_R1C0_20gradi_DiodeIV_rev_3_6_2024_9h4m4s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R1C0_20gradi_DiodeIV_21_5_2024_9h50m2s.txt");         
  filenames.push_back("Sensore5/FBK_TI_Sens5_R2C0_20gradi_DiodeIV_rev_3_6_2024_9h33m25s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R1C0_20gradi_DiodeIV_21_5_2024_9h51m53s.txt");        
  filenames.push_back("Sensore5/FBK_TI_Sens5_R3C0_20gradi_DiodeIV_rev_3_6_2024_9h47m6s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R1C0_20gradi_DiodeIV_prova_21_5_2024_9h47m52s.txt");  
  filenames.push_back("Sensore5/FBK_TI_Sens5_R4C0_20gradi_DiodeIV_rev_3_6_2024_10h1m46s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R1C0_20gradi_DiodeIV_prova_21_5_2024_9h48m50s.txt");

 for(Int_t x=0; x< filenames.size(); x++)
   {
      
     fstream ifs(filenames[x], ios::in);

     TString plotname = filenames[x];
     plotname.ReplaceAll("/","_");
     plotname.ReplaceAll(".txt","");

     //     fstream ifs(filenames, ios::in);
  
     string line, word;
     std::vector<string> row;
     std::vector<double> ip,v;
     //  TVectorD ip, v;
     
     ip.clear();
     v.clear();
     row.clear();
     
     int i = 0;
     
     TCanvas *c1 = new TCanvas("c1","c1");
     TH2F *h2;
     if(scale==0)
       h2 = new TH2F("h2","h2",2,0,100,2,1E-6,1E2);
     if(scale==1)
       h2 = new TH2F("h2","h2",2,0,100,2,1E-6,1E4);
     h2->SetTitle(plotname);
     h2->SetStats(0);
     h2->SetXTitle("|V| [V]");
     h2->SetYTitle("I [#muA]");
     h2->Draw();
     
     float imax = 0.0;
     float vmax = -999.;
     
     if(ifs.is_open())
       {
	 while(getline(ifs,line) && i < 5000)
	   {
	     if(i > 1)
	       {
		 row.clear();
		 
		 stringstream str(line);
		 
		 while(getline(str, word, '\t'))
		   row.push_back(word);
		 
		 std::cout << row[0] << ", " << row[1] << std::endl;
		 if(std::stod(row[1])*1E6 > imax)
		   imax = std::stod(row[1])*1E6;
		 if(-1.0*std::stod(row[0]) > vmax)
		   vmax = -1.0*std::stod(row[0]);
		 ip.push_back(1E6*std::stod(row[1]));
		 v.push_back(-1.0*std::stod(row[0]));
	       }
	     i++;
	   }
       }

     std::cout << imax << std::endl;
     Int_t n = ip.size();
     TGraph *gr1 = new TGraph(n,&(v[0]),&(ip[0]));
     gr1->SetMarkerStyle(20); gr1->SetMarkerColor(6);
     gr1->SetLineWidth(0);
     gr1->Draw("Psame");
     //     if(imax < 0.01)
     if(scale==0)
       {
         if(vmax > 2)
           c1->SaveAs(plotname+".png");
       }
     if(scale==1)
       {
	 c1->SetLogy();
	 if(vmax > 2)
	   c1->SaveAs(plotname+"_log.png");
       }
   }
}


void PlotCV_Perugia(int scale=0)
{

  //  string filenames = inputname;                                                                                                                                 
  std::vector<string> filenames;

  filenames.push_back("Sensore1/FBK_TI_Sens1_R3C0_20gradi_DiodeCV_21_5_2024_10h10m15s.txt");  
  filenames.push_back("Sensore2/FBK_TI_Sens2_R4C0_20gradi_DiodeCV_10kHz_7_6_2024_15h50m57s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R3C0_20gradi_DiodeCV_21_5_2024_10h8m4s.txt");    
  filenames.push_back("Sensore2/FBK_TI_Sens2_R4C0_20gradi_DiodeCV_2kHz_7_6_2024_15h55m21s.txt");
  filenames.push_back("Sensore1/FBK_TI_Sens1_R3C0_20gradi_DiodeCV_21_5_2024_10h9m33s.txt");   
  filenames.push_back("Sensore2/FBK_TI_Sens2_R4C0_20gradi_DiodeCV_7_6_2024_15h46m40s.txt");
  filenames.push_back("Sensore2/FBK_TI_Sens2_R0C0_20gradi_DiodeCV_7_6_2024_15h33m41s.txt");   
  filenames.push_back("Sensore5/FBK_TI_Sens5_R1C0_20gradi_DiodeCV_3_6_2024_9h13m5s.txt");
  filenames.push_back("Sensore2/FBK_TI_Sens2_R1C0_20gradi_DiodeCV_7_6_2024_15h37m42s.txt");   
  filenames.push_back("Sensore5/FBK_TI_Sens5_R2C0_20gradi_DiodeCV_3_6_2024_9h25m53s.txt");
  filenames.push_back("Sensore2/FBK_TI_Sens2_R2C0_20gradi_DiodeCV_7_6_2024_15h39m29s.txt");   
  filenames.push_back("Sensore5/FBK_TI_Sens5_R3C0_20gradi_DiodeCV_3_6_2024_9h39m29s.txt");
  filenames.push_back("Sensore2/FBK_TI_Sens2_R3C0_20gradi_DiodeCV_7_6_2024_15h41m37s.txt");   
  filenames.push_back("Sensore5/FBK_TI_Sens5_R4C0_20gradi_DiodeCV_3_6_2024_9h53m34s.txt");

  for(Int_t x=0; x< filenames.size(); x++)
    {
      
      fstream ifs(filenames[x], ios::in);
      
      TString plotname = filenames[x];
      plotname.ReplaceAll("/","_");
      plotname.ReplaceAll(".txt","");
      
      //     fstream ifs(filenames, ios::in);
      
      string line, word;
      std::vector<string> row;
      std::vector<double> c,v;
     
      c.clear();
      v.clear();
      row.clear();
      
      int i = 0;
     
      TCanvas *c1 = new TCanvas("c1","c1");
     TH2F *h2;
     h2 = new TH2F("h2","h2",2,0,100,2,1E-1,1E3);
     h2->SetTitle(plotname);
     h2->SetStats(0);
     h2->SetXTitle("|V| [V]");
     h2->SetYTitle("C [pF]");
     h2->Draw();
     
     float imax = 0.0;
     float vmax = -999.;
     
     if(ifs.is_open())
       {
	 while(getline(ifs,line) && i < 5000)
	   {
	     if(i > 1)
	       {
		 row.clear();
		 
		 stringstream str(line);
		 
		 while(getline(str, word, '\t'))
		   row.push_back(word);
		 
		 std::cout << row[0] << ", " << row[1] << std::endl;
		 if(std::stod(row[1])*1E12 > imax)
		   imax = std::stod(row[1])*1E12;
                 if(-1.0*std::stod(row[0]) > vmax)
                   vmax = -1.0*std::stod(row[0]);
		 c.push_back(1E12*std::stod(row[1]));
		 v.push_back(-1.0*std::stod(row[0]));
	       }
	     i++;
	   }
       }

     std::cout << imax << std::endl;
     Int_t n = c.size();
     TGraph *gr1 = new TGraph(n,&(v[0]),&(c[0]));
     gr1->SetMarkerStyle(20); gr1->SetMarkerColor(6);
     gr1->SetLineWidth(0);
     gr1->Draw("Psame");
     //  if(imax < 0.01)
     //     c1->SetLogy();
     if(scale==0)
       {
	 if(vmax > 2)
	   c1->SaveAs(plotname+".png");
       }
     if(scale==1)
       {
	 c1->SetLogy();                                                                                                                                          
         if(vmax > 2)
           c1->SaveAs(plotname+"_log.png");
       }
   }
}
