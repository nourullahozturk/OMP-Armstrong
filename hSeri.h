
void fSeri() {

	double itime, ftime, exec_time;
	itime = omp_get_wtime();
	int n, basamak, rakam, toplam, count = 0;
	for (int i = 0; i < N; i++) {

		n = i;
		basamak = 1;
		while (n > 9) { //sayinin basamak sayisini bulur
			basamak++;
			n = n / 10;
		}

		n = i;
		toplam = 0;
		for (int j = 0; j < basamak; j++) {
			rakam = n % 10;
			toplam += pow(rakam, basamak);
			n = n / 10;
		}

		if (i == toplam && 0 != toplam) {
			//printf("%d ", i);
			count++;
		}

	}

	ftime = omp_get_wtime();
	exec_time = ftime - itime;
	printf("\n\nSeri kosuyor...");
	printf("\ngecen sure %f", exec_time);
	printf("\nverilen araliktaki armstrong sayi sayisi: %d", count);
}