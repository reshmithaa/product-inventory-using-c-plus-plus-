#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class USER
{
private:
    string name;
    string password;
    string address;
    string DOB;
    long int number;

    bool logedin;
public:
    USER();
    virtual ~USER(){}
    bool login();
    void signup();
    void viewProducts();
    virtual void billing()=0;
    virtual void addCart();
    void viewCart();

    bool getLogedin();
};
void USER::viewCart(){
    cout<<"Cart"<<endl;
    fstream file("temp.txt",ios::in);

    if (!file){
        cout<<"Oops some technical issue happened sorry!!!";
    }
    else{
        int amt=0;
        cout<<"Your Items..."<<endl;
        while (!file.eof())
        {
            string s;
            int countspace=0,pos=0;
            getline(file,s);
            cout<<s<<endl;
            for (pos = 0; pos < s.length() && countspace!=3; pos++){
                if (s[pos]==' ')
                    countspace++;
            }
            string tem=s.substr(pos,s.length()-pos);
            // cout<<tem<<endl;
            amt=stoi(tem);
            cout<<amt;
        }
        cout<<"Your BILL..."<<endl;
        cout<<"Total amount                     : "<<amt<<endl;
    }
}
static USER* user;
fstream file("temp.txt",ios::out);
class Product
{
private:

public:
    Product(/* args */);
    virtual ~Product(){}
    static void showall();
    static void hplaptop();
    static void Dell();
    static void Lenovo();

