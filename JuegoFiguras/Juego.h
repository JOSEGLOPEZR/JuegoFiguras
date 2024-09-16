#pragma once

namespace JuegoFiguras {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
		int vidas = 3;          // Lives counter, used to remove red hearts
		int puntos = 0;         // Points counter, win when reaching 4 points
		int puntosVictoria = 0; // Victory points counter, displayed from 0 to 100
		int contador = 0;       // Counter to switch images
		int numlados;           // Stores the number of sides of the shape


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ lblAux;


	private: System::Windows::Forms::PictureBox^ Correcto;
	private: System::Windows::Forms::PictureBox^ Incorrecto;
	private: System::Windows::Forms::PictureBox^ corazonB3;
	private: System::Windows::Forms::PictureBox^ corazonB2;
	private: System::Windows::Forms::PictureBox^ corazonB1;
	private: System::Windows::Forms::PictureBox^ corazonR3;
	private: System::Windows::Forms::PictureBox^ corazonR2;
	private: System::Windows::Forms::PictureBox^ corazonR1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblPuntos;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	public:
		Juego(void)
		{
			InitializeComponent();
			//
			//

			// Base route
			String^ rutaBase = AppDomain::CurrentDomain->BaseDirectory;

			// Simple gif
			GifInicio->Image = Image::FromFile(rutaBase + "Imagenes/presioneIniciar.gif");

			// Initial state of pictureBox
			Figura1->Visible = false;
			Figura2->Visible = false;
			Figura3->Visible = false;
			Figura4->Visible = false;
			Correcto->Visible = false;
			Incorrecto->Visible = false;
			corazonB1->Visible = false;
			corazonB2->Visible = false;
			corazonB3->Visible = false;

			// Load images 
			Figura1->Image = Image::FromFile(rutaBase + "Imagenes/TRIANGULO.png");
			Figura2->Image = Image::FromFile(rutaBase + "Imagenes/CUADRADO.png");
			Figura3->Image = Image::FromFile(rutaBase + "Imagenes/ROMBO.png");
			Figura4->Image = Image::FromFile(rutaBase + "Imagenes/PENTAGONO.png");
			Correcto->Image = Image::FromFile(rutaBase + "Imagenes/Correcto.png");
			Incorrecto->Image = Image::FromFile(rutaBase + "Imagenes/Incorrecto.png");
			corazonR1->Image = Image::FromFile(rutaBase + "Imagenes/CorazonRojo.png");
			corazonR2->Image = Image::FromFile(rutaBase + "Imagenes/CorazonRojo.png");
			corazonR3->Image = Image::FromFile(rutaBase + "Imagenes/CorazonRojo.png");
			corazonB1->Image = Image::FromFile(rutaBase + "Imagenes/CorazonBlanco.png");
			corazonB2->Image = Image::FromFile(rutaBase + "Imagenes/CorazonBlanco.png");
			corazonB3->Image = Image::FromFile(rutaBase + "Imagenes/CorazonBlanco.png");

			// Hide "playing" and "end" buttons
			btnJugando->Visible = false;
			btnFinJuego->Visible = false;

			// Disable all buttons when the game starts
			btn1->Enabled = false;
			btn2->Enabled = false;
			btn3->Enabled = false;
			btn4->Enabled = false;
			btn5->Enabled = false;
			btn6->Enabled = false;
			btn7->Enabled = false;
			btn8->Enabled = false;
			btn9->Enabled = false;
			button1->Enabled = false;

			// Assign tags to buttons
			btn1->Tag = 1;
			btn2->Tag = 2;
			btn3->Tag = 3;
			btn4->Tag = 4;
			btn5->Tag = 5;
			btn6->Tag = 6;
			btn7->Tag = 7;
			btn8->Tag = 8;
			btn9->Tag = 9;
		}

		// Function to enable images and buttons
		void Iniciar() {
			GifInicio->Visible = false;
			btn1->Enabled = true;
			btn2->Enabled = true;
			btn3->Enabled = true;
			btn4->Enabled = true;
			btn5->Enabled = true;
			btn6->Enabled = true;
			btn7->Enabled = true;
			btn8->Enabled = true;
			btn9->Enabled = true;
			button1->Enabled = true;
			btnIniciarJuego->Visible = false;
			btnJugando->Visible = true;
			Figura1->Visible = true;
		}

