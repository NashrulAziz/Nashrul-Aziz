#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Vehicle {
    string licensePlate;
    string type;  // "Car" atau "Motorcycle"
    int entryTime; // Dalam jam
};

class ParkingSystem {
private:
    vector<Vehicle> vehicles;
    const int baseFee = 2000;        // Biaya dasar parkir
    const int carRate = 5000;        // Tarif per jam untuk mobil
    const int motorcycleRate = 2000; // Tarif per jam untuk motor
    const int maxCapacity = 50;     // Kapasitas maksimal parkir

public:
    void parkVehicle() {
        if (vehicles.size() >= maxCapacity) {
            cout << "Parkir penuh! Tidak bisa menerima kendaraan baru.\n";
            return;
        }

        Vehicle v;
        cout << "Masukkan nomor plat kendaraan: ";
        cin >> v.licensePlate;
        cout << "Masukkan jenis kendaraan (Car/Motorcycle): ";
        cin >> v.type;
        cout << "Masukkan waktu masuk (jam, format 24 jam): ";
        cin >> v.entryTime;

        vehicles.push_back(v);
        cout << "Kendaraan berhasil masuk ke parkir.\n";
    }

    void removeVehicle() {
        string plate;
        int exitTime;
        cout << "Masukkan nomor plat kendaraan yang akan keluar: ";
        cin >> plate;
        cout << "Masukkan waktu keluar (jam, format 24 jam): ";
        cin >> exitTime;

        for (size_t i = 0; i < vehicles.size(); ++i) {
            if (vehicles[i].licensePlate == plate) {
                int duration = exitTime - vehicles[i].entryTime;
                if (duration <= 0) {
                    cout << "Waktu keluar tidak valid.\n";
                    return;
                }

                int rate = (vehicles[i].type == "Car") ? carRate : motorcycleRate;
                int fee = baseFee + (duration * rate);

                cout << "Kendaraan dengan plat " << plate << " telah keluar.\n";
                cout << "Durasi parkir: " << duration << " jam.\n";
                cout << "Biaya dasar: Rp " << baseFee << "\n";
                cout << "Biaya per jam: Rp " << (rate * duration) << "\n";
                cout << "Total biaya parkir: Rp " << fee << ".\n";

                vehicles.erase(vehicles.begin() + i);
                return;
            }
        }
        cout << "Kendaraan dengan plat tersebut tidak ditemukan.\n";
    }

    void displayVehicles() {
        if (vehicles.empty()) {
            cout << "Tidak ada kendaraan yang parkir saat ini.\n";
            return;
        }

        cout << "Daftar kendaraan yang sedang parkir:\n";
        cout << "No. | Plat Nomor | Jenis Kendaraan | Waktu Masuk\n";
        cout << "-----------------------------------------------\n";

        for (size_t i = 0; i < vehicles.size(); ++i) {
            cout << i + 1 << "    | " << vehicles[i].licensePlate
                 << "         | " << vehicles[i].type
                 << "            | " << vehicles[i].entryTime << " jam\n";
        }
    }

    void displayMenu() {
        cout << "\n=== Program Sistem Parkir Rumah Sakit ===\n";
        cout << "1. Kendaraan Masuk Parkiran\n";
        cout << "2. Kendaraan Keluar dari parkiran\n";
        cout << "3. Kendaraan Yang Berada Di Parkiran\n";
        cout << "4. Keluar\n";
    }
};

int main() {
    ParkingSystem ps;
    int choice;

    do {
        ps.displayMenu();
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ps.parkVehicle();
            break;
        case 2:
            ps.removeVehicle();
            break;
        case 3:
            ps.displayVehicles();
            break;
        case 4:
            cout << "Terima kasih telah menggunakan sistem parkir.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}
