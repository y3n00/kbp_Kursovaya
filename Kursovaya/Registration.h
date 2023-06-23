#pragma once
#include "Globals.h"
namespace Kursovaya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Registration
	/// </summary>
	public
	ref class Registration : public System::Windows::Forms::Form {
	public:
		Registration() {
			InitializeComponent();
			Globals::applyTheme(this);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Registration() {
			if (components) {
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ titleLabel;
		System::Windows::Forms::Label^ loginLabel;
		System::Windows::Forms::Label^ fullnameLabel;
		System::Windows::Forms::Label^ passwLabel;
		System::Windows::Forms::Label^ passwrepLabel;
		System::Windows::Forms::Button^ confirmButton;
		System::Windows::Forms::CheckBox^ showPasswcb;
		System::Windows::Forms::TextBox^ logintb;
		System::Windows::Forms::TextBox^ fullnametb;
		System::Windows::Forms::TextBox^ passwtb;
		System::Windows::Forms::TextBox^ passwreptb;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Registration::typeid));
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->fullnameLabel = (gcnew System::Windows::Forms::Label());
			this->passwLabel = (gcnew System::Windows::Forms::Label());
			this->passwrepLabel = (gcnew System::Windows::Forms::Label());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->showPasswcb = (gcnew System::Windows::Forms::CheckBox());
			this->logintb = (gcnew System::Windows::Forms::TextBox());
			this->fullnametb = (gcnew System::Windows::Forms::TextBox());
			this->passwtb = (gcnew System::Windows::Forms::TextBox());
			this->passwreptb = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			resources->ApplyResources(this->titleLabel, L"titleLabel");
			this->titleLabel->Name = L"titleLabel";
			// 
			// loginLabel
			// 
			resources->ApplyResources(this->loginLabel, L"loginLabel");
			this->loginLabel->Name = L"loginLabel";
			// 
			// fullnameLabel
			// 
			resources->ApplyResources(this->fullnameLabel, L"fullnameLabel");
			this->fullnameLabel->Name = L"fullnameLabel";
			// 
			// passwLabel
			// 
			resources->ApplyResources(this->passwLabel, L"passwLabel");
			this->passwLabel->Name = L"passwLabel";
			// 
			// passwrepLabel
			// 
			resources->ApplyResources(this->passwrepLabel, L"passwrepLabel");
			this->passwrepLabel->Name = L"passwrepLabel";
			// 
			// confirmButton
			// 
			resources->ApplyResources(this->confirmButton, L"confirmButton");
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew System::EventHandler(this, &Registration::confirmButton_Click);
			// 
			// showPasswcb
			// 
			resources->ApplyResources(this->showPasswcb, L"showPasswcb");
			this->showPasswcb->Name = L"showPasswcb";
			this->showPasswcb->UseVisualStyleBackColor = true;
			this->showPasswcb->CheckedChanged += gcnew System::EventHandler(this, &Registration::showPasswcb_CheckedChanged);
			// 
			// logintb
			// 
			resources->ApplyResources(this->logintb, L"logintb");
			this->logintb->Name = L"logintb";
			// 
			// fullnametb
			// 
			resources->ApplyResources(this->fullnametb, L"fullnametb");
			this->fullnametb->Name = L"fullnametb";
			// 
			// passwtb
			// 
			resources->ApplyResources(this->passwtb, L"passwtb");
			this->passwtb->Name = L"passwtb";
			this->passwtb->UseSystemPasswordChar = true;
			// 
			// passwreptb
			// 
			resources->ApplyResources(this->passwreptb, L"passwreptb");
			this->passwreptb->Name = L"passwreptb";
			this->passwreptb->UseSystemPasswordChar = true;
			// 
			// Registration
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->passwreptb);
			this->Controls->Add(this->passwtb);
			this->Controls->Add(this->fullnametb);
			this->Controls->Add(this->logintb);
			this->Controls->Add(this->showPasswcb);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->passwrepLabel);
			this->Controls->Add(this->passwLabel);
			this->Controls->Add(this->fullnameLabel);
			this->Controls->Add(this->loginLabel);
			this->Controls->Add(this->titleLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Registration";
			this->ShowIcon = false;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Registration::Registration_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void Registration_FormClosed(System::Object^, System::Windows::Forms::FormClosedEventArgs^) {
			Application::Exit();
		}

		System::Void showPasswcb_CheckedChanged(System::Object^, System::EventArgs^) {
			const auto value = !passwtb->UseSystemPasswordChar;
			passwtb->UseSystemPasswordChar = value;
			passwreptb->UseSystemPasswordChar = value;
		}

		System::Void confirmButton_Click(System::Object^, System::EventArgs^) {
			if (String::IsNullOrEmpty(logintb->Text) ||
				String::IsNullOrEmpty(fullnametb->Text) ||
				String::IsNullOrEmpty(passwtb->Text) ||
				String::IsNullOrEmpty(passwreptb->Text)) {
				MB_ERROR("FIELDS_EMPTY");
				return;
			}
			const auto login = string_cast(logintb->Text);
			const auto name = string_cast(fullnametb->Text);
			const auto passw = string_cast(passwtb->Text);
			const auto reppassw = string_cast(passwreptb->Text);
			if (!Globals::findAcc(login).empty()) {
				MB_ERROR("ACC_EXIST");
				logintb->Clear();
				passwtb->Clear();
				passwreptb->Clear();
				return;
			}
			if (passw != reppassw) {
				MB_ERROR("PASSWORD_MISMATCH");
				passwtb->Clear();
				passwreptb->Clear();
				return;
			}
			currentUsername = name;
			Globals::addAcc(login, name, passw);
			this->Hide();
		}
	};
}  // namespace Kursovaya
