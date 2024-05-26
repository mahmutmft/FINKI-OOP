#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Image {
protected:
    char *imeSlika;
    char *imeSopstvenik;
    int shirina;
    int visina;
public:
    Image(char *imeSlika = "untitled", char *imeSopstvenik = "unknown", int shirina = 800, int visina = 800) {
        this->imeSlika = new char[strlen(imeSlika) + 1];
        this->imeSopstvenik = new char [strlen(imeSopstvenik) + 1];
        strcpy(this->imeSlika, imeSlika);
        strcpy(this->imeSopstvenik, imeSopstvenik);
        this->shirina = shirina;
        this->visina = visina;
    }

    Image(const Image &p) {
        this->imeSlika = new char[strlen(p.imeSlika) + 1];
        this->imeSopstvenik = new char [strlen(p.imeSopstvenik) + 1];
        strcpy(this->imeSlika, imeSlika);
        strcpy(this->imeSopstvenik, imeSopstvenik);
        this->shirina = p.shirina;
        this->visina = p.visina;
    }

    Image operator=(const Image &p) {
        if (this != &p) {
            delete[]imeSlika;
            delete[]imeSopstvenik;
            this->imeSlika = new char[strlen(p.imeSlika) + 1];
            this->imeSopstvenik = new char [strlen(p.imeSopstvenik) + 1];
            strcpy(this->imeSlika, imeSlika);
            strcpy(this->imeSopstvenik, imeSopstvenik);
            this->shirina = p.shirina;
            this->visina = p.visina;
        }
        return *this;
    }

    virtual double fileSize() {
        return visina * shirina * 3;
    }

    friend ostream &operator<<(ostream &out, Image &p) {
        out << p.imeSlika << " " << p.imeSopstvenik << " " << p.fileSize();
        return out;
    }

    bool operator<(Image &p) {
        return fileSize() < p.fileSize();
    }
};

class TransparentImage : public Image {
protected:
    bool isTransparent;
public:
    TransparentImage(char *imeSlika = "untitled", char *imeSopstvenik = "unknown", int shirina = 800, int visina = 800,
                     bool isTransparent = false) : Image(imeSlika, imeSopstvenik, shirina, visina) {
        this->isTransparent = isTransparent;
    }

    double fileSize() override {
        if (isTransparent) {
            return shirina * visina * 4;
        } else {
            return  shirina * visina + 3.5;
        }
    }
};

class Folder {
private:
    char imeFolder[255];
    char imeKorisnik[50];
    Image *niza[100];
    int n;
public:
    Folder(char *imeFolder = " ", char *imeKrosnik = " ", int n = 0) {
        strcpy(this->imeFolder, imeFolder);
        strcpy(this->imeKorisnik, imeKrosnik);
        this->n = n;
    }

    Folder(const Folder &p) {
        strcpy(this->imeFolder, p.imeFolder);
        strcpy(this->imeKorisnik, p.imeKorisnik);
        this->n = p.n;
        for (int i = 0; i < p.n; i++) {
            niza[i] = p.niza[i];
        }
    }

    Folder operator=(const Folder &p) {
        if (this != &p) {
            strcpy(this->imeFolder, p.imeFolder);
            strcpy(this->imeKorisnik, p.imeKorisnik);
            this->n = p.n;
            for (int i = 0; i < p.n; i++) {
                niza[i] = p.niza[i];
            }
        }
        return *this;
    }

    double folderSize() {
        double size = 0;
        for (int i = 0; i < n; i++) {
            size += niza[i]->fileSize();
        }
        return size;
    }

    Image *getMaxFile() {
        Image *max = niza[0];
        for (int i = 0; i < n; i++) {
            if (niza[i] > max) {
                max = niza[i];
            }
        }
        return max;
    }

    Folder &operator+=(Image &p) {
        niza[n++] = &p;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Folder &p);

    Image *operator[](int index) {
        if (index < 0 || index >= n) {
            return nullptr;
        }
        return niza[index];
    }
};

ostream &operator<<(ostream &out, const Folder &p) {
    out << p.imeFolder <<" "<<p.imeKorisnik<<endl;
    out << "--" << endl;
    for (int i = 0; i < p.n; i++) {
        out << *p.niza[i] << endl;
    }
    cout<<"--"<<endl;
    cout << "Folder size: " << p.n << endl;
    return out;
}

Folder max_folder_size(Folder *niza, int n) {
    Folder maxFolder = niza[0];
    for (int i = 1; i < n; ++i) {
        if (niza[i].folderSize() > maxFolder.folderSize()) {
            maxFolder = niza[i];
        }
    }
    return maxFolder;
}


int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc == 1) {
        // Testing constructor(s) & operator << for class File

        cin >> name;
        cin >> user_name;
        cin >> w;
        cin >> h;


        Image f1;

        cout << f1;

        Image f2(name);
        cout << f2;

        Image f3(name, user_name);
        cout << f3;

        Image f4(name, user_name, w, h);
        cout << f4;
    } else if (tc == 2) {
        // Testing constructor(s) & operator << for class TextFile
        cin >> name;
        cin >> user_name;
        cin >> w >> h;
        cin >> tl;

        TransparentImage tf1;
        cout << tf1;

        TransparentImage tf4(name, user_name, w, h, tl);
        cout << tf4;
    } else if (tc == 3) {
        // Testing constructor(s) & operator << for class Folder
        cin >> name;
        cin >> user_name;

        Folder f3(name, user_name);
        cout << f3;
    } else if (tc == 4) {
        // Adding files to folder
        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image *f;
        TransparentImage *tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            } else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout << dir;
    } else if (tc == 5) {
        // Testing getMaxFile for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image *f;
        TransparentImage *tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            } else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout << *(dir.getMaxFile());
    } else if (tc == 6) {
        // Testing operator [] for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image *f;
        TransparentImage *tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            } else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }

        cin >> sub; // Reading index of specific file
        cout << *dir[sub];
    } else if (tc == 7) {
        // Testing function max_folder_size
        int folders_num;

        Folder dir_list[10];

        Folder dir;
        cin >> folders_num;

        for (int i = 0; i < folders_num; ++i) {
            cin >> name;
            cin >> user_name;
            dir = Folder(name, user_name);


            Image *f;
            TransparentImage *tf;

            int sub, fileType;

            while (1) {
                cin >> sub; // Should we add subfiles to this folder
                if (!sub) break;

                cin >> fileType;
                if (fileType == 1) { // Reading File
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    f = new Image(name, user_name, w, h);
                    dir += *f;
                } else if (fileType == 2) {
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    cin >> tl;
                    tf = new TransparentImage(name, user_name, w, h, tl);
                    dir += *tf;
                }
            }
            dir_list[i] = dir;
        }

        cout << max_folder_size(dir_list, folders_num);
    }
    return 0;
};
