#include "firfilter.h"
#include <fircoefs.h>
#include <QDebug>

FIRFilter::FIRFilter()
{

}


std::deque<FixedFP> FIRFilter::getOutput(std::deque<FixedFP> input)
{
    qDebug() << "<=================FILTER COEFFICIENTS==============>";
    for (int i=0; i<FILTER_ORDER; i++) qDebug() << coef_f[i].to_float();
    qDebug() << "<==================================================>";

    //Resizing input to prevent error during convolution
    int len = input.size() + FILTER_ORDER - 1;
    input.resize(len, 0);
    std::deque<FixedFP> output;

//    for (int i=len-1; i>=0; i--)
//    {
//        FixedFP result = 0;
//        //Convoluting current sample
//        qDebug() << "Convoluting sample number" << i;
//        for (int k=0; k<FILTER_ORDER; k++)
//        {
//            if(i-k >= 0)
//            {
//                float add = input[i-k].to_float() * coef_f[k].to_float();
//                qDebug() << "Adding" << add;
//                result += add;
//                qDebug() << "Result is" << result.to_float();
//            }
//        }
//        qDebug() << "End Result is" << result.to_float();
//        qDebug() << "<===================================>" ;
//        output.push_front(result);
//    }
    //New version
    for (int i=0; i<len; i++)
    {
        FixedFP result = 0;
        for (int k=0; k<FILTER_ORDER; k++)
        {
            if (i-k >= 0)
            {
                float add = input[i-k].to_float() * coef_f[k].to_float();
                result += add;
            }
        }
        output.push_back(result);
    }

    qDebug() << "<=================FILTERED SIGNAL==================>" ;
    for (int i=0; i<output.size(); i++) qDebug() << output[i].to_float();
    qDebug() << "<==================================================>";


    return output;
}
