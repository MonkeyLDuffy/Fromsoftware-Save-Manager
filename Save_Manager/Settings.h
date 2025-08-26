#pragma once
#include "Header.h"

namespace SaveManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
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
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ delete_confirm_checkbox;
	private: System::Windows::Forms::HelpProvider^ helpProvider1;
























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
			this->delete_confirm_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->SuspendLayout();
			// 
			// delete_confirm_checkbox
			// 
			this->delete_confirm_checkbox->AutoSize = true;
			this->delete_confirm_checkbox->Checked = true;
			this->delete_confirm_checkbox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->delete_confirm_checkbox->Location = System::Drawing::Point(13, 13);
			this->delete_confirm_checkbox->Name = L"delete_confirm_checkbox";
			this->delete_confirm_checkbox->Size = System::Drawing::Size(154, 17);
			this->delete_confirm_checkbox->TabIndex = 0;
			this->delete_confirm_checkbox->Text = L"Enable Delete Confirmation";
			this->delete_confirm_checkbox->UseVisualStyleBackColor = true;
			this->delete_confirm_checkbox->CheckedChanged += gcnew System::EventHandler(this, &Settings::delete_confirm_checkbox_CheckedChanged);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(316, 41);
			this->Controls->Add(this->delete_confirm_checkbox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Settings";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		void store_user_hotkey_input(System::Windows::Forms::KeyEventArgs^ e) {

}



	

	private: System::Void delete_confirm_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (delete_confirm_checkbox->Checked) {
			write_text_file("Settings/require_delete_confirmation.txt", "true");
		}
		else {
			write_text_file("Settings/require_delete_confirmation.txt", "false");
		}
	}
	private: System::Void Settings_Load(System::Object^ sender, System::EventArgs^ e) {
		if (read_text_file("Settings/require_delete_confirmation.txt") == "true") {
			delete_confirm_checkbox->Checked = true;
		}
		else {
			delete_confirm_checkbox->Checked = false;

		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
