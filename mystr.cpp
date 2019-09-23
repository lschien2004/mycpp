
#include "mystr.h"

int WdIdxInStr(const int si,const int ei,const char *str,const char *word) {
    int wl=-1;
    int ll=-1;
    if(str!=NULL) ll=strlen(str);
    if(word!=NULL) wl=strlen(word);
    int sp=si;
    if(sp<0) sp=0;
    int el=ei+1;
    if(ei<0) el=ll;
    
    if( !(ll<1 || wl<1 || ll<wl || sp>=el || el>ll)) {  
    	for(int i=sp;i<el;i++) {
        	if((el-i)<wl) return -1;
        	if(str[i]==word[0]) if(strncmp(str+i,word,wl)==0) return i;
    	}
    }
    return -1;
}
int WdIdxInStr(const char *str,const char *word) {
	return WdIdxInStr(-1,-1,str,word);
}
int WdIdxInStr(const int si,const char *str,const char *word) {
	return WdIdxInStr(si,-1,str,word);
}
int WdIdxInStr(const int si,const int ei,const char *str,const char c) {
	char s[2]; s[0]=c; s[1]='\0'; 
	return WdIdxInStr(si,ei,str,s);
}
int WdIdxInStr(const char *str,const char c) {
	return WdIdxInStr(-1,-1,str,c);
}
int WdIdxInStr(const int si,const char *str,const char c) {
	return WdIdxInStr(si,-1,str,c);
}

int WdIdxInStrRev(const int si,const int ei,const char *str,const char *word) {
    int wl=-1;
    int ll=-1;
    if(str!=NULL) ll=strlen(str);
    if(word!=NULL) wl=strlen(word);
    int sp=si;
    if(sp<0) sp=0;
    int el=ei+1;
    if(ei<0) el=ll;
    
    if( !(ll<1 || wl<1 || ll<wl || sp>=el || el>ll)) {  
    	for(int i=el-wl;i>=sp;i--) {
        	if(str[i]==word[0]) if(strncmp(str+i,word,wl)==0) return i;
    	}
    }
    return -1;
}
int WdIdxInStrRev(const char *str,const char *word) {
	return WdIdxInStrRev(-1,-1,str,word);
}
int WdIdxInStrRev(const int si,const char *str,const char *word) {
	return WdIdxInStrRev(si,-1,str,word);
}
int WdIdxInStrRev(const int si,const int ei,const char *str,const char c) {
	char s[2]; s[0]=c; s[1]='\0'; 
	return WdIdxInStrRev(si,ei,str,s);
}
int WdIdxInStrRev(const char *str,const char c) {
	return WdIdxInStrRev(-1,-1,str,c);
}
int WdIdxInStrRev(const int si,const char *str,const char c) {
	return WdIdxInStrRev(si,-1,str,c);
}


char MyStr::Emptystr[2]="";
PO2	MyStr::sp2;


PO2 MyStr::SymBlkIdxInStr(const int si,const int ei,const char *str,const char *SymChrLst) {
	sp2.p1=-1; sp2.p2=-1;
	int ll=-1;
	if(str!=NULL) ll=strlen(str);
	int lsym=-1;
	if(SymChrLst!=NULL) lsym=strlen(SymChrLst);
	int sp=si;
	if(sp<0) sp=0;
	int ep=ei;
	if(ei<0) ep=ll-1;
	if(ll>0 || lsym>0 || sp<=ep || ep<ll) {
		for(int n=0;n<lsym;n++) {
			int p=WdIdxInStr(sp,ep,str,SymChrLst[n]);
			int q=WdIdxInStr(p+1,ep,str,SymChrLst[n]);
			if(p>-1 && q>-1) {
				if(sp2.p1<0) {sp2.p1=p; sp2.p2=q;}
				else if(p<sp2.p1) {sp2.p1=p; sp2.p2=q;}
			}
		}
	}
	return sp2;
}
PO2 MyStr::SymBlkIdxInStr(const int si,const int ei,const char *SymChrLst) {
	return SymBlkIdxInStr(si,ei,str,SymChrLst);
}
const char*	MyStr::resizeX(char **pstr,const char *istr) {
//printf("\n** str=%u tmp=%u Emptystr=%u *pstr=%u istr='%s'",str,tmp,Emptystr,*pstr,istr);
	int ll=0;
	if(*pstr==NULL) *pstr=Emptystr;
	else			ll=strlen(*pstr);
	int ii=0;
	if(istr!=NULL) ii=strlen(istr);
	if(ii!=ll) {
		if(*pstr!=Emptystr) delete [] *pstr;
		if(ii<1)	*pstr=Emptystr;
		else		*pstr=strdup(istr);
	} else if(ii>0) 	strcpy(*pstr,istr);
	return *pstr;
}
const char*	MyStr::resize(const char *istr) { 
	resizeX(&str,istr); len=strlen(str); return str;
}
const char*	MyStr::resizetmp(const char *istr) {
	return resizeX(&tmp,istr);
}
void MyStr::release(void) { 
	len=0; 
	if(str!=Emptystr) delete [] str; 
	str=Emptystr;
}
void MyStr::releasetmp(void) { 
	if(tmp!=Emptystr) delete [] tmp;
	tmp=Emptystr;
}

