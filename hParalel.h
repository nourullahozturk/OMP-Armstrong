
void fParalel()
{
	omp_set_num_threads(NTHREADS);
	double itime, ftime, exec_time;
	itime = omp_get_wtime();
	int totalCount = 0;

	#pragma omp parallel
	{
		int n, basamak, rakam, toplam, count = 0;
		#pragma omp for
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
		#pragma omp critical
		totalCount += count;
	}

	ftime = omp_get_wtime();
	exec_time = ftime - itime;
	printf("\n\nParalel kosuyor...");
	printf("\ngecen sure %f", exec_time);
	printf("\nverilen araliktaki armstrong sayi sayisi: %d", totalCount);
}