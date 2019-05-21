#include "iGraphics.h"
bool bg_music=true;
int lvl=0;
char c_array[5][100]={"c1.bmp","c2.bmp","c3.bmp","c4.bmp","c5.bmp"};
char digit_array[10][100]={"images\\0.bmp","images\\1.bmp","images\\2.bmp","images\\3.bmp","images\\4.bmp","images\\5.bmp","images\\6.bmp","images\\7.bmp","images\\8.bmp","images\\9.bmp"};
int i=0,cx=0,cy=450;
int sx=80,sy=450,ex=1000,ey=1000,insX=1000,insY=1000,hx=1000,hy=1000;
char instruction[300]={"!!!!!!!!!!! Welcome To Math Fun!!!!!!! \n"};
char instruction1[100]={"You Have to Solve 3 math for level up"};
int ins=0;
int score=0,rectangel=100;
bool check=false;
char w_c_array[7][100]={"w_c_1.bmp","w_c_2.bmp","w_c_3.bmp","w_c_4.bmp","w_c_5.bmp","w_c_6.bmp","w_c_7.bmp"};

int r, g, b;
int start=0;
int x1=10,x2=70,x3=140; 
int x4=00,x5=70,x6=140; 
int x7=0,x8=70,x9=140; 
int y123=300;
int y456=180;
int y789=60;
int x10=70,y10=420;
int digit=11;
int n,m,k;
int wrong=0,correct=0;

char high_score_show[100];
int h_s=0,rx=850,ry=600;

char score_print[20];
char lvl_print[20];

int sec=10,j=0,t=0;
int wx=1000,wy=1000;
int high_score=0;
int no_ans=1;
FILE *ptr;

void  high_score_print()
{
	///FILE *fp;
	ptr=fopen("high_score.txt","r");
	fgets(high_score_show,20,ptr);
	fclose(ptr);

}

void high_score_counter(int score)
{
	if(high_score<score)
		 {
        
		ptr=fopen("high_score.txt","w");
		fprintf(ptr,"%d",score);
		high_score=score;
		fclose(ptr);
		
		 }
	
}

void wrong_charecter()
{  
	if(wrong==1)
     {
	  wx=270;
      wy=300;
     }

     j++;
	
	if(j>=6)
	{
		j=0;	
	}
}

void charecter()
{ 
	
	if(start==0)
   {
	i++;
	cx+=6;
	if(i>=4)
	{   
		i=0;
	}
	
	if(cx>=280)
	{
		cx=1000;
		cy=1000;

	}
	if(sx<=350)
	{
	  sx+=6;
	}
	if(sx>=350 && cx>=280) 
	{
		start=1;
		cx=0;
		cy=320;
		insX=80;
		insY=320;
	}
}

if(start==1)
{
	i++;
	cx+=6;
	if(i>=4)
	{   
		i=0;
	}
	
	if(cx>=280)
	{
		cx=1000;
		cy=1000;

	}
	if(insX<=350)
	{
		insX+=6;
	}

	if(insX>=350 && cx>=280) 
	{
		start=2;
		cx=0;
		cy=210;
		hx=80;
		hy=210;
		
	}

}

if(start==2)
{
	i++;
	cx+=6;
	if(i>=4)
	{   
		i=0;
	}
	
	if(cx>=280)
	{
		cx=1000;
		cy=1000;

	}
	if(hx<=350)
	{
		hx+=6;
	}

	if(hx>=350 && cx>=280) 
	{
		start=3;
		cx=0;
		cy=100;
		ex=80;
		ey=100;
		
	}

}


if(start==3)
	{ 
	i++;
	cx+=6;
	if(i>=4)
	{   
		i=0;
	}
	
	if(cx>=280)
	{
		cx=1000;
		cy=1000;

	}
	if(ex<=350)
	{
	  ex+=6;
	}
	if(ex>=350 && cx>=280) 
	{
		start=4;
	//	cx=1000;
	//	cy=2500;
		
	}
		
	}
	
}

