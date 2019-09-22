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

static PO2 sp2;
static char Emptystr[]="";

int WordIdxInStr(const char *str,const char *word);
int WordIdxInStr(const int si,const char *str,const char *word);
int WordIdxInStr(const int si,const int ei,const char *str,const char *word);
int WordIdxInStrRev(const char *str,const char *word);
int WordIdxInStrRev(const int si,const char *str,const char *word);
int WordIdxInStrRev(const int si,const int ei,const char *str,const char *word);

int WordIdxInStr(const char *str,const char c);
int WordIdxInStr(const int si,const char *str,const char c);
int WordIdxInStr(const int si,const int ei,const char *str,const char c);
int WordIdxInStrRev(const char *str,const char c);
int WordIdxInStrRev(const int si,const char *str,const char c);
int WordIdxInStrRev(const int si,const int ei,const char *str,const char c);

PO2 SymBlkIdxInStr(const int si,const int ei,const char *str,const char *SymChrLst);

class MyStr {
private:
			int  		len;
			char 		*str;
			char 		*tmp;
protected:
			const char*	resizeX(char **pstr,const char *istr);
virtual 	const char*	resize(const char *istr);
virtual 	const char*	resizetmp(const char *istr);
virtual 	void		release(void);
virtual 	void		releasetmp(void);

public:
			MyStr();
			MyStr(const char *s);
			MyStr(MyStr &S);
			~MyStr();
			
virtual 	operator int();
virtual 	operator char*();
virtual 	operator const char*();

virtual 	MyStr&	operator=(const char *s);
virtual 	MyStr&	operator=(const char c);
virtual 	MyStr&	operator=(MyStr &S);

virtual 	MyStr&	operator+=(const char *s);
virtual 	MyStr&	operator+=(const char c);
virtual 	MyStr&	operator+=(MyStr &S);

virtual 	bool	operator==(const char *s);
virtual 	bool	operator==(const char c);
virtual 	bool	operator==(MyStr &S);
 
virtual 	bool	operator!=(const char *s);
virtual 	bool	operator!=(const char c);
virtual 	bool	operator!=(MyStr &S);

virtual 	const char*	operator+(const char *s);
virtual 	const char*	operator+(const char c);
virtual 	const char*	operator+(MyStr &S);

virtual 	int		InStr(const char *w);
virtual 	int		InStr(const int si,const char *w);
virtual 	int		InStr(const int si,const int ei,const char *w);

virtual 	int		InStr(const char c);
virtual 	int		InStr(const int si,const char c);
virtual 	int		InStr(const int si,const int ei,const char c);

virtual 	int		InStrRev(const char *w);
virtual 	int		InStrRev(const int si,const char *w);
virtual 	int		InStrRev(const int si,const int ei,const char *w);

virtual 	int		InStrRev(const char c);
virtual 	int		InStrRev(const int si,const char c);                                              
virtual 	int		InStrRev(const int si,const int ei,const char c);

virtual 	const char* GetStrRangeByKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst);
virtual 	const char* GetStrRangeBtwKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst);
					
virtual 	const char* GetStrRangeByKey(const char *k1,const char *k2);
virtual 	const char* GetStrRangeByKey(const char c1,const char c2);
virtual 	const char* GetStrRangeBtwKey(const char *k1,const char *k2);
virtual 	const char* GetStrRangeBtwKey(const char c1,const char c2);

virtual 	const char* GetStrRangeByIdx(const char si,const char ei);
virtual 	const char* GetStrRangeBtwIdx(const char si,const char ei);

virtual		const char* GetStrRemoveWord(const char *wd);
virtual		const char* GetStrRemoveWord(const int si,const char *wd);
virtual		const char* GetStrRemoveWord(const int si,const int ei,const char *wd);

virtual		const char* GetStrRemoveWordExSymBlk(const int si,const int ei,const char *wd,const char *SymChrLst);

};

#endif
