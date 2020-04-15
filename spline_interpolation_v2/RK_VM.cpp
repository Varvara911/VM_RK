#include "Form1.h"

using namespace vm_2;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<System::String^> ^args){
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false); 
  Application::Run(gcnew Form1());
  return 0;
}
