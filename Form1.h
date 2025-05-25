#pragma once // �������, �� ������������ ���� ���� ��������� ���� ���� ��� ��� ���������

#include <cmath>         // ϳ��������� ������������ ������� (���� �� ��������������� �������)
#include <fstream>       // ��� ������ � ������� (�� ��������������� �������������, ��� ������� ��� ����������)

namespace CarDistanceApp { // ���������� �������� ���� ��� ��������� �������� ����

	using namespace System; // ������������ ���������� �������� ���� .NET
	using namespace System::ComponentModel; // ��� ����������� ����� (���� ���� ������� ��� �����)
	using namespace System::Collections;     // �������� .NET (�� ��������������� ��� ����)
	using namespace System::Windows::Forms;  // ������ ����� ��� ��������� WinForms GUI
	using namespace System::Data;            // ��� ������ � ������ (�� ���������������)
	using namespace System::Drawing;         // ��� ������ � ��������/������������ � UI
	using namespace System::IO;              // ��� �������/������ � �����

	public ref class Form1 : public System::Windows::Forms::Form // ���������� ������� �����, ��� ������ �� Form
	{
	public:
		Form1(void) // ����������� �����
		{
			InitializeComponent(); // ����������� UI-����������
		}

	protected:
		~Form1() // ���������� �����
		{
			if (components) // ��������, �� ������� ����������
			{
				delete components; // ��������� �������
			}
		}

	private:
		// ���������� �������� ����������
		Label^ labelV1;          // ̳��� ��� �������� �������� V1
		Label^ labelV2;          // ̳��� ��� V2
		Label^ labelS;           // ̳��� ��� ��������� ������ S
		Label^ labelT;           // ̳��� ��� ���� T
		TextBox^ txtV1;          // ���� �������� V1
		TextBox^ txtV2;          // ���� �������� V2
		TextBox^ txtS;           // ���� �������� ������
		TextBox^ txtT;           // ���� �������� ����
		Button^ btnCalculate;    // ������ ��� ����������
		TextBox^ txtResult;      // ���� ������ ����������
		Button^ btnLoadFile;     // ������ ��� ������������ ����� � �����
		Button^ btnSaveFile;     // ������ ��� ���������� ���������� � ����
		OpenFileDialog^ openFileDialog; // ĳ���� ������ ����� ��� �������
		SaveFileDialog^ saveFileDialog; // ĳ���� ������ ����� ��� ����������
		System::ComponentModel::IContainer^ components; // ��������� ��� ����������

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) // ����� ��� ����������� UI-����������
		{
			// ����������� ����
			this->labelV1 = gcnew Label();
			this->labelV2 = gcnew Label();
			this->labelS = gcnew Label();
			this->labelT = gcnew Label();

			// ����������� ����������
			this->txtV1 = gcnew TextBox();
			this->txtV2 = gcnew TextBox();
			this->txtS = gcnew TextBox();
			this->txtT = gcnew TextBox();

			// ����������� ������
			this->btnCalculate = gcnew Button();
			this->btnLoadFile = gcnew Button();
			this->btnSaveFile = gcnew Button();

			// ����������� ���� ����������
			this->txtResult = gcnew TextBox();

			// ĳ����� ��� ������ � �������
			this->openFileDialog = gcnew OpenFileDialog();
			this->saveFileDialog = gcnew SaveFileDialog();

			this->SuspendLayout(); // ������������ ������� ��� ������ �����������

			// ---- ������������ ������������ ���� ----
			this->labelV1->Text = L"V1 (��/���):";
			this->labelV1->Location = Point(20, 20);
			this->labelV1->Size = Drawing::Size(80, 20);

			this->labelV2->Text = L"V2 (��/���):";
			this->labelV2->Location = Point(20, 60);
			this->labelV2->Size = Drawing::Size(80, 20);

			this->labelS->Text = L"S (��):";
			this->labelS->Location = Point(20, 100);
			this->labelS->Size = Drawing::Size(80, 20);

			this->labelT->Text = L"T (���):";
			this->labelT->Location = Point(20, 140);
			this->labelT->Size = Drawing::Size(80, 20);

			// ---- ������������ ���������� ----
			this->txtV1->Location = Point(110, 18);
			this->txtV1->Size = Drawing::Size(150, 25);

			this->txtV2->Location = Point(110, 58);
			this->txtV2->Size = Drawing::Size(150, 25);

			this->txtS->Location = Point(110, 98);
			this->txtS->Size = Drawing::Size(150, 25);

			this->txtT->Location = Point(110, 138);
			this->txtT->Size = Drawing::Size(150, 25);

			// ---- ������ ----
			this->btnCalculate->Text = L"���������";
			this->btnCalculate->Location = Point(20, 180);
			this->btnCalculate->Size = Drawing::Size(90, 30);
			this->btnCalculate->Click += gcnew EventHandler(this, &Form1::btnCalculate_Click); // ����'���� ��䳿 ����������
			this->btnLoadFile->Text = L"������� � �����";
			this->btnLoadFile->Location = Point(130, 180);
			this->btnLoadFile->Size = Drawing::Size(110, 30);
			this->btnLoadFile->Click += gcnew EventHandler(this, &Form1::btnLoadFile_Click);
			this->btnSaveFile->Text = L"�������� � ����";
			this->btnSaveFile->Location = Point(260, 180);
			this->btnSaveFile->Size = Drawing::Size(110, 30);
			this->btnSaveFile->Click += gcnew EventHandler(this, &Form1::btnSaveFile_Click);

			// ---- ���� ���������� ----
			this->txtResult->Location = Point(20, 220);
			this->txtResult->Size = Drawing::Size(350, 60);
			this->txtResult->Multiline = true;
			this->txtResult->ReadOnly = true;
			this->txtResult->ScrollBars = ScrollBars::Vertical;

			// ---- ���������� ����� ----
			this->ClientSize = Drawing::Size(400, 300); // ����� ����
			this->Controls->Add(this->labelV1);
			this->Controls->Add(this->labelV2);
			this->Controls->Add(this->labelS);
			this->Controls->Add(this->labelT);
			this->Controls->Add(this->txtV1);
			this->Controls->Add(this->txtV2);
			this->Controls->Add(this->txtS);
			this->Controls->Add(this->txtT);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->btnLoadFile);
			this->Controls->Add(this->btnSaveFile);
			this->Controls->Add(this->txtResult);