MyStr::MyStr() { 
	tmp=Emptystr; str=Emptystr; len=0;
}
MyStr::MyStr(const char *s) {
	tmp=Emptystr;
	str=Emptystr; resize(s); len=strlen(str);
}
MyStr::MyStr(MyStr &S) {
	tmp=Emptystr;
	str=Emptystr; resize(S.str); len=strlen(str); 
}
MyStr::~MyStr() {
	releasetmp(); release();
}

MyStr::operator int() 				{ return len; }
MyStr::operator char*() 			{ return str; }
MyStr::operator const char*() 		{ return str; }

MyStr&	MyStr::operator=(const char *s)	{ resize(s); return *this; }
MyStr&	MyStr::operator=(const char c)	{ char s[2]; s[0]=c; s[1]='\0'; resize(s); return *this; }
MyStr&	MyStr::operator=(MyStr &S)		{ resize(S.str); return *this; }

MyStr&	MyStr::operator+=(const char c)	{ char s[2]; s[0]=c; s[1]='\0'; return operator+=(s); }
MyStr&	MyStr::operator+=(MyStr &S)		{ return operator+=(S.str); }

bool	MyStr::operator==(const char c)	{ char s[2]; s[0]=c; s[1]='\0'; return operator==(s); }
bool	MyStr::operator==(MyStr &S)		{ return operator==(S.str); }
 
bool	MyStr::operator!=(const char *s)	{ if(operator==(s)) return false; else return true; }
bool	MyStr::operator!=(const char c) 	{ char s[2]; s[0]=c; s[1]='\0'; return operator!=(s); }
bool	MyStr::operator!=(MyStr &S) 		{ return operator!=(S.str); }

const char*	MyStr::operator+(const char c)	{ char s[2]; s[0]=c; s[1]='\0'; return operator+(s); }
const char*	MyStr::operator+(MyStr &S)		{ return operator+(S.str); }

int		MyStr::InStr(const char *w) 							{ return WdIdxInStr(-1,-1,str,w); }
int		MyStr::InStr(const int si,const char *w) 				{ return WdIdxInStr(si,-1,str,w); }
int		MyStr::InStr(const int si,const int ei,const char *w) 	{ return WdIdxInStr(si,ei,str,w); }

int		MyStr::InStr(const char c) 								{ return WdIdxInStr(-1,-1,str,c); }
int		MyStr::InStr(const int si,const char c) 				{ return WdIdxInStr(si,-1,str,c); }
int		MyStr::InStr(const int si,const int ei,const char c) 	{ return WdIdxInStr(si,ei,str,c); }

int		MyStr::InStrRev(const char *w) 								{ return WdIdxInStrRev(-1,-1,str,w); }
int		MyStr::InStrRev(const int si,const char *w) 				{ return WdIdxInStrRev(si,-1,str,w); }
int		MyStr::InStrRev(const int si,const int ei,const char *w) 	{ return WdIdxInStrRev(si,ei,str,w); }

int		MyStr::InStrRev(const char c) 								{ return WdIdxInStrRev(-1,-1,str,c); }
int		MyStr::InStrRev(const int si,const char c) 					{ return WdIdxInStrRev(si,-1,str,c); }
int		MyStr::InStrRev(const int si,const int ei,const char c) 	{ return WdIdxInStrRev(si,ei,str,c); }

