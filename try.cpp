
#include "mystr.h"

using namespace std;

void po2check(const char *s,const char *sym)
{
    MyStr S;
    S=s;
	int k=-1;
	PO2 p=S.SymBlkIdxInStr(k,-1,sym);
	printf("\n     012345678901234567890");
	printf("\nstr='%s' len=%d Sym='%s'\n",(char*)S,(int)S,sym);
	while(p.p1>-1) {
		printf("k=%d , p.p1=%d p.p2=%d\n",k,p.p1,p.p2);
		k=p.p2+1;
		p=S.SymBlkIdxInStr(k,-1,sym);
	}
}

int main(int ac,char** av)
{
    MyStr S,T,K1,K2,SYM;
	int n;
	int sp=-1;
	int ep=-1;
/*
    S="a?bbb?\"\"?e?''?'\"";
	po2check((const char*)S,"\"?'");
	S="\"AA\"?BB?''?\"CC?'";
	po2check((const char*)S,"\"?'");
	S+="***?'";
	po2check((const char*)S,"\"'");
	S+="\"";
	po2check((const char*)S,"?'");
	po2check((const char*)S,"\"?'");
	po2check((const char*)S,"?'\"");

	T="TT";
	S="";
	printf("\n'%s'\n",S+"AA");
	printf("\n'%s'\n",S+'c');
	printf("\n'%s'\n",S+T);
	S="S+";
	printf("\n'%s'\n",S+"AA");
	printf("\n'%s'\n",S+'c');
	printf("\n'%s'\n",S+T);

	S="abc?defabc?defa";
  	printf("\nS=[%d] '%s'",(int)S,(char*)S);
    printf("\nS.GetRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeByKey((const char*)K1,(const char*)K2));
	K1="bc";
    printf("\nS.GetRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeByKey((const char*)K1,(const char*)K2));
	K2="bc";
    printf("\nS.GetRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeByKey((const char*)K1,(const char*)K2));
	K1="";
    printf("\nS.GetRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeByKey((const char*)K1,(const char*)K2));
	K1="a"; K2="f";
    printf("\nS.GetRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeByKey((const char*)K1,(const char*)K2));
	K1="f"; K2="a";
    printf("\nS.GetRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeByKey((const char*)K1,(const char*)K2));
	K1="?"; K2="?";
    printf("\nS.GetRangeByKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeByKey((const char*)K1,(const char*)K2));


	K1=""; K2="";
    printf("\n\nS.GetRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeBtwKey((const char*)K1,(const char*)K2));
	K1="bc";
    printf("\nS.GetRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeBtwKey((const char*)K1,(const char*)K2));
	K2="bc";
    printf("\nS.GetRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeBtwKey((const char*)K1,(const char*)K2));
	K1="";
    printf("\nS.GetRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeBtwKey((const char*)K1,(const char*)K2));
	K1="a"; K2="f";
    printf("\nS.GetRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeBtwKey((const char*)K1,(const char*)K2));
	K1="abcd"; K2="cdef";
    printf("\nS.GetRangeBtwKey('%s','%s')='%s'",(char*)K1,(char*)K2,S.GetRangeBtwKey((const char*)K1,(const char*)K2));

	sp=-1;
	ep=-1;
    printf("\n\nS.GetRangeByIdx('%d','%d')='%s'",sp,ep,S.GetRangeByIdx(sp,ep));
    ep=(int)S;
    printf("\nS.GetRangeByIdx('%d','%d')='%s'",sp,ep,S.GetRangeByIdx(sp,ep));
    ep-=1;
    printf("\nS.GetRangeByIdx('%d','%d')='%s'",sp,ep,S.GetRangeByIdx(sp,ep));

for(n=0;n<10;n++) {   
    sp+=1; ep-=1;
    printf("\nS.GetRangeByIdx('%d','%d')='%s'",sp,ep,S.GetRangeByIdx(sp,ep));
}
    sp=0; ep=sp;
    printf("\nS.GetRangeByIdx('%d','%d')='%s'",sp,ep,S.GetRangeByIdx(sp,ep));
    sp=(int)S-1; ep=sp;
    printf("\nS.GetRangeByIdx('%d','%d')='%s'",sp,ep,S.GetRangeByIdx(sp,ep));

	sp=-1; ep=-1;
    printf("\n\nS.GetRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetRangeBtwIdx(sp,ep));
    ep=(int)S;
    printf("\nS.GetRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetRangeBtwIdx(sp,ep));
    ep-=1;
    printf("\nS.GetRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetRangeBtwIdx(sp,ep));

for(n=0;n<10;n++) {   
    sp+=1; ep-=1;
    printf("\nS.GetRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetRangeBtwIdx(sp,ep));
} 
    sp=0; ep=sp;
    printf("\nS.GetRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetRangeBtwIdx(sp,ep));
    sp=(int)S-1; ep=sp;
    printf("\nS.GetRangeBtwIdx('%d','%d')='%s'",sp,ep,S.GetRangeBtwIdx(sp,ep));

    SYM="?\"";
	S="abc?de,fa,bc?,defa,\"asd\",end";
  	printf("\nS=[%d] '%s'",(int)S,(char*)S);
	K1=""; K2="";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="c";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K2="d";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="f";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="e";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="a";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1=","; K2=","; SYM="?\"";
    printf("\nS.GetRangeByKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeByKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));

	SYM="?\"";
  	printf("\n\nS=[%d] '%s'",(int)S,(char*)S);
	K1=""; K2="";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="c";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K2="d";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="f";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="e";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1="a"; K2="a";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));
	K1=","; K2=","; SYM="?\"";
    printf("\nS.GetRangeBtwKeyExSymBlk('%s','%s','%s')='%s'",(char*)K1,(char*)K2,(char*)SYM,S.GetRangeBtwKeyExSymBlk((char*)K1,(char*)K2,(char*)SYM));

	S="abc?de,fa,bc?,defa,\"asd\",end";
  	printf("\n\n   012345678901234567890123456789");
  	printf("\nS='%s' [%2d]",(char*)S,(int)S);
  	K1=","; n=-1;
    printf("\nS.GetRangeWithWdDel('%s')='%s'",(char*)K1,S.GetRangeWithWdDel((char*)K1));
   	printf("\nS='%s' [%2d]",(char*)S,(int)S);
   	printf("\nS.GetRangeWithWdDel('%d','%s')='%s'",n,(char*)K1,S.GetRangeWithWdDel(n,(char*)K1));
    n+=11;
  	printf("\nS='%s' [%2d]",(char*)S,(int)S);
    printf("\nS.GetRangeWithWdDel('%d','%s')='%s'",n,(char*)K1,S.GetRangeWithWdDel(n,(char*)K1));
	sp=10; ep=17;
  	printf("\nS='%s' [%2d]",(char*)S,(int)S);
    printf("\nS.GetRangeWithWdDel('%d','%d','%s')='%s'",sp,ep,(char*)K1,S.GetRangeWithWdDel(sp,ep,(char*)K1));
   	printf("\nS='%s' [%2d]",(char*)S,(int)S);
*/
	S="abc?de,fa,bc?,defa,\"asd\",end";
   	printf("\n\n   012345678901234567890123456789");
	sp=-1; ep=-1; K1="a,";
  	printf("\nS='%s' [%2d]",(char*)S,(int)S);
    printf("\nS.GetRangeWithWdDelExSymBlk('%d','%d','%s','%s')\n='%s'",sp,ep,(char*)K1,(char*)SYM,S.GetRangeWithWdDelExSymBlk(sp,ep,(char*)K1,(char*)SYM));

	S="abc?de,fbc?,,,defa,\"as,d\",end,,";
   	printf("\n\n   012345678901234567890123456789");
	sp=-1; ep=-1; K1=",,"; K2=","; SYM="?\"";
  	printf("\nS='%s' [%2d]",(char*)S,(int)S);
    printf("\nS.GetRangeWithWdChgExSymBlk('%d','%d','%s','%s','%s')\n='%s'",sp,ep,(char*)K1,(char*)K2,(char*)SYM,S.GetRangeWithWdChgExSymBlk(sp,ep,(char*)K1,(char*)K2,(char*)SYM));

    exit(0);
}
