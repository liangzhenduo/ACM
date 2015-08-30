#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_L=1000;
class BigInt{
public:
    int len,s[MAX_L];
    BigInt();
    BigInt(const char*);
    BigInt(int);
    bool sign;
    string toStr()const;
    friend istream& operator>>(istream &,BigInt &);
    friend ostream& operator<<(ostream &,BigInt &);
    BigInt operator=(const char*);
    BigInt operator=(int);
    BigInt operator=(const string);
    bool operator>(const BigInt&)const;
    bool operator>=(const BigInt&)const;
    bool operator<(const BigInt&)const;
    bool operator<=(const BigInt&)const;
    bool operator==(const BigInt&)const;
    bool operator!=(const BigInt&)const;
    BigInt operator+(const BigInt&)const;
    BigInt operator++();
    BigInt operator++(int);
    BigInt operator+=(const BigInt&);
    BigInt operator-(const BigInt&)const;
    BigInt operator--();
    BigInt operator--(int);
    BigInt operator-=(const BigInt&);
    BigInt operator*(const BigInt&)const;
    BigInt operator*(const int num)const;
    BigInt operator*=(const BigInt&);
    BigInt operator/(const BigInt&)const;
    BigInt operator/=(const BigInt&);
    BigInt operator%(const BigInt&)const;
    BigInt factorial()const;
    BigInt Sqrt()const;
    BigInt pow(const BigInt&)const;
    void clean();
    ~BigInt();
};

BigInt::BigInt(){
    memset(s,0,sizeof(s));
    len=1;
    sign=1;
}

BigInt::BigInt(const char *num){
    *this=num;
}

BigInt::BigInt(int num){
    *this=num;
}

string BigInt::toStr()const{
    string res="";
    for(int i=0;i<len;i++)
        res=(char)(s[i]+'0')+res;
    if(res=="") res="0";
    if(!sign&&res!="0") res="-"+res;
    return res;
}

istream &operator>>(istream &in,BigInt &num){
    string str;
    in>>str;
    num=str;
    return in;
}

ostream &operator<<(ostream &out,BigInt &num){
    out<<num.toStr();
    return out;
}

BigInt BigInt::operator=(const char *num){
    memset(s,0,sizeof(s));
    char a[MAX_L]="";
    if (num[0]!='-') strcpy(a,num);
    else
        for(int i=1;i<strlen(num);i++)
            a[i-1]=num[i];
    sign=!(num[0]=='-');
    len=strlen(a);
    for(int i=0;i<strlen(a);i++)
        s[i]=a[len-i-1]-48;
    return *this;
}

BigInt BigInt::operator=(int num){
    if(num<0) sign=0,num=-num;
    else sign=1;
    char tmp[MAX_L];
    sprintf(tmp,"%d",num);
    *this=tmp;
    return *this;
}

BigInt BigInt::operator=(const string num){
    const char *tmp;
    tmp=num.c_str();
    *this=tmp;
    return *this;
}

bool BigInt::operator<(const BigInt &num)const{
    if(sign^num.sign) return num.sign;
    if(len!=num.len) return len < num.len;
    for(int i=len-1;i>=0;i--)
        if(s[i]!=num.s[i])
            return sign?(s[i]<num.s[i]):(!(s[i]<num.s[i]));
    return !sign;
}

bool BigInt::operator>(const BigInt&num)const{
    return num<*this;
}

bool BigInt::operator<=(const BigInt&num)const{
    return !(*this>num);
}

bool BigInt::operator>=(const BigInt&num)const{
    return !(*this<num);
}

bool BigInt::operator!=(const BigInt&num)const{
    return *this>num||*this<num;
}

bool BigInt::operator==(const BigInt&num)const{
    return !(num!=*this);
}

BigInt BigInt::operator+(const BigInt &num)const{
    if(sign^num.sign){
        BigInt tmp=sign?num:*this;
        tmp.sign=1;
        return sign?*this-tmp:num-tmp;
    }
    BigInt res;
    res.len=0;
    int tmp=0;
    for(int i=0;tmp||i<(max(len,num.len));i++){
        int t=s[i]+num.s[i]+tmp;
        res.s[res.len++]=t%10;
        tmp=t/10;
    }
    res.sign=sign;
    return res;
}

