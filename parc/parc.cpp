//Solutie ciurdita
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

void scufundare(int p, int a[2][10000],int n)
{	int pozmax=p;
	if (2*p<=n && a[0][pozmax]<a[0][2*p]) pozmax=2*p;
	if (2*p+1<=n && a[0][pozmax]<a[0][2*p+1]) pozmax=2*p+1;
	if (p!=pozmax)
	{	swap(a[0][p],a[0][pozmax]);
		swap(a[1][p],a[1][pozmax]);
		scufundare(pozmax,a,n);
	}
}

ofstream os ("parc.out");

void heapsort(int a[2][10000],int n)      // pistele de biciclete le sortez in ordine crescatoare
{	int i;
	for (i=n/2;i>=1;--i)
		scufundare(i,a,n);
	for (i=n;i>1;--i)
	{	swap(a[0][1],a[0][i]);
		swap(a[1][1],a[1][i]);
		scufundare(1,a,i-1);
	}
}

int main()
{	int pv[2][10000],po[2][10000],xp,yp,xg,yg,xpr,ypr,m,n,i,j,p2,sv[10000],so[10000];
	int startv, finishv,starto,finisho,xinv=0,yinv=0,d_oriz,d_vert,cx,cy,semnx=1,semny=1;
	int kx,ky,segmx[10000],segmy[10000];
	double lung;
	freopen("parc.in","r",stdin);

	scanf("%d %d\n",&xp,&yp);
	scanf("%d %d %d %d\n",&xg,&yg,&xpr,&ypr);
	if (xpr<xg)    // voi prelucra doar un singur caz: cand gigel este in stanga-jos
	{	xinv=1;       // iar prietenul este in dreapta-sus
		xg=xp-xg;    //pentru a rezolva acest lucru, voi folosi simetrii pe OX si OY daca este necesar
		xpr=xp-xpr;
		semnx=-1;
	}
	if (ypr<yg)
	{	yinv=1;
		semny=-1;
		yg=yp-yg;
		ypr=yp-ypr;
	}
	if (xpr==xg)
	{
	    os << ypr-yg << "\n1";
		return 0;
	}
	if (ypr==yg)
	{
	    os << xpr-xg << "\n1";
		return 0;
	}
	scanf("%d\n",&m);
	if (xinv)
		for (i=1;i<=m;++i)
		{	scanf("%d %d\n",&pv[0][i],&pv[1][i]);
			if (pv[0][i]<pv[1][i]) swap(pv[0][i],pv[1][i]);
			pv[0][i]=xp-pv[0][i];                           // citesc pistele verticale (x-urile) si daca e nevoie
			pv[1][i]=xp-pv[1][i];                           // transform in simetricul lor sa le prelucrez de la st. da dr.
		}
	else
		for (i=1;i<=m;++i)
		{	scanf("%d %d\n",&pv[0][i],&pv[1][i]);
			if (pv[0][i]>pv[1][i]) swap(pv[0][i],pv[1][i]);
		}
	heapsort(pv,m);                           // sortez punctele in ordine crescatoare
	scanf("%d\n",&n);
	if (yinv)
		for (i=1;i<=n;++i)
		{	scanf("%d %d\n",&po[0][i],&po[1][i]);            // citesc pistele orizontale (y-urile) si daca e nevoie
			if (po[0][i]<po[1][i]) swap(po[0][i],po[1][i]);  // le transform in simetricul lor sa le parcurg de jos in sus
			po[0][i]=yp-po[0][i];
			po[1][i]=yp-po[1][i];
		}
	else
		for (i=1;i<=n;++i)
		{	scanf("%d %d\n",&po[0][i],&po[1][i]);
			if (po[0][i]>po[1][i]) swap(po[0][i],po[1][i]);
		}
	heapsort(po,n);                           // sortez punctele in ordine crescatoare
	sv[0]=0;
	for(i=1;i<=m;++i)
		sv[i]=sv[i-1]+pv[1][i]-pv[0][i];       // memorez grosimile pistelor, ca si sume partiale
	so[0]=0;
	for(i=1;i<=n;++i)
		so[i]=so[i-1]+po[1][i]-po[0][i];       //  idem

	startv=1;
	while (xg>pv[0][startv]) ++startv;        // ma uit cate piste verticale sunt intre Gigel si prietenul lui
	finishv=m;
	while (xpr<pv[1][finishv]) --finishv;

	starto=1;
	while (yg>po[0][starto]) ++starto;       // ma uit cate piste orizontale sunt intre Gigel si prietenul lui
	finisho=n;
	while (ypr<po[1][finisho]) --finisho;
	d_oriz=sv[finishv]-sv[startv-1];         // grosimea pistelor verticale
	d_vert=so[finisho]-so[starto-1];         // grosimea pistelor verticale
	cx=xpr-xg-d_oriz;               // cea mai scurta distanta dintre doua puncte se calculeaza dintr-un triunghi
	cy=ypr-yg-d_vert;                  // dreptunghic cu catele cx si cy
		//cx si cy reprezinta lungimile catetelor triunghiului dreptunghic fara pistele orizontale si verticale
	lung = sqrt((float)(cx*cx+cy*cy))+d_oriz+d_vert;    // la lungimea ipotenuzei se adauga distantele orizontale si verticale

	segmx[0] = pv[0][startv] - xg;
	kx = 0;
	for (i = startv+1; i <= finishv; ++i)
	{
	    ++kx;
		segmx[kx] = segmx[kx-1] + pv[0][i] - pv[1][i-1];
	}
	segmy[0] = po[0][starto] - yg;
	ky = 0;
	for (i = starto+1; i <= finisho; ++i)
	{
	    ++ky;
		segmy[ky] = segmy[ky-1] + po[0][i] - po[1][i-1];
	}

	p2=1;
	i=j=0;
	while(i<=kx && j<=ky)
		if (segmx[i]*cy==segmy[j]*cx)
		{	p2*=2;
			++i;++j;
		}
		else
			if (segmx[i]*cy>segmy[j]*cx)
				++j;
			else
				++i;
    os << fixed << setprecision(6) << lung << '\n';
	os << p2;
	return 0;
}
