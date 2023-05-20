#include <bits/stdc++.h>
using namespace std;
int idpower[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char checkcode[11]={'1','0','X','9','8','7','6','5','4','3','2'};
class CDate
{

private:
 int year, month, day;
public:
 CDate(int a, int b, int c){
  year=a;
  month=b;
  day=c;
 };
 CDate(CDate & d){
  year = d.year;
  month = d.month;
  day =  d.day;
 }
 bool check(){
  int leap[12]={31,(isLeap() ? 29 : 28),31,30,31,30,31,31,30,31,30,31};
  if(month < 0 || day < 0 || day > leap[month - 1] || month > 12){
   return false;
  }
  return true;
 }
 int Sum(){
  return year * 10000 + month * 100 + day;
 }
 bool judge(int y,int m,int d){
  if(y != year || m != month || d != day)return false;
  return true;
 }
 bool isLeap(){
  return (year%4==0 && year % 100 != 0 || year % 400 == 0);
 }
 void print(){
  cout << year << "年"  << month << "月" << day << "日 ";
 }
};

class COldId
{
protected:
 char* pId15, * pName; //15位身份证号码，姓名
 CDate birthday; //出生日期
public:
 COldId(char* pIdVal, char* pNameVal, CDate& day) : birthday(day) {
  pId15 = new char [strlen(pIdVal) + 1];
  strcpy(pId15,pIdVal);
  pName = new char [strlen(pNameVal) + 1];
  strcpy(pName,pNameVal);
 }
 bool check(){}//验证15位身份证是否合法
 void print(){}
 ~COldId(){
  delete[] pId15;
  delete[] pName;
 }
};

class CNewId:public COldId
{
private:
 char* pId18;
 int va;
 CDate issue;
public:
 CNewId(char* na,char* p15,char* p18,CDate & d,int ax,int bx,int cx,int v) : COldId(p15,na,d),issue(ax,bx,cx){
  va = v;
  pId18 = new char [strlen(p18) + 1];
  strcpy(pId18,p18);
 }
 bool check(){
  int len = strlen(pId18);
  if(len == 18){
   for(int i = 0;i < len;i ++){
    if(i != len - 1 && (pId18[i] < '0' || pId18[i] > '9'))return false;
    if(i == len - 1 && (pId18[i] < '0' || pId18[i] > '9') && pId18[i] != 'X')return false;
   }
   for(int i = 0,to = 0;i < 15;i ++,to ++){
    if(to == 6)to += 2;
    if(pId15[i] != pId18[to])return false;
   }

   int y = (pId18[6] - '0') * 1000 + (pId
