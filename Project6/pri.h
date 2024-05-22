#pragma once

namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ pri
	/// </summary>
	public ref class pri : public System::Windows::Forms::Form
	{
	public:
		pri(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~pri()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ expression;
	protected:
	private: System::Windows::Forms::Button^ get_expression;
	private: System::Windows::Forms::TextBox^ posk_text;
	private: System::Windows::Forms::PictureBox^ board;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ output_p;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->expression = (gcnew System::Windows::Forms::TextBox());
			this->get_expression = (gcnew System::Windows::Forms::Button());
			this->posk_text = (gcnew System::Windows::Forms::TextBox());
			this->board = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->output_p = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->board))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// expression
			// 
			this->expression->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->expression->Location = System::Drawing::Point(759, 82);
			this->expression->Name = L"expression";
			this->expression->Size = System::Drawing::Size(407, 31);
			this->expression->TabIndex = 1;
			this->expression->Text = L"x";
			// 
			// get_expression
			// 
			this->get_expression->Location = System::Drawing::Point(981, 232);
			this->get_expression->Name = L"get_expression";
			this->get_expression->Size = System::Drawing::Size(88, 31);
			this->get_expression->TabIndex = 2;
			this->get_expression->Text = L"build";
			this->get_expression->UseVisualStyleBackColor = true;
			this->get_expression->Click += gcnew System::EventHandler(this, &pri::get_expression_Click);
			// 
			// posk_text
			// 
			this->posk_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->posk_text->Location = System::Drawing::Point(759, 119);
			this->posk_text->Name = L"posk_text";
			this->posk_text->Size = System::Drawing::Size(407, 31);
			this->posk_text->TabIndex = 3;
			// 
			// board
			// 
			this->board->Location = System::Drawing::Point(0, 0);
			this->board->Name = L"board";
			this->board->Size = System::Drawing::Size(709, 534);
			this->board->TabIndex = 4;
			this->board->TabStop = false;
			this->board->Click += gcnew System::EventHandler(this, &pri::board_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(781, 343);
			this->trackBar1->Maximum = 500;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(276, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Value = 100;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &pri::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Open Sans SemiBold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(781, 311);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 31);
			this->label1->TabIndex = 6;
			this->label1->Text = L"scale";
			// 
			// output_p
			// 
			this->output_p->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->output_p->Location = System::Drawing::Point(759, 195);
			this->output_p->Name = L"output_p";
			this->output_p->Size = System::Drawing::Size(407, 31);
			this->output_p->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Open Sans SemiBold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(753, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(255, 31);
			this->label2->TabIndex = 8;
			this->label2->Text = L"производна€ функции";
			// 
			// pri
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 606);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->output_p);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->board);
			this->Controls->Add(this->posk_text);
			this->Controls->Add(this->get_expression);
			this->Controls->Add(this->expression);
			this->Name = L"pri";
			this->Text = L"pri";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->board))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void paint();
		System::Void get_expression_Click(System::Object^ sender, System::EventArgs^ e);
	
	
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e);
private: System::Void p();

private: System::Void board_Click(System::Object^ sender, System::EventArgs^ e);


};
}
