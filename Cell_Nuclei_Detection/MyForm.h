#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>


#define Tolerance 0.003 //0.005 // -->Merkeze uzaklýk farký

namespace NetworkCompareForDarknet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>

	int yoloBox;
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			centerArray = (float****)malloc(1 * sizeof(float***));
			files = (const char**)malloc(1 * sizeof(const char*));
			avarageTime = (int*)malloc(1 * sizeof(int));
			fileCount = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  networkCompare;
	protected:

	protected:

	private:
		/// <summary>

		float**** centerArray;
		const char** files;
		int fileCount;
		int frameCount;
		int** correctBoxesArray;
		float* totalCorrectBoxArray;
		int* avarageTime;




	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  selectNetFile;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  chartClear;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart3;
	private: System::Windows::Forms::Panel^  panel2;




		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->networkCompare = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->selectNetFile = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartClear = (gcnew System::Windows::Forms::Button());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// networkCompare
			// 
			this->networkCompare->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->networkCompare->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->networkCompare->Location = System::Drawing::Point(3, 353);
			this->networkCompare->Name = L"networkCompare";
			this->networkCompare->Size = System::Drawing::Size(107, 33);
			this->networkCompare->TabIndex = 4;
			this->networkCompare->Text = L"Compear";
			this->networkCompare->UseVisualStyleBackColor = true;
			this->networkCompare->Click += gcnew System::EventHandler(this, &MyForm::networkCompare_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// selectNetFile
			// 
			this->selectNetFile->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->selectNetFile->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selectNetFile->Location = System::Drawing::Point(3, 314);
			this->selectNetFile->Name = L"selectNetFile";
			this->selectNetFile->Size = System::Drawing::Size(107, 33);
			this->selectNetFile->TabIndex = 6;
			this->selectNetFile->Text = L"File";
			this->selectNetFile->UseVisualStyleBackColor = true;
			this->selectNetFile->Click += gcnew System::EventHandler(this, &MyForm::selectNetFile_Click);
			// 
			// chart1
			// 
			this->chart1->BorderSkin->BackColor = System::Drawing::Color::White;
			this->chart1->BorderSkin->BorderWidth = 5;
			this->chart1->BorderSkin->PageColor = System::Drawing::SystemColors::Control;
			this->chart1->BorderSkin->SkinStyle = System::Windows::Forms::DataVisualization::Charting::BorderSkinStyle::Sunken;
			chartArea1->AxisX->Interval = 5;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisX->Title = L"Frame";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea1->AxisY->Interval = 10;
			chartArea1->AxisY->Title = L"Number of Matching Box Count";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea1->BackColor = System::Drawing::Color::White;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->BackColor = System::Drawing::Color::White;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(8, 25);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			this->chart1->Size = System::Drawing::Size(1013, 346);
			this->chart1->TabIndex = 7;
			this->chart1->Text = L"chart1";
			// 
			// chartClear
			// 
			this->chartClear->Enabled = false;
			this->chartClear->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->chartClear->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chartClear->Location = System::Drawing::Point(3, 392);
			this->chartClear->Name = L"chartClear";
			this->chartClear->Size = System::Drawing::Size(107, 35);
			this->chartClear->TabIndex = 8;
			this->chartClear->Text = L"Clear";
			this->chartClear->UseVisualStyleBackColor = true;
			this->chartClear->Click += gcnew System::EventHandler(this, &MyForm::chartClear_Click);
			// 
			// chart2
			// 
			this->chart2->BorderSkin->BackColor = System::Drawing::Color::White;
			this->chart2->BorderSkin->BorderWidth = 5;
			this->chart2->BorderSkin->PageColor = System::Drawing::SystemColors::Control;
			this->chart2->BorderSkin->SkinStyle = System::Windows::Forms::DataVisualization::Charting::BorderSkinStyle::Sunken;
			chartArea2->AxisX->Interval = 1;
			chartArea2->AxisX->ScaleBreakStyle->StartFromZero = System::Windows::Forms::DataVisualization::Charting::StartFromZero::Yes;
			chartArea2->AxisX->Title = L"File No";
			chartArea2->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea2->AxisY->Interval = 5;
			chartArea2->AxisY->Maximum = 100;
			chartArea2->AxisY->Title = L"Accuracy Rate(%)";
			chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea2->BackColor = System::Drawing::Color::White;
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->BackColor = System::Drawing::Color::White;
			legend2->ItemColumnSpacing = 10;
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(8, 377);
			this->chart2->Name = L"chart2";
			this->chart2->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			this->chart2->Size = System::Drawing::Size(510, 288);
			this->chart2->TabIndex = 1;
			this->chart2->Text = L"chart2";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->chart3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->chart1);
			this->panel1->Controls->Add(this->chart2);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1030, 675);
			this->panel1->TabIndex = 9;
			// 
			// chart3
			// 
			this->chart3->BorderSkin->BackColor = System::Drawing::Color::White;
			this->chart3->BorderSkin->BorderWidth = 5;
			this->chart3->BorderSkin->PageColor = System::Drawing::SystemColors::Control;
			this->chart3->BorderSkin->SkinStyle = System::Windows::Forms::DataVisualization::Charting::BorderSkinStyle::Sunken;
			chartArea3->AxisX->Interval = 1;
			chartArea3->AxisX->ScaleBreakStyle->StartFromZero = System::Windows::Forms::DataVisualization::Charting::StartFromZero::Yes;
			chartArea3->AxisX->Title = L"File No";
			chartArea3->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea3->AxisY->Interval = 10;
			chartArea3->AxisY->Title = L"Avarage Of Frame Processing Time(ms)";
			chartArea3->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea3->BackColor = System::Drawing::Color::White;
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			legend3->BackColor = System::Drawing::Color::White;
			legend3->ItemColumnSpacing = 10;
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(524, 377);
			this->chart3->Name = L"chart3";
			this->chart3->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			this->chart3->Size = System::Drawing::Size(497, 288);
			this->chart3->TabIndex = 11;
			this->chart3->Text = L"chart3";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Info;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(327, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(433, 22);
			this->label1->TabIndex = 10;
			this->label1->Text = L"The first file selected is considered 100% correct.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->selectNetFile);
			this->panel2->Controls->Add(this->networkCompare);
			this->panel2->Controls->Add(this->chartClear);
			this->panel2->Location = System::Drawing::Point(1048, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(116, 675);
			this->panel2->TabIndex = 10;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1168, 698);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	void SetFileValues(int fileNo) {
		int boxes = 0, frame = 0;
		centerArray = (float****)realloc(centerArray, (fileNo + 1) * sizeof(float***));
		centerArray[fileNo] = (float***)malloc((frame+1) * sizeof(float**));
		centerArray[fileNo][frame] = (float**)malloc((boxes + 1) * sizeof(float*));
		avarageTime = (int*)realloc(avarageTime, (fileNo + 1) * sizeof(int));

		ifstream file(files[fileNo]);
		string line;
		string::size_type sz;

		while (!file.eof()) {
			centerArray[fileNo][frame] = (float**)realloc(centerArray[fileNo][frame], (boxes + 1) * sizeof(float*));
			centerArray[fileNo][frame][boxes] = (float*)malloc(2 * sizeof(float));
			getline(file, line);
			if (line == "") {
				centerArray[fileNo][frame][boxes][0] = 32; //32--> Ascii space character.(to seperate frames)
				centerArray[fileNo][frame][boxes][1] = 32;
				frame++;
				centerArray[fileNo] = (float***)realloc(centerArray[fileNo], (frame + 1) * sizeof(float**));
				centerArray[fileNo][frame] = (float**)malloc((boxes + 1) * sizeof(float*));
				boxes = 0;
			}
			else if (line == "Milisecond") {
				file >> avarageTime[fileNo];
			}
			else {
				centerArray[fileNo][frame][boxes][0] = stof(line, &sz);
				centerArray[fileNo][frame][boxes][1] = stof(line.substr(sz));
				boxes++;
			}
		}
		file.close();

		frameCount = frame;
		centerArray[fileNo][frame][boxes] = (float*)malloc(2 * sizeof(float));
		centerArray[fileNo][frame][boxes][0] = 32;
		centerArray[fileNo][frame][boxes][1] = 32;
	}
	private: System::Void networkCompare_Click(System::Object^  sender, System::EventArgs^  e) {
		if (fileCount < 2) {
			MessageBox::Show("You must select at least two files!");
			fileCount = 0;
		}
		else {
			float yolo_x_up, yolo_x_down, yolo_y_up, yolo_y_down;
			int firstFileBoxCount = 0;
			int correctBoxCount;
			correctBoxesArray = (int**)malloc((fileCount) * sizeof(int*));

			for (int f_no = 0; f_no < fileCount; f_no++) 
				correctBoxesArray[f_no] = (int*)malloc((frameCount) * sizeof(int));

			for (int f_no = 0; f_no < fileCount - 1; f_no++) {
				correctBoxCount = 0;
				for (int f = 0; f < frameCount; f++) {
					for (int i = 0; centerArray[0][f][i][0] != 32; i++) {
						if (f_no == 0)firstFileBoxCount++;

						yolo_x_up   = centerArray[0][f][i][0] + Tolerance;
						yolo_x_down = centerArray[0][f][i][0] - Tolerance;

						yolo_y_up   = centerArray[0][f][i][1] + Tolerance;
						yolo_y_down = centerArray[0][f][i][1] - Tolerance;

						for (int j = 0; centerArray[f_no + 1][f][j][0] != 32; j++) {
							if (yolo_x_up > centerArray[f_no + 1][f][j][0] && yolo_x_down < centerArray[f_no + 1][f][j][0])
								if (yolo_y_up > centerArray[f_no + 1][f][j][1] && yolo_y_down < centerArray[f_no + 1][f][j][1])
									correctBoxCount++;
						}
					}
					if (f_no == 0)correctBoxesArray[0][f] = firstFileBoxCount - 1; // Her frame'de fazlalýk 32'ýn box'ý var.
					//cout << correctBoxesArray[0][f] << endl;
					correctBoxesArray[f_no + 1][f] = correctBoxCount;
					for (int b = 0; centerArray[f_no + 1][f][b][0] != 32; b++)
						free(centerArray[f_no + 1][f][b]);//f1,f2,f3,f4 -->x,y
					free(centerArray[f_no + 1][f]);//f1,f2,f3,f4 -->boxes
					//cout << correctBoxesArray[f_no + 1][f] << endl;
					correctBoxCount = 0;
					firstFileBoxCount = 0;
				}
				//cout << endl << endl;
			}
			for (int f = 0; f < frameCount; f++) {
				for (int b = 0; centerArray[0][f][b][0] != 32; b++)
					free(centerArray[0][f][b]);//f1,f2,f3,f4 -->x,y
				free(centerArray[0][f]);//f1,f2,f3,f4 -->boxes
			}
			free(centerArray);

			totalCorrectBoxArray = (float*)malloc(fileCount * sizeof(float));
			for (int f_no = 0; f_no < fileCount; f_no++) {
				totalCorrectBoxArray[f_no] = 0;
				for (int f = 0; f < frameCount; f++)
					totalCorrectBoxArray[f_no] += correctBoxesArray[f_no][f];//file2 ve file3 alýcak
				//cout << totalCorrectBoxArray[f_no] << endl;

				if (f_no != 0)totalCorrectBoxArray[f_no] = (totalCorrectBoxArray[f_no] * 100.0f) / totalCorrectBoxArray[0];
			}
			totalCorrectBoxArray[0] = 100; //%100 ->> ilk dosya
			for (int f_no = 0; f_no < fileCount; f_no++) {
				string seriesName = "File";
				seriesName += std::to_string(f_no + 1);
				String^ str = gcnew String(seriesName.c_str()); //std::string --> System::String'e dönüþtürüldü.
				chart1->Series->Add(str);
				chart1->Series[str]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
				chart2->Series->Add(str);
				chart2->Series[str]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
				chart3->Series->Add(str);
				chart3->Series[str]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
				for (int f = 0; f < frameCount; f++)
					this->chart1->Series[str]->Points->AddXY(f, correctBoxesArray[f_no][f]);
				this->chart2->Series[str]->Points->AddXY(f_no + 1, totalCorrectBoxArray[f_no]);
				this->chart3->Series[str]->Points->AddXY(f_no + 1, avarageTime[f_no]);
			}
			this->selectNetFile->Enabled = false;
			this->networkCompare->Enabled = false;
			this->chartClear->Enabled = true;
		}
	}
	private: System::Void selectNetFile_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			(fileCount==0)? files = (const char**)malloc(1 * sizeof(const char*)):
				files = (const char**)realloc(files, (fileCount + 1) * sizeof(const char*));
			msclr::interop::marshal_context ^ context = gcnew msclr::interop::marshal_context();
			files[fileCount] = context->marshal_as<const char*>(openFileDialog1->FileName);
			SetFileValues(fileCount++);
		}
	}
	private: System::Void chartClear_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int f_no = 0; f_no < fileCount; f_no++) {
			this->chart1->Series->Clear();
			this->chart2->Series->Clear();
			this->chart3->Series->Clear();
			free(correctBoxesArray[f_no]);
		}
		free(correctBoxesArray);
		free(totalCorrectBoxArray);
		free(avarageTime);

		centerArray = (float****)malloc(1 * sizeof(float***));
		avarageTime = (int*)malloc(1 * sizeof(int));

		this->networkCompare->Enabled = true;
		this->selectNetFile->Enabled = true;
		this->chartClear->Enabled = false;
		fileCount = 0;
	}
};
}
