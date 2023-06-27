#pragma once
#include "Globals.h"
namespace Kursovaya
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace Collections;
	using namespace Windows;
	using namespace Forms;
	using namespace Data;
	using namespace Drawing;


	public ref class Registration: public Form {
	public:
		Registration() {
			InitializeComponent();
			Globals::applyTheme(this);
		}

	protected:
		~Registration() {
			if(components) {
				delete components;
			}
		}

	private:
		Label^ titleLabel;
		Label^ loginLabel;
		Label^ fullnameLabel;
		Label^ passwLabel;
		Label^ passwrepLabel;
		Button^ confirmButton;
		CheckBox^ showPasswcb;
		TextBox^ logintb;
		TextBox^ fullnametb;
		TextBox^ passwtb;
		TextBox^ passwreptb;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Registration::typeid));
			this->titleLabel = (gcnew Label());
			this->loginLabel = (gcnew Label());
			this->fullnameLabel = (gcnew Label());
			this->passwLabel = (gcnew Label());
			this->passwrepLabel = (gcnew Label());
			this->confirmButton = (gcnew Button());
			this->showPasswcb = (gcnew CheckBox());
			this->logintb = (gcnew TextBox());
			this->fullnametb = (gcnew TextBox());
			this->passwtb = (gcnew TextBox());
			this->passwreptb = (gcnew TextBox());
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
			this->confirmButton->Click += gcnew EventHandler(this, &Registration::confirmButton_Click);
			// 
			// showPasswcb
			// 
			resources->ApplyResources(this->showPasswcb, L"showPasswcb");
			this->showPasswcb->Name = L"showPasswcb";
			this->showPasswcb->UseVisualStyleBackColor = true;
			this->showPasswcb->CheckedChanged += gcnew EventHandler(this, &Registration::showPasswcb_CheckedChanged);
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
			this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
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
			this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Registration";
			this->ShowIcon = false;
			this->FormClosed += gcnew FormClosedEventHandler(this, &Registration::Registration_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Void Registration_FormClosed(Object^, FormClosedEventArgs^) {
			Application::Exit();
		}

		Void showPasswcb_CheckedChanged(Object^, EventArgs^) {
			const auto newValue = !passwtb->UseSystemPasswordChar;
			passwtb->UseSystemPasswordChar = newValue;
			passwreptb->UseSystemPasswordChar = newValue;
		}

		Void confirmButton_Click(Object^, EventArgs^) {
			if(String::IsNullOrEmpty(logintb->Text) ||
			   String::IsNullOrEmpty(fullnametb->Text) ||
			   String::IsNullOrEmpty(passwtb->Text) ||
			   String::IsNullOrEmpty(passwreptb->Text)) {
				MB_ERROR("FIELDS_EMPTY");
				return;
			}

			const auto
				login = string_cast(logintb->Text),
				name = string_cast(fullnametb->Text),
				passw = string_cast(passwtb->Text),
				reppassw = string_cast(passwreptb->Text);

			if(!Globals::findAcc(login).empty()) {
				MB_ERROR("ACC_EXIST");
				logintb->Clear();
				passwtb->Clear();
				passwreptb->Clear();
				return;
			}
			if(passw != reppassw) {
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
