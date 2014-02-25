//test HugeInt
#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>
typedef long long int lint;
using namespace std;

class HugeInt{
    friend istream &operator>>(istream&,HugeInt&);
    friend ostream &operator<<(ostream&,const HugeInt&);
public:

    HugeInt();
    HugeInt(const HugeInt &);
    HugeInt(lint [],int);
    HugeInt(string);
    HugeInt(int);
    ~HugeInt();


    void sethi(string);
    lint* gethi()const;
    int getsize()const;
    HugeInt operator+(const HugeInt&);
    const HugeInt &operator=(const HugeInt&);
     bool operator==(const HugeInt&)const;
private:
    lint *hi;
    int size;
    static const lint flow=1000000000;
};

istream &operator>>(istream &in,HugeInt &t){
    string temp;
    in >> temp;
    t=HugeInt(temp);
    return in;
}

bool HugeInt::operator==(const HugeInt &t)const{
    if(size!=t.size) return false;

    for(int i=0;i<size;i++){
        if(hi[i]!=t.hi[i]) return false;
    }

    return true;
}

ostream &operator<<(ostream &out,const HugeInt &t){
    int i=t.size-1,a=0;

    while(i!=-1&&t.hi[i]==0) i--;
    if(i==-1) out<<"0";
    else{
        out<<t.hi[i];
        i--;
        for(;i!=-1;i--){
            out <<setfill('0')<< setw(9)<< t.hi[i];

        }
    }
    return out;
}

HugeInt::HugeInt(){size=0;}

HugeInt::HugeInt(const HugeInt &t){
    hi=new lint[t.size];
    size=t.size;
    for(int i=0;i<size;i++)
        hi[i]=t.hi[i];
}

HugeInt::HugeInt(lint t[] , int ts){

    int i;
    for(i=ts-1;i>=0 && !t[i];i--);
        ts=i+1;
    hi=new lint[ts];
    size=ts;

    for(i=0;i<size;i++)
        hi[i]=t[i];

}

HugeInt::HugeInt(int t){

    size=1;
    //for(int i=1;t/pow(10,i)>=1;i++,size++);
    hi=new lint[size];
    hi[0]=t;
        //for(int i=0;i<size;i++,t/=10)
            //hi[i]=t%10;

}

HugeInt::HugeInt(string t){
    this->sethi(t);
}

HugeInt::~HugeInt(){
    if(size)
        delete [] hi;
}

HugeInt HugeInt::operator+(const HugeInt &t){

    int max=(size>t.size)?size:t.size;
    int min=(size<t.size)?size:t.size;
    lint *temp=new lint[max+1];
    lint *x=(size>t.size)?hi:t.hi;
    lint *y=(x==hi)?t.hi:hi;

    temp[max]=0;
    for(int i=0;i<max;i++){
        if(i>=min) temp[i]=x[i];
        else temp[i]=x[i]+y[i];

        if(i!=0 && temp[i-1]>flow-1){
            temp[i-1]%=flow;
            temp[i]+=1;
        }
    }if(temp[max-1]>flow-1){
        temp[max]=1;
        temp[max-1]%=flow;
    }

    HugeInt tmp(temp,max+1);
    delete [] temp;
    return tmp;
}

const HugeInt &HugeInt::operator=(const HugeInt &t){
    if(size)
        delete [] hi;
    int i;
    hi=new lint[t.size];
    size=t.size;
    for(i=size-1;i>=0 && !hi[i];i--);
    size=i+1;
    for(i=0;i<size;++i)
        hi[i]=t.hi[i];


    return *this;
}

lint* HugeInt::gethi()const{
    return hi;
}

int HugeInt::getsize()const{
    return size;
}

void HugeInt::sethi(string t){
    int j=t.size()-1;

    size=(t.size()-1)/9+1;
    hi=new lint[size];
    for(int i=0;i!=size;i++){
        hi[i]=0;
        for(int x=1;x<flow&&j!=-1;x*=10,j--)
            hi[i]+=(t[j]-48)*x;
    }
}

int main(){
    char a;
    HugeInt x;
    HugeInt z(0);
    HugeInt result;
    cin>>result;
    if(result==z)
        return 0;
    while(cin >> x){
        if(x==z)
            break;
        result = result+x;
    }
    cout<< result<<endl;
    return 0;
}
