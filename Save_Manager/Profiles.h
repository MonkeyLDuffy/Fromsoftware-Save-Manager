#pragma once

#include <vector>
#include <iostream>
#include <filesystem>
#include <Windows.h>

#include "Rename.h"
#include "Confirm_Delete.h"

namespace fs = std::filesystem;



namespace SaveManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Profiles
	/// </summary>
	public ref class Profiles : public System::Windows::Forms::Form
	{
	public:
		Profiles(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Profiles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ profiles_selected_game;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ browse_save_button;
	private: System::Windows::Forms::Label^ save_path_display_label;




	private: System::Windows::Forms::Label^ save_path_label;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ profiles_listbox;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ new_profile_button;
	private: System::Windows::Forms::Button^ delete_profile_button;
	private: System::Windows::Forms::Button^ rename_profile_button;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->profiles_selected_game = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->browse_save_button = (gcnew System::Windows::Forms::Button());
			this->save_path_display_label = (gcnew System::Windows::Forms::Label());
			this->save_path_label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->profiles_listbox = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->new_profile_button = (gcnew System::Windows::Forms::Button());
			this->delete_profile_button = (gcnew System::Windows::Forms::Button());
			this->rename_profile_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// profiles_selected_game
			// 
			this->profiles_selected_game->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->profiles_selected_game->FormattingEnabled = true;
			this->profiles_selected_game->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Dark Souls", L"Dark Souls: Remastered",
					L"Dark Souls II", L"Dark Souls II: SotFS", L"Dark Souls III", L"Sekiro: Shadows Die Twice", L"ELDEN RING"
			});
			this->profiles_selected_game->Location = System::Drawing::Point(15, 25);
			this->profiles_selected_game->Name = L"profiles_selected_game";
			this->profiles_selected_game->Size = System::Drawing::Size(160, 21);
			this->profiles_selected_game->TabIndex = 0;
			this->profiles_selected_game->SelectedIndexChanged += gcnew System::EventHandler(this, &Profiles::profiles_selected_game_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Selected Game:";
			// 
			// browse_save_button
			// 
			this->browse_save_button->Location = System::Drawing::Point(12, 74);
			this->browse_save_button->Name = L"browse_save_button";
			this->browse_save_button->Size = System::Drawing::Size(75, 23);
			this->browse_save_button->TabIndex = 3;
			this->browse_save_button->Text = L"Browse";
			this->browse_save_button->UseVisualStyleBackColor = true;
			this->browse_save_button->Click += gcnew System::EventHandler(this, &Profiles::button1_Click);
			// 
			// save_path_display_label
			// 
			this->save_path_display_label->AutoSize = true;
			this->save_path_display_label->Location = System::Drawing::Point(12, 58);
			this->save_path_display_label->Name = L"save_path_display_label";
			this->save_path_display_label->Size = System::Drawing::Size(97, 13);
			this->save_path_display_label->TabIndex = 4;
			this->save_path_display_label->Text = L"Current Save Path:";
			// 
			// save_path_label
			// 
			this->save_path_label->AutoSize = true;
			this->save_path_label->Location = System::Drawing::Point(115, 58);
			this->save_path_label->Name = L"save_path_label";
			this->save_path_label->Size = System::Drawing::Size(0, 13);
			this->save_path_label->TabIndex = 5;
			this->save_path_label->Click += gcnew System::EventHandler(this, &Profiles::save_path_label_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Profiles:";
			// 
			// profiles_listbox
			// 
			this->profiles_listbox->FormattingEnabled = true;
			this->profiles_listbox->Location = System::Drawing::Point(12, 125);
			this->profiles_listbox->Name = L"profiles_listbox";
			this->profiles_listbox->Size = System::Drawing::Size(418, 199);
			this->profiles_listbox->TabIndex = 7;
			// 
			// new_profile_button
			// 
			this->new_profile_button->Location = System::Drawing::Point(436, 125);
			this->new_profile_button->Name = L"new_profile_button";
			this->new_profile_button->Size = System::Drawing::Size(75, 23);
			this->new_profile_button->TabIndex = 8;
			this->new_profile_button->Text = L"New";
			this->new_profile_button->UseVisualStyleBackColor = true;
			this->new_profile_button->Click += gcnew System::EventHandler(this, &Profiles::new_profile_button_Click);
			// 
			// delete_profile_button
			// 
			this->delete_profile_button->Location = System::Drawing::Point(436, 183);
			this->delete_profile_button->Name = L"delete_profile_button";
			this->delete_profile_button->Size = System::Drawing::Size(75, 23);
			this->delete_profile_button->TabIndex = 9;
			this->delete_profile_button->Text = L"Delete";
			this->delete_profile_button->UseVisualStyleBackColor = true;
			this->delete_profile_button->Click += gcnew System::EventHandler(this, &Profiles::delete_profile_button_Click);
			// 
			// rename_profile_button
			// 
			this->rename_profile_button->Cursor = System::Windows::Forms::Cursors::Default;
			this->rename_profile_button->Location = System::Drawing::Point(436, 154);
			this->rename_profile_button->Name = L"rename_profile_button";
			this->rename_profile_button->Size = System::Drawing::Size(75, 23);
			this->rename_profile_button->TabIndex = 10;
			this->rename_profile_button->Text = L"Rename";
			this->rename_profile_button->UseVisualStyleBackColor = true;
			this->rename_profile_button->Click += gcnew System::EventHandler(this, &Profiles::rename_profile_button_Click);
			// 
			// Profiles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(523, 330);
			this->Controls->Add(this->rename_profile_button);
			this->Controls->Add(this->delete_profile_button);
			this->Controls->Add(this->new_profile_button);
			this->Controls->Add(this->profiles_listbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->save_path_label);
			this->Controls->Add(this->save_path_display_label);
			this->Controls->Add(this->browse_save_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->profiles_selected_game);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Profiles";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Profiles";
			this->Activated += gcnew System::EventHandler(this, &Profiles::Profiles_Activated);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Profiles::Profiles_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Profiles::Profiles_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Profiles_Load(System::Object^ sender, System::EventArgs^ e) {

		profiles_selected_game->SelectedIndex = current_selected_game;

		std::string profiles_path = game_index_to_path(profiles_selected_game->SelectedIndex);

		populate_listbox(profiles_path, profiles_listbox);

		std::string save_txt_path = game_index_to_path(profiles_selected_game->SelectedIndex) + "save_path.txt";
		std::string save_path = read_text_file(save_txt_path);
		save_path_label->Text = gcnew System::String(save_path.c_str());


	}
private: System::Void profiles_selected_game_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	profiles_current_selected_game = profiles_selected_game->SelectedIndex;

	std::string profiles_path = game_index_to_path(profiles_selected_game->SelectedIndex);

	populate_listbox(profiles_path, profiles_listbox);

	std::string save_txt_path = game_index_to_path(profiles_selected_game->SelectedIndex) + "save_path.txt";
	std::string save_path = read_text_file(save_txt_path);
	save_path_label->Text = gcnew System::String(save_path.c_str());

}
private: System::Void save_path_label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Runs when 'Browse' button clicked
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ file_path = openFileDialog1->FileName;

		std::string file_path_str = msclr::interop::marshal_as<std::string>(file_path);

		std::string save_txt_path = game_index_to_path(profiles_selected_game->SelectedIndex) + "save_path.txt";

		write_text_file(save_txt_path, file_path_str);

		save_path_label->Text = file_path;
	}
}

