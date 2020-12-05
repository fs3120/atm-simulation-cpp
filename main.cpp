#include "fungsi.cpp"

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

int main(){
	// Variabel ==================================================
	char pilihan = '1';												// Variabel sementara untuk pilihan pada main menu
	char pilihanTL = '1';											// Variabel sementara untuk pilihan pada main menu transaksi lainnya
	char pilihanBB = '1';											// Variabel sementara untuk pilihan bayar / beli

	// Data nasabah ==============================================
	std::string pinT = "123456";									// PIN untuk akses ATM
	int saldoT	= 100000000;										// Jumlah saldo
	long long rekN = 1231231231;									// No. Rekening Nasabah (10 Digit)

	// Data nasabah tujuan =======================================
	long long rekT = 8691049693;									// No. Rekening Tujuan (10 Digit)
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
			penarikanFixed(saldoT, 100000);
		}else if(pilihan == '2'){
			penarikanFixed(saldoT, 300000);
		}else if(pilihan == '3'){
			bayarBeli(pilihanBB);
			if(pilihanBB == '1'){
				voucherHP(saldoT, rekN);
			}else if(pilihanBB == '2'){
				// Telepon / HP
			}else if(pilihanBB == '3'){
				// TV Kabel / Internet
			}else if(pilihanBB == '4'){
				// Pendidikan
			}else if(pilihanBB == '5'){
				// Listrik / Gas
			}else if(pilihanBB == '6'){
				// Kartu Kredit
			}else if(pilihanBB == '7'){
				// PAM
			}else if(pilihanBB == '8'){
				// Lainnya
			}
		}else if(pilihan == '4'){
			// Mandiri Prabayar
		}else if(pilihan == '5'){
			penarikanFixed(saldoT, 50000);
		}else if(pilihan == '6'){
			penarikanFixed(saldoT, 1000000);
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
				transfer(rekT, rekN, nama, saldoT);
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
