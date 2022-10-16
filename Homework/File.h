#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class File
{
public:
	File(string fileDirectory);
	File();
	~File();

	void SetDirectory(string fileDirectory);

	string GetName();
	int GetRecordsCount();
	int GetWordCount();

	string Read();

	void Write(string text);
	void ClearRecords();

	string GetLine(int line);
	string operator[](int index);

private:
	string fileDirectory;
	string nameFile;
	fstream file;

	int records = 0;
	int words = 0;

	void AnalyzingNewFile();

	bool TryOpenFileAsRead();
	void OpenFileAsWrite();

	void GenerateName();
	void CountingRecordsAndWordsInNewFile();
	void CountingWordsInNewRecords(string record);
};