MyStr& MyStr::operator+=(const char *s) {
	if(s!=NULL) {
		int ls=0;
		if(s!=NULL) ls=strlen(s);
		if(ls>0) {
			ls+=len;
			char *t=new char[ls+1];
			strncpy(t,str,len);
			strcpy(t+len,s);
			release();
			str=t;
			len=strlen(str);
		}
	}
	return *this;
}
bool MyStr::operator==(const char *s) {
	int ls=-1;
	if(s!=NULL) ls=strlen(s);
	if(len==ls) {
		if(strcmp(str,s)==0) return true;
	}
	return false;
}
const char*	MyStr::operator+(const char *s) {
	int ls=0;
	if(s!=NULL) ls=strlen(s);
	if(ls>0) {
		char *t=new char[len+ls+1];
		strncpy(t,str,len);
		strcpy(t+len,s);
		releasetmp();
		tmp=t;
	} else resizetmp(str);
	return tmp;
}
const char* MyStr::GetRangeBtwKey(const char *k1,const char *k2) {
	int lk1=0;
	if(k1!=NULL) lk1=strlen(k1);
	int lk2=0;
	if(k2!=NULL) lk2=strlen(k2);
	if( (lk1<1 && lk2<1) || len<1 ) return resizetmp(str);
	
	int p=0;
	int q=len-1;
	if(lk1>0) { 
		p=InStr(k1);
		if(p>-1) {
			p+=lk1;
			if(lk2>0) q=InStr(p,k2)-1;
		}
	} else if(lk2>0) q=InStr(k2)-1;
	if(p>-1 && q>-1) {
		lk1=q-p+1;
		char *t=new char[lk1+1];
		strncpy(t,str+p,lk1);
		t[lk1]='\0';
		releasetmp();
		tmp=t;
		return tmp;
	}
	return resizetmp(NULL);
}
const char* MyStr::GetRangeBtwKey(const char c1,const char c2) {
	char s1[2]; s1[0]=c1; s1[1]='\0';
	char s2[2]; s2[0]=c2; s2[1]='\0';
	return GetRangeBtwKey(s1,s2);
}
const char* MyStr::GetRangeByKey(const char *k1,const char *k2) {
	int lk1=0;
	if(k1!=NULL) lk1=strlen(k1);
	int lk2=0;
	if(k2!=NULL) lk2=strlen(k2);
	if( (lk1<1 && lk2<1) || len<1 ) return resizetmp(str);
	
	int p=0;
	int q=len-1;
	if(lk1>0) { 
		p=InStr(k1);
		if(p>-1 && lk2>0) q=InStr(p+lk1,k2);
	} else if(lk2>0) q=InStr(k2);
	if(p>-1 && q>-1) {
		lk1=q-p+lk2;
		char *t=new char[lk1+1];
		strncpy(t,str+p,lk1);
		t[lk1]='\0';
		releasetmp();
		tmp=t;
		return tmp;
	}
	return resizetmp(NULL);
}
const char* MyStr::GetRangeByKey(const char c1,const char c2) {
	char s1[2]; s1[0]=c1; s1[1]='\0';
	char s2[2]; s2[0]=c2; s2[1]='\0';
	return GetRangeByKey(s1,s2);
}

const char* MyStr::GetRangeByKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst) {
	int lk1=0;
	if(k1!=NULL) lk1=strlen(k1);
	int lk2=0;
	if(k2!=NULL) lk2=strlen(k2);
	if( (lk1<1 && lk2<1) || len<1 ) return resizetmp(str);
	int lsym=0;
	if(SymChrLst!=NULL) lsym=strlen(SymChrLst);
	if(lsym<1) return GetRangeByKey(k1,k2);
	
	int k=0 ,p=-1 ,q=-1;
	if(lk1<1) p=k;
	if(lk2<1) q=len;
	PO2 pp=SymBlkIdxInStr(k,-1,SymChrLst);
	while(pp.p1>-1) {
		if(lk1>0 && p<0) {
			p=InStr(k,pp.p1-1,k1);
			if(p>-1) k=p+lk1;
		}
		if(lk2>0) q=InStr(k,pp.p1-1,k2);
		if(p>-1 && q>-1) break;
		k=pp.p2+1;
		pp=SymBlkIdxInStr(k,-1,SymChrLst);
	}
	if(lk1>0 && p<0) {
		p=InStr(k,-1,k1);
		if(p>-1) k=p+lk1;
	}
	if(lk2>0 && q<0 ) q=InStr(k,-1,k2);
	if(p>-1 && q>-1) {
		lk1=q+lk2-p;
		char *t=new char[lk1+1];
		strncpy(t,str+p,lk1);
		t[lk1]='\0';
		releasetmp();
		tmp=t;
		return tmp;
	}	
	return resizetmp(NULL);
}

