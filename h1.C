{
	h = new TGraphErrors("Datas/Volt-count.txt","%lg%lg%lg");
	h->SetTitle("Observed count for each voltage values;Voltage(V);Count");
	h->Draw();
}