    static void AppleMob();
    static void OnePlus();

};
void Product::hplaptop(){
    string colour;
    float cost;
    string Pname;
    int quantity;

    int ch;
    fstream file("temp.txt",ios::app);
    cout<<"-----------------HP Laptops------------------"<<endl;
    cout<<"1) Basic Laptop           cost : 25000"<<endl;
    cout<<"2) Student laptop         cost : 35000"<<endl;
    cout<<"3) Multitasking Laptop    cost : 60000"<<endl;
    cout<<"4) Gaming laptop          cost : 80000"<<endl;
    cout<<"5) Go Back"<<endl;
    cout<<"Enter your choice to in add cart : ";
    cin>>ch;

    if (user->getLogedin()){
        cout<<"Enter colour : ";
        cin>>colour;

        cout<<"Enter quantity : ";
        cin>>quantity;

        if (ch==1){
            cout<<"HP Basic Laptop          cost : 25000"<<endl;
            Pname="HP_Basic_Laptop";
            cost=25000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==1){
            cout<<"HP Student Laptop        cost : 35000"<<endl;
            Pname="HP_Student_Laptop";
            cost=35000;      
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
            Product::showall();
        }
        else if (ch==3){
            cout<<"HP Multitasking Laptop   cost : 60000"<<endl;
            Pname="HP_Multitasking_Laptop";
            cost=60000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
            Product::showall();
        }
        else if (ch==4){
            cout<<"HP Gaming Laptop         cost : 80000"<<endl;
            Pname="HP_Gaming_Laptop";
            cost=80000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
            Product::showall();
        }
        else if (ch==5){
            showall();        
        }
        else{
            cout<<"Invalid input !!!"<<endl;
            hplaptop();
        }
    }
    else{
        cout<<"Not yet loged in Please login to continue..."<<endl;
        user->login();
        Product::showall();
    }
    
}
void Product::Dell(){
    string colour;
    float cost;
    string Pname;
    int quantity;

    int ch;
    fstream file("temp.txt",ios::app);
    cout<<"----------------Dell Laptops------------------"<<endl;
    cout<<"1) Basic Laptop           cost : 25000"<<endl;
    cout<<"2) Student laptop         cost : 45000"<<endl;
    cout<<"3) Multitasking Laptop    cost : 63000"<<endl;
    cout<<"4) Gaming laptop          cost : 70000"<<endl;
    cout<<"5) Go Back";
    cout<<"Enter your choice to in add cart : "<<endl;
    cin>>ch;

    if (user->getLogedin()){
        cout<<"Enter colour : ";
        cin>>colour;

        cout<<"Enter quantity : ";
        cin>>quantity;

        if (ch==1){
            cout<<"Dell Basic Laptop          cost : 25000"<<endl;
            Pname="Dell_Basic_Laptop";
            cost=25000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
        }
        else if (ch==1){
            cout<<"Dell Student Laptop        cost : 45000"<<endl;
            Pname="Dell_Student_Laptop";
            cost=45000;          
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
        }
        else if (ch==3){
            cout<<"Dell Multitasking Laptop   cost : 63000"<<endl;
            Pname="Dell_Multitasking_Laptop";
            cost=63000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
        }
        else if (ch==4){
            cout<<"Dell Gaming Laptop         cost : 70000"<<endl;
            Pname="Dell_Gaming_Laptop";
            cost=70000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
        }
        else if (ch==5){
            Product::showall();       
        }
        else{
            cout<<"Invalid input !!!"<<endl;
            Dell();
        }
    }
    else{
        cout<<"Not yet loged in Please login to continue..."<<endl;
        user->login();
        Product::showall();
    }
}
void Product::Lenovo(){
    int ch;
    string colour;
    float cost;
    string Pname;
    int quantity;
    fstream file("temp.txt",ios::app);
    cout<<"---------------Lenovo Laptops----------------"<<endl;
    cout<<"1) Basic Laptop           cost : 25000"<<endl;
    cout<<"2) Student laptop         cost : 45000"<<endl;
    cout<<"3) Multitasking Laptop    cost : 63000"<<endl;
    cout<<"4) Gaming laptop          cost : 70000"<<endl;
    cout<<"5) Go Back"<<endl;
    cout<<"Enter your choice to in add cart : ";
    cin>>ch;

    if (user->getLogedin()){
        cout<<"Enter colour : ";
        cin>>colour;
        cout<<"Enter quantity : ";        
        cin>>quantity;

        if (ch==1){
            cout<<"Lenovo Basic Laptop          cost : 25000"<<endl;
            Pname="Lenovo_Basic_Laptop";
            cost=25000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
            Product::showall();
        }
        else if (ch==1){
            cout<<"Lenovo Student Laptop        cost : 45000"<<endl;
            Pname="Lenovo_Student_Laptop";
            cost=45000;          
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart : "<<endl;
            Product::showall();
        }
        else if (ch==3){
            cout<<"Lenovo Multitasking Laptop   cost : 60000"<<endl;
            Pname="Lenovo_Multitasking_Laptop";
            cost=60000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==4){
            cout<<"Lenovo Gaming Laptop         cost : 70000"<<endl;
            Pname="Lenovo_Gaming_Laptop";
            cost=70000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==5){
            Product::showall(); 
        }
        else{
            cout<<"Invalid input !!!"<<endl;
            Lenovo();
        }
    }
    else{
        cout<<"Not yet loged in Please login to continue..."<<endl;
        user->login();
        Product::showall();
    }
}
void Product::AppleMob(){
    int ch;
    string colour;
    float cost;
    string Pname;
    int quantity;

    fstream file("temp.txt",ios::app);
    cout<<"---------------Apple Mobiles-----------------"<<endl;
    cout<<"1) iphone 13 Pro max      cost : 1,40,000"<<endl;
    cout<<"2) iphone 13 mini         cost : 73,000"<<endl;
    cout<<"3) iphone 12              cost : 53,000"<<endl;
    cout<<"4) iphone 12 Pro max      cost : 1,20,000"<<endl;
    cout<<"5) Go Back"<<endl;
    cout<<"Enter your choice to in add cart";
    cin>>ch;

    if (user->getLogedin()){
        cout<<"Enter colour : ";
        cin>>colour;
        cout<<"Enter quantity : ";        
        cin>>quantity;

        if (ch==1){
            cout<<"iphone 13 Pro max          cost : 25000"<<endl;
            Pname="iphone_13_Pro_max";
            cost=140000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==1){
            cout<<"iphone 13 min        cost : 73000"<<endl;
            Pname="iphone_13_mini";
            cost=73000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==3){
            cout<<"iphone 12 mini   cost : 53000"<<endl;
            Pname="iphone_12_mini";
            cost=53000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==4){
            cout<<"iphone pro max         cost : 120000"<<endl;
            Pname="iphone_12_pro_max";
            cost=120000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==5){
            Product::showall();  
        }
        else{
            cout<<"Invalid input !!!"<<endl;
            AppleMob();
        }
    }
    else{
        cout<<"Not yet loged in Please login to continue..."<<endl;
        user->login();
        Product::showall();
    }
}
void Product::OnePlus(){
    int ch;
    string colour;
    float cost;
    string Pname;
    int quantity;

    fstream file("temp.txt",ios::app);
    cout<<"---------------OnePlus Mobiles-----------------"<<endl;
    cout<<"1) OnePlus Nord2          cost : 30,000"<<endl;
    cout<<"2) Oneplus 9 Pro          cost : 50,000"<<endl;
    cout<<"3) OnePlus 10R            cost : 49,000"<<endl;
    cout<<"4) Go Back"<<endl;
    cout<<"Enter your choice to in add cart";
    cin>>ch;

    if (user->getLogedin()){
        cout<<"Enter colour : ";
        cin>>colour;

        cout<<"Enter quantity : ";
        cin>>quantity;

        if (ch==1){
            cout<<"OnePlus Nord 2          cost : 30000"<<endl;
            Pname="OnePlus_Nord2";
            cost=30000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==1){
            cout<<"OnePlus 9 Pro        cost : 50000"<<endl;
            Pname="OnePlus9_Pro";
            cost=50000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==3){
            cout<<"OnePlus 10R   cost : 49000"<<endl;
            Pname="OnePlus_10R";
            cost=49000;
            file<<Pname<<" "<<colour<<" "<<quantity<<" "<<cost<<endl;
            cout<<"Sucessfully added into your cart"<<endl;
            Product::showall();
        }
        else if (ch==4){
            Product::showall();  
        }
        else{
            cout<<"Invalid input !!!"<<endl;
            AppleMob();
        }
    }
    else{
        cout<<"Not yet loged in Please login to continue..."<<endl;
        user->login();
        Product::showall();
    }
}

