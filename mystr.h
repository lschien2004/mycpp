#ifndef __MyStr__h__
    #define __MyStr__h__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

typedef struct {
	int p1;
	int p2;
} PO2;

int WdIdxInStr(const char *str,const char *word);
int WdIdxInStr(const int si,const char *str,const char *word);
int WdIdxInStr(const int si,const int ei,const char *str,const char *word);
int WdIdxInStrRev(const char *str,const char *word);
int WdIdxInStrRev(const int si,const char *str,const char *word);
int WdIdxInStrRev(const int si,const int ei,const char *str,const char *word);

int WdIdxInStr(const char *str,const char c);
int WdIdxInStr(const int si,const char *str,const char c);
int WdIdxInStr(const int si,const int ei,const char *str,const char c);
int WdIdxInStrRev(const char *str,const char c);
int WdIdxInStrRev(const int si,const char *str,const char c);
int WdIdxInStrRev(const int si,const int ei,const char *str,const char c);


class MyStr {
private:
static 		 char 		Emptystr[];
static 		 PO2		sp2;
			 int  		len;
			 char 		*str;
			 char 		*tmp;
protected:
			 const char*	resizeX(char **pstr,const char *istr);
virtual 	 const char*	resize(const char *istr);
virtual 	 const char*	resizetmp(const char *istr);
virtual 	 void		release(void);
virtual 	 void		releasetmp(void);

public:
			 MyStr();
			 MyStr(const char *s);
			 MyStr(MyStr &S);
			 ~MyStr();
			
virtual 	 operator int();
virtual 	 operator char*();
virtual 	 operator const char*();

virtual 	 MyStr& operator=(const char *s);
virtual 	 MyStr& operator=(const char c);
virtual 	 MyStr& operator=(MyStr &S);

virtual 	 MyStr& operator+=(const char *s);
virtual 	 MyStr& operator+=(const char c);
virtual 	 MyStr& operator+=(MyStr &S);

virtual 	 bool operator==(const char *s);
virtual 	 bool operator==(const char c);
virtual 	 bool operator==(MyStr &S);
 
virtual 	 bool operator!=(const char *s);
virtual 	 bool operator!=(const char c);
virtual 	 bool operator!=(MyStr &S);

virtual 	 const char* operator+(const char *s);
virtual 	 const char* operator+(const char c);
virtual 	 const char* operator+(MyStr &S);

			 PO2 		SymBlkIdxInStr(const int si,const int ei,const char *SymChrLst);
			 PO2 		SymBlkIdxInStr(const int si,const int ei,const char *str,const char *SymChrLst);

virtual 	 int 		InStr(const char *w);
virtual 	 int 		InStr(const int si,const char *w);
virtual 	 int 		InStr(const int si,const int ei,const char *w);

virtual 	 int 		InStr(const char c);
virtual 	 int 		InStr(const int si,const char c);
virtual 	 int 		InStr(const int si,const int ei,const char c);

virtual 	 int 		InStrRev(const char *w);
virtual 	 int 		InStrRev(const int si,const char *w);
virtual 	 int 		InStrRev(const int si,const int ei,const char *w);

virtual 	 int 		InStrRev(const char c);
virtual 	 int 		InStrRev(const int si,const char c);                                              
virtual 	 int 		InStrRev(const int si,const int ei,const char c);

virtual 	 const char* GetRangeByKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst);
virtual 	 const char* GetRangeBtwKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst);
					
virtual 	 const char* GetRangeByKey(const char *k1,const char *k2);
virtual 	 const char* GetRangeByKey(const char c1,const char c2);
virtual 	 const char* GetRangeBtwKey(const char *k1,const char *k2);
virtual 	 const char* GetRangeBtwKey(const char c1,const char c2);

virtual 	 const char* GetRangeByIdx(const char si,const char ei);
virtual 	 const char* GetRangeBtwIdx(const char si,const char ei);

virtual 	 const char* GetRangeWithWdChg(const char *owd,const char *nwd);
virtual 	 const char* GetRangeWithWdChg(const int si,const char *owd,const char *nwd);
virtual 	 const char* GetRangeWithWdChg(const int si,const int ei,const char *owd,const char *nwd);

virtual 	 const char* GetRangeWithWdDel(const char *wd);
virtual 	 const char* GetRangeWithWdDel(const int si,const char *wd);
virtual 	 const char* GetRangeWithWdDel(const int si,const int ei,const char *wd);

virtual 	 const char* GetRangeWithWdChgExSymBlk(const char *owd,const char *nwd,const char *SymChrLst);
virtual 	 const char* GetRangeWithWdChgExSymBlk(const int si,const char *owd,const char *nwd,const char *SymChrLst);
virtual 	 const char* GetRangeWithWdChgExSymBlk(const int si,const int ei,const char *owd,const char *nwd,const char *SymChrLst);

virtual 	 const char* GetRangeWithWdDelExSymBlk(const char *wd,const char *SymChrLst);
virtual 	 const char* GetRangeWithWdDelExSymBlk(const int si,const char *wd,const char *SymChrLst);
virtual 	 const char* GetRangeWithWdDelExSymBlk(const int si,const int ei,const char *wd,const char *SymChrLst);

};

#endif
