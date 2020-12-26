#pragma once

namespace lab1var2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(336, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(365, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите одномерный массив( вводить через пробел )";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(91, 188);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(324, 45);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Количество элементов, равных 0";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(608, 189);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(324, 45);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Упорядочить элементы по возрастанию модуля";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(294, 87);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(435, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::TextBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(141, 342);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 27);
			this->label2->TabIndex = 8;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(413, 435);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(195, 37);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Выход";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1042, 545);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		static array<double>^ A = gcnew array<double>(1000);
		static int f = 0;
		static int e1 = 0;

	private: System::Void TextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == ' ') || (e->KeyChar == '-') || (e->KeyChar == 8) || (e->KeyChar == ','))
			//цифра
			return;
		//остальные символы запрещены
		e->Handled = true;

	}

		   //Вывести кол-во нулевых элементов
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {

		array<String^>^ as;
		array<Char>^ ar;
		ar = gcnew array<Char>(1);
		ar[0] = ' ';
		f = 0, e1 = 0;
		//получение массива
		if (textBox1->Text->Length != 0)
		{

			as = textBox1->Text->Split(ar);
			for (int i = 0; i < as->Length; i++)
			{
				try
				{
					A[i] = Convert::ToDouble(as[i]);
					e1++;
				}
				catch (...)
				{
					MessageBox::Show("Вы неверно ввели данные !\n",
						"Ошибка",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
					label2->Text = "";
					return;
				}
			}
			//Вычисление кол-ва нулевых элементов
			for (int i = 0; i < e1; i++)
			{
				if (A[i] == 0)
					f++;
			}
			label2->Text = "Количество нулевых элементов : " + f;
		}
		else
		{
			MessageBox::Show("Вы ввели не все данные !\n",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			label2->Text = "";
		}


	}

		   //Упорядочение элементов массива по возрастанию модулей элементов
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ as;
		array<Char>^ ar;
		ar = gcnew array<Char>(1);
		ar[0] = ' ';
		f = 0, e1 = 0;
		//получение массива
		if (textBox1->Text->Length != 0)
		{

			as = textBox1->Text->Split(ar);
			for (int i = 0; i < as->Length; i++)
			{
				try
				{
					A[i] = Convert::ToDouble(as[i]);
					e1++;
				}
				catch (...)
				{
					MessageBox::Show("Вы неверно ввели данные !\n",
						"Ошибка",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
					label2->Text = "";
					return;
				}
			}
			//сортировка массива
			for (int i = 0; i < e1; i++)
			{
				for (int k = 0; k < e1 - 1; k++)
				{
					if (Math::Abs(A[k + 1]) < Math::Abs(A[k]))
					{
						double c = A[k];
						A[k] = A[k + 1];
						A[k + 1] = c;
					}
				}
			}
			String^ list;
			for (int i = 0; i < e1; i++)
				list += " " + A[i];
			label2->Text = "Упорядоченный массив : " + list;


		}
		else
		{
			MessageBox::Show("Вы ввели не все данные !\n",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			label2->Text = "";
		}
	}


	private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	};
}
