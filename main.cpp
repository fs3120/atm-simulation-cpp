#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <unistd.h>

//<< "                                           "
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

// Prototype Fungsi ==============================================
void masukkanKartu();
void masukkanPin(std::string);
void mainMenu(char&);
void keluarKartu();
void configureCMD();
void fontsize(int,int);

// Prototype Fungsi Transaksi ====================================
void penarikanJL(int&);
void mainMenuL(char&);
void informasiSaldo(int&);
void transfer(long long, std::string, int&);

int main(){
	// Variabel ==================================================
	char pilihan = '1';												// Variabel sementara untuk pilihan pada main menu
	char pilihanTL = '1';											// Variabel sementara untuk pilihan pada main menu transaksi lainnya

	// Data nasabah ==============================================
	std::string pinT = "123456";									// PIN untuk akses ATM
	int saldoT	= 100000000;										// Jumlah saldo

	// Data nasabah tujuan =======================================
	long long rek = 8691049693;										// No. Rekening Tujuan
	std::string nama = "Muhammad Rahmadhan Fauzan";					// Nama Pemilik Rekening Tujuan
	
	// Pengaturan CMD ============================================
	configureCMD();													// Mengatur tampilan CMD

    // Kartu dan PIN =============================================
    masukkanKartu();												// Tampilan masukkan kartu
    masukkanPin(pinT);												// Tampilan masukkan pin
    
    // Main Menu =================================================
	while(pilihan != 32){											// keluar simulasi apabila menekan 32 (ascii dari spasi)
		mainMenu(pilihan);											// Tampilan main menu sekaligus menetapkan pilihan transaksi
		if(pilihan == '1'){
			// Penarikan 100k
		}else if(pilihan == '2'){
			// Penarikan 300k
		}else if(pilihan == '3'){
			// Bayar / Beli
		}else if(pilihan == '4'){
			// Mandiri Prabayar
		}else if(pilihan == '5'){
			// Penarikan 500k
		}else if(pilihan == '6'){
			// Penarikan 1jt
		}else if(pilihan == '7'){
			penarikanJL(saldoT);
		}else if(pilihan == '8'){
			mainMenuL(pilihanTL);
			if(pilihanTL == '1'){
				informasiSaldo(saldoT);
			}else if(pilihanTL == '2'){
				// Informasi Pinjaman
			}else if(pilihanTL == '3'){
				// Cetak Resi Mandiri SMS
			}else if(pilihanTL == '4'){
				// Ubah PIN
			}else if(pilihanTL == '5'){
				transfer(rek, nama, saldoT);
			}else if(pilihanTL == '6'){
				// Pendaftaran E-Banking
			}else if(pilihanTL == '7'){
				// Cetak Mutasi
			}else if(pilihanTL == '8'){
				keluarKartu();
				pilihan = 32;										// Ini bukan supaya ke else if dibawahnya
			}														// Tapi supaya keluar while loop
		}else if(pilihan == 32){
			keluarKartu();
		}
	}
	return 0;
}

void masukkanKartu(){
	char ch;
	system("cls");
	std::cout << "\n\t     SELAMAT DATANG DI\n\n"
		   	  << "\tPROGRAM SIMULASI MESIN ATM\n\n\n\n\n\n\n"
			  << "\tSILAHKAN MASUKKAN KARTU ANDA\n"
	 		  << "\t      UNTUK PELAYANAN\n\n"
	 		  << "   TEKAN [ENTER] UNTUK MEMASUKKAN KARTU\n\n";
	ch = _getch();
	while(ch != 13){												// Jika bukan enter yang ditekan maka akan terus meminta input
		ch = _getch();
	}
	Beep(600,200);
}

void masukkanPin(std::string pinT){
	std::string pin;
	char ch;
	while(pin != pinT){												// Ketika pin tidak sama dengan pinT maka akan looping
		pin = "";													// Menampilkan tampilan masukkan pin
		system("cls");
		std::cout << "\n\t\tHATI-HATI!!\n"
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
			else if(ch == 8 && pin.length() >= 1){					// Menghapus karakter
				std::cout << char(8) << " " << char(8);						
				pin = pin.erase(pin.length()-1);
				continue;											
			}
			else if(ch < 48 || ch > 57 || pin.length() >= 6){		// Hanya angka yang dapat diinput dan 
				continue;											// ketika sudah 6 karakter tidak bisa input lagi
			}
			pin.push_back(ch);
			std::cout << "X";
			Beep(600,200);
		}
		if(pin != pinT){											// Jika pin yang diinput tidak sama dengan pin sebenarnya
    		std::cout << "\n\n"
				 << "       PIN YANG ANDA MASUKKAN SALAH\n\n\n\n";
    		sleep(3);
		}
	}
}

