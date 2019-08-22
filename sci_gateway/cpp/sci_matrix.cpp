
extern "C"
{
#include<Scierror.h>
#include<sciprint.h>
#include<api_scilab.h>
#include "localization.h"
#include<fun.h>

static const char fname[] = "octave_fun";

int sci_octave_fun(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{
   
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

		//int x = fun();
		//typename (x);
		double x = fun();
		//sciprint("%f\n", fun());

		
		out[0] = scilab_createDouble(env, x);

		//out[0] = scilab_createDoubleMatrix(env, 20, 1, 0);
    //scilab_getDoubleArray(env, out[0], &x);

    return 0;
}
}
