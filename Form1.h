#pragma once // Гарантує, що заголовочний файл буде включений лише один раз при компіляції

#include <cmath>         // Підключення математичних функцій (хоча не використовується напряму)
#include <fstream>       // Для роботи з файлами (не використовується безпосередньо, але можливо для розширення)

namespace CarDistanceApp { // Оголошення простору імен для уникнення конфліктів назв

	using namespace System; // Імпортування системного простору імен .NET
	using namespace System::ComponentModel; // Для компонентної моделі (може бути потрібне для форми)
	using namespace System::Collections;     // Колекції .NET (не використовується тут явно)
	using namespace System::Windows::Forms;  // Основні класи для створення WinForms GUI
	using namespace System::Data;            // Для роботи з даними (не використовується)
	using namespace System::Drawing;         // Для роботи з графікою/координатами в UI
	using namespace System::IO;              // Для читання/запису у файли

	public ref class Form1 : public System::Windows::Forms::Form // Оголошення головної форми, яка наслідує від Form
	{
	public:
		Form1(void) // Конструктор форми
		{
			InitializeComponent(); // Ініціалізація UI-компонентів
		}

	protected:
		~Form1() // Деструктор форми
		{
			if (components) // Перевірка, чи існують компоненти
			{
				delete components; // Звільнення ресурсів
			}
		}

	private:
		// Оголошення елементів інтерфейсу
		Label^ labelV1;          // Мітка для введення швидкості V1
		Label^ labelV2;          // Мітка для V2
		Label^ labelS;           // Мітка для початкової відстані S
		Label^ labelT;           // Мітка для часу T
		TextBox^ txtV1;          // Поле введення V1
		TextBox^ txtV2;          // Поле введення V2
		TextBox^ txtS;           // Поле введення відстані
		TextBox^ txtT;           // Поле введення часу
		Button^ btnCalculate;    // Кнопка для обчислення
		TextBox^ txtResult;      // Поле виводу результату
		Button^ btnLoadFile;     // Кнопка для завантаження даних з файлу
		Button^ btnSaveFile;     // Кнопка для збереження результату у файл
		OpenFileDialog^ openFileDialog; // Діалог вибору файлу для читання
		SaveFileDialog^ saveFileDialog; // Діалог вибору файлу для збереження
		System::ComponentModel::IContainer^ components; // Контейнер для компонентів

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) // Метод для ініціалізації UI-компонентів
		{
			// Ініціалізація міток
			this->labelV1 = gcnew Label();
			this->labelV2 = gcnew Label();
			this->labelS = gcnew Label();
			this->labelT = gcnew Label();

			// Ініціалізація текстбоксів
			this->txtV1 = gcnew TextBox();
			this->txtV2 = gcnew TextBox();
			this->txtS = gcnew TextBox();
			this->txtT = gcnew TextBox();

			// Ініціалізація кнопок
			this->btnCalculate = gcnew Button();
			this->btnLoadFile = gcnew Button();
			this->btnSaveFile = gcnew Button();

			// Ініціалізація поля результату
			this->txtResult = gcnew TextBox();

			// Діалоги для роботи з файлами
			this->openFileDialog = gcnew OpenFileDialog();
			this->saveFileDialog = gcnew SaveFileDialog();

			this->SuspendLayout(); // Призупинення розмітки для швидшої ініціалізації

			// ---- Налаштування властивостей міток ----
			this->labelV1->Text = L"V1 (км/год):";
			this->labelV1->Location = Point(20, 20);
			this->labelV1->Size = Drawing::Size(80, 20);

			this->labelV2->Text = L"V2 (км/год):";
			this->labelV2->Location = Point(20, 60);
			this->labelV2->Size = Drawing::Size(80, 20);

			this->labelS->Text = L"S (км):";
			this->labelS->Location = Point(20, 100);
			this->labelS->Size = Drawing::Size(80, 20);

			this->labelT->Text = L"T (год):";
			this->labelT->Location = Point(20, 140);
			this->labelT->Size = Drawing::Size(80, 20);

			// ---- Налаштування текстбоксів ----
			this->txtV1->Location = Point(110, 18);
			this->txtV1->Size = Drawing::Size(150, 25);

			this->txtV2->Location = Point(110, 58);
			this->txtV2->Size = Drawing::Size(150, 25);

			this->txtS->Location = Point(110, 98);
			this->txtS->Size = Drawing::Size(150, 25);

			this->txtT->Location = Point(110, 138);
			this->txtT->Size = Drawing::Size(150, 25);

			// ---- Кнопки ----
			this->btnCalculate->Text = L"Обчислити";
			this->btnCalculate->Location = Point(20, 180);
			this->btnCalculate->Size = Drawing::Size(90, 30);
			this->btnCalculate->Click += gcnew EventHandler(this, &Form1::btnCalculate_Click); // Прив'язка події натискання
			this->btnLoadFile->Text = L"Зчитати з файлу";
			this->btnLoadFile->Location = Point(130, 180);
			this->btnLoadFile->Size = Drawing::Size(110, 30);
			this->btnLoadFile->Click += gcnew EventHandler(this, &Form1::btnLoadFile_Click);
			this->btnSaveFile->Text = L"Зберегти у файл";
			this->btnSaveFile->Location = Point(260, 180);
			this->btnSaveFile->Size = Drawing::Size(110, 30);
			this->btnSaveFile->Click += gcnew EventHandler(this, &Form1::btnSaveFile_Click);

			// ---- Поле результату ----
			this->txtResult->Location = Point(20, 220);
			this->txtResult->Size = Drawing::Size(350, 60);
			this->txtResult->Multiline = true;
			this->txtResult->ReadOnly = true;
			this->txtResult->ScrollBars = ScrollBars::Vertical;

			// ---- Властивості форми ----
			this->ClientSize = Drawing::Size(400, 300); // Розмір вікна
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

			this->Text = L"Обчислення відстані між автомобілями"; // Заголовок вікна
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Фіксований розмір
			this->MaximizeBox = false; // Заборонити розгортання вікна

			this->ResumeLayout(false); // Відновити автоматичну розмітку
			this->PerformLayout();     // Примусово виконати розмітку
		}
#pragma endregion

