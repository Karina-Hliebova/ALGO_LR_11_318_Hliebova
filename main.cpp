#include "pch.h" // ϳ��������� ���-������������� ���������. �������� ��������������� ��� ����������� ���������, ������ ����� �������������� ���������.

#include "Form1.h" // ϳ��������� ��������� ����� Form1, ��� ������ ���� ��������� ��������� ��������.

using namespace System; // ϳ��������� �������� ���� .NET System, ���� ������ ����� ���� (���������, String, Int32 ����).
using namespace System::ComponentModel; // ������ ���� ��� ���������� (�� ���������� ����� ��������������� ���, ��� ���� ���� ������� ��� WinForms).
using namespace System::Collections; // ������ ���� ��� �������� .NET (ArrayList, Hashtable ����).
using namespace System::Windows::Forms; // �������� ������ ���� ��� ������ � Windows Forms � ����������� �����������.
using namespace System::Data; // ������ ���� ��� ������ � ������, ��-�� DataSet, DataTable ���� (���� ���� �� ������������ �����).
using namespace System::Drawing; // ������ ���� ��� ������ � �������� � ���������, ��������, ������� ����.
using namespace System::IO; // ������ ���� ��� ������ � ������� �� �������� ��������/���������.

[STAThreadAttribute] // �������, �� ����� �� ������������ ������ ������ (Single Threaded Apartment), ����������� ��� �������� ������ WinForms (�������� � ���������� ����������, ��-�� ������).

int main(array<String^>^ args) // ����� ����� � ��������. ������ ����� ��������� ���������� ����� (���� �).
{
    Application::EnableVisualStyles(); // ��������� ����� Windows ��� ��������� ������� ������, ���� �� ����� ��������.

    Application::SetCompatibleTextRenderingDefault(false); // ���������� ����� ���������� ������. false ������ ������������ GDI+ ��� ����������� ������ (����� ��� ���������� �� ����� ������).

    CarDistanceApp::Form1 form; // ��������� ���������� ������� ����� Form1 � �������� ���� CarDistanceApp.

    Application::Run(% form); // ������� ����� �� ������� ���� ��������. % ������ �������� ��������� �� form (tracking reference � C++/CLI).
    return 0; // ���������� ���� ����������.
}