void Product::showall(){
    int ch,ch1;
    cout<<"1) Laptop"<<endl;
    cout<<"2) Mobile phones"<<endl;
    cout<<"3) Airdopes"<<endl;
    cout<<"4) Login page"<<endl;
    cout<<"5) View cart"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    
    if (ch==1){
        cout<<"Section : Laptops"<<endl;
        cout<<"1) HP Laptops"<<endl;
        cout<<"2) Dell"<<endl;
        cout<<"3) Lenovo"<<endl;
        cout<<"4) Go Back"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch1;

        if (ch1==1){
            hplaptop();
        }
        else if (ch1==2){
            Dell();
        }
        else if(ch1==3){
            Lenovo();
        }
        else if (ch1==4)
            showall();
        else{
            cout<<"Invalid input !!!";
            showall();
        }
    }
    else if (ch==2){
        cout<<"Section : MOBILES"<<endl;
        cout<<"1) Apple"<<endl;
        cout<<"2) OnePlus"<<endl;
        cout<<"4) Go Back"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch1;
        if (ch1==1){
            AppleMob();
        }
        else if (ch1==2)
            OnePlus();
        else if (ch1==4)
            showall();
        else{
            cout<<"Invalid input"<<endl;
            showall();
        }
    }
    // else if (ch==3){
    //     cout<<"Section : Airdops"<<endl;
    //     cout<<"1) Apple"<<endl;
    //     cout<<"2) JBL"<<endl;
    //     cout<<"3) boAt"<<endl;
    //     cout<<"Enter youe choice : ";
    //     cin>>ch1;
    // }
    else if (ch==4){
        user->login();
    }
    else if (ch==5){
        user->viewCart();
    }
    else{
        cout<<"Invalid input !!!"<<endl;
        showall();
    }
}
Product::Product(/* args */)
{
}
bool USER::login(){
    long int m;
    string pass;

    cout<<"Enter your mobile number : ";
    cin>>m;
    cout<<"Enter Password : ";
    cin>>pass;

    string record;
    string na, p;
    int pos,pos2;

    fstream file("userfile.txt",ios::in);

    if (file){
        while (!file.eof())
        {
            getline(file,record);
            pos = record.find(" ");
            na=record.substr(0,pos);
            pos2=record.find(" ",pos+1);
            p=record.substr(pos+1,pos2-pos-1);
        }
        int num;
        num=stoi(na);
        if (pass==p && m==num){
            cout<<"Sucessfully loged in..."<<endl;
            logedin=1;
            Product::showall();
            return 1;
        }
        else{
            cout<<"Invalid user name or password !!!"<<endl;
            return 0;
        }
    }
    else
        return 0;
}
bool USER::getLogedin(){
    if (logedin==1)
        return 1;
    else
        return 0;
}
void USER::viewProducts(){
    int ch;


}
void USER::billing(){

}
void USER::addCart(){

}

USER::USER(){
    name="";password="";address="",DOB="",number=0;logedin=0;
}

class NormalUser:public USER
{
private:
    
public:
    NormalUser();
    virtual ~NormalUser(){};
    void billing();
    void addCart();
    void viewCart();

};

void NormalUser::billing(){

}
void NormalUser::viewCart(){

}
void NormalUser::addCart(){
    
}
NormalUser::NormalUser(/* args */)
{
}


int main(){

    system("CLS");
    int ch;
    // USER* user;
    while (1)
    {
        cout<<"---------------------------WELCOME----------------------"<<endl;
        cout<<"                      1) Normal User"<<endl;
        cout<<"                      2) VIP User"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;

        if (ch==1){
            user=new NormalUser;
        }
        else if (ch==2){

        }
        int signchoice;
        cout<<"                      1) Login"<<endl;
        cout<<"                      2) Signup"<<endl;
        cout<<"                      3) View Products"<<endl;
        cout<<"Enter your choice : ";
        cin>>signchoice;

        if (signchoice==1){
            user->login();
            Product::showall();
        }
        else if (signchoice==2){

        }
        else if (signchoice==3){
            Product::showall();
        }
        else{
            cout<<"Enter choice correctly"<<endl;
            continue;
        }
    }


    return 0;
}