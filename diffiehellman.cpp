#include<iostream>
#include<cmath>
#include<string>
using namespace std;
class diffie
{
public:
int p;
int primitive;
int i;
int value;
int count=0;
int a;
int b; 
int x;
int y;
int z=0;
int xx;
int yy;
long long f=1;
long long s=1;
long long r=1;
long long w=1;
int prime()
{
   cout<<"Please Enter a Prime Number"<<endl;
    cin>>p;
    if(p==1)
    {
        cout<<"1 is not a prime number"<<endl;
    }
    else
    {
    for(i=2;i<p;i++)
	{
		if(p%i==0)
		{
			count=1;
		}
	}
	if(count==0)
	{
		cout<<"This is a prime number"<<endl;
	}
	else
	{
		cout<<"This is not a prime number"<<endl;
	}
}}
int primitiveroot()
{
    if(p==2){
        primitive=1;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==3){
        primitive=2;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==5){
        primitive=2;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==7){
        primitive=3;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==11){
        primitive=2;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==13){
        primitive=2;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==17){
        primitive=3;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==19){
        primitive=2;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==23){
        primitive=5;
        cout<<"primitive is....: "<<primitive<<endl;
        getprivatekey();
    }
    else if(p==29){
        primitive=2;
        cout<<"primitive is....:"<<primitive<<endl;
        getprivatekey();
    }
    else if(p==31){
        primitive=3;
        cout<<"primitive is....:"<<primitive<<endl;
        getprivatekey();
    }
    else if(p==37){
        primitive=2;
        cout<<"primitive is....:"<<primitive<<endl;
        getprivatekey();
    }
    else if(p==41){
        primitive=6;
        cout<<"primitive is....:"<<primitive<<endl;
        getprivatekey();
    }
    else if(p==43){
        primitive=3;
        cout<<"primitive is....:"<<primitive<<endl;
        getprivatekey();
    }
    else if(p==47){
        primitive=5;
        cout<<"primitive is....:"<<primitive<<endl;
        getprivatekey();
    }
    else
    {
        cout<<"Primitive does not exist";
    }
}
int getprivatekey()
{
    cout<<"Enter Private key for Alice"<<endl;
    cin>>a;
    cout<<"Enter Private key for Bob"<<endl;
    cin>>b;
}
int alicekey()
{
  x=cal(primitive,a);
  x=x%p;

 cout<<"Private key for alice is.....: "<<x<<endl;

}
int bobkey()
{   
 y=cal2(primitive,b);
 y=y%p;
 cout<<"Private key for bob is.....: "<<y<<endl;
}
int cal(int l,int k)
{
    while (k != 0) {
        r *= l;
        --k;
    
    }
}
int cal2(int l,int k)
{
    while (k != 0) {
        s *= l;
        --k;
    
    }
}
int cal3(int l,int k)
{
    while (k != 0) {
        w *= l;
        --k;
    
    }
}
int cal4(int l,int k)
{
    while (k != 0) {
        f *= l;
        --k;
    
    }
}
int exchange()
{
    cout<<"Exchange is done....!"<<endl;
    z=x;
    x=y;
    y=z;
    cout<<"After Exchange private key for alice is....: "<<x<<endl;
    cout<<"After Exchange private key for bob is....: "<<y<<endl;
}
int key()
{
    xx=cal3(x,a);
    xx=xx%p;
    cout<<"Alice Keyis....:"<<xx<<endl;
    yy=cal4(y,b);
    yy=yy%p;
    cout<<"Bob Key is....: "<<yy<<endl;
}
string Encryption(string PlainText)
{
    value=xx;
    string CipherText = "", plainString = "";

    for(int i = 0; i < PlainText.size(); i++){
        if((PlainText[i] >= 'a' && PlainText[i] <= 'z') || (PlainText[i] >= 'A' && PlainText[i] <= 'Z'))
            plainString += PlainText[i];
    }

    for(int i = 0; i < plainString.size(); i++){
        if(plainString[i] >= 'A' && plainString[i] <= 'Z'){
            CipherText += (((plainString[i] - 'A') + value) % 26 ) + 'A';
        }
        else if(plainString[i] >= 'a' && plainString[i] <= 'z'){
            CipherText += (((plainString[i] - 'a') + value) % 26 ) + 'a';
        }
    }

    return CipherText;
}
string Decryption(string CipherText)
{
    value=yy;
    string PlainText = "", cipherString = "";

    for(int i = 0; i < CipherText.size(); i++){
        if((CipherText[i] >= 'a' && CipherText[i] <= 'z') || (CipherText[i] >= 'A' && CipherText[i] <= 'Z'))
            cipherString += CipherText[i];
    }

    int number, nowNUm, ans = 0, div = 0;
    for(int i = 0; i < cipherString.size(); i++){
        if(cipherString[i] >= 'A' && cipherString[i] <= 'Z'){
            number = (cipherString[i] - value - 'A' + 1);
            nowNUm = number;

            if(nowNUm > 0) PlainText += (nowNUm - 1)+ 'A';
            else{
                    div = abs(number) / 26 + 1;
                    ans = ((div * 26) + nowNUm) % 26;
                    if(ans == 0) PlainText += 'Z';
                    else PlainText += (ans - 1) + 'A';
            }
        }
        else if(cipherString[i] >= 'a' && cipherString[i] <= 'z'){
            number = (cipherString[i] - value - 'a' + 1);
            nowNUm = number;

            if(nowNUm > 0) PlainText += (nowNUm - 1)+ 'a';
            else{
                div = abs(number) / 26 + 1;
                ans = ((div * 26) + nowNUm) % 26;
                if(ans == 0) PlainText += 'z';
                else PlainText += (ans - 1) + 'a';
            }
        }
    }

    return PlainText;
}
};
int main()
{
    diffie obj1;
    obj1.prime();
    obj1.primitiveroot();
    obj1.alicekey();
    obj1.bobkey();
    obj1.exchange();
    obj1.key();
     string PlainText;
     string CipherText; 
     int input;
     char choose;
    cout<<"Select 1 for Encryption"<<endl;
    cout<<"Select 2 for Decryption"<<endl;
    cin>>input;
    cout<<"You selected....: "<<input<<endl;
    switch(input)
    {
        case 1:
                cout<<"Feed me some Plaintext"<<endl;
                cout << "Enter Plain Text.... : ";
                cin >> PlainText;
                cout << "Cipher Text : ";
                cout << obj1.Encryption(PlainText) << endl;
                break;
        case 2:
                cout<<"Feed me some Ciphertext"<<endl;
                cout<<"Enter Cipher Text....: ";
                cin>>CipherText;
                cout << "Plain Text : ";
                cout << obj1.Decryption(CipherText) << endl;
                break;
        default:
                cout<<"Choice other than 1 or 2 is not allowed"<<endl;
                cout<<"Do you want to continue or exit....:"<<endl;
                cout<<"Press Y for Continue or N for exit....: ";
                cin>>choose;
                if(choose=='Y'|choose=='y')
                {
                    cout<<"Select 1 for Encryption"<<endl;
    cout<<"Select 2 for Decryption"<<endl;
    cin>>input;
    cout<<"You selected....: "<<input<<endl;
    switch(input)
    {
        case 1:
                cout<<"Feed me some Plaintext"<<endl;
                cout << "Enter Plain Text.... : ";
                cin >> PlainText;
                cout << "Cipher Text : ";
                cout << obj1.Encryption(PlainText) << endl;
                break;
        case 2:
                cout<<"Feed me some Ciphertext"<<endl;
                cout<<"Enter Cipher Text....: ";
                cin>>CipherText;
                cout << "Plain Text : ";
                cout << obj1.Decryption(CipherText) << endl;
                break;
        default:
                cout<<"Choice other than 1 or 2 is not allowed";
                break;
                }}
        else
        {
            break;
        }        

                     
    }
    
    
}