BigInt BigInt::operator++(){
    *this=*this+1;
    return *this;
}

BigInt BigInt::operator++(int){
    BigInt old=*this;
    ++(*this);
    return old;
}

BigInt BigInt::operator+=(const BigInt &num){
    *this=*this+num;
    return *this;
}

BigInt BigInt::operator-(const BigInt &num)const{
    BigInt b=num,a=*this;
    if(!num.sign&&!sign){
        b.sign=1;
        a.sign=1;
        return b-a;
    }
    if(!b.sign){
        b.sign=1;
        return a+b;
    }
    if(!a.sign){
        a.sign=1;
        b=BigInt(0)-(a+b);
        return b;
    }
    if(a<b){
        BigInt c=(b-a);
        c.sign=false;
        return c;
    }
    BigInt res;
    res.len=0;
    for(int i=0,g=0;i<a.len;i++){
        int x=a.s[i]-g;
        if(i<b.len) x-=b.s[i];
        if(x>=0) g=0;
        else{
            g=1;
            x+=10;
        }
        res.s[res.len++]=x;
    }
    res.clean();
    return res;
}

BigInt BigInt::operator*(const BigInt &num)const{
    BigInt res;
    res.len=len+num.len;
    for(int i=0;i<len;i++)
        for(int j=0;j<num.len;j++)
            res.s[i+j]+=s[i]*num.s[j];
    for(int i=0;i<res.len;i++){
        res.s[i+1]+=res.s[i]/10;
        res.s[i]%=10;
    }
    res.clean();
    res.sign=!(sign^num.sign);
    return res;
}

BigInt BigInt::operator*(const int num)const{
    BigInt x=num;
    BigInt z=*this;
    return x*z;
}
BigInt BigInt::operator*=(const BigInt&num){
    *this=*this*num;
    return *this;
}

BigInt BigInt::operator/(const BigInt&num)const{
    BigInt ans;
    ans.len=len-num.len+1;
    if (ans.len<0){
        ans.len=1;
        return ans;
    }
    BigInt divisor=*this,divid=num;
    divisor.sign=divid.sign=1;
    int k=ans.len-1;
    int j=len-1;
    while(k>=0){
        while(divisor.s[j]==0) j--;
        if(k>j) k=j;
        char z[MAX_L];
        memset(z,0,sizeof(z));
        for(int i=j;i>=k;i--)
            z[j-i]=divisor.s[i]+'0';
        BigInt dividend=z;
        if(dividend<divid) {k--;continue;}
        int key=0;
        while(divid*key<=dividend) key++;
        key--;
        ans.s[k]=key;
        BigInt tmp=divid*key;
        for(int i=0;i<k;i++)
            tmp=tmp*10;
        divisor=divisor-tmp;
        k--;
    }
    ans.clean();
    ans.sign=!(sign^num.sign);
    return ans;
}

BigInt BigInt::operator/=(const BigInt&num){
    *this=*this/num;
    return *this;
}

BigInt BigInt::operator%(const BigInt& num)const{
    BigInt a=*this,b=num;
    a.sign=b.sign=1;
    BigInt res,tmp=a/b*b;
    res=a-tmp;
    res.sign=sign;
    return res;
}

BigInt BigInt::pow(const BigInt& num)const{
    BigInt res=1;
    for(BigInt i=0;i<num;i++)
        res=res*(*this);
    return res;
}

BigInt BigInt::factorial()const{
    BigInt res=1;
    for(BigInt i=1;i<=*this;i++)
        res*=i;
    return res;
}

void BigInt::clean(){
    if(len==0) len++;
    while(len>1&&s[len-1]=='\0')
        len--;
}

BigInt BigInt::Sqrt()const{
    if(*this<0)return -1;
    if(*this<=1)return *this;
    BigInt l=0,r=*this,mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(mid*mid>*this) r=mid;
        else l=mid;
    }
    return l;
}

BigInt::~BigInt(){}

int main(){

}