void color(){
	r = (rand() % 255) + 1;
	g = (rand() % 255) + 1;
	b = (rand() % 255) + 1;
	iSetColor(r, g, b);
}

void digitcheck(int digit)
{   
	int a=0;
	if(lvl==1)
	{
		a=m-n;
		if(digit==a)
		{
			check=true;
		}
		else
		{
			check=false;
		}
	}
	if(lvl==2)
	{
		a=n-m;
		if(digit==a)
		{
			check=true;
		}
		else
		{
			check=false;
		}

	}
	if(lvl==3)
	{
		a=((n*m)+k);
		if(digit==a)
		{
			check=true;
		}
		else
		{
			check=false;
		}
		
	}
	
}

void Timer()
{  
	if(no_ans==1)
   {
	if(lvl==1)
	{
	rectangel-=10;
	if(rectangel==0)
	  {
		  t=1;
		  no_ans=0;
	  }
	}
	if(lvl==2)
	{
	rectangel-=15;
	if(rectangel<=0)
	  { 
		  rectangel=0;
		  t=1;
		  no_ans=0;
	  }
	}
	if(lvl==3)
	{
	rectangel-=18;
	if(rectangel<=0)
	  { 
		  rectangel=0;
		  t=1;
		  no_ans=0;
	  }
	}
  }
}

