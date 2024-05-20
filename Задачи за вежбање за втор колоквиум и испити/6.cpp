#include <iostream>
#include <cstring>

using namespace std;

class ExistingGame{
private:
    char msg[200];
public:
    ExistingGame(char *msg = " "){
        strcpy(this->msg, msg);
    }
    void message(){
        cout<<msg<<endl;
    }
};

class Game {
protected:
    char ime[100];
    double cena;
public:
    double getCena() const {
        return cena;
    }

protected:
    bool kupena;
public:
    Game(char *ime = "", double cena = 0, bool kupena = false) {
        strcpy(this->ime, ime);
        this->cena = cena;
        this->kupena = kupena;
    }

    friend ostream &operator<<(ostream &out, const Game &p) {
        out << "Game: " << p.ime << ", " << "regular price: " << "$" << p.cena;
        if (p.kupena) {
            out << ", bought on sale" << endl;
        }
        return out;
    }

    friend istream &operator>>(istream &in, Game &p) {
        in.get();
        in.getline(p.ime, 100);
        in >> p.cena >> p.kupena;
        return in;
    }
    bool getKupena(){
        return kupena;
    }

};

class SubscriptionGame : public Game {
protected:
    double nadomestok;
    int mesec;
    int godina;
public:
    SubscriptionGame(char *ime = " ", double cena = 0, bool kupena = false, double nadomestok = 0, int mesec = 0,
                     int godina = 0)
            : Game(ime, cena, kupena) {
        this->nadomestok = nadomestok;
        this->mesec = mesec;
        this->godina = godina;
    }

    friend ostream &operator<<(ostream &out, const SubscriptionGame &p) {
        out << "Game: " << p.ime << ", regular price: $" << p.cena << ", ";
        if (p.kupena) {
            out << "bought on sale, ";
        }
        out << "monthly fee: $" << p.nadomestok << ", purchased: " << p.mesec << "-" << p.godina << endl;
        return out;
    }

    friend istream &operator>>(istream &in, SubscriptionGame &p) {
        in.get();
        in.getline(p.ime, 100);
        in >> p.cena >> p.kupena >> p.nadomestok >> p.mesec >> p.godina;
        return in;
    }

};

class User{
private:
    char ime[100];
    Game * kolekcija;
    int size;
public:
    User(char *ime = " "){
        strcpy(this->ime, ime);
        this->kolekcija= new Game[0];
        int size=0;
    }
    User(const User &p){
        strcpy(this->ime, p.ime);
        this->kolekcija= new Game[0];
        int size=0;
    }
    User &operator=(const User &p){
        if(this != &p){
            delete [] kolekcija;
            strcpy(this->ime, p.ime);
            this->kolekcija= new Game[0];
            int size=0;
        }
        return *this;
    }
    User &operator+=(const Game &p){
        int counter=0;
        for ( int i = 0 ; i < size ;i++) {
            if (kolekcija[i].getKupena()) {
                counter++;
            }
        }
        if ( counter > 0) {
            throw ExistingGame("The game is already in the collection");
        }
        else {
            Game *tmp = new Game[size + 1]; // 4 5 6 7 8
            // 4 5 6 7 8 _
            for (int i = 0; i < size; i++) {
                tmp[i] = kolekcija[i];
            }
            tmp[size++] = p;
            delete kolekcija;
            kolekcija = tmp;
            return *this;
        }
    }
    double total_spend(){
        double sum = 0;
        for(int i=0;i<size;i++){
            sum += kolekcija[i].getCena();
        }
        return sum;
    }
    friend ostream &operator<<(ostream &o, const User &p){
        o<<"User: "<<p.ime<<endl;
        return o;
    }
    ~User(){
        delete[]kolekcija;
    }
};

int main() {
    int test_case_num;

    cin>>test_case_num;

    // for Game
    char game_name[100];
    float game_price;
    bool game_on_sale;

    // for SubscritionGame
    float sub_game_monthly_fee;
    int sub_game_month, sub_game_year;

    // for User
    char username[100];
    int num_user_games;

    if (test_case_num == 1){
        cout<<"Testing class Game and operator<< for Game"<<std::endl;
        cin.get();
        cin.getline(game_name,100);
        //cin.get();
        cin>>game_price>>game_on_sale;

        Game g(game_name, game_price, game_on_sale);

        cout<<g;
    }
    else if (test_case_num == 2){
        cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
        cin.get();
        cin.getline(game_name, 100);

        cin>>game_price>>game_on_sale;

        cin>>sub_game_monthly_fee;
        cin>>sub_game_month>>sub_game_year;

        SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        cout<<sg;
    }
    else if (test_case_num == 3){
        cout<<"Testing operator>> for Game"<<std::endl;
        Game g;

        cin>>g;

        cout<<g;
    }
    else if (test_case_num == 4){
        cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
        SubscriptionGame sg;

        cin>>sg;

        cout<<sg;
    }
    else if (test_case_num == 5){
        cout<<"Testing class User and operator+= for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        try {

            for (int i=0; i<num_user_games; ++i){

                cin >> game_type;

                Game *g;
                // 1 - Game, 2 - SubscriptionGame
                if (game_type == 1){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;
                    g = new Game(game_name, game_price, game_on_sale);
                }
                else if (game_type == 2){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;

                    cin>>sub_game_monthly_fee;
                    cin>>sub_game_month>>sub_game_year;
                    g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
                }

                //cout<<(*g);


                u+=(*g);
            }
        }catch(ExistingGame &ex){
            ex.message();
        }

        cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

    }
    else if (test_case_num == 6){
        cout<<"Testing exception ExistingGame for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        for (int i=0; i<num_user_games; ++i){

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            }
            else if (game_type == 2){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;

                cin>>sub_game_monthly_fee;
                cin>>sub_game_month>>sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
            }

            //cout<<(*g);

            try {
                u+=(*g);
            }
            catch(ExistingGame &ex){
                ex.message();
            }
        }

        cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
    }
    else if (test_case_num == 7){
        cout<<"Testing total_spent method() for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        for (int i=0; i<num_user_games; ++i){

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            }
            else if (game_type == 2){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;

                cin>>sub_game_monthly_fee;
                cin>>sub_game_month>>sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
            }

            //cout<<(*g);


            u+=(*g);
        }

        cout<<u;

        cout<<"Total money spent: $"<<u.total_spent()<<endl;
    }
}

