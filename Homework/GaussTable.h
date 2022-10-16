#pragma once

struct GaussTable
{
	int N;
	double** table;

	GaussTable(int N)
	{
		this->N = N;
		table = new double* [column];
		InitTable(N);
	}
	~GaussTable()
	{
		for (int i = 0; i < column; i++)
		{
			delete[] table[i];
		}

		delete [] table;
	}

	private:
		int static const column = 2;
		void InitTable(int N)
		{
			for (int i = 0; i < column; i++)
			{
				table[i] = new double[N];
				for (int j = 0; j < N; j++)
					table[i][j] = 0.0F;
			}
		}

};
