#pragma once
#include "Confirm_Delete.h"

namespace SaveManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Rename
	/// </summary>
	public ref class Rename : public System::Windows::Forms::Form
	{
	public:
		Rename(void)
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
		~Rename()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ rename_entry;
	private: System::Windows::Forms::Label^ name_label;
	protected:

	private: System::Windows::Forms::Button^ ok_button;
	private: System::Windows::Forms::Button^ cancel_button;

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
			this->rename_entry = (gcnew System::Windows::Forms::TextBox());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->ok_button = (gcnew System::Windows::Forms::Button());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rename_entry
			// 
			this->rename_entry->Location = System::Drawing::Point(12, 25);
			this->rename_entry->Name = L"rename_entry";
			this->rename_entry->Size = System::Drawing::Size(260, 20);
			this->rename_entry->TabIndex = 0;
			this->rename_entry->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Rename::rename_entry_KeyDown);
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->Location = System::Drawing::Point(12, 9);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(66, 13);
			this->name_label->TabIndex = 1;
			this->name_label->Text = L"Enter Name:";
			// 
			// ok_button
			// 
			this->ok_button->Location = System::Drawing::Point(12, 51);
			this->ok_button->Name = L"ok_button";
			this->ok_button->Size = System::Drawing::Size(125, 23);
			this->ok_button->TabIndex = 2;
			this->ok_button->Text = L"OK";
			this->ok_button->UseVisualStyleBackColor = true;
			this->ok_button->Click += gcnew System::EventHandler(this, &Rename::ok_button_Click);
			// 
			// cancel_button
			// 
			this->cancel_button->Location = System::Drawing::Point(147, 51);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(125, 23);
			this->cancel_button->TabIndex = 3;
			this->cancel_button->Text = L"Cancel";
			this->cancel_button->UseVisualStyleBackColor = true;
			this->cancel_button->Click += gcnew System::EventHandler(this, &Rename::cancel_button_Click);
			// 
			// Rename
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 85);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->ok_button);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->rename_entry);
			this->Name = L"Rename";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Rename";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Rename::Rename_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void ok_button_Click(System::Object^ sender, System::EventArgs^ e) {

		System::String^ entered_name_sys = rename_entry->Text;
		std::string entered_name = msclr::interop::marshal_as<std::string>(entered_name_sys);

		int count = -1;
		std::string rename_path = to_rename + "/" + entered_name;

		if (entry_mode == "rename profile") {
			rename_path = game_index_to_path(profiles_current_selected_game) + entered_name;
		}

		item_storage = entered_name;

		while (fs::exists(rename_path)) {
			count++;
			rename_path = to_rename + "/" + entered_name + "(" + std::to_string(count) + ")";
			if (entry_mode == "rename profile") {
				rename_path = game_index_to_path(profiles_current_selected_game) + entered_name + "(" + std::to_string(count) + ")";
			}


			item_storage = entered_name + "(" + std::to_string(count) + ")";
		}
		

		if (entry_mode == "rename save") {

			try {				
				fs::rename(to_rename + "/" + save_name_storage, to_rename + "/" + item_storage);
			}

			catch (const std::exception& e) {
				this->Close();
			}
		}




		else if (entry_mode == "new profile") {
			try {
				fs::create_directory(rename_path);
			}

			catch (const std::exception& e) {
				this->Close();
			}
		}

		else if (entry_mode == "rename profile") {
			try {
				fs::rename(game_index_to_path(profiles_current_selected_game) + to_rename, game_index_to_path(profiles_current_selected_game) + item_storage);
				current_selected_profile = item_storage;
			}

			catch (const std::exception& e) {
				this->Close();
			}

		}

		this->Close();


	}
	private: System::Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}









private: System::Void Rename_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	//Save_Manager^ save_manager = gcnew Save_Manager();
	//save_manager->new_profile_refresh();
}


private: System::Void rename_entry_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		ok_button->PerformClick();
	}
}
};
}