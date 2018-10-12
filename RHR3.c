/* Study Guide CST 100 Exam 2
 * File:   CST100Exam3.c
 * Author: rrucker
 *
 * Created on November 21, 2010, 2:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*The exam, which consists of running code (hopefully :-) ),
 *  is set n the context of calculating correlation coefficients
 * between centered vectors, as we have been doing for several class
 * periods. Again, we will use data from vehicle trials.
 * I will supply that data which you will use to manually'
 * create an external data file.
 * The only new part is reading in the data from this  external file.
 * I have shown how to do this below:
 * **************** Instructions for the Exam*****
 * Create a new C/C++ project and name the main file,
 * prefixed with your initials, and then the string Exam3
 * For my file it would be:
 * RHRExam3.c
 * provide identification as to name, date,  and class as well.
 *
 * At the top of your output,before  you
 * show calculation code,
 * write out  several identifying printf line
 * describing what is to be accomplished.
 *
 * Declare a struct, named CarCorrelation that has three components:
 * name, a character string of 30,
 * ageMpg matrix , a double  array  with the first row being
 * a row of median car ages, and the  second row a set of median
 * miles per gallon for that age of car.
 *
 *
 *
 *
 * Manually create a file in your project directory named:
 * numbers.txt
 * that has two rows of  doubles.
 * (I will give you this files data, but until then practice with maybe
 * 4 or 5 values for each row.
 * This is the file your program must read into age
 * and mpg. The first row goes into age while the second row
 * goes into mpg. See below for guidance on the read.
 * The exam will assume you can construct a file like the one I have
 * and then read it into a struct as exemplified.
 * NOTE: carefully the formatting code, especially 'Lf'.
 * Once in the struct do the following:
 * a. write a function to calculate the average
 * b. write a function to calculate the centered vectors
 * c. write a function(s) to calculate the  correlation coefficient
 * d. Write a comment describing what that coefficient tells you. Remamber
 * r lies between -1 and +1. What does a negative r mean?
 *
 * When the exam is done, paste your output to the main file and email me.
 *
 */
struct CarCorrelation
{
    char name[30]; // identifier of dataset
    double ageMpg[2][5]; // median age of cars in the experiement
    int rowLength; // number of row ( this will be '2' for this exam)
    //in statistics there would usually be multiple rows expressing
    //inter- correlations, resulting in a correlation/covariance matrix.
    int colLength;// number of columns
};

int main(void)
{
    struct CarCorrelation data=   // instance of the struct,named 'data'
    {
     "car data",  // identifier
     {}, // to be filled in by reading age and mpg from file
     2,  // number of rows
     5, //number of columns
    };
    char fileName[30]= "numbersX.txt";
    FILE *fp = fopen(fileName, "r");
    if (fp==NULL)
    { printf("can't open file  %s for reads!! \n", fileName);
        exit(1);// abort
    }
    //NOTE: I know I only have to read 2 rows but data.length columns
    //can vary depending on supplied data
    int rowIndex;
    int colIndex;

    for(rowIndex=0; rowIndex<data.rowLength; rowIndex +=1)
    {
    for(colIndex=0; colIndex<data.colLength; colIndex+=1)
    {
    fscanf(fp,"%lf" ,&data.ageMpg[rowIndex][colIndex]);
    printf("ageMpg[%d][%d] = %6.2lf \n" ,
        rowIndex, colIndex, data.ageMpg[rowIndex][colIndex]);
    }//end colIndex for 
    }//end rowIndex for
    fclose(fp);
    return (0);
}

/* My results from reading a two rows of an external file, numbersX.txt
 ageMpg[0][0] =   1.00
ageMpg[0][1] =   2.00
ageMpg[0][2] =   2.00
ageMpg[0][3] =   4.00
ageMpg[0][4] =   5.00
ageMpg[1][0] =  10.00
ageMpg[1][1] =  20.00
ageMpg[1][2] =  40.00
ageMpg[1][3] =  60.00
ageMpg[1][4] =  55.00
Press [Enter] to close the terminal ...
*/
