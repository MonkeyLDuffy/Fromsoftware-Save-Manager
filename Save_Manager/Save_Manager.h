#pragma once
#include "Settings.h"
#include "Profiles.h"
#include "Confirm_Delete.h"
#include <filesystem>



namespace SaveManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Save_Manager : public System::Windows::Forms::Form
	{
	public:
		Save_Manager(void)
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
		~Save_Manager()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ saves_listbox;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ sort_by;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ selected_profile_combobox;

	private: System::Windows::Forms::TextBox^ search_box;


	private: System::Windows::Forms::Button^ Import_Button;
	private: System::Windows::Forms::Button^ Load_Button;
	private: System::Windows::Forms::Button^ Replace_Button;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ profilesToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ selected_game_combobox;

	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::PictureBox^ success_image;
	private: System::Windows::Forms::PictureBox^ error_image;


	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Save_Manager::typeid));
			this->saves_listbox = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sort_by = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->selected_profile_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->search_box = (gcnew System::Windows::Forms::TextBox());
			this->Import_Button = (gcnew System::Windows::Forms::Button());
			this->Load_Button = (gcnew System::Windows::Forms::Button());
			this->Replace_Button = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->selected_game_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->success_image = (gcnew System::Windows::Forms::PictureBox());
			this->error_image = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->success_image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error_image))->BeginInit();
			this->SuspendLayout();
			// 
			// saves_listbox
			// 
			this->saves_listbox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->saves_listbox->FormattingEnabled = true;
			this->saves_listbox->Location = System::Drawing::Point(9, 93);
			this->saves_listbox->Name = L"saves_listbox";
			this->saves_listbox->Size = System::Drawing::Size(590, 238);
			this->saves_listbox->TabIndex = 0;
			this->saves_listbox->SelectedIndexChanged += gcnew System::EventHandler(this, &Save_Manager::saves_listbox_SelectedIndexChanged);
			this->saves_listbox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Save_Manager::saves_listbox_MouseUp);

			// anchors the listbox
			this->saves_listbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Top |
				System::Windows::Forms::AnchorStyles::Bottom |
				System::Windows::Forms::AnchorStyles::Left |
				System::Windows::Forms::AnchorStyles::Right
				);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->optionsToolStripMenuItem,
					this->profilesToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(610, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->Enter += gcnew System::EventHandler(this, &Save_Manager::menuStrip1_Enter);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Settings";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Save_Manager::optionsToolStripMenuItem_Click);
			// 
			// profilesToolStripMenuItem
			// 
			this->profilesToolStripMenuItem->Name = L"profilesToolStripMenuItem";
			this->profilesToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->profilesToolStripMenuItem->Text = L"Profiles";
			this->profilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Save_Manager::profilesToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Location = System::Drawing::Point(6, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Selected Game:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Cursor = System::Windows::Forms::Cursors::Default;
			this->label2->Location = System::Drawing::Point(6, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Sort By:";
			// 
			// sort_by
			// 
			this->sort_by->Cursor = System::Windows::Forms::Cursors::Default;
			this->sort_by->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->sort_by->FormattingEnabled = true;
			this->sort_by->Location = System::Drawing::Point(56, 67);
			this->sort_by->Name = L"sort_by";
			this->sort_by->Size = System::Drawing::Size(129, 21);
			this->sort_by->TabIndex = 5;
			this->sort_by->Items->Add(L"Alphabetical");
			this->sort_by->Items->Add(L"Created Time");
			this->sort_by->SelectedIndex = 0; // Default to Alphabetical
			this->sort_by->SelectedIndexChanged += gcnew System::EventHandler(this, &Save_Manager::sort_by_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Cursor = System::Windows::Forms::Cursors::Default;
			this->label3->Location = System::Drawing::Point(188, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Selected Profile:";
			// 
			// selected_profile_combobox
			// 
			this->selected_profile_combobox->Cursor = System::Windows::Forms::Cursors::Default;
			this->selected_profile_combobox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->selected_profile_combobox->FormattingEnabled = true;
			this->selected_profile_combobox->Location = System::Drawing::Point(191, 40);
			this->selected_profile_combobox->Name = L"selected_profile_combobox";
			this->selected_profile_combobox->Size = System::Drawing::Size(408, 21);
			this->selected_profile_combobox->TabIndex = 7;
			this->selected_profile_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &Save_Manager::selected_profile_combobox_SelectedIndexChanged);
			// 
			// search_box
			// 
			this->search_box->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->search_box->Location = System::Drawing::Point(238, 67);
			this->search_box->Name = L"search_box";
			this->search_box->Size = System::Drawing::Size(361, 20);
			this->search_box->TabIndex = 8;
			this->search_box->TextChanged += gcnew System::EventHandler(this, &Save_Manager::search_box_TextChanged);
			// 
			// Import_Button
			// 
			this->Import_Button->Cursor = System::Windows::Forms::Cursors::Default;
			this->Import_Button->Location = System::Drawing::Point(12, 337);
			this->Import_Button->Name = L"Import_Button";
			this->Import_Button->Size = System::Drawing::Size(196, 30);
			this->Import_Button->TabIndex = 9;
			this->Import_Button->Text = L"Import Save";
			this->Import_Button->UseVisualStyleBackColor = true;
			this->Import_Button->Click += gcnew System::EventHandler(this, &Save_Manager::Import_Button_Click);

			this->Import_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left
				);
			// 
			// Load_Button
			// 
			this->Load_Button->Cursor = System::Windows::Forms::Cursors::Default;
			this->Load_Button->Location = System::Drawing::Point(214, 337);
			this->Load_Button->Name = L"Load_Button";
			this->Load_Button->Size = System::Drawing::Size(183, 30);
			this->Load_Button->TabIndex = 10;
			this->Load_Button->Text = L"Load Save";
			this->Load_Button->UseVisualStyleBackColor = true;
			this->Load_Button->Click += gcnew System::EventHandler(this, &Save_Manager::Load_Button_Click);

			this->Load_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left
				);
			// 
			// Replace_Button
			// 
			this->Replace_Button->Cursor = System::Windows::Forms::Cursors::Default;
			this->Replace_Button->Location = System::Drawing::Point(403, 337);
			this->Replace_Button->Name = L"Replace_Button";
			this->Replace_Button->Size = System::Drawing::Size(196, 30);
			this->Replace_Button->TabIndex = 11;
			this->Replace_Button->Text = L"Replace Save";
			this->Replace_Button->UseVisualStyleBackColor = true;
			this->Replace_Button->Click += gcnew System::EventHandler(this, &Save_Manager::Replace_Button_Click);

			this->Replace_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right
				);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Cursor = System::Windows::Forms::Cursors::Default;
			this->label4->Location = System::Drawing::Point(188, 70);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Search:";
			// 
			// selected_game_combobox
			// 
			this->selected_game_combobox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->selected_game_combobox->FormattingEnabled = true;
			this->selected_game_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Dark Souls", L"Dark Souls: Remastered",
					L"Dark Souls II", L"Dark Souls II: SotFS", L"Dark Souls III", L"Sekiro: Shadows Die Twice", L"ELDEN RING"
			});
			this->selected_game_combobox->Location = System::Drawing::Point(9, 40);
			this->selected_game_combobox->Name = L"selected_game_combobox";
			this->selected_game_combobox->Size = System::Drawing::Size(176, 21);
			this->selected_game_combobox->TabIndex = 13;
			this->selected_game_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &Save_Manager::selected_game_combobox_SelectedIndexChanged);
			// 
			// timer
			// 
			this->timer->Interval = 3000;
			this->timer->Tick += gcnew System::EventHandler(this, &Save_Manager::timer_Tick);
			// 
			// success_image
			// 
			this->success_image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"success_image.Image")));
			this->success_image->Location = System::Drawing::Point(170, 164);
			this->success_image->Name = L"success_image";
			this->success_image->Size = System::Drawing::Size(254, 103);
			this->success_image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->success_image->TabIndex = 14;
			this->success_image->TabStop = false;
			this->success_image->Visible = false;
			// 
			// error_image
			// 
			this->error_image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"error_image.Image")));
			this->error_image->Location = System::Drawing::Point(126, 164);
			this->error_image->Name = L"error_image";
			this->error_image->Size = System::Drawing::Size(349, 103);
			this->error_image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->error_image->TabIndex = 15;
			this->error_image->TabStop = false;
			this->error_image->Visible = false;
			// 
			// Save_Manager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(610, 375);
			this->Controls->Add(this->error_image);
			this->Controls->Add(this->success_image);
			this->Controls->Add(this->selected_game_combobox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Replace_Button);
			this->Controls->Add(this->Load_Button);
			this->Controls->Add(this->Import_Button);
			this->Controls->Add(this->search_box);
			this->Controls->Add(this->selected_profile_combobox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->sort_by);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->saves_listbox);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Save_Manager";
			this->ShowIcon = false;
			this->Text = L"Jackson's Awesome Save Manager";
			this->Activated += gcnew System::EventHandler(this, &Save_Manager::Save_Manager_Activated);
			this->Load += gcnew System::EventHandler(this, &Save_Manager::Save_Manager_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->success_image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->error_image))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void Save_Manager_Load(System::Object^ sender, System::EventArgs^ e) {

		try {
			selected_game_combobox->SelectedIndex = stoi(read_text_file("Settings/last_game.txt"));
		}
		catch (...) {
			selected_game_combobox->SelectedIndex = 0;
		}


		fs::path profile_path = game_index_to_path(selected_game_combobox->SelectedIndex);
		populate_combobox(profile_path, selected_profile_combobox);

		try {
			selected_profile_combobox->SelectedIndex = stoi(read_text_file(game_index_to_path(selected_game_combobox->SelectedIndex) + "last_profile.txt"));
		}
		catch (...) {
		}



		fs::path save_path = game_index_to_path(selected_game_combobox->SelectedIndex) + combobox_selected_to_string(selected_profile_combobox);
		populate_listbox_sorted(save_path, saves_listbox, sort_by->SelectedIndex);





	}

		   void refresh_main() {
			   fs::path profile_path = game_index_to_path(current_selected_game);
			   populate_combobox(profile_path, selected_profile_combobox);

			   // Ensure current_selected_profile is valid
			   bool found = false;
			   for (int i = 0; i < selected_profile_combobox->Items->Count; ++i) {
				   if (selected_profile_combobox->Items[i]->ToString() == gcnew System::String(current_selected_profile.c_str())) {
					   selected_profile_combobox->SelectedIndex = i;
					   found = true;
					   break;
				   }
			   }
			   if (!found) {
				   if (selected_profile_combobox->Items->Count > 0) {
					   selected_profile_combobox->SelectedIndex = 0;
					   current_selected_profile = msclr::interop::marshal_as<std::string>(selected_profile_combobox->SelectedItem->ToString());
				   }
				   else {
					   selected_profile_combobox->SelectedIndex = -1;
					   current_selected_profile = "";
				   }
			   }

			   fs::path save_path = game_index_to_path(selected_game_combobox->SelectedIndex) + current_selected_profile;
			   populate_listbox_sorted(save_path, saves_listbox, sort_by->SelectedIndex);
		   }







	private: System::Void optionsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		Settings^ settings = gcnew Settings;
		set_window_position(this, settings);
		settings->ShowDialog();
	}


	private: System::Void profilesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		Profiles^ profiles = gcnew Profiles;
		set_window_position(this, profiles);
		profiles->ShowDialog();

		refresh_main();
		selected_profile_combobox->SelectedItem = convert_to_system_string(item_storage);


	}
	public: System::Void selected_game_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		write_text_file("Settings/last_game.txt", std::to_string(selected_game_combobox->SelectedIndex));

		current_selected_game = selected_game_combobox->SelectedIndex;


		fs::path profile_path = game_index_to_path(selected_game_combobox->SelectedIndex);
		populate_combobox(profile_path, selected_profile_combobox);

		if (selected_profile_combobox->Items->Count == 0) {
			saves_listbox->Items->Clear();
			search_box->Text = "";
			return;
		}

		try {
			selected_profile_combobox->SelectedIndex = stoi(read_text_file(game_index_to_path(current_selected_game) + "last_profile.txt"));
		}

		catch (...) {
		}

		fs::path save_path = game_index_to_path(selected_game_combobox->SelectedIndex) + combobox_selected_to_string(selected_profile_combobox);
		populate_listbox_sorted(save_path, saves_listbox, sort_by->SelectedIndex);

	}
	private: System::Void selected_profile_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		current_selected_profile = convert_to_std_string(selected_profile_combobox->SelectedItem->ToString());

		search_box->Text = "";

		if (selected_profile_combobox->Items->Count == 0) {
			saves_listbox->Items->Clear();
			return;
		}

		fs::path save_path = game_index_to_path(selected_game_combobox->SelectedIndex) + combobox_selected_to_string(selected_profile_combobox);
		populate_listbox_sorted(save_path, saves_listbox, sort_by->SelectedIndex);

		write_text_file((game_index_to_path(current_selected_game) + "last_profile.txt"), std::to_string(selected_profile_combobox->SelectedIndex));



	}
	private: System::Void search_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (selected_profile_combobox->Items->Count == 0) {
			saves_listbox->Items->Clear();
			search_box->Text = "";
			return;
		}

		fs::path save_path = game_index_to_path(current_selected_game) + current_selected_profile;

		String^ search_query = search_box->Text->ToLower();
		std::string search_query_str = convert_to_std_string(search_query);

		std::vector<std::string>  items = read_folders(save_path);
		std::vector<std::string> matching;

		for (const auto& str : items) {
			std::string lowercase_str = str;
			std::transform(lowercase_str.begin(), lowercase_str.end(), lowercase_str.begin(), ::tolower);
			if (lowercase_str.find(search_query_str) != std::string::npos) {
				matching.push_back(str);
			}
		}

		saves_listbox->Items->Clear();

		for (const auto& str : matching) {
			System::String^ itemString = gcnew System::String(str.c_str());
			saves_listbox->Items->Add(itemString);
		}




	}

	private: System::Void menuStrip1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void Save_Manager_Activated(System::Object^ sender, System::EventArgs^ e) {


	}



		   void right_click_menu_rename(System::Object^ sender, System::EventArgs^ e) {
			   entry_mode = "rename save";
			   to_rename = game_index_to_path(current_selected_game) + current_selected_profile;
			   save_name_storage = msclr::interop::marshal_as<std::string>(saves_listbox->SelectedItem->ToString());

			   Rename^ rename = gcnew Rename();
			   set_window_position(this, rename);
			   rename->ShowDialog();

			   search_box_TextChanged(nullptr, nullptr);

			   saves_listbox->SelectedItem = convert_to_system_string(item_storage);

		   }

		   void right_click_menu_delete(System::Object^ sender, System::EventArgs^ e) {
			   save_name_storage = msclr::interop::marshal_as<std::string>(saves_listbox->SelectedItem->ToString());

			   if (read_text_file("Settings/require_delete_confirmation.txt") == "true") {
				   Confirm_Delete^ confirm_delete = gcnew Confirm_Delete();
				   set_window_position(this, confirm_delete);
				   confirm_delete->ShowDialog();

				   if (delete_confirmation == false) {
					   return;
				   }
			   }

			   // Remove the save directory
			   std::filesystem::remove_all(game_index_to_path(current_selected_game) + current_selected_profile + "/" + current_selected_save);

			   // Reset confirmation flag
			   delete_confirmation = false;

			   // Refresh the listbox and clear selection
			   refresh_main();
			   saves_listbox->ClearSelected(); // Deselect any item
			   current_selected_save = "";     // Clear the variable


		   }



	private: System::Void saves_listbox_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			int item_index = saves_listbox->IndexFromPoint(e->Location);
			if (item_index != -1) {
				saves_listbox->SelectedIndex = item_index;


				System::Windows::Forms::ContextMenuStrip^ right_click_menu = gcnew System::Windows::Forms::ContextMenuStrip();
				right_click_menu->ShowImageMargin = false;
				right_click_menu->Items->Add("Rename", nullptr, gcnew System::EventHandler(this, &Save_Manager::right_click_menu_rename));
				right_click_menu->Items->Add("Delete", nullptr, gcnew System::EventHandler(this, &Save_Manager::right_click_menu_delete));
				right_click_menu->Show(saves_listbox, e->Location);



			}
		}
	}


	private: System::Void saves_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (saves_listbox->SelectedIndex != -1) {
			current_selected_save = convert_to_std_string((saves_listbox->SelectedItem->ToString()));
		}
	}




	private: System::Void Import_Button_Click(System::Object^ sender, System::EventArgs^ e) {

		int count = -1;
		std::string copy_path = game_index_to_path(current_selected_game) + current_selected_profile + "/New Save";
		std::string save_name = "New Save";

		while (fs::exists(copy_path)) {
			count++;
			copy_path = game_index_to_path(current_selected_game) + current_selected_profile + "/New Save" + "(" + std::to_string(count) + ")";
			save_name = "New Save" + std::string("(") + std::to_string(count) + std::string(")");

		}

		std::string save_path = read_text_file(game_index_to_path(current_selected_game) + "save_path.txt");
		std::string save_file_name = "\\" + get_file_name(save_path);


		try {
			std::filesystem::create_directory(copy_path);

			auto value = get_current_time_microseconds();

			// Write to created.txt
			std::ofstream created_file(copy_path + "/created.txt");
			created_file << value;
			created_file.close();
			fs::copy_file(save_path, copy_path + save_file_name);

		}

		catch (const std::filesystem::filesystem_error& ex) {
			fs::remove_all(copy_path);

			int error_image_X = (saves_listbox->Width - error_image->Width) / 2;
			int error_image_Y = saves_listbox->Top + (saves_listbox->Height - error_image->Height) / 2;

			error_image->Location = System::Drawing::Point(error_image_X, error_image_Y);
			error_image->Visible = true;

			timer->Start();
			return;
		}

		refresh_main();
		selected_profile_combobox->SelectedItem = convert_to_system_string(current_selected_profile);
		saves_listbox->SelectedItem = convert_to_system_string(save_name);

		int success_image_X = (saves_listbox->Width - success_image->Width) / 2;
		int success_image_Y = saves_listbox->Top + (saves_listbox->Height - success_image->Height) / 2;

		success_image->Location = System::Drawing::Point(success_image_X, success_image_Y);
		success_image->Visible = true;
		timer->Start();

	}



	private: System::Void Load_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saves_listbox->SelectedIndex == -1) {
			return;
		}

		std::string game_save_path = read_text_file(game_index_to_path(current_selected_game) + "save_path.txt");
		std::string game_save_name = get_file_name(game_save_path);
		std::string to_copy = game_index_to_path(current_selected_game) + current_selected_profile + "/" + current_selected_save + "/" + game_save_name;


		try {
			fs::copy_file(to_copy, game_save_path, fs::copy_options::overwrite_existing);
		}

		catch (const std::filesystem::filesystem_error& ex) {
			int error_image_X = (saves_listbox->Width - error_image->Width) / 2;
			int error_image_Y = saves_listbox->Top + (saves_listbox->Height - error_image->Height) / 2;

			error_image->Location = System::Drawing::Point(error_image_X, error_image_Y);
			error_image->Visible = true;

			timer->Start();

			return;
		}

		int success_image_X = (saves_listbox->Width - success_image->Width) / 2;
		int success_image_Y = saves_listbox->Top + (saves_listbox->Height - success_image->Height) / 2;

		success_image->Location = System::Drawing::Point(success_image_X, success_image_Y);
		success_image->Visible = true;
		timer->Start();

	}





	private: System::Void Replace_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saves_listbox->SelectedIndex == -1) {
			return;
		}


		std::string game_save_path = read_text_file(game_index_to_path(current_selected_game) + "save_path.txt");
		std::string game_save_name = get_file_name(game_save_path);
		std::string replace_path = game_index_to_path(current_selected_game) + current_selected_profile + "/" + current_selected_save + "/" + game_save_name;


		try {
			fs::copy_file(game_save_path, replace_path, fs::copy_options::overwrite_existing);
		}

		catch (const std::filesystem::filesystem_error& ex) {
			int error_image_X = (saves_listbox->Width - error_image->Width) / 2;
			int error_image_Y = saves_listbox->Top + (saves_listbox->Height - error_image->Height) / 2;

			error_image->Location = System::Drawing::Point(error_image_X, error_image_Y);
			error_image->Visible = true;

			timer->Start();
			return;
		}

		int success_image_X = (saves_listbox->Width - success_image->Width) / 2;
		int success_image_Y = saves_listbox->Top + (saves_listbox->Height - success_image->Height) / 2;

		success_image->Location = System::Drawing::Point(success_image_X, success_image_Y);
		success_image->Visible = true;
		timer->Start();


	}

	private: System::Void sort_by_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Refresh the listbox with the new sort order
		if (selected_profile_combobox->Items->Count == 0) {
			saves_listbox->Items->Clear();
			return;
		}
		fs::path save_path = game_index_to_path(current_selected_game) + current_selected_profile;
		populate_listbox_sorted(save_path, saves_listbox, sort_by->SelectedIndex);
	}


	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		success_image->Visible = false;
		error_image->Visible = false;
		timer->Stop();
	}










	};
}