void iDraw()
{
    if(lvl==0)
	{
	
	iShowBMP(0,0,"start_bg.bmp");

	iShowBMP2(cx,cy,c_array[i],0);

	iShowBMP(sx,sy,"play_button.bmp");
	iShowBMP(insX,insY,"info.bmp");
	iShowBMP(hx,hy,"high.bmp");
	iShowBMP(ex,ey,"exit_button.bmp");
	iSetColor(0,0,0);
	iText(370,560,"Math Fun",GLUT_BITMAP_TIMES_ROMAN_24);

	}

	if(h_s==1)
	{  
	    iShowBMP(0,0,"start_bg.bmp");
		iShowBMP(750,500,"back.bmp");
		iSetColor(0,0,0);
		iFilledRectangle(150,180,450,150);

		iSetColor(255,255,255);
		iText(190,220,"High Score: ",GLUT_BITMAP_TIMES_ROMAN_24);	
		iText(330,220,high_score_show,GLUT_BITMAP_TIMES_ROMAN_24);
		 	
	}
	if(ins==1)
	  {
         iClear(); 
		 iShowBMP(750,500,"back.bmp");
		 iSetColor(255,255,255);
		 iText(200,300,instruction,GLUT_BITMAP_TIMES_ROMAN_24);
		 iText(195,250,instruction1,GLUT_BITMAP_TIMES_ROMAN_24);

	  }
    if(lvl==1)
	{
		iShowBMP(0,0,"lvl_1_bg.bmp");
		iShowBMP(750,500,"back.bmp");	
		iShowBMP2(320,120,digit_array[n],0);
		iShowBMP2(450,150,"images\\Plus.bmp",0);
		iShowBMP2(600,120,"images\\equal.bmp",0);
		iShowBMP2(700,120,digit_array[m],0);


       if(t==1)
	   {
		   iShowBMP(350,300,"Time.bmp");
		  
	   }
		
		if(digit<10)
		{
			iShowBMP2(550,120,digit_array[digit],0);
			if(check==true)
			 {   	
			    ///iShowBMP2(400,150,"correct.bmp",0);
				correct=1;						
				iShowBMP2(650,350,"next.bmp",0);
			 }
			else
			{
				iShowBMP2(380,300,"sorry.bmp",0);
				wrong=1;
				iShowBMP2(wx,wy,w_c_array[j],0);
			}		
		}
		else 
		{
			iShowBMP2(450,70,"images\\qus.bmp",0);
		}

	}
	if(lvl==2)
	{   
		iShowBMP(0,0,"lvl_2_bg.bmp");
		iShowBMP(750,500,"back.bmp");
		iShowBMP2(320,120,digit_array[n],0);
		iShowBMP2(450,150,"images\\Minus.bmp",0);
		iShowBMP2(600,120,"images\\equal.bmp",0);
		iShowBMP2(700,120,digit_array[m],0);


       if(t==1)
	   {
		   iShowBMP(350,300,"Time.bmp");
	   }

		if(digit<10)
		{
			iShowBMP2(550,120,digit_array[digit],0);
			if(check==true)
			{   
			///	iShowBMP2(400,150,"correct.bmp",0);	
				correct=1;							
				iShowBMP2(650,350,"next.bmp",0);
			}
			else
			{   
				iShowBMP2(380,300,"sorry.bmp",0);
				iShowBMP2(wx,wy,w_c_array[j],0);
				wrong=1;								
			}
		}
		else 
		  {
			iShowBMP2(450,70,"images\\qus.bmp",0);
		  }

	}
	if(lvl==3)
	{   
		iShowBMP(0,0,"lvl_3_bg.bmp");
		iShowBMP(750,500,"back.bmp");
		iShowBMP2(300,120,digit_array[n],0);
		iShowBMP2(400,150,"images\\intu.bmp",0);
		iShowBMP2(450,120,digit_array[m],0);
		iShowBMP2(530,150,"images\\plus.bmp",0);
		iShowBMP2(570,120,digit_array[k],0);
		iShowBMP2(610,120,"images\\equal.bmp",0);


       if(t==1)
	   {
		   iShowBMP(350,300,"Time.bmp");
	   }


		if(digit<10)
		{
			iShowBMP2(750,120,digit_array[digit],0);
			if(check==true)
			{   
			///	iShowBMP2(400,150,"correct.bmp",0);	
				correct=1;							
				iShowBMP2(650,350,"next.bmp",0);
			}
			else
			{   
				iShowBMP2(380,300,"sorry.bmp",0);
				iShowBMP2(wx,wy,w_c_array[j],0);
				wrong=1;								
			}
		}
		else 
		  {
			iShowBMP2(650,70,"images\\qus.bmp",0);
		  }

	}
	if(lvl==4)
	{
		iClear();
		iShowBMP(750,500,"back.bmp");
		iSetColor(255,255,255);
		iText(300,300,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(r,g,b);
		iText(320,400,"You Won",GLUT_BITMAP_TIMES_ROMAN_24);


	}
	if(lvl>0 && lvl!=4)
	{
		
	    iShowBMP2(x1,y123,"images\\1.bmp",0);
		iShowBMP2(x2,y123,"images\\2.bmp",0);
		iShowBMP2(x3,y123,"images\\3.bmp",0);
		iShowBMP2(x4,y456,"images\\4.bmp",0);
		iShowBMP2(x5,y456,"images\\5.bmp",0);
		iShowBMP2(x6,y456,"images\\6.bmp",0);
		iShowBMP2(x7,y789,"images\\7.bmp",0);
		iShowBMP2(x8,y789,"images\\8.bmp",0);
		iShowBMP2(x9,y789,"images\\9.bmp",0);
		iShowBMP2(x10,y10,"images\\0.bmp",0);

		iSetColor(r,g,b);
		iRectangle(300,90,530,190);

		iSetColor(255,255,255);
		iText(644,550,score_print,GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(0,0,0);
		iFilledRectangle(200,530,135,50);
		iSetColor(255,255,255);
		iText(230,550,lvl_print,GLUT_BITMAP_TIMES_ROMAN_24);

		if(rectangel>40)
		 {
			iSetColor(0,255,0);
		 }
		 else 
		 {
			 iSetColor(255,0,0);
		 }
		iFilledRectangle(450,530,rectangel,15);
		iSetColor(255,255,255);
		iText(355,530,"Timmer: ",GLUT_BITMAP_TIMES_ROMAN_24);
		
		if(score==1 || score==4 || score==7)
		{   
			iSetColor(0,255,0);
			iFilledRectangle(200,530,45,15);
		}
		if(score==2  || score==5 || score== 8)
		{   
			iSetColor(0,255,0);
			iFilledRectangle(200,530,90,15);
		}
		if((score==3 && lvl==1) || (lvl==2 && score==6) || (lvl==3 && score==9)) 
		{   
			iSetColor(0,255,0);
			iFilledRectangle(200,530,135,15);
		}
		
	}

}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{  
	printf("\n%d %d\n",mx,my);
	
	if(lvl==0)
	{
	if((mx>=355 && mx<=475) && (my>=450 && my<=520))
	{  
		
		  lvl=1;
		  ///for eqation
		   digit=10;
		   n=rand()%5+1;
		   m=rand()%7+2;
	
		 if(n>m)
		  {
	     	n=rand()%5+1;
		    m=rand()%7+2;
		  }	
		
	}
	if((mx>=355 && mx<=475) && (my>= 210 && my<=280))
	{
		high_score_print();
		///sprintf(high_score_show,"High Score: %s\n",high_score_show);
		h_s=1;

	}
	if((mx>=355 && mx<=470) && ( my>=320 && my<=390))
	{
		ins=1;
	}
		
	if((mx>=355 && mx<=475)&& (my>=100 && my<=170))
	{	
		high_score_counter(score);
		exit(0);
	}
	
	}

	if((lvl ==1 || lvl == 2 || lvl == 3 || h_s==1 || ins==1 || lvl==4) && (correct!=1 && wrong!=1))
	{	
	/// for digit

	if((mx>=75 && mx<=135) && (my>=425 && my<=530) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=0;
		no_ans=0;
		digitcheck(digit);
		if(check==true)
		{		
			score = score+1;
			iShowBMP2(650,350,"next.bmp",0);
			printf("Score is : %d",score);			
		}
		else 
		{
			score = score-1;
		}

	}
	if((mx>=26 || mx>=45 )&& mx<=65 && (my>=305 && my<=395) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=1;
		no_ans=0;
		digitcheck(digit);
		if(check==true)
		{		
			score = score+1;
			printf("Score is : %d",score);
				   
		}
		else 
		{
			score = score-1;
		}
		
	}
	if((mx>=85 && mx<=145) && (my>=310 && my<=400)  && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=2;
		no_ans=0;
		digitcheck(digit);
		if(check==true)
		{		
			score = score+1;		
			printf("Score is : %d",score);	    
		}
		else 
		{
			score = score-1;
		}
		
	}
	if((mx>=153 && mx<=205) && (my>=315 && my<=403) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=3;
		no_ans=0;
		digitcheck(digit);
	  if(check==true)
		{		
			score = score+1;		
			printf("Score is : %d",score);	  
		}
	  else 
		{
			score = score-1;
		}

	}
	if((mx>=5 && mx<=75) && (my>=190 && my<285)  && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=4;
		no_ans=0;
	    digitcheck(digit);
		 if(check==true)
		{		
			score = score+1;
			printf("Score is : %d",score);				   
		}
		 else 
		{
			score = score-1;
		}
		
		
	}
	if((mx>=85 && mx<=140) && (my>=190 && my<=285) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=5;
		no_ans=0;
        digitcheck(digit);
		 if(check==true)
		{		
			score = score+1;	
			printf("Score is : %d",score);   
		}
		 else 
		{
			score = score-1;
		}
		
	}
	if((mx>=152 && mx<=203) && (my>=195 && my<=285) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=6;
		no_ans=0;
		digitcheck(digit);
		 if(check==true)
		{		
			score = score+1;		
			printf("Score is : %d",score);			
		}
		 else 
		{
			score = score-1;
		}
	
	}
	if((mx>=15 && mx<=75) && (my>=75 && my<=175) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=7;
		no_ans=0;
	    digitcheck(digit);
		 if(check==true)
		{		
			score = score+1;
			printf("Score is : %d",score);		
		}
		 else 
		{
			score = score-1;
		}
		
	}
	if((mx>=82 && mx<=136) && (my>=82 && my<=186) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=8;
		no_ans=0;
	    digitcheck(digit);
		 if(check==true)
		{		
			score = score+1;
			printf("Score is : %d",score);	
		}
		 else 
		{
			score = score-1;
		}
		
	}
	if((mx>=150 && mx<=210) && (my>=70 && my<=165) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		digit=9;
		no_ans=0;
		digitcheck(digit);
		 if(check==true)
		{		
			score = score+1;
			printf("Score is : %d",score);			
		 }
		 else 
		{
			score = score-1;
		}
		
	}
	
	if((mx>=750 && mx<=800) && (my>=500 && my<=550) && (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		
		high_score_counter(score);
		lvl=0;
		score=0;
		ins=0;
		h_s=0;
		t=0;
		digit=10;
		rectangel=100;
		
	 }
	if(t==1)
	{  
		if((mx>=445 && mx<=480) && (my>=360 && my<=380))
		{  t=0;
		   no_ans=1;
		   rectangel=100;
		   
			if(lvl==1)
			{
			digit=10;
	 	    n=rand()%5+1;
		    m=rand()%7+2;	   

		  if(n>m)
		  {
	     	n=rand()%5+1;
		    m=rand()%7+2;
			if(n>m)
		  {
	     	n=rand()%5+1;
		    m=rand()%7+2;
		  }	

			}

		  }
			if(lvl==2)
			{
                 digit=10;
	 	         n=rand()%7+2;
		         m=rand()%5+1;

		   if(m>n)
		    {
	        	n=rand()%7+2;
		        m=rand()%5+1;
			if(m>n)
			   {
		     	n=rand()%7+2;
		        m=rand()%5+1;
			   }
		     }	
		   }
			if(lvl==3)
			{
				 digit=10;
	 	         n=rand()%3+1;
		         m=rand()%2+1;
		         k=rand()%2+2;
			}

	   }

	if((mx>=570 && mx<=600) &&(my>=360 && my<=380))
	{
		    high_score_counter(score);
			lvl=0;
			digit=10;
			score=0;
			t=0;
			rectangel=100;
			no_ans=1;
	}

	 }
	}
	///level 1 random
	if(lvl==1 && correct==1)
	{
		if(mx>650 && mx<750 && my>350 && my<400)
		{ 
		   rectangel=100;
			no_ans=1;
	       digit=10;
	 	   n=rand()%5+1;
		   m=rand()%7+2;	   

		  if(n>m)
		  {
	     	n=rand()%5+1;
		    m=rand()%7+2;
			if(n>m)
		  {
	     	n=rand()%5+1;
		    m=rand()%7+2;
		  }	
		  }	
		  
		 if(score==3)
		  {  
		   digit=10;
	 	   n=rand()%7+2;
		   m=rand()%5+1;

		  if(m>n)
		  {
	     	n=rand()%7+2;
		    m=rand()%5+1;
			if(m>n)
		  {
	     	n=rand()%7+2;
		    m=rand()%5+1;
		  }	
		  }	
			  lvl++;
		  }
			correct=0;
		  }
	     
	}

	if(lvl==1 && wrong==1)
	{
		if((mx>400 && mx<460) && (my>320 && my<350))
		{  	
		   rectangel=100;
			no_ans=1;
		   digit=10;
		   n=rand()%5+1;
		   m=rand()%7+2;

		  if(n>m)
		  {
	     	n=rand()%5+1;
		    m=rand()%7+2;
		  }	
		  wrong=0;
		}
		else if((mx>=605 && mx<=635) && (my>320 && my<350))
		{
	       rectangel=100;
			no_ans=1;
			high_score_counter(score);
			lvl=0;
			digit=10;
			score=0;
		}

	}

    if(lvl==2 && correct==1)
	{
		if(mx>650 && mx<750 && my>350 && my<400)
		{
		   rectangel=100;
			no_ans=1;
	       digit=10;
	 	   n=rand()%7+2;
		   m=rand()%5+1;

		  if(m>n)
		  {
	     	n=rand()%7+2;
		    m=rand()%5+1;
			if(m>n)
			{
			n=rand()%7+2;
		    m=rand()%5+1;
			}
		  }	
		  
		 if(score==6)
		  {
			 rectangel=100;
			no_ans=1;
		   digit=10;
	 	   n=rand()%3+1;
		   m=rand()%2+1;
		   k=rand()%2+2;

			  lvl++;
		  }
     		correct=0;
		  }
	     
	  }

	if(lvl==2 && wrong==1)
	{
		if((mx>400 && mx<460) && (my>320 && my<350))
		{  
		   rectangel=100;
			no_ans=1;
		   digit=10;
		   n=rand()%7+2;
		   m=rand()%5+1;

		  if(m>n)
		  {
	     	n=rand()%7+2;
		    m=rand()%5+1;
		  }	
		  wrong=0;
		}

		if(mx>605 && mx<640 && my>320 && my<350)
		{
			high_score_counter(score);
			lvl=0;
			digit=10;
			score=0;
			
		}

	}

	///lvl=3
		if(lvl==3 && correct==1)
	{
		if(mx>650 && mx<750 && my>350 && my<400)
		{ 
			rectangel=100;
			no_ans=1;
	       digit=10;
	 	    n=rand()%3+1;
		   m=rand()%2+1;
		   k=rand()%2+2;  
		  
		 if(score==9)
		  { 
			rectangel=100;
			no_ans=1;
		   digit=10;
	 	   lvl++;
		  }	
		
			correct=0;
		  }
	     
	}

	if(lvl==3 && wrong==1)
	{
		if((mx>400 && mx<460) && (my>320 && my<350))
		{  		
			rectangel=100;
			no_ans=1;
		   digit=10;
		   n=rand()%3+1;
		   m=rand()%2+1;
		   k=rand()%2+2;  
		  
		  wrong=0;
		}
		else if((mx>=605 && mx<=635) && (my>320 && my<350))
		{
	
			high_score_counter(score);
			lvl=0;
			digit=10;
			score=0;
		}

	}


	sprintf(score_print,"Score : %d",score);
	sprintf(lvl_print,"Level : %d",lvl);
	
	if(lvl==4)
	{
		 PlaySound("Music\\wow",NULL,SND_LOOP||SND_ASYNC);
	}
	
	if(t==0 && lvl==1)
	{
		 PlaySound("Music\\clock_lvl_1",NULL,SND_ASYNC);
		 
	}
	if(t==0 && lvl==2)
	{
		 PlaySound("Music\\clock_lvl_2",NULL,SND_ASYNC);
		 
	}
	if(t==0 && lvl==3)
	{
		 PlaySound("Music\\clock_lvl_3",NULL,SND_ASYNC);
		 
	}

///for back and reset

	if(wrong==1)
	     {
		   PlaySound("Music\\wrong",NULL,SND_LOOP||SND_ASYNC);
		   wrong=0;
		   
	     }
	if(correct==1)
	     {
		   PlaySound("Music\\Correct_Answer",NULL,SND_LOOP||SND_ASYNC);
		   correct=0;	   
	     }

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	    {   
		PlaySound("Music\\button_click", NULL, SND_ASYNC);	
    	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	   {
		PlaySound("Music\\button_click", NULL,  SND_ASYNC);	
	    }

		
 }

void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		bg_music=true;
		PlaySound("Music\\Faded_bg_music", NULL, SND_LOOP | SND_ASYNC);
	}
	
	if(key == 'o')
	{
		bg_music=false;
		PlaySound(0,0,0);
	}

}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

int main()
{   
	iSetTimer(100,color);
	iSetTimer(50, charecter);
	iSetTimer(1000,Timer);
	
	iSetTimer(400,wrong_charecter);

	if(bg_music == true)
	{
    PlaySound("Music\\Faded_bg_music", NULL, SND_LOOP | SND_ASYNC);
	}
	
	iInitialize(850, 600, "Math for Fun");

	return 0;
}	