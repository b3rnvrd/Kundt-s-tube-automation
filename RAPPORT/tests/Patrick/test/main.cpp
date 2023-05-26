#include <iostream>
#include "visa.h"
using namespace std;

int main()
{
        // open resource manager
        ViSession rscmng;
        ViStatus stat = viOpenDefaultRM(&rscmng);

        // search for the oscilloscope
        ViChar viFound[VI_FIND_BUFLEN];
        ViUInt32 nFound;
        ViFindList listOfFound;
        stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);

        // connect to the oscilloscope
        ViSession osc;
        stat = viOpen(rscmng, viFound, VI_NULL, VI_NULL, &osc);
       // if (stat < VI_SUCCESS) qDebug() << "failed";

        // communicate
        viPrintf(osc, (ViString)"*IDN?\n");     /* Send an *IDN? string to the device */
        char buf[256] = {0};
        viScanf(osc,(ViString)"%t",&buf);       /* Read results */
       // qDebug()<<buf;
        //qDebug()<<stat;

        /* Open session to GPIB device at address 11 */
        ViSession vi;
        stat = viOpen (rscmng, "GPIB0::11::INSTR", VI_NULL,VI_NULL, &vi);
        if (stat < VI_SUCCESS) qDebug() << "Connecting failed";

        viPrintf (vi,"*RST\n");                                       /* Initialize device */
        viPrintf (vi, (ViString)"*IDN?\n");                             /* Send an *IDN? string to the device */
        char buf1 [256] = {0};
        viScanf (vi, (ViString)"%t", &buf1);                            /* Read results */
        printf ("Instrument identification string: %s\n", buf1);      /* Print results */
        qDebug()<<buf1;

        // close VI sessions
        viClose(rscmng);
        viClose(osc);
        viClose (vi);
}
