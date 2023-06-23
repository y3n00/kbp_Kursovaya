#pragma once
#include <string>

#include "Globals.h"
#include "Login.h"
#include "Registration.h"

namespace Kursovaya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public
	ref class MainForm : public System::Windows::Forms::Form {
	public:
		MainForm(void) {
			Form^ f;
			this->Hide();
			if (Globals::accsJson.empty())
				f = gcnew Registration();
			else
				f = gcnew Login();
			f->ShowDialog();
			InitializeComponent();

			this->Text = gcnew String(("HairShop | User: " + currentUsername).c_str());
			this->Show();

			this->dateTimePicker1->MinDate = DateTime::Now;
			this->dateTimePicker1->MaxDate = DateTime::Now.AddDays(30);
			Globals::changeTheme(Globals::currentTheme, this);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm() {
			if (components) {
				delete components;
			}
		}

		System::Windows::Forms::MenuStrip^ Menu;
		System::Windows::Forms::ToolStripMenuItem^ dataToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ loadToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ themeToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ darkToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ lightToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ languageToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ englishToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ russianToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ belarusianToolStripMenuItem;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::TextBox^ customerNametb;
		System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		System::Windows::Forms::CheckedListBox^ checkedListBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::DataGridViewTextBoxColumn^ DateColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ CustomerNameColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ ServicesColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ TotalPriceColumn;
	private: System::Windows::Forms::ToolStripMenuItem^ colorfulToolStripMenuItem;
	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->Menu = (gcnew System::Windows::Forms::MenuStrip());
			this->dataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->themeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->darkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorfulToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->russianToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->belarusianToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->DateColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CustomerNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ServicesColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TotalPriceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->customerNametb = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Menu
			// 
			resources->ApplyResources(this->Menu, L"Menu");
			this->Menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dataToolStripMenuItem,
					this->settingsToolStripMenuItem
			});
			this->Menu->Name = L"Menu";
			this->Menu->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			// 
			// dataToolStripMenuItem
			// 
			this->dataToolStripMenuItem->AutoToolTip = true;
			this->dataToolStripMenuItem->CheckOnClick = true;
			this->dataToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->loadToolStripMenuItem
			});
			this->dataToolStripMenuItem->Name = L"dataToolStripMenuItem";
			resources->ApplyResources(this->dataToolStripMenuItem, L"dataToolStripMenuItem");
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			resources->ApplyResources(this->saveToolStripMenuItem, L"saveToolStripMenuItem");
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			resources->ApplyResources(this->loadToolStripMenuItem, L"loadToolStripMenuItem");
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::loadToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->CheckOnClick = true;
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->themeToolStripMenuItem,
					this->languageToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			resources->ApplyResources(this->settingsToolStripMenuItem, L"settingsToolStripMenuItem");
			// 
			// themeToolStripMenuItem
			// 
			this->themeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->darkToolStripMenuItem,
					this->lightToolStripMenuItem, this->colorfulToolStripMenuItem
			});
			this->themeToolStripMenuItem->Name = L"themeToolStripMenuItem";
			resources->ApplyResources(this->themeToolStripMenuItem, L"themeToolStripMenuItem");
			// 
			// darkToolStripMenuItem
			// 
			this->darkToolStripMenuItem->Name = L"darkToolStripMenuItem";
			resources->ApplyResources(this->darkToolStripMenuItem, L"darkToolStripMenuItem");
			this->darkToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::darkToolStripMenuItem_Click);
			// 
			// lightToolStripMenuItem
			// 
			this->lightToolStripMenuItem->Name = L"lightToolStripMenuItem";
			resources->ApplyResources(this->lightToolStripMenuItem, L"lightToolStripMenuItem");
			this->lightToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::lightToolStripMenuItem_Click);
			// 
			// colorfulToolStripMenuItem
			// 
			this->colorfulToolStripMenuItem->Name = L"colorfulToolStripMenuItem";
			resources->ApplyResources(this->colorfulToolStripMenuItem, L"colorfulToolStripMenuItem");
			this->colorfulToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::colorfulToolStripMenuItem_Click);
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->englishToolStripMenuItem,
					this->russianToolStripMenuItem, this->belarusianToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			resources->ApplyResources(this->languageToolStripMenuItem, L"languageToolStripMenuItem");
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			resources->ApplyResources(this->englishToolStripMenuItem, L"englishToolStripMenuItem");
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::englishToolStripMenuItem_Click);
			// 
			// russianToolStripMenuItem
			// 
			this->russianToolStripMenuItem->Name = L"russianToolStripMenuItem";
			resources->ApplyResources(this->russianToolStripMenuItem, L"russianToolStripMenuItem");
			this->russianToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::russianToolStripMenuItem_Click);
			// 
			// belarusianToolStripMenuItem
			// 
			this->belarusianToolStripMenuItem->Name = L"belarusianToolStripMenuItem";
			resources->ApplyResources(this->belarusianToolStripMenuItem, L"belarusianToolStripMenuItem");
			this->belarusianToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::belarusianToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->DateColumn,
					this->CustomerNameColumn, this->ServicesColumn, this->TotalPriceColumn
			});
			resources->ApplyResources(this->dataGridView1, L"dataGridView1");
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			// 
			// DateColumn
			// 
			resources->ApplyResources(this->DateColumn, L"DateColumn");
			this->DateColumn->Name = L"DateColumn";
			// 
			// CustomerNameColumn
			// 
			resources->ApplyResources(this->CustomerNameColumn, L"CustomerNameColumn");
			this->CustomerNameColumn->Name = L"CustomerNameColumn";
			// 
			// ServicesColumn
			// 
			resources->ApplyResources(this->ServicesColumn, L"ServicesColumn");
			this->ServicesColumn->Name = L"ServicesColumn";
			// 
			// TotalPriceColumn
			// 
			resources->ApplyResources(this->TotalPriceColumn, L"TotalPriceColumn");
			this->TotalPriceColumn->Name = L"TotalPriceColumn";
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// customerNametb
			// 
			resources->ApplyResources(this->customerNametb, L"customerNametb");
			this->customerNametb->Name = L"customerNametb";
			this->customerNametb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::customerNametb_KeyPress);
			// 
			// dateTimePicker1
			// 
			resources->ApplyResources(this->dateTimePicker1, L"dateTimePicker1");
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Name = L"dateTimePicker1";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = System::Drawing::SystemColors::Control;
			this->checkedListBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->checkedListBox1, L"checkedListBox1");
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				resources->GetString(L"checkedListBox1.Items"),
					resources->GetString(L"checkedListBox1.Items1"), resources->GetString(L"checkedListBox1.Items2"), resources->GetString(L"checkedListBox1.Items3"),
					resources->GetString(L"checkedListBox1.Items4")
			});
			this->checkedListBox1->Name = L"checkedListBox1";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// MainForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->customerNametb);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->Menu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->Menu;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Menu->ResumeLayout(false);
			this->Menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void MainForm_FormClosed(System::Object^, System::Windows::Forms::FormClosedEventArgs^) {
			Globals::save();
			Application::Exit();
		}

		inline void sort() {
			dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		}

		inline void resetValues() {
			dateTimePicker1->Value = DateTime::Now;
			customerNametb->Clear();
			for (int i = 0; i < checkedListBox1->Items->Count; ++i)
				checkedListBox1->SetItemChecked(i, false);
		}

		System::Void saveToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			Globals::save();
			{
				const auto DG = this->dataGridView1;
				const auto cols = DG->ColumnCount, rows = DG->RowCount;
				auto& data = Globals::mainDataJson["Data"];
				for (int i = 0; i < rows; ++i) {
					auto& entry = data[i];
					entry["Date"] = string_cast(DG->Rows[i]->Cells[0]->Value->ToString());
					entry["Name"] = string_cast(DG->Rows[i]->Cells[1]->Value->ToString());
					entry["Services"] = string_cast(DG->Rows[i]->Cells[2]->Value->ToString());
					entry["Price"] = Convert::ToInt16(DG->Rows[i]->Cells[3]->Value->ToString());
				}

				FolderBrowserDialog^ FBD = gcnew FolderBrowserDialog;
				if (FBD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					Globals::saveData(string_cast(FBD->SelectedPath));
			}
		}

		System::Void loadToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			{
				OpenFileDialog^ OFD = gcnew OpenFileDialog;
				OFD->Filter = "json files(*.json)|*.json";
				if (OFD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					Globals::loadData(string_cast(OFD->FileName));

				const auto& data = Globals::mainDataJson.at("Data");
				for (auto& entry : data) {
					const auto date = DateTime::Parse(string_cast(entry["Date"].get<std::string>()));
					const auto name = string_cast(entry["Name"].get<std::string>());
					const auto services = string_cast(entry["Services"].get<std::string>());
					const auto price = entry["Price"].get<short>();

					DateTimePicker^ DTP = gcnew DateTimePicker();
					DTP->Value = date;
					dataGridView1->Rows->Add(DTP->Value.ToString(dateTimePicker1->CustomFormat), name, services, price);
				}
			}
			sort();
		}

		System::Void customerNametb_KeyPress(System::Object^, System::Windows::Forms::KeyPressEventArgs^ e) {
			e->Handled = !(Char::IsLetter(e->KeyChar) || e->KeyChar == (char)Keys::Back);
		}

		System::Void button1_Click(System::Object^, System::EventArgs^) {
			if (dateTimePicker1->Value == DateTime::Now) {
				MB_WARNING("WRONG_DATE");
				return;
			}
			if (String::IsNullOrEmpty(customerNametb->Text)) {
				MB_WARNING("FIELDS_EMPTY");
				return;
			}
			const auto checkedCount = checkedListBox1->CheckedItems->Count;
			if (checkedCount == 0) {
				MB_WARNING("NOT_CHECKED");
				return;
			}

			String^ selectedItems = "";
			for each (System::Object ^ item in checkedListBox1->CheckedItems)
				selectedItems += item->ToString() + ", ";
			selectedItems = selectedItems->Remove(selectedItems->Length - 2);

			const int priceForOneService = 15;
			const int totalPrice = priceForOneService * checkedCount;
			const auto DT = dateTimePicker1;
			dataGridView1->Rows->Add(DT->Value.ToString(DT->CustomFormat), customerNametb->Text, selectedItems, totalPrice);

			resetValues();
			sort();
		}

		inline void updateUI() {
			this->Controls->Clear();
			InitializeComponent();
		}

		inline void redrawUI() {
			
		}

		System::Void englishToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			Globals::changeLang(Languages::ENG);
			updateUI();
		}

		System::Void russianToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			Globals::changeLang(Languages::RU);
			updateUI();
		}

		System::Void belarusianToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			Globals::changeLang(Languages::BEL);
			updateUI();
		}

		System::Void darkToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			Globals::changeTheme(Themes::Dark, this);
		}

		System::Void lightToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			Globals::changeTheme(Themes::Light, this);
		}

		System::Void colorfulToolStripMenuItem_Click(System::Object^, System::EventArgs^) {
			Globals::changeTheme(Themes::Colorful, this);
		}
	};
}  // namespace Kursovaya
