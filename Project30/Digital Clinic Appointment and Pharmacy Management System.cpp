#include <iostream>
#include <string>
using namespace std;

/*
This structure stores patient information.
Each patient is stored as a node in a linked list.
*/

struct Patient {
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

/*
This class manages patient records using linked list.
*/

class PatientList {
private:
    Patient* start = nullptr;
    Patient* location = nullptr;
    int nextID = 1;  // auto generated patient ID

public:

    void addPatient() {
        string name, disease;
        int age;
        Patient* newNode = new Patient;

        cout << "Enter the name of Patient Admitted: ";
        cin >> name;
        cout << "Enter the disease of Patient Admitted: ";
        cin >> disease;
        cout << "Enter the age of Patient Admitted: ";
        cin >> age;

        newNode->name = name;
        newNode->disease = disease;
        newNode->age = age;
        newNode->id = nextID++;
        newNode->next = nullptr;

        if (start == nullptr) {
            start = location = newNode;
        }
        else {
            location->next = newNode;
            location = newNode;
        }

        cout << "Patient added successfully with ID: " << newNode->id << endl;
    }

    // Displays all patients
    void displayPatient() {
        Patient* display = start;
        if (display == nullptr) {
            cout << "No Patient Record Found!!" << endl;
            return;
        }
        int i = 0;
        while (display != nullptr) {
            cout << "Patient " << i + 1 << " details:" << endl;
            cout << "Patient ID: " << display->id << endl;
            cout << "Patient Name: " << display->name << endl;
            cout << "Patient disease: " << display->disease << endl;
            cout << "Patient age: " << display->age << endl;
            i++;
            display = display->next;
        }
    }

    // Searches patient by ID
    bool searchPatient(int id) {
        Patient* search = start;
        if (search == nullptr) {
            cout << "Patient list is empty." << endl;
            return false;
        }
        while (search != nullptr) {
            if (search->id == id) {
                cout << "Patient Record Found with id: " << id << endl;
                cout << "Patient Name: " << search->name << endl;
                cout << "Patient Disease: " << search->disease << endl;
                cout << "Patient Age: " << search->age << endl;
                return true;
            }
            search = search->next;
        }
        cout << "Patient Record Not Found with ID: " << id << endl;
        return false;
    }

    // Checks if patient exists
    bool exists(int id) {
        Patient* temp = start;
        while (temp != nullptr) {
            if (temp->id == id) return true;
            temp = temp->next;
        }
        return false;
    }

    // Modifies patient record
    void modifyPatient(int id) {
        Patient* modify = start;
        if (modify == nullptr) {
            cout << "No Patient Found to be modified, Patient List empty." << endl;
            return;
        }

        while (modify != nullptr && modify->id != id) {
            modify = modify->next;
        }
        if (modify == nullptr) {
            cout << "Patient Record Not Found to modify for id: " << id << endl;
            return;
        }

        cout << "Patient Record Found with id: " << id << endl;
        cout << "Name was: " << modify->name << "  Disease was: " << modify->disease << "  Age was: " << modify->age << endl;

        string name, disease;
        int age;
        cout << "Enter the new Name: ";
        cin >> name;
        cout << "Enter the new Age: ";
        cin >> age;
        cout << "Enter the disease: ";
        cin >> disease;

        modify->name = name;
        modify->age = age;
        modify->disease = disease;

        cout << "Modify Successfully." << endl;
        
    }

    // Deletes a patient record
    void deletePatient(int id) {
        if (start == nullptr) {
            cout << "Patient List Empty." << endl;
            return;
        }
        Patient* loc = start;
        Patient* prev = nullptr;

   
        if (loc->id == id) {
            Patient* temp = loc;
            start = start->next;
            if (start == nullptr) location = nullptr; 
            delete temp;
            cout << "Delete Successfully." << endl;
            displayPatient();
            return;
        }

  
        prev = loc;
        loc = loc->next;
        while (loc != nullptr && loc->id != id) {
            prev = loc;
            loc = loc->next;
        }
        if (loc == nullptr) {
            cout << "No Patient Found id " << id << " to be deleted." << endl;
            return;
        }
        prev->next = loc->next;
        if (prev->next == nullptr) location = prev; 
        delete loc;
        cout << "Delete Successfully." << endl;
        displayPatient();
    }

