#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void one();
void two();
void fri();
void main(){
	int a;
	scanf("%d",&a);
	switch(a){
	case 1:
	    one();
	    break;
	case 2:
	    two();
	    break;
	case 3:
		fri();
		break;
	default:
	 printf("no");
	}
}
void one(){
	int a,i;
	FILE *f;
	int *p;
	scanf("%d",&a);
	int c[2];
	p=(int*)malloc(a*sizeof(int));
	srand(time(NULL));
	for (i=0;i<a;i++){
	    p[i]=rand();
	  }
	f=fopen("C:cr.txt","w");
		fprintf(f,"1");
		fprintf(f,"%d",a);
		fclose(f);
	f=fopen("C:cr.txt","w+b");
	c[1]=a;
	c[0]=1;
	fwrite(&c[0], sizeof(int*),1,f);
	fwrite(&c[1], sizeof(int*),1,f);
	for (i=0;i<a;i++){
		fwrite(p, sizeof(int*),1,f);
		p++;
	}
	fclose(f);
	free(p);
}
void two(){
	int a,i,j,b;
	FILE *f;
	int *p;
	int c;
	scanf("%d",&a);
	scanf("%d",&b);
	p=(int*)malloc(a*b*sizeof(int));
	srand(time(NULL));
	for (j=0;j<a;j++){
		for (i=0;i<b;i++){
	        p[j*a+i]=rand();
		}
	  }
	f=fopen("C:cr.txt","w");
	fprintf(f,"2");
	fprintf(f,"%d",a);
	fprintf(f,"%d",b);
	fclose(f);
	f=fopen("C:cr.txt","w+b");
	for (j=0;j<a;j++){
			for (i=0;i<b;i++){
				fwrite(p, sizeof(int*),1,f);
				p++;
			}
		  }
	fclose(f);
	free(p);
}
void fri(){
    int x,y,z,i,j,k;
    FILE *f;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    int *p;
    p=(int*)malloc(x*y*z*sizeof(int));
	f=fopen("C:cr.txt","w+b");
	srand(time(NULL));
	for (i = 0; i < x; i++) {
			    for (j = 0; j < x; j++) {
			    	for (k = 0; k< x;k++){
			    		p[i*x*y+j*x+k]=rand();
			    }
			   }
			}
	f=fopen("C:cr.txt","w");
	fprintf(f,"3");
	fprintf(f,"%d",x);
	fprintf(f,"%d",y);
	fprintf(f,"%d",z);
	fclose(f);
	for (i = 0; i < x; i++) {
		    for (j = 0; j < x; j++) {
		    	for (k = 0; k< x;k++){
		    	fwrite(p, sizeof(int**),1,f);
		    }
		    }
		}
	fclose(f);
	free(p);
}
