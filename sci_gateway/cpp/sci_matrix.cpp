#include <string>
#include "wchar.h"
#include <cstdlib>
//#include <ctype.h>
extern "C"
{
#include<Scierror.h>
#include<sciprint.h>
#include<api_scilab.h>
#include "localization.h"
#include "fun.h"
#include <cstdio>
#include <math.h>
#include <stdio.h>
#include "os_string.h"



static const char fname[] = "octave_fun";
///////#####call octave_fun([2],"hamming") ########////////////
int sci_octave_fun(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{
	if (nin < 4)
    {
        Scierror(999, _("%s: Wrong number of input arguments: %d expected.\n"), fname, 4);
        return STATUS_ERROR;
    }
	//	printf("Number of Input Args are %d\n",nin);
/*
int typ=0;
	for(int i=1;i<nin+1;i++)
		{
			typ = scilab_getType(env, in[i-1]);
			printf("Type of input %d is: %d\n",i,typ);
		}
printf("%s\n","1 - sci_matrix: a matrix of doubles");
printf("%s\n","10 - sci_strings: a matrix of strings");
printf("%s\n", "=================================");

*/

/*
	printf("%d\n", nin);
	int row = 0;
  int col = 0;
  int size = 0;
	size = scilab_getDim2d(env, in[0], &row, &col);
	printf("%d\n", row);
	printf("%d\n", col);
	int i=3;
*/

	octf ins;

	octf *inptr = &ins;
///////////////////First Input/////////////////////	
	if(scilab_getType(env, in[0])==1)
	{
		double* n = NULL;
		int row1 = 0;
		int col1 = 0;
		int size1 = 0;
		size1 = scilab_getDim2d(env, in[0], &row1, &col1);
		scilab_getDoubleArray(env, in[0], &n);

			int dim1 = row1*col1;
			ins.input1 = new double[dim1];
			ins.size_input1[1]=row1;
			ins.size_input1[2]=col1;

			for(unsigned int i=0; i<size1; i++)
			{
				ins.input1[i] = n[i];//.float_value();
			}
		}
		else
		{
			Scierror(999, _("%s: Wrong type for input argument #%d: A double expected.\n"), fname, 1);
        return STATUS_ERROR;
		}
///////////////////Second Input/////////////////////	
	if(scilab_getType(env, in[1])==1)
	{
		double* n2 = NULL;
		int row2 = 0;
		int col2 = 0;
		int size2 = 0;
		size2 = scilab_getDim2d(env, in[1], &row2, &col2);
		scilab_getDoubleArray(env, in[1], &n2);

		int dim2 = row2*col2;
		ins.input2 = new double[dim2];
		ins.size_input2[1]=row2;
		ins.size_input2[2]=col2;

			for(unsigned int i=0; i<size2; i++)
			{
				ins.input2[i] = n2[i];//.float_value();
			}
		}
		else
		{
			Scierror(999, _("%s: Wrong type for input argument #%d: A double expected.\n"), fname, 2);
        return STATUS_ERROR;
		}
///////////////////Third Input/////////////////////	
	if(scilab_getType(env, in[2])==1)
	{
		double* n3 = NULL;
		int row3 = 0;
		int col3 = 0;
		int size3 = 0;
		size3 = scilab_getDim2d(env, in[2], &row3, &col3);
		scilab_getDoubleArray(env, in[2], &n3);

		int dim3 = row3*col3;
		ins.input3 = new double[dim3];
		ins.size_input3[1]=row3;
		ins.size_input3[2]=col3;

			for(unsigned int i=0; i<size3; i++)
			{
				ins.input3[i] = n3[i];//.float_value();
			}
		}
		else
		{
			Scierror(999, _("%s: Wrong type for input argument #%d: A double expected.\n"), fname, 3);
        return STATUS_ERROR;
		}

////////////////Fourth Input/////////////////////
	if(scilab_getType(env, in[3])==10)
	{
		wchar_t* in2 = 0;

		char str2[20];
		if (scilab_isString(env, in[3]) == 0)
			{
			  Scierror(999, _("%s: Wrong type for input argument #%d: A String expected.\n"), fname, 4);
			    return STATUS_ERROR;
			}
		else
			{
				scilab_getString(env, in[3], &in2);
				//printf("%S\n", in1);

				 wcstombs(str2, in2, sizeof(str2));
				//printf("%s\n", str);
				if(str2)
					ins.name1 = str2;
			}
		}
		else
		{
			Scierror(999, _("%s: Wrong type for input argument #%d: A String expected.\n"), fname, 4);
        return STATUS_ERROR;
		}

////////////////Fifth Input/////////////////////
if(nin<5)
{
	//printf("Here1----------------");
	ins.package = NULL;
}
else
{
//printf("Here2----------------");
		wchar_t* in4 = 0;

		char str3[20];

			if (scilab_isString(env, in[4]) == 0)
				{	
					//printf("Here----------------");
					ins.name2 = NULL;
					Scierror(999, _("%s: Wrong type for input argument #%d: An Octave function name expected.\n"), fname, 4);

					return STATUS_ERROR;
				}
			else
				{
					scilab_getString(env, in[4], &in4);
					//printf("%S\n", in1);

					wcstombs(str3, in4, sizeof(str3));
					//printf("%s\n", str);
//					if(!*str3)
						ins.package = str3;
//					else
//						ins.name2 = NULL;
				}


}

/*
////////////////optional Input/////////////////////
	wchar_t* in1 = 0;

	char str[20];
	if (scilab_isString(env, in[1]) == 0)
    {
      Scierror(999, _("%s: Wrong type for input argument #%d: A String expected.\n"), fname, 2);
        return STATUS_ERROR;
    }
	else
		{
			scilab_getString(env, in[1], &in1);
			//printf("%S\n", in1);

			 wcstombs(str, in1, sizeof(str));
			//printf("%s\n", str);
			if(str)
				ins.package = str;
		}
*/

//if (nin != 0)
//    {
//        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 1);
//        return 1;
//    }


if (nout > 2)
    {
        Scierror(77, _("%s: Wrong number of output argument(s). Maximum %d expected\n"), fname, 2);
        return 1;
    }

		


		int status_fun = fun(inptr);
	if(status_fun==1)
	{
		return 1;
	}
	else
	{	
		////////////////////First Output////////////////////	
 		int out_row1 = ins.size_output1[1];
		int out_col1 = ins.size_output1[2];
		int out_dim1 = out_row1 * out_col1;
		out[0] = scilab_createDoubleMatrix2d(env, out_row1, out_col1, 0);

		double* out1 = NULL;
   	scilab_getDoubleArray(env, out[0], &out1);

		for(unsigned int i=0; i<out_dim1; i++)
		{
			out1[i] = ins.output1[i];//.float_value();
		}
		////////////////////Second Output////////////////////	
 		int out_row2 = ins.size_output2[1];
		int out_col2 = ins.size_output2[2];
		int out_dim2 = out_row2 * out_col2;
		//printf("out_row2 is: %d\n", out_row2);
		//printf("out_col2 is: %d\n", out_col2);
		//printf("no of outputs is: %d\n", ins.out_count);
		if(nout==2)
		{
			if((out_row2>0 && out_col2>0))
			{
				//printf("Generating second output---------\n");
				out[1] = scilab_createDoubleMatrix2d(env, out_row2, out_col2, 0);

				double* out2 = NULL;
			 	scilab_getDoubleArray(env, out[1], &out2);

				for(unsigned int i=0; i<out_dim2; i++)
				{
					out2[i] = ins.output2[i];//.float_value();
				}
					//free(ins.output2);
					delete ins.output2;
			}
			else
			{
				Scierror(77, _("%s: Wrong number of output argument(s): Maximum %d expected \n"), fname, 1);
		      return 1;
			}
		}
/*		free(ins.output1);
		free(ins.input1);
		free(ins.input2);
		free(ins.input3);*/
		delete ins.output1;
		delete ins.input1;
		delete ins.input2;
		delete ins.input3;
	}

    return 0;
}
}