    // Counts total patients
    int countPatients() {
        Patient* temp = start;
        int countPatient = 0;
        while (temp != nullptr) {
            countPatient++;
            temp = temp->next;
        }
        return countPatient;
    }
};

/*
Appointment structure stores appointment details.
*/
struct Appointment {
    int patientID;
    string date;
    string time;
    string reason;
    Appointment* next;
};

/*
This class manages appointment queue using linked list.
*/

class AppointmentQueue {
private:
    Appointment* front;
    Appointment* rear;

public:
    AppointmentQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Inserts appointment in queue
    void enQueue(int patientId) {
        string date, time, reason;
        Appointment* newNode = new Appointment;

        cout << "Enter date (e.g. 2025-12-20): ";
        cin >> date;
        cout << "Enter time (e.g. 10:30): ";
        cin >> time;
        cout << "Enter the reason for Appointment: ";
        cin >> reason;

        newNode->date = date;
        newNode->time = time;
        newNode->patientID = patientId;
        newNode->reason = reason;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Appointment enqueued for patient ID " << patientId << endl;
    }

    // Removes appointment from queue
    void deQueue() {
        if (isEmpty()) {
            cout << "Queue Empty." << endl;
            return;
        }
        else {
            Appointment* temp = front;
            cout << "Serving Patient ID: " << front->patientID << endl;
            front = front->next;
            cout << "Patient Appointment Deleted Successfully." << endl;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
        }
    }

    
    void bookAppointment(int PatientID) {
        enQueue(PatientID);
        cout << "Patient Appointment Booked Successfully for ID " << PatientID << endl;
    }

    // Serves next appointment
    void serveAppointment() {
        if (isEmpty()) {
            cout << "No Appointment to Serve." << endl;
            return;
        }
        deQueue();
    }
    // Displays appointment queue
    void viewQueue() { 
        if (isEmpty()) {
            cout << "No pending appointments." << endl;
            return;
        }
        Appointment* temp = front;
        cout << "Pending Appointment Details:" << endl;
        while (temp != nullptr) {
            cout << "Patient ID: " << temp->patientID << endl;
            cout << "Appointment Date: " << temp->date << endl;
            cout << "Appointment time: " << temp->time << endl;
            cout << "Appointment Reason: " << temp->reason << endl;
            cout << "---------------------------" << endl;
            temp = temp->next;
        }
    }
    // Cancels appointment
    void cancelAppointment(int patientid) {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return;
        }

        if (front->patientID == patientid) {
            deQueue();
            return;
        }

        Appointment* current = front->next;
        Appointment* previous = front;

        while (current != nullptr && current->patientID != patientid) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Appointment not found." << endl;
            return;
        }

        previous->next = current->next;
        if (current == rear) rear = previous;
        delete current;
        cout << "Appointment Cancelled." << endl;
        viewQueue();
    }
    // Counts appointments
    int queueCount() { 
        if (isEmpty()) {
            return 0;
        }
        Appointment* count = front;
        int countAppointment = 0;
        while (count != nullptr) {
            countAppointment++;
            count = count->next;
        }
        return countAppointment;
    }
};


/*
Medicine structure stores medicine details.
*/

struct Medicine {
    int id;
    string name;
    int quantity;
    float price;
};

/*
Pharmacy class manages medicine inventory using array.
*/


class Pharmacy {
private:
    int totalMedicines = 0;
    int countid = 1;
    Medicine medicines[100];

public:
    Pharmacy() {
        totalMedicines = 0;
        countid = 1;
    }

