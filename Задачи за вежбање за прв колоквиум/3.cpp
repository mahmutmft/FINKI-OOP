    #include<iostream>
    #include<cstring>

    using namespace std;

    class StockRecord {
    private:
        char id[12];
        char imeKompanija[50];
        double cenaKupeni;
        double cenaMomentalna;
        int brojAkcii;
    public:
        StockRecord(char *id = " ", char *imeKompanija = " ", double cenaKupeni = 0, int brojAkcii = 0,
                    double cenaMomenatlna = 0) {
            strcpy(this->id, id);
            strcpy(this->imeKompanija, imeKompanija);
            this->cenaKupeni = cenaKupeni;
            this->brojAkcii = brojAkcii;
            this->cenaMomentalna = cenaMomenatlna;
        }
        void setNewPrice(double c){
            cenaMomentalna = c;
        }
        double value(){
            return brojAkcii * cenaMomentalna;
        }
        double profit() const{
            return brojAkcii * (cenaMomentalna - cenaKupeni);
        }
        friend ostream &operator<<(ostream &out, const StockRecord &p){
            out<<p.imeKompanija<<" "<<p.brojAkcii<<" "<<p.cenaKupeni<<" "<<p.cenaMomentalna<<" "<<p.profit()<<endl;
            return out;
        }
    };

    class Client{
    private:
        char imePrezime[60];
        int id;
        StockRecord *niza;
        int n;
    public:
        Client(const char *imePrezime = " ", int id = 0, int n = 0){
            strcpy(this->imePrezime, imePrezime);
            this->id = id;
            niza = new StockRecord[n];
            this->n = n;
        }
        Client(const Client &p){
            strcpy(this->imePrezime, p.imePrezime);
            this->id = p.id;
            niza = new StockRecord[p.n];
            this->n = p.n;
            for(int i=0;i<p.n;i++){
                this->niza[i] = p.niza[i];
            }
        }
        Client &operator=(const Client &p){
            if(this != &p){
                delete[]niza;
                strcpy(this->imePrezime, p.imePrezime);
                this->id = p.id;
                niza = new StockRecord[p.n];
                this->n = p.n;
                for(int i=0;i<p.n;i++){
                    this->niza[i] = p.niza[i];
                }
            }
            return *this;
        }
        Client &operator+=(const StockRecord &p){
            StockRecord *temp = new StockRecord[n+1];
            for(int i=0;i<n;i++){
                temp[i] = niza[i];
            }
            temp[n] = p;
            n++;
            delete[] niza;
            niza=temp;
            return *this;
        }
        double totalValue() const{
            double totalValue = 0;
            for(int i=0;i<n;i++){
                totalValue += niza[i].value();
            }
            return totalValue;
        }
        friend ostream &operator<<(ostream &out, const Client &p){
            out<<p.id<<" "<<p.totalValue()<<endl;
            for(int i=0;i<p.n;i++){
                cout<<p.niza[i];
            }
            return out;
        }
    };

    int main() {

        int test;
        cin >> test;

        if (test == 1) {
            double price;
            cout << "=====TEST NA KLASATA StockRecord=====" << endl;
            StockRecord sr("1", "Microsoft", 60.0, 100);
            cout << "Konstruktor OK" << endl;
            cin >> price;
            sr.setNewPrice(price);
            cout << "SET metoda OK" << endl;
        } else if (test == 2) {
            cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
            char id[12], company[50];
            double price, newPrice;
            int n, shares;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> id;
                cin >> company;
                cin >> price;
                cin >> newPrice;
                cin >> shares;
                StockRecord sr(id, company, price, shares);
                sr.setNewPrice(newPrice);
                cout << sr.value() << endl;
                cout << sr;
            }
        } else if (test == 3) {
            cout << "=====TEST NA KLASATA Client=====" << endl;
            char companyID[12], companyName[50], clientName[50];
            int clientID, n, shares;
            double oldPrice, newPrice;
            bool flag = true;
            cin >> clientName;
            cin >> clientID;
            cin >> n;
            Client c(clientName, clientID);
            cout << "Konstruktor OK" << endl;
            for (int i = 0; i < n; ++i) {
                cin >> companyID;
                cin >> companyName;
                cin >> oldPrice;
                cin >> newPrice;
                cin >> shares;
                StockRecord sr(companyID, companyName, oldPrice, shares);
                sr.setNewPrice(newPrice);
                c += sr;
                if (flag) {
                    cout << "Operator += OK" << endl;
                    flag = false;
                }
            }
            cout << c;
            cout << "Operator << OK" << endl;
        }
        return 0;

    }