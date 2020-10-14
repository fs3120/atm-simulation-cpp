#include <iostream>
#include <windows.h>

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

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
HWND wh = GetConsoleWindow();

void fontsize(int,int);
void showHeader();
void masukkanKartu();
void mainMenu();

int main(){
	// Pengaturan CMD ============================================
	fontsize(45, 45);												// Ubah ukuran font pada CMD
	system("color 17");												// Set warna background CMD menjadi biru & warna teks menjadi putih
    MoveWindow(wh, 250, 0, 1024, 768, TRUE);						// Set resolusi CMD
    // ===========================================================

    // Main menu =================================================
    masukkanKartu();
}

void fontsize(int a, int b){  
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
	lpConsoleCurrentFontEx->dwFontSize.X = a;  
	lpConsoleCurrentFontEx->dwFontSize.Y = b;  
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
}

void showHeader(){
    std::cout << "\tProgram Simulasi Mesin ATM v1.0\n";
}

void masukkanKartu(){
	showHeader();
  std::cout << "\n\n\n";
	std::cout << "\t Harap Masukkan Kartu ATM Anda\n\n";
	std::cout << "     Tekan [Enter] untuk memasukkan kartu\n";
	std::cin.get();
	std::cout << "           Kartu berhasil dimasukkan\n";
}

void mainMenu(){
	showHeader();
	std::cout << "\n\n\n";
}