		// Function to handle image carousel
		void LlamarImagenes() {
			Figura1->Visible = false;
			Figura2->Visible = false;
			Figura3->Visible = false;
			Figura4->Visible = false;

			if (contador == 0)
				Figura1->Visible = true;
			else if (contador == 1)
				Figura2->Visible = true;
			else if (contador == 2)
				Figura3->Visible = true;
			else if (contador == 3)
				Figura4->Visible = true;

			contador++;

			if (contador >= 4) // Reset carousel
				contador = 0;

			// Set number of sides based on visible figure
			if (Figura1->Visible == true) 
			{
				lblAux->Text = "3";
				numlados = Int32::Parse(lblAux->Text);
			}
			else if (Figura2->Visible == true)
			{
				lblAux->Text = "4";
				numlados = Int32::Parse(lblAux->Text);

			}
			else if (Figura3->Visible == true)
			{
				lblAux->Text = "4";
				numlados = Int32::Parse(lblAux->Text);

			}
			else if (Figura4->Visible == true)
			{
				lblAux->Text = "5";
				numlados = Int32::Parse(lblAux->Text);

			}
		}

		// Function to handle losing lives
		void PerderVida() {
			if (vidas == 2)
			{
				corazonR1->Visible = false;
				corazonB1->Visible = true;
			}
			else if (vidas == 1)
			{
				corazonR2->Visible = false;
				corazonB2->Visible = true;

			}
			else if (vidas == 0)
			{
				corazonR3->Visible = false;
				corazonB3->Visible = true;

			}
		}
		// Function to show the player won or lost and closes the form immediately
		void GanarPerder() {
			if (puntos == 4)
			{
				MessageBox::Show("¡Felicidades! ¡Eres un ganador!", "G A N A S T E", MessageBoxButtons::OK, MessageBoxIcon::Information);
				btnFinJuego->Visible = true;
				btnJugando->Visible = false;
				this->Close(); 
			}
			else if (vidas == 0) {
				btnJugando->Visible = false;
				btnFinJuego->Visible = true;
				MessageBox::Show("Perdiste todas tus vidas. Juego Terminado :(", "P E R D I S T E", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close(); 
			}
		}
		// Function to add 25 points at a time, until you reach 100 points
		void SumarPuntos() {
			if (puntosVictoria == 1)
			{
				lblPuntos->Text = "25";
			}
			else if (puntosVictoria == 2)
			{
				lblPuntos->Text = "50";
			}
			else if (puntosVictoria == 3)
			{
				lblPuntos->Text = "75";
			}
			else if (puntosVictoria == 4)
			{
				lblPuntos->Text = "100";
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ GifInicio;


	private: System::Windows::Forms::Button^ btn1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn5;


	private: System::Windows::Forms::Label^ lblResultado;
	private: System::Windows::Forms::Button^ btn6;
	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Button^ btn8;
	private: System::Windows::Forms::Button^ btn9;
	private: System::Windows::Forms::Button^ btnIniciarJuego;
	private: System::Windows::Forms::PictureBox^ Figura1;


	private: System::Windows::Forms::Button^ btnJugando;
	private: System::Windows::Forms::Button^ btnFinJuego;

	private: System::Windows::Forms::PictureBox^ Figura2;
	private: System::Windows::Forms::PictureBox^ Figura3;
	private: System::Windows::Forms::PictureBox^ Figura4;




	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->corazonB3 = (gcnew System::Windows::Forms::PictureBox());
			this->corazonB2 = (gcnew System::Windows::Forms::PictureBox());
			this->corazonB1 = (gcnew System::Windows::Forms::PictureBox());
			this->corazonR3 = (gcnew System::Windows::Forms::PictureBox());
			this->corazonR2 = (gcnew System::Windows::Forms::PictureBox());
			this->corazonR1 = (gcnew System::Windows::Forms::PictureBox());
			this->GifInicio = (gcnew System::Windows::Forms::PictureBox());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->lblResultado = (gcnew System::Windows::Forms::Label());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btnIniciarJuego = (gcnew System::Windows::Forms::Button());
			this->btnJugando = (gcnew System::Windows::Forms::Button());
			this->btnFinJuego = (gcnew System::Windows::Forms::Button());
			this->Figura1 = (gcnew System::Windows::Forms::PictureBox());
			this->Figura2 = (gcnew System::Windows::Forms::PictureBox());
			this->Figura3 = (gcnew System::Windows::Forms::PictureBox());
			this->Figura4 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lblAux = (gcnew System::Windows::Forms::Label());
			this->Correcto = (gcnew System::Windows::Forms::PictureBox());
			this->Incorrecto = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblPuntos = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonB3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonB2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonB1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonR3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonR2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonR1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GifInicio))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Correcto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Incorrecto))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->corazonB3);
			this->groupBox1->Controls->Add(this->corazonB2);
			this->groupBox1->Controls->Add(this->corazonB1);
			this->groupBox1->Controls->Add(this->corazonR3);
			this->groupBox1->Controls->Add(this->corazonR2);
			this->groupBox1->Controls->Add(this->corazonR1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(667, 53);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(205, 87);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Vidas Restantes";
			// 
			// corazonB3
			// 
			this->corazonB3->Location = System::Drawing::Point(143, 28);
			this->corazonB3->Name = L"corazonB3";
			this->corazonB3->Size = System::Drawing::Size(50, 50);
			this->corazonB3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->corazonB3->TabIndex = 35;
			this->corazonB3->TabStop = false;
			// 
			// corazonB2
			// 
			this->corazonB2->Location = System::Drawing::Point(87, 28);
			this->corazonB2->Name = L"corazonB2";
			this->corazonB2->Size = System::Drawing::Size(50, 50);
			this->corazonB2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->corazonB2->TabIndex = 36;
			this->corazonB2->TabStop = false;
			// 
			// corazonB1
			// 
			this->corazonB1->Location = System::Drawing::Point(31, 28);
			this->corazonB1->Name = L"corazonB1";
			this->corazonB1->Size = System::Drawing::Size(50, 50);
			this->corazonB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->corazonB1->TabIndex = 37;
			this->corazonB1->TabStop = false;
			// 
			// corazonR3
			// 
			this->corazonR3->Location = System::Drawing::Point(143, 28);
			this->corazonR3->Name = L"corazonR3";
			this->corazonR3->Size = System::Drawing::Size(50, 50);
			this->corazonR3->TabIndex = 40;
			this->corazonR3->TabStop = false;
			// 
			// corazonR2
			// 
			this->corazonR2->Location = System::Drawing::Point(87, 28);
			this->corazonR2->Name = L"corazonR2";
			this->corazonR2->Size = System::Drawing::Size(50, 50);
			this->corazonR2->TabIndex = 39;
			this->corazonR2->TabStop = false;
			// 
			// corazonR1
			// 
			this->corazonR1->Location = System::Drawing::Point(31, 28);
			this->corazonR1->Name = L"corazonR1";
			this->corazonR1->Size = System::Drawing::Size(50, 50);
			this->corazonR1->TabIndex = 38;
			this->corazonR1->TabStop = false;
			// 
			// GifInicio
			// 
			this->GifInicio->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GifInicio.Image")));
			this->GifInicio->Location = System::Drawing::Point(309, 53);
			this->GifInicio->Name = L"GifInicio";
			this->GifInicio->Size = System::Drawing::Size(237, 209);
			this->GifInicio->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->GifInicio->TabIndex = 4;
			this->GifInicio->TabStop = false;
			// 
			// btn1
			// 
			this->btn1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn1.BackgroundImage")));
			this->btn1->FlatAppearance->BorderSize = 0;
			this->btn1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn1->Location = System::Drawing::Point(320, 374);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(57, 51);
			this->btn1->TabIndex = 5;
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &Juego::btn1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(126, 312);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(602, 30);
			this->label1->TabIndex = 6;
			this->label1->Text = L"¿Cuántos lados tiene la figura\?";
			// 
			// btn2
			// 
			this->btn2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn2.BackgroundImage")));
			this->btn2->FlatAppearance->BorderSize = 0;
			this->btn2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn2->Location = System::Drawing::Point(383, 374);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(51, 51);
			this->btn2->TabIndex = 7;
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &Juego::btn2_Click);
			// 
			// btn3
			// 
			this->btn3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn3.BackgroundImage")));
			this->btn3->FlatAppearance->BorderSize = 0;
			this->btn3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn3->Location = System::Drawing::Point(440, 375);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(51, 50);
			this->btn3->TabIndex = 8;
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &Juego::btn3_Click);
			// 
			// btn4
			// 
			this->btn4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn4.BackgroundImage")));
			this->btn4->FlatAppearance->BorderSize = 0;
			this->btn4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn4->Location = System::Drawing::Point(325, 427);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(51, 51);
			this->btn4->TabIndex = 9;
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Juego::btn4_Click);
			// 
			// btn5
			// 
			this->btn5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn5.BackgroundImage")));
			this->btn5->FlatAppearance->BorderSize = 0;
			this->btn5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn5->Location = System::Drawing::Point(383, 427);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(51, 51);
			this->btn5->TabIndex = 10;
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &Juego::btn5_Click);
			// 
			// lblResultado
			// 
			this->lblResultado->AutoSize = true;
			this->lblResultado->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblResultado->Location = System::Drawing::Point(95, 143);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(64, 29);
			this->lblResultado->TabIndex = 15;
			this->lblResultado->Text = L"...";
			// 
			// btn6
			// 
			this->btn6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn6.BackgroundImage")));
			this->btn6->FlatAppearance->BorderSize = 0;
			this->btn6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn6->Location = System::Drawing::Point(440, 427);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(51, 49);
			this->btn6->TabIndex = 16;
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &Juego::btn6_Click);
			// 
			// btn7
			// 
			this->btn7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn7.BackgroundImage")));
			this->btn7->FlatAppearance->BorderSize = 0;
			this->btn7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn7->Location = System::Drawing::Point(326, 477);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(51, 50);
			this->btn7->TabIndex = 17;
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &Juego::btn7_Click);
			// 
			// btn8
			// 
			this->btn8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn8.BackgroundImage")));
			this->btn8->FlatAppearance->BorderSize = 0;
			this->btn8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn8->Location = System::Drawing::Point(383, 477);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(51, 49);
			this->btn8->TabIndex = 18;
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &Juego::btn8_Click);
			// 
			// btn9
			// 
			this->btn9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn9.BackgroundImage")));
			this->btn9->FlatAppearance->BorderSize = 0;
			this->btn9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn9->Location = System::Drawing::Point(440, 477);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(50, 50);
			this->btn9->TabIndex = 19;
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &Juego::btn9_Click);
			// 
			// btnIniciarJuego
			// 
			this->btnIniciarJuego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnIniciarJuego.BackgroundImage")));
			this->btnIniciarJuego->FlatAppearance->BorderSize = 0;
			this->btnIniciarJuego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIniciarJuego->Location = System::Drawing::Point(12, 467);
			this->btnIniciarJuego->Name = L"btnIniciarJuego";
			this->btnIniciarJuego->Size = System::Drawing::Size(168, 69);
			this->btnIniciarJuego->TabIndex = 20;
			this->btnIniciarJuego->UseVisualStyleBackColor = true;
			this->btnIniciarJuego->Click += gcnew System::EventHandler(this, &Juego::btnIniciarJuego_Click);
			// 
			// btnJugando
			// 
			this->btnJugando->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJugando.BackgroundImage")));
			this->btnJugando->FlatAppearance->BorderSize = 0;
			this->btnJugando->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJugando->Location = System::Drawing::Point(12, 468);
			this->btnJugando->Name = L"btnJugando";
			this->btnJugando->Size = System::Drawing::Size(168, 69);
			this->btnJugando->TabIndex = 22;
			this->btnJugando->UseVisualStyleBackColor = true;
			// 
			// btnFinJuego
			// 
			this->btnFinJuego->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnFinJuego.BackgroundImage")));
			this->btnFinJuego->FlatAppearance->BorderSize = 0;
			this->btnFinJuego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFinJuego->Location = System::Drawing::Point(12, 468);
			this->btnFinJuego->Name = L"btnFinJuego";
			this->btnFinJuego->Size = System::Drawing::Size(168, 69);
			this->btnFinJuego->TabIndex = 23;
			this->btnFinJuego->UseVisualStyleBackColor = true;
			// 
			// Figura1
			// 
			this->Figura1->Location = System::Drawing::Point(309, 53);
			this->Figura1->Name = L"Figura1";
			this->Figura1->Size = System::Drawing::Size(237, 209);
			this->Figura1->TabIndex = 24;
			this->Figura1->TabStop = false;
			// 
			// Figura2
			// 
			this->Figura2->Location = System::Drawing::Point(309, 52);
			this->Figura2->Name = L"Figura2";
			this->Figura2->Size = System::Drawing::Size(237, 209);
			this->Figura2->TabIndex = 26;
			this->Figura2->TabStop = false;
			// 
			// Figura3
			// 
			this->Figura3->Location = System::Drawing::Point(309, 52);
			this->Figura3->Name = L"Figura3";
			this->Figura3->Size = System::Drawing::Size(237, 209);
			this->Figura3->TabIndex = 27;
			this->Figura3->TabStop = false;
			// 
			// Figura4
			// 
			this->Figura4->Location = System::Drawing::Point(309, 53);
			this->Figura4->Name = L"Figura4";
			this->Figura4->Size = System::Drawing::Size(237, 209);
			this->Figura4->TabIndex = 28;
			this->Figura4->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(369, 268);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 39);
			this->button1->TabIndex = 29;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Juego::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(298, 357);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(217, 179);
			this->groupBox2->TabIndex = 30;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Números";
			// 
			// lblAux
			// 
			this->lblAux->AutoSize = true;
			this->lblAux->Location = System::Drawing::Point(807, 446);
			this->lblAux->Name = L"lblAux";
			this->lblAux->Size = System::Drawing::Size(35, 13);
			this->lblAux->TabIndex = 32;
			this->lblAux->Text = L"label2";
			this->lblAux->Visible = false;
			// 
			// Correcto
			// 
			this->Correcto->Location = System::Drawing::Point(222, 193);
			this->Correcto->Name = L"Correcto";
			this->Correcto->Size = System::Drawing::Size(68, 68);
			this->Correcto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Correcto->TabIndex = 33;
			this->Correcto->TabStop = false;
			// 
			// Incorrecto
			// 
			this->Incorrecto->Location = System::Drawing::Point(563, 194);
			this->Incorrecto->Name = L"Incorrecto";
			this->Incorrecto->Size = System::Drawing::Size(68, 68);
			this->Incorrecto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Incorrecto->TabIndex = 34;
			this->Incorrecto->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(723, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 20);
			this->label2->TabIndex = 35;
			this->label2->Text = L"P U N T O S:";
			// 
			// lblPuntos
			// 
			this->lblPuntos->AutoSize = true;
			this->lblPuntos->Font = (gcnew System::Drawing::Font(L"Marlett", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblPuntos->Location = System::Drawing::Point(752, 175);
			this->lblPuntos->Name = L"lblPuntos";
			this->lblPuntos->Size = System::Drawing::Size(17, 18);
			this->lblPuntos->TabIndex = 36;
			this->lblPuntos->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(149, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(545, 30);
			this->label3->TabIndex = 37;
			this->label3->Text = L"CONSIGUE 100 PUNTOS Y GANA!!";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 81);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(249, 20);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Número Seleccionado:";
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(884, 560);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblPuntos);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Incorrecto);
			this->Controls->Add(this->Correcto);
			this->Controls->Add(this->lblAux);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Figura4);
			this->Controls->Add(this->Figura3);
			this->Controls->Add(this->Figura2);
			this->Controls->Add(this->Figura1);
			this->Controls->Add(this->btnFinJuego);
			this->Controls->Add(this->btnJugando);
			this->Controls->Add(this->btnIniciarJuego);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->lblResultado);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->GifInicio);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Location = System::Drawing::Point(21, 219);
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Figuras Geométricas";
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonB3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonB2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonB1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonR3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonR2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->corazonR1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GifInicio))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Figura4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Correcto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Incorrecto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//INICIA

		private: System::Void ProcesarClick(System::Object^ sender) {
			// Obtener el botón que disparó el evento
			Button^ boton = safe_cast<Button^>(sender);

			// Extraer el valor del tag como el número del botón
			int valorBoton = Int32::Parse(boton->Tag->ToString());

			lblResultado->Text = valorBoton.ToString(); // Actualizar el label con el número
			int ladosclick = valorBoton; // Usar directamente el valor del botón clicado

			if (ladosclick == numlados) {
				puntosVictoria++;
				Correcto->Visible = true;
				puntos++;
			}
			else {
				vidas--;
				PerderVida();
				Incorrecto->Visible = true;
			}

			SumarPuntos();
			GanarPerder();
		}









	private: System::Void btn1_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btn2_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btn3_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btn4_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btn5_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}

	private: System::Void btn6_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btn7_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btn8_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btn9_Click(System::Object^ sender, System::EventArgs^ e) {
		ProcesarClick(sender);
	}
	private: System::Void btnIniciarJuego_Click(System::Object^ sender, System::EventArgs^ e) {
		Iniciar();
		LlamarImagenes();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	LlamarImagenes();
	Correcto->Visible = false;
	Incorrecto->Visible = false;
	}
};
}





