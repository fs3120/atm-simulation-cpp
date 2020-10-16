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
HANDLE in	= GetStdHandle(STD_INPUT_HANDLE);
HWND wh 	= GetConsoleWindow();

void fontsize(int,int);
void showHeader();
void masukkanKartu();
void masukkanPin(string&);
void mainMenu(char&);

int main(){
	// Data nasabah ==============================================
	char pilihan = 0;												// Variabel sementara untuk pilihan pada main menu
	string pin	= "";												// Variabel sementara untuk pin
	string pinT	= "123456";											// PIN untuk akses ATM
	int saldo	= 10000000;											// Jumlah saldo
	// ===========================================================
	
	// Pengaturan CMD ============================================
	_COORD coord;													// Variabel untuk menyimpan window size
	coord.X = 47; 
	coord.Y = 16;
	_SMALL_RECT Rect;												// Variabel untuk menyimpan screen buffer size
    Rect.Top = Rect.Left = 0;
    Rect.Right = 46;
	Rect.Bottom = 15;
	SetConsoleWindowInfo(out, TRUE, &Rect);							// Merubah ukuran window size
	SetConsoleScreenBufferSize(out, coord);							// Merubah ukuran screen buffer size
	system("title Simulasi Mesin ATM v1.0");						// Ubah title CMD
	fontsize(35, 35);												// Ubah ukuran font pada CMD
    system("color 17");												// Merubah warna background CMD menjadi biru & warna teks menjadi putih
    SetWindowLong(wh, GWL_STYLE,									// Disable resize dan maximize pada window CMD 
				  GetWindowLong(wh, GWL_STYLE) 
				  & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    // ===========================================================

    // Kartu dan PIN =============================================
    masukkanKartu();												// Tampilan masukkan kartu
    while(pin != pinT){												// Ketika pin tidak sama dengan pinT
    	pin = "";													// maka akan terus menampilkan tampilan masukkan pin
    	masukkanPin(pin);
    	if(pin != pinT){
    		std::cout << "\n\n\n\t  Pin yang anda masukkan salah\n";
    		sleep(4);
		}else{
			system("cls");
			showHeader();
			std::cout << "\n\n\n\n\n\n\t\t  "
					  << "Harap Tunggu\n\n\n\n\n\n\n\n";
    		sleep(3);
		}
	}
    // ===========================================================
    
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
		case '0':{
			system("cls");
			break;
		}
	}
    // ===========================================================
}

void showHeader(){
    std::cout << "\tProgram Simulasi Mesin ATM v1.0\n";
}

void masukkanKartu(){
	char ch;
	system("cls");
	showHeader();
    cout << "\n\n\n";
	cout << "\t Harap Masukkan Kartu ATM Anda\n\n";
	cout << "     Tekan [Enter] untuk memasukkan kartu\n";
	ch = _getch();
	while(ch != 13){
		ch = _getch();
	}
	cout << "\n\n\n\t   Kartu berhasil dimasukkan\n";
	sleep(3);
}

void masukkanPin(string &pin){
	char ch;
	system("cls");
	showHeader();
    cout << "\n\n\n";
	cout << "\t  Harap Masukkan PIN ATM Anda\n";
	cout << "\t\t   (6 Digit)\n\n\n";
	cout << "\t\t     ";
	while(1){
		ch = _getch();
		if(ch == 13 && pin.length() == 6){							// Kondisi untuk keluar loop
			break;													
		}
		if(ch == 8 && pin.length() >= 1){							// Fitur menghapus karakter
			cout << char(8) << " " << char(8);						
			pin = pin.erase(pin.length()-1);						
			continue;												
		}
		if(ch < 48 || ch > 57 || pin.length() >= 6){				// Fitur supaya hanya angka yang dapat diinput dan 
			continue;												// ketika sudah 6 karakter tidak bisa input lagi
		}
		pin.push_back(ch);											
		cout << "*";												
	}
}

void mainMenu(char &pilihan){
	char ch;
	system("cls");
	showHeader();
	cout << "\n\n\n\n";
	cout << "Pilih transaksi:\n";
	cout << "[1]Cek Saldo\n"
		 << "[2]Transfer\n"
		 << "[3]Pembayaran\n"
		 << "[0]Cancel\n"
		 << "\n\n\n\n\nInput: ";
	while(1){
		ch = _getch();
		if(ch == 13 && pilihan != 0){								// Kondisi keluar loop
			break;
		}
		if(ch == 8 && pilihan != 0){								// Fitur untuk menghapus pilihan
			cout << char(8) << " " << char(8);				
			pilihan = 0;
			continue;					
		}
		if(ch < 48 || ch > 51 || pilihan != 0){						// Fitur supaya input pilihan hanya boleh angka tertentu
			continue;												// dan maksimalnya hanya 1 karakter
		}
		pilihan = ch;
		cout << ch;
	}
}

void fontsize(int a, int b){  
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}
