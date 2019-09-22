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
 inline	const char*	resize(const char *istr) 	{ resizeX(&str,istr); len=strlen(str); return str; }
 inline	const char*	resizetmp(const char *istr) { return resizeX(&tmp,istr); }
 inline void		release(void) 				{ len=0; if(str!=Emptystr) delete [] str; str=Emptystr; }
 inline void		releasetmp(void) 			{ if(tmp!=Emptystr) delete [] tmp; tmp=Emptystr; }

public:
 inline				MyStr() { str=Emptystr; tmp=Emptystr; len=0; }
 inline				MyStr(const char *s) { str=Emptystr; tmp=Emptystr; resize(s); len=strlen(str); }
 inline				MyStr(MyStr &S) { str=Emptystr; tmp=Emptystr; resize(S.str); len=strlen(str); }
 inline				~MyStr() { releasetmp(); release(); }
			
 inline 			operator int() 				{ return len; }
 inline 			operator char*() 			{ return str; }
 inline 			operator const char*() 		{ return str; }

 inline virtual 	MyStr&	operator=(const char *s)	{ resize(s); return *this; }
 inline virtual 	MyStr&	operator=(const char c)		{ char s[2]; s[0]=c; s[1]='\0'; resize(s); return *this; }
 inline virtual 	MyStr&	operator=(MyStr &S)			{ resize(S.str); return *this; }

        virtual 	MyStr&	operator+=(const char *s);
 inline virtual 	MyStr&	operator+=(const char c) 	{ char s[2]; s[0]=c; s[1]='\0'; return operator+=(s); }
 inline virtual 	MyStr&	operator+=(MyStr &S)		{ return operator+=(S.str); }

		virtual 	bool	operator==(const char *s);
 inline	virtual 	bool	operator==(const char c) 	{ char s[2]; s[0]=c; s[1]='\0'; return operator==(s); }
 inline	virtual 	bool	operator==(MyStr &S) 		{ return operator==(S.str); }
 
 inline	virtual 	bool	operator!=(const char *s)   { if(operator==(s)) return false; else return true; }
 inline	virtual 	bool	operator!=(const char c) 	{ char s[2]; s[0]=c; s[1]='\0'; return operator!=(s); }
 inline	virtual 	bool	operator!=(MyStr &S) 		{ return operator!=(S.str); }

        virtual 	const char*	operator+(const char *s);
 inline	virtual 	const char*	operator+(const char c)	{ char s[2]; s[0]=c; s[1]='\0'; return operator+(s); }
 inline	virtual 	const char*	operator+(MyStr &S)		{ return operator+(S.str); }

 inline	virtual 	int		InStr(const char *w) 							{ return WordIdxInStr(-1,-1,str,w); }
 inline	virtual 	int		InStr(const int si,const char *w) 				{ return WordIdxInStr(si,-1,str,w); }
 inline	virtual 	int		InStr(const int si,const int ei,const char *w) 	{ return WordIdxInStr(si,ei,str,w); }

 inline	virtual 	int		InStr(const char c) 							{ return WordIdxInStr(-1,-1,str,c); }
 inline	virtual 	int		InStr(const int si,const char c) 				{ return WordIdxInStr(si,-1,str,c); }
 inline	virtual 	int		InStr(const int si,const int ei,const char c) 	{ return WordIdxInStr(si,ei,str,c); }

 inline	virtual 	int		InStrRev(const char *w) 							{ return WordIdxInStrRev(-1,-1,str,w); }
 inline	virtual 	int		InStrRev(const int si,const char *w) 				{ return WordIdxInStrRev(si,-1,str,w); }
 inline	virtual 	int		InStrRev(const int si,const int ei,const char *w) 	{ return WordIdxInStrRev(si,ei,str,w); }

 inline	virtual 	int		InStrRev(const char c) 								{ return WordIdxInStrRev(-1,-1,str,c); }
 inline	virtual 	int		InStrRev(const int si,const char c) 				{ return WordIdxInStrRev(si,-1,str,c); }
 inline	virtual 	int		InStrRev(const int si,const int ei,const char c) 	{ return WordIdxInStrRev(si,ei,str,c); }

					const char* GetStrRangeByKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst);
					const char* GetStrRangeBtwKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst);
					
					const char* GetStrRangeByKey(const char *k1,const char *k2);
inline				const char* GetStrRangeByKey(const char c1,const char c2) { char s1[2]; s1[0]=c1; s1[1]='\0'; char s2[2]; s2[0]=c2; s2[1]='\0'; return GetStrRangeByKey(s1,s2); }
					const char* GetStrRangeBtwKey(const char *k1,const char *k2);
inline				const char* GetStrRangeBtwKey(const char c1,const char c2) { char s1[2]; s1[0]=c1; s1[1]='\0'; char s2[2]; s2[0]=c2; s2[1]='\0'; return GetStrRangeBtwKey(s1,s2); }

					const char* GetStrRangeByIdx(const char si,const char ei);
					const char* GetStrRangeBtwIdx(const char si,const char ei);
};

#endif