    bool isFull() {
        return totalMedicines >= 100;
    }

    // Adds medicine
    void addMedicine() {
        if (isFull()) {
            cout << "Cannot add medicine. Inventory is full!" << endl;
            return;
        }
        cout << "Enter the Medicine Name: ";
        cin >> medicines[totalMedicines].name;
        cout << "Enter the Medicine price: ";
        cin >> medicines[totalMedicines].price;
        cout << "Enter the Quantities of Medicine: ";
        cin >> medicines[totalMedicines].quantity;
        medicines[totalMedicines].id = countid;
        int medid = medicines[totalMedicines].id;
        totalMedicines++;
        countid++;
        cout << "Medicine Added Successfully with id: " << medid << endl;
    }

    // Finds index of medicine
    int findIndexById(int id) {
        for (int i = 0; i < totalMedicines; i++) {
            if (medicines[i].id == id) return i;
        }
        return -1;
    }

  
    bool searchMedicineById(int id) {
        return findIndexById(id) != -1;
    }

  
    int getStock(int id) {
        int idx = findIndexById(id);
        if (idx == -1) return -1;
        return medicines[idx].quantity;
    }

    // Updates medicine stock
    void updateStock(int id, int quantity_change) {
        int idx = findIndexById(id);
        if (idx == -1) {
            cout << "Medicine not found." << endl;
            return;
        }
        int newQty = medicines[idx].quantity + quantity_change;
        if (newQty < 0) {
            cout << "Operation would make stock negative. Current stock: " << medicines[idx].quantity << endl;
            return;
        }
        medicines[idx].quantity = newQty;
        cout << "Medicine Stock Updated Successfully. New quantity: " << medicines[idx].quantity << endl;
    }

    // Search medicines By Name
    int searchMedicineByName(string name) {
        for (int i = 0; i < totalMedicines; i++) {
            if (medicines[i].name == name) {
                cout << "Medicine Found with name: " << name << endl;
                return i;
            }
        }
        return -1;
    }


    void deleteMedicine(int id) {
        int idx = findIndexById(id);
        if (idx == -1) {
            cout << "Medicine not found." << endl;
            return;
        }
        for (int i = idx; i < totalMedicines - 1; i++) {
            medicines[i] = medicines[i + 1];
        }
        totalMedicines--;
        cout << "Medicine Deleted Successfully." << endl;
    }

    // Displays medicines
    void displayMedicines() {
        if (totalMedicines == 0) {
            cout << "No Medicine in Inventory." << endl;
            return;
        }
        else {
            for (int i = 0; i < totalMedicines; i++) {
                cout << "Medicine Details:" << endl;
                cout << "Medicine ID: " << medicines[i].id << endl;
                cout << "Medicine Name: " << medicines[i].name << endl;
                cout << "Medicine Quantities Available: " << medicines[i].quantity << endl;
                cout << "Medicine Price: " << medicines[i].price << endl;
                cout << "---------------------------" << endl;
            }
        }
    }
    // Sort medicines By Name By ASCII Value compare
    void sortMedicineByName() {
        for (int i = 0; i < totalMedicines - 1; i++) {
            for (int j = 0; j < totalMedicines - i - 1; j++) {
                if (medicines[j].name > medicines[j + 1].name) {
                    swap(medicines[j], medicines[j + 1]);
                }
            }
        }
        cout << "Medicines sorted by name." << endl;
    }

    // Displays low stock medicines
    void displayLowStock(int threshold = 5) {
        bool found = false;
        for (int i = 0; i < totalMedicines; i++) {
            if (medicines[i].quantity <= threshold) {
                if (!found) {
                    cout << "Low stock medicines (<= " << threshold << "):" << endl;
                    found = true;
                }
                cout << "ID: " << medicines[i].id << ", Name: " << medicines[i].name
                    << ", Qty: " << medicines[i].quantity << endl;
            }
        }
        if (!found) cout << "No medicines are low in stock." << endl;
    }
};