			this->Text = L"���������� ������ �� �����������"; // ��������� ����
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Գ�������� �����
			this->MaximizeBox = false; // ���������� ����������� ����

			this->ResumeLayout(false); // ³������� ����������� �������
			this->PerformLayout();     // ��������� �������� �������
		}
#pragma endregion

	private: System::Void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// ���������� ������� � ����������
			double V1 = Double::Parse(txtV1->Text);
			double V2 = Double::Parse(txtV2->Text);
			double S = Double::Parse(txtS->Text);
			double T = Double::Parse(txtT->Text);

			// �������� �� ���������
			if (V1 < 0 || V2 < 0 || S < 0 || T < 0) {
				MessageBox::Show("��������, ������� � ��� ������ ���� ��������� �������.", "������� ��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// ���������� ������ �� ����������� ����� T �����
			double distance = Math::Abs(S - T * (V1 + V2));

			// ���� ���������� � ���������
			txtResult->Text = "³������ �� ����������� ����� " + T.ToString("F2") + " ���: " + distance.ToString("F2") + " ��";
		}
		catch (FormatException^) {
			// ������� ��� ����������� �������� �������
			MessageBox::Show("���� �����, ������ ������� ������ ��������.", "������� �������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			// ���� ����������
			MessageBox::Show("������� �������: " + ex->Message, "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnLoadFile_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				// ���������� ��� ����� � ��������� �����
				array<String^>^ lines = File::ReadAllLines(openFileDialog->FileName);
				if (lines->Length >= 4) {
					// ��������� ������� �����������
					txtV1->Text = lines[0];
					txtV2->Text = lines[1];
					txtS->Text = lines[2];
					txtT->Text = lines[3];
				}
				else {
					// ���� �� ����������� �����
					MessageBox::Show("���� ������� ������ ���������� 4 �����: V1, V2, S, T.", "������� �����", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			catch (Exception^ ex) {
				// ������� ������� �����
				MessageBox::Show("�� ������� ��������� ����: " + ex->Message, "������� �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void btnSaveFile_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				// ����� ���������� � �������� ����
				File::WriteAllText(saveFileDialog->FileName, txtResult->Text);
				MessageBox::Show("��������� ������ ���������.", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				// ������� ��� ���������
				MessageBox::Show("�� ������� �������� ����: " + ex->Message, "������� �����", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	};
}