const char* MyStr::GetRangeBtwKeyExSymBlk(const char *k1,const char *k2,const char *SymChrLst) {
	int lk1=0;
	if(k1!=NULL) lk1=strlen(k1);
	int lk2=0;
	if(k2!=NULL) lk2=strlen(k2);
	if( (lk1<1 && lk2<1) || len<1 ) return resizetmp(str);
	int lsym=0;
	if(SymChrLst!=NULL) lsym=strlen(SymChrLst);
	if(lsym<1) return GetRangeBtwKey(k1,k2);
	
	int k=0 ,p=-1 ,q=-1;
	if(lk1<1) p=k;
	if(lk2<1) q=len;
	PO2 pp=SymBlkIdxInStr(k,-1,SymChrLst);
	while(pp.p1>-1) {
		if(lk1>0 && p<0) {
			p=InStr(k,pp.p1-1,k1);
			if(p>-1) k=p+lk1;
		}
		if(lk2>0) q=InStr(k,pp.p1-1,k2);
		if(p>-1 && q>-1) break;
		k=pp.p2+1;
		pp=SymBlkIdxInStr(k,-1,SymChrLst);
	}
	if(lk1>0 && p<0) {
		p=InStr(k,-1,k1);
		if(p>-1) k=p+lk1;
	}
	if(lk2>0 && q<0 ) q=InStr(k,-1,k2);
	if(p>-1 && q>-1) {
		if(lk1>0) p+=lk1;
		if(lk2>0) q--;
		lk1=q-p+1;
		char *t=new char[lk1+1];
		strncpy(t,str+p,lk1);
		t[lk1]='\0';
		releasetmp();
		tmp=t;
		return tmp;
	}	
	return resizetmp(NULL);
}
const char* MyStr::GetRangeByIdx(const char si,const char ei) {
	int sp=si;
	if(si<0) sp=0;
	int ep=ei;
	if(ei<0) ep=len-1;
	if(len>0 && sp<=ep && ep<len) {
		int ll=ep-sp+1;
		char *t=new char[ll+1];
		strncpy(t,str+sp,ll);
		t[ll]='\0';
		releasetmp();
		tmp=t;
		return tmp;
	}
	return resizetmp(NULL);
}
const char* MyStr::GetRangeBtwIdx(const char si,const char ei) {
	int sp=si+1;
	if(si<0) sp=0;
	int ep=-1;
	if(ei<0) ep=len-1;
	else if(ei<len) ep=ei-1;
	
	if(len>0 && sp<=ep && ep<len) {
		int ll=ep-sp+1;
		char *t=new char[ll+1];
		strncpy(t,str+sp,ll);
		t[ll]='\0';
		releasetmp();
		tmp=t;
		return tmp;
	}
	return resizetmp(NULL);
}

