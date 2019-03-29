{
	TF1 *f1 = new TF1("mpoi","[0]*TMath::Power(([1]),(x))*(TMath::Exp(-[1]))/TMath::Gamma((x)+1)", 0, 140);
	mpoi->SetParNames("Normalization Constant","mu");
	mpoi->SetParameter(1,4);
	mpoi->SetParameter(0,200);
	double dummy;
	h= new TH1D("Ba133","Counts for Ba133 Sample in 10s time intervals; Observed Number of Radiation; Count",40,0,80);//This part has been modified for each histogram names, titles, ranges, number of bins etc.
	g= new TGraph("Datas/Ba133.txt","%lg%lg");//This part also was modified to get the necessary data.
	for(int i=0;i<g->GetN();i++){
		dummy= g->GetY()[i];
		Ba133->Fill(dummy);
	}
	Ba133->SetFillColor(kBlue-10);
	Ba133->Fit("mpoi");
	Ba133->Draw();
}
