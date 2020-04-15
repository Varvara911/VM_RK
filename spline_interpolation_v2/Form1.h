#include <fstream> 
#include <string>
#include "frk_vm.h"
#include <iostream>
#include <iomanip>
#include <list>

#pragma once

namespace vm_2 {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Windows::Forms::DataVisualization::Charting;
  using namespace System::Data;
  using namespace System::Drawing;

  public ref class Form1 : public System::Windows::Forms::Form  {
	public:
	  Form1(void)  {
	      InitializeComponent();
		}
	protected:
	  ~Form1()  {
		if (components)  {
		  delete components;
		}
	  }
	  int num_of_series=0;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Label^ Errors;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TextBox^ H;
	private: System::Windows::Forms::TextBox^ end;
	private: System::Windows::Forms::TextBox^ _xdash0;
	private: System::Windows::Forms::TextBox^ begin;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ lambda;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Label^ changed;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ N;
	private: System::Windows::Forms::TextBox^ textBox1;

	protected: 

	private:
      System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	void InitializeComponent(void)  {
		System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->textBox2 = (gcnew System::Windows::Forms::TextBox());
		this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->Errors = (gcnew System::Windows::Forms::Label());
		this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
		this->H = (gcnew System::Windows::Forms::TextBox());
		this->end = (gcnew System::Windows::Forms::TextBox());
		this->_xdash0 = (gcnew System::Windows::Forms::TextBox());
		this->begin = (gcnew System::Windows::Forms::TextBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->lambda = (gcnew System::Windows::Forms::TextBox());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->button4 = (gcnew System::Windows::Forms::Button());
		this->changed = (gcnew System::Windows::Forms::Label());
		this->button6 = (gcnew System::Windows::Forms::Button());
		this->label10 = (gcnew System::Windows::Forms::Label());
		this->N = (gcnew System::Windows::Forms::TextBox());
		this->textBox1 = (gcnew System::Windows::Forms::TextBox());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
		this->SuspendLayout();
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(6, 24);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(27, 13);
		this->label3->TabIndex = 6;
		this->label3->Text = L"Шаг";
		// 
		// textBox2
		// 
		this->textBox2->Location = System::Drawing::Point(169, 40);
		this->textBox2->Name = L"textBox2";
		this->textBox2->ReadOnly = true;
		this->textBox2->Size = System::Drawing::Size(54, 22);
		this->textBox2->TabIndex = 10;
		this->textBox2->Text = L"0";
		// 
		// numericUpDown2
		// 
		this->numericUpDown2->DecimalPlaces = 2;
		this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 131072 });
		this->numericUpDown2->Location = System::Drawing::Point(6, 40);
		this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
		this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
		this->numericUpDown2->Name = L"numericUpDown2";
		this->numericUpDown2->Size = System::Drawing::Size(75, 22);
		this->numericUpDown2->TabIndex = 7;
		this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(166, 25);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(57, 13);
		this->label4->TabIndex = 9;
		this->label4->Text = L"Точность:";
		// 
		// Errors
		// 
		this->Errors->AutoSize = true;
		this->Errors->Location = System::Drawing::Point(264, 689);
		this->Errors->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->Errors->Name = L"Errors";
		this->Errors->Size = System::Drawing::Size(0, 17);
		this->Errors->TabIndex = 19;
		// 
		// chart1
		// 
		this->chart1->AntiAliasing = System::Windows::Forms::DataVisualization::Charting::AntiAliasingStyles::None;
		chartArea1->AxisX->Crossing = 1.7976931348623157E+308;
		chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
		chartArea1->AxisX->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisX->IsLabelAutoFit = false;
		chartArea1->AxisX->IsMarginVisible = false;
		chartArea1->AxisX->IsStartedFromZero = false;
		chartArea1->AxisX->LabelAutoFitMaxFontSize = 5;
		chartArea1->AxisX->LabelAutoFitMinFontSize = 5;
		chartArea1->AxisX->LabelStyle->Interval = 0;
		chartArea1->AxisX->LabelStyle->IntervalOffset = 0;
		chartArea1->AxisX->LabelStyle->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisX->LabelStyle->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisX->LabelStyle->IsStaggered = true;
		chartArea1->AxisX->LabelStyle->TruncatedLabels = true;
		chartArea1->AxisX->LineColor = System::Drawing::SystemColors::ActiveCaption;
		chartArea1->AxisX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
		chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::SystemColors::ActiveCaption;
		chartArea1->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
		chartArea1->AxisX->MaximumAutoSize = 90;
		chartArea1->AxisX->ScaleBreakStyle->BreakLineStyle = System::Windows::Forms::DataVisualization::Charting::BreakLineStyle::Wave;
		chartArea1->AxisX->ScaleBreakStyle->Enabled = true;
		chartArea1->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
		chartArea1->AxisY->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisY->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisY->IsLabelAutoFit = false;
		chartArea1->AxisY->IsMarksNextToAxis = false;
		chartArea1->AxisY->LabelStyle->Interval = 0;
		chartArea1->AxisY->LabelStyle->IntervalOffset = 0;
		chartArea1->AxisY->LabelStyle->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisY->LabelStyle->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
		chartArea1->AxisY->LabelStyle->IsStaggered = true;
		chartArea1->AxisY->LabelStyle->TruncatedLabels = true;
		chartArea1->AxisY->LineColor = System::Drawing::SystemColors::ActiveCaption;
		chartArea1->AxisY->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
		chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::SystemColors::ActiveCaption;
		chartArea1->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
		chartArea1->AxisY->MaximumAutoSize = 90;
		chartArea1->Name = L"ChartArea1";
		this->chart1->ChartAreas->Add(chartArea1);
		this->chart1->Location = System::Drawing::Point(16, 209);
		this->chart1->Margin = System::Windows::Forms::Padding(4);
		this->chart1->Name = L"chart1";
		this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
		series1->ChartArea = L"ChartArea1";
		series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		series1->LabelBorderWidth = 5;
		series1->MarkerBorderColor = System::Drawing::Color::Black;
		series1->MarkerBorderWidth = 2;
		series1->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		series1->Name = L"Series1";
		series1->SmartLabelStyle->AllowOutsidePlotArea = System::Windows::Forms::DataVisualization::Charting::LabelOutsidePlotAreaStyle::No;
		series1->SmartLabelStyle->CalloutLineAnchorCapStyle = System::Windows::Forms::DataVisualization::Charting::LineAnchorCapStyle::Diamond;
		this->chart1->Series->Add(series1);
		this->chart1->Size = System::Drawing::Size(1073, 511);
		this->chart1->TabIndex = 0;
		this->chart1->Text = L"chart1";
		// 
		// H
		// 
		this->H->Location = System::Drawing::Point(247, 110);
		this->H->Margin = System::Windows::Forms::Padding(4);
		this->H->Name = L"H";
		this->H->Size = System::Drawing::Size(56, 22);
		this->H->TabIndex = 37;
		// 
		// end
		// 
		this->end->Location = System::Drawing::Point(100, 111);
		this->end->Margin = System::Windows::Forms::Padding(4);
		this->end->Name = L"end";
		this->end->Size = System::Drawing::Size(56, 22);
		this->end->TabIndex = 38;
		// 
		// _xdash0
		// 
		this->_xdash0->Location = System::Drawing::Point(100, 160);
		this->_xdash0->Margin = System::Windows::Forms::Padding(4);
		this->_xdash0->Name = L"_xdash0";
		this->_xdash0->Size = System::Drawing::Size(56, 22);
		this->_xdash0->TabIndex = 39;
		// 
		// begin
		// 
		this->begin->Location = System::Drawing::Point(100, 63);
		this->begin->Margin = System::Windows::Forms::Padding(4);
		this->begin->Name = L"begin";
		this->begin->Size = System::Drawing::Size(56, 22);
		this->begin->TabIndex = 40;
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(30, 63);
		this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(62, 17);
		this->label1->TabIndex = 42;
		this->label1->Text = L"Начало:";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(30, 111);
		this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(53, 17);
		this->label2->TabIndex = 43;
		this->label2->Text = L"Конец:";
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Location = System::Drawing::Point(30, 163);
		this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(42, 17);
		this->label6->TabIndex = 45;
		this->label6->Text = L"X\'(0):";
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Location = System::Drawing::Point(208, 111);
		this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(20, 17);
		this->label7->TabIndex = 46;
		this->label7->Text = L"h:";
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(358, 126);
		this->button1->Margin = System::Windows::Forms::Padding(4);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(165, 58);
		this->button1->TabIndex = 47;
		this->button1->Text = L"Построить";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
		// 
		// lambda
		// 
		this->lambda->Location = System::Drawing::Point(247, 160);
		this->lambda->Margin = System::Windows::Forms::Padding(4);
		this->lambda->Name = L"lambda";
		this->lambda->Size = System::Drawing::Size(56, 22);
		this->lambda->TabIndex = 48;
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Location = System::Drawing::Point(208, 163);
		this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(20, 17);
		this->label8->TabIndex = 49;
		this->label8->Text = L"б:";
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Location = System::Drawing::Point(30, 19);
		this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(209, 17);
		this->label9->TabIndex = 50;
		this->label9->Text = L"Уравнение: x\'\'+δx\'cos⁡nx+sin⁡x=0";
		this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		this->label9->Click += gcnew System::EventHandler(this, &Form1::label9_Click);
		// 
		// button3
		// 
		this->button3->Location = System::Drawing::Point(790, 126);
		this->button3->Margin = System::Windows::Forms::Padding(4);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(171, 58);
		this->button3->TabIndex = 51;
		this->button3->Text = L"Очистить";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
		// 
		// button4
		// 
		this->button4->Location = System::Drawing::Point(479, 53);
		this->button4->Margin = System::Windows::Forms::Padding(4);
		this->button4->Name = L"button4";
		this->button4->Size = System::Drawing::Size(44, 36);
		this->button4->TabIndex = 52;
		this->button4->Text = L">>";
		this->button4->UseVisualStyleBackColor = true;
		this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
		// 
		// changed
		// 
		this->changed->AutoSize = true;
		this->changed->Location = System::Drawing::Point(984, 47);
		this->changed->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->changed->Name = L"changed";
		this->changed->Size = System::Drawing::Size(0, 17);
		this->changed->TabIndex = 54;
		this->changed->Visible = false;
		// 
		// button6
		// 
		this->button6->Location = System::Drawing::Point(572, 126);
		this->button6->Margin = System::Windows::Forms::Padding(4);
		this->button6->Name = L"button6";
		this->button6->Size = System::Drawing::Size(163, 58);
		this->button6->TabIndex = 56;
		this->button6->Text = L"Фазовый портрет";
		this->button6->UseVisualStyleBackColor = true;
		this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
		// 
		// label10
		// 
		this->label10->AutoSize = true;
		this->label10->Location = System::Drawing::Point(208, 63);
		this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label10->Name = L"label10";
		this->label10->Size = System::Drawing::Size(22, 17);
		this->label10->TabIndex = 58;
		this->label10->Text = L"N:";
		this->label10->Click += gcnew System::EventHandler(this, &Form1::label10_Click);
		// 
		// N
		// 
		this->N->Location = System::Drawing::Point(247, 60);
		this->N->Margin = System::Windows::Forms::Padding(4);
		this->N->Name = L"N";
		this->N->Size = System::Drawing::Size(56, 22);
		this->N->TabIndex = 57;
		// 
		// textBox1
		// 
		this->textBox1->Location = System::Drawing::Point(431, 60);
		this->textBox1->Name = L"textBox1";
		this->textBox1->Size = System::Drawing::Size(32, 22);
		this->textBox1->TabIndex = 59;
		this->textBox1->Text = L"шаг";
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::Window;
		this->ClientSize = System::Drawing::Size(1105, 735);
		this->Controls->Add(this->textBox1);
		this->Controls->Add(this->label10);
		this->Controls->Add(this->N);
		this->Controls->Add(this->button6);
		this->Controls->Add(this->changed);
		this->Controls->Add(this->button4);
		this->Controls->Add(this->button3);
		this->Controls->Add(this->label9);
		this->Controls->Add(this->label8);
		this->Controls->Add(this->lambda);
		this->Controls->Add(this->button1);
		this->Controls->Add(this->label7);
		this->Controls->Add(this->label6);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->begin);
		this->Controls->Add(this->_xdash0);
		this->Controls->Add(this->end);
		this->Controls->Add(this->H);
		this->Controls->Add(this->Errors);
		this->Controls->Add(this->chart1);
		this->Margin = System::Windows::Forms::Padding(4);
		this->Name = L"Form1";
		this->Text = L"Laba";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	double begin = this->begin->Text == "" ? 0 : Convert::ToDouble(this->begin->Text);
	this->begin->Text = Convert::ToString(begin);
	double end = this->end->Text == "" ? 10 : Convert::ToDouble(this->end->Text);
	if (end - begin < 15) {
		end += 15;
	}
	this->end->Text = Convert::ToString(end);
	double h = this->H->Text == "" ? 0.01 : Convert::ToDouble(this->H->Text);
	this->H->Text = Convert::ToString(h);
	double lambda = this->lambda->Text == "" ? 3 : Convert::ToDouble(this->lambda->Text);
	this->lambda->Text = Convert::ToString(lambda);
	double x0dash = this->_xdash0->Text == "" ? 1 : Convert::ToDouble(this->_xdash0->Text);
	this->_xdash0->Text = Convert::ToString(x0dash);
	double N = this->N->Text == "" ? 3 : Convert::ToDouble(this->N->Text);
	this->N->Text = Convert::ToString(N);

