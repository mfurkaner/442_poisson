{
	TF1 *f1 = new TF1("n0","[1]*[0]*(TMath::Exp(-[0]*x))", 0, 140);//n=0 time dependent poisson for n+1
	TF1 *f2 = new TF1("n1","[1]*[0]*[0]*(TMath::Exp(-[0]*x))*x", 0, 140);//n=1 time dependent poisson for n+1
	n0->SetParNames("alpha","Normalization constant");
	n1->SetParNames("alpha","Normalization constant");
	n0->SetParameter(0,1);
	n0->SetParLimits(0,0,10);
	n1->SetParameter(0,1);
//	mpoi->SetParameter(0,200);
	double dummy;
	h= new TH1D("n1fit","n=1 distance taken from the chart recorder;distance between two signals(cm); Count",16,0,8);//This part has been modified for each histogram names, titles, ranges, number of bins etc.
	g= new TGraph("Datas/distance.txt","%*lg%lg%lg");//Has n=0 in X axis n=1 in Y axis
	for(int i=0;i<g->GetN();i++){
		dummy= g->GetY()[i];
		n1fit->Fill(dummy);
	}
	n1fit->SetFillColor(kGray+1);
	n1fit->Fit("n1");
	n1fit->Draw();
}