/*
Prescription structure stores prescription data.
*/

struct Prescription {
    int patientID;
    int medicineID;
    int quantity;
};

/*
Stack class manages prescriptions.
*/

class PrescriptionStack {
private:
    Prescription stackArr[100];
    int top = -1;

public:
    bool isFull() {
        return top == 99;
    }

    bool isEmpty() {
        return top == -1;
    }

    // Adds prescription
    void addPrescription(int patientID, int medicineID, int qty, Pharmacy& pharmacy) {
        if (isFull()) {
            cout << "Prescription stack full, cannot add (Overflow)." << endl;
            return;
        }
     
        int stock = pharmacy.getStock(medicineID);
        if (stock == -1) {
            cout << "Medicine ID Not Found." << endl;
            return;
        }
        if (stock < qty) {
            cout << "Not enough medicine stock. Available: " << stock << endl;
            return;
        }

        top++;
        stackArr[top].patientID = patientID;
        stackArr[top].medicineID = medicineID;
        stackArr[top].quantity = qty;

   
        pharmacy.updateStock(medicineID, -qty);

        cout << "Prescription Added Successfully." << endl;
    }

    // Undo prescription
    void undoPrescription(Pharmacy& pharmacy) {
        if (isEmpty()) {
            cout << "No prescriptions to undo." << endl;
            return;
        }

        pharmacy.updateStock(stackArr[top].medicineID, stackArr[top].quantity);

        cout << "Prescription for patient ID " << stackArr[top].patientID
            << " undone. Medicine stock restored." << endl;
        top--;
    }

    void displayRecent() {
        if (isEmpty()) {
            cout << "No prescriptions to display." << endl;
            return;
        }

        cout << "Recent Prescriptions (most recent first):" << endl;
        int limit = top - 4; 
        if (limit < 0) limit = 0;

        for (int i = top; i >= limit; i--) {
            cout << "Patient ID: " << stackArr[i].patientID << endl;
            cout << "Medicine ID: " << stackArr[i].medicineID << endl;
            cout << "Quantity: " << stackArr[i].quantity << endl;
            cout << "---------------------------" << endl;
        }
    }

    // Counts prescriptions
    int count() {
        return top + 1;
    }
};