	if(this->chart1->Series[num_of_series]){
		this->chart1->Series->Add(Convert::ToString(++num_of_series));
		this->chart1->Series[num_of_series]->ChartType = SeriesChartType::Line;
		this->chart1->Series[num_of_series]->Color = Color::Black;
	}

	std::vector<double> res;
	std::vector<double> res_v;
	int count = 0;
	R_K(begin, end, h, lambda, x0dash, N, res, res_v);
	for (double i = begin; i < end; i += h) {
		this->chart1->Series[num_of_series]->Points->AddXY(i, res[count]);
		count++;
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < num_of_series + 1; ++i) {
		this->chart1->Series[i]->Points->Clear();
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->end->Text = Convert::ToString(Convert::ToDouble(this->end->Text) + 10);

	button1_Click(sender, e);
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	double begin = this->begin->Text == "" ? 0 : Convert::ToDouble(this->begin->Text);
	this->begin->Text = Convert::ToString(begin);
	double end = this->end->Text == "" ? 10 : Convert::ToDouble(this->end->Text);
	if (end - begin < 15) {
		end += 15;
	}
	this->end->Text = Convert::ToString(end);
	double h = this->H->Text == "" ? 0.01 : Convert::ToDouble(this->H->Text);
	this->H->Text = Convert::ToString(h);
	double lambda = this->lambda->Text == "" ? 3 : Convert::ToDouble(this->lambda->Text);
	this->lambda->Text = Convert::ToString(lambda);
	double x0dash = this->_xdash0->Text == "" ? 1 : Convert::ToDouble(this->_xdash0->Text);
	this->_xdash0->Text = Convert::ToString(x0dash);
	double N = this->N->Text == "" ? 3 : Convert::ToDouble(this->N->Text);
	this->N->Text = Convert::ToString(N);

	std::vector<double> res;
	std::vector<double> res_v;
	R_K(begin, end, h, lambda, x0dash, N, res, res_v);
	int count = 0;
	std::ofstream ofs;
	ofs.open("Output.txt");
	ofs << "x" << std::setw(20) << "v" << std::setw(20) << "t" << std::endl;
	for (double i = begin; i < end; i += h) {
		ofs << res[count] << std::setw(20) << res_v[count] << std::setw(20) << i << std::endl;
		++count;
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = -5; i < 6; ++i) {
		this->_xdash0->Text = Convert::ToString(i);
		button1_Click(sender, e);
	}

}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

