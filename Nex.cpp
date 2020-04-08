#include <iostream>
#include <windows.h>
#include <fstream>
#include <direct.h>
#include <string>

using namespace std;

/*prototipo de funciones*/
/**
*@param string Root folder direction
**/
void index(string final_dir);
/**
*@param string Root folder direction
**/
void struct_file(string final_dir);
/**
*@param string Root folder direction
**/
void npm(string final_dir);
/**
*@param string Root folder direction
**/
void npm_express(string final_dir);

int main(){
    string directions;
    string final_dir;

    cout<<"This will create a Node.js + Express basic proyect in C:/..:"<<endl;
    cout<<"Enter the name of the containing Folder: ";
    cin>>directions;
    final_dir = "C:/"+directions+"/";
    system("cls");


    struct_file(final_dir);
    npm(final_dir);
    npm_express(final_dir);
    index(final_dir);

    return 0;
}
/*END MAIN*/

void npm_express(string final_dir){
    string npm_command = "cd "+final_dir+" && npm install express";
    cout<<"Please wait for express to install.."<<endl;
    system(npm_command.c_str());
    system("pause");
    system("cls");
}

void npm(string final_dir){
    string npm_command = "cd "+final_dir+" && npm init -y";

    cout<<"Please wait until node init..."<<endl;
    system(npm_command.c_str());
    cout<<"Node init completed in "<<final_dir<<endl;
    system("pause");
    system("cls");
 }

void struct_file(string final_dir){
    string pb = "public/";
    string db = "database/";
    string rt = "routes/";
    string vw = "views/";

    char symbol1 = 195;
    char symbol2 = 192;


    /*direcciones finales*/
    string pb_dir = final_dir + pb;
    string rt_dir = final_dir + rt;
    string vw_dir = final_dir + vw;
    string db_dir = final_dir + db;

    if(mkdir(final_dir.c_str()) == 0){
        cout<<"Root folder created: "<<final_dir<<endl;

        if(mkdir(pb_dir.c_str()) == 0){
            cout<<symbol1<<"Sub-folder created: "<<pb_dir<<endl;
        }
        if(mkdir(rt_dir.c_str()) == 0){
            cout<<symbol1<<"Sub-folder created: "<<rt_dir<<endl;
        }
        if(mkdir(vw_dir.c_str()) == 0){
            cout<<symbol1<<"Sub-folder created: "<<vw_dir<<endl;
        }
        if(mkdir(db_dir.c_str()) == 0){
            cout<<symbol2<<"Sub-folder created: "<<db_dir<<endl;
            cout<<endl;
            cout<<"-All folder tree created!-"<<endl;
        }

    }else{
        cout<<"ERROR CREATING THE FOLDERS"<<endl;
    }



}



/*Function to create index.js file*/
void index(string final_dir){
    string index = final_dir + "index.js";

    fstream output(index.c_str(), fstream::out);
    output<< "const express = require(\"express\");\n";
    output<< "const app = express();\n";
    output<< "const path = require(\"path\");\n";
    output<< "\n";
    output<< "\n";
    output<< "This set the views folder for views container";
    output<< "app.set(\"views\", path.join(__dirname, \"views\"));";
    output<< "//This sets the public folder for assets container";
    output<< "app.use(express.static(path.join(__dirname, \"public\")));";
    output<< "//Insert code here";
    output<< "\n";
    output<< "\n";
    output<< "app.listen(3000);\n";
    output<< "console.log(\"Server is running in http://localhost:3000\");";
    output.close();
    cout<<"\nIndex.js File created\n";
    cout<<"\nYour Proyect is ready to start!\n";
}
