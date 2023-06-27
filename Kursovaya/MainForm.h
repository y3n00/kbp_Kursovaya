#pragma once
#include <string>

#include "Globals.h"
#include "Login.h"
#include "Registration.h"

namespace Kursovaya
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace Collections;
	using namespace Windows::Forms;
	using namespace Data;
	using namespace Drawing;
	public ref class MainForm: public Form {
		String^ customDateFormat;
	public:
		MainForm(void) {
			Form^ f;
			this->Hide();
			if(Globals::accsJson.empty())
				f = gcnew Registration();
			else
				f = gcnew Login();
			f->ShowDialog();
			InitializeComponent();

			this->Text = gcnew String(("HairShop | User: " + currentUsername).c_str());
			Globals::applyTheme(this);
			this->Show();

			this->dateTimePicker1->MinDate = DateTime::Now;
			this->dateTimePicker1->MaxDate = DateTime::Now.AddDays(30);
			customDateFormat = this->dateTimePicker1->CustomFormat;
		}

	protected:
		~MainForm() {
			if(components) {
				delete components;
			}
		}

		MenuStrip^ Menu;
		ToolStripMenuItem^ dataToolStripMenuItem;
		ToolStripMenuItem^ saveToolStripMenuItem;
		ToolStripMenuItem^ loadToolStripMenuItem;
		ToolStripMenuItem^ settingsToolStripMenuItem;
		ToolStripMenuItem^ themeToolStripMenuItem;
		ToolStripMenuItem^ darkToolStripMenuItem;
		ToolStripMenuItem^ lightToolStripMenuItem;
		ToolStripMenuItem^ languageToolStripMenuItem;
		ToolStripMenuItem^ englishToolStripMenuItem;
		ToolStripMenuItem^ russianToolStripMenuItem;
		ToolStripMenuItem^ belarusianToolStripMenuItem;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		DataGridView^ dataGridView1;
		Button^ button1;
		TextBox^ customerNametb;
		DateTimePicker^ dateTimePicker1;
		CheckedListBox^ checkedListBox1;
		Label^ label1;
		Label^ label2;
		Label^ label3;
		DataGridViewTextBoxColumn^ DateColumn;
		DataGridViewTextBoxColumn^ CustomerNameColumn;
		DataGridViewTextBoxColumn^ ServicesColumn;
		DataGridViewTextBoxColumn^ TotalPriceColumn;
		System::ComponentModel::Container^ components;
		ToolStripMenuItem^ colorfulToolStripMenuItem;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->Menu = (gcnew MenuStrip());
			this->dataToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->themeToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->darkToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->lightToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->colorfulToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->russianToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->belarusianToolStripMenuItem = (gcnew ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->dataGridView1 = (gcnew DataGridView());
			this->DateColumn = (gcnew DataGridViewTextBoxColumn());
			this->CustomerNameColumn = (gcnew DataGridViewTextBoxColumn());
			this->ServicesColumn = (gcnew DataGridViewTextBoxColumn());
			this->TotalPriceColumn = (gcnew DataGridViewTextBoxColumn());
			this->button1 = (gcnew Button());
			this->customerNametb = (gcnew TextBox());
			this->dateTimePicker1 = (gcnew DateTimePicker());
			this->checkedListBox1 = (gcnew CheckedListBox());
			this->label1 = (gcnew Label());
			this->label2 = (gcnew Label());
			this->label3 = (gcnew Label());
			this->Menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Menu
			// 
			resources->ApplyResources(this->Menu, L"Menu");
			this->Menu->Items->AddRange(gcnew cli::array< ToolStripItem^  >(2) {
				this->dataToolStripMenuItem,
					this->settingsToolStripMenuItem
			});
			this->Menu->Name = L"Menu";
			this->Menu->RenderMode = ToolStripRenderMode::System;
			// 
			// dataToolStripMenuItem
			// 
			this->dataToolStripMenuItem->AutoToolTip = true;
			this->dataToolStripMenuItem->CheckOnClick = true;
			this->dataToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< ToolStripItem^  >(2) {
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
			this->saveToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			resources->ApplyResources(this->loadToolStripMenuItem, L"loadToolStripMenuItem");
			this->loadToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::loadToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->CheckOnClick = true;
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< ToolStripItem^  >(2) {
				this->themeToolStripMenuItem,
					this->languageToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			resources->ApplyResources(this->settingsToolStripMenuItem, L"settingsToolStripMenuItem");
			// 
			// themeToolStripMenuItem
			// 
			this->themeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< ToolStripItem^  >(3) {
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
			this->darkToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::darkToolStripMenuItem_Click);
			// 
			// lightToolStripMenuItem
			// 
			this->lightToolStripMenuItem->Name = L"lightToolStripMenuItem";
			resources->ApplyResources(this->lightToolStripMenuItem, L"lightToolStripMenuItem");
			this->lightToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::lightToolStripMenuItem_Click);
			// 
			// colorfulToolStripMenuItem
			// 
			this->colorfulToolStripMenuItem->Name = L"colorfulToolStripMenuItem";
			resources->ApplyResources(this->colorfulToolStripMenuItem, L"colorfulToolStripMenuItem");
			this->colorfulToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::colorfulToolStripMenuItem_Click);
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< ToolStripItem^  >(3) {
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
			this->englishToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::englishToolStripMenuItem_Click);
			// 
			// russianToolStripMenuItem
			// 
			this->russianToolStripMenuItem->Name = L"russianToolStripMenuItem";
			resources->ApplyResources(this->russianToolStripMenuItem, L"russianToolStripMenuItem");
			this->russianToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::russianToolStripMenuItem_Click);
			// 
			// belarusianToolStripMenuItem
			// 
			this->belarusianToolStripMenuItem->Name = L"belarusianToolStripMenuItem";
			resources->ApplyResources(this->belarusianToolStripMenuItem, L"belarusianToolStripMenuItem");
			this->belarusianToolStripMenuItem->Click += gcnew EventHandler(this, &MainForm::belarusianToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BorderStyle = BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< DataGridViewColumn^  >(4) {
				this->DateColumn,
					this->CustomerNameColumn, this->ServicesColumn, this->TotalPriceColumn
			});
			resources->ApplyResources(this->dataGridView1, L"dataGridView1");
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidthSizeMode = DataGridViewRowHeadersWidthSizeMode::DisableResizing;
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
			this->button1->Click += gcnew EventHandler(this, &MainForm::button1_Click);
			// 
			// customerNametb
			// 
			resources->ApplyResources(this->customerNametb, L"customerNametb");
			this->customerNametb->Name = L"customerNametb";
			this->customerNametb->KeyPress += gcnew KeyPressEventHandler(this, &MainForm::customerNametb_KeyPress);
			// 
			// dateTimePicker1
			// 
			resources->ApplyResources(this->dateTimePicker1, L"dateTimePicker1");
			this->dateTimePicker1->Format = DateTimePickerFormat::Custom;
			this->dateTimePicker1->Name = L"dateTimePicker1";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = Drawing::SystemColors::Control;
			this->checkedListBox1->BorderStyle = BorderStyle::None;
			resources->ApplyResources(this->checkedListBox1, L"checkedListBox1");
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< Object^  >(5) {
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
			this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->customerNametb);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->Menu);
			this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->Menu;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->FormClosed += gcnew FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Menu->ResumeLayout(false);
			this->Menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Void MainForm_FormClosed(Object^, FormClosedEventArgs^) {
			Globals::save();
			Application::Exit();
		}

		inline void sort() {
			dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		}

		inline void resetValues() {
			dateTimePicker1->Value = DateTime::Now;
			customerNametb->Clear();
			for(int i = 0; i < checkedListBox1->Items->Count; ++i)
				checkedListBox1->SetItemChecked(i, false);
		}

		Void saveToolStripMenuItem_Click(Object^, EventArgs^) {
			Globals::save();

			const auto DG = this->dataGridView1;
			const auto cols = DG->ColumnCount, rows = DG->RowCount;
			auto& data = Globals::mainDataJson["Data"];
			for(int i = 0; i < rows; ++i) {
				auto& entry = data[i];
				entry["Date"] = string_cast(DG->Rows[i]->Cells[0]->Value->ToString());
				entry["Name"] = string_cast(DG->Rows[i]->Cells[1]->Value->ToString());
				entry["Services"] = string_cast(DG->Rows[i]->Cells[2]->Value->ToString());
				entry["Price"] = Convert::ToInt16(DG->Rows[i]->Cells[3]->Value->ToString());
			}

			FolderBrowserDialog^ FBD = gcnew FolderBrowserDialog;
			if(FBD->ShowDialog() == Windows::Forms::DialogResult::OK)
				Globals::saveData(string_cast(FBD->SelectedPath));
		}

		Void loadToolStripMenuItem_Click(Object^, EventArgs^) {
			OpenFileDialog^ OFD = gcnew OpenFileDialog;
			OFD->Filter = "json files(*.json)|*.json";
			if(OFD->ShowDialog() != Windows::Forms::DialogResult::OK)
				return;

			Globals::loadData(string_cast(OFD->FileName));
			const auto& data = Globals::mainDataJson.at("Data");
			for(auto& entry : data) {
				auto date = DateTime::ParseExact(string_cast(entry["Date"].get<std::string>()), customDateFormat, nullptr);
				const auto name = string_cast(entry["Name"].get<std::string>());
				const auto services = string_cast(entry["Services"].get<std::string>());
				const auto price = entry["Price"].get<short>();
				dataGridView1->Rows->Add(date.ToString(customDateFormat), name, services, price);
			}
			sort();
		}

		Void customerNametb_KeyPress(Object^, KeyPressEventArgs^ e) {
			e->Handled = !(Char::IsLetter(e->KeyChar) || e->KeyChar == (char)Keys::Back);
		}

		Void button1_Click(Object^, EventArgs^) {
			if(dateTimePicker1->Value <= DateTime::Now.AddMinutes(5)) {
				MB_WARNING("WRONG_DATE");
				return;
			}
			if(String::IsNullOrEmpty(customerNametb->Text)) {
				MB_WARNING("FIELDS_EMPTY");
				return;
			}
			const auto checkedCount = checkedListBox1->CheckedItems->Count;
			if(checkedCount == 0) {
				MB_WARNING("NOT_CHECKED");
				return;
			}

			String^ selectedItems;
			for each(Object ^ item in checkedListBox1->CheckedItems)
				selectedItems += item->ToString() + ", ";
			selectedItems = selectedItems->Remove(selectedItems->Length - 2);

			const int priceForOneService = 15;
			const int totalPrice = priceForOneService * checkedCount;
			const auto DTValue = dateTimePicker1->Value.ToString(customDateFormat);
			dataGridView1->Rows->Add(DTValue, customerNametb->Text, selectedItems, totalPrice);

			resetValues();
			sort();
		}

		inline void updateUI() {
			this->Controls->Clear();
			InitializeComponent();
			Globals::applyTheme(this);
		}

		Void englishToolStripMenuItem_Click(Object^, EventArgs^) {
			Globals::changeLang(Languages::ENG);
			updateUI();
		}

		Void russianToolStripMenuItem_Click(Object^, EventArgs^) {
			Globals::changeLang(Languages::RU);
			updateUI();
		}

		Void belarusianToolStripMenuItem_Click(Object^, EventArgs^) {
			Globals::changeLang(Languages::BEL);
			updateUI();
		}

		Void darkToolStripMenuItem_Click(Object^, EventArgs^) {
			Globals::updateTheme(Themes::Dark);
			Globals::applyTheme(this);
		}

		Void lightToolStripMenuItem_Click(Object^, EventArgs^) {
			Globals::updateTheme(Themes::Light);
			Globals::applyTheme(this);
		}

		Void colorfulToolStripMenuItem_Click(Object^, EventArgs^) {
			Globals::updateTheme(Themes::Colorful);
			Globals::applyTheme(this);
		}
	};
}  // namespace Kursovaya
