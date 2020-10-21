#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <unistd.h>
using namespace std;

// =======================================================================================
// Program Simulasi Mesin ATM v1.0
// Program ini dibuat untuk memenuhi tugas mata kuliah Teknik Pemodelan dan Simulasi 5E
// Yang dibina oleh dosen kami yaitu Desi Nurmaningsih S.Kom, M.Kom
// 
// Program ini dibuat oleh:
// Muhammad Fikri Syahid	(11180910000041)
// Muhammad Akmal Fauzan	(11180910000044)
// Rahmadhan Adinugroho		(11180910000046)
//
// UIN Syarif Hidayatullah Jakarta Fakultas Sains dan Teknologi Jurusan Teknik Informatika 
// Tahun ajaran 2020/2021
// =======================================================================================

HANDLE out	= GetStdHandle(STD_OUTPUT_HANDLE);
HWND wh 	= GetConsoleWindow();

void masukkanKartu();
void masukkanPin(string);
void mainMenu(char&);
void keluarKartu();
void configureCMD();
void fontsize(int,int);

int main(){
	// Variabel ==================================================
	char pilihan = 0;												// Variabel sementara untuk pilihan pada main menu
	
	// Data nasabah ==============================================
	string pinT	= "123456";											// PIN untuk akses ATM
	int saldo	= 10000000;											// Jumlah saldo
	
	// Pengaturan CMD ============================================
	configureCMD();													// Mengatur tampilan CMD

    // Kartu dan PIN =============================================
    masukkanKartu();												// Tampilan masukkan kartu
    masukkanPin(pinT);												// Tampilan masukkan pin
    
    // Main Menu =================================================
    mainMenu(pilihan);												// Tampilan main menu sekaligus menetapkan pilihan transaksi
    switch(pilihan){
    	case '1':{
    		system("cls");
			break;
		}
		case '2':{
			system("cls");
			break;
		}
		case '3':{
			system("cls");
			break;
		}
		case '4':{
			system("cls");
			break;
		}
		case '5':{
			system("cls");
			break;
		}
		case '6':{
			system("cls");
			break;
		}
		case '7':{
			system("cls");
			break;
		}
		case '8':{
			system("cls");
			break;
		}
		case '0':{
			keluarKartu();
			break;
		}
	}
	return 0;
}

void masukkanKartu(){
	char ch;
	system("cls");
	cout << "\n\t     SELAMAT DATANG DI\n\n";
	cout << "\tPROGRAM SIMULASI MESIN ATM\n\n\n\n\n\n\n";
	cout << "\tSILAHKAN MASUKKAN KARTU ANDA\n"
		 << "\t      UNTUK PELAYANAN\n\n";
	cout << "   TEKAN [ENTER] UNTUK MEMASUKKAN KARTU\n\n";
	ch = _getch();
	while(ch != 13){
		ch = _getch();
	}
	Beep(600,200);
}

void masukkanPin(string pinT){
	string pin;
	char ch;
	while(pin != pinT){												// Ketika pin tidak sama dengan pinT
		pin = "";													// maka akan terus menampilkan tampilan masukkan pin
		system("cls");
		cout << "\n\t\tHATI-HATI!!\n"
			 << "  JANGAN MEMBERITAHUKAN PIN DAN NO KARTU\n"
			 << "\t   ANDA KEPADA SIAPAPUN\n\n\n\n"
			 << "      SILAHKAN MASUKKAN NOMOR PIN ANDA\n\n"
			 << "\t\t  ";
		while(1){
			ch = _getch();
			if(ch == 13 && pin.length() == 6){						// Kondisi untuk keluar loop
				Beep(600,200);
				break;													
			}
			if(ch == 8 && pin.length() >= 1){						// Menghapus karakter
				cout << char(8) << " " << char(8);						
				pin = pin.erase(pin.length()-1);					
				continue;												
			}
			if(ch < 48 || ch > 57 || pin.length() >= 6){			// Hanya angka yang dapat diinput dan 
				continue;											// ketika sudah 6 karakter tidak bisa input lagi
			}
			pin.push_back(ch);
			cout << "X";
			Beep(600,200);
		}
		if(pin != pinT){
    		cout << "\n\n"
				 << "       PIN YANG ANDA MASUKKAN SALAH\n\n\n\n";
    		sleep(3);
		}
	}
}

void mainMenu(char &pilihan){
	char ch;
	system("cls");
	cout << "\n\t\tMENU UTAMA\n"
		 << "\t (PECAHAN UANG RP.50.000)\n"
		 << "\t==========================\n"
		 << "\t  TEKAN <0> UNTUK BATAL\n\n"
	  // << "                                             "
		 << "[1]<---- 100.000           500.000 ---->[5]\n\n"
		 << "[2]<---- 300.000           1000.000 --->[6]\n\n"
		 << "[3]<----- BAYAR/           PENARIKAN -->[7]\n"
		 << "            BELI           JUMLAH LAIN\n\n"
		 << "[4]<---- MANDIRI           TRANSAKSI -->[8]\n"
		 << "        PRABAYAR           LAINNYA\n";
	while(1){
		ch = _getch();
		if(ch < 48 || ch > 56){										// Input pilihan hanya boleh angka tertentu
			continue;
		}else{
			pilihan = ch;
			Beep(600,200);
			break;
		}
	}
}

void keluarKartu(){
	char ch;
	system("cls");
    cout << "\n\n\n";
	cout << "\tHARAP AMBIL KARTU ATM ANDA\n\n";
	cout << "    TEKAN [ENTER] UNTUK MENGAMBIL KARTU"
		 << "\n\n\n\n\n\n\n\n\n\n";
	ch = _getch();
	while(ch != 13){
		ch = _getch();
	}
	Beep(600,200);
	system("cls");
	cout << "\n\n\n\n\n\n\n"
		 << "\t\tTERIMAKASIH\n\n\n\n\n\n\n\n";
	sleep(3);
	system("cls");
}

void configureCMD(){
	_COORD coord;													// Variabel untuk menyimpan window size
	coord.X = 43; 
	coord.Y = 16;
	_SMALL_RECT Rect;												// Variabel untuk menyimpan screen buffer size
    Rect.Top = Rect.Left = 0;
    Rect.Right = 42;
	Rect.Bottom = 15;
	SetConsoleWindowInfo(out, TRUE, &Rect);							// Merubah ukuran window size
	SetConsoleScreenBufferSize(out, coord);							// Merubah ukuran screen buffer
	system("title Simulasi Mesin ATM");								// Ubah title CMD
	fontsize(35, 35);												// Ubah ukuran font pada CMD
    system("color 1F");												// Merubah warna background CMD menjadi biru & warna teks menjadi putih
    SetWindowLong(wh, GWL_STYLE,									// Disable resize dan maximize pada window CMD 
				  GetWindowLong(wh, GWL_STYLE) 
				  & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void fontsize(int a, int b){  
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}
