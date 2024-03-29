
#include<Scierror.h>
#include<sciprint.h>
#include<api_scilab.h>
#include "localization.h"
#include "fun.h"
#include <stdio.h>
#include <math.h>

static const char fname[] = "octave_fun";

int sci_octave_fun(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{
double retval;
double* out1 = NULL;
   
if (nin != 0)
    {
        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 2);
        return 1;
    }

if (nout != 1)
    {
        Scierror(77, _("%s: Wrong number of output argument(s): %d expected.\n"), fname, 1);
        return 1;
    }
		*out = scilab_createDoubleMatrix2d(env, 1, 1, 5);
    fun(&retval);
		printf("%f\n", retval); 
		*out1 = retval;
   	scilab_getDoubleArray(env, out[0], &out1);



    return 0;
}