void mainMenu(char &pilihan){
	char ch;
	system("cls");
	std::cout << "\n"
	 		  << "                MENU UTAMA\n"
	 		  << "        ==========================\n"
	 		  << "        TEKAN <SPASI> UNTUK KELUAR\n\n"
	 		  << " [1]<-----100.000        500.000------>[5] \n\n"
	 		  << " [2]<-----300.000        1000.000----->[6] \n\n"
	 		  << " [3]<------BAYAR/        PENARIKAN---->[7] \n"
	 		  << "             BELI        JUMLAH LAIN       \n\n"
	 		  << " [4]<-----MANDIRI        TRANSAKSI---->[8] \n"
	 		  << "         PRABAYAR        LAINNYA           \n\n";
	while(1){
		ch = _getch();
		if(ch == 32){												// Apabila menginput spasi maka akan pass value by reference ke &pilihan
			pilihan = ch;
			Beep(600,200);
			break;
		}else if(ch < 49 || ch > 56){								// Jika menginput selain angka (1-8) maka loop kembali (tidak terjadi apa2)
			continue;
		}else{														// Apabila menginput angka maka akan pass value by reference ke &pilihan
			pilihan = ch;
			Beep(600,200);
			break;
		}
	}
}

void keluarKartu(){
	char ch;
	system("cls");
    std::cout << "\n\n\n\n"
	 		  << "\t HARAP AMBIL KARTU ATM ANDA\n\n\n"
	 		  << "    TEKAN [ENTER] UNTUK MENGAMBIL KARTU"
			  << "\n\n\n\n\n\n\n\n";
	ch = _getch();													// Jika bukan enter yang ditekan maka akan terus meminta input
	while(ch != 13){
		ch = _getch();
	}
	Beep(600,200);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n"
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
    system("color 1E");												// Merubah warna background CMD menjadi biru & warna teks menjadi light yellow
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

// Fungsi Transaksi ==============================================
// ===============================================================
void penarikanJL(int &saldoT){
	std::string saldoS;
	int saldoI = 0, sTemp = 0;
	int l10k = 0, l20k = 0, l50k = 0, l100k = 0;
	bool sukses = false, yakin = false;									// Sukses apabila proses greedy sudah selesai
	char ch;															// Yakin apabila user ingin mengambil uangnya (konfirmasi)
	system("cls");
	std::cout << "\n"
	 		  << "\t      MASUKKAN JUMLAH\n"
	 		  << "\t      PENARIKAN DALAM\n"
	 		  << "\t    KELIPATAN RP.10000\n"
	 		  << "\t MAKSIMUM 1 KALI PENARIKAN\n"
	 		  << "\t\tRP.2500.000\n\n"
	 		  << "        TEKAN <SPASI> KE MENU UTAMA\n\n\n"
	 		  << "\t\tRP.";
	while(1){															// Looping selamanya 
		ch = _getch();													// (keluar jika user memilih batal atau jika penarikan sukses)
		if(ch == 32){													// Ketika spasi ditekan maka akan kembali ke menu awal
			Beep(600,200);
			break;
		}else if(ch == 13 && saldoS.length() >= 5){						// Ketika enter ditekan dan permintaan penarikan sudah 5 digit
			Beep(600,200);												// Maka akan menjalankan berikut
			saldoI = std::stoi(saldoS);
			if(saldoI > 2500000){										// Pengecekan apakah jumlah penarikan melebihi batas
				std::cout << "\n\n"
						  << "      JUMLAH PENARIKAN MELEBIHI BATAS\n\n\n";
				sleep(3);
			}else if(saldoT < saldoI){									// Pengecekan apakah saldo cukup
				std::cout << "\n\n"
						  << "          SALDO ANDA TIDAK CUKUP\n"
				 		  << "         UNTUK MELAKUKAN PENARIKAN\n\n";
				sleep(3);
			}else if(saldoI % 10000 != 0){								// Pengecekan apakah permintaan penarikan kelipatan 10000
				std::cout << "\n\n"
						  << "       INPUT JUMLAH PENARIKAN ERROR\n\n\n";
				sleep(3);
			}else{														// Jika sudah memenuhi persyaratan
				sTemp = saldoI;											// Maka akan menjalankan algoritma greedy
				while(!sukses){											// Untuk mencari jumlah lembaran yang akan keluar
					if(sTemp >= 100000){								// Penjelasan :
						sTemp -= 100000;									// Akan terus mengurangi sTemp (penarikan sementara) dari lembaran terbesar
						l100k++;											// Ketika telah dikurangi maka jumlah lembaran bersangkutan akan bertambah
						continue;											// Dan akan mengulangi loop (continue;)
					}else if(sTemp >= 50000){								// Apabila sTemp sudah mencapai 0 
						sTemp -= 50000;										// (ini sudah pasti karena ada pengecekan % 10000 sebelumnya)
						l50k++;												// Maka sukses = true (jika sukses true maka loop greedy selesai) 
						continue;											// Dan ada konfirmasi pengambilan uang
					}else if(sTemp >= 20000){
						sTemp -= 20000;
						l20k++;
						continue;
					}else if(sTemp >= 10000){
						sTemp -= 10000;
						l10k++;
						continue;
					}else{
						sukses = true;
						system("cls");
						std::cout << "\n\n\n\n"
								  << "     APAKAH ANDA YAKIN INGIN MENGAMBIL\n"
								  << "         UANG SEBESAR RP." << saldoI << "?\n\n"
							 	  << "        TEKAN <ENTER> UNTUK LANJUT\n"
							 	  << "         TEKAN <SPASI> UNTUK BATAL\n\n\n";
						ch = _getch();
						if(ch == 13){										// Jika menekan enter maka user yakin ingin mengambil uang
							yakin = true;
						}else if(ch == 32){									// Jika menekan spasi maka user batal mengambil uang
							yakin = false;
						}else{
							ch = _getch();
						}
						Beep(600,200);
						if(yakin){											// Apabila user yakin maka akan memunculkan pesan proses
							std::cout << "           HARAP TUNGGU SEBENTAR\n\n\n\n";
							sleep(3);
						}
						continue;
					}
				}
				if(yakin){													// Jika user yakin maka akan ada output penarikan uang
					system("cls");
					saldoT -= saldoI;										// Jumlah saldo berkurang
					std::cout << "\n\n"
							  << "      ANDA MENDAPATKAN UANG SEJUMLAH\n"
					  		  << "                RP." << saldoI << std::endl
							  << "          DENGAN JUMLAH LEMBARAN\n"
							  << "              SEBAGAI BERIKUT\n\n\n";
					if(l100k > 0){
						std::cout << "\tRP.100000 SEBANYAK " << l100k << " LEMBAR\n";
					}
					if(l50k > 0){
						std::cout << "\tRP.50000 SEBANYAK " << l50k << " LEMBAR\n";
					}
					if(l20k > 0){
						std::cout << "\tRP.20000 SEBANYAK " << l20k << " LEMBAR\n";
					}
					if(l10k > 0){
						std::cout << "\tRP.10000 SEBANYAK " << l10k << " LEMBAR\n";
					}
					l100k = l50k = l20k = l10k = sTemp = saldoI = 0;
					std::cout << "\n\n"
						<< "    TEKAN <ENTER> UNTUK KEMBALI KE MENU\n\n";
					ch = _getch();
					while(ch != 13){										// Jika tidak menekan enter maka tidak bisa keluar
						ch = _getch();
					}
					Beep(600,200);
				}
			}
			break;
		}else if(ch == 8 && saldoS.length() >= 1){							// Jika backspace ditekan dan input jumlah penarikan >= 1
			std::cout << char(8) << " " << char(8);							// Menghapus 1 digit input pada layar
			saldoS = saldoS.erase(saldoS.length()-1);						// Menghapus 1 digit jumlah penarikan
			continue;
		}else if(ch < 48 || ch > 57){										// Jika menginput selain angka
			continue;														// Looping kembali
		}
		saldoS.push_back(ch);												// Jika lolos (input berupa angka) 
		std::cout << ch;													// Maka angka dimasukkan ke digit jumlah penarikan
		Beep(600,200);														// Lalu mengoutput input pada layar
	}
}

void mainMenuL(char &pilihan){
	char ch;
	system("cls");
	std::cout << "\n"
			  << "            MENU UTAMA LAINNYA\n"
			  << "        ===========================\n"
			  << "        TEKAN <SPASI> KE MENU UTAMA\n\n"
			  << " [1]<---INFORMASI        TRANSFER----->[5] \n"
			  << "           SALDO                           \n\n"
			  << " [2]<---INFORMASI        PENDAFTARAN-->[6] \n"
			  << "         PINJAMAN        E-BANKING         \n\n"
			  << " [3]<--CETAK RESI        CETAK-------->[7] \n"
			  << "      MANDIRI SMS        MUTASI            \n\n"
			  << " [4]<----UBAH PIN        KELUAR------->[8] \n";
	while(1){														// Looping hanya bisa keluar apabila user
		ch = _getch();												// Memilih pilihan atau menekan spasi
		if(ch == 32){												// Jika menekan spasi maka keluar (pass by reference ke &pilihan)
			pilihan = ch;
			Beep(600,200);
			break;
		}else if(ch < 49 || ch > 56){								// Jika menginput selain angka maka loop kembali (tidak terjadi apa2)
			continue;
		}else{														// Jika menginput angka maka keluar (pass by reference ke &pilihan)
			pilihan = ch;
			Beep(600,200);
			break;
		}
	}
}

void informasiSaldo(int &saldo){
	char ch;
	system("cls");
	std::cout << "\n\n\n"
			  << "            SALDO REKENING ANDA\n\n"
			  << "                RP." << saldo << "\n\n"
			  << "        TRANSAKSI ANDA TELAH SELESAI\n"
			  << "        APAKAH ANDA INGIN MELAKUKAN\n"
			  << "             TRANSAKSI LAINNYA?\n\n"
			  << "        TEKAN <ENTER> KE MENU UTAMA\n\n\n\n\n";
	ch = _getch();
	while(ch != 13){											 	// Jika input selain enter maka akan terus meminta input
		ch = _getch();
	}
	Beep(600,200);
}

void transfer(long long rek, std::string nama, int &saldo){
	char ch;
	std::string rekTempS, saldoTS;
	long long rekTempLL = 0, saldoTLL = 0;
	system("cls");
	std::cout << "\n"
		
			  << "        WASPADA TERHADAP PENIPUAN!!\n"
			  << "               MASUKKAN NOMOR\n"
			  << "          REKENING TUJUAN TRANSFER\n\n"
			  << "        TEKAN <SPASI> KE MENU UTAMA\n\n"
			  << "                ";
	while(1){
		ch = _getch();
		if(ch == 32){
			Beep(600,200);
			break;
		}else if(ch == 13 && rekTempS.length() == 10){
			Beep(600,200);
			rekTempLL = std::stoll(rekTempS);
			if(rekTempLL != rek){
				std::cout << "\n\n\n"
						  << "          REKENING TIDAK TERDAFTAR\n\n\n\n\n";
				sleep(3);
				break;
			}else{
				system("cls");
				std::cout << "\n"
						  << "              MASUKKAN JUMLAH\n"
						  << "             (MINIMUM RP.10000)\n\n"
						  << "       TEKAN <ENTER> UNTUK KONFIRMASI\n"
						  << "          TEKAN <SPASI> UNTUK BATAL\n\n"
						  << "                RP.";
				while(1){
					ch = _getch();
					if(ch == 32){
						Beep(600,200);
						break;
					}else if(ch == 13 && saldoTS.length() >= 5){
						Beep(600,200);
						saldoTLL = stoi(saldoTS);
						if(saldoTLL < 10000){
							std::cout << "\n\n\n"
									  << "    JUMLAH TRANSFER KURANG DARI RP.10000\n\n\n\n\n";
							sleep(3);
							break;
						}else if(saldoTLL > saldo){
							std::cout << "\n\n\n"
									  << "           SALDO ANDA TIDAK CUKUP\n\n\n\n\n";
							sleep(3);
							break;
						}else{
							system("cls");
							//	      << "                                           "
							std::cout << "\n"
									  << "            KONFIRMASI TRANSFER\n\n"
									  << "  REK.TUJUAN : " << rek << "\n"
									  << "  NAMA       : " << nama << "\n"
									  << "  JUMLAH     : RP." << saldoTLL << "\n"
									  << "  DARI REK.  : 1231231231\n\n\n"
									  << "       TEKAN <ENTER> UNTUK KONFIRMASI\n"
									  << "         TEKAN <SPASI> KE MENU UTAMA\n\n\n\n\n";
							while(1){
								ch = _getch();
								if(ch == 32){
									Beep(600,200);
									break;
								}else if(ch == 13){
									Beep(600,200);
									system("cls");
									//	      << "                                           "
									std::cout << "\n\n\n"
											  << "          TRANSFER SEDANG DIPROSES\n\n\n\n";
									sleep(2);
									saldo -= saldoTLL;
									std::cout << "              TRANSFER SUKSES\n\n\n\n\n\n\n\n";
									sleep(2);
									break;
								}else{
									continue;
								}
							}
							break;
						}
					}else if(ch == 8 && saldoTS.length() >= 1){
						std::cout << char(8) << " " << char(8);
						saldoTS = saldoTS.erase(saldoTS.length()-1);
						continue;
					}else if(ch < 48 || ch > 57){
						continue;
					}else{
						Beep(600,200);
						saldoTS.push_back(ch);
						std::cout << ch;
					}
				}
				break;
			}
		}else if(ch == 8 && rekTempS.length() >= 1){
			std::cout << char(8) << " " << char(8);					// Menghapus 1 digit input pada layar
			rekTempS = rekTempS.erase(rekTempS.length()-1);
			continue;
		}else if(ch < 48 || ch > 57 || rekTempS.length() >= 10){
			continue;
		}else{
			Beep(600,200);
			rekTempS.push_back(ch);
			std::cout << ch;
		}
	}
}
