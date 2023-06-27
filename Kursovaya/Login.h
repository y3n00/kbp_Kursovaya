#pragma once
#include "Globals.h"
#include "Registration.h"

namespace Kursovaya
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Login: public Form {
	public:
		Login() {
			InitializeComponent();
			Globals::applyTheme(this);
		}

	protected:
		~Login() {
			if(components) {
				delete components;
			}
		}

	private:
		Label^ title;
		Label^ LoginLabel;
		Label^ PasswLabel;
		TextBox^ logintb;
		TextBox^ passwtb;
		Button^ RegistrationButton;
		Button^ LoginButton;
		CheckBox^ showPassw;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources =
				(gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->title = (gcnew Label());
			this->LoginLabel = (gcnew Label());
			this->PasswLabel = (gcnew Label());
			this->logintb = (gcnew TextBox());
			this->passwtb = (gcnew TextBox());
			this->RegistrationButton = (gcnew Button());
			this->LoginButton = (gcnew Button());
			this->showPassw = (gcnew CheckBox());
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
			this->RegistrationButton->Click +=
				gcnew EventHandler(this, &Login::RegistrationButton_Click);
			//
			// LoginButton
			//
			resources->ApplyResources(this->LoginButton, L"LoginButton");
			this->LoginButton->Name = L"LoginButton";
			this->LoginButton->UseVisualStyleBackColor = false;
			this->LoginButton->Click +=
				gcnew EventHandler(this, &Login::LoginButton_Click);
			//
			// showPassw
			//
			resources->ApplyResources(this->showPassw, L"showPassw");
			this->showPassw->Name = L"showPassw";
			this->showPassw->UseVisualStyleBackColor = true;
			this->showPassw->CheckedChanged +=
				gcnew EventHandler(this, &Login::showPassw_CheckedChanged);
			//
			// Login
			//
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->showPassw);
			this->Controls->Add(this->LoginButton);
			this->Controls->Add(this->RegistrationButton);
			this->Controls->Add(this->passwtb);
			this->Controls->Add(this->logintb);
			this->Controls->Add(this->PasswLabel);
			this->Controls->Add(this->LoginLabel);
			this->Controls->Add(this->title);
			this->FormBorderStyle =
				Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Login";
			this->ShowIcon = false;
			this->FormClosed += gcnew FormClosedEventHandler(
				this, &Login::Login_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		Void Login_FormClosed(Object^, FormClosedEventArgs^) {
			Application::Exit();
		}

		Void showPassw_CheckedChanged(Object^, EventArgs^) {
			const auto newValue = !passwtb->UseSystemPasswordChar;
			passwtb->UseSystemPasswordChar = newValue;
		}

		Void RegistrationButton_Click(Object^, EventArgs^) {
			this->Hide();
			Registration^ rg = gcnew Registration();
			rg->ShowDialog();
		}

		Void LoginButton_Click(Object^, EventArgs^) {
			if(String::IsNullOrEmpty(this->logintb->Text) ||
			   String::IsNullOrEmpty(this->passwtb->Text)) {
				MB_ERROR("FIELDS_EMPTY");
				return;
			}

			const auto
				login = string_cast(this->logintb->Text),
				passw = string_cast(this->passwtb->Text);

			const auto acc = Globals::findAcc(login);
			if(acc.empty() ||
			   CaesarDecrypt(acc.at("Password"), (int)login.length()) != passw) {
				this->passwtb->Clear();
				MB_ERROR("NO_ACC");
				return;
			}
			acc["Name"].get_to(currentUsername);
			this->Hide();
		}
	};
}  // namespace Kursovaya