/*
Main system class controls all menus.
*/
class ClinicSystem {
private:
    PatientList pl;
    AppointmentQueue aq;
    Pharmacy p;
    PrescriptionStack ps;

public:
    // Main menu
    void menu() {
        int choice;

        do {
            cout << "\n===== MAIN MENU =====\n";
            cout << "1. Patient Management" << endl;
            cout << "2. Appointment Booking" << endl;
            cout << "3. Pharmacy Inventory" << endl;
            cout << "4. Prescription System" << endl;
            cout << "5. Generate Daily Report" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                patientMenu();
                break;
            case 2:
                appointmentMenu();
                break;
            case 3:
                pharmacyMenu();
                break;
            case 4:
                prescriptionMenu();
                break;
            case 5:
                generateDailyReport();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }

        } while (choice != 6);
    }

    void patientMenu() {
        int choice, id;

        do {
            cout << "\n--- Patient Menu ---\n";
            cout << "1. Add Patient " << endl;
            cout << "2. Search Patient " << endl;
            cout << "3. Modify Patient " << endl;
            cout << "4. Delete Patient " << endl;
            cout << "5. Display All Patients " << endl;
            cout << "6. Back " << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                pl.addPatient();
                break;

            case 2:
                cout << "Enter Patient ID: ";
                cin >> id;
                pl.searchPatient(id);
                break;

            case 3:
                cout << "Enter Patient ID to modify: ";
                cin >> id;
                pl.modifyPatient(id);
                break;

            case 4:
                cout << "Enter Patient ID to delete: ";
                cin >> id;
                pl.deletePatient(id);
                break;

            case 5:
                pl.displayPatient();
                break;

            case 6:
                return;

            default:
                cout << "Invalid choice! " << endl;
            }

        } while (choice != 6);
    }

    void appointmentMenu() {
        int choice, id;

        do {
            cout << "\n--- Appointment Menu ---\n";
            cout << "1. Book Appointment " << endl;
            cout << "2. Cancel Appointment " << endl;
            cout << "3. Serve Appointment " << endl;
            cout << "4. View Appointment Queue " << endl;
            cout << "5. Back " << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;

                if (!pl.exists(id)) {
                    cout << "Patient not found. Cannot book.\n";
                }
                else {
                    aq.bookAppointment(id);
                }
                break;

            case 2:
                cout << "Enter Patient ID to cancel: ";
                cin >> id;
                aq.cancelAppointment(id);
                break;

            case 3:
                aq.serveAppointment();
                break;

            case 4:
                aq.viewQueue();
                break;

            case 5:
                return;

            default:
                cout << "Invalid choice! " << endl;
            }

        } while (choice != 5);
    }

    void pharmacyMenu() {
        int choice, id;

        do {
            cout << "\n--- Pharmacy Menu ---\n";
            cout << "1. Add Medicine " << endl;
            cout << "2. Update Stock " << endl;
            cout << "3. Search Medicine " << endl;
            cout << "4. Delete Medicine " << endl;
            cout << "5. Display All Medicines " << endl;
            cout << "6. Sort Medicines By Name " << endl;
            cout << "7. Low stock report" << endl;
            cout << "8. Back " << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                p.addMedicine();
                break;

            case 2: {
                cout << "Enter Medicine ID: ";
                cin >> id;
                int qty;
                cout << "Enter quantity change (use negative to reduce): ";
                cin >> qty;
                p.updateStock(id, qty);
                break;
            }

            case 3:
                cout << "Enter Medicine ID: ";
                cin >> id;
                if (p.searchMedicineById(id)) {
                    int idx = p.findIndexById(id);
                    p.displayMedicines(); 
                }
                else {
                    cout << "Medicine not found." << endl;
                }
                break;

            case 4:
                cout << "Enter Medicine ID to delete: ";
                cin >> id;
                p.deleteMedicine(id);
                break;

            case 5:
                p.displayMedicines();
                break;

            case 6:
                p.sortMedicineByName();
                break;

            case 7:
                p.displayLowStock();
                break;

            case 8:
                return;

            default:
                cout << "Invalid choice! " << endl;
            }

        } while (choice != 8);
    }

    void prescriptionMenu() {
        int choice, pid, mid, qty;

        do {
            cout << "\n--- Prescription Menu ---\n";
            cout << "1. Add Prescription " << endl;
            cout << "2. Undo Prescription " << endl;
            cout << "3. View Recent Prescriptions " << endl;
            cout << "4. Back " << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                cout << "Enter Patient ID: " << endl;
                cin >> pid;

                if (!pl.exists(pid)) {
                    cout << "Patient does not exist!" << endl;
                    break;
                }

                cout << "Enter Medicine ID: " << endl;
                cin >> mid;

                cout << "Enter Quantity: " << endl;
                cin >> qty;

                ps.addPrescription(pid, mid, qty, p);
                break;

            case 2:
                ps.undoPrescription(p);
                break;

            case 3:
                ps.displayRecent();
                break;

            case 4:
                return;

            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 4);
    }

    void generateDailyReport() {

        cout << "\n=== DAILY REPORT ===\n";

        cout << "Total Patients: " << pl.countPatients() << endl;

        cout << "Appointments Pending: " << aq.queueCount() << endl;

        cout << "Total Prescriptions: " << ps.count() << endl;

        cout << "\nMedicines Low in Stock:\n";
        p.displayLowStock();
    }
};


int main() {
    ClinicSystem cs;
    cs.menu();
    return 0;
}