const char* MyStr::GetRangeWithWdChg(const int si,const int ei,const char *owd,const char *nwd) {
	int sp=si;
	if(si<0) sp=0;
	int ep=ei;
	if(ep<0) ep=len-1;
	int lowd=0;
	if(owd!=NULL) lowd=strlen(owd);
	int lnwd=0;
	if(nwd!=NULL) lnwd=strlen(nwd);
	
//printf("\n*>GetRangeWithWdChg:str='%s' sp=%d ep=%d len=%d lowd=%d lnwd=%d",str,sp,ep,len,lowd,lnwd);

	if(len<1 || sp>ep || ep>=len) return resizetmp(NULL);
	if(lowd<1) return resizetmp(str);

	int isp=sp;
	MyStr T;
	int p=InStr(sp,ep,owd);
	while(p>-1) {
		if(p>sp) T+=GetRangeByIdx(sp,p-1);
		if(lnwd>0) T+=nwd;
		sp=p+lowd;
		p=InStr(sp,ep,owd);
	}
//printf("\n*>sp=%d , isp=%d",sp,isp);
	if(sp==isp) return str;
	if(sp<=ep) T+=GetRangeByIdx(sp,ep);
//printf("\n*>T='%s'",T.str);
	return resizetmp(T.GetRangeWithWdChg(owd,nwd));
}
const char* MyStr::GetRangeWithWdChg(const char *owd,const char *nwd) { 
	return GetRangeWithWdChg(-1,-1,owd,nwd); 
}
const char* MyStr::GetRangeWithWdChg(const int si,const char *owd,const char *nwd) { 
	return GetRangeWithWdChg(si,-1,owd,nwd);
}

const char* MyStr::GetRangeWithWdDel(const int si,const int ei,const char *wd) { 
	return GetRangeWithWdChg(si,ei,wd,NULL); 
}
const char* MyStr::GetRangeWithWdDel(const int si,const char *wd) { 
	return GetRangeWithWdChg(si,-1,wd,NULL); 
}
const char* MyStr::GetRangeWithWdDel(const char *wd) { 
	return GetRangeWithWdChg(-1,-1,wd,NULL); 
}

const char* MyStr::GetRangeWithWdChgExSymBlk(const int si,const int ei,const char *owd,const char *nwd,const char *SymChrLst) {
	int sp=si;
	if(si<0) sp=0;
	int ep=ei;
	if(ep<0) ep=len-1;
	int lowd=0;
	if(owd!=NULL) lowd=strlen(owd);
	int lnwd=0;
	if(nwd!=NULL) lnwd=strlen(nwd);

	if(len<1 || sp>ep || ep>=len) return resizetmp(NULL);
	if(lowd<1) return resizetmp(str);

	int lsym=0;
	if(SymChrLst!=NULL) lsym=strlen(SymChrLst);
	if(lsym<1) return GetRangeWithWdChg(si,ei,owd,nwd);

	MyStr T;
	PO2 pp=SymBlkIdxInStr(sp,ep,SymChrLst);
	while(pp.p1>-1) {
		int p=InStr(sp,pp.p1-1,owd);
		if(p>0) {
			T+=GetRangeByIdx(sp,p-1);
			if(lnwd>0) { T+=nwd; T=T.GetRangeWithWdChg(owd,nwd); }
			sp=p+lowd;
		} else	{T+=GetRangeByIdx(sp,pp.p2); sp=pp.p2+1;}
		pp=SymBlkIdxInStr(sp,ep,SymChrLst);
	}
	if(sp<=ep) {
		T+=GetRangeByIdx(sp,ep);
		T=T.GetRangeWithWdChg(owd,nwd);
	}
	return resizetmp(T.str);
}
const char* MyStr::GetRangeWithWdChgExSymBlk(const char *owd,const char *nwd,const char *SymChrLst) { 
	return GetRangeWithWdChgExSymBlk(-1,-1,owd,nwd,SymChrLst);
}
const char* MyStr::GetRangeWithWdChgExSymBlk(const int si,const char *owd,const char *nwd,const char *SymChrLst) {
	return GetRangeWithWdChgExSymBlk(si,-1,owd,nwd,SymChrLst);
}

const char* MyStr::GetRangeWithWdDelExSymBlk(const int si,const int ei,const char *wd,const char *SymChrLst){
	return GetRangeWithWdChgExSymBlk(si,ei,wd,NULL,SymChrLst);
}	
const char* MyStr::GetRangeWithWdDelExSymBlk(const char *wd,const char *SymChrLst) {
	return GetRangeWithWdChgExSymBlk(-1,-1,wd,NULL,SymChrLst);
}
const char* MyStr::GetRangeWithWdDelExSymBlk(const int si,const char *wd,const char *SymChrLst) {
	return GetRangeWithWdChgExSymBlk(si,-1,wd,NULL,SymChrLst);
}