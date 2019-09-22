
#include "mystr.h"

using namespace std;

void po2check(const char *s,const char *sym)
{
    MyStr S;
    S=s;
	int k=-1;
	PO2 p=SymBlkIdxInStr(k,-1,(char*)S,sym);
	printf("\n     012345678901234567890");
	printf("\nstr='%s' len=%d Sym='%s'\n",(char*)S,(int)S,sym);
	while(p.p1>-1) {
		printf("k=%d , p.p1=%d p.p2=%d\n",k,p.p1,p.p2);
		k=p.p2+1;
		p=SymBlkIdxInStr(k,-1,(char*)S,sym);
	}
}

int main(int ac,char** av)
{
/*    MyStr S("a?bbb?\"\"?e?''?'\"");
	po2check((const char*)S,"\"?'");
	S="\"AA\"?BB?''?\"CC?'";
	po2check((const char*)S,"\"?'");
	S+="***?'";
	po2check((const char*)S,"\"'");
	S+="\"";
	po2check((const char*)S,"?'");
	po2check((const char*)S,"\"?'");
	po2check((const char*)S,"?'\"");

	MyStr S,T("TT");
	printf("\n'%s'\n",S+"AA");
	printf("\n'%s'\n",S+'c');
	printf("\n'%s'\n",S+T);
	S="S+";
	printf("\n'%s'\n",S+"AA");
	printf("\n'%s'\n",S+'c');
	printf("\n'%s'\n",S+T);
*/
	MyStr S("abcdefabcdef");
  	printf("\nS=[%d] '%s'",(int)S,(char*)S);
	MyStr K1,K2;
    printf("\nS.GetStrRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeByKey((const char*)K1,(const char*)K2));
	K1="bc";
    printf("\nS.GetStrRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeByKey((const char*)K1,(const char*)K2));
	K2="bc";
    printf("\nS.GetStrRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeByKey((const char*)K1,(const char*)K2));
	K1="";
    printf("\nS.GetStrRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeByKey((const char*)K1,(const char*)K2));
	K1="a"; K2="f";
    printf("\nS.GetStrRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeByKey((const char*)K1,(const char*)K2));
	K1="abcd"; K2="cdef";
    printf("\nS.GetStrRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeByKey((const char*)K1,(const char*)K2));


	K1=""; K2="";
    printf("\n\nS.GetStrRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeBtwKey((const char*)K1,(const char*)K2));
	K1="bc";
    printf("\nS.GetStrRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeBtwKey((const char*)K1,(const char*)K2));
	K2="bc";
    printf("\nS.GetStrRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeBtwKey((const char*)K1,(const char*)K2));
	K1="";
    printf("\nS.GetStrRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeBtwKey((const char*)K1,(const char*)K2));
	K1="a"; K2="f";
    printf("\nS.GetStrRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeBtwKey((const char*)K1,(const char*)K2));
	K1="abcd"; K2="cdef";
    printf("\nS.GetStrRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetStrRangeBtwKey((const char*)K1,(const char*)K2));

int n;
	int sp=-1;
	int ep=-1;
    printf("\n\nS.GetStrRangeByIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeByIdx(sp,ep));
    ep=(int)S;
    printf("\nS.GetStrRangeByIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeByIdx(sp,ep));
    ep-=1;
    printf("\nS.GetStrRangeByIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeByIdx(sp,ep));

for(n=0;n<10;n++) {   
    sp+=1; ep-=1;
    printf("\nS.GetStrRangeByIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeByIdx(sp,ep));
}
    sp=0; ep=sp;
    printf("\nS.GetStrRangeByIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeByIdx(sp,ep));
    sp=(int)S-1; ep=sp;
    printf("\nS.GetStrRangeByIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeByIdx(sp,ep));

	sp=-1; ep=-1;
    printf("\n\nS.GetStrRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeBtwIdx(sp,ep));
    ep=(int)S;
    printf("\nS.GetStrRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeBtwIdx(sp,ep));
    ep-=1;
    printf("\nS.GetStrRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeBtwIdx(sp,ep));

for(n=0;n<10;n++) {   
    sp+=1; ep-=1;
    printf("\nS.GetStrRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeBtwIdx(sp,ep));
} 
    sp=0; ep=sp;
    printf("\nS.GetStrRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeBtwIdx(sp,ep));
    sp=(int)S-1; ep=sp;
    printf("\nS.GetStrRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetStrRangeBtwIdx(sp,ep));

    MyStr SYM("?\"");
	S="abc?defabc?defa";
  	printf("\nS=[%d] '%s'",(int)S,(char*)S);
	K1=""; K2="";
    printf("\nS.GetStrRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetStrRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="c";
    printf("\nS.GetStrRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetStrRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K2="d";
    printf("\nS.GetStrRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetStrRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="";
    printf("\nS.GetStrRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetStrRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="f";
    printf("\nS.GetStrRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetStrRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="e";
    printf("\nS.GetStrRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetStrRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="a";
    printf("\nS.GetStrRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetStrRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));



    exit(0);

}
