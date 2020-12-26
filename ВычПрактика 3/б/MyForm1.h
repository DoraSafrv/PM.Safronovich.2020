#pragma once
#include <cmath>

double PI = 3.14;
double EXP = 2.71828182845904523536;

namespace Graphics {

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

	protected:



	private: System::Windows::Forms::PictureBox^ pictureBox2;




	private: System::Windows::Forms::Label^ label3;

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
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(38, 127);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(675, 750);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox2_Paint);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(79, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(596, 33);
			this->label3->TabIndex = 9;
			this->label3->Text = L"График функции z = cos(sqrt(x^2 + y^2))";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(764, 890);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Графики";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		static double x0 = 4, Y0 = -0.5, z0 = 3, alf = 4.2, bet = 4.92, A = -6.5, a = -6.5;
		static double Xmin = -1.5, Xmax = 1.5, Ymin = -1.5, Ymax = 1.5;
		static int Width = 200, Height = 200;
		static double h1 = 0.1, h0 = 0.25;
		static array<Point>^ ob = gcnew array<Point>(4);

	private: void IJ(double x, double y, double z, array<int>^ ar) {
		double Xn, Yn, Zn;

		//Осуществляем перенос системы координат в т.(x0,Y0,z0)
		Xn = (x - x0) * Math::Cos(alf) - (y - Y0) * Math::Sin(alf);
		Yn = ((x - x0) * Math::Sin(alf) + (y - Y0) * Math::Cos(alf)) * Math::Cos(bet) - (z - z0) * Math::Sin(bet);
		Zn = ((x - x0) * Math::Sin(alf) + (y - Y0) * Math::Cos(alf)) * Math::Sin(bet) + (z - z0) * Math::Cos(bet);

		//Делаем проекцию на плоскость
		Xn /= Zn / A + 1;
		Yn /= Zn / a + 1;

		//Масштабируем оси x и y
		ar[0] = Width * (Xn - Xmin) / (Xmax - Xmin);
		ar[1] = Height * (Yn - Ymax) / (Ymin - Ymax);
	}

	private: double F1(double x1, double y1) {
		return (Math::Cos(Math::Sqrt(x1 * x1 + y1 * y1)));
	}

	private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		int i3, j3;
		int i1, j1, i2, j2;
		array<int>^ a1;
		array<int>^ a2;
		a1 = gcnew array<int>(2);
		a2 = gcnew array<int>(2);
		IJ(0, 0, 0, a1);

		//Рисуем и подписываем ось x
		IJ(4, 0, 0, a2);
		e->Graphics->DrawLine(Pens::White, a1[0], a1[1], a2[0], a2[1]);
		e->Graphics->DrawString("X", this->Font, Brushes::Red, a2[0] + 3, a2[1]);

		//Рисуем и подписываем ось y
		IJ(0, 4, 0, a2);
		e->Graphics->DrawLine(Pens::White, a1[0], a1[1], a2[0], a2[1]);
		e->Graphics->DrawString("Y", this->Font, Brushes::Red, a2[0] + 3, a2[1]);

		//Рисуем и подписываем ось z
		IJ(0, 0, 4.3, a2);
		e->Graphics->DrawLine(Pens::White, a1[0], a1[1], a2[0], a2[1]);
		e->Graphics->DrawString("Z", this->Font, Brushes::Red, a2[0] + 3, a2[1] - 3);


		for (j3 = 0; j3 < 25; j3++) {
			for (i3 = 0; i3 < 30; i3++) {
				IJ(h0 + h1 * i3, h0 + h1 * j3, F1(h0 + h1 * i3, h0 + h1 * j3), a1);
				ob[0].X = a1[0];
				ob[0].Y = a1[1];
				IJ(h0 + h1 * i3, h0 + h1 * (j3 + 1), F1(h0 + h1 * i3, h0 + h1 * (j3 + 1)), a1);
				ob[1].X = a1[0];
				ob[1].Y = a1[1];
				IJ(h0 + h1 * (i3 + 1), h0 + h1 * (j3 + 1), F1(h0 + h1 * (i3 + 1), h0 + h1 * (j3 + 1)), a1);
				ob[2].X = a1[0];
				ob[2].Y = a1[1];
				IJ(h0 + h1 * (i3 + 1), h0 + h1 * j3, F1(h0 + h1 * (i3 + 1), h0 + h1 * j3), a1);
				ob[3].X = a1[0];
				ob[3].Y = a1[1];
				e->Graphics->DrawPolygon(Pens::Yellow, ob);
			}
		}
	}
	};
}