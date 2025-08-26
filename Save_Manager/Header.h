#include <algorithm>
#include <filesystem>
#include <fstream>
#include <msclr/marshal_cppstd.h>

#pragma once
namespace fs = std::filesystem;

// This header contains many helper functions used throughout the program

std::vector<std::string> read_folders(fs::path path) {
    std::vector<std::string> folder_list;

    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_directory(entry)) {
            std::string temp = entry.path().filename().string();
            folder_list.push_back(temp);
        }
    }
    return folder_list;
}

void populate_listbox(fs::path path, System::Windows::Forms::ListBox^ listbox) {
    std::vector<std::string> folder_list = read_folders(path);


    listbox->Items->Clear();

    if (folder_list.empty()) {
        return;
    }

    for (const auto& str : folder_list) {
        System::String^ itemString = gcnew System::String(str.c_str());

        listbox->Items->Add(itemString);
    }
}

// Helper to get current time in microseconds
int64_t get_current_time_microseconds() {
    auto now = std::chrono::system_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    return now_us.time_since_epoch().count();
}

void populate_listbox_sorted(const std::filesystem::path& save_path, System::Windows::Forms::ListBox^ listbox, int sort_mode) {
    std::vector<std::string> items = read_folders(save_path);

    if (sort_mode == 0) { // Alphabetical
        std::sort(items.begin(), items.end());
    }
    else { // Created Time
        std::vector<std::pair<std::string, int64_t>> time_items;
        for (const auto& name : items) {
            std::filesystem::path created_file_path = save_path / name / "created.txt";
            int64_t timestamp = 0;
            if (std::filesystem::exists(created_file_path)) {
                std::ifstream created_file(created_file_path.string());
                created_file >> timestamp;
                created_file.close();
            }
            else {
                // File doesn't exist, create it with current time
                timestamp = get_current_time_microseconds();
                std::ofstream created_file(created_file_path.string());
                created_file << timestamp;
                created_file.close();
            }
            time_items.push_back({ name, timestamp });
        }
        // Sort by timestamp, then alphabetically if timestamps are equal
        std::sort(time_items.begin(), time_items.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
            });
        items.clear();
        for (const auto& pair : time_items)
            items.push_back(pair.first);
    }

    listbox->Items->Clear();
    for (const auto& str : items) {
        System::String^ itemString = gcnew System::String(str.c_str());
        listbox->Items->Add(itemString);
    }
}

void populate_combobox(fs::path path, System::Windows::Forms::ComboBox^ combobox) {
    std::vector<std::string> folder_list = read_folders(path);

    combobox->Items->Clear();

    for (const auto& str : folder_list) {
        System::String^ itemString = gcnew System::String(str.c_str());

        combobox->Items->Add(itemString);
    }
}

std::string game_index_to_path(int game_index) { // This function takes in the selected index of the game combo box and returns a path to the saves for that game
std::string path;
    switch (game_index) {
    case 0:
        path = "Saves/Dark Souls/";
        break;

    case 1:
        path = "Saves/Dark Souls Remastered/";
        break;

    case 2:
        path = "Saves/Dark Souls II/";
        break;

    case 3:
        path = "Saves/Dark Souls II SotFS/";
        break;

    case 4:
        path = "Saves/Dark Souls III/";
        break;

    case 5:
        path = "Saves/Sekiro Shadows Die Twice/";
        break;

    case 6:
        path = "Saves/ELDEN RING/";
        break;
    }

    return path;
}

std::string combobox_selected_to_string(System::Windows::Forms::ComboBox^ combobox) {
    System::String^ current_selection;

    if (combobox->SelectedIndex == -1) {
        current_selection = "";
    }
    else {
        current_selection = combobox->SelectedItem->ToString();
    }

    std::string current_selection_std_str = msclr::interop::marshal_as<std::string>(current_selection);
    return current_selection_std_str;
}

std::string listbox_selected_to_string(System::Windows::Forms::ListBox^ listbox) {
    System::String^ current_selection = listbox->SelectedItem->ToString();
    std::string current_selection_std_str = msclr::interop::marshal_as<std::string>(current_selection);
    return current_selection_std_str;
}

std::string read_text_file(const std::string& file_path) {
    std::ifstream input_file(file_path);
    std::string file_contents;
    if (input_file.is_open()) {
        std::getline(input_file, file_contents);
        input_file.close();
    }
    return file_contents;
}

void write_text_file(const std::string& file_path, const std::string& content) {
    std::ofstream outFile(file_path, std::ofstream::trunc);
    outFile << content;
    outFile.close();
}

System::String^ convert_to_system_string(std::string str) {
    return msclr::interop::marshal_as<System::String^>(str);
}

std::string convert_to_std_string(System::String^ str) {
    return msclr::interop::marshal_as<std::string>(str);
}

std::string get_file_name(const std::string& path) {
    size_t last_slash_pos = path.find_last_of('\\');
    if (last_slash_pos != std::string::npos && last_slash_pos + 1 < path.length()) {
        return path.substr(last_slash_pos + 1);
    }
    return "";
}

void set_window_position(System::Windows::Forms::Form^ main_window, System::Windows::Forms::Form^ child_window)
{
    int centerX = main_window->Location.X + main_window->Size.Width / 2;
    int centerY = main_window->Location.Y + main_window->Size.Height / 2;

    int child_window_X = centerX - child_window->Size.Width / 2;
    int child_window_Y = centerY - child_window->Size.Height / 2;

    child_window->Location = System::Drawing::Point(child_window_X, child_window_Y);
}

// Reads a text file, creates it with default_value if missing
inline std::string read_or_create_text_file(const fs::path& path, const std::string& default_value) {
    if (!fs::exists(path)) {
        std::ofstream ofs(path);
        ofs << default_value;
        ofs.close();
        return default_value;
    }
    std::ifstream ifs(path);
    std::string content;
    std::getline(ifs, content);
    ifs.close();
    return content;
}

/* Currently not used for anything
std::string str_tolower(const std::string& str) {
    std::string lower_str = str;

    for (char& c : lower_str) {
        c = std::tolower(c);
    }

    return lower_str;
}
*/

