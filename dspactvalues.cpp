#include "dspactvalues.h"


cDspActValues::cDspActValues()
{
}


cDspActValues cDspActValues::operator = (cDspActValues dspVals)
{
    cDspActValues tmpVals;

    tmpVals.kfkorrf = dspVals.kfkorrf;
    tmpVals.rmsnf = dspVals.rmsnf;
    tmpVals.ampl1nf = dspVals.ampl1nf;
    tmpVals.rmsxf = dspVals.rmsxf;
    tmpVals.ampl1xf = dspVals.ampl1xf;
    tmpVals.dphif = dspVals.dphif;
    tmpVals.tdsync = dspVals.tdsync;
    tmpVals.phin = dspVals.phin;
    tmpVals.phix =dspVals.phix;

    return tmpVals;
}
