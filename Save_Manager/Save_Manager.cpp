#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <string>

namespace fs = std::filesystem;

int current_selected_game; // This is to keep track of the currently selected game between the different forms
int profiles_current_selected_game; // This is to keep track of the currently selected game in the profile menu
std::string current_selected_profile;
std::string current_selected_save;
std::string entry_mode; // This is to tell the profile menu whether to create a new folder with the entered name or to rename the selected profile
std::string to_rename;
std::string item_storage = ""; // This string is used to store the entered name of a new profile in order to select it in the profiles combo box on the main form
std::string save_name_storage;
bool delete_confirmation = false;
int center_x;
int center_y;


#include "Header.h"
#include "Save_Manager.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew SaveManager::Save_Manager());
    return 0;
}