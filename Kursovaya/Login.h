#pragma once
#include "Globals.h"
#include "Registration.h"
namespace Kursovaya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public
	ref class Login : public System::Windows::Forms::Form {
	public:
		Login() {
			InitializeComponent();
			Globals::changeTheme(Globals::currentTheme, this);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login() {
			if (components) {
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ title;
		System::Windows::Forms::Label^ LoginLabel;
		System::Windows::Forms::Label^ PasswLabel;
		System::Windows::Forms::TextBox^ logintb;
		System::Windows::Forms::TextBox^ passwtb;
		System::Windows::Forms::Button^ RegistrationButton;
		System::Windows::Forms::Button^ LoginButton;
		System::Windows::Forms::CheckBox^ showPassw;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->LoginLabel = (gcnew System::Windows::Forms::Label());
			this->PasswLabel = (gcnew System::Windows::Forms::Label());
			this->logintb = (gcnew System::Windows::Forms::TextBox());
			this->passwtb = (gcnew System::Windows::Forms::TextBox());
			this->RegistrationButton = (gcnew System::Windows::Forms::Button());
			this->LoginButton = (gcnew System::Windows::Forms::Button());
			this->showPassw = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// title
			// 
			resources->ApplyResources(this->title, L"title");
			this->title->Name = L"title";
			// 
			// LoginLabel
			// 
			resources->ApplyResources(this->LoginLabel, L"LoginLabel");
			this->LoginLabel->Name = L"LoginLabel";
			// 
			// PasswLabel
			// 
			resources->ApplyResources(this->PasswLabel, L"PasswLabel");
			this->PasswLabel->Name = L"PasswLabel";
			// 
			// logintb
			// 
			resources->ApplyResources(this->logintb, L"logintb");
			this->logintb->Name = L"logintb";
			// 
			// passwtb
			// 
			resources->ApplyResources(this->passwtb, L"passwtb");
			this->passwtb->Name = L"passwtb";
			this->passwtb->UseSystemPasswordChar = true;
			// 
			// RegistrationButton
			// 
			resources->ApplyResources(this->RegistrationButton, L"RegistrationButton");
			this->RegistrationButton->Name = L"RegistrationButton";
			this->RegistrationButton->UseVisualStyleBackColor = true;
			this->RegistrationButton->Click += gcnew System::EventHandler(this, &Login::RegistrationButton_Click);
			// 
			// LoginButton
			// 
			resources->ApplyResources(this->LoginButton, L"LoginButton");
			this->LoginButton->Name = L"LoginButton";
			this->LoginButton->UseVisualStyleBackColor = false;
			this->LoginButton->Click += gcnew System::EventHandler(this, &Login::LoginButton_Click);
			// 
			// showPassw
			// 
			resources->ApplyResources(this->showPassw, L"showPassw");
			this->showPassw->Name = L"showPassw";
			this->showPassw->UseVisualStyleBackColor = true;
			this->showPassw->CheckedChanged += gcnew System::EventHandler(this, &Login::showPassw_CheckedChanged);
			// 
			// Login
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->showPassw);
			this->Controls->Add(this->LoginButton);
			this->Controls->Add(this->RegistrationButton);
			this->Controls->Add(this->passwtb);
			this->Controls->Add(this->logintb);
			this->Controls->Add(this->PasswLabel);
			this->Controls->Add(this->LoginLabel);
			this->Controls->Add(this->title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Login";
			this->ShowIcon = false;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Login::Login_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void Login_FormClosed(System::Object^, System::Windows::Forms::FormClosedEventArgs^) {
			Application::Exit();
		}

		System::Void showPassw_CheckedChanged(System::Object^, System::EventArgs^) {
			const auto prevValue = passwtb->UseSystemPasswordChar;
			passwtb->UseSystemPasswordChar = !prevValue;
		}

		System::Void RegistrationButton_Click(System::Object^, System::EventArgs^) {
			this->Hide();
			Registration^ rg = gcnew Registration();
			rg->ShowDialog();
		}

		System::Void LoginButton_Click(System::Object^, System::EventArgs^) {
			if (String::IsNullOrEmpty(this->logintb->Text) || String::IsNullOrEmpty(this->passwtb->Text)) {
				MB_ERROR("FIELDS_EMPTY");
				return;
			}
			const auto login = string_cast(this->logintb->Text);
			const auto passw = string_cast(this->passwtb->Text);
			const auto& acc = Globals::findAcc(login);
			if (acc.empty() || CaesarDecrypt(acc.at("Password"), login.length()) != passw) {
				this->passwtb->Clear();
				MB_ERROR("NO_ACC");
				return;
			}
			acc["Name"].get_to(currentUsername);
			this->Hide();
		}
	};
}  // namespace Kursovaya
