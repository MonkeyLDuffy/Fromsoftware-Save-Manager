#pragma once

namespace SaveManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Confirm_Delete
	/// </summary>
	public ref class Confirm_Delete : public System::Windows::Forms::Form
	{
	public:
		Confirm_Delete(void)
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
		~Confirm_Delete()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ confirm_delete_label;
	protected:
	private: System::Windows::Forms::Button^ confirm_button;
	private: System::Windows::Forms::Button^ cancel_button;

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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->confirm_delete_label = (gcnew System::Windows::Forms::Label());
			this->confirm_button = (gcnew System::Windows::Forms::Button());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// confirm_delete_label
			// 
			this->confirm_delete_label->AutoSize = true;
			this->confirm_delete_label->Location = System::Drawing::Point(12, 9);
			this->confirm_delete_label->Name = L"confirm_delete_label";
			this->confirm_delete_label->Size = System::Drawing::Size(141, 13);
			this->confirm_delete_label->TabIndex = 0;
			this->confirm_delete_label->Text = L"Do you really want to delete ";
			this->confirm_delete_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// confirm_button
			// 
			this->confirm_button->Location = System::Drawing::Point(12, 41);
			this->confirm_button->Name = L"confirm_button";
			this->confirm_button->Size = System::Drawing::Size(125, 23);
			this->confirm_button->TabIndex = 1;
			this->confirm_button->Text = L"Confirm";
			this->confirm_button->UseVisualStyleBackColor = true;
			this->confirm_button->Click += gcnew System::EventHandler(this, &Confirm_Delete::confirm_button_Click);
			// 
			// cancel_button
			// 
			this->cancel_button->Location = System::Drawing::Point(143, 41);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(129, 23);
			this->cancel_button->TabIndex = 2;
			this->cancel_button->Text = L"Cancel";
			this->cancel_button->UseVisualStyleBackColor = true;
			this->cancel_button->Click += gcnew System::EventHandler(this, &Confirm_Delete::cancel_button_Click);
			// 
			// Confirm_Delete
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 76);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->confirm_button);
			this->Controls->Add(this->confirm_delete_label);
			this->Name = L"Confirm_Delete";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Confirm_Delete";
			this->Load += gcnew System::EventHandler(this, &Confirm_Delete::Confirm_Delete_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Confirm_Delete_Load(System::Object^ sender, System::EventArgs^ e) {
		confirm_delete_label->Text += convert_to_system_string("'" + save_name_storage + "'" + "?");
;
	}

	private: System::Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void confirm_button_Click(System::Object^ sender, System::EventArgs^ e) {
		delete_confirmation = true;
		this->Close();
	}
};
}