	private: System::Void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Зчитування значень з текстбоксів
			double V1 = Double::Parse(txtV1->Text);
			double V2 = Double::Parse(txtV2->Text);
			double S = Double::Parse(txtS->Text);
			double T = Double::Parse(txtT->Text);

			// Перевірка на додатність
			if (V1 < 0 || V2 < 0 || S < 0 || T < 0) {
				MessageBox::Show("Швидкості, відстань і час повинні бути додатними числами.", "Помилка введення", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Обчислення відстані між автомобілями через T годин
			double distance = Math::Abs(S - T * (V1 + V2));

			// Вивід результату у текстбокс
			txtResult->Text = "Відстань між автомобілями через " + T.ToString("F2") + " год: " + distance.ToString("F2") + " км";
		}
		catch (FormatException^) {
			// Помилка при перетворенні введених значень
			MessageBox::Show("Будь ласка, введіть коректні числові значення.", "Помилка формату", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			// Інші виключення
			MessageBox::Show("Сталася помилка: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnLoadFile_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				// Зчитування всіх рядків з вибраного файлу
				array<String^>^ lines = File::ReadAllLines(openFileDialog->FileName);
				if (lines->Length >= 4) {
					// Присвоєння значень текстбоксам
					txtV1->Text = lines[0];
					txtV2->Text = lines[1];
					txtS->Text = lines[2];
					txtT->Text = lines[3];
				}
				else {
					// Файл має недостатньо рядків
					MessageBox::Show("Файл повинен містити щонайменше 4 рядки: V1, V2, S, T.", "Помилка файлу", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			catch (Exception^ ex) {
				// Помилка читання файлу
				MessageBox::Show("Не вдалося прочитати файл: " + ex->Message, "Помилка файлу", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void btnSaveFile_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				// Запис результату у вибраний файл
				File::WriteAllText(saveFileDialog->FileName, txtResult->Text);
				MessageBox::Show("Результат успішно збережено.", "Збереження", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				// Помилка при збереженні
				MessageBox::Show("Не вдалося зберегти файл: " + ex->Message, "Помилка файлу", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	};
}
