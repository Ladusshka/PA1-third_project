#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct
{
  int m_TotalDays;
  int m_WorkDays;
} TResult;
#endif /* __PROGTEST__ */

  int visokosny(int y){
    if((y%4==0 && y%100!=0) || (y%4==0 && y%400==0) ){return 1;}
    else{return 0;}
         
    }

  

    int prazdniny(int d, int m) 
    {
        if((d==1 && m ==5)||(d==8 && m ==5)||(d==5 && m ==7)||(d==6 && m ==7)||(d==28 && m ==9)||(d==28 && m ==10)||(d==17 && m ==11)||(d==24 && m ==12)||(d==25 && m ==12)||(d==26 && m ==12)||(d==1 && m ==1))
        {
            return 1;}
        else{
                return 0;}
    }
    int dnimesyaca(int m, int y){
        int days[12]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m==1 && visokosny(y)){
            return 29;}
        else{
            return days[m];}
    }
    int daysOfWeek(int d, int m, int y){
        if(m==1 || m==2){
            m+=12;
            y--;
        }
        int number = (d+((31*(m-2))/12)+y%100+((y%100)/4)+((y/100)/4)-2*(y/100))%7;
        if(!(number>=0)){number+=7;}
        return number;
    }

 
    int numOfDay (int y, int m, int d) {
       if (m==1||m==2)
        {
            
            m+=12; 
            y--;
            
        };
       int result = (d+((13*(m+1))/5) + y + y/4 - (y/100) + (y/400))%7;
       if(result<0) result+=7;
       return result;
    }
      
    int spravnyvstup(int y, int m, int d){
        if( (m<1 || m>12) || d>dnimesyaca(m-1,y) || d<1 || y<2000 ){return 0;}
            else{return 1;}
    }

  bool isWorkDay ( int y, int m, int d )
{
    if (!spravnyvstup ( y,  m,  d)) 
    {
        return 0;
    }
    if(prazdniny(d,m))
    {
        return 0;
    }
    int res=numOfDay ( y,  m,  d);

    if (res==0 || res==1) 
    {
        return 0;
    }
    else{return 1;}

}

   void counter_counteru(int*bebra, int*bebra2,int y1, int m1, int d1, int y2, int m2, int d2 )
    {
            while(!(y1==y2 && m1==m2 && d1==d2))
        {
            if(isWorkDay(y1,m1,d1) )
                 {
                    (*bebra2)++;
                 }
            
            if(d1 == dnimesyaca(m1-1,y1) ){m1++; d1=0;}
            if(m1==13){y1++; d1=0;m1=1;}
            d1++;
            (*bebra)++;
            

        }
    }
    TResult countDays(int y1, int m1, int d1, int y2, int m2, int d2){
        TResult result;
        result.m_TotalDays = 0;
        result. m_WorkDays =0;


        int counter=1;
        int counter2;

        if(!spravnyvstup(y1,m1,d1) || !spravnyvstup(y2,m2,d2))
        {
             result.m_TotalDays = -1;
             result.m_WorkDays =-1;
            return result;
        }
        if(y2<y1 || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
        {
            result.m_TotalDays = -1;
            result.m_WorkDays =-1;
            return result;
        }



       if(!isWorkDay(y2,m2,d2) )
        {
            counter2 =0;
        }
        else{counter2=1;}



        counter_counteru(&counter, &counter2, y1,m1,d1,y2,m2,d2 );
    
        result.m_TotalDays = counter;
        result.m_WorkDays =counter2;
        return result;


}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TResult r;

  assert ( isWorkDay ( 2023, 10, 10 ) );

  assert ( ! isWorkDay ( 2023, 11, 11 ) );

  assert ( ! isWorkDay ( 2023, 11, 17 ) );

  assert ( ! isWorkDay ( 2023, 11, 31 ) );

  assert ( ! isWorkDay ( 2023,  2, 29 ) );

  assert ( ! isWorkDay ( 2004,  2, 29 ) );

  assert ( isWorkDay ( 2008,  2, 29 ) );

  assert ( ! isWorkDay ( 2001,  2, 29 ) );

  assert ( ! isWorkDay ( 1996,  1,  2 ) );

  r = countDays ( 2023, 11,  1,
                  2023, 11, 30 );
  assert ( r . m_TotalDays == 30 );
  assert ( r . m_WorkDays == 21 );

  r = countDays ( 2023, 11,  1,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 17 );
  assert ( r . m_WorkDays == 12 );

  r = countDays ( 2023, 11,  1,
                  2023, 11,  1 );
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 1 );

  r = countDays ( 2023, 11, 17,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 0 );

  r = countDays ( 2023,  1,  1,
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 365 );
  assert ( r . m_WorkDays == 252 );

  r = countDays ( 2024,  1,  1,
                  2024, 12, 31 );
  assert ( r . m_TotalDays == 366 );
  assert ( r . m_WorkDays == 254 );

  r = countDays ( 2000,  1,  1,      
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 8766 );
  assert ( r . m_WorkDays == 6072 );

  r = countDays ( 2001,  2,  3,
                  2023,  7, 18 );
  assert ( r . m_TotalDays == 8201 );
  assert ( r . m_WorkDays == 5682 );

  r = countDays ( 2021,  3, 31,
                  2023, 11, 12 );
  assert ( r . m_TotalDays == 957 );
  assert ( r . m_WorkDays == 666 );

  r = countDays ( 2001,  1,  1,
                  2000,  1,  1 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );

  r = countDays ( 2001,  1,  1,
                  2023,  2, 29 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );
  
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
