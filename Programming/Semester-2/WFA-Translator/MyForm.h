#pragma once




//class tWord
//{
//	System::String^ wEnglish;
//	 wRussian;
//};



namespace WFA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_translate;
	protected:

	private: System::Windows::Forms::Label^  text_root;

	protected:

	private: System::Windows::Forms::TextBox^  textBox;

	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::Label^  label_translation;




	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog2;





	private: System::ComponentModel::IContainer^  components;



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
			this->components = (gcnew System::ComponentModel::Container());
			this->button_translate = (gcnew System::Windows::Forms::Button());
			this->text_root = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->label_translation = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_translate
			// 
			this->button_translate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_translate->BackColor = System::Drawing::SystemColors::Desktop;
			this->button_translate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_translate->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button_translate->Location = System::Drawing::Point(461, 358);
			this->button_translate->Name = L"button_translate";
			this->button_translate->Size = System::Drawing::Size(200, 53);
			this->button_translate->TabIndex = 0;
			this->button_translate->Text = L"Translate";
			this->button_translate->UseVisualStyleBackColor = false;
			this->button_translate->Click += gcnew System::EventHandler(this, &MyForm::button_translate_Click);
			// 
			// text_root
			// 
			this->text_root->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->text_root->AutoSize = true;
			this->text_root->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.875F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->text_root->Location = System::Drawing::Point(198, 75);
			this->text_root->Name = L"text_root";
			this->text_root->Size = System::Drawing::Size(280, 41);
			this->text_root->TabIndex = 1;
			this->text_root->Text = L"Enter english word";
			// 
			// textBox
			// 
			this->textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox->Location = System::Drawing::Point(134, 169);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(390, 69);
			this->textBox->TabIndex = 2;
			// 
			// label_translation
			// 
			this->label_translation->AutoSize = true;
			this->label_translation->Location = System::Drawing::Point(110, 372);
			this->label_translation->Name = L"label_translation";
			this->label_translation->Size = System::Drawing::Size(120, 25);
			this->label_translation->TabIndex = 6;
			this->label_translation->Text = L"*translation";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(706, 42);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->saveAsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(64, 38);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(324, 38);
			this->openToolStripMenuItem->Text = L"Open";
			//this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(324, 38);
			this->saveAsToolStripMenuItem->Text = L"Save as";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(324, 38);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(706, 472);
			this->Controls->Add(this->label_translation);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->text_root);
			this->Controls->Add(this->button_translate);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->Text = "Translation";

		//text_root->Text = String::Format("{0}", Convert::ToChar(0x221B));
		//label1->Text = "Введите число";
		//label2->Text = "";
		//button->Text = "Вычислить";	

		////------------- реализация ToolTip
		//toolTip1->SetToolTip(textBox, "Введите\nчто-нибудь");
		//toolTip1->IsBalloon = true;
	}




	private: System::Void button_translate_Click(System::Object^  sender, System::EventArgs^  e) {
			
		bool temp = false;
		String^ fileName = "voc_41words.txt";
		try
		{
			Console::WriteLine("trying to open file {0}...", fileName);
			StreamReader^ din = File::OpenText(fileName);

			String^ str;
			String^ toTr = textBox->Text;
			while ((str = din->ReadLine()) != nullptr)
			{
				str = str->ToLower();
				toTr = toTr->ToLower();

				if (str->Contains(toTr))
				{
					temp = true;
					break;
				}

			}

			if (temp == false){
				label_translation->Text = "There's no translatoin";
			}
			else {
				label_translation->Text = str;
				temp = false;
			}

		}

		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e))
				Console::WriteLine("file '{0}' not found", fileName);
			else
				Console::WriteLine("problem reading file '{0}'", fileName);
		}
	}	
	
	};
}
