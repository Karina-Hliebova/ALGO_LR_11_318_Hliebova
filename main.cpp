#include "pch.h" // Підключення пре-компільованого заголовка. Зазвичай використовується для прискорення компіляції, містить часто використовувані заголовки.

#include "Form1.h" // Підключення заголовка форми Form1, яка містить весь графічний інтерфейс програми.

using namespace System; // Підключення простору імен .NET System, який містить базові типи (наприклад, String, Int32 тощо).
using namespace System::ComponentModel; // Простір імен для компонентів (не обов’язково прямо використовується тут, але може бути потрібен для WinForms).
using namespace System::Collections; // Простір імен для колекцій .NET (ArrayList, Hashtable тощо).
using namespace System::Windows::Forms; // Основний простір імен для роботи з Windows Forms — інтерфейсом користувача.
using namespace System::Data; // Простір імен для роботи з даними, як-от DataSet, DataTable тощо (може бути не використаний прямо).
using namespace System::Drawing; // Простір імен для роботи з графікою — кольорами, шрифтами, формами тощо.
using namespace System::IO; // Простір імен для роботи з файлами та потоками введення/виведення.

[STAThreadAttribute] // Атрибут, що вказує на використання одного потоку (Single Threaded Apartment), обов’язковий для коректної роботи WinForms (особливо з елементами інтерфейсу, як-от діалоги).

int main(array<String^>^ args) // Точка входу в програму. Приймає масив аргументів командного рядка (якщо є).
{
    Application::EnableVisualStyles(); // Увімкнення стилів Windows для сучасного вигляду кнопок, форм та інших елементів.

    Application::SetCompatibleTextRenderingDefault(false); // Встановлює режим рендерингу тексту. false означає використання GDI+ для відображення тексту (краще для локалізації та нових шрифтів).

    CarDistanceApp::Form1 form; // Створення екземпляру головної форми Form1 з простору імен CarDistanceApp.

    Application::Run(% form); // Запускає форму як головне вікно програми. % означає передачу посилання на form (tracking reference у C++/CLI).
    return 0; // Повернення коду завершення.
}