private: System::Void delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (profiles_listbox->SelectedItem == nullptr)
		return;

	// Check if confirmation is required
	if (read_text_file("Settings/require_delete_confirmation.txt") == "true") {
		save_name_storage = msclr::interop::marshal_as<std::string>(profiles_listbox->SelectedItem->ToString());
		delete_confirmation = false;

		Confirm_Delete^ confirm_delete = gcnew Confirm_Delete();
		set_window_position(this, confirm_delete);
		confirm_delete->ShowDialog();

		if (!delete_confirmation) {
			return;
		}
	}

	std::string delete_path = game_index_to_path(profiles_selected_game->SelectedIndex) + msclr::interop::marshal_as<std::string>(profiles_listbox->SelectedItem->ToString());
	fs::remove(delete_path);

	std::string profiles_path = game_index_to_path(profiles_selected_game->SelectedIndex);
	populate_listbox(profiles_path, profiles_listbox);

}

private: System::Void new_profile_button_Click(System::Object^ sender, System::EventArgs^ e) {
	entry_mode = "new profile";
	to_rename = game_index_to_path(profiles_current_selected_game);

	Rename^ rename = gcnew Rename();
	set_window_position(this, rename);
	rename->ShowDialog();

	std::string profiles_path = game_index_to_path(profiles_selected_game->SelectedIndex);
	populate_listbox(profiles_path, profiles_listbox);
}


private: System::Void Profiles_Activated(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void rename_profile_button_Click(System::Object^ sender, System::EventArgs^ e) {
	entry_mode = "rename profile";
	to_rename = msclr::interop::marshal_as<std::string>(profiles_listbox->SelectedItem->ToString());



	Rename^ rename = gcnew Rename();
	set_window_position(this, rename);
	rename->ShowDialog();

	std::string profiles_path = game_index_to_path(profiles_selected_game->SelectedIndex);
	populate_listbox(profiles_path, profiles_listbox);
}
private: System::Void Profiles_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {

	//refresh_profile_combobox();
}
};
